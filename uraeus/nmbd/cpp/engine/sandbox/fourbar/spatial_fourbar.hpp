
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
{

public:
    ConfigurationAssembler ConfigInputs;
    void set_inital_configuration();
    void constructFromJSON(std::string fileName);                

private:
    void populateArguments();

public:
    Eigen::VectorXd q;
    Eigen::VectorXd qd;

    Eigen::Vector3d R_ground {0, 0, 0};
    Eigen::Vector4d P_ground {1, 0, 0, 0};

    Eigen::Vector3d Rd_ground {0, 0, 0};
    Eigen::Vector4d Pd_ground {0, 0, 0, 0};

    Eigen::Vector4d P_rbs_l1 ;
    Eigen::Vector4d Pd_rbs_l2 ;
    Eigen::Vector3d ax2_jcs_c ;
    Eigen::Vector3d Rd_rbs_l1 ;
    Eigen::Matrix<double, 3, 3> Jbar_rbs_l3 ;
    Eigen::Vector3d R_rbs_l2 ;
    Eigen::Vector3d ax1_jcs_a ;
    Eigen::Vector4d P_rbs_l2 ;
    Eigen::Vector4d Pdd_rbs_l1 ;
    std::function<double(double)> UF_mcs_act ;
    double m_rbs_l1 ;
    Eigen::Vector3d ax1_jcs_d ;
    Eigen::Vector4d Pd_rbs_l3 ;
    Eigen::Vector3d ax1_jcs_b ;
    Eigen::Vector4d P_rbs_l3 ;
    double m_rbs_l2 ;
    Eigen::Vector3d Rd_rbs_l2 ;
    Eigen::Matrix<double, 3, 3> Jbar_rbs_l1 ;
    Eigen::Vector3d pt1_jcs_d ;
    Eigen::Vector3d Rdd_rbs_l2 ;
    Eigen::Vector4d Pdd_rbs_l2 ;
    Eigen::Vector3d ax1_jcs_c ;
    Eigen::Vector3d R_rbs_l1 ;
    Eigen::Vector3d Rdd_rbs_l3 ;
    Eigen::Matrix<double, 3, 3> Jbar_rbs_l2 ;
    Eigen::Vector3d pt1_jcs_c ;
    Eigen::Vector3d Rdd_rbs_l1 ;
    Eigen::Vector3d pt1_jcs_b ;
    Eigen::Vector4d Pdd_rbs_l3 ;
    double m_rbs_l3 ;
    Eigen::Vector3d Rd_rbs_l3 ;
    Eigen::Vector4d Pd_rbs_l1 ;
    Eigen::Vector3d pt1_jcs_a ;
    Eigen::Vector3d R_rbs_l3 ;

};


// Declaring the Topology Class and its numerical objects.
// =======================================================
class Topology
{

public:
    // Topology constants.
    int n = 28;
    int nc = 28;
    int nrows = 15;
    int ncols = 2*4;

    // Topology variables
    std::string prefix;
    double t = 0;

    Eigen::VectorXd q0;

    Eigen::VectorXd pos_eq;
    Eigen::VectorXd vel_eq;
    Eigen::VectorXd acc_eq;

    std::vector<Eigen::MatrixXd> jac_eq;
    std::vector<Eigen::MatrixXd> mas_eq;

    Eigen::VectorXd rows = Eigen::VectorXd::LinSpaced(nrows, 0, nrows-1);

    Eigen::VectorXd jac_rows;
    Eigen::VectorXd jac_cols;

    Dict_SI indicies_map;


public:

    // Topology Constructors.
    Topology();
    Topology(std::string);

    // Base Configuration object.
    Configuration config;

    // Topology initializing functions.
    void initialize();
    void assemble(Dict_SI& indicies_map, Dict_SS& interface_map, int rows_offset);
    void set_initial_states();
    void eval_constants();

    // Topology Equations Evaluators.
    void eval_pos_eq();
    void eval_vel_eq();
    void eval_acc_eq();
    void eval_jac_eq();

    // Topology States Setters.
    void set_gen_coordinates(Eigen::Ref<Eigen::VectorXd> q);
    void set_gen_velocities(Eigen::Ref<Eigen::VectorXd> qd);
    void set_gen_accelerations(Eigen::Ref<Eigen::VectorXd> qdd);

private:
    void set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map);

// Topology Bodies Indicies from the network graph.                    
public:
    int ground ;
    int rbs_l1 ;
    int rbs_l2 ;
    int rbs_l3 ;

    Eigen::Matrix<double, 28, 1> q;
    Eigen::Matrix<double, 28, 1> qd;
    Eigen::Matrix<double, 28, 1> qdd;

// Topology Generalized Coordinates (R and P vectors).
public:
    const Eigen::Ref<Eigen::Vector3d> R_rbs_l1 = q.segment(7,3);
    const Eigen::Ref<Eigen::Vector4d> P_rbs_l1 = q.segment(10,4);
    const Eigen::Ref<Eigen::Vector3d> R_rbs_l2 = q.segment(14,3);
    const Eigen::Ref<Eigen::Vector4d> P_rbs_l2 = q.segment(17,4);
    const Eigen::Ref<Eigen::Vector3d> R_rbs_l3 = q.segment(21,3);
    const Eigen::Ref<Eigen::Vector4d> P_rbs_l3 = q.segment(24,4);

// Topology Generalized Velocities (dR/dt and dP/dt vectors).
public:
    const Eigen::Vector3d Rd_ground {0, 0, 0};
    const Eigen::Vector4d Pd_ground {0, 0, 0, 0};
    const Eigen::Ref<Eigen::Vector3d> Rd_rbs_l1 = qd.segment(7,3);
    const Eigen::Ref<Eigen::Vector4d> Pd_rbs_l1 = qd.segment(10,4);
    const Eigen::Ref<Eigen::Vector3d> Rd_rbs_l2 = qd.segment(14,3);
    const Eigen::Ref<Eigen::Vector4d> Pd_rbs_l2 = qd.segment(17,4);
    const Eigen::Ref<Eigen::Vector3d> Rd_rbs_l3 = qd.segment(21,3);
    const Eigen::Ref<Eigen::Vector4d> Pd_rbs_l3 = qd.segment(24,4);

// Topology Generalized Accelerations (dR2/dt2 and dP2/dt2 vectors).
public:
    const Eigen::Vector3d Rdd_ground {0, 0, 0};
    const Eigen::Vector4d Pdd_ground {0, 0, 0, 0};
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbs_l1 = qdd.segment(7,3);
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbs_l1 = qdd.segment(10,4);
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbs_l2 = qdd.segment(14,3);
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbs_l2 = qdd.segment(17,4);
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbs_l3 = qdd.segment(21,3);
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbs_l3 = qdd.segment(24,4);

// Configuration Constants.
public:    
    Eigen::Vector4d P_ground ;
    Eigen::Vector3d ubar_rbs_l2_jcs_c ;
    Eigen::Vector3d ubar_rbs_l1_jcs_a ;
    Eigen::Matrix<double, 3, 3> Jbar_ground ;
    Eigen::Matrix3d Mbar_rbs_l2_jcs_c ;
    Eigen::Vector3d R_ground ;
    Eigen::Vector3d ubar_rbs_l1_jcs_b ;
    Eigen::Vector3d F_rbs_l2_gravity ;
    Eigen::Matrix3d Mbar_ground_jcs_d ;
    Eigen::Matrix3d Mbar_rbs_l2_jcs_b ;
    Eigen::Vector3d ubar_rbs_l2_jcs_b ;
    Eigen::Vector3d ubar_rbs_l3_jcs_c ;
    Eigen::Vector3d ubar_ground_jcs_a ;
    Eigen::Vector3d ubar_rbs_l3_jcs_d ;
    Eigen::Vector3d F_rbs_l1_gravity ;
    Eigen::Matrix3d Mbar_rbs_l1_jcs_b ;
    Eigen::Vector4d Pg_ground ;
    Eigen::Vector3d F_rbs_l3_gravity ;
    Eigen::Matrix3d Mbar_rbs_l1_jcs_a ;
    double m_ground ;
    Eigen::Matrix3d Mbar_rbs_l3_jcs_c ;
    Eigen::Matrix3d Mbar_rbs_l3_jcs_d ;
    Eigen::Vector3d ubar_ground_jcs_d ;
    Eigen::Matrix3d Mbar_ground_jcs_a ;

};
