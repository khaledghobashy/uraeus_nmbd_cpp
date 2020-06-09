
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

    double fal_strut_FL ;
    Eigen::Vector3d ax1_jcr_tie_steering ;
    Eigen::Vector4d Pd_rbr_hub ;
    Eigen::Vector3d pt1_jcl_lca_upright ;
    Eigen::Vector3d pt1_jcr_lca_upright ;
    Eigen::Vector3d pt2_mcr_wheel_travel ;
    Eigen::Vector3d ax1_jcl_strut ;
    std::function<Eigen::Vector3d(double)> UF_far_tire_T ;
    Eigen::Vector3d Rd_rbl_hub ;
    Eigen::Vector3d pt1_jcl_tie_upright ;
    Eigen::Vector3d pt1_mcr_wheel_travel ;
    Eigen::Vector4d Pd_rbl_upper_strut ;
    Eigen::Vector3d R_rbl_lca ;
    Eigen::Vector4d Pd_rbr_lower_strut ;
    Eigen::Vector4d Pd_rbl_tie_rod ;
    double m_rbl_hub ;
    Eigen::Vector4d Pd_rbr_upper_strut ;
    std::function<Eigen::Vector3d(double)> UF_fal_tire_T ;
    Eigen::Vector3d R_rbr_upright ;
    Eigen::Vector3d ax2_jcl_tie_steering ;
    Eigen::Vector3d pt1_jcl_strut ;
    Eigen::Vector3d ax1_jcl_lca_chassis ;
    Eigen::Vector3d R_rbr_hub ;
    Eigen::Vector3d ax2_jcr_tie_steering ;
    Eigen::Vector4d Pdd_rbr_upper_strut ;
    Eigen::Vector4d Pd_rbl_upright ;
    Eigen::Vector3d ax1_jcl_hub_bearing ;
    Eigen::Vector4d Pdd_rbl_hub ;
    Eigen::Vector3d Rdd_rbl_upper_strut ;
    double m_rbl_lca ;
    Eigen::Vector3d Rd_rbl_upright ;
    Eigen::Vector3d Rdd_rbl_tie_rod ;
    Eigen::Vector3d pt1_fal_tire ;
    double m_rbr_upper_strut ;
    Eigen::Vector3d ax2_jcl_strut_lca ;
    Eigen::Vector3d pt1_jcl_strut_lca ;
    double m_rbr_uca ;
    Eigen::Vector3d ax1_jcr_tie_upright ;
    Eigen::Vector3d pt1_jcr_strut_chassis ;
    Eigen::Vector3d Rdd_rbl_lower_strut ;
    Eigen::Vector4d Pdd_rbr_uca ;
    Eigen::Vector3d Rd_rbr_lower_strut ;
    Eigen::Vector3d ax2_jcl_strut_chassis ;
    Eigen::Vector4d Pdd_rbl_lower_strut ;
    Eigen::Vector4d Pd_rbr_upright ;
    Eigen::Vector4d Pd_rbr_lca ;
    std::function<double(double)> UF_mcr_wheel_travel ;
    Eigen::Vector4d P_rbr_lca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_upright ;
    double m_rbr_hub ;
    double m_rbl_upper_strut ;
    Eigen::Vector3d Rdd_rbr_upright ;
    Eigen::Vector3d ax1_jcr_uca_upright ;
    Eigen::Vector3d pt1_jcl_uca_upright ;
    std::function<double(double)> UF_mcl_wheel_travel ;
    Eigen::Vector3d Rd_rbr_uca ;
    std::function<Eigen::Vector3d(double)> UF_far_tire_F ;
    Eigen::Vector4d Pdd_rbl_uca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_upper_strut ;
    double m_rbl_uca ;
    Eigen::Vector3d ax1_jcl_tie_upright ;
    Eigen::Vector3d pt1_jcl_hub_bearing ;
    double m_rbl_upright ;
    Eigen::Vector3d Rd_rbr_upright ;
    Eigen::Vector3d ax1_jcr_strut_chassis ;
    Eigen::Vector3d pt1_mcl_wheel_travel ;
    Eigen::Vector3d R_rbl_tie_rod ;
    Eigen::Vector4d Pd_rbl_hub ;
    Eigen::Vector3d ax1_jcl_strut_lca ;
    Eigen::Vector4d P_rbl_lca ;
    Eigen::Vector3d Rdd_rbl_upright ;
    double m_rbr_lca ;
    Eigen::Vector4d Pdd_rbl_tie_rod ;
    Eigen::Vector3d ax1_jcr_hub_bearing ;
    Eigen::Vector3d pt1_jcl_tie_steering ;
    Eigen::Vector3d R_rbl_upright ;
    Eigen::Vector3d R_rbl_uca ;
    Eigen::Vector3d Rd_rbl_lower_strut ;
    Eigen::Vector4d P_rbr_upright ;
    Eigen::Vector3d Rd_rbl_lca ;
    Eigen::Vector4d Pdd_rbr_hub ;
    Eigen::Vector3d pt2_far_strut ;
    Eigen::Vector3d R_rbr_lca ;
    Eigen::Vector3d Rdd_rbr_hub ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_hub ;
    double m_rbl_tie_rod ;
    Eigen::Vector4d Pd_rbl_uca ;
    Eigen::Vector4d Pd_rbr_tie_rod ;
    Eigen::Vector3d ax1_jcr_strut ;
    Eigen::Vector3d R_rbr_tie_rod ;
    Eigen::Vector3d R_rbl_lower_strut ;
    Eigen::Vector3d pt1_jcr_strut_lca ;
    Eigen::Vector3d Rd_rbr_hub ;
    Eigen::Vector3d Rd_rbl_uca ;
    Eigen::Vector3d pt1_jcl_uca_chassis ;
    Eigen::Vector3d Rd_rbl_upper_strut ;
    Eigen::Vector4d P_rbl_lower_strut ;
    Eigen::Vector3d pt2_fal_strut ;
    double m_rbr_lower_strut ;
    Eigen::Vector3d ax1_jcr_uca_chassis ;
    Eigen::Vector3d Rd_rbr_upper_strut ;
    Eigen::Vector3d ax1_jcr_strut_lca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_upright ;
    Eigen::Vector3d pt1_far_tire ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_tie_rod ;
    Eigen::Vector3d Rd_rbr_lca ;
    Eigen::Vector3d ax1_jcr_lca_upright ;
    std::function<double(double)> UF_mcl_wheel_lock ;
    Eigen::Vector3d Rdd_rbl_lca ;
    Eigen::Vector3d R_rbr_uca ;
    Eigen::Vector3d ax1_jcr_lca_chassis ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_uca ;
    Eigen::Vector3d pt1_jcr_tie_steering ;
    Eigen::Vector3d Rdd_rbr_lca ;
    Eigen::Vector4d P_rbl_upright ;
    Eigen::Vector3d R_rbl_upper_strut ;
    Eigen::Vector3d pt1_jcr_uca_upright ;
    Eigen::Vector3d pt1_jcl_strut_chassis ;
    Eigen::Vector3d ax2_jcr_strut_lca ;
    Eigen::Vector4d Pd_rbl_lca ;
    Eigen::Vector4d Pd_rbl_lower_strut ;
    Eigen::Vector4d P_rbl_tie_rod ;
    Eigen::Vector4d Pdd_rbr_tie_rod ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_lca ;
    Eigen::Vector3d pt1_jcr_lca_chassis ;
    Eigen::Vector3d pt1_far_strut ;
    Eigen::Vector3d ax1_jcl_strut_chassis ;
    Eigen::Vector3d Rdd_rbr_lower_strut ;
    Eigen::Vector4d Pdd_rbr_upright ;
    std::function<double(double)> UF_mcr_wheel_lock ;
    Eigen::Vector3d ax1_jcl_uca_chassis ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_tie_rod ;
    std::function<double(double)> UF_fal_strut_Fd ;
    Eigen::Vector3d pt1_jcr_strut ;
    Eigen::Vector3d ax1_jcl_tie_steering ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_lower_strut ;
    Eigen::Vector4d Pdd_rbl_upper_strut ;
    double far_strut_FL ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_upper_strut ;
    Eigen::Vector3d Rdd_rbr_upper_strut ;
    std::function<double(double)> UF_far_strut_Fd ;
    Eigen::Vector4d P_rbl_hub ;
    Eigen::Vector4d Pdd_rbr_lca ;
    Eigen::Vector4d P_rbl_upper_strut ;
    Eigen::Vector4d P_rbr_lower_strut ;
    Eigen::Vector3d Rdd_rbl_uca ;
    Eigen::Vector3d Rd_rbl_tie_rod ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_hub ;
    Eigen::Vector3d pt1_jcr_uca_chassis ;
    std::function<double(double)> UF_far_strut_Fs ;
    double m_rbr_tie_rod ;
    Eigen::Vector3d ax1_jcl_uca_upright ;
    Eigen::Vector3d Rdd_rbr_tie_rod ;
    Eigen::Vector4d Pd_rbr_uca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbr_lca ;
    Eigen::Vector4d Pdd_rbl_upright ;
    Eigen::Vector4d P_rbr_tie_rod ;
    Eigen::Vector3d pt1_jcr_hub_bearing ;
    Eigen::Vector3d pt1_jcr_tie_upright ;
    Eigen::Vector3d Rdd_rbl_hub ;
    std::function<Eigen::Vector3d(double)> UF_fal_tire_F ;
    Eigen::Vector4d Pdd_rbr_lower_strut ;
    Eigen::Vector3d pt2_mcl_wheel_travel ;
    Eigen::Vector4d P_rbr_upper_strut ;
    Eigen::Vector4d P_rbr_uca ;
    double m_rbr_upright ;
    Eigen::Vector3d ax1_jcl_lca_upright ;
    Eigen::Vector3d Rdd_rbr_uca ;
    double m_rbl_lower_strut ;
    Eigen::Vector3d R_rbr_upper_strut ;
    Eigen::Vector4d P_rbr_hub ;
    Eigen::Vector3d R_rbr_lower_strut ;
    Eigen::Vector3d R_rbl_hub ;
    Eigen::Vector3d pt1_jcl_lca_chassis ;
    std::function<double(double)> UF_fal_strut_Fs ;
    Eigen::Vector4d P_rbl_uca ;
    Eigen::Vector3d pt1_fal_strut ;
    Eigen::Vector3d ax2_jcr_strut_chassis ;
    Eigen::Vector3d Rd_rbr_tie_rod ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_uca ;
    Eigen::Vector4d Pdd_rbl_lca ;
    Eigen::Matrix<double, 3, 3> Jbar_rbl_lower_strut ;

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
    Eigen::Ref<Eigen::Vector3d> R_rbr_uca = q.segment(7, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbr_uca = q.segment(10, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbl_uca = q.segment(14, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbl_uca = q.segment(17, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbr_lca = q.segment(21, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbr_lca = q.segment(24, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbl_lca = q.segment(28, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbl_lca = q.segment(31, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbr_upright = q.segment(35, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbr_upright = q.segment(38, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbl_upright = q.segment(42, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbl_upright = q.segment(45, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbr_upper_strut = q.segment(49, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbr_upper_strut = q.segment(52, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbl_upper_strut = q.segment(56, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbl_upper_strut = q.segment(59, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbr_lower_strut = q.segment(63, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbr_lower_strut = q.segment(66, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbl_lower_strut = q.segment(70, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbl_lower_strut = q.segment(73, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbr_tie_rod = q.segment(77, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbr_tie_rod = q.segment(80, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbl_tie_rod = q.segment(84, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbl_tie_rod = q.segment(87, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbr_hub = q.segment(91, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbr_hub = q.segment(94, 4) ;
    Eigen::Ref<Eigen::Vector3d> R_rbl_hub = q.segment(98, 3) ;
    Eigen::Ref<Eigen::Vector4d> P_rbl_hub = q.segment(101, 4) ;

// Topology Generalized Velocities (dR/dt and dP/dt vectors).
public:
    Eigen::Ref<Eigen::Vector3d> Rd_ground = qd.segment(0, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_ground = qd.segment(3, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbr_uca = qd.segment(7, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbr_uca = qd.segment(10, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbl_uca = qd.segment(14, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbl_uca = qd.segment(17, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbr_lca = qd.segment(21, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbr_lca = qd.segment(24, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbl_lca = qd.segment(28, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbl_lca = qd.segment(31, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbr_upright = qd.segment(35, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbr_upright = qd.segment(38, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbl_upright = qd.segment(42, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbl_upright = qd.segment(45, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbr_upper_strut = qd.segment(49, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbr_upper_strut = qd.segment(52, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbl_upper_strut = qd.segment(56, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbl_upper_strut = qd.segment(59, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbr_lower_strut = qd.segment(63, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbr_lower_strut = qd.segment(66, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbl_lower_strut = qd.segment(70, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbl_lower_strut = qd.segment(73, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbr_tie_rod = qd.segment(77, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbr_tie_rod = qd.segment(80, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbl_tie_rod = qd.segment(84, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbl_tie_rod = qd.segment(87, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbr_hub = qd.segment(91, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbr_hub = qd.segment(94, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rd_rbl_hub = qd.segment(98, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pd_rbl_hub = qd.segment(101, 4) ;

// Topology Generalized Accelerations (dR2/dt2 and dP2/dt2 vectors).
public:
    Eigen::Ref<Eigen::Vector3d> Rdd_ground = qdd.segment(0, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_ground = qdd.segment(3, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbr_uca = qdd.segment(7, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbr_uca = qdd.segment(10, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbl_uca = qdd.segment(14, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbl_uca = qdd.segment(17, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbr_lca = qdd.segment(21, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbr_lca = qdd.segment(24, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbl_lca = qdd.segment(28, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbl_lca = qdd.segment(31, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbr_upright = qdd.segment(35, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbr_upright = qdd.segment(38, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbl_upright = qdd.segment(42, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbl_upright = qdd.segment(45, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbr_upper_strut = qdd.segment(49, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbr_upper_strut = qdd.segment(52, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbl_upper_strut = qdd.segment(56, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbl_upper_strut = qdd.segment(59, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbr_lower_strut = qdd.segment(63, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbr_lower_strut = qdd.segment(66, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbl_lower_strut = qdd.segment(70, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbl_lower_strut = qdd.segment(73, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbr_tie_rod = qdd.segment(77, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbr_tie_rod = qdd.segment(80, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbl_tie_rod = qdd.segment(84, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbl_tie_rod = qdd.segment(87, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbr_hub = qdd.segment(91, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbr_hub = qdd.segment(94, 4) ;
    Eigen::Ref<Eigen::Vector3d> Rdd_rbl_hub = qdd.segment(98, 3) ;
    Eigen::Ref<Eigen::Vector4d> Pdd_rbl_hub = qdd.segment(101, 4) ;

// Topology Lagrange Multipliers.
public:
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcr_uca_chassis = lgr.segment(0, 5) ;
    Eigen::Ref<Eigen::Matrix<double, 3, 1>> L_jcr_uca_upright = lgr.segment(5, 3) ;
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcl_uca_chassis = lgr.segment(8, 5) ;
    Eigen::Ref<Eigen::Matrix<double, 3, 1>> L_jcl_uca_upright = lgr.segment(13, 3) ;
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcr_lca_chassis = lgr.segment(16, 5) ;
    Eigen::Ref<Eigen::Matrix<double, 3, 1>> L_jcr_lca_upright = lgr.segment(21, 3) ;
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcl_lca_chassis = lgr.segment(24, 5) ;
    Eigen::Ref<Eigen::Matrix<double, 3, 1>> L_jcl_lca_upright = lgr.segment(29, 3) ;
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcr_hub_bearing = lgr.segment(32, 5) ;
    Eigen::Ref<Eigen::Matrix<double, 1, 1>> L_mcr_wheel_lock = lgr.segment(37, 1) ;
    Eigen::Ref<Eigen::Matrix<double, 5, 1>> L_jcl_hub_bearing = lgr.segment(38, 5) ;
    Eigen::Ref<Eigen::Matrix<double, 1, 1>> L_mcl_wheel_lock = lgr.segment(43, 1) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcr_strut_chassis = lgr.segment(44, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcr_strut = lgr.segment(48, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcl_strut_chassis = lgr.segment(52, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcl_strut = lgr.segment(56, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcr_strut_lca = lgr.segment(60, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcl_strut_lca = lgr.segment(64, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcr_tie_steering = lgr.segment(68, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 3, 1>> L_jcr_tie_upright = lgr.segment(72, 3) ;
    Eigen::Ref<Eigen::Matrix<double, 4, 1>> L_jcl_tie_steering = lgr.segment(75, 4) ;
    Eigen::Ref<Eigen::Matrix<double, 3, 1>> L_jcl_tie_upright = lgr.segment(79, 3) ;
    Eigen::Ref<Eigen::Matrix<double, 1, 1>> L_mcr_wheel_travel = lgr.segment(82, 1) ;
    Eigen::Ref<Eigen::Matrix<double, 1, 1>> L_mcl_wheel_travel = lgr.segment(83, 1) ;

 };



// ============================================================================
//                     Topology Class Decleration
// ============================================================================

class Topology
{

public:
    // Topology constants.
    static const int n = 105;
    static const int nc = 105;
    static const int nrows = 64;
    static const int ncols = 2 * 15;
    std::vector<std::string> bodies_names {"ground", "rbr_uca", "rbl_uca", "rbr_lca", "rbl_lca", "rbr_upright", "rbl_upright", "rbr_upper_strut", "rbl_upper_strut", "rbr_lower_strut", "rbl_lower_strut", "rbr_tie_rod", "rbl_tie_rod", "rbr_hub", "rbl_hub"};
    std::vector<std::string> joints_names {"jcr_uca_chassis", "jcr_uca_upright", "jcl_uca_chassis", "jcl_uca_upright", "jcr_lca_chassis", "jcr_lca_upright", "jcl_lca_chassis", "jcl_lca_upright", "jcr_hub_bearing", "mcr_wheel_lock", "jcl_hub_bearing", "mcl_wheel_lock", "jcr_strut_chassis", "jcr_strut", "jcl_strut_chassis", "jcl_strut", "jcr_strut_lca", "jcl_strut_lca", "jcr_tie_steering", "jcr_tie_upright", "jcl_tie_steering", "jcl_tie_upright", "mcr_wheel_travel", "mcl_wheel_travel"};

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


// Configuration Constants.
public:    
    Eigen::Vector3d T_rbl_upper_strut_fal_strut ;
    Eigen::Vector3d ubar_rbl_upright_jcl_hub_bearing ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_lca_upright ;
    Eigen::Vector3d R_ground ;
    Eigen::Matrix3d Mbar_rbr_upper_strut_jcr_strut ;
    Eigen::Vector3d ubar_rbl_hub_mcl_wheel_travel ;
    Eigen::Vector3d F_rbr_upright_gravity ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_hub_bearing ;
    Eigen::Vector3d ubar_ground_jcr_lca_chassis ;
    Eigen::Vector3d ubar_rbr_lower_strut_jcr_strut_lca ;
    Eigen::Vector3d F_rbr_uca_gravity ;
    Eigen::Matrix3d Mbar_rbr_tie_rod_jcr_tie_upright ;
    Eigen::Vector3d ubar_ground_jcl_tie_steering ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_tie_upright ;
    Eigen::Vector3d ubar_ground_jcr_uca_chassis ;
    Eigen::Vector3d ubar_rbl_uca_jcl_uca_chassis ;
    Eigen::Vector3d ubar_rbr_uca_jcr_uca_chassis ;
    Eigen::Vector3d ubar_ground_jcr_tie_steering ;
    Eigen::Vector3d ubar_rbl_lca_jcl_strut_lca ;
    double m_ground ;
    Eigen::Vector3d F_rbl_lower_strut_gravity ;
    Eigen::Matrix3d Mbar_rbl_tie_rod_jcl_tie_steering ;
    Eigen::Matrix3d Mbar_rbl_upper_strut_jcl_strut_chassis ;
    Eigen::Matrix3d Mbar_rbr_uca_jcr_uca_upright ;
    Eigen::Vector3d ubar_rbl_lower_strut_fal_strut ;
    Eigen::Vector3d F_rbr_tie_rod_gravity ;
    Eigen::Vector3d ubar_rbr_lower_strut_jcr_strut ;
    Eigen::Vector3d ubar_rbl_upper_strut_jcl_strut ;
    Eigen::Vector3d ubar_rbr_upright_jcr_hub_bearing ;
    Eigen::Vector3d ubar_rbl_upright_jcl_uca_upright ;
    Eigen::Vector3d ubar_ground_mcr_wheel_travel ;
    Eigen::Vector3d ubar_ground_mcl_wheel_travel ;
    Eigen::Vector3d ubar_rbl_tie_rod_jcl_tie_upright ;
    Eigen::Matrix<double, 3, 3> Jbar_ground ;
    Eigen::Matrix3d Mbar_rbr_lca_jcr_lca_upright ;
    Eigen::Vector3d ubar_ground_jcl_strut_chassis ;
    Eigen::Vector3d ubar_rbl_hub_jcl_hub_bearing ;
    Eigen::Vector3d F_rbr_upper_strut_gravity ;
    Eigen::Vector3d ubar_rbr_upper_strut_jcr_strut_chassis ;
    Eigen::Matrix3d Mbar_rbl_uca_jcl_uca_upright ;
    Eigen::Vector3d T_rbl_lower_strut_fal_strut ;
    Eigen::Vector3d ubar_rbl_uca_jcl_uca_upright ;
    Eigen::Vector3d F_rbr_lca_gravity ;
    Eigen::Vector3d ubar_rbr_tie_rod_jcr_tie_upright ;
    Eigen::Vector3d F_rbl_upper_strut_gravity ;
    Eigen::Matrix3d Mbar_rbl_uca_jcl_uca_chassis ;
    Eigen::Matrix3d Mbar_ground_jcl_uca_chassis ;
    Eigen::Matrix3d Mbar_rbl_upper_strut_jcl_strut ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_uca_upright ;
    Eigen::Vector4d Pg_ground ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_hub_bearing ;
    Eigen::Vector3d F_rbl_uca_gravity ;
    Eigen::Matrix3d Mbar_rbl_lca_jcl_lca_upright ;
    Eigen::Vector3d ubar_rbl_lca_jcl_lca_chassis ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_tie_upright ;
    Eigen::Matrix3d Mbar_rbr_uca_jcr_uca_chassis ;
    Eigen::Vector3d ubar_rbr_hub_mcr_wheel_travel ;
    Eigen::Vector3d ubar_rbl_lower_strut_jcl_strut_lca ;
    Eigen::Vector3d ubar_rbl_hub_fal_tire ;
    Eigen::Vector4d P_ground ;
    Eigen::Vector3d ubar_rbr_upright_jcr_uca_upright ;
    Eigen::Matrix3d Mbar_rbr_tie_rod_jcr_tie_steering ;
    Eigen::Vector3d ubar_rbr_lca_jcr_strut_lca ;
    Eigen::Matrix3d Mbar_rbl_hub_jcl_hub_bearing ;
    Eigen::Vector3d ubar_rbr_upright_jcr_tie_upright ;
    Eigen::Vector3d ubar_rbl_upright_jcl_tie_upright ;
    Eigen::Vector3d ubar_ground_far_tire ;
    Eigen::Vector3d ubar_rbr_upper_strut_far_strut ;
    Eigen::Matrix3d Mbar_rbl_lca_jcl_lca_chassis ;
    Eigen::Matrix3d Mbar_rbl_lca_jcl_strut_lca ;
    Eigen::Matrix3d Mbar_rbl_lower_strut_jcl_strut ;
    Eigen::Vector3d T_rbr_lower_strut_far_strut ;
    Eigen::Vector3d T_rbr_upper_strut_far_strut ;
    Eigen::Matrix3d Mbar_rbl_tie_rod_jcl_tie_upright ;
    Eigen::Vector3d ubar_rbr_uca_jcr_uca_upright ;
    Eigen::Matrix3d Mbar_rbr_lower_strut_jcr_strut ;
    Eigen::Vector3d ubar_ground_fal_tire ;
    Eigen::Matrix3d Mbar_ground_jcr_tie_steering ;
    Eigen::Matrix3d Mbar_ground_jcr_strut_chassis ;
    Eigen::Vector3d ubar_rbl_upper_strut_jcl_strut_chassis ;
    Eigen::Matrix3d Mbar_rbl_upright_jcl_uca_upright ;
    Eigen::Matrix3d Mbar_rbr_upright_jcr_lca_upright ;
    Eigen::Matrix3d Mbar_rbr_upper_strut_jcr_strut_chassis ;
    Eigen::Vector3d F_rbl_hub_gravity ;
    Eigen::Vector3d F_rbr_lower_strut_gravity ;
    Eigen::Vector3d ubar_rbl_upper_strut_fal_strut ;
    Eigen::Vector3d ubar_rbr_lca_jcr_lca_chassis ;
    Eigen::Matrix3d Mbar_rbr_lower_strut_jcr_strut_lca ;
    Eigen::Vector3d F_rbl_tie_rod_gravity ;
    Eigen::Vector3d ubar_rbr_tie_rod_jcr_tie_steering ;
    Eigen::Vector3d F_rbl_upright_gravity ;
    Eigen::Matrix3d Mbar_ground_jcr_uca_chassis ;
    Eigen::Vector3d ubar_rbr_hub_far_tire ;
    Eigen::Vector3d ubar_rbr_upright_jcr_lca_upright ;
    Eigen::Matrix3d Mbar_ground_jcl_strut_chassis ;
    Eigen::Vector3d ubar_rbl_tie_rod_jcl_tie_steering ;
    Eigen::Vector3d ubar_rbl_lca_jcl_lca_upright ;
    Eigen::Vector3d ubar_rbr_upper_strut_jcr_strut ;
    Eigen::Matrix3d Mbar_ground_jcl_tie_steering ;
    Eigen::Vector3d ubar_ground_jcl_uca_chassis ;
    Eigen::Matrix3d Mbar_ground_jcl_lca_chassis ;
    Eigen::Vector3d F_rbr_hub_gravity ;
    Eigen::Matrix3d Mbar_rbr_lca_jcr_lca_chassis ;
    Eigen::Vector3d ubar_ground_jcr_strut_chassis ;
    Eigen::Matrix3d Mbar_rbr_hub_jcr_hub_bearing ;
    Eigen::Vector3d ubar_rbl_lower_strut_jcl_strut ;
    Eigen::Vector3d ubar_rbr_hub_jcr_hub_bearing ;
    Eigen::Vector3d F_rbl_lca_gravity ;
    Eigen::Vector3d ubar_rbr_lower_strut_far_strut ;
    Eigen::Matrix3d Mbar_rbl_lower_strut_jcl_strut_lca ;
    Eigen::Vector3d ubar_rbl_upright_jcl_lca_upright ;
    Eigen::Matrix3d Mbar_ground_jcr_lca_chassis ;
    Eigen::Vector3d ubar_rbr_lca_jcr_lca_upright ;
    Eigen::Vector3d ubar_ground_jcl_lca_chassis ;
    Eigen::Matrix3d Mbar_rbr_lca_jcr_strut_lca ;

};
