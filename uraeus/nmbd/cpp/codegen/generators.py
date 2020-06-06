# Standard library imports
import os
import re
import textwrap
import itertools
from string import Template

# Local application imports
from .printer import printer


class abstract_generator(object):
    """
    A C++ code-generator class that generates numerical code with an OOP
    structure using Eigen Library.
    
    Parameters
    ----------
    mbs : topology
        An instance of a topology class.
    
    Methods
    -------
    write_code_file()
        Write the structured code-files in a .py file format. These code-files
        are saved in the corresponding sub-directory in the //generated_templates
        directory.
        
    Notes
    -----
    This generator structures the numerical code of the system as follows:
        - Creating a 'model_name'.py file that is designed  be used as an 
          imported  module. The file is saved in a sub-directory inside the
          'generated_templates' directory.
        - This module contains one class only, the 'topology' class.
        - This class provides the interface to be used either directly by the 
          python_solver or indirectly by the assembly class that assembles 
          several 'topology' classes together.

    """
    
    def __init__(self,mbs, printer=printer()):
        
        self.mbs     = mbs
        self.printer = printer
        self.name    = self.mbs.name
                
        self.arguments_symbols = [printer._print(exp) for exp in self.mbs.arguments_symbols]
        self.constants_symbols = [printer._print(exp) for exp in self.mbs.constants_symbols]
        self.runtime_symbols   = [printer._print(exp) for exp in self.mbs.runtime_symbols]
        
        self.primary_arguments = self.arguments_symbols
        
        self.constants_symbolic_expr = self.mbs.constants_symbolic_expr
        self.constants_numeric_expr  = self.mbs.constants_numeric_expr
        
        self.gen_coordinates_exp = self.mbs.mapped_gen_coordinates
        self.gen_coordinates_sym = [printer._print(exp.lhs) for exp in self.gen_coordinates_exp]

        self.gen_velocities_exp  = self.mbs.mapped_gen_velocities
        self.gen_velocities_sym  = [printer._print(exp.lhs) for exp in self.gen_velocities_exp]
        
        self.gen_accelerations_exp  = self.mbs.mapped_gen_accelerations
        self.gen_accelerations_sym  = [printer._print(exp.lhs) for exp in self.gen_accelerations_exp]
        
        self.lagrange_multipliers_exp  = self.mbs.mapped_lagrange_multipliers
        self.lagrange_multipliers_sym  = [printer._print(exp.lhs) for exp in self.lagrange_multipliers_exp]

        self.joint_reactions_sym = [printer._print(exp) for exp in self.mbs.reactions_symbols]

        self.virtual_coordinates = [printer._print(exp) for exp in self.mbs.virtual_coordinates]
                
        self.bodies = self.mbs.bodies

    @staticmethod
    def _insert_string(string):
        def inserter(x): return string + x.group(0)
        return inserter

###############################################################################
###############################################################################

class template_codegen(abstract_generator):
    
    def write_header_class(self):
        text = '''
                #pragma once

                // Standard Library Includes.
                #include <map>
                #include <vector>
                
                // uraeus library includes.
                #include <uraeus/numerics/euler_parameters.hpp>
                #include <uraeus/numerics/spatial_algebra.hpp>
                #include <uraeus/solvers/helpers.hpp>

                #include <uraeus/systems/configuration.hpp>

                typedef std::map<std::string, std::string> Dict_SS;
                typedef std::map<std::string, int> Dict_SI;
                
                // Declaring the Configuration Class and its numerical objects.
                // ============================================================
                class Configuration
                {{

                public:
                    Configuration();
                
                public:
                    ConfigurationAssembler ConfigInputs;
                    void constructFromJSON(const std::string& fileName);                
                    void set_inital_configuration();
                
                private:
                    void populateArguments();

                public:
                    Eigen::VectorXd q;
                    Eigen::VectorXd qd;

                    Eigen::Vector3d R_ground {{0, 0, 0}};
                    Eigen::Vector4d P_ground {{1, 0, 0, 0}};
                    
                    Eigen::Vector3d Rd_ground {{0, 0, 0}};
                    Eigen::Vector4d Pd_ground {{0, 0, 0, 0}};

                    {primary_arguments}
                    
                }};


                // ============================================================================
                //                     Coordinates Struct Decleration
                // ============================================================================
                struct Coordinates
                {
                private:
                    Coordinates() = delete;

                public:
                    Coordinates(Eigen::Ref<Eigen::VectorXd> q, 
                                Eigen::Ref<Eigen::VectorXd> qd, 
                                Eigen::Ref<Eigen::VectorXd> qdd);

                public:
                    Eigen::Ref<Eigen::VectorXd> m_q;
                    Eigen::Ref<Eigen::VectorXd> m_qd;
                    Eigen::Ref<Eigen::VectorXd> m_qdd;
                
                // Topology Generalized Coordinates (R and P vectors).
                public:
                    {coordinates}
                
                // Topology Generalized Velocities (dR/dt and dP/dt vectors).
                public:
                    {velocities}
                
                // Topology Generalized Accelerations (dR2/dt2 and dP2/dt2 vectors).
                public:
                    {accelerations}

                
                // ============================================================================
                //                     Topology Class Decleration
                // ============================================================================
                
                class Topology
                {{
                
                public:
                    // Topology constants.
                    static const int n = {n};
                    static const int nc = {nc};
                    static const int nrows = {nve};
                    static const int ncols = 2*{nodes};
                    std::vector<std::string> names {bodies_names};
                    

                    // Topology Constructors.

                    // Deleting the default constructor to inforce initialization with the 
                    // desired vectors
                    Topology() = delete;

                    Topology(std::string name, 
                            Eigen::Ref<Eigen::VectorXd> q, 
                            Eigen::Ref<Eigen::VectorXd> qd, 
                            Eigen::Ref<Eigen::VectorXd> qdd);

                public:

                    // These variables are to be initialized through the class constructor 
                    // initializer list
                    std::string prefix;
                    Coordinates coord;
                    Configuration config;

                    // These variables are initialized with their default constructor.
                    double t = 0;
                                        
                    Eigen::VectorXd pos_eq;
                    Eigen::VectorXd vel_eq;
                    Eigen::VectorXd acc_eq;

                    Eigen::VectorXd jac_rows;
                    Eigen::VectorXd jac_cols;
                    
                    std::vector<Eigen::MatrixXd> jac_eq;
                    std::vector<Eigen::MatrixXd> mas_eq;
                    
                    Eigen::VectorXd rows = Eigen::VectorXd::LinSpaced(nrows, 0, nrows-1);
                    
                    Dict_SI indicies_map;
                    
                    // Topology initializing functions.
                    void initialize();
                    void set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map);
                    void map_indicies();
                    void assemble(Dict_SI& indicies_map, Dict_SS& interface_map, int rows_offset);
                    void eval_constants();
                    
                    // Topology Equations Evaluators.
                    void eval_pos_eq();
                    void eval_vel_eq();
                    void eval_acc_eq();
                    void eval_jac_eq();
                
                // Topology Bodies Indicies from the network graph.                    
                public:
                    {bodies}
                                
                // Configuration Constants.
                public:    
                    {constants}
                
                }};
                '''
        text = text.expandtabs()
        text = textwrap.dedent(text)
        
        p = self.printer
        
        primary_aruments = '\n'.join(['%s ;'%p._print(i, declare=True) for i in 
                                      set(self.mbs.arguments_symbols)])
        primary_aruments = textwrap.indent(primary_aruments, 4*' ').lstrip()
        
        bodies_indices = '\n'.join(['int %s ;'%i for i in self.bodies])
        bodies_indices = textwrap.indent(bodies_indices, 4*' ').lstrip()

        bodies_names = ', '.join(['%s'%i for i in self.bodies])
        bodies_names = textwrap.indent('{%s}'%bodies_names, 4*' ').lstrip()
        
        coordinates = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) for exp in
                                 self.gen_coordinates_exp[2:]])
        coordinates = textwrap.indent(coordinates, 4*' ').lstrip()

        velocities = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) for exp in 
                                self.gen_velocities_exp])
        velocities = textwrap.indent(velocities, 4*' ').lstrip()

        accelerations = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) for exp in
                                   self.gen_accelerations_exp])
        accelerations = textwrap.indent(accelerations, 4*' ').lstrip()

        constants = '\n'.join(['%s ;'%p._print(i, declare=True) for i in 
                               set(self.mbs.constants_symbols)])
        constants = textwrap.indent(constants, 4*' ').lstrip()
        
        text = text.format(primary_arguments = primary_aruments,
                           bodies = bodies_indices,
                           bodies_names = bodies_names,
                           coordinates = coordinates,
                           velocities = velocities,
                           accelerations = accelerations,
                           constants = constants,
                           n = self.mbs.n,
                           nc = self.mbs.nc,
                           nve = self.mbs.nve,
                           nodes = len(self.bodies))        
        return text
    
    def write_header_file(self, dir_path=''):
        file_path = os.path.join(dir_path, self.name)
        system_class = self.write_header_content()
        with open('%s.hpp'%file_path, 'w') as file:
            file.write(system_class)
        print('File full path : %s.hpp'%file_path)
    
    
    def write_source_file(self, dir_path=''):
        file_path = os.path.join(dir_path, self.name)
        system_class = self.write_source_content()
        with open('%s.cpp'%file_path, 'w') as file:
            file.write(system_class)
        print('File full path : %s.cpp'%file_path)

    
    def write_header_content(self):
        printer = p = self.printer
        indent = ''

        header_template = os.path.join(os.path.dirname(__file__), "header_template.txt")

        with open(header_template, "r") as f:
            template_text = Template(f.read())

        primary_aruments = '\n'.join(['%s ;'%p._print(i, declare=True) for i in 
                                      set(self.mbs.arguments_symbols)])
        primary_aruments = textwrap.indent(primary_aruments, 4*' ').lstrip()
        
        bodies_indices = '\n'.join(['int %s ;'%i for i in self.bodies])
        bodies_indices = textwrap.indent(bodies_indices, 4*' ').lstrip()

        bodies_names = ', '.join(['"%s"'%i for i in self.bodies])
        bodies_names = textwrap.indent('{%s}'%bodies_names, 4*' ').lstrip()
        
        coordinates = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) for exp in
                                 self.gen_coordinates_exp])
        coordinates = textwrap.indent(coordinates, 4*' ').lstrip()

        velocities = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) for exp in 
                                self.gen_velocities_exp])
        velocities = textwrap.indent(velocities, 4*' ').lstrip()

        accelerations = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) for exp in
                                   self.gen_accelerations_exp])
        accelerations = textwrap.indent(accelerations, 4*' ').lstrip()

        constants = '\n'.join(['%s ;'%p._print(i, declare=True) for i in 
                               set(self.mbs.constants_symbols)])
        constants = textwrap.indent(constants, 4*' ').lstrip()

        template_text = template_text.safe_substitute(
            primary_arguments = primary_aruments,
            bodies = bodies_indices,
            bodies_names = bodies_names,
            coordinates = coordinates,
            velocities = velocities,
            accelerations = accelerations,
            constants = constants,
            n = self.mbs.n,
            nc = self.mbs.nc,
            nve = self.mbs.nve,
            nodes = len(self.bodies))

        return template_text



    def write_source_content(self):

        printer = self.printer
        indent = ''

        source_template = os.path.join(os.path.dirname(__file__), "source_template.txt")

        with open(source_template, "r") as f:
            template_text = Template(f.read())
                
        file_name = self.name

        jac_rows, jac_cols, nnz = self.get_jac_data()
        indicies_map, virtuals  = self.get_indicies_mapping()
        primary_arguments, q_equalities, qd_equalities  = self.get_coordinates_equalities()
        num_constants, sym_constants = self.get_constants_expressions()

        pos_replacements, pos_expressions = self.get_pos_equations()
        vel_replacements, vel_expressions = self.get_vel_equations()
        acc_replacements, acc_expressions = self.get_acc_equations()
        jac_replacements, jac_expressions = self.get_jac_equations()

        template_text = template_text.safe_substitute(
            file_name = file_name,
            n = self.mbs.n,
            jac_rows = jac_rows,
            jac_cols = jac_cols,
            nnz = nnz,
            indicies_map = indicies_map,
            virtuals = virtuals,
            primary_arguments = primary_arguments,
            q_equalities = q_equalities,
            qd_equalities = qd_equalities,
            sym_constants = sym_constants,
            num_constants = num_constants,
            pos_replacements = pos_replacements,
            pos_expressions = pos_expressions,
            vel_replacements = vel_replacements,
            vel_expressions = vel_expressions,
            acc_replacements = acc_replacements,
            acc_expressions = acc_expressions,
            jac_replacements = jac_replacements,
            jac_expressions = jac_expressions)

        return template_text
    
    
    def get_pos_equations(self):
        return self.get_X_equations("pos")

    def get_vel_equations(self):
        return self.get_X_equations("vel")

    def get_acc_equations(self):
        return self.get_X_equations("acc")

    def get_jac_equations(self):
        return self.get_X_equations("jac", std_vector=True)

    def get_X_equations(self, eq_initial, std_vector=False):

        printer = self.printer

        # Geting the optimized equations' vector/matrix from the topology class.
        # The expected format is two lists [replacements] and [expressions].
        replacements_list = getattr(self.mbs, '%s_rep'%eq_initial)
        expressions_list  = getattr(self.mbs, '%s_exp'%eq_initial)
        # Extracting the vector/matrix from the returned expressions list.
        vector_expr = expressions_list[0]
        # Extracting the Non-Zero values of the vector/matrix.
        vector_data = [i[-1] for i in vector_expr.row_list()]
        
        # Extract the numerical format of the replacements and expressions into
        # a list of string expressions.
        num_repl_list = ['auto&& %s'%(printer._print(exp, declare=False, is_ref=True)) for exp in replacements_list]
        num_expr_list = [printer._print(exp) for exp in vector_data]
        
        # Joining the extracted strings to form a valid text block.
        num_repl_text = '\n'.join(num_repl_list)
        num_expr_text = ',\n'.join(num_expr_list)

        # Creating a regex pattern of strings that represents the variables
        # which need to be perfixed by a 'self.' to be referenced correctly.
        self_pattern = itertools.chain(self.runtime_symbols,)
                                       #self.constants_symbols)
        self_pattern = '|'.join(self_pattern)
        
        # Creating a regex pattern of strings that represents the variables
        # which need to be perfixed by a 'config.' to be referenced correctly.
        config_pattern = set(self.primary_arguments) - set(self.runtime_symbols)
        config_pattern = '|'.join([r'%s'%i for i in config_pattern])
        
        # Performing the regex substitution with 'self.'.
        self_inserter = self._insert_string('coord.')
        num_repl_text = re.sub(self_pattern, self_inserter, num_repl_text)
        num_expr_text = re.sub(self_pattern, self_inserter, num_expr_text)
        
        # Performing the regex substitution with 'config.'.
        config_inserter = self._insert_string('config.')
        num_repl_text = re.sub(config_pattern, config_inserter, num_repl_text)
        num_expr_text = re.sub(config_pattern, config_inserter, num_expr_text)
        
        # Indenting the text block for propper class and function indentation.
        num_repl_text = textwrap.indent(num_repl_text, 4*' ').lstrip() 
        num_expr_text = textwrap.indent(num_expr_text, 8*' ').lstrip()
        
        num_expr_text = '{%s}'%num_expr_text if std_vector else num_expr_text

        return num_repl_text, num_expr_text

    def get_jac_data(self):
        indent = ''
        ind_body = {v:k for k,v in self.mbs.nodes_indicies.items()}
        rows, cols, data = zip(*self.mbs.jac_equations.row_list())
        string_cols = [('%s*2'%ind_body[i//2] if i%2==0 else '%s*2+1'%ind_body[i//2]) for i in cols]
        string_cols_text = ', \n'.join(string_cols)
        string_cols_text = textwrap.indent(string_cols_text, 8*' ').lstrip()

        jac_rows = str(rows)[1:-1]
        jac_cols = string_cols_text
        nnz = len(data)

        return jac_rows, jac_cols, nnz


    def get_indicies_mapping(self):
        indent = ''
        printer = self.printer

        indicies_map = '\n'.join(['%s = indicies_map[p+"%s"];'%(i, i) for i in self.bodies])
        indicies_map = textwrap.indent(indicies_map, 4*' ').lstrip()
        
        virtuals = '\n'.join(['%s = indicies_map[interface_map[p+"%s"];'%(i, i) for i in self.mbs.virtual_bodies])
        virtuals = textwrap.indent(virtuals, indent).lstrip()
        
        return indicies_map, virtuals
    
    def get_coordinates_equalities(self):
        indent = ''
        self_inserter = self._insert_string('')

        primary_arguments = '\n'.join(['ConfigInputs.get("%s", %s);'%(i, i) for i 
                                      in self.primary_arguments])
        primary_arguments = textwrap.indent(primary_arguments, 4*' ').lstrip()

        q_pattern = '|'.join(self.gen_coordinates_sym)
        q_equalities = ', \n'.join(['%s'%q for q in self.gen_coordinates_sym])
        q_equalities = re.sub(q_pattern, self_inserter, q_equalities)
        q_equalities = textwrap.indent(q_equalities, 8*' ').lstrip()
        
        qd_pattern = '|'.join(self.gen_velocities_sym)
        qd_equalities = ', \n'.join(['%s'%q for q in self.gen_velocities_sym])
        qd_equalities = re.sub(qd_pattern, self_inserter, qd_equalities)
        qd_equalities = textwrap.indent(qd_equalities, 8*' ').lstrip()

        return primary_arguments, q_equalities, qd_equalities
    
    def get_constants_expressions(self):
        printer = self.printer
                
        config_pattern_iter = itertools.chain(self.arguments_symbols,
                                              self.virtual_coordinates)
        config_pattern = '|'.join(config_pattern_iter)
        config_inserter = self._insert_string('config.')
        
        self_pattern_iter = itertools.chain(self.constants_symbols)
        self_pattern = '|'.join(self_pattern_iter)
        self_inserter = self._insert_string('')
        
        num_constants_list = self.constants_numeric_expr
        num_constants_text = '\n'.join((printer._print(i) for i in num_constants_list))
        num_constants_text = re.sub(config_pattern, config_inserter, num_constants_text)
        num_constants_text = re.sub(self_pattern, self_inserter, num_constants_text)
        num_constants_text = textwrap.indent(num_constants_text, 4*' ').lstrip()

        sym_constants = self.constants_symbolic_expr
        sym_constants_text = '\n'.join((printer._print(i) for i in sym_constants))
        sym_constants_text = re.sub(config_pattern, config_inserter, sym_constants_text)
        sym_constants_text = re.sub(self_pattern, self_inserter, sym_constants_text)
        sym_constants_text = textwrap.indent(sym_constants_text, 4*' ').lstrip()

        return num_constants_text, sym_constants_text


###############################################################################
###############################################################################
