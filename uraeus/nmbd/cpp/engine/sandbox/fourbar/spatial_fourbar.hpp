
#pragma once

// Standard Library Includes.
#include <map>
#include <vector>

#include "eigen/Eigen/Sparse"

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
{

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

    Eigen::Vector3d R_ground {0, 0, 0};
    Eigen::Vector4d P_ground {1, 0, 0, 0};

    Eigen::Vector3d Rd_ground {0, 0, 0};
    Eigen::Vector4d Pd_ground {0, 0, 0, 0};

    Eigen::Vector3d R_rbs_l1 ;
    Eigen::Vector3d Rd_rbs_l1 ;
    Eigen::Vector3d pt1_jcs_a ;
    double m_rbs_l3 ;
    Eigen::Vector3d R_rbs_l2 ;
    Eigen::Matrix<double, 3, 3> Jbar_rbs_l2 ;
    Eigen::Vector3d Rdd_rbs_l3 ;
    Eigen::Vector3d pt1_jcs_c ;
    Eigen::Vector3d Rdd_rbs_l1 ;
    Eigen::Vector4d P_rbs_l3 ;
    Eigen::Vector4d Pdd_rbs_l3 ;
    Eigen::Vector3d Rdd_rbs_l2 ;
    double m_rbs_l2 ;
    Eigen::Vector4d P_rbs_l2 ;
    Eigen::Vector4d P_rbs_l1 ;
    Eigen::Vector4d Pd_rbs_l1 ;
    double m_rbs_l1 ;
    Eigen::Vector4d Pd_rbs_l2 ;
    std::function<double(double)> UF_mcs_act ;
    Eigen::Vector4d Pdd_rbs_l2 ;
    Eigen::Vector4d Pd_rbs_l3 ;
    Eigen::Vector4d Pdd_rbs_l1 ;
    Eigen::Vector3d ax1_jcs_b ;
    Eigen::Vector3d ax2_jcs_c ;
    Eigen::Vector3d ax1_jcs_d ;
    Eigen::Matrix<double, 3, 3> Jbar_rbs_l1 ;
    Eigen::Matrix<double, 3, 3> Jbar_rbs_l3 ;
    Eigen::Vector3d R_rbs_l3 ;
    Eigen::Vector3d pt1_jcs_d ;
    Eigen::Vector3d pt1_jcs_b ;
    Eigen::Vector3d Rd_rbs_l2 ;
    Eigen::Vector3d Rd_rbs_l3 ;
    Eigen::Vector3d ax1_jcs_a ;
    Eigen::Vector3d ax1_jcs_c ;

};

// ============================================================================
//                     Coordinates Struct Decleration
// ============================================================================
struct Coordinates
{
private:
    Coordinates() = delete;

public:
    Coordinates(Eigen::Ref<Eigen::VectorXd> _q, 
                Eigen::Ref<Eigen::VectorXd> _qd, 
                Eigen::Ref<Eigen::VectorXd> _qdd,
                Eigen::Ref<Eigen::VectorXd> _lgr);

public:
    Eigen::Ref<Eigen::VectorXd> q;
    Eigen::Ref<Eigen::VectorXd> qd;
    Eigen::Ref<Eigen::VectorXd> qdd;
    Eigen::Ref<Eigen::VectorXd> lgr;

// Topology Generalized Coordinates (R and P vectors).
public:    
    Eigen::Ref<Eigen::Vector3d> R_ground = q.segment(0, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_ground = q.segment(3, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbs_l1 = q.segment(7, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbs_l1 = q.segment(10, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbs_l2 = q.segment(14, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbs_l2 = q.segment(17, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbs_l3 = q.segment(21, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbs_l3 = q.segment(24, 4) ;

// Topology Generalized Velocities (dR/dt and dP/dt vectors).
public:
    Eigen::Ref<Eigen::Vector3d> Rd_ground = qd.segment(0, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_ground = qd.segment(3, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbs_l1 = qd.segment(7, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbs_l1 = qd.segment(10, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbs_l2 = qd.segment(14, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbs_l2 = qd.segment(17, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbs_l3 = qd.segment(21, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbs_l3 = qd.segment(24, 4) ;

// Topology Generalized Accelerations (dR2/dt2 and dP2/dt2 vectors).
public:
    Eigen::Ref<Eigen::Vector3d> Rdd_ground = qdd.segment(0, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_ground = qdd.segment(3, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbs_l1 = qdd.segment(7, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbs_l1 = qdd.segment(10, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbs_l2 = qdd.segment(14, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbs_l2 = qdd.segment(17, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbs_l3 = qdd.segment(21, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbs_l3 = qdd.segment(24, 4) ;

// Topology Lagrange Multipliers.
public:
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcs_a = lgr.segment(0, 5) ;
    Eigen::Ref<Eigen::Matrix<double, 1, 1>> L_mcs_act = lgr.segment(5, 1) ;
    Eigen::Ref<Eigen::Matrix<double, 3, 1>> L_jcs_b = lgr.segment(6, 3) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcs_c = lgr.segment(9, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcs_d = lgr.segment(13, 5) ;

 };



// ============================================================================
//                     Topology Class Decleration
// ============================================================================

class Topology
{

public:
    // Topology constants.
    static const int n = 28;
    static const int nc = 28;
    static const int nrows = 15;
    static const int ncols = 2 * 4;
    std::vector<std::string> bodies_names {"ground", "rbs_l1", "rbs_l2", "rbs_l3"};
    std::vector<std::string> joints_names {"jcs_a", "mcs_act", "jcs_b", "jcs_c", "jcs_d"};

public:
    // Topology Constructors.

    // Deleting the default constructor to inforce initialization with the 
    // desired vectors
    Topology() = delete;

    Topology(std::string name, 
            Eigen::Ref<Eigen::VectorXd> q, 
            Eigen::Ref<Eigen::VectorXd> qd, 
            Eigen::Ref<Eigen::VectorXd> qdd,
            Eigen::Ref<Eigen::VectorXd> lgr);

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
    Eigen::VectorXd frc_eq;
    Eigen::VectorXd rct_eq;

    Eigen::VectorXd jac_rows;
    Eigen::VectorXd jac_cols;
    Eigen::VectorXd mas_cols = Eigen::VectorXd::LinSpaced(ncols, 0, ncols-1);

    std::vector<Eigen::MatrixXd> jac_eq;
    std::vector<Eigen::MatrixXd> mas_eq;

    Dict_SI indicies_map;

    void initialize();
    void set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map);
    void map_indicies();
    void assemble(Dict_SI& indicies_map, Dict_SS& interface_map, int rows_offset);
    void eval_constants();


    // Topology Equations Evaluators.
    void eval_pos_eq();
    void eval_vel_eq();
    void eval_acc_eq();
    void eval_frc_eq();
    void eval_jac_eq();
    void eval_mas_eq();
    void eval_reactions();
    void eval_reactions(Eigen::Ref<SparseBlock> jacobian);

// Topology Bodies Indicies from the network graph.                    
public:
    int ground ;
    int rbs_l1 ;
    int rbs_l2 ;
    int rbs_l3 ;


// Configuration Constants.
public:    
    Eigen::Matrix3d Mbar_rbs_l3_jcs_c ;
    double m_ground ;
    Eigen::Matrix3d Mbar_rbs_l2_jcs_b ;
    Eigen::Vector3d ubar_rbs_l1_jcs_a ;
    Eigen::Vector3d F_rbs_l1_gravity ;
    Eigen::Vector4d P_ground ;
    Eigen::Vector3d ubar_ground_jcs_a ;
    Eigen::Vector3d R_ground ;
    Eigen::Matrix3d Mbar_rbs_l1_jcs_b ;
    Eigen::Matrix3d Mbar_ground_jcs_a ;
    Eigen::Vector3d ubar_rbs_l3_jcs_d ;
    Eigen::Vector3d F_rbs_l3_gravity ;
    Eigen::Matrix3d Mbar_rbs_l3_jcs_d ;
    Eigen::Vector3d ubar_rbs_l1_jcs_b ;
    Eigen::Vector3d ubar_rbs_l3_jcs_c ;
    Eigen::Vector3d ubar_rbs_l2_jcs_c ;
    Eigen::Vector3d ubar_rbs_l2_jcs_b ;
    Eigen::Vector4d Pg_ground ;
    Eigen::Matrix3d Mbar_rbs_l1_jcs_a ;
    Eigen::Matrix3d Mbar_rbs_l2_jcs_c ;
    Eigen::Matrix<double, 3, 3> Jbar_ground ;
    Eigen::Vector3d F_rbs_l2_gravity ;
    Eigen::Matrix3d Mbar_ground_jcs_d ;
    Eigen::Vector3d ubar_ground_jcs_d ;

};
