
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

    std::function<double(double)> UF_fal_strut_Fs ;
    Eigen::Vector3d ax1_jcr_strut ;
    Eigen::Vector3d pt2_fal_strut ;
    Eigen::Vector3d Rdd_rbr_upright ;
    std::function<double(double)> UF_far_tire_F ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_uca ;
    Eigen::Vector4d Pd_rbl_uca ;
    Eigen::Vector4d Pdd_rbr_lca ;
    double m_rbl_tie_rod ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_upper_strut ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_tie_rod ;
    Eigen::Vector4d Pdd_rbl_lower_strut ;
    Eigen::Vector4d Pd_rbr_tie_rod ;
    std::function<double(double)> UF_mcr_wheel_travel ;
    Eigen::Vector3d ax1_jcl_strut_chassis ;
    Eigen::Vector3d pt1_far_tire ;
    Eigen::Vector3d R_rbl_hub ;
    double fal_strut_FL ;
    Eigen::Vector3d pt1_jcl_lca_upright ;
    Eigen::Vector3d ax1_jcl_hub_bearing ;
    Eigen::Vector4d P_rbr_lca ;
    double m_rbr_upright ;
    Eigen::Vector3d R_rbr_uca ;
    Eigen::Vector3d ax2_jcr_strut_lca ;
    Eigen::Vector3d ax1_jcl_lca_upright ;
    Eigen::Vector3d ax1_jcl_uca_upright ;
    double m_rbr_lca ;
    Eigen::Vector3d Rd_rbr_uca ;
    double m_rbl_upright ;
    Eigen::Vector3d ax2_jcr_tie_steering ;
    Eigen::Vector3d pt1_mcl_wheel_travel ;
    Eigen::Vector3d ax1_jcl_lca_chassis ;
    Eigen::Vector3d pt1_fal_tire ;
    Eigen::Vector3d Rdd_rbr_tie_rod ;
    Eigen::Vector4d P_rbr_uca ;
    Eigen::Vector4d P_rbr_upright ;
    Eigen::Vector3d Rdd_rbr_upper_strut ;
    double m_rbr_lower_strut ;
    Eigen::Vector3d pt1_jcl_tie_steering ;
    double m_rbl_uca ;
    Eigen::Vector4d Pd_rbl_hub ;
    Eigen::Vector3d Rd_rbl_upright ;
    Eigen::Vector4d P_rbl_upright ;
    Eigen::Vector4d P_rbr_hub ;
    Eigen::Vector3d Rd_rbl_hub ;
    Eigen::Vector3d pt2_far_strut ;
    Eigen::Vector4d P_rbr_tie_rod ;
    Eigen::Vector4d Pdd_rbl_upper_strut ;
    Eigen::Vector3d Rd_rbr_lower_strut ;
    Eigen::Vector4d Pd_rbr_upper_strut ;
    Eigen::Vector3d pt1_jcr_tie_upright ;
    Eigen::Vector3d Rdd_rbr_hub ;
    Eigen::Vector3d R_rbr_lca ;
    Eigen::Vector3d pt1_mcr_wheel_travel ;
    Eigen::Vector3d pt1_jcl_strut_chassis ;
    Eigen::Vector3d Rd_rbl_tie_rod ;
    Eigen::Vector4d P_rbr_upper_strut ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_upright ;
    Eigen::Vector3d Rdd_rbl_uca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_hub ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_lower_strut ;
    Eigen::Vector4d P_rbl_lca ;
    Eigen::Vector3d ax1_jcr_hub_bearing ;
    Eigen::Vector3d Rd_rbr_upper_strut ;
    Eigen::Vector4d Pd_rbr_uca ;
    Eigen::Vector4d Pdd_rbl_tie_rod ;
    Eigen::Vector3d Rd_rbr_upright ;
    Eigen::Vector4d Pd_rbl_upper_strut ;
    std::function<double(double)> UF_fal_tire_T ;
    Eigen::Vector3d ax1_jcr_strut_lca ;
    Eigen::Vector3d Rd_rbr_tie_rod ;
    Eigen::Vector3d R_rbr_tie_rod ;
    Eigen::Vector3d ax1_jcl_tie_upright ;
    std::function<double(double)> UF_mcr_wheel_lock ;
    Eigen::Vector3d R_rbl_lower_strut ;
    Eigen::Vector3d Rd_rbr_hub ;
    Eigen::Vector3d R_rbl_uca ;
    Eigen::Vector4d Pdd_rbl_upright ;
    Eigen::Vector3d pt1_jcl_strut ;
    Eigen::Vector4d P_rbl_tie_rod ;
    Eigen::Vector4d Pd_rbl_tie_rod ;
    Eigen::Vector3d ax1_jcr_uca_chassis ;
    Eigen::Vector4d Pd_rbr_lca ;
    Eigen::Vector4d Pdd_rbr_upright ;
    Eigen::Vector3d R_rbl_lca ;
    Eigen::Vector4d Pd_rbl_lower_strut ;
    Eigen::Vector3d pt1_jcr_strut_lca ;
    std::function<double(double)> UF_fal_strut_Fd ;
    std::function<double(double)> UF_far_tire_T ;
    Eigen::Vector3d pt1_jcl_uca_chassis ;
    Eigen::Vector3d R_rbl_upright ;
    Eigen::Vector3d R_rbr_hub ;
    Eigen::Vector3d R_rbr_lower_strut ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_uca ;
    Eigen::Vector3d Rdd_rbr_uca ;
    Eigen::Vector3d pt1_jcr_strut_chassis ;
    Eigen::Vector3d ax1_jcr_tie_steering ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_lower_strut ;
    Eigen::Vector3d ax2_jcr_strut_chassis ;
    Eigen::Vector3d pt1_jcr_lca_chassis ;
    Eigen::Vector3d pt1_jcr_hub_bearing ;
    double m_rbl_upper_strut ;
    std::function<double(double)> UF_mcl_wheel_travel ;
    Eigen::Vector3d Rdd_rbl_lower_strut ;
    double m_rbl_lca ;
    Eigen::Vector3d ax2_jcl_strut_lca ;
    Eigen::Vector4d Pd_rbl_lca ;
    Eigen::Vector3d Rd_rbl_upper_strut ;
    Eigen::Vector3d ax2_jcl_tie_steering ;
    Eigen::Vector3d ax1_jcr_lca_upright ;
    Eigen::Vector3d Rdd_rbl_hub ;
    Eigen::Vector3d ax1_jcr_tie_upright ;
    Eigen::Vector4d Pd_rbr_upright ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_hub ;
    Eigen::Vector3d pt2_mcr_wheel_travel ;
    Eigen::Vector4d Pdd_rbl_uca ;
    Eigen::Vector3d ax1_jcr_strut_chassis ;
    Eigen::Vector4d Pdd_rbr_hub ;
    Eigen::Vector4d P_rbl_lower_strut ;
    double m_rbl_hub ;
    Eigen::Vector3d pt1_jcr_uca_upright ;
    Eigen::Vector3d pt1_jcl_lca_chassis ;
    double far_strut_FL ;
    Eigen::Vector3d pt2_mcl_wheel_travel ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_lca ;
    Eigen::Vector3d R_rbl_upper_strut ;
    Eigen::Vector4d Pd_rbr_hub ;
    Eigen::Vector3d pt1_jcr_lca_upright ;
    Eigen::Vector3d ax1_jcl_tie_steering ;
    Eigen::Vector3d pt1_fal_strut ;
    Eigen::Vector4d Pdd_rbr_upper_strut ;
    std::function<double(double)> UF_far_strut_Fs ;
    double m_rbr_uca ;
    Eigen::Vector4d Pd_rbl_upright ;
    Eigen::Vector4d Pdd_rbl_lca ;
    Eigen::Vector3d Rdd_rbr_lca ;
    std::function<double(double)> UF_far_strut_Fd ;
    Eigen::Vector3d pt1_jcl_tie_upright ;
    double m_rbr_hub ;
    std::function<double(double)> UF_mcl_wheel_lock ;
    Eigen::Vector3d ax2_jcl_strut_chassis ;
    Eigen::Vector4d P_rbl_uca ;
    double m_rbr_upper_strut ;
    Eigen::Vector3d pt1_jcr_strut ;
    std::function<double(double)> UF_fal_tire_F ;
    Eigen::Vector3d Rd_rbr_lca ;
    Eigen::Vector4d Pdd_rbr_lower_strut ;
    Eigen::Vector4d P_rbl_hub ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_upper_strut ;
    Eigen::Vector3d Rdd_rbl_tie_rod ;
    Eigen::Vector4d P_rbl_upper_strut ;
    Eigen::Vector3d Rdd_rbl_upper_strut ;
    Eigen::Vector3d pt1_jcl_strut_lca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_lca ;
    Eigen::Vector4d Pd_rbr_lower_strut ;
    Eigen::Vector3d Rdd_rbr_lower_strut ;
    Eigen::Vector4d Pdd_rbl_hub ;
    Eigen::Vector3d pt1_jcr_uca_chassis ;
    Eigen::Vector3d pt1_jcl_hub_bearing ;
    double m_rbr_tie_rod ;
    Eigen::Vector3d R_rbr_upright ;
    Eigen::Vector4d P_rbr_lower_strut ;
    Eigen::Vector3d ax1_jcr_lca_chassis ;
    Eigen::Vector3d Rdd_rbl_upright ;
    double m_rbl_lower_strut ;
    Eigen::Vector4d Pdd_rbr_tie_rod ;
    Eigen::Vector3d R_rbl_tie_rod ;
    Eigen::Vector3d ax1_jcr_uca_upright ;
    Eigen::Vector3d Rd_rbl_lca ;
    Eigen::Vector3d ax1_jcl_uca_chassis ;
    Eigen::Vector3d Rdd_rbl_lca ;
    Eigen::Vector3d Rd_rbl_lower_strut ;
    Eigen::Vector3d Rd_rbl_uca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_upright ;
    Eigen::Vector3d ax1_jcl_strut ;
    Eigen::Vector3d pt1_jcr_tie_steering ;
    Eigen::Vector3d R_rbr_upper_strut ;
    Eigen::Vector3d pt1_jcl_uca_upright ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_tie_rod ;
    Eigen::Vector3d ax1_jcl_strut_lca ;
    Eigen::Vector4d Pdd_rbr_uca ;
    Eigen::Vector3d pt1_far_strut ;

};


// Declaring the Topology Class and its numerical objects.
// =======================================================
class Topology
{

public:
    // Topology constants.
    static const int n = 105;
    static const int nc = 105;
    static const int nrows = 64;
    static const int ncols = 2*15;

    // Topology variables
    std::string prefix;
    double t = 0;

    Eigen::VectorXd q0;

    Eigen::Matrix<double, n, 1> q;
    Eigen::Matrix<double, n, 1> qd;
    Eigen::Matrix<double, n, 1> qdd;

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
    void set_gen_coordinates(const Eigen::Ref<Eigen::VectorXd>& q);
    void set_gen_velocities(const Eigen::Ref<Eigen::VectorXd>& qd);
    void set_gen_accelerations(const Eigen::Ref<Eigen::VectorXd>& qdd);

private:
    void set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map);

// Topology Bodies Indicies from the network graph.                    
public:
    int ground ;
    int rbr_uca ;
    int rbl_uca ;
    int rbr_lca ;
    int rbl_lca ;
    int rbr_upright ;
    int rbl_upright ;
    int rbr_upper_strut ;
    int rbl_upper_strut ;
    int rbr_lower_strut ;
    int rbl_lower_strut ;
    int rbr_tie_rod ;
    int rbl_tie_rod ;
    int rbr_hub ;
    int rbl_hub ;

// Topology Generalized Coordinates (R and P vectors).
public:
    const Eigen::Ref<Eigen::Vector3d> R_rbr_uca = q.segment(7, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbr_uca = q.segment(10, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbl_uca = q.segment(14, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbl_uca = q.segment(17, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbr_lca = q.segment(21, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbr_lca = q.segment(24, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbl_lca = q.segment(28, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbl_lca = q.segment(31, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbr_upright = q.segment(35, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbr_upright = q.segment(38, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbl_upright = q.segment(42, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbl_upright = q.segment(45, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbr_upper_strut = q.segment(49, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbr_upper_strut = q.segment(52, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbl_upper_strut = q.segment(56, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbl_upper_strut = q.segment(59, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbr_lower_strut = q.segment(63, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbr_lower_strut = q.segment(66, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbl_lower_strut = q.segment(70, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbl_lower_strut = q.segment(73, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbr_tie_rod = q.segment(77, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbr_tie_rod = q.segment(80, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbl_tie_rod = q.segment(84, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbl_tie_rod = q.segment(87, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbr_hub = q.segment(91, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbr_hub = q.segment(94, 4) ;
    const Eigen::Ref<Eigen::Vector3d> R_rbl_hub = q.segment(98, 3) ;
    const Eigen::Ref<Eigen::Vector4d> P_rbl_hub = q.segment(101, 4) ;

// Topology Generalized Velocities (dR/dt and dP/dt vectors).
public:
    const Eigen::Ref<Eigen::Vector3d> Rd_ground = qd.segment(0, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_ground = qd.segment(3, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbr_uca = qd.segment(7, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbr_uca = qd.segment(10, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbl_uca = qd.segment(14, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbl_uca = qd.segment(17, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbr_lca = qd.segment(21, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbr_lca = qd.segment(24, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbl_lca = qd.segment(28, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbl_lca = qd.segment(31, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbr_upright = qd.segment(35, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbr_upright = qd.segment(38, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbl_upright = qd.segment(42, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbl_upright = qd.segment(45, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbr_upper_strut = qd.segment(49, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbr_upper_strut = qd.segment(52, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbl_upper_strut = qd.segment(56, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbl_upper_strut = qd.segment(59, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbr_lower_strut = qd.segment(63, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbr_lower_strut = qd.segment(66, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbl_lower_strut = qd.segment(70, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbl_lower_strut = qd.segment(73, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbr_tie_rod = qd.segment(77, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbr_tie_rod = qd.segment(80, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbl_tie_rod = qd.segment(84, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbl_tie_rod = qd.segment(87, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbr_hub = qd.segment(91, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbr_hub = qd.segment(94, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rd_rbl_hub = qd.segment(98, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pd_rbl_hub = qd.segment(101, 4) ;

// Topology Generalized Accelerations (dR2/dt2 and dP2/dt2 vectors).
public:
    const Eigen::Ref<Eigen::Vector3d> Rdd_ground = qdd.segment(0, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_ground = qdd.segment(3, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbr_uca = qdd.segment(7, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbr_uca = qdd.segment(10, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbl_uca = qdd.segment(14, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbl_uca = qdd.segment(17, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbr_lca = qdd.segment(21, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbr_lca = qdd.segment(24, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbl_lca = qdd.segment(28, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbl_lca = qdd.segment(31, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbr_upright = qdd.segment(35, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbr_upright = qdd.segment(38, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbl_upright = qdd.segment(42, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbl_upright = qdd.segment(45, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbr_upper_strut = qdd.segment(49, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbr_upper_strut = qdd.segment(52, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbl_upper_strut = qdd.segment(56, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbl_upper_strut = qdd.segment(59, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbr_lower_strut = qdd.segment(63, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbr_lower_strut = qdd.segment(66, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbl_lower_strut = qdd.segment(70, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbl_lower_strut = qdd.segment(73, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbr_tie_rod = qdd.segment(77, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbr_tie_rod = qdd.segment(80, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbl_tie_rod = qdd.segment(84, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbl_tie_rod = qdd.segment(87, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbr_hub = qdd.segment(91, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbr_hub = qdd.segment(94, 4) ;
    const Eigen::Ref<Eigen::Vector3d> Rdd_rbl_hub = qdd.segment(98, 3) ;
    const Eigen::Ref<Eigen::Vector4d> Pdd_rbl_hub = qdd.segment(101, 4) ;

// Configuration Constants.
public:    
    Eigen::Matrix3d Mbar_rbr_upper_strut_jcr_strut ;
    Eigen::Vector3d F_rbr_tie_rod_gravity ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_lca_upright ;
    Eigen::Vector3d F_rbr_upright_gravity ;
    Eigen::Vector3d T_rbr_lower_strut_far_strut ;
    Eigen::Vector3d ubar_ground_mcl_wheel_travel ;
    Eigen::Vector3d ubar_ground_jcl_uca_chassis ;
    Eigen::Vector3d ubar_rbr_tie_rod_jcr_tie_upright ;
    Eigen::Matrix3d Mbar_ground_jcr_lca_chassis ;
    Eigen::Vector3d ubar_ground_mcr_wheel_travel ;
    Eigen::Matrix3d Mbar_rbl_tie_rod_jcl_tie_steering ;
    Eigen::Vector3d ubar_rbl_upper_strut_fal_strut ;
    Eigen::Vector3d ubar_rbl_lca_jcl_strut_lca ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_lca_upright ;
    Eigen::Vector3d ubar_rbr_tie_rod_jcr_tie_steering ;
    Eigen::Vector3d F_rbr_lca_gravity ;
    Eigen::Vector3d T_rbl_lower_strut_fal_strut ;
    Eigen::Vector3d ubar_rbl_upright_jcl_uca_upright ;
    Eigen::Matrix3d Mbar_ground_jcl_tie_steering ;
    Eigen::Vector3d ubar_rbr_upright_jcr_uca_upright ;
    Eigen::Vector3d ubar_rbr_lca_jcr_strut_lca ;
    Eigen::Vector3d ubar_ground_jcr_strut_chassis ;
    Eigen::Vector3d ubar_ground_jcl_tie_steering ;
    Eigen::Vector3d ubar_rbr_upright_jcr_hub_bearing ;
    Eigen::Vector3d F_rbr_lower_strut_gravity ;
    Eigen::Matrix3d Mbar_rbl_lower_strut_jcl_strut_lca ;
    Eigen::Matrix3d Mbar_rbl_uca_jcl_uca_chassis ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_uca_upright ;
    Eigen::Vector3d F_rbr_upper_strut_gravity ;
    Eigen::Vector3d ubar_rbl_tie_rod_jcl_tie_steering ;
    Eigen::Matrix3d Mbar_rbl_lca_jcl_lca_chassis ;
    Eigen::Vector3d ubar_rbl_lower_strut_fal_strut ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_uca_upright ;
    Eigen::Vector3d ubar_rbr_upper_strut_jcr_strut ;
    Eigen::Matrix3d Mbar_rbl_lca_jcl_strut_lca ;
    Eigen::Vector3d ubar_rbl_lca_jcl_lca_upright ;
    Eigen::Matrix3d Mbar_rbr_lca_jcr_strut_lca ;
    Eigen::Vector3d ubar_rbl_upright_jcl_lca_upright ;
    Eigen::Matrix3d Mbar_ground_jcr_uca_chassis ;
    Eigen::Vector3d F_rbr_uca_gravity ;
    Eigen::Vector3d ubar_rbr_hub_mcr_wheel_travel ;
    Eigen::Vector3d F_rbl_lca_gravity ;
    Eigen::Vector3d ubar_rbr_lower_strut_jcr_strut_lca ;
    Eigen::Vector3d ubar_rbl_lower_strut_jcl_strut ;
    Eigen::Matrix3d Mbar_ground_jcl_uca_chassis ;
    Eigen::Matrix3d Mbar_rbr_lower_strut_jcr_strut ;
    Eigen::Vector3d ubar_rbr_upright_jcr_lca_upright ;
    Eigen::Vector3d ubar_rbl_upright_jcl_tie_upright ;
    Eigen::Vector3d F_rbl_upper_strut_gravity ;
    Eigen::Matrix3d Mbar_rbr_uca_jcr_uca_upright ;
    Eigen::Vector3d ubar_ground_jcl_lca_chassis ;
    Eigen::Vector3d F_rbl_upright_gravity ;
    Eigen::Vector3d ubar_ground_jcr_tie_steering ;
    Eigen::Vector3d ubar_rbr_lower_strut_far_strut ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_hub_bearing ;
    Eigen::Vector3d ubar_rbr_uca_jcr_uca_upright ;
    Eigen::Matrix3d Mbar_rbr_tie_rod_jcr_tie_upright ;
    Eigen::Vector3d R_ground ;
    Eigen::Matrix3d Mbar_rbl_lca_jcl_lca_upright ;
    Eigen::Matrix3d Mbar_ground_jcr_strut_chassis ;
    Eigen::Vector3d ubar_rbl_uca_jcl_uca_chassis ;
    Eigen::Vector3d ubar_rbl_hub_fal_tire ;
    Eigen::Matrix3d Mbar_rbr_uca_jcr_uca_chassis ;
    Eigen::Vector3d ubar_ground_jcl_strut_chassis ;
    Eigen::Matrix3d Mbar_rbl_lower_strut_jcl_strut ;
    Eigen::Vector3d ubar_rbr_upright_jcr_tie_upright ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_hub_bearing ;
    Eigen::Vector3d ubar_rbr_lca_jcr_lca_chassis ;
    Eigen::Vector3d ubar_rbl_tie_rod_jcl_tie_upright ;
    Eigen::Vector4d P_ground ;
    Eigen::Vector3d T_rbr_upper_strut_far_strut ;
    Eigen::Vector3d ubar_rbr_upper_strut_jcr_strut_chassis ;
    Eigen::Matrix3d Mbar_rbr_lca_jcr_lca_upright ;
    Eigen::Vector3d ubar_rbr_lca_jcr_lca_upright ;
    Eigen::Matrix3d Mbar_rbr_lower_strut_jcr_strut_lca ;
    Eigen::Vector4d Pg_ground ;
    Eigen::Vector3d F_rbl_tie_rod_gravity ;
    Eigen::Matrix3d Mbar_ground_jcl_lca_chassis ;
    Eigen::Vector3d ubar_rbr_hub_jcr_hub_bearing ;
    Eigen::Matrix3d Mbar_rbr_upper_strut_jcr_strut_chassis ;
    Eigen::Vector3d ubar_rbl_lca_jcl_lca_chassis ;
    Eigen::Vector3d ubar_rbr_upper_strut_far_strut ;
    Eigen::Vector3d ubar_rbl_upper_strut_jcl_strut_chassis ;
    Eigen::Vector3d F_rbl_hub_gravity ;
    Eigen::Vector3d ubar_ground_jcr_uca_chassis ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_tie_upright ;
    Eigen::Vector3d ubar_rbr_lower_strut_jcr_strut ;
    Eigen::Vector3d ubar_rbl_hub_jcl_hub_bearing ;
    Eigen::Matrix3d Mbar_rbl_hub_jcl_hub_bearing ;
    Eigen::Matrix3d Mbar_rbl_tie_rod_jcl_tie_upright ;
    Eigen::Vector3d F_rbl_lower_strut_gravity ;
    Eigen::Vector3d ubar_ground_fal_tire ;
    Eigen::Matrix<double, 3, 3> Jbar_ground ;
    Eigen::Vector3d T_rbl_upper_strut_fal_strut ;
    Eigen::Matrix3d Mbar_ground_jcl_strut_chassis ;
    Eigen::Vector3d ubar_rbr_uca_jcr_uca_chassis ;
    Eigen::Matrix3d Mbar_rbl_uca_jcl_uca_upright ;
    Eigen::Vector3d ubar_rbl_upright_jcl_hub_bearing ;
    Eigen::Vector3d F_rbl_uca_gravity ;
    Eigen::Matrix3d Mbar_rbl_upper_strut_jcl_strut_chassis ;
    Eigen::Vector3d ubar_ground_far_tire ;
    Eigen::Matrix3d Mbar_ground_jcr_tie_steering ;
    Eigen::Vector3d ubar_rbl_hub_mcl_wheel_travel ;
    Eigen::Vector3d ubar_rbr_hub_far_tire ;
    Eigen::Vector3d ubar_rbl_lower_strut_jcl_strut_lca ;
    Eigen::Vector3d ubar_rbl_uca_jcl_uca_upright ;
    Eigen::Matrix3d Mbar_rbl_upper_strut_jcl_strut ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_tie_upright ;
    double m_ground ;
    Eigen::Vector3d ubar_ground_jcr_lca_chassis ;
    Eigen::Matrix3d Mbar_rbr_lca_jcr_lca_chassis ;
    Eigen::Matrix3d Mbar_rbr_tie_rod_jcr_tie_steering ;
    Eigen::Matrix3d Mbar_rbr_hub_jcr_hub_bearing ;
    Eigen::Vector3d ubar_rbl_upper_strut_jcl_strut ;
    Eigen::Vector3d F_rbr_hub_gravity ;

};
