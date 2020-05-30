
#include "double_wishbone_direct_acting.hpp"


void Configuration::constructFromJSON(std::string fileName)
{
    std::cout << "Constructing Configuration Inputs" << std::endl;
    this->ConfigInputs.constructFromJSON(fileName);

    std::cout << "Populating Configuration Arguments!" << std::endl;
    this->populateArguments();
};


void Configuration::populateArguments()
{
    ConfigInputs.get("R_rbr_uca", R_rbr_uca);
    ConfigInputs.get("P_rbr_uca", P_rbr_uca);
    ConfigInputs.get("Rd_rbr_uca", Rd_rbr_uca);
    ConfigInputs.get("Pd_rbr_uca", Pd_rbr_uca);
    ConfigInputs.get("Rdd_rbr_uca", Rdd_rbr_uca);
    ConfigInputs.get("Pdd_rbr_uca", Pdd_rbr_uca);
    ConfigInputs.get("m_rbr_uca", m_rbr_uca);
    ConfigInputs.get("Jbar_rbr_uca", Jbar_rbr_uca);
    ConfigInputs.get("R_rbl_uca", R_rbl_uca);
    ConfigInputs.get("P_rbl_uca", P_rbl_uca);
    ConfigInputs.get("Rd_rbl_uca", Rd_rbl_uca);
    ConfigInputs.get("Pd_rbl_uca", Pd_rbl_uca);
    ConfigInputs.get("Rdd_rbl_uca", Rdd_rbl_uca);
    ConfigInputs.get("Pdd_rbl_uca", Pdd_rbl_uca);
    ConfigInputs.get("m_rbl_uca", m_rbl_uca);
    ConfigInputs.get("Jbar_rbl_uca", Jbar_rbl_uca);
    ConfigInputs.get("R_rbr_lca", R_rbr_lca);
    ConfigInputs.get("P_rbr_lca", P_rbr_lca);
    ConfigInputs.get("Rd_rbr_lca", Rd_rbr_lca);
    ConfigInputs.get("Pd_rbr_lca", Pd_rbr_lca);
    ConfigInputs.get("Rdd_rbr_lca", Rdd_rbr_lca);
    ConfigInputs.get("Pdd_rbr_lca", Pdd_rbr_lca);
    ConfigInputs.get("m_rbr_lca", m_rbr_lca);
    ConfigInputs.get("Jbar_rbr_lca", Jbar_rbr_lca);
    ConfigInputs.get("R_rbl_lca", R_rbl_lca);
    ConfigInputs.get("P_rbl_lca", P_rbl_lca);
    ConfigInputs.get("Rd_rbl_lca", Rd_rbl_lca);
    ConfigInputs.get("Pd_rbl_lca", Pd_rbl_lca);
    ConfigInputs.get("Rdd_rbl_lca", Rdd_rbl_lca);
    ConfigInputs.get("Pdd_rbl_lca", Pdd_rbl_lca);
    ConfigInputs.get("m_rbl_lca", m_rbl_lca);
    ConfigInputs.get("Jbar_rbl_lca", Jbar_rbl_lca);
    ConfigInputs.get("R_rbr_upright", R_rbr_upright);
    ConfigInputs.get("P_rbr_upright", P_rbr_upright);
    ConfigInputs.get("Rd_rbr_upright", Rd_rbr_upright);
    ConfigInputs.get("Pd_rbr_upright", Pd_rbr_upright);
    ConfigInputs.get("Rdd_rbr_upright", Rdd_rbr_upright);
    ConfigInputs.get("Pdd_rbr_upright", Pdd_rbr_upright);
    ConfigInputs.get("m_rbr_upright", m_rbr_upright);
    ConfigInputs.get("Jbar_rbr_upright", Jbar_rbr_upright);
    ConfigInputs.get("R_rbl_upright", R_rbl_upright);
    ConfigInputs.get("P_rbl_upright", P_rbl_upright);
    ConfigInputs.get("Rd_rbl_upright", Rd_rbl_upright);
    ConfigInputs.get("Pd_rbl_upright", Pd_rbl_upright);
    ConfigInputs.get("Rdd_rbl_upright", Rdd_rbl_upright);
    ConfigInputs.get("Pdd_rbl_upright", Pdd_rbl_upright);
    ConfigInputs.get("m_rbl_upright", m_rbl_upright);
    ConfigInputs.get("Jbar_rbl_upright", Jbar_rbl_upright);
    ConfigInputs.get("R_rbr_upper_strut", R_rbr_upper_strut);
    ConfigInputs.get("P_rbr_upper_strut", P_rbr_upper_strut);
    ConfigInputs.get("Rd_rbr_upper_strut", Rd_rbr_upper_strut);
    ConfigInputs.get("Pd_rbr_upper_strut", Pd_rbr_upper_strut);
    ConfigInputs.get("Rdd_rbr_upper_strut", Rdd_rbr_upper_strut);
    ConfigInputs.get("Pdd_rbr_upper_strut", Pdd_rbr_upper_strut);
    ConfigInputs.get("m_rbr_upper_strut", m_rbr_upper_strut);
    ConfigInputs.get("Jbar_rbr_upper_strut", Jbar_rbr_upper_strut);
    ConfigInputs.get("R_rbl_upper_strut", R_rbl_upper_strut);
    ConfigInputs.get("P_rbl_upper_strut", P_rbl_upper_strut);
    ConfigInputs.get("Rd_rbl_upper_strut", Rd_rbl_upper_strut);
    ConfigInputs.get("Pd_rbl_upper_strut", Pd_rbl_upper_strut);
    ConfigInputs.get("Rdd_rbl_upper_strut", Rdd_rbl_upper_strut);
    ConfigInputs.get("Pdd_rbl_upper_strut", Pdd_rbl_upper_strut);
    ConfigInputs.get("m_rbl_upper_strut", m_rbl_upper_strut);
    ConfigInputs.get("Jbar_rbl_upper_strut", Jbar_rbl_upper_strut);
    ConfigInputs.get("R_rbr_lower_strut", R_rbr_lower_strut);
    ConfigInputs.get("P_rbr_lower_strut", P_rbr_lower_strut);
    ConfigInputs.get("Rd_rbr_lower_strut", Rd_rbr_lower_strut);
    ConfigInputs.get("Pd_rbr_lower_strut", Pd_rbr_lower_strut);
    ConfigInputs.get("Rdd_rbr_lower_strut", Rdd_rbr_lower_strut);
    ConfigInputs.get("Pdd_rbr_lower_strut", Pdd_rbr_lower_strut);
    ConfigInputs.get("m_rbr_lower_strut", m_rbr_lower_strut);
    ConfigInputs.get("Jbar_rbr_lower_strut", Jbar_rbr_lower_strut);
    ConfigInputs.get("R_rbl_lower_strut", R_rbl_lower_strut);
    ConfigInputs.get("P_rbl_lower_strut", P_rbl_lower_strut);
    ConfigInputs.get("Rd_rbl_lower_strut", Rd_rbl_lower_strut);
    ConfigInputs.get("Pd_rbl_lower_strut", Pd_rbl_lower_strut);
    ConfigInputs.get("Rdd_rbl_lower_strut", Rdd_rbl_lower_strut);
    ConfigInputs.get("Pdd_rbl_lower_strut", Pdd_rbl_lower_strut);
    ConfigInputs.get("m_rbl_lower_strut", m_rbl_lower_strut);
    ConfigInputs.get("Jbar_rbl_lower_strut", Jbar_rbl_lower_strut);
    ConfigInputs.get("R_rbr_tie_rod", R_rbr_tie_rod);
    ConfigInputs.get("P_rbr_tie_rod", P_rbr_tie_rod);
    ConfigInputs.get("Rd_rbr_tie_rod", Rd_rbr_tie_rod);
    ConfigInputs.get("Pd_rbr_tie_rod", Pd_rbr_tie_rod);
    ConfigInputs.get("Rdd_rbr_tie_rod", Rdd_rbr_tie_rod);
    ConfigInputs.get("Pdd_rbr_tie_rod", Pdd_rbr_tie_rod);
    ConfigInputs.get("m_rbr_tie_rod", m_rbr_tie_rod);
    ConfigInputs.get("Jbar_rbr_tie_rod", Jbar_rbr_tie_rod);
    ConfigInputs.get("R_rbl_tie_rod", R_rbl_tie_rod);
    ConfigInputs.get("P_rbl_tie_rod", P_rbl_tie_rod);
    ConfigInputs.get("Rd_rbl_tie_rod", Rd_rbl_tie_rod);
    ConfigInputs.get("Pd_rbl_tie_rod", Pd_rbl_tie_rod);
    ConfigInputs.get("Rdd_rbl_tie_rod", Rdd_rbl_tie_rod);
    ConfigInputs.get("Pdd_rbl_tie_rod", Pdd_rbl_tie_rod);
    ConfigInputs.get("m_rbl_tie_rod", m_rbl_tie_rod);
    ConfigInputs.get("Jbar_rbl_tie_rod", Jbar_rbl_tie_rod);
    ConfigInputs.get("R_rbr_hub", R_rbr_hub);
    ConfigInputs.get("P_rbr_hub", P_rbr_hub);
    ConfigInputs.get("Rd_rbr_hub", Rd_rbr_hub);
    ConfigInputs.get("Pd_rbr_hub", Pd_rbr_hub);
    ConfigInputs.get("Rdd_rbr_hub", Rdd_rbr_hub);
    ConfigInputs.get("Pdd_rbr_hub", Pdd_rbr_hub);
    ConfigInputs.get("m_rbr_hub", m_rbr_hub);
    ConfigInputs.get("Jbar_rbr_hub", Jbar_rbr_hub);
    ConfigInputs.get("R_rbl_hub", R_rbl_hub);
    ConfigInputs.get("P_rbl_hub", P_rbl_hub);
    ConfigInputs.get("Rd_rbl_hub", Rd_rbl_hub);
    ConfigInputs.get("Pd_rbl_hub", Pd_rbl_hub);
    ConfigInputs.get("Rdd_rbl_hub", Rdd_rbl_hub);
    ConfigInputs.get("Pdd_rbl_hub", Pdd_rbl_hub);
    ConfigInputs.get("m_rbl_hub", m_rbl_hub);
    ConfigInputs.get("Jbar_rbl_hub", Jbar_rbl_hub);
    ConfigInputs.get("ax1_jcr_uca_chassis", ax1_jcr_uca_chassis);
    ConfigInputs.get("pt1_jcr_uca_chassis", pt1_jcr_uca_chassis);
    ConfigInputs.get("ax1_jcr_uca_upright", ax1_jcr_uca_upright);
    ConfigInputs.get("pt1_jcr_uca_upright", pt1_jcr_uca_upright);
    ConfigInputs.get("ax1_jcl_uca_chassis", ax1_jcl_uca_chassis);
    ConfigInputs.get("pt1_jcl_uca_chassis", pt1_jcl_uca_chassis);
    ConfigInputs.get("ax1_jcl_uca_upright", ax1_jcl_uca_upright);
    ConfigInputs.get("pt1_jcl_uca_upright", pt1_jcl_uca_upright);
    ConfigInputs.get("ax1_jcr_lca_chassis", ax1_jcr_lca_chassis);
    ConfigInputs.get("pt1_jcr_lca_chassis", pt1_jcr_lca_chassis);
    ConfigInputs.get("ax1_jcr_lca_upright", ax1_jcr_lca_upright);
    ConfigInputs.get("pt1_jcr_lca_upright", pt1_jcr_lca_upright);
    ConfigInputs.get("ax1_jcl_lca_chassis", ax1_jcl_lca_chassis);
    ConfigInputs.get("pt1_jcl_lca_chassis", pt1_jcl_lca_chassis);
    ConfigInputs.get("ax1_jcl_lca_upright", ax1_jcl_lca_upright);
    ConfigInputs.get("pt1_jcl_lca_upright", pt1_jcl_lca_upright);
    ConfigInputs.get("ax1_jcr_hub_bearing", ax1_jcr_hub_bearing);
    ConfigInputs.get("pt1_jcr_hub_bearing", pt1_jcr_hub_bearing);
    ConfigInputs.get("ax1_jcr_hub_bearing", ax1_jcr_hub_bearing);
    ConfigInputs.get("UF_mcr_wheel_lock", UF_mcr_wheel_lock);
    ConfigInputs.get("ax1_jcl_hub_bearing", ax1_jcl_hub_bearing);
    ConfigInputs.get("pt1_jcl_hub_bearing", pt1_jcl_hub_bearing);
    ConfigInputs.get("ax1_jcl_hub_bearing", ax1_jcl_hub_bearing);
    ConfigInputs.get("UF_mcl_wheel_lock", UF_mcl_wheel_lock);
    ConfigInputs.get("ax1_jcr_strut_chassis", ax1_jcr_strut_chassis);
    ConfigInputs.get("ax2_jcr_strut_chassis", ax2_jcr_strut_chassis);
    ConfigInputs.get("pt1_jcr_strut_chassis", pt1_jcr_strut_chassis);
    ConfigInputs.get("ax1_jcr_strut", ax1_jcr_strut);
    ConfigInputs.get("pt1_jcr_strut", pt1_jcr_strut);
    ConfigInputs.get("pt1_far_strut", pt1_far_strut);
    ConfigInputs.get("pt2_far_strut", pt2_far_strut);
    ConfigInputs.get("UF_far_strut_Fs", UF_far_strut_Fs);
    ConfigInputs.get("UF_far_strut_Fd", UF_far_strut_Fd);
    ConfigInputs.get("far_strut_FL", far_strut_FL);
    ConfigInputs.get("ax1_jcl_strut_chassis", ax1_jcl_strut_chassis);
    ConfigInputs.get("ax2_jcl_strut_chassis", ax2_jcl_strut_chassis);
    ConfigInputs.get("pt1_jcl_strut_chassis", pt1_jcl_strut_chassis);
    ConfigInputs.get("ax1_jcl_strut", ax1_jcl_strut);
    ConfigInputs.get("pt1_jcl_strut", pt1_jcl_strut);
    ConfigInputs.get("pt1_fal_strut", pt1_fal_strut);
    ConfigInputs.get("pt2_fal_strut", pt2_fal_strut);
    ConfigInputs.get("UF_fal_strut_Fs", UF_fal_strut_Fs);
    ConfigInputs.get("UF_fal_strut_Fd", UF_fal_strut_Fd);
    ConfigInputs.get("fal_strut_FL", fal_strut_FL);
    ConfigInputs.get("ax1_jcr_strut_lca", ax1_jcr_strut_lca);
    ConfigInputs.get("ax2_jcr_strut_lca", ax2_jcr_strut_lca);
    ConfigInputs.get("pt1_jcr_strut_lca", pt1_jcr_strut_lca);
    ConfigInputs.get("ax1_jcl_strut_lca", ax1_jcl_strut_lca);
    ConfigInputs.get("ax2_jcl_strut_lca", ax2_jcl_strut_lca);
    ConfigInputs.get("pt1_jcl_strut_lca", pt1_jcl_strut_lca);
    ConfigInputs.get("ax1_jcr_tie_steering", ax1_jcr_tie_steering);
    ConfigInputs.get("ax2_jcr_tie_steering", ax2_jcr_tie_steering);
    ConfigInputs.get("pt1_jcr_tie_steering", pt1_jcr_tie_steering);
    ConfigInputs.get("ax1_jcr_tie_upright", ax1_jcr_tie_upright);
    ConfigInputs.get("pt1_jcr_tie_upright", pt1_jcr_tie_upright);
    ConfigInputs.get("ax1_jcl_tie_steering", ax1_jcl_tie_steering);
    ConfigInputs.get("ax2_jcl_tie_steering", ax2_jcl_tie_steering);
    ConfigInputs.get("pt1_jcl_tie_steering", pt1_jcl_tie_steering);
    ConfigInputs.get("ax1_jcl_tie_upright", ax1_jcl_tie_upright);
    ConfigInputs.get("pt1_jcl_tie_upright", pt1_jcl_tie_upright);
    ConfigInputs.get("pt1_mcr_wheel_travel", pt1_mcr_wheel_travel);
    ConfigInputs.get("pt2_mcr_wheel_travel", pt2_mcr_wheel_travel);
    ConfigInputs.get("UF_mcr_wheel_travel", UF_mcr_wheel_travel);
    ConfigInputs.get("UF_far_tire_F", UF_far_tire_F);
    ConfigInputs.get("UF_far_tire_T", UF_far_tire_T);
    ConfigInputs.get("pt1_far_tire", pt1_far_tire);
    ConfigInputs.get("pt1_mcl_wheel_travel", pt1_mcl_wheel_travel);
    ConfigInputs.get("pt2_mcl_wheel_travel", pt2_mcl_wheel_travel);
    ConfigInputs.get("UF_mcl_wheel_travel", UF_mcl_wheel_travel);
    ConfigInputs.get("UF_fal_tire_F", UF_fal_tire_F);
    ConfigInputs.get("UF_fal_tire_T", UF_fal_tire_T);
    ConfigInputs.get("pt1_fal_tire", pt1_fal_tire);
};

void Configuration::set_inital_configuration()
{
    this-> R_ground << 0, 0, 0 ;
    this-> P_ground << 1, 0, 0, 0 ;

    this-> q.resize(105);
    this-> q << 
        this->R_ground, 
        this->P_ground, 
        this->R_rbr_uca, 
        this->P_rbr_uca, 
        this->R_rbl_uca, 
        this->P_rbl_uca, 
        this->R_rbr_lca, 
        this->P_rbr_lca, 
        this->R_rbl_lca, 
        this->P_rbl_lca, 
        this->R_rbr_upright, 
        this->P_rbr_upright, 
        this->R_rbl_upright, 
        this->P_rbl_upright, 
        this->R_rbr_upper_strut, 
        this->P_rbr_upper_strut, 
        this->R_rbl_upper_strut, 
        this->P_rbl_upper_strut, 
        this->R_rbr_lower_strut, 
        this->P_rbr_lower_strut, 
        this->R_rbl_lower_strut, 
        this->P_rbl_lower_strut, 
        this->R_rbr_tie_rod, 
        this->P_rbr_tie_rod, 
        this->R_rbl_tie_rod, 
        this->P_rbl_tie_rod, 
        this->R_rbr_hub, 
        this->P_rbr_hub, 
        this->R_rbl_hub, 
        this->P_rbl_hub;

    this-> qd.resize(105);
    this-> qd << 
        this->Rd_ground, 
        this->Pd_ground, 
        this->Rd_rbr_uca, 
        this->Pd_rbr_uca, 
        this->Rd_rbl_uca, 
        this->Pd_rbl_uca, 
        this->Rd_rbr_lca, 
        this->Pd_rbr_lca, 
        this->Rd_rbl_lca, 
        this->Pd_rbl_lca, 
        this->Rd_rbr_upright, 
        this->Pd_rbr_upright, 
        this->Rd_rbl_upright, 
        this->Pd_rbl_upright, 
        this->Rd_rbr_upper_strut, 
        this->Pd_rbr_upper_strut, 
        this->Rd_rbl_upper_strut, 
        this->Pd_rbl_upper_strut, 
        this->Rd_rbr_lower_strut, 
        this->Pd_rbr_lower_strut, 
        this->Rd_rbl_lower_strut, 
        this->Pd_rbl_lower_strut, 
        this->Rd_rbr_tie_rod, 
        this->Pd_rbr_tie_rod, 
        this->Rd_rbl_tie_rod, 
        this->Pd_rbl_tie_rod, 
        this->Rd_rbr_hub, 
        this->Pd_rbr_hub, 
        this->Rd_rbl_hub, 
        this->Pd_rbl_hub;
};



Topology::Topology(){};
Topology::Topology(std::string prefix = "")
{
    this-> prefix = prefix;

    this-> q0.resize(this-> n);

    this-> pos_eq.resize(this-> nc);
    this-> vel_eq.resize(this-> nc);
    this-> acc_eq.resize(this-> nc);

    this-> jac_eq.reserve(this-> jac_rows.size());

    this-> indicies_map[prefix + "ground"] = 0;
    this-> indicies_map[prefix + "rbr_uca"] = 1;
    this-> indicies_map[prefix + "rbl_uca"] = 2;
    this-> indicies_map[prefix + "rbr_lca"] = 3;
    this-> indicies_map[prefix + "rbl_lca"] = 4;
    this-> indicies_map[prefix + "rbr_upright"] = 5;
    this-> indicies_map[prefix + "rbl_upright"] = 6;
    this-> indicies_map[prefix + "rbr_upper_strut"] = 7;
    this-> indicies_map[prefix + "rbl_upper_strut"] = 8;
    this-> indicies_map[prefix + "rbr_lower_strut"] = 9;
    this-> indicies_map[prefix + "rbl_lower_strut"] = 10;
    this-> indicies_map[prefix + "rbr_tie_rod"] = 11;
    this-> indicies_map[prefix + "rbl_tie_rod"] = 12;
    this-> indicies_map[prefix + "rbr_hub"] = 13;
    this-> indicies_map[prefix + "rbl_hub"] = 14;
};



void Topology::initialize()
{
    Dict_SS interface_map;
    this-> t = 0;
    this-> assemble(this-> indicies_map, interface_map, 0);
    this-> set_initial_states();
    this-> eval_constants();

};


void Topology::assemble(Dict_SI& indicies_map, Dict_SS& interface_map, int rows_offset)
{
    this-> set_mapping(indicies_map, interface_map);
    this-> rows += (rows_offset * Eigen::VectorXd::Ones(this ->rows.size()) );

    this-> jac_rows.resize(224);
    this-> jac_rows << 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 44, 45, 45, 45, 45, 46, 46, 46, 46, 47, 47, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63;
    this-> jac_rows += (rows_offset * Eigen::VectorXd::Ones(this ->jac_rows.size()) );

    this-> jac_cols.resize(224);
    this-> jac_cols << 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_uca*2, 
        this-> rbr_uca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_uca*2, 
        this-> rbr_uca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_uca*2, 
        this-> rbr_uca*2+1, 
        this-> rbr_uca*2, 
        this-> rbr_uca*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_uca*2, 
        this-> rbl_uca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_uca*2, 
        this-> rbl_uca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_uca*2, 
        this-> rbl_uca*2+1, 
        this-> rbl_uca*2, 
        this-> rbl_uca*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_lca*2, 
        this-> rbr_lca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_lca*2, 
        this-> rbr_lca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_lca*2, 
        this-> rbr_lca*2+1, 
        this-> rbr_lca*2, 
        this-> rbr_lca*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_lca*2, 
        this-> rbl_lca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_lca*2, 
        this-> rbl_lca*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_lca*2, 
        this-> rbl_lca*2+1, 
        this-> rbl_lca*2, 
        this-> rbl_lca*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> rbr_hub*2, 
        this-> rbr_hub*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> rbr_hub*2, 
        this-> rbr_hub*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> rbr_hub*2, 
        this-> rbr_hub*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> rbr_hub*2, 
        this-> rbr_hub*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> rbl_hub*2, 
        this-> rbl_hub*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> rbl_hub*2, 
        this-> rbl_hub*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> rbl_hub*2, 
        this-> rbl_hub*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> rbl_hub*2, 
        this-> rbl_hub*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_upper_strut*2, 
        this-> rbr_upper_strut*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_upper_strut*2, 
        this-> rbr_upper_strut*2+1, 
        this-> rbr_upper_strut*2, 
        this-> rbr_upper_strut*2+1, 
        this-> rbr_lower_strut*2, 
        this-> rbr_lower_strut*2+1, 
        this-> rbr_upper_strut*2, 
        this-> rbr_upper_strut*2+1, 
        this-> rbr_lower_strut*2, 
        this-> rbr_lower_strut*2+1, 
        this-> rbr_upper_strut*2, 
        this-> rbr_upper_strut*2+1, 
        this-> rbr_lower_strut*2, 
        this-> rbr_lower_strut*2+1, 
        this-> rbr_upper_strut*2, 
        this-> rbr_upper_strut*2+1, 
        this-> rbr_lower_strut*2, 
        this-> rbr_lower_strut*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_upper_strut*2, 
        this-> rbl_upper_strut*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_upper_strut*2, 
        this-> rbl_upper_strut*2+1, 
        this-> rbl_upper_strut*2, 
        this-> rbl_upper_strut*2+1, 
        this-> rbl_lower_strut*2, 
        this-> rbl_lower_strut*2+1, 
        this-> rbl_upper_strut*2, 
        this-> rbl_upper_strut*2+1, 
        this-> rbl_lower_strut*2, 
        this-> rbl_lower_strut*2+1, 
        this-> rbl_upper_strut*2, 
        this-> rbl_upper_strut*2+1, 
        this-> rbl_lower_strut*2, 
        this-> rbl_lower_strut*2+1, 
        this-> rbl_upper_strut*2, 
        this-> rbl_upper_strut*2+1, 
        this-> rbl_lower_strut*2, 
        this-> rbl_lower_strut*2+1, 
        this-> rbr_lca*2, 
        this-> rbr_lca*2+1, 
        this-> rbr_lower_strut*2, 
        this-> rbr_lower_strut*2+1, 
        this-> rbr_lca*2, 
        this-> rbr_lca*2+1, 
        this-> rbr_lower_strut*2, 
        this-> rbr_lower_strut*2+1, 
        this-> rbl_lca*2, 
        this-> rbl_lca*2+1, 
        this-> rbl_lower_strut*2, 
        this-> rbl_lower_strut*2+1, 
        this-> rbl_lca*2, 
        this-> rbl_lca*2+1, 
        this-> rbl_lower_strut*2, 
        this-> rbl_lower_strut*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_tie_rod*2, 
        this-> rbr_tie_rod*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_tie_rod*2, 
        this-> rbr_tie_rod*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> rbr_tie_rod*2, 
        this-> rbr_tie_rod*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_tie_rod*2, 
        this-> rbl_tie_rod*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_tie_rod*2, 
        this-> rbl_tie_rod*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> rbl_tie_rod*2, 
        this-> rbl_tie_rod*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_hub*2, 
        this-> rbr_hub*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbl_hub*2, 
        this-> rbl_hub*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbr_uca*2, 
        this-> rbr_uca*2+1, 
        this-> rbl_uca*2, 
        this-> rbl_uca*2+1, 
        this-> rbr_lca*2, 
        this-> rbr_lca*2+1, 
        this-> rbl_lca*2, 
        this-> rbl_lca*2+1, 
        this-> rbr_upright*2, 
        this-> rbr_upright*2+1, 
        this-> rbl_upright*2, 
        this-> rbl_upright*2+1, 
        this-> rbr_upper_strut*2, 
        this-> rbr_upper_strut*2+1, 
        this-> rbl_upper_strut*2, 
        this-> rbl_upper_strut*2+1, 
        this-> rbr_lower_strut*2, 
        this-> rbr_lower_strut*2+1, 
        this-> rbl_lower_strut*2, 
        this-> rbl_lower_strut*2+1, 
        this-> rbr_tie_rod*2, 
        this-> rbr_tie_rod*2+1, 
        this-> rbl_tie_rod*2, 
        this-> rbl_tie_rod*2+1, 
        this-> rbr_hub*2, 
        this-> rbr_hub*2+1, 
        this-> rbl_hub*2, 
        this-> rbl_hub*2+1;
};


void Topology::set_initial_states()
{
    this-> set_gen_coordinates(this-> config.q);
    this-> set_gen_velocities(this-> config.qd);
    this-> q0 = this-> config.q;
};


void Topology::set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map)
{
    auto& p = this-> prefix;

    this-> ground = indicies_map[p+"ground"];
    this-> rbr_uca = indicies_map[p+"rbr_uca"];
    this-> rbl_uca = indicies_map[p+"rbl_uca"];
    this-> rbr_lca = indicies_map[p+"rbr_lca"];
    this-> rbl_lca = indicies_map[p+"rbl_lca"];
    this-> rbr_upright = indicies_map[p+"rbr_upright"];
    this-> rbl_upright = indicies_map[p+"rbl_upright"];
    this-> rbr_upper_strut = indicies_map[p+"rbr_upper_strut"];
    this-> rbl_upper_strut = indicies_map[p+"rbl_upper_strut"];
    this-> rbr_lower_strut = indicies_map[p+"rbr_lower_strut"];
    this-> rbl_lower_strut = indicies_map[p+"rbl_lower_strut"];
    this-> rbr_tie_rod = indicies_map[p+"rbr_tie_rod"];
    this-> rbl_tie_rod = indicies_map[p+"rbl_tie_rod"];
    this-> rbr_hub = indicies_map[p+"rbr_hub"];
    this-> rbl_hub = indicies_map[p+"rbl_hub"];

    
};




void Topology::set_gen_coordinates(Eigen::VectorXd &q)
{
    this-> R_ground << q.block(0,0, 3,1) ;
    this-> P_ground << q.block(3,0, 4,1) ;
    this-> R_rbr_uca << q.block(7,0, 3,1) ;
    this-> P_rbr_uca << q.block(10,0, 4,1) ;
    this-> R_rbl_uca << q.block(14,0, 3,1) ;
    this-> P_rbl_uca << q.block(17,0, 4,1) ;
    this-> R_rbr_lca << q.block(21,0, 3,1) ;
    this-> P_rbr_lca << q.block(24,0, 4,1) ;
    this-> R_rbl_lca << q.block(28,0, 3,1) ;
    this-> P_rbl_lca << q.block(31,0, 4,1) ;
    this-> R_rbr_upright << q.block(35,0, 3,1) ;
    this-> P_rbr_upright << q.block(38,0, 4,1) ;
    this-> R_rbl_upright << q.block(42,0, 3,1) ;
    this-> P_rbl_upright << q.block(45,0, 4,1) ;
    this-> R_rbr_upper_strut << q.block(49,0, 3,1) ;
    this-> P_rbr_upper_strut << q.block(52,0, 4,1) ;
    this-> R_rbl_upper_strut << q.block(56,0, 3,1) ;
    this-> P_rbl_upper_strut << q.block(59,0, 4,1) ;
    this-> R_rbr_lower_strut << q.block(63,0, 3,1) ;
    this-> P_rbr_lower_strut << q.block(66,0, 4,1) ;
    this-> R_rbl_lower_strut << q.block(70,0, 3,1) ;
    this-> P_rbl_lower_strut << q.block(73,0, 4,1) ;
    this-> R_rbr_tie_rod << q.block(77,0, 3,1) ;
    this-> P_rbr_tie_rod << q.block(80,0, 4,1) ;
    this-> R_rbl_tie_rod << q.block(84,0, 3,1) ;
    this-> P_rbl_tie_rod << q.block(87,0, 4,1) ;
    this-> R_rbr_hub << q.block(91,0, 3,1) ;
    this-> P_rbr_hub << q.block(94,0, 4,1) ;
    this-> R_rbl_hub << q.block(98,0, 3,1) ;
    this-> P_rbl_hub << q.block(101,0, 4,1) ;
};

void Topology::set_gen_velocities(Eigen::VectorXd &qd)
{
    this-> Rd_ground << qd.block(0,0, 3,1) ;
    this-> Pd_ground << qd.block(3,0, 4,1) ;
    this-> Rd_rbr_uca << qd.block(7,0, 3,1) ;
    this-> Pd_rbr_uca << qd.block(10,0, 4,1) ;
    this-> Rd_rbl_uca << qd.block(14,0, 3,1) ;
    this-> Pd_rbl_uca << qd.block(17,0, 4,1) ;
    this-> Rd_rbr_lca << qd.block(21,0, 3,1) ;
    this-> Pd_rbr_lca << qd.block(24,0, 4,1) ;
    this-> Rd_rbl_lca << qd.block(28,0, 3,1) ;
    this-> Pd_rbl_lca << qd.block(31,0, 4,1) ;
    this-> Rd_rbr_upright << qd.block(35,0, 3,1) ;
    this-> Pd_rbr_upright << qd.block(38,0, 4,1) ;
    this-> Rd_rbl_upright << qd.block(42,0, 3,1) ;
    this-> Pd_rbl_upright << qd.block(45,0, 4,1) ;
    this-> Rd_rbr_upper_strut << qd.block(49,0, 3,1) ;
    this-> Pd_rbr_upper_strut << qd.block(52,0, 4,1) ;
    this-> Rd_rbl_upper_strut << qd.block(56,0, 3,1) ;
    this-> Pd_rbl_upper_strut << qd.block(59,0, 4,1) ;
    this-> Rd_rbr_lower_strut << qd.block(63,0, 3,1) ;
    this-> Pd_rbr_lower_strut << qd.block(66,0, 4,1) ;
    this-> Rd_rbl_lower_strut << qd.block(70,0, 3,1) ;
    this-> Pd_rbl_lower_strut << qd.block(73,0, 4,1) ;
    this-> Rd_rbr_tie_rod << qd.block(77,0, 3,1) ;
    this-> Pd_rbr_tie_rod << qd.block(80,0, 4,1) ;
    this-> Rd_rbl_tie_rod << qd.block(84,0, 3,1) ;
    this-> Pd_rbl_tie_rod << qd.block(87,0, 4,1) ;
    this-> Rd_rbr_hub << qd.block(91,0, 3,1) ;
    this-> Pd_rbr_hub << qd.block(94,0, 4,1) ;
    this-> Rd_rbl_hub << qd.block(98,0, 3,1) ;
    this-> Pd_rbl_hub << qd.block(101,0, 4,1) ;
};

void Topology::set_gen_accelerations(Eigen::VectorXd &qdd)
{
    this-> Rdd_ground << qdd.block(0,0, 3,1) ;
    this-> Pdd_ground << qdd.block(3,0, 4,1) ;
    this-> Rdd_rbr_uca << qdd.block(7,0, 3,1) ;
    this-> Pdd_rbr_uca << qdd.block(10,0, 4,1) ;
    this-> Rdd_rbl_uca << qdd.block(14,0, 3,1) ;
    this-> Pdd_rbl_uca << qdd.block(17,0, 4,1) ;
    this-> Rdd_rbr_lca << qdd.block(21,0, 3,1) ;
    this-> Pdd_rbr_lca << qdd.block(24,0, 4,1) ;
    this-> Rdd_rbl_lca << qdd.block(28,0, 3,1) ;
    this-> Pdd_rbl_lca << qdd.block(31,0, 4,1) ;
    this-> Rdd_rbr_upright << qdd.block(35,0, 3,1) ;
    this-> Pdd_rbr_upright << qdd.block(38,0, 4,1) ;
    this-> Rdd_rbl_upright << qdd.block(42,0, 3,1) ;
    this-> Pdd_rbl_upright << qdd.block(45,0, 4,1) ;
    this-> Rdd_rbr_upper_strut << qdd.block(49,0, 3,1) ;
    this-> Pdd_rbr_upper_strut << qdd.block(52,0, 4,1) ;
    this-> Rdd_rbl_upper_strut << qdd.block(56,0, 3,1) ;
    this-> Pdd_rbl_upper_strut << qdd.block(59,0, 4,1) ;
    this-> Rdd_rbr_lower_strut << qdd.block(63,0, 3,1) ;
    this-> Pdd_rbr_lower_strut << qdd.block(66,0, 4,1) ;
    this-> Rdd_rbl_lower_strut << qdd.block(70,0, 3,1) ;
    this-> Pdd_rbl_lower_strut << qdd.block(73,0, 4,1) ;
    this-> Rdd_rbr_tie_rod << qdd.block(77,0, 3,1) ;
    this-> Pdd_rbr_tie_rod << qdd.block(80,0, 4,1) ;
    this-> Rdd_rbl_tie_rod << qdd.block(84,0, 3,1) ;
    this-> Pdd_rbl_tie_rod << qdd.block(87,0, 4,1) ;
    this-> Rdd_rbr_hub << qdd.block(91,0, 3,1) ;
    this-> Pdd_rbr_hub << qdd.block(94,0, 4,1) ;
    this-> Rdd_rbl_hub << qdd.block(98,0, 3,1) ;
    this-> Pdd_rbl_hub << qdd.block(101,0, 4,1) ;
};



void Topology::eval_constants()
{
    auto& config = this-> config;

    this-> R_ground << 0, 0, 0 ;
    this-> P_ground << 1, 0, 0, 0 ;
    this-> Pg_ground << 1, 0, 0, 0 ;
    this-> m_ground = 1.0 ;
    this-> Jbar_ground << 1, 0, 0, 0, 1, 0, 0, 0, 1 ;
    this-> F_rbr_uca_gravity << 0, 0, -9810.0*config.m_rbr_uca ;
    this-> F_rbl_uca_gravity << 0, 0, -9810.0*config.m_rbl_uca ;
    this-> F_rbr_lca_gravity << 0, 0, -9810.0*config.m_rbr_lca ;
    this-> F_rbl_lca_gravity << 0, 0, -9810.0*config.m_rbl_lca ;
    this-> F_rbr_upright_gravity << 0, 0, -9810.0*config.m_rbr_upright ;
    this-> F_rbl_upright_gravity << 0, 0, -9810.0*config.m_rbl_upright ;
    this-> F_rbr_upper_strut_gravity << 0, 0, -9810.0*config.m_rbr_upper_strut ;
    this-> T_rbr_upper_strut_far_strut << Eigen::MatrixXd::Zero(3, 1) ;
    this-> T_rbr_lower_strut_far_strut << Eigen::MatrixXd::Zero(3, 1) ;
    this-> F_rbl_upper_strut_gravity << 0, 0, -9810.0*config.m_rbl_upper_strut ;
    this-> T_rbl_upper_strut_fal_strut << Eigen::MatrixXd::Zero(3, 1) ;
    this-> T_rbl_lower_strut_fal_strut << Eigen::MatrixXd::Zero(3, 1) ;
    this-> F_rbr_lower_strut_gravity << 0, 0, -9810.0*config.m_rbr_lower_strut ;
    this-> F_rbl_lower_strut_gravity << 0, 0, -9810.0*config.m_rbl_lower_strut ;
    this-> F_rbr_tie_rod_gravity << 0, 0, -9810.0*config.m_rbr_tie_rod ;
    this-> F_rbl_tie_rod_gravity << 0, 0, -9810.0*config.m_rbl_tie_rod ;
    this-> F_rbr_hub_gravity << 0, 0, -9810.0*config.m_rbr_hub ;
    this-> F_rbl_hub_gravity << 0, 0, -9810.0*config.m_rbl_hub ;

    this-> Mbar_rbr_uca_jcr_uca_chassis << A(config.P_rbr_uca).transpose() * triad(config.ax1_jcr_uca_chassis) ;
    this-> Mbar_ground_jcr_uca_chassis << A(this-> P_ground).transpose() * triad(config.ax1_jcr_uca_chassis) ;
    this-> ubar_rbr_uca_jcr_uca_chassis << (A(config.P_rbr_uca).transpose() * config.pt1_jcr_uca_chassis + -1 * A(config.P_rbr_uca).transpose() * config.R_rbr_uca) ;
    this-> ubar_ground_jcr_uca_chassis << (A(this-> P_ground).transpose() * config.pt1_jcr_uca_chassis + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbr_uca_jcr_uca_upright << A(config.P_rbr_uca).transpose() * triad(config.ax1_jcr_uca_upright) ;
    this-> Mbar_rbr_upright_jcr_uca_upright << A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_uca_upright) ;
    this-> ubar_rbr_uca_jcr_uca_upright << (A(config.P_rbr_uca).transpose() * config.pt1_jcr_uca_upright + -1 * A(config.P_rbr_uca).transpose() * config.R_rbr_uca) ;
    this-> ubar_rbr_upright_jcr_uca_upright << (A(config.P_rbr_upright).transpose() * config.pt1_jcr_uca_upright + -1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright) ;
    this-> Mbar_rbl_uca_jcl_uca_chassis << A(config.P_rbl_uca).transpose() * triad(config.ax1_jcl_uca_chassis) ;
    this-> Mbar_ground_jcl_uca_chassis << A(this-> P_ground).transpose() * triad(config.ax1_jcl_uca_chassis) ;
    this-> ubar_rbl_uca_jcl_uca_chassis << (A(config.P_rbl_uca).transpose() * config.pt1_jcl_uca_chassis + -1 * A(config.P_rbl_uca).transpose() * config.R_rbl_uca) ;
    this-> ubar_ground_jcl_uca_chassis << (A(this-> P_ground).transpose() * config.pt1_jcl_uca_chassis + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbl_uca_jcl_uca_upright << A(config.P_rbl_uca).transpose() * triad(config.ax1_jcl_uca_upright) ;
    this-> Mbar_rbl_upright_jcl_uca_upright << A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_uca_upright) ;
    this-> ubar_rbl_uca_jcl_uca_upright << (A(config.P_rbl_uca).transpose() * config.pt1_jcl_uca_upright + -1 * A(config.P_rbl_uca).transpose() * config.R_rbl_uca) ;
    this-> ubar_rbl_upright_jcl_uca_upright << (A(config.P_rbl_upright).transpose() * config.pt1_jcl_uca_upright + -1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright) ;
    this-> Mbar_rbr_lca_jcr_lca_chassis << A(config.P_rbr_lca).transpose() * triad(config.ax1_jcr_lca_chassis) ;
    this-> Mbar_ground_jcr_lca_chassis << A(this-> P_ground).transpose() * triad(config.ax1_jcr_lca_chassis) ;
    this-> ubar_rbr_lca_jcr_lca_chassis << (A(config.P_rbr_lca).transpose() * config.pt1_jcr_lca_chassis + -1 * A(config.P_rbr_lca).transpose() * config.R_rbr_lca) ;
    this-> ubar_ground_jcr_lca_chassis << (A(this-> P_ground).transpose() * config.pt1_jcr_lca_chassis + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbr_lca_jcr_lca_upright << A(config.P_rbr_lca).transpose() * triad(config.ax1_jcr_lca_upright) ;
    this-> Mbar_rbr_upright_jcr_lca_upright << A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_lca_upright) ;
    this-> ubar_rbr_lca_jcr_lca_upright << (A(config.P_rbr_lca).transpose() * config.pt1_jcr_lca_upright + -1 * A(config.P_rbr_lca).transpose() * config.R_rbr_lca) ;
    this-> ubar_rbr_upright_jcr_lca_upright << (A(config.P_rbr_upright).transpose() * config.pt1_jcr_lca_upright + -1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright) ;
    this-> Mbar_rbl_lca_jcl_lca_chassis << A(config.P_rbl_lca).transpose() * triad(config.ax1_jcl_lca_chassis) ;
    this-> Mbar_ground_jcl_lca_chassis << A(this-> P_ground).transpose() * triad(config.ax1_jcl_lca_chassis) ;
    this-> ubar_rbl_lca_jcl_lca_chassis << (A(config.P_rbl_lca).transpose() * config.pt1_jcl_lca_chassis + -1 * A(config.P_rbl_lca).transpose() * config.R_rbl_lca) ;
    this-> ubar_ground_jcl_lca_chassis << (A(this-> P_ground).transpose() * config.pt1_jcl_lca_chassis + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbl_lca_jcl_lca_upright << A(config.P_rbl_lca).transpose() * triad(config.ax1_jcl_lca_upright) ;
    this-> Mbar_rbl_upright_jcl_lca_upright << A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_lca_upright) ;
    this-> ubar_rbl_lca_jcl_lca_upright << (A(config.P_rbl_lca).transpose() * config.pt1_jcl_lca_upright + -1 * A(config.P_rbl_lca).transpose() * config.R_rbl_lca) ;
    this-> ubar_rbl_upright_jcl_lca_upright << (A(config.P_rbl_upright).transpose() * config.pt1_jcl_lca_upright + -1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright) ;
    this-> Mbar_rbr_upright_jcr_hub_bearing << A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_hub_bearing) ;
    this-> Mbar_rbr_hub_jcr_hub_bearing << A(config.P_rbr_hub).transpose() * triad(config.ax1_jcr_hub_bearing) ;
    this-> ubar_rbr_upright_jcr_hub_bearing << (A(config.P_rbr_upright).transpose() * config.pt1_jcr_hub_bearing + -1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright) ;
    this-> ubar_rbr_hub_jcr_hub_bearing << (A(config.P_rbr_hub).transpose() * config.pt1_jcr_hub_bearing + -1 * A(config.P_rbr_hub).transpose() * config.R_rbr_hub) ;
    this-> Mbar_rbr_upright_jcr_hub_bearing << A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_hub_bearing) ;
    this-> Mbar_rbr_hub_jcr_hub_bearing << A(config.P_rbr_hub).transpose() * triad(config.ax1_jcr_hub_bearing) ;
    this-> Mbar_rbl_upright_jcl_hub_bearing << A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_hub_bearing) ;
    this-> Mbar_rbl_hub_jcl_hub_bearing << A(config.P_rbl_hub).transpose() * triad(config.ax1_jcl_hub_bearing) ;
    this-> ubar_rbl_upright_jcl_hub_bearing << (A(config.P_rbl_upright).transpose() * config.pt1_jcl_hub_bearing + -1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright) ;
    this-> ubar_rbl_hub_jcl_hub_bearing << (A(config.P_rbl_hub).transpose() * config.pt1_jcl_hub_bearing + -1 * A(config.P_rbl_hub).transpose() * config.R_rbl_hub) ;
    this-> Mbar_rbl_upright_jcl_hub_bearing << A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_hub_bearing) ;
    this-> Mbar_rbl_hub_jcl_hub_bearing << A(config.P_rbl_hub).transpose() * triad(config.ax1_jcl_hub_bearing) ;
    this-> Mbar_rbr_upper_strut_jcr_strut_chassis << A(config.P_rbr_upper_strut).transpose() * triad(config.ax1_jcr_strut_chassis) ;
    this-> Mbar_ground_jcr_strut_chassis << A(this-> P_ground).transpose() * triad(config.ax2_jcr_strut_chassis, triad(config.ax1_jcr_strut_chassis).block(0,1, 3,1)) ;
    this-> ubar_rbr_upper_strut_jcr_strut_chassis << (A(config.P_rbr_upper_strut).transpose() * config.pt1_jcr_strut_chassis + -1 * A(config.P_rbr_upper_strut).transpose() * config.R_rbr_upper_strut) ;
    this-> ubar_ground_jcr_strut_chassis << (A(this-> P_ground).transpose() * config.pt1_jcr_strut_chassis + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbr_upper_strut_jcr_strut << A(config.P_rbr_upper_strut).transpose() * triad(config.ax1_jcr_strut) ;
    this-> Mbar_rbr_lower_strut_jcr_strut << A(config.P_rbr_lower_strut).transpose() * triad(config.ax1_jcr_strut) ;
    this-> ubar_rbr_upper_strut_jcr_strut << (A(config.P_rbr_upper_strut).transpose() * config.pt1_jcr_strut + -1 * A(config.P_rbr_upper_strut).transpose() * config.R_rbr_upper_strut) ;
    this-> ubar_rbr_lower_strut_jcr_strut << (A(config.P_rbr_lower_strut).transpose() * config.pt1_jcr_strut + -1 * A(config.P_rbr_lower_strut).transpose() * config.R_rbr_lower_strut) ;
    this-> ubar_rbr_upper_strut_far_strut << (A(config.P_rbr_upper_strut).transpose() * config.pt1_far_strut + -1 * A(config.P_rbr_upper_strut).transpose() * config.R_rbr_upper_strut) ;
    this-> ubar_rbr_lower_strut_far_strut << (A(config.P_rbr_lower_strut).transpose() * config.pt2_far_strut + -1 * A(config.P_rbr_lower_strut).transpose() * config.R_rbr_lower_strut) ;
    this-> Mbar_rbl_upper_strut_jcl_strut_chassis << A(config.P_rbl_upper_strut).transpose() * triad(config.ax1_jcl_strut_chassis) ;
    this-> Mbar_ground_jcl_strut_chassis << A(this-> P_ground).transpose() * triad(config.ax2_jcl_strut_chassis, triad(config.ax1_jcl_strut_chassis).block(0,1, 3,1)) ;
    this-> ubar_rbl_upper_strut_jcl_strut_chassis << (A(config.P_rbl_upper_strut).transpose() * config.pt1_jcl_strut_chassis + -1 * A(config.P_rbl_upper_strut).transpose() * config.R_rbl_upper_strut) ;
    this-> ubar_ground_jcl_strut_chassis << (A(this-> P_ground).transpose() * config.pt1_jcl_strut_chassis + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbl_upper_strut_jcl_strut << A(config.P_rbl_upper_strut).transpose() * triad(config.ax1_jcl_strut) ;
    this-> Mbar_rbl_lower_strut_jcl_strut << A(config.P_rbl_lower_strut).transpose() * triad(config.ax1_jcl_strut) ;
    this-> ubar_rbl_upper_strut_jcl_strut << (A(config.P_rbl_upper_strut).transpose() * config.pt1_jcl_strut + -1 * A(config.P_rbl_upper_strut).transpose() * config.R_rbl_upper_strut) ;
    this-> ubar_rbl_lower_strut_jcl_strut << (A(config.P_rbl_lower_strut).transpose() * config.pt1_jcl_strut + -1 * A(config.P_rbl_lower_strut).transpose() * config.R_rbl_lower_strut) ;
    this-> ubar_rbl_upper_strut_fal_strut << (A(config.P_rbl_upper_strut).transpose() * config.pt1_fal_strut + -1 * A(config.P_rbl_upper_strut).transpose() * config.R_rbl_upper_strut) ;
    this-> ubar_rbl_lower_strut_fal_strut << (A(config.P_rbl_lower_strut).transpose() * config.pt2_fal_strut + -1 * A(config.P_rbl_lower_strut).transpose() * config.R_rbl_lower_strut) ;
    this-> Mbar_rbr_lower_strut_jcr_strut_lca << A(config.P_rbr_lower_strut).transpose() * triad(config.ax1_jcr_strut_lca) ;
    this-> Mbar_rbr_lca_jcr_strut_lca << A(config.P_rbr_lca).transpose() * triad(config.ax2_jcr_strut_lca, triad(config.ax1_jcr_strut_lca).block(0,1, 3,1)) ;
    this-> ubar_rbr_lower_strut_jcr_strut_lca << (A(config.P_rbr_lower_strut).transpose() * config.pt1_jcr_strut_lca + -1 * A(config.P_rbr_lower_strut).transpose() * config.R_rbr_lower_strut) ;
    this-> ubar_rbr_lca_jcr_strut_lca << (A(config.P_rbr_lca).transpose() * config.pt1_jcr_strut_lca + -1 * A(config.P_rbr_lca).transpose() * config.R_rbr_lca) ;
    this-> Mbar_rbl_lower_strut_jcl_strut_lca << A(config.P_rbl_lower_strut).transpose() * triad(config.ax1_jcl_strut_lca) ;
    this-> Mbar_rbl_lca_jcl_strut_lca << A(config.P_rbl_lca).transpose() * triad(config.ax2_jcl_strut_lca, triad(config.ax1_jcl_strut_lca).block(0,1, 3,1)) ;
    this-> ubar_rbl_lower_strut_jcl_strut_lca << (A(config.P_rbl_lower_strut).transpose() * config.pt1_jcl_strut_lca + -1 * A(config.P_rbl_lower_strut).transpose() * config.R_rbl_lower_strut) ;
    this-> ubar_rbl_lca_jcl_strut_lca << (A(config.P_rbl_lca).transpose() * config.pt1_jcl_strut_lca + -1 * A(config.P_rbl_lca).transpose() * config.R_rbl_lca) ;
    this-> Mbar_rbr_tie_rod_jcr_tie_steering << A(config.P_rbr_tie_rod).transpose() * triad(config.ax1_jcr_tie_steering) ;
    this-> Mbar_ground_jcr_tie_steering << A(this-> P_ground).transpose() * triad(config.ax2_jcr_tie_steering, triad(config.ax1_jcr_tie_steering).block(0,1, 3,1)) ;
    this-> ubar_rbr_tie_rod_jcr_tie_steering << (A(config.P_rbr_tie_rod).transpose() * config.pt1_jcr_tie_steering + -1 * A(config.P_rbr_tie_rod).transpose() * config.R_rbr_tie_rod) ;
    this-> ubar_ground_jcr_tie_steering << (A(this-> P_ground).transpose() * config.pt1_jcr_tie_steering + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbr_tie_rod_jcr_tie_upright << A(config.P_rbr_tie_rod).transpose() * triad(config.ax1_jcr_tie_upright) ;
    this-> Mbar_rbr_upright_jcr_tie_upright << A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_tie_upright) ;
    this-> ubar_rbr_tie_rod_jcr_tie_upright << (A(config.P_rbr_tie_rod).transpose() * config.pt1_jcr_tie_upright + -1 * A(config.P_rbr_tie_rod).transpose() * config.R_rbr_tie_rod) ;
    this-> ubar_rbr_upright_jcr_tie_upright << (A(config.P_rbr_upright).transpose() * config.pt1_jcr_tie_upright + -1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright) ;
    this-> Mbar_rbl_tie_rod_jcl_tie_steering << A(config.P_rbl_tie_rod).transpose() * triad(config.ax1_jcl_tie_steering) ;
    this-> Mbar_ground_jcl_tie_steering << A(this-> P_ground).transpose() * triad(config.ax2_jcl_tie_steering, triad(config.ax1_jcl_tie_steering).block(0,1, 3,1)) ;
    this-> ubar_rbl_tie_rod_jcl_tie_steering << (A(config.P_rbl_tie_rod).transpose() * config.pt1_jcl_tie_steering + -1 * A(config.P_rbl_tie_rod).transpose() * config.R_rbl_tie_rod) ;
    this-> ubar_ground_jcl_tie_steering << (A(this-> P_ground).transpose() * config.pt1_jcl_tie_steering + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> Mbar_rbl_tie_rod_jcl_tie_upright << A(config.P_rbl_tie_rod).transpose() * triad(config.ax1_jcl_tie_upright) ;
    this-> Mbar_rbl_upright_jcl_tie_upright << A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_tie_upright) ;
    this-> ubar_rbl_tie_rod_jcl_tie_upright << (A(config.P_rbl_tie_rod).transpose() * config.pt1_jcl_tie_upright + -1 * A(config.P_rbl_tie_rod).transpose() * config.R_rbl_tie_rod) ;
    this-> ubar_rbl_upright_jcl_tie_upright << (A(config.P_rbl_upright).transpose() * config.pt1_jcl_tie_upright + -1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright) ;
    this-> ubar_rbr_hub_mcr_wheel_travel << (A(config.P_rbr_hub).transpose() * config.pt1_mcr_wheel_travel + -1 * A(config.P_rbr_hub).transpose() * config.R_rbr_hub) ;
    this-> ubar_ground_mcr_wheel_travel << (A(this-> P_ground).transpose() * config.pt2_mcr_wheel_travel + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> ubar_rbr_hub_far_tire << (A(config.P_rbr_hub).transpose() * config.pt1_far_tire + -1 * A(config.P_rbr_hub).transpose() * config.R_rbr_hub) ;
    this-> ubar_ground_far_tire << (A(this-> P_ground).transpose() * config.pt1_far_tire + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> ubar_rbl_hub_mcl_wheel_travel << (A(config.P_rbl_hub).transpose() * config.pt1_mcl_wheel_travel + -1 * A(config.P_rbl_hub).transpose() * config.R_rbl_hub) ;
    this-> ubar_ground_mcl_wheel_travel << (A(this-> P_ground).transpose() * config.pt2_mcl_wheel_travel + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> ubar_rbl_hub_fal_tire << (A(config.P_rbl_hub).transpose() * config.pt1_fal_tire + -1 * A(config.P_rbl_hub).transpose() * config.R_rbl_hub) ;
    this-> ubar_ground_fal_tire << (A(this-> P_ground).transpose() * config.pt1_fal_tire + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
};

void Topology::eval_pos_eq()
{
    auto& config = this-> config;
    auto& t = this-> t;

    Eigen::Vector3d x0 = this-> R_rbr_uca ;
    Eigen::Vector3d x1 = this-> R_ground ;
    Eigen::Vector3d x2 = -1 * x1 ;
    Eigen::Vector4d x3 = this-> P_rbr_uca ;
    Eigen::Matrix<double, 3, 3> x4 = A(x3) ;
    Eigen::Vector4d x5 = this-> P_ground ;
    Eigen::Matrix<double, 3, 3> x6 = A(x5) ;
    Eigen::Matrix<double, 3, 3> x7 = x4.transpose() ;
    Eigen::Vector3d x8 = this-> Mbar_ground_jcr_uca_chassis.col(2) ;
    Eigen::Vector3d x9 = this-> R_rbr_upright ;
    Eigen::Vector3d x10 = -1 * x9 ;
    Eigen::Vector4d x11 = this-> P_rbr_upright ;
    Eigen::Matrix<double, 3, 3> x12 = A(x11) ;
    Eigen::Vector3d x13 = this-> R_rbl_uca ;
    Eigen::Vector4d x14 = this-> P_rbl_uca ;
    Eigen::Matrix<double, 3, 3> x15 = A(x14) ;
    Eigen::Matrix<double, 3, 3> x16 = x15.transpose() ;
    Eigen::Vector3d x17 = this-> Mbar_ground_jcl_uca_chassis.col(2) ;
    Eigen::Vector3d x18 = this-> R_rbl_upright ;
    Eigen::Vector3d x19 = -1 * x18 ;
    Eigen::Vector4d x20 = this-> P_rbl_upright ;
    Eigen::Matrix<double, 3, 3> x21 = A(x20) ;
    Eigen::Vector3d x22 = this-> R_rbr_lca ;
    Eigen::Vector4d x23 = this-> P_rbr_lca ;
    Eigen::Matrix<double, 3, 3> x24 = A(x23) ;
    Eigen::Matrix<double, 3, 3> x25 = x24.transpose() ;
    Eigen::Vector3d x26 = this-> Mbar_ground_jcr_lca_chassis.col(2) ;
    Eigen::Vector3d x27 = this-> R_rbl_lca ;
    Eigen::Vector4d x28 = this-> P_rbl_lca ;
    Eigen::Matrix<double, 3, 3> x29 = A(x28) ;
    Eigen::Matrix<double, 3, 3> x30 = x29.transpose() ;
    Eigen::Vector3d x31 = this-> Mbar_ground_jcl_lca_chassis.col(2) ;
    Eigen::Vector3d x32 = this-> R_rbr_hub ;
    Eigen::Vector4d x33 = this-> P_rbr_hub ;
    Eigen::Matrix<double, 3, 3> x34 = A(x33) ;
    Eigen::Matrix<double, 3, 3> x35 = x12.transpose() ;
    Eigen::Vector3d x36 = this-> Mbar_rbr_hub_jcr_hub_bearing.col(2) ;
    Eigen::Vector3d x37 = this-> Mbar_rbr_hub_jcr_hub_bearing.col(0) ;
    Eigen::Vector3d x38 = this-> R_rbl_hub ;
    Eigen::Vector4d x39 = this-> P_rbl_hub ;
    Eigen::Matrix<double, 3, 3> x40 = A(x39) ;
    Eigen::Matrix<double, 3, 3> x41 = x21.transpose() ;
    Eigen::Vector3d x42 = this-> Mbar_rbl_hub_jcl_hub_bearing.col(2) ;
    Eigen::Vector3d x43 = this-> Mbar_rbl_hub_jcl_hub_bearing.col(0) ;
    Eigen::Vector3d x44 = this-> R_rbr_upper_strut ;
    Eigen::Vector4d x45 = this-> P_rbr_upper_strut ;
    Eigen::Matrix<double, 3, 3> x46 = A(x45) ;
    Eigen::Matrix<double, 3, 3> x47 = x46.transpose() ;
    Eigen::Matrix<double, 1, 3> x48 = this-> Mbar_rbr_upper_strut_jcr_strut.col(0).transpose() ;
    Eigen::Vector4d x49 = this-> P_rbr_lower_strut ;
    Eigen::Matrix<double, 3, 3> x50 = A(x49) ;
    Eigen::Vector3d x51 = this-> Mbar_rbr_lower_strut_jcr_strut.col(2) ;
    Eigen::Matrix<double, 1, 3> x52 = this-> Mbar_rbr_upper_strut_jcr_strut.col(1).transpose() ;
    Eigen::Vector3d x53 = this-> R_rbr_lower_strut ;
    Eigen::Vector3d x54 = (x44 + -1 * x53 + x46 * this-> ubar_rbr_upper_strut_jcr_strut + -1 * x50 * this-> ubar_rbr_lower_strut_jcr_strut) ;
    Eigen::Vector3d x55 = this-> R_rbl_upper_strut ;
    Eigen::Vector4d x56 = this-> P_rbl_upper_strut ;
    Eigen::Matrix<double, 3, 3> x57 = A(x56) ;
    Eigen::Matrix<double, 3, 3> x58 = x57.transpose() ;
    Eigen::Matrix<double, 1, 3> x59 = this-> Mbar_rbl_upper_strut_jcl_strut.col(0).transpose() ;
    Eigen::Vector4d x60 = this-> P_rbl_lower_strut ;
    Eigen::Matrix<double, 3, 3> x61 = A(x60) ;
    Eigen::Vector3d x62 = this-> Mbar_rbl_lower_strut_jcl_strut.col(2) ;
    Eigen::Matrix<double, 1, 3> x63 = this-> Mbar_rbl_upper_strut_jcl_strut.col(1).transpose() ;
    Eigen::Vector3d x64 = this-> R_rbl_lower_strut ;
    Eigen::Vector3d x65 = (x55 + -1 * x64 + x57 * this-> ubar_rbl_upper_strut_jcl_strut + -1 * x61 * this-> ubar_rbl_lower_strut_jcl_strut) ;
    Eigen::Vector3d x66 = this-> R_rbr_tie_rod ;
    Eigen::Vector4d x67 = this-> P_rbr_tie_rod ;
    Eigen::Matrix<double, 3, 3> x68 = A(x67) ;
    Eigen::Vector3d x69 = this-> R_rbl_tie_rod ;
    Eigen::Vector4d x70 = this-> P_rbl_tie_rod ;
    Eigen::Matrix<double, 3, 3> x71 = A(x70) ;
    Eigen::Matrix<double, 1, 1> x72 = Eigen::MatrixXd::Identity(1, 1) ;
    Eigen::Matrix<double, 1, 1> x73 = x72 ;
    Eigen::Matrix<double, 1, 1> x74 = -1 * x72 ;

    this-> pos_eq << 
        (x0 + x2 + x4 * this-> ubar_rbr_uca_jcr_uca_chassis + -1 * x6 * this-> ubar_ground_jcr_uca_chassis),
        this-> Mbar_rbr_uca_jcr_uca_chassis.col(0).transpose() * x7 * x6 * x8,
        this-> Mbar_rbr_uca_jcr_uca_chassis.col(1).transpose() * x7 * x6 * x8,
        (x0 + x10 + x4 * this-> ubar_rbr_uca_jcr_uca_upright + -1 * x12 * this-> ubar_rbr_upright_jcr_uca_upright),
        (x13 + x2 + x15 * this-> ubar_rbl_uca_jcl_uca_chassis + -1 * x6 * this-> ubar_ground_jcl_uca_chassis),
        this-> Mbar_rbl_uca_jcl_uca_chassis.col(0).transpose() * x16 * x6 * x17,
        this-> Mbar_rbl_uca_jcl_uca_chassis.col(1).transpose() * x16 * x6 * x17,
        (x13 + x19 + x15 * this-> ubar_rbl_uca_jcl_uca_upright + -1 * x21 * this-> ubar_rbl_upright_jcl_uca_upright),
        (x22 + x2 + x24 * this-> ubar_rbr_lca_jcr_lca_chassis + -1 * x6 * this-> ubar_ground_jcr_lca_chassis),
        this-> Mbar_rbr_lca_jcr_lca_chassis.col(0).transpose() * x25 * x6 * x26,
        this-> Mbar_rbr_lca_jcr_lca_chassis.col(1).transpose() * x25 * x6 * x26,
        (x22 + x10 + x24 * this-> ubar_rbr_lca_jcr_lca_upright + -1 * x12 * this-> ubar_rbr_upright_jcr_lca_upright),
        (x27 + x2 + x29 * this-> ubar_rbl_lca_jcl_lca_chassis + -1 * x6 * this-> ubar_ground_jcl_lca_chassis),
        this-> Mbar_rbl_lca_jcl_lca_chassis.col(0).transpose() * x30 * x6 * x31,
        this-> Mbar_rbl_lca_jcl_lca_chassis.col(1).transpose() * x30 * x6 * x31,
        (x27 + x19 + x29 * this-> ubar_rbl_lca_jcl_lca_upright + -1 * x21 * this-> ubar_rbl_upright_jcl_lca_upright),
        (x9 + -1 * x32 + x12 * this-> ubar_rbr_upright_jcr_hub_bearing + -1 * x34 * this-> ubar_rbr_hub_jcr_hub_bearing),
        this-> Mbar_rbr_upright_jcr_hub_bearing.col(0).transpose() * x35 * x34 * x36,
        this-> Mbar_rbr_upright_jcr_hub_bearing.col(1).transpose() * x35 * x34 * x36,
        (std::cos(config.UF_mcr_wheel_lock(t)) * this-> Mbar_rbr_upright_jcr_hub_bearing.col(1).transpose() * x35 * x34 * x37 + -1 * std::sin(config.UF_mcr_wheel_lock(t)) * this-> Mbar_rbr_upright_jcr_hub_bearing.col(0).transpose() * x35 * x34 * x37),
        (x18 + -1 * x38 + x21 * this-> ubar_rbl_upright_jcl_hub_bearing + -1 * x40 * this-> ubar_rbl_hub_jcl_hub_bearing),
        this-> Mbar_rbl_upright_jcl_hub_bearing.col(0).transpose() * x41 * x40 * x42,
        this-> Mbar_rbl_upright_jcl_hub_bearing.col(1).transpose() * x41 * x40 * x42,
        (std::cos(config.UF_mcl_wheel_lock(t)) * this-> Mbar_rbl_upright_jcl_hub_bearing.col(1).transpose() * x41 * x40 * x43 + -1 * std::sin(config.UF_mcl_wheel_lock(t)) * this-> Mbar_rbl_upright_jcl_hub_bearing.col(0).transpose() * x41 * x40 * x43),
        (x44 + x2 + x46 * this-> ubar_rbr_upper_strut_jcr_strut_chassis + -1 * x6 * this-> ubar_ground_jcr_strut_chassis),
        this-> Mbar_rbr_upper_strut_jcr_strut_chassis.col(0).transpose() * x47 * x6 * this-> Mbar_ground_jcr_strut_chassis.col(0),
        x48 * x47 * x50 * x51,
        x52 * x47 * x50 * x51,
        x48 * x47 * x54,
        x52 * x47 * x54,
        (x55 + x2 + x57 * this-> ubar_rbl_upper_strut_jcl_strut_chassis + -1 * x6 * this-> ubar_ground_jcl_strut_chassis),
        this-> Mbar_rbl_upper_strut_jcl_strut_chassis.col(0).transpose() * x58 * x6 * this-> Mbar_ground_jcl_strut_chassis.col(0),
        x59 * x58 * x61 * x62,
        x63 * x58 * x61 * x62,
        x59 * x58 * x65,
        x63 * x58 * x65,
        (x53 + -1 * x22 + x50 * this-> ubar_rbr_lower_strut_jcr_strut_lca + -1 * x24 * this-> ubar_rbr_lca_jcr_strut_lca),
        this-> Mbar_rbr_lower_strut_jcr_strut_lca.col(0).transpose() * x50.transpose() * x24 * this-> Mbar_rbr_lca_jcr_strut_lca.col(0),
        (x64 + -1 * x27 + x61 * this-> ubar_rbl_lower_strut_jcl_strut_lca + -1 * x29 * this-> ubar_rbl_lca_jcl_strut_lca),
        this-> Mbar_rbl_lower_strut_jcl_strut_lca.col(0).transpose() * x61.transpose() * x29 * this-> Mbar_rbl_lca_jcl_strut_lca.col(0),
        (x66 + x2 + x68 * this-> ubar_rbr_tie_rod_jcr_tie_steering + -1 * x6 * this-> ubar_ground_jcr_tie_steering),
        this-> Mbar_rbr_tie_rod_jcr_tie_steering.col(0).transpose() * x68.transpose() * x6 * this-> Mbar_ground_jcr_tie_steering.col(0),
        (x66 + x10 + x68 * this-> ubar_rbr_tie_rod_jcr_tie_upright + -1 * x12 * this-> ubar_rbr_upright_jcr_tie_upright),
        (x69 + x2 + x71 * this-> ubar_rbl_tie_rod_jcl_tie_steering + -1 * x6 * this-> ubar_ground_jcl_tie_steering),
        this-> Mbar_rbl_tie_rod_jcl_tie_steering.col(0).transpose() * x71.transpose() * x6 * this-> Mbar_ground_jcl_tie_steering.col(0),
        (x69 + x19 + x71 * this-> ubar_rbl_tie_rod_jcl_tie_upright + -1 * x21 * this-> ubar_rbl_upright_jcl_tie_upright),
        (-1 * config.UF_mcr_wheel_travel(t) * x73 + (x32 + x34 * this-> ubar_rbr_hub_mcr_wheel_travel).block(2,0, 1,1) + -1 * (x1 + x6 * this-> ubar_ground_mcr_wheel_travel).block(2,0, 1,1)),
        (-1 * config.UF_mcl_wheel_travel(t) * x73 + (x38 + x40 * this-> ubar_rbl_hub_mcl_wheel_travel).block(2,0, 1,1) + -1 * (x1 + x6 * this-> ubar_ground_mcl_wheel_travel).block(2,0, 1,1)),
        x1,
        (x5 + -1 * this-> Pg_ground),
        (x74 + x3.transpose() * x3),
        (x74 + x14.transpose() * x14),
        (x74 + x23.transpose() * x23),
        (x74 + x28.transpose() * x28),
        (x74 + x11.transpose() * x11),
        (x74 + x20.transpose() * x20),
        (x74 + x45.transpose() * x45),
        (x74 + x56.transpose() * x56),
        (x74 + x49.transpose() * x49),
        (x74 + x60.transpose() * x60),
        (x74 + x67.transpose() * x67),
        (x74 + x70.transpose() * x70),
        (x74 + x33.transpose() * x33),
        (x74 + x39.transpose() * x39);
};

void Topology::eval_vel_eq()
{
    auto& config = this-> config;
    auto& t = this-> t;

    Eigen::Vector3d v0 = Eigen::MatrixXd::Zero(3, 1) ;
    Eigen::Matrix<double, 1, 1> v1 = Eigen::MatrixXd::Zero(1, 1) ;
    Eigen::Matrix<double, 1, 1> v2 = Eigen::MatrixXd::Identity(1, 1) ;

    this-> vel_eq << 
        v0,
        v1,
        v1,
        v0,
        v0,
        v1,
        v1,
        v0,
        v0,
        v1,
        v1,
        v0,
        v0,
        v1,
        v1,
        v0,
        v0,
        v1,
        v1,
        (v1 + -1 * derivative(config.UF_mcr_wheel_lock, t, 1) * v2),
        v0,
        v1,
        v1,
        (v1 + -1 * derivative(config.UF_mcl_wheel_lock, t, 1) * v2),
        v0,
        v1,
        v1,
        v1,
        v1,
        v1,
        v0,
        v1,
        v1,
        v1,
        v1,
        v1,
        v0,
        v1,
        v0,
        v1,
        v0,
        v1,
        v0,
        v0,
        v1,
        v0,
        (v1 + -1 * derivative(config.UF_mcr_wheel_travel, t, 1) * v2),
        (v1 + -1 * derivative(config.UF_mcl_wheel_travel, t, 1) * v2),
        v0,
        Eigen::MatrixXd::Zero(4, 1),
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1,
        v1;
};

void Topology::eval_acc_eq()
{
    auto& config = this-> config;
    auto& t = this-> t;

    Eigen::Vector4d a0 = this-> Pd_rbr_uca ;
    Eigen::Vector4d a1 = this-> Pd_ground ;
    Eigen::Vector3d a2 = this-> Mbar_ground_jcr_uca_chassis.col(2) ;
    Eigen::Matrix<double, 1, 3> a3 = a2.transpose() ;
    Eigen::Vector4d a4 = this-> P_ground ;
    Eigen::Matrix<double, 3, 3> a5 = A(a4).transpose() ;
    Eigen::Vector3d a6 = this-> Mbar_rbr_uca_jcr_uca_chassis.col(0) ;
    Eigen::Vector4d a7 = this-> P_rbr_uca ;
    Eigen::Matrix<double, 3, 3> a8 = A(a7).transpose() ;
    Eigen::Matrix<double, 3, 4> a9 = B(a1, a2) ;
    Eigen::Matrix<double, 1, 4> a10 = a0.transpose() ;
    Eigen::Matrix<double, 3, 4> a11 = B(a4, a2) ;
    Eigen::Vector3d a12 = this-> Mbar_rbr_uca_jcr_uca_chassis.col(1) ;
    Eigen::Vector4d a13 = this-> Pd_rbr_upright ;
    Eigen::Vector4d a14 = this-> Pd_rbl_uca ;
    Eigen::Vector3d a15 = this-> Mbar_rbl_uca_jcl_uca_chassis.col(0) ;
    Eigen::Vector4d a16 = this-> P_rbl_uca ;
    Eigen::Matrix<double, 3, 3> a17 = A(a16).transpose() ;
    Eigen::Vector3d a18 = this-> Mbar_ground_jcl_uca_chassis.col(2) ;
    Eigen::Matrix<double, 3, 4> a19 = B(a1, a18) ;
    Eigen::Matrix<double, 1, 3> a20 = a18.transpose() ;
    Eigen::Matrix<double, 1, 4> a21 = a14.transpose() ;
    Eigen::Matrix<double, 3, 4> a22 = B(a4, a18) ;
    Eigen::Vector3d a23 = this-> Mbar_rbl_uca_jcl_uca_chassis.col(1) ;
    Eigen::Vector4d a24 = this-> Pd_rbl_upright ;
    Eigen::Vector4d a25 = this-> Pd_rbr_lca ;
    Eigen::Vector3d a26 = this-> Mbar_ground_jcr_lca_chassis.col(2) ;
    Eigen::Matrix<double, 1, 3> a27 = a26.transpose() ;
    Eigen::Vector3d a28 = this-> Mbar_rbr_lca_jcr_lca_chassis.col(0) ;
    Eigen::Vector4d a29 = this-> P_rbr_lca ;
    Eigen::Matrix<double, 3, 3> a30 = A(a29).transpose() ;
    Eigen::Matrix<double, 3, 4> a31 = B(a1, a26) ;
    Eigen::Matrix<double, 1, 4> a32 = a25.transpose() ;
    Eigen::Matrix<double, 3, 4> a33 = B(a4, a26) ;
    Eigen::Vector3d a34 = this-> Mbar_rbr_lca_jcr_lca_chassis.col(1) ;
    Eigen::Vector4d a35 = this-> Pd_rbl_lca ;
    Eigen::Vector3d a36 = this-> Mbar_rbl_lca_jcl_lca_chassis.col(0) ;
    Eigen::Vector4d a37 = this-> P_rbl_lca ;
    Eigen::Matrix<double, 3, 3> a38 = A(a37).transpose() ;
    Eigen::Vector3d a39 = this-> Mbar_ground_jcl_lca_chassis.col(2) ;
    Eigen::Matrix<double, 3, 4> a40 = B(a1, a39) ;
    Eigen::Matrix<double, 1, 3> a41 = a39.transpose() ;
    Eigen::Matrix<double, 1, 4> a42 = a35.transpose() ;
    Eigen::Matrix<double, 3, 4> a43 = B(a4, a39) ;
    Eigen::Vector3d a44 = this-> Mbar_rbl_lca_jcl_lca_chassis.col(1) ;
    Eigen::Vector4d a45 = this-> Pd_rbr_hub ;
    Eigen::Vector3d a46 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    Eigen::Vector4d a47 = this-> P_rbr_upright ;
    Eigen::Matrix<double, 3, 3> a48 = A(a47).transpose() ;
    Eigen::Vector3d a49 = this-> Mbar_rbr_hub_jcr_hub_bearing.col(2) ;
    Eigen::Matrix<double, 3, 4> a50 = B(a45, a49) ;
    Eigen::Matrix<double, 1, 3> a51 = a49.transpose() ;
    Eigen::Vector4d a52 = this-> P_rbr_hub ;
    Eigen::Matrix<double, 3, 3> a53 = A(a52).transpose() ;
    Eigen::Matrix<double, 1, 4> a54 = a13.transpose() ;
    Eigen::Matrix<double, 3, 4> a55 = B(a52, a49) ;
    Eigen::Vector3d a56 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    Eigen::Matrix<double, 1, 1> a57 = Eigen::MatrixXd::Identity(1, 1) ;
    Eigen::Vector3d a58 = this-> Mbar_rbr_hub_jcr_hub_bearing.col(0) ;
    Eigen::Vector3d a59 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    Eigen::Vector3d a60 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    Eigen::Vector4d a61 = this-> Pd_rbl_hub ;
    Eigen::Vector3d a62 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    Eigen::Vector4d a63 = this-> P_rbl_upright ;
    Eigen::Matrix<double, 3, 3> a64 = A(a63).transpose() ;
    Eigen::Vector3d a65 = this-> Mbar_rbl_hub_jcl_hub_bearing.col(2) ;
    Eigen::Matrix<double, 3, 4> a66 = B(a61, a65) ;
    Eigen::Matrix<double, 1, 3> a67 = a65.transpose() ;
    Eigen::Vector4d a68 = this-> P_rbl_hub ;
    Eigen::Matrix<double, 3, 3> a69 = A(a68).transpose() ;
    Eigen::Matrix<double, 1, 4> a70 = a24.transpose() ;
    Eigen::Matrix<double, 3, 4> a71 = B(a68, a65) ;
    Eigen::Vector3d a72 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    Eigen::Vector3d a73 = this-> Mbar_rbl_hub_jcl_hub_bearing.col(0) ;
    Eigen::Vector3d a74 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    Eigen::Vector3d a75 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    Eigen::Vector4d a76 = this-> Pd_rbr_upper_strut ;
    Eigen::Vector3d a77 = this-> Mbar_ground_jcr_strut_chassis.col(0) ;
    Eigen::Vector3d a78 = this-> Mbar_rbr_upper_strut_jcr_strut_chassis.col(0) ;
    Eigen::Vector4d a79 = this-> P_rbr_upper_strut ;
    Eigen::Matrix<double, 3, 3> a80 = A(a79).transpose() ;
    Eigen::Matrix<double, 1, 4> a81 = a76.transpose() ;
    Eigen::Vector3d a82 = this-> Mbar_rbr_upper_strut_jcr_strut.col(0) ;
    Eigen::Matrix<double, 1, 3> a83 = a82.transpose() ;
    Eigen::Vector4d a84 = this-> Pd_rbr_lower_strut ;
    Eigen::Vector3d a85 = this-> Mbar_rbr_lower_strut_jcr_strut.col(2) ;
    Eigen::Matrix<double, 3, 4> a86 = B(a84, a85) ;
    Eigen::Matrix<double, 1, 3> a87 = a85.transpose() ;
    Eigen::Vector4d a88 = this-> P_rbr_lower_strut ;
    Eigen::Matrix<double, 3, 3> a89 = A(a88).transpose() ;
    Eigen::Matrix<double, 3, 4> a90 = B(a76, a82) ;
    Eigen::Matrix<double, 4, 3> a91 = B(a79, a82).transpose() ;
    Eigen::Matrix<double, 3, 4> a92 = B(a88, a85) ;
    Eigen::Vector3d a93 = this-> Mbar_rbr_upper_strut_jcr_strut.col(1) ;
    Eigen::Matrix<double, 1, 3> a94 = a93.transpose() ;
    Eigen::Matrix<double, 3, 4> a95 = B(a76, a93) ;
    Eigen::Matrix<double, 4, 3> a96 = B(a79, a93).transpose() ;
    Eigen::Vector3d a97 = this-> ubar_rbr_upper_strut_jcr_strut ;
    Eigen::Vector3d a98 = this-> ubar_rbr_lower_strut_jcr_strut ;
    Eigen::Vector3d a99 = (B(a76, a97) * a76 + -1 * B(a84, a98) * a84) ;
    Eigen::Vector3d a100 = (this-> Rd_rbr_upper_strut + -1 * this-> Rd_rbr_lower_strut + B(a79, a97) * a76 + -1 * B(a88, a98) * a84) ;
    Eigen::Matrix<double, 1, 3> a101 = (this-> R_rbr_upper_strut.transpose() + -1 * this-> R_rbr_lower_strut.transpose() + a97.transpose() * a80 + -1 * a98.transpose() * a89) ;
    Eigen::Vector4d a102 = this-> Pd_rbl_upper_strut ;
    Eigen::Vector3d a103 = this-> Mbar_ground_jcl_strut_chassis.col(0) ;
    Eigen::Vector3d a104 = this-> Mbar_rbl_upper_strut_jcl_strut_chassis.col(0) ;
    Eigen::Vector4d a105 = this-> P_rbl_upper_strut ;
    Eigen::Matrix<double, 3, 3> a106 = A(a105).transpose() ;
    Eigen::Matrix<double, 1, 4> a107 = a102.transpose() ;
    Eigen::Vector3d a108 = this-> Mbar_rbl_upper_strut_jcl_strut.col(0) ;
    Eigen::Matrix<double, 1, 3> a109 = a108.transpose() ;
    Eigen::Vector4d a110 = this-> Pd_rbl_lower_strut ;
    Eigen::Vector3d a111 = this-> Mbar_rbl_lower_strut_jcl_strut.col(2) ;
    Eigen::Matrix<double, 3, 4> a112 = B(a110, a111) ;
    Eigen::Matrix<double, 1, 3> a113 = a111.transpose() ;
    Eigen::Vector4d a114 = this-> P_rbl_lower_strut ;
    Eigen::Matrix<double, 3, 3> a115 = A(a114).transpose() ;
    Eigen::Matrix<double, 3, 4> a116 = B(a102, a108) ;
    Eigen::Matrix<double, 4, 3> a117 = B(a105, a108).transpose() ;
    Eigen::Matrix<double, 3, 4> a118 = B(a114, a111) ;
    Eigen::Vector3d a119 = this-> Mbar_rbl_upper_strut_jcl_strut.col(1) ;
    Eigen::Matrix<double, 1, 3> a120 = a119.transpose() ;
    Eigen::Matrix<double, 3, 4> a121 = B(a102, a119) ;
    Eigen::Matrix<double, 4, 3> a122 = B(a105, a119).transpose() ;
    Eigen::Vector3d a123 = this-> ubar_rbl_upper_strut_jcl_strut ;
    Eigen::Vector3d a124 = this-> ubar_rbl_lower_strut_jcl_strut ;
    Eigen::Vector3d a125 = (B(a102, a123) * a102 + -1 * B(a110, a124) * a110) ;
    Eigen::Vector3d a126 = (this-> Rd_rbl_upper_strut + -1 * this-> Rd_rbl_lower_strut + B(a105, a123) * a102 + -1 * B(a114, a124) * a110) ;
    Eigen::Matrix<double, 1, 3> a127 = (this-> R_rbl_upper_strut.transpose() + -1 * this-> R_rbl_lower_strut.transpose() + a123.transpose() * a106 + -1 * a124.transpose() * a115) ;
    Eigen::Vector3d a128 = this-> Mbar_rbr_lower_strut_jcr_strut_lca.col(0) ;
    Eigen::Vector3d a129 = this-> Mbar_rbr_lca_jcr_strut_lca.col(0) ;
    Eigen::Matrix<double, 1, 4> a130 = a84.transpose() ;
    Eigen::Vector3d a131 = this-> Mbar_rbl_lower_strut_jcl_strut_lca.col(0) ;
    Eigen::Vector3d a132 = this-> Mbar_rbl_lca_jcl_strut_lca.col(0) ;
    Eigen::Matrix<double, 1, 4> a133 = a110.transpose() ;
    Eigen::Vector4d a134 = this-> Pd_rbr_tie_rod ;
    Eigen::Vector3d a135 = this-> Mbar_ground_jcr_tie_steering.col(0) ;
    Eigen::Vector3d a136 = this-> Mbar_rbr_tie_rod_jcr_tie_steering.col(0) ;
    Eigen::Vector4d a137 = this-> P_rbr_tie_rod ;
    Eigen::Matrix<double, 1, 4> a138 = a134.transpose() ;
    Eigen::Vector4d a139 = this-> Pd_rbl_tie_rod ;
    Eigen::Vector3d a140 = this-> Mbar_rbl_tie_rod_jcl_tie_steering.col(0) ;
    Eigen::Vector4d a141 = this-> P_rbl_tie_rod ;
    Eigen::Vector3d a142 = this-> Mbar_ground_jcl_tie_steering.col(0) ;
    Eigen::Matrix<double, 1, 4> a143 = a139.transpose() ;

    this-> acc_eq << 
        (B(a0, this-> ubar_rbr_uca_jcr_uca_chassis) * a0 + -1 * B(a1, this-> ubar_ground_jcr_uca_chassis) * a1),
        (a3 * a5 * B(a0, a6) * a0 + a6.transpose() * a8 * a9 * a1 + 2 * a10 * B(a7, a6).transpose() * a11 * a1),
        (a3 * a5 * B(a0, a12) * a0 + a12.transpose() * a8 * a9 * a1 + 2 * a10 * B(a7, a12).transpose() * a11 * a1),
        (B(a0, this-> ubar_rbr_uca_jcr_uca_upright) * a0 + -1 * B(a13, this-> ubar_rbr_upright_jcr_uca_upright) * a13),
        (B(a14, this-> ubar_rbl_uca_jcl_uca_chassis) * a14 + -1 * B(a1, this-> ubar_ground_jcl_uca_chassis) * a1),
        (a15.transpose() * a17 * a19 * a1 + a20 * a5 * B(a14, a15) * a14 + 2 * a21 * B(a16, a15).transpose() * a22 * a1),
        (a23.transpose() * a17 * a19 * a1 + a20 * a5 * B(a14, a23) * a14 + 2 * a21 * B(a16, a23).transpose() * a22 * a1),
        (B(a14, this-> ubar_rbl_uca_jcl_uca_upright) * a14 + -1 * B(a24, this-> ubar_rbl_upright_jcl_uca_upright) * a24),
        (B(a25, this-> ubar_rbr_lca_jcr_lca_chassis) * a25 + -1 * B(a1, this-> ubar_ground_jcr_lca_chassis) * a1),
        (a27 * a5 * B(a25, a28) * a25 + a28.transpose() * a30 * a31 * a1 + 2 * a32 * B(a29, a28).transpose() * a33 * a1),
        (a27 * a5 * B(a25, a34) * a25 + a34.transpose() * a30 * a31 * a1 + 2 * a32 * B(a29, a34).transpose() * a33 * a1),
        (B(a25, this-> ubar_rbr_lca_jcr_lca_upright) * a25 + -1 * B(a13, this-> ubar_rbr_upright_jcr_lca_upright) * a13),
        (B(a35, this-> ubar_rbl_lca_jcl_lca_chassis) * a35 + -1 * B(a1, this-> ubar_ground_jcl_lca_chassis) * a1),
        (a36.transpose() * a38 * a40 * a1 + a41 * a5 * B(a35, a36) * a35 + 2 * a42 * B(a37, a36).transpose() * a43 * a1),
        (a44.transpose() * a38 * a40 * a1 + a41 * a5 * B(a35, a44) * a35 + 2 * a42 * B(a37, a44).transpose() * a43 * a1),
        (B(a35, this-> ubar_rbl_lca_jcl_lca_upright) * a35 + -1 * B(a24, this-> ubar_rbl_upright_jcl_lca_upright) * a24),
        (B(a13, this-> ubar_rbr_upright_jcr_hub_bearing) * a13 + -1 * B(a45, this-> ubar_rbr_hub_jcr_hub_bearing) * a45),
        (a46.transpose() * a48 * a50 * a45 + a51 * a53 * B(a13, a46) * a13 + 2 * a54 * B(a47, a46).transpose() * a55 * a45),
        (a56.transpose() * a48 * a50 * a45 + a51 * a53 * B(a13, a56) * a13 + 2 * a54 * B(a47, a56).transpose() * a55 * a45),
        (-1 * derivative(config.UF_mcr_wheel_lock, t, 2) * a57 + a58.transpose() * a53 * (std::cos(config.UF_mcr_wheel_lock(t)) * B(a13, a59) + -1 * std::sin(config.UF_mcr_wheel_lock(t)) * B(a13, a60)) * a13 + (std::cos(config.UF_mcr_wheel_lock(t)) * a59.transpose() * a48 + -1 * std::sin(config.UF_mcr_wheel_lock(t)) * a60.transpose() * a48) * B(a45, a58) * a45 + 2 * (std::cos(config.UF_mcr_wheel_lock(t)) * a54 * B(a47, a59).transpose() + -1 * std::sin(config.UF_mcr_wheel_lock(t)) * a54 * B(a47, a60).transpose()) * B(a52, a58) * a45),
        (B(a24, this-> ubar_rbl_upright_jcl_hub_bearing) * a24 + -1 * B(a61, this-> ubar_rbl_hub_jcl_hub_bearing) * a61),
        (a62.transpose() * a64 * a66 * a61 + a67 * a69 * B(a24, a62) * a24 + 2 * a70 * B(a63, a62).transpose() * a71 * a61),
        (a72.transpose() * a64 * a66 * a61 + a67 * a69 * B(a24, a72) * a24 + 2 * a70 * B(a63, a72).transpose() * a71 * a61),
        (-1 * derivative(config.UF_mcl_wheel_lock, t, 2) * a57 + a73.transpose() * a69 * (std::cos(config.UF_mcl_wheel_lock(t)) * B(a24, a74) + -1 * std::sin(config.UF_mcl_wheel_lock(t)) * B(a24, a75)) * a24 + (std::cos(config.UF_mcl_wheel_lock(t)) * a74.transpose() * a64 + -1 * std::sin(config.UF_mcl_wheel_lock(t)) * a75.transpose() * a64) * B(a61, a73) * a61 + 2 * (std::cos(config.UF_mcl_wheel_lock(t)) * a70 * B(a63, a74).transpose() + -1 * std::sin(config.UF_mcl_wheel_lock(t)) * a70 * B(a63, a75).transpose()) * B(a68, a73) * a61),
        (B(a76, this-> ubar_rbr_upper_strut_jcr_strut_chassis) * a76 + -1 * B(a1, this-> ubar_ground_jcr_strut_chassis) * a1),
        (a77.transpose() * a5 * B(a76, a78) * a76 + a78.transpose() * a80 * B(a1, a77) * a1 + 2 * a81 * B(a79, a78).transpose() * B(a4, a77) * a1),
        (a83 * a80 * a86 * a84 + a87 * a89 * a90 * a76 + 2 * a81 * a91 * a92 * a84),
        (a94 * a80 * a86 * a84 + a87 * a89 * a95 * a76 + 2 * a81 * a96 * a92 * a84),
        (a83 * a80 * a99 + 2 * a81 * a91 * a100 + a101 * a90 * a76),
        (a94 * a80 * a99 + 2 * a81 * a96 * a100 + a101 * a95 * a76),
        (B(a102, this-> ubar_rbl_upper_strut_jcl_strut_chassis) * a102 + -1 * B(a1, this-> ubar_ground_jcl_strut_chassis) * a1),
        (a103.transpose() * a5 * B(a102, a104) * a102 + a104.transpose() * a106 * B(a1, a103) * a1 + 2 * a107 * B(a105, a104).transpose() * B(a4, a103) * a1),
        (a109 * a106 * a112 * a110 + a113 * a115 * a116 * a102 + 2 * a107 * a117 * a118 * a110),
        (a120 * a106 * a112 * a110 + a113 * a115 * a121 * a102 + 2 * a107 * a122 * a118 * a110),
        (a109 * a106 * a125 + 2 * a107 * a117 * a126 + a127 * a116 * a102),
        (a120 * a106 * a125 + 2 * a107 * a122 * a126 + a127 * a121 * a102),
        (B(a84, this-> ubar_rbr_lower_strut_jcr_strut_lca) * a84 + -1 * B(a25, this-> ubar_rbr_lca_jcr_strut_lca) * a25),
        (a128.transpose() * a89 * B(a25, a129) * a25 + a129.transpose() * a30 * B(a84, a128) * a84 + 2 * a130 * B(a88, a128).transpose() * B(a29, a129) * a25),
        (B(a110, this-> ubar_rbl_lower_strut_jcl_strut_lca) * a110 + -1 * B(a35, this-> ubar_rbl_lca_jcl_strut_lca) * a35),
        (a131.transpose() * a115 * B(a35, a132) * a35 + a132.transpose() * a38 * B(a110, a131) * a110 + 2 * a133 * B(a114, a131).transpose() * B(a37, a132) * a35),
        (B(a134, this-> ubar_rbr_tie_rod_jcr_tie_steering) * a134 + -1 * B(a1, this-> ubar_ground_jcr_tie_steering) * a1),
        (a135.transpose() * a5 * B(a134, a136) * a134 + a136.transpose() * A(a137).transpose() * B(a1, a135) * a1 + 2 * a138 * B(a137, a136).transpose() * B(a4, a135) * a1),
        (B(a134, this-> ubar_rbr_tie_rod_jcr_tie_upright) * a134 + -1 * B(a13, this-> ubar_rbr_upright_jcr_tie_upright) * a13),
        (B(a139, this-> ubar_rbl_tie_rod_jcl_tie_steering) * a139 + -1 * B(a1, this-> ubar_ground_jcl_tie_steering) * a1),
        (a140.transpose() * A(a141).transpose() * B(a1, a142) * a1 + a142.transpose() * a5 * B(a139, a140) * a139 + 2 * a143 * B(a141, a140).transpose() * B(a4, a142) * a1),
        (B(a139, this-> ubar_rbl_tie_rod_jcl_tie_upright) * a139 + -1 * B(a24, this-> ubar_rbl_upright_jcl_tie_upright) * a24),
        (-1 * derivative(config.UF_mcr_wheel_travel, t, 2) * a57 + (B(a45, this-> ubar_rbr_hub_mcr_wheel_travel) * a45 + -1 * B(a1, this-> ubar_ground_mcr_wheel_travel) * a1).block(2,0, 1,1)),
        (-1 * derivative(config.UF_mcl_wheel_travel, t, 2) * a57 + (B(a61, this-> ubar_rbl_hub_mcl_wheel_travel) * a61 + -1 * B(a1, this-> ubar_ground_mcl_wheel_travel) * a1).block(2,0, 1,1)),
        Eigen::MatrixXd::Zero(3, 1),
        Eigen::MatrixXd::Zero(4, 1),
        2 * a10 * a0,
        2 * a21 * a14,
        2 * a32 * a25,
        2 * a42 * a35,
        2 * a54 * a13,
        2 * a70 * a24,
        2 * a81 * a76,
        2 * a107 * a102,
        2 * a130 * a84,
        2 * a133 * a110,
        2 * a138 * a134,
        2 * a143 * a139,
        2 * a45.transpose() * a45,
        2 * a61.transpose() * a61;
};

void Topology::eval_jac_eq()
{
    auto& config = this-> config;
    auto& t = this-> t;

    Eigen::Matrix<double, 3, 3> j0 = Eigen::MatrixXd::Identity(3, 3) ;
    Eigen::Vector4d j1 = this-> P_rbr_uca ;
    Eigen::Matrix<double, 1, 3> j2 = Eigen::MatrixXd::Zero(1, 3) ;
    Eigen::Vector3d j3 = this-> Mbar_ground_jcr_uca_chassis.col(2) ;
    Eigen::Matrix<double, 1, 3> j4 = j3.transpose() ;
    Eigen::Vector4d j5 = this-> P_ground ;
    Eigen::Matrix<double, 3, 3> j6 = A(j5).transpose() ;
    Eigen::Vector3d j7 = this-> Mbar_rbr_uca_jcr_uca_chassis.col(0) ;
    Eigen::Vector3d j8 = this-> Mbar_rbr_uca_jcr_uca_chassis.col(1) ;
    Eigen::Matrix<double, 3, 3> j9 = -1 * j0 ;
    Eigen::Matrix<double, 3, 3> j10 = A(j1).transpose() ;
    Eigen::Matrix<double, 3, 4> j11 = B(j5, j3) ;
    Eigen::Vector4d j12 = this-> P_rbr_upright ;
    Eigen::Vector4d j13 = this-> P_rbl_uca ;
    Eigen::Vector3d j14 = this-> Mbar_ground_jcl_uca_chassis.col(2) ;
    Eigen::Matrix<double, 1, 3> j15 = j14.transpose() ;
    Eigen::Vector3d j16 = this-> Mbar_rbl_uca_jcl_uca_chassis.col(0) ;
    Eigen::Vector3d j17 = this-> Mbar_rbl_uca_jcl_uca_chassis.col(1) ;
    Eigen::Matrix<double, 3, 3> j18 = A(j13).transpose() ;
    Eigen::Matrix<double, 3, 4> j19 = B(j5, j14) ;
    Eigen::Vector4d j20 = this-> P_rbl_upright ;
    Eigen::Vector4d j21 = this-> P_rbr_lca ;
    Eigen::Vector3d j22 = this-> Mbar_ground_jcr_lca_chassis.col(2) ;
    Eigen::Matrix<double, 1, 3> j23 = j22.transpose() ;
    Eigen::Vector3d j24 = this-> Mbar_rbr_lca_jcr_lca_chassis.col(0) ;
    Eigen::Vector3d j25 = this-> Mbar_rbr_lca_jcr_lca_chassis.col(1) ;
    Eigen::Matrix<double, 3, 3> j26 = A(j21).transpose() ;
    Eigen::Matrix<double, 3, 4> j27 = B(j5, j22) ;
    Eigen::Vector4d j28 = this-> P_rbl_lca ;
    Eigen::Vector3d j29 = this-> Mbar_ground_jcl_lca_chassis.col(2) ;
    Eigen::Matrix<double, 1, 3> j30 = j29.transpose() ;
    Eigen::Vector3d j31 = this-> Mbar_rbl_lca_jcl_lca_chassis.col(0) ;
    Eigen::Vector3d j32 = this-> Mbar_rbl_lca_jcl_lca_chassis.col(1) ;
    Eigen::Matrix<double, 3, 3> j33 = A(j28).transpose() ;
    Eigen::Matrix<double, 3, 4> j34 = B(j5, j29) ;
    Eigen::Vector3d j35 = this-> Mbar_rbr_hub_jcr_hub_bearing.col(2) ;
    Eigen::Matrix<double, 1, 3> j36 = j35.transpose() ;
    Eigen::Vector4d j37 = this-> P_rbr_hub ;
    Eigen::Matrix<double, 3, 3> j38 = A(j37).transpose() ;
    Eigen::Vector3d j39 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    Eigen::Vector3d j40 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    Eigen::Matrix<double, 3, 3> j41 = A(j12).transpose() ;
    Eigen::Matrix<double, 3, 4> j42 = B(j37, j35) ;
    Eigen::Vector3d j43 = this-> Mbar_rbr_hub_jcr_hub_bearing.col(0) ;
    Eigen::Vector3d j44 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    Eigen::Vector3d j45 = this-> Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    Eigen::Vector3d j46 = this-> Mbar_rbl_hub_jcl_hub_bearing.col(2) ;
    Eigen::Matrix<double, 1, 3> j47 = j46.transpose() ;
    Eigen::Vector4d j48 = this-> P_rbl_hub ;
    Eigen::Matrix<double, 3, 3> j49 = A(j48).transpose() ;
    Eigen::Vector3d j50 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    Eigen::Vector3d j51 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    Eigen::Matrix<double, 3, 3> j52 = A(j20).transpose() ;
    Eigen::Matrix<double, 3, 4> j53 = B(j48, j46) ;
    Eigen::Vector3d j54 = this-> Mbar_rbl_hub_jcl_hub_bearing.col(0) ;
    Eigen::Vector3d j55 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    Eigen::Vector3d j56 = this-> Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    Eigen::Vector4d j57 = this-> P_rbr_upper_strut ;
    Eigen::Vector3d j58 = this-> Mbar_ground_jcr_strut_chassis.col(0) ;
    Eigen::Vector3d j59 = this-> Mbar_rbr_upper_strut_jcr_strut_chassis.col(0) ;
    Eigen::Matrix<double, 3, 3> j60 = A(j57).transpose() ;
    Eigen::Vector3d j61 = this-> Mbar_rbr_lower_strut_jcr_strut.col(2) ;
    Eigen::Matrix<double, 1, 3> j62 = j61.transpose() ;
    Eigen::Vector4d j63 = this-> P_rbr_lower_strut ;
    Eigen::Matrix<double, 3, 3> j64 = A(j63).transpose() ;
    Eigen::Vector3d j65 = this-> Mbar_rbr_upper_strut_jcr_strut.col(0) ;
    Eigen::Matrix<double, 3, 4> j66 = B(j57, j65) ;
    Eigen::Vector3d j67 = this-> Mbar_rbr_upper_strut_jcr_strut.col(1) ;
    Eigen::Matrix<double, 3, 4> j68 = B(j57, j67) ;
    Eigen::Matrix<double, 1, 3> j69 = j65.transpose() ;
    Eigen::Matrix<double, 1, 3> j70 = j69 * j60 ;
    Eigen::Vector3d j71 = this-> ubar_rbr_upper_strut_jcr_strut ;
    Eigen::Matrix<double, 3, 4> j72 = B(j57, j71) ;
    Eigen::Vector3d j73 = this-> ubar_rbr_lower_strut_jcr_strut ;
    Eigen::Matrix<double, 1, 3> j74 = (this-> R_rbr_upper_strut.transpose() + -1 * this-> R_rbr_lower_strut.transpose() + j71.transpose() * j60 + -1 * j73.transpose() * j64) ;
    Eigen::Matrix<double, 1, 3> j75 = j67.transpose() ;
    Eigen::Matrix<double, 1, 3> j76 = j75 * j60 ;
    Eigen::Matrix<double, 3, 4> j77 = B(j63, j61) ;
    Eigen::Matrix<double, 3, 4> j78 = B(j63, j73) ;
    Eigen::Vector4d j79 = this-> P_rbl_upper_strut ;
    Eigen::Vector3d j80 = this-> Mbar_ground_jcl_strut_chassis.col(0) ;
    Eigen::Vector3d j81 = this-> Mbar_rbl_upper_strut_jcl_strut_chassis.col(0) ;
    Eigen::Matrix<double, 3, 3> j82 = A(j79).transpose() ;
    Eigen::Vector3d j83 = this-> Mbar_rbl_lower_strut_jcl_strut.col(2) ;
    Eigen::Matrix<double, 1, 3> j84 = j83.transpose() ;
    Eigen::Vector4d j85 = this-> P_rbl_lower_strut ;
    Eigen::Matrix<double, 3, 3> j86 = A(j85).transpose() ;
    Eigen::Vector3d j87 = this-> Mbar_rbl_upper_strut_jcl_strut.col(0) ;
    Eigen::Matrix<double, 3, 4> j88 = B(j79, j87) ;
    Eigen::Vector3d j89 = this-> Mbar_rbl_upper_strut_jcl_strut.col(1) ;
    Eigen::Matrix<double, 3, 4> j90 = B(j79, j89) ;
    Eigen::Matrix<double, 1, 3> j91 = j87.transpose() ;
    Eigen::Matrix<double, 1, 3> j92 = j91 * j82 ;
    Eigen::Vector3d j93 = this-> ubar_rbl_upper_strut_jcl_strut ;
    Eigen::Matrix<double, 3, 4> j94 = B(j79, j93) ;
    Eigen::Vector3d j95 = this-> ubar_rbl_lower_strut_jcl_strut ;
    Eigen::Matrix<double, 1, 3> j96 = (this-> R_rbl_upper_strut.transpose() + -1 * this-> R_rbl_lower_strut.transpose() + j93.transpose() * j82 + -1 * j95.transpose() * j86) ;
    Eigen::Matrix<double, 1, 3> j97 = j89.transpose() ;
    Eigen::Matrix<double, 1, 3> j98 = j97 * j82 ;
    Eigen::Matrix<double, 3, 4> j99 = B(j85, j83) ;
    Eigen::Matrix<double, 3, 4> j100 = B(j85, j95) ;
    Eigen::Vector3d j101 = this-> Mbar_rbr_lca_jcr_strut_lca.col(0) ;
    Eigen::Vector3d j102 = this-> Mbar_rbr_lower_strut_jcr_strut_lca.col(0) ;
    Eigen::Vector3d j103 = this-> Mbar_rbl_lca_jcl_strut_lca.col(0) ;
    Eigen::Vector3d j104 = this-> Mbar_rbl_lower_strut_jcl_strut_lca.col(0) ;
    Eigen::Vector4d j105 = this-> P_rbr_tie_rod ;
    Eigen::Vector3d j106 = this-> Mbar_ground_jcr_tie_steering.col(0) ;
    Eigen::Vector3d j107 = this-> Mbar_rbr_tie_rod_jcr_tie_steering.col(0) ;
    Eigen::Vector4d j108 = this-> P_rbl_tie_rod ;
    Eigen::Vector3d j109 = this-> Mbar_ground_jcl_tie_steering.col(0) ;
    Eigen::Vector3d j110 = this-> Mbar_rbl_tie_rod_jcl_tie_steering.col(0) ;
    Eigen::Matrix<double, 1, 3> j111 = j0.block(2,0, 1,3) ;
    Eigen::Matrix<double, 1, 3> j112 = -1 * j111 ;

    this-> jac_eq = 
        {j9,
        -1 * B(j5, this-> ubar_ground_jcr_uca_chassis),
        j0,
        B(j1, this-> ubar_rbr_uca_jcr_uca_chassis),
        j2,
        j7.transpose() * j10 * j11,
        j2,
        j4 * j6 * B(j1, j7),
        j2,
        j8.transpose() * j10 * j11,
        j2,
        j4 * j6 * B(j1, j8),
        j0,
        B(j1, this-> ubar_rbr_uca_jcr_uca_upright),
        j9,
        -1 * B(j12, this-> ubar_rbr_upright_jcr_uca_upright),
        j9,
        -1 * B(j5, this-> ubar_ground_jcl_uca_chassis),
        j0,
        B(j13, this-> ubar_rbl_uca_jcl_uca_chassis),
        j2,
        j16.transpose() * j18 * j19,
        j2,
        j15 * j6 * B(j13, j16),
        j2,
        j17.transpose() * j18 * j19,
        j2,
        j15 * j6 * B(j13, j17),
        j0,
        B(j13, this-> ubar_rbl_uca_jcl_uca_upright),
        j9,
        -1 * B(j20, this-> ubar_rbl_upright_jcl_uca_upright),
        j9,
        -1 * B(j5, this-> ubar_ground_jcr_lca_chassis),
        j0,
        B(j21, this-> ubar_rbr_lca_jcr_lca_chassis),
        j2,
        j24.transpose() * j26 * j27,
        j2,
        j23 * j6 * B(j21, j24),
        j2,
        j25.transpose() * j26 * j27,
        j2,
        j23 * j6 * B(j21, j25),
        j0,
        B(j21, this-> ubar_rbr_lca_jcr_lca_upright),
        j9,
        -1 * B(j12, this-> ubar_rbr_upright_jcr_lca_upright),
        j9,
        -1 * B(j5, this-> ubar_ground_jcl_lca_chassis),
        j0,
        B(j28, this-> ubar_rbl_lca_jcl_lca_chassis),
        j2,
        j31.transpose() * j33 * j34,
        j2,
        j30 * j6 * B(j28, j31),
        j2,
        j32.transpose() * j33 * j34,
        j2,
        j30 * j6 * B(j28, j32),
        j0,
        B(j28, this-> ubar_rbl_lca_jcl_lca_upright),
        j9,
        -1 * B(j20, this-> ubar_rbl_upright_jcl_lca_upright),
        j0,
        B(j12, this-> ubar_rbr_upright_jcr_hub_bearing),
        j9,
        -1 * B(j37, this-> ubar_rbr_hub_jcr_hub_bearing),
        j2,
        j36 * j38 * B(j12, j39),
        j2,
        j39.transpose() * j41 * j42,
        j2,
        j36 * j38 * B(j12, j40),
        j2,
        j40.transpose() * j41 * j42,
        j2,
        j43.transpose() * j38 * (std::cos(config.UF_mcr_wheel_lock(t)) * B(j12, j44) + -1 * std::sin(config.UF_mcr_wheel_lock(t)) * B(j12, j45)),
        j2,
        (std::cos(config.UF_mcr_wheel_lock(t)) * j44.transpose() * j41 + -1 * std::sin(config.UF_mcr_wheel_lock(t)) * j45.transpose() * j41) * B(j37, j43),
        j0,
        B(j20, this-> ubar_rbl_upright_jcl_hub_bearing),
        j9,
        -1 * B(j48, this-> ubar_rbl_hub_jcl_hub_bearing),
        j2,
        j47 * j49 * B(j20, j50),
        j2,
        j50.transpose() * j52 * j53,
        j2,
        j47 * j49 * B(j20, j51),
        j2,
        j51.transpose() * j52 * j53,
        j2,
        j54.transpose() * j49 * (std::cos(config.UF_mcl_wheel_lock(t)) * B(j20, j55) + -1 * std::sin(config.UF_mcl_wheel_lock(t)) * B(j20, j56)),
        j2,
        (std::cos(config.UF_mcl_wheel_lock(t)) * j55.transpose() * j52 + -1 * std::sin(config.UF_mcl_wheel_lock(t)) * j56.transpose() * j52) * B(j48, j54),
        j9,
        -1 * B(j5, this-> ubar_ground_jcr_strut_chassis),
        j0,
        B(j57, this-> ubar_rbr_upper_strut_jcr_strut_chassis),
        j2,
        j59.transpose() * j60 * B(j5, j58),
        j2,
        j58.transpose() * j6 * B(j57, j59),
        j2,
        j62 * j64 * j66,
        j2,
        j69 * j60 * j77,
        j2,
        j62 * j64 * j68,
        j2,
        j75 * j60 * j77,
        j70,
        (j69 * j60 * j72 + j74 * j66),
        -1 * j70,
        -1 * j69 * j60 * j78,
        j76,
        (j75 * j60 * j72 + j74 * j68),
        -1 * j76,
        -1 * j75 * j60 * j78,
        j9,
        -1 * B(j5, this-> ubar_ground_jcl_strut_chassis),
        j0,
        B(j79, this-> ubar_rbl_upper_strut_jcl_strut_chassis),
        j2,
        j81.transpose() * j82 * B(j5, j80),
        j2,
        j80.transpose() * j6 * B(j79, j81),
        j2,
        j84 * j86 * j88,
        j2,
        j91 * j82 * j99,
        j2,
        j84 * j86 * j90,
        j2,
        j97 * j82 * j99,
        j92,
        (j91 * j82 * j94 + j96 * j88),
        -1 * j92,
        -1 * j91 * j82 * j100,
        j98,
        (j97 * j82 * j94 + j96 * j90),
        -1 * j98,
        -1 * j97 * j82 * j100,
        j9,
        -1 * B(j21, this-> ubar_rbr_lca_jcr_strut_lca),
        j0,
        B(j63, this-> ubar_rbr_lower_strut_jcr_strut_lca),
        j2,
        j102.transpose() * j64 * B(j21, j101),
        j2,
        j101.transpose() * j26 * B(j63, j102),
        j9,
        -1 * B(j28, this-> ubar_rbl_lca_jcl_strut_lca),
        j0,
        B(j85, this-> ubar_rbl_lower_strut_jcl_strut_lca),
        j2,
        j104.transpose() * j86 * B(j28, j103),
        j2,
        j103.transpose() * j33 * B(j85, j104),
        j9,
        -1 * B(j5, this-> ubar_ground_jcr_tie_steering),
        j0,
        B(j105, this-> ubar_rbr_tie_rod_jcr_tie_steering),
        j2,
        j107.transpose() * A(j105).transpose() * B(j5, j106),
        j2,
        j106.transpose() * j6 * B(j105, j107),
        j9,
        -1 * B(j12, this-> ubar_rbr_upright_jcr_tie_upright),
        j0,
        B(j105, this-> ubar_rbr_tie_rod_jcr_tie_upright),
        j9,
        -1 * B(j5, this-> ubar_ground_jcl_tie_steering),
        j0,
        B(j108, this-> ubar_rbl_tie_rod_jcl_tie_steering),
        j2,
        j110.transpose() * A(j108).transpose() * B(j5, j109),
        j2,
        j109.transpose() * j6 * B(j108, j110),
        j9,
        -1 * B(j20, this-> ubar_rbl_upright_jcl_tie_upright),
        j0,
        B(j108, this-> ubar_rbl_tie_rod_jcl_tie_upright),
        j112,
        -1 * B(j5, this-> ubar_ground_mcr_wheel_travel).block(2,0, 1,4),
        j111,
        B(j37, this-> ubar_rbr_hub_mcr_wheel_travel).block(2,0, 1,4),
        j112,
        -1 * B(j5, this-> ubar_ground_mcl_wheel_travel).block(2,0, 1,4),
        j111,
        B(j48, this-> ubar_rbl_hub_mcl_wheel_travel).block(2,0, 1,4),
        j0,
        Eigen::MatrixXd::Zero(3, 4),
        Eigen::MatrixXd::Zero(4, 3),
        Eigen::MatrixXd::Identity(4, 4),
        j2,
        2 * j1.transpose(),
        j2,
        2 * j13.transpose(),
        j2,
        2 * j21.transpose(),
        j2,
        2 * j28.transpose(),
        j2,
        2 * j12.transpose(),
        j2,
        2 * j20.transpose(),
        j2,
        2 * j57.transpose(),
        j2,
        2 * j79.transpose(),
        j2,
        2 * j63.transpose(),
        j2,
        2 * j85.transpose(),
        j2,
        2 * j105.transpose(),
        j2,
        2 * j108.transpose(),
        j2,
        2 * j37.transpose(),
        j2,
        2 * j48.transpose()};
};


