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


// Declaring the Topology Class and its numerical objects.
// =======================================================
class ATopology
{

public:
    std::vector<std::string> names;

public:
    // Topology constants.
    static const int n = 0;
    static const int nc = 0;
    static const int nrows = 0;
    static const int ncols = 0;

    // Topology variables
    std::string prefix;
    double t = 0;

    Eigen::VectorXd q;
    Eigen::VectorXd qd;
    Eigen::VectorXd qdd;

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
    virtual ~ATopology(){}

    // Topology initializing functions.
    virtual void initialize();
    virtual void assemble(Dict_SI& indicies_map, Dict_SS& interface_map, int rows_offset) = 0;
    virtual void set_initial_states() = 0;
    virtual void eval_constants() = 0;

    // Topology Equations Evaluators.
    virtual void eval_pos_eq() = 0;
    virtual void eval_vel_eq() = 0;
    virtual void eval_acc_eq() = 0;
    virtual void eval_jac_eq() = 0;

    // Topology States Setters.
    virtual void set_gen_coordinates(const Eigen::Ref<Eigen::VectorXd>& q);
    virtual void set_gen_velocities(const Eigen::Ref<Eigen::VectorXd>& qd);
    virtual void set_gen_accelerations(const Eigen::Ref<Eigen::VectorXd>& qdd);

    virtual void map_indicies();


};