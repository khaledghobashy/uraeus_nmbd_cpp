# Standard library imports
import os
import re
import shutil
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

        self.joints_names = [edge[-1] for edge in self.mbs.constraints_graph.edges(data='name')]

    @staticmethod
    def _insert_string(string):
        def inserter(x): return string + x.group(0)
        return inserter

###############################################################################
###############################################################################

class template_codegen(abstract_generator):

    
    def write_cmake_file(self, dir_path=''):
        file_path = os.path.join(dir_path, 'CMakeLists.txt')
        text = self._write_cmake_content()
        with open(file_path, 'w') as file:
            file.write(text)
        print('Generated CMakeLists.txt at : %s'%file_path)

    def write_cpp_files(self, dir_path=''):
        self.write_topology_header(dir_path)
        self.write_topology_source(dir_path)
        self.write_simulation_header(dir_path)
        self.write_simulation_source(dir_path)

    def write_cython_files(self, dir_path=''):
        templates_path = os.path.join(os.path.dirname(__file__), "templates")
        self.write_pyx_file(dir_path)
        self.write_pxd_file(dir_path)
        shutil.copy(os.path.join(templates_path, "call_obj.pyx"), dir_path)
        shutil.copy(os.path.join(templates_path, "py_obj_wrapper.hpp"), dir_path)
        shutil.copy(os.path.join(templates_path, "cython_cmake.txt"), os.path.join(dir_path, "CMakeLists.txt"))
        print('Generated call_obj.pyx file at %s'%dir_path)
        print('Generated py_obj_wrapper.hpp file at %s'%dir_path)
        print('Generated CMakeLists.txt file at %s'%dir_path)

    def write_topology_header(self, dir_path=''):
        file_path = os.path.join(dir_path, self.name)
        text = self._write_header_content()
        with open('%s.hpp'%file_path, 'w') as file:
            file.write(text)
        print('Generated topology header file at : %s.hpp'%file_path)
    
    def write_topology_source(self, dir_path=''):
        file_path = os.path.join(dir_path, self.name)
        text = self._write_source_content()
        with open('%s.cpp'%file_path, 'w') as file:
            file.write(text)
        print('Generated topology source file at : %s.cpp'%file_path)
    
    def write_simulation_header(self, dir_path=''):
        file_path = os.path.join(dir_path, 'simulation')
        text = self._write_simulation_hpp_content()
        with open('%s.hpp'%file_path, 'w') as file:
            file.write(text)
        print('Generated simulation header file at : %s.hpp'%file_path)
    
    def write_simulation_source(self, dir_path=''):
        file_path = os.path.join(dir_path, 'simulation')
        text = self._write_simulation_cpp_content()
        with open('%s.cpp'%file_path, 'w') as file:
            file.write(text)
        print('Generated simulation source file at : %s.cpp'%file_path)

    
    def write_pyx_file(self, dir_path=''):
        file_path = os.path.join(dir_path, 'simulation.pyx')
        text = self._write_pyx_content()
        with open(file_path, 'w') as file:
            file.write(text)
        print('Generated simulation.pyx at : %s'%file_path)

    def write_pxd_file(self, dir_path=''):
        file_path = os.path.join(dir_path, 'simulation.pxd')
        text = self._write_pxd_content()
        with open(file_path, 'w') as file:
            file.write(text)
        print('Generated simulation.pxd at : %s'%file_path)

    
    def _write_pyx_content(self):
        template = os.path.join(os.path.dirname(__file__), "templates/simulation_pyx.txt")

        with open(template, "r") as f:
            template_text = Template(f.read())
        
        function_definition = \
        '''
        def set_{UF}(self, func):
            cdef PyObjWrapper f = PyObjWrapper(func)
            self.sim.set_{UF}(f)
        '''

        user_functions = [function_definition.format(UF = i) \
            for i in self.arguments_symbols \
                if i.startswith('UF') and not (i.endswith('_F') or i.endswith('_T'))]

        user_functions_text = '\n'.join(user_functions)
        user_functions_text = textwrap.dedent(user_functions_text)
        user_functions_text = textwrap.indent(user_functions_text, 4*' ').lstrip()

        text = template_text.safe_substitute(
            user_functions = user_functions_text)

        return text

    def _write_pxd_content(self):
        template = os.path.join(os.path.dirname(__file__), "templates/simulation_pxd.txt")

        with open(template, "r") as f:
            template_text = Template(f.read())
        
        function_definition = \
        '''
        void set_{UF}(PyObjWrapper func) except +
        '''

        user_functions = [function_definition.format(UF = i) \
            for i in self.arguments_symbols \
                if i.startswith('UF') and not (i.endswith('_F') or i.endswith('_T'))]

        user_functions_text = ''.join(user_functions)
        user_functions_text = textwrap.dedent(user_functions_text)
        user_functions_text = textwrap.indent(user_functions_text, 8*' ').lstrip()

        text = template_text.safe_substitute(
            user_functions = user_functions_text)
        
        return text


    def _write_simulation_hpp_content(self):
        template = os.path.join(os.path.dirname(__file__), "templates/simulation_hpp.txt")

        with open(template, "r") as f:
            template_text = Template(f.read())
        
        function_definition = \
        '''
        void set_{UF}(std::function<double(double)> func);
        '''

        user_functions = [function_definition.format(UF = i) \
            for i in self.arguments_symbols \
                if (i.startswith('UF') and not (i.endswith('_F') or i.endswith('_T')))]

        user_functions_text = ''.join(user_functions)
        user_functions_text = textwrap.dedent(user_functions_text)
        user_functions_text = textwrap.indent(user_functions_text, 4*' ').lstrip()

        text = template_text.safe_substitute(
            topology_name = self.name,
            user_functions = user_functions_text)

        return text
    

    def _write_simulation_cpp_content(self):
        template = os.path.join(os.path.dirname(__file__), "templates/simulation_cpp.txt")

        with open(template, "r") as f:
            template_text = Template(f.read())

        
        default_functions_text = \
        '''
        Soln.model.config.{UF} = [] (double t)->Eigen::Vector3d{{return Eigen::Vector3d::Zero(3);}};
        '''
       
        default_functions = [default_functions_text.format(UF = i)\
            for i in self.arguments_symbols \
                if (i.startswith('UF') and (i.endswith('_F') or i.endswith('_T')))]

        default_functions_text = ''.join(default_functions)
        default_functions_text = textwrap.dedent(default_functions_text)
        default_functions_text = textwrap.indent(default_functions_text, 4*' ').lstrip()


        function_definition = \
        '''
        void Simulation::set_{UF}(std::function<double(double)> func)
        {{
            Soln.model.config.{UF} = func;
        }};
        '''

        user_functions = [function_definition.format(UF = i) \
            for i in self.arguments_symbols \
                if (i.startswith('UF') and not (i.endswith('_F') or i.endswith('_T')))]

        user_functions_text = ''.join(user_functions)
        user_functions_text = textwrap.dedent(user_functions_text)
        user_functions_text = textwrap.indent(user_functions_text, '').lstrip()


        text = template_text.safe_substitute(
            user_functions = user_functions_text,
            default_functions = default_functions_text)

        return text

    def _write_cmake_content(self):
        template = os.path.join(os.path.dirname(__file__), "templates/cmake_template.txt")

        with open(template, "r") as f:
            template_text = Template(f.read())
        
        text = template_text.safe_substitute(
            topology_name = self.name)

        return text
    

    def _write_header_content(self):
        import sympy as sm
        printer = p = self.printer
        indent = ''

        template = os.path.join(
            os.path.dirname(__file__), 
            "templates/header_template.txt")

        with open(template, "r") as f:
            template_text = Template(f.read())

        # Configuration struct variables
        # ============================== 
        primary_arguments = '\n'.join(['%s ;'%p._print(i, declare=True) for i in 
                                      set(self.mbs.arguments_symbols)])
        primary_arguments = textwrap.indent(primary_arguments, 4*' ').lstrip()
        
        configuration_repl = \
        {
            "primary_arguments": primary_arguments
        }

        # Coordinates Struct variables
        # ============================
        coordinates = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True)
            for exp in self.gen_coordinates_exp])
        coordinates = textwrap.indent(coordinates, 4*' ').lstrip()

        velocities = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) 
            for exp in self.gen_velocities_exp])
        velocities = textwrap.indent(velocities, 4*' ').lstrip()

        accelerations = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True)
            for exp in self.gen_accelerations_exp])
        accelerations = textwrap.indent(accelerations, 4*' ').lstrip()

        lagrange = '\n'.join(['%s'%p._print(exp, declare=False, is_ref=True) 
            for exp in self.lagrange_multipliers_exp])
        lagrange = textwrap.indent(lagrange, 4*' ').lstrip()
        lagrange = lagrange.replace('Lambda', 'lgr')

        coordinates_repl = \
        {
            "coordinates": coordinates,
            "velocities": velocities,
            "accelerations": accelerations,
            "lagrange": lagrange
        }
        # --------------------------------------------------------


        # Topology Class variables
        # ============================== 
        bodies_indices = '\n'.join(['int %s ;'%i for i in self.bodies])
        bodies_indices = textwrap.indent(bodies_indices, 4*' ').lstrip()

        bodies_names = ', '.join(['"%s"'%i for i in self.bodies])
        bodies_names = textwrap.indent('{%s}'%bodies_names, 4*' ').lstrip()

        joints_names = ', '.join(['"%s"'%i for i in self.joints_names])
        joints_names = textwrap.indent('{%s}'%joints_names, 4*' ').lstrip()

        topology_repl = \
        {
            "n": self.mbs.n,
            "nc": self.mbs.nc,
            "nve": self.mbs.nve,
            "ncols": 2 * (self.mbs.n // 7),
            "topology_name": self.mbs.name,
            "bodies_indices": bodies_indices,
            "bodies_names": bodies_names,
            "joints_names": joints_names
        }
        # --------------------------------------------------------


        # Constants struct variables
        # ============================== 
        constants_symbols = '\n'.join(['%s ;'%p._print(i, declare=True) for i in 
                               set(self.mbs.constants_symbols)])
        constants_symbols = textwrap.indent(constants_symbols, 4*' ').lstrip()

        constants_repl = \
        {
            "constants_symbols": constants_symbols
        }

        # --------------------------------------------------------

        # Actuators struct variables
        # ============================== 
        actuators_symbols = '\n'.join(['%s ;'%p._print(i, declare=True) for i in 
                               set(self.mbs.arguments_symbols) 
                               if str(i).startswith("UF_")])
        actuators_symbols = textwrap.indent(actuators_symbols, 4*' ').lstrip()

        actuators_repl = \
        {
            "actuators_symbols": actuators_symbols
        }

        # Position Constraint Equations Struct
        # ====================================
        pos_cse_expr = '\n'.join(['%s ;'%p._print(i[0], declare=True) 
            for i in self.mbs.pos_rep])
        pos_cse_expr = textwrap.indent(pos_cse_expr, 4*' ').lstrip()

        pos_eq_repl = \
            {
                "pos_common_expressions": pos_cse_expr,
            }
        # --------------------------------------------------------

        # Velocities Constraint Equations Struct
        # ======================================
        vel_cse_expr = '\n'.join(['%s ;'%p._print(i[0], declare=True) 
            for i in self.mbs.vel_rep])
        vel_cse_expr = textwrap.indent(vel_cse_expr, 4*' ').lstrip()

        vel_eq_repl = \
            {
                "vel_common_expressions": vel_cse_expr,
            }
        # --------------------------------------------------------

        # Acceleration Constraint Equations Struct
        # ========================================
        acc_cse_expr = '\n'.join(['%s ;'%p._print(i[0], declare=True) 
            for i in self.mbs.acc_rep])
        acc_cse_expr = textwrap.indent(acc_cse_expr, 4*' ').lstrip()

        acc_eq_repl = \
            {
                "acc_common_expressions": acc_cse_expr,
            }
        # --------------------------------------------------------
        
        # Forces Vector Equations Struct
        # ===============================
        frc_cse_expr = '\n'.join(['%s ;'%p._print(i[0], declare=True) 
            for i in self.mbs.frc_rep])
        frc_cse_expr = textwrap.indent(frc_cse_expr, 4*' ').lstrip()

        frc_eq_repl = \
            {
                "frc_common_expressions": frc_cse_expr,
            }
        # --------------------------------------------------------

        # Constraints Jacobian Equations Struct
        # =====================================
        jac_cse_expr = '\n'.join(['%s ;'%p._print(i[0], declare=True) 
            for i in self.mbs.jac_rep])
        jac_cse_expr = textwrap.indent(jac_cse_expr, 4*' ').lstrip()

        jac_eq_repl = \
            {
                "jac_common_expressions": jac_cse_expr,
            }
        # --------------------------------------------------------

        # Mass Matrix Equations Struct
        # ============================
        mas_cse_expr = '\n'.join(['%s ;'%p._print(i[0], declare=True) 
            for i in self.mbs.mass_rep])
        mas_cse_expr = textwrap.indent(mas_cse_expr, 4*' ').lstrip()

        mas_eq_repl = \
            {
                "mas_common_expressions": mas_cse_expr,
            }
        # --------------------------------------------------------

        # Template replacements
        # =====================
        template_text = template_text.safe_substitute(
            **topology_repl,
            **coordinates_repl,
            **constants_repl,
            **configuration_repl,
            **actuators_repl,
            **pos_eq_repl,
            **vel_eq_repl,
            **acc_eq_repl,
            **frc_eq_repl,
            **jac_eq_repl,
            **mas_eq_repl)

        return template_text



    def _write_source_content(self):

        printer = self.printer
        indent = ''

        source_template = os.path.join(os.path.dirname(__file__), "templates/source_template.txt")

        with open(source_template, "r") as f:
            template_text = Template(f.read())
        
        jac_rows, jac_cols, nnz = self.get_jac_data()
        indicies_map, virtuals  = self.get_indicies_mapping()
        primary_arguments, q_equalities, qd_equalities  = self.get_coordinates_equalities()
        num_constants, sym_constants = self.get_constants_expressions()

        pos_replacements, pos_expressions = self.get_pos_equations()
        vel_replacements, vel_expressions = self.get_vel_equations()
        acc_replacements, acc_expressions = self.get_acc_equations()
        jac_replacements, jac_expressions = self.get_jac_equations()
        mas_replacements, mas_expressions = self.get_mas_equations()
        frc_replacements, frc_expressions = self.get_frc_equations()

        #rct_expressions = self.get_reactions_equations()
        rct_expressions2, rct_return2 = self.get_reactions_equations2()

        template_text = template_text.safe_substitute(
            topology_name = self.name,
            n = self.mbs.n,
            nnz = nnz,
            n_joints = len(self.joints_names),
            jac_rows = jac_rows,
            jac_cols = jac_cols,
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
            jac_expressions = jac_expressions,
            mas_replacements = mas_replacements,
            mas_expressions = mas_expressions,
            frc_replacements = frc_replacements,
            frc_expressions = frc_expressions,
            rct_expressions1 = '//rct_expressions',
            rct_return1 = '//rct_return',
            rct_expressions2 = rct_expressions2,
            rct_return2 = rct_return2,
            jac_submatrices = '// TODO',
            mas_submatrices = '//  TODO')

        return template_text
    
    
    def get_pos_equations(self):
        return self.get_X_equations("pos")

    def get_vel_equations(self):
        return self.get_X_equations("vel")

    def get_acc_equations(self):
        return self.get_X_equations("acc")

    def get_frc_equations(self):
        return self.get_X_equations("frc")

    def get_jac_equations(self):
        return self.get_X_equations("jac", std_vector=True)

    def get_mas_equations(self):
        return self.get_X_equations("mass", std_vector=True)

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
        num_repl_list = ['%s'%(printer._print(exp, declare=False, is_ref=False)) for exp in replacements_list]
        num_expr_list = [printer._print(exp) for exp in vector_data]
        
        # Joining the extracted strings to form a valid text block.
        num_repl_text = '\n'.join(num_repl_list)
        if std_vector:
            num_expr_text = '\n'.join(["matricies.emplace_back(%s);"%i for i in num_expr_list])
        else:
            num_expr_text = ',\n'.join(num_expr_list)

        num_repl_text = re.sub(r'Eigen::Vector3d\s+([a-zA-Z_][a-zA-Z_0-9]*) = t ;',
                               r'double \1 = t ;', num_repl_text)

        # Creating a regex pattern of strings that represents the variables
        # which need to be perfixed by a 'self.' to be referenced correctly.
        self_pattern = itertools.chain(self.runtime_symbols,)
        self_pattern = '|'.join(self_pattern)

        # Creating a regex pattern of strings that represents the variables
        # which need to be perfixed by a 'consts.' to be referenced correctly.
        consts_pattern = set(self.constants_symbols) - set(self.runtime_symbols)
        consts_pattern = '|'.join(consts_pattern)
        
        # Creating a regex pattern of strings that represents the variables
        # which need to be perfixed by a 'config.' to be referenced correctly.
        config_pattern = set(self.primary_arguments) - set(self.runtime_symbols)
        config_pattern = '|'.join([r'%s'%i for i in config_pattern])
        
        # Performing the regex substitution with 'self.'.
        self_inserter = self._insert_string('coord.')
        num_repl_text = re.sub(self_pattern, self_inserter, num_repl_text)
        num_expr_text = re.sub(self_pattern, self_inserter, num_expr_text)
        
        # Performing the regex substitution with 'consts.'.
        consts_inserter = self._insert_string('consts.')
        num_repl_text = re.sub(consts_pattern, consts_inserter, num_repl_text)
        num_expr_text = re.sub(consts_pattern, consts_inserter, num_expr_text)
        
        # Performing the regex substitution with 'config.'.
        config_inserter = self._insert_string('config.')
        num_repl_text = re.sub(config_pattern, config_inserter, num_repl_text)
        num_expr_text = re.sub(config_pattern, config_inserter, num_expr_text)
        
        # Indenting the text block for propper class and function indentation.
        num_repl_text = textwrap.indent(num_repl_text, 4*' ').lstrip() 
        num_expr_text = textwrap.indent(num_expr_text, (4 if std_vector else 8)*' ').lstrip()
        
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
    

    def get_reactions_equations(self):

        expressions = []
        
        offset = 0
        for edge in self.mbs.constraints_graph.edges(data=True):
            nc = edge[-1]['nc']
            nve = edge[-1]['nve']
            joint_name = edge[-1]['name']
            body_name = edge[0]
            def_locs = edge[-1]['class'].def_locs
            
            R_exp = [f'jac_eq[%s]'%(4*i + offset) for i in range(nve)]
            R_blocks_text = ', '.join(R_exp) + ';'
            P_exp = [f'jac_eq[%s]'%(4*i + offset + 1) for i in range(nve)]
            P_blocks_text = ', '.join(P_exp) + ';'
            
            text = [
            f'// Joint Name : {joint_name}',
            f'Eigen::MatrixXd R_jac_{joint_name}({nc}, 3);',
            f'Eigen::MatrixXd P_jac_{joint_name}({nc}, 4);',
            f'R_jac_{joint_name} << %s'%R_blocks_text,
            f'P_jac_{joint_name} << %s'%P_blocks_text,
            f'Eigen::VectorXd F_{joint_name} = -R_jac_{joint_name}.transpose() * coord.L_{joint_name};',
            f'Eigen::VectorXd T_{joint_name} = 0.5*E(coord.P_{body_name}) * (-P_jac_{joint_name}.transpose() * coord.L_{joint_name}) - skew(A(coord.P_{body_name})*ubar_{body_name}_{joint_name})*F_{joint_name};' if def_locs \
            else f'Eigen::VectorXd T_{joint_name} = 0.5*E(coord.P_{body_name}) * (-P_jac_{joint_name}.transpose() * coord.L_{joint_name});',
            ]
            
            text = '\n'.join(text)        
            expressions.append(text)
            offset += nve*4
        
        expressions_text = '\n\n'.join(expressions)
        return expressions_text
    
    
    def get_reactions_equations1(self):
        
        indent = 4*' '
        p = self.printer
        
        equations = self.mbs.reactions_equalities
        #print(equations[0].rhs.args[1].__class__.__name__)
        #print(equations[0].rhs.shape)
        #print('\n', p._print(equations[0].rhs), '\n')
        equations_text = '\n'.join([p._print(expr) for expr in equations])
        
        self_pattern = itertools.chain(self.runtime_symbols,
                                       self.constants_symbols,
                                       self.joint_reactions_sym,
                                       self.lagrange_multipliers_sym)
        self_pattern = '|'.join(self_pattern)
        self_inserter = self._insert_string('')
        equations_text = re.sub(self_pattern,self_inserter,equations_text)
        
        config_pattern = set(self.primary_arguments) - set(self.runtime_symbols)
        config_pattern = '|'.join([r'%s'%i for i in config_pattern])
        config_inserter = self._insert_string('config.')
        equations_text = re.sub(config_pattern,config_inserter,equations_text)
                
        equations_text = textwrap.indent(equations_text,indent).lstrip() 
        
        reactions = ',\n'.join(['%r : self.%s'%(i,i) for i in self.joint_reactions_sym])
        reactions = textwrap.indent(reactions, 5*indent).lstrip()
        reactions = '{%s}'%reactions
        
        return equations_text, reactions

    def get_reactions_equations2(self):

        expressions = []
        returns = []
        
        row_offset = 0
        for edge in self.mbs.constraints_graph.edges(data=True):
            nc = edge[-1]['nc']
            nve = edge[-1]['nve']
            joint_name = edge[-1]['name']
            body_name = edge[0]
            def_locs = edge[-1]['class'].def_locs

            col_offset = self.mbs.nodes_indicies[body_name] * 7

            text = [
            f'// Joint Name : {joint_name}',
            f'const Eigen::MatrixXd& Jac_{joint_name} = jacobian.block({row_offset}, {col_offset}, {nc}, 7);',
            f'Eigen::VectorXd Q_{joint_name} = -Jac_{joint_name}.transpose() * coord.L_{joint_name};',
            f'const Eigen::VectorXd& F_{joint_name} = Q_{joint_name}.segment(0, 3);',
            f'Eigen::VectorXd T_{joint_name} = 0.5*E(coord.P_{body_name}) * Q_{joint_name}.segment(3, 4) - skew(A(coord.P_{body_name})*ubar_{body_name}_{joint_name})*F_{joint_name};' if def_locs \
            else f'Eigen::VectorXd T_{joint_name} = 0.5*E(coord.P_{body_name}) * Q_{joint_name}.segment(3, 4);',
            ]
            
            text = '\n'.join(text)        
            expressions.append(text)
            row_offset += nc

            returns.append(f'F_{joint_name}')
            returns.append(f'T_{joint_name}')
        
        expressions_text = '\n\n'.join(expressions)
        expressions_text = textwrap.indent(expressions_text, 4*' ').lstrip()

        reactions_return = ',\n'.join(returns) + ';'
        reactions_return = textwrap.indent(reactions_return, 8*' ').lstrip()

        return expressions_text, reactions_return



###############################################################################
###############################################################################
