
#include "double_wishbone_direct_acting.hpp"

// ============================================================================
//                     Configuration Class Implementation
// ============================================================================

typedef Eigen::SparseMatrix<double, Eigen::ColMajor> SparseBlock;


Configuration::Configuration()
    :
        ConfigInputs()
    {}

void Configuration::constructFromJSON(const std::string& fileName)
{
    ConfigInputs.constructFromJSON(fileName);
    populateArguments();
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
    R_ground << 0, 0, 0 ;
    P_ground << 1, 0, 0, 0 ;

    q.resize(105);
    q << 
        R_ground, 
        P_ground, 
        R_rbr_uca, 
        P_rbr_uca, 
        R_rbl_uca, 
        P_rbl_uca, 
        R_rbr_lca, 
        P_rbr_lca, 
        R_rbl_lca, 
        P_rbl_lca, 
        R_rbr_upright, 
        P_rbr_upright, 
        R_rbl_upright, 
        P_rbl_upright, 
        R_rbr_upper_strut, 
        P_rbr_upper_strut, 
        R_rbl_upper_strut, 
        P_rbl_upper_strut, 
        R_rbr_lower_strut, 
        P_rbr_lower_strut, 
        R_rbl_lower_strut, 
        P_rbl_lower_strut, 
        R_rbr_tie_rod, 
        P_rbr_tie_rod, 
        R_rbl_tie_rod, 
        P_rbl_tie_rod, 
        R_rbr_hub, 
        P_rbr_hub, 
        R_rbl_hub, 
        P_rbl_hub;

    qd.resize(105);
    qd << 
        Rd_ground, 
        Pd_ground, 
        Rd_rbr_uca, 
        Pd_rbr_uca, 
        Rd_rbl_uca, 
        Pd_rbl_uca, 
        Rd_rbr_lca, 
        Pd_rbr_lca, 
        Rd_rbl_lca, 
        Pd_rbl_lca, 
        Rd_rbr_upright, 
        Pd_rbr_upright, 
        Rd_rbl_upright, 
        Pd_rbl_upright, 
        Rd_rbr_upper_strut, 
        Pd_rbr_upper_strut, 
        Rd_rbl_upper_strut, 
        Pd_rbl_upper_strut, 
        Rd_rbr_lower_strut, 
        Pd_rbr_lower_strut, 
        Rd_rbl_lower_strut, 
        Pd_rbl_lower_strut, 
        Rd_rbr_tie_rod, 
        Pd_rbr_tie_rod, 
        Rd_rbl_tie_rod, 
        Pd_rbl_tie_rod, 
        Rd_rbr_hub, 
        Pd_rbr_hub, 
        Rd_rbl_hub, 
        Pd_rbl_hub;
};

// ============================================================================
//                     Coordinates Struct Constructor
// ============================================================================

Coordinates::Coordinates(Eigen::Ref<Eigen::VectorXd> _q, 
                         Eigen::Ref<Eigen::VectorXd> _qd, 
                         Eigen::Ref<Eigen::VectorXd> _qdd,
                         Eigen::Ref<Eigen::VectorXd> _lgr)
    : // Initializer list initializing the needed struct memebrs.
        q(_q), qd(_qd), qdd(_qdd), lgr(_lgr)
    {};


// ============================================================================
//                     Topology Class Implementation
// ============================================================================

// Topology Constructor
// ====================
Topology::Topology(std::string name, 
            Eigen::Ref<Eigen::VectorXd> q, 
            Eigen::Ref<Eigen::VectorXd> qd, 
            Eigen::Ref<Eigen::VectorXd> qdd,
            Eigen::Ref<Eigen::VectorXd> lgr)

    : // Initializer list initializing the needed struct memebrs.
        prefix(name), coord(q, qd, qdd, lgr), config()

{
    pos_eq.resize(nc);
    vel_eq.resize(nc);
    acc_eq.resize(nc);
    frc_eq.resize(n);

    jac_rows.resize(224);
    jac_cols.resize(224);
    jac_eq.reserve(224);

    mas_eq.reserve(2*ncols);
};

// Topology initializer and assembler
// ==================================
void Topology::initialize()
{
    Dict_SS interface_map;
    map_indicies();
    assemble(indicies_map, interface_map, 0);
    coord.q << config.q;
    eval_constants();
};

void Topology::map_indicies()
{
    int i = 0;
    for (auto& name : names) {indicies_map[prefix + name] = i; i++;};
};


void Topology::assemble(Dict_SI& indicies_map, Dict_SS& interface_map, int rows_offset)
{
    set_mapping(indicies_map, interface_map);

    jac_rows << 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 27, 28, 28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 39, 40, 40, 40, 40, 41, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 44, 45, 45, 45, 45, 46, 46, 46, 46, 47, 47, 47, 47, 48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55, 56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63;
    jac_rows += (rows_offset * Eigen::VectorXd::Ones(jac_rows.size()) );

    jac_cols << 
        ground*2, 
        ground*2+1, 
        rbr_uca*2, 
        rbr_uca*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_uca*2, 
        rbr_uca*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_uca*2, 
        rbr_uca*2+1, 
        rbr_uca*2, 
        rbr_uca*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_uca*2, 
        rbl_uca*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_uca*2, 
        rbl_uca*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_uca*2, 
        rbl_uca*2+1, 
        rbl_uca*2, 
        rbl_uca*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_lca*2, 
        rbr_lca*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_lca*2, 
        rbr_lca*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_lca*2, 
        rbr_lca*2+1, 
        rbr_lca*2, 
        rbr_lca*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_lca*2, 
        rbl_lca*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_lca*2, 
        rbl_lca*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_lca*2, 
        rbl_lca*2+1, 
        rbl_lca*2, 
        rbl_lca*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        rbr_hub*2, 
        rbr_hub*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        rbr_hub*2, 
        rbr_hub*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        rbr_hub*2, 
        rbr_hub*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        rbr_hub*2, 
        rbr_hub*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        rbl_hub*2, 
        rbl_hub*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        rbl_hub*2, 
        rbl_hub*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        rbl_hub*2, 
        rbl_hub*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        rbl_hub*2, 
        rbl_hub*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_upper_strut*2, 
        rbr_upper_strut*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_upper_strut*2, 
        rbr_upper_strut*2+1, 
        rbr_upper_strut*2, 
        rbr_upper_strut*2+1, 
        rbr_lower_strut*2, 
        rbr_lower_strut*2+1, 
        rbr_upper_strut*2, 
        rbr_upper_strut*2+1, 
        rbr_lower_strut*2, 
        rbr_lower_strut*2+1, 
        rbr_upper_strut*2, 
        rbr_upper_strut*2+1, 
        rbr_lower_strut*2, 
        rbr_lower_strut*2+1, 
        rbr_upper_strut*2, 
        rbr_upper_strut*2+1, 
        rbr_lower_strut*2, 
        rbr_lower_strut*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_upper_strut*2, 
        rbl_upper_strut*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_upper_strut*2, 
        rbl_upper_strut*2+1, 
        rbl_upper_strut*2, 
        rbl_upper_strut*2+1, 
        rbl_lower_strut*2, 
        rbl_lower_strut*2+1, 
        rbl_upper_strut*2, 
        rbl_upper_strut*2+1, 
        rbl_lower_strut*2, 
        rbl_lower_strut*2+1, 
        rbl_upper_strut*2, 
        rbl_upper_strut*2+1, 
        rbl_lower_strut*2, 
        rbl_lower_strut*2+1, 
        rbl_upper_strut*2, 
        rbl_upper_strut*2+1, 
        rbl_lower_strut*2, 
        rbl_lower_strut*2+1, 
        rbr_lca*2, 
        rbr_lca*2+1, 
        rbr_lower_strut*2, 
        rbr_lower_strut*2+1, 
        rbr_lca*2, 
        rbr_lca*2+1, 
        rbr_lower_strut*2, 
        rbr_lower_strut*2+1, 
        rbl_lca*2, 
        rbl_lca*2+1, 
        rbl_lower_strut*2, 
        rbl_lower_strut*2+1, 
        rbl_lca*2, 
        rbl_lca*2+1, 
        rbl_lower_strut*2, 
        rbl_lower_strut*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_tie_rod*2, 
        rbr_tie_rod*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_tie_rod*2, 
        rbr_tie_rod*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        rbr_tie_rod*2, 
        rbr_tie_rod*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_tie_rod*2, 
        rbl_tie_rod*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_tie_rod*2, 
        rbl_tie_rod*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        rbl_tie_rod*2, 
        rbl_tie_rod*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_hub*2, 
        rbr_hub*2+1, 
        ground*2, 
        ground*2+1, 
        rbl_hub*2, 
        rbl_hub*2+1, 
        ground*2, 
        ground*2+1, 
        ground*2, 
        ground*2+1, 
        rbr_uca*2, 
        rbr_uca*2+1, 
        rbl_uca*2, 
        rbl_uca*2+1, 
        rbr_lca*2, 
        rbr_lca*2+1, 
        rbl_lca*2, 
        rbl_lca*2+1, 
        rbr_upright*2, 
        rbr_upright*2+1, 
        rbl_upright*2, 
        rbl_upright*2+1, 
        rbr_upper_strut*2, 
        rbr_upper_strut*2+1, 
        rbl_upper_strut*2, 
        rbl_upper_strut*2+1, 
        rbr_lower_strut*2, 
        rbr_lower_strut*2+1, 
        rbl_lower_strut*2, 
        rbl_lower_strut*2+1, 
        rbr_tie_rod*2, 
        rbr_tie_rod*2+1, 
        rbl_tie_rod*2, 
        rbl_tie_rod*2+1, 
        rbr_hub*2, 
        rbr_hub*2+1, 
        rbl_hub*2, 
        rbl_hub*2+1;
};


void Topology::set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map)
{
    auto& p = this-> prefix;

    ground = indicies_map[p+"ground"];
    rbr_uca = indicies_map[p+"rbr_uca"];
    rbl_uca = indicies_map[p+"rbl_uca"];
    rbr_lca = indicies_map[p+"rbr_lca"];
    rbl_lca = indicies_map[p+"rbl_lca"];
    rbr_upright = indicies_map[p+"rbr_upright"];
    rbl_upright = indicies_map[p+"rbl_upright"];
    rbr_upper_strut = indicies_map[p+"rbr_upper_strut"];
    rbl_upper_strut = indicies_map[p+"rbl_upper_strut"];
    rbr_lower_strut = indicies_map[p+"rbr_lower_strut"];
    rbl_lower_strut = indicies_map[p+"rbl_lower_strut"];
    rbr_tie_rod = indicies_map[p+"rbr_tie_rod"];
    rbl_tie_rod = indicies_map[p+"rbl_tie_rod"];
    rbr_hub = indicies_map[p+"rbr_hub"];
    rbl_hub = indicies_map[p+"rbl_hub"];

    
};


void Topology::eval_constants()
{
    R_ground << 0, 0, 0 ;
    P_ground << 1, 0, 0, 0 ;
    Pg_ground << 1, 0, 0, 0 ;
    m_ground = 1.0 ;
    Jbar_ground << 1, 0, 0, 0, 1, 0, 0, 0, 1 ;
    F_rbr_uca_gravity << 0, 0, -9810.0*config.m_rbr_uca ;
    F_rbl_uca_gravity << 0, 0, -9810.0*config.m_rbl_uca ;
    F_rbr_lca_gravity << 0, 0, -9810.0*config.m_rbr_lca ;
    F_rbl_lca_gravity << 0, 0, -9810.0*config.m_rbl_lca ;
    F_rbr_upright_gravity << 0, 0, -9810.0*config.m_rbr_upright ;
    F_rbl_upright_gravity << 0, 0, -9810.0*config.m_rbl_upright ;
    F_rbr_upper_strut_gravity << 0, 0, -9810.0*config.m_rbr_upper_strut ;
    T_rbr_upper_strut_far_strut << Eigen::MatrixXd::Zero(3, 1) ;
    T_rbr_lower_strut_far_strut << Eigen::MatrixXd::Zero(3, 1) ;
    F_rbl_upper_strut_gravity << 0, 0, -9810.0*config.m_rbl_upper_strut ;
    T_rbl_upper_strut_fal_strut << Eigen::MatrixXd::Zero(3, 1) ;
    T_rbl_lower_strut_fal_strut << Eigen::MatrixXd::Zero(3, 1) ;
    F_rbr_lower_strut_gravity << 0, 0, -9810.0*config.m_rbr_lower_strut ;
    F_rbl_lower_strut_gravity << 0, 0, -9810.0*config.m_rbl_lower_strut ;
    F_rbr_tie_rod_gravity << 0, 0, -9810.0*config.m_rbr_tie_rod ;
    F_rbl_tie_rod_gravity << 0, 0, -9810.0*config.m_rbl_tie_rod ;
    F_rbr_hub_gravity << 0, 0, -9810.0*config.m_rbr_hub ;
    F_rbl_hub_gravity << 0, 0, -9810.0*config.m_rbl_hub ;
                    
    Mbar_rbr_uca_jcr_uca_chassis << (A(config.P_rbr_uca).transpose() * triad(config.ax1_jcr_uca_chassis)) ;
    Mbar_ground_jcr_uca_chassis << (A(P_ground).transpose() * triad(config.ax1_jcr_uca_chassis)) ;
    ubar_rbr_uca_jcr_uca_chassis << ((A(config.P_rbr_uca).transpose() * config.pt1_jcr_uca_chassis) + (-1 * A(config.P_rbr_uca).transpose() * config.R_rbr_uca)) ;
    ubar_ground_jcr_uca_chassis << ((A(P_ground).transpose() * config.pt1_jcr_uca_chassis) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbr_uca_jcr_uca_upright << (A(config.P_rbr_uca).transpose() * triad(config.ax1_jcr_uca_upright)) ;
    Mbar_rbr_upright_jcr_uca_upright << (A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_uca_upright)) ;
    ubar_rbr_uca_jcr_uca_upright << ((A(config.P_rbr_uca).transpose() * config.pt1_jcr_uca_upright) + (-1 * A(config.P_rbr_uca).transpose() * config.R_rbr_uca)) ;
    ubar_rbr_upright_jcr_uca_upright << ((A(config.P_rbr_upright).transpose() * config.pt1_jcr_uca_upright) + (-1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright)) ;
    Mbar_rbl_uca_jcl_uca_chassis << (A(config.P_rbl_uca).transpose() * triad(config.ax1_jcl_uca_chassis)) ;
    Mbar_ground_jcl_uca_chassis << (A(P_ground).transpose() * triad(config.ax1_jcl_uca_chassis)) ;
    ubar_rbl_uca_jcl_uca_chassis << ((A(config.P_rbl_uca).transpose() * config.pt1_jcl_uca_chassis) + (-1 * A(config.P_rbl_uca).transpose() * config.R_rbl_uca)) ;
    ubar_ground_jcl_uca_chassis << ((A(P_ground).transpose() * config.pt1_jcl_uca_chassis) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbl_uca_jcl_uca_upright << (A(config.P_rbl_uca).transpose() * triad(config.ax1_jcl_uca_upright)) ;
    Mbar_rbl_upright_jcl_uca_upright << (A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_uca_upright)) ;
    ubar_rbl_uca_jcl_uca_upright << ((A(config.P_rbl_uca).transpose() * config.pt1_jcl_uca_upright) + (-1 * A(config.P_rbl_uca).transpose() * config.R_rbl_uca)) ;
    ubar_rbl_upright_jcl_uca_upright << ((A(config.P_rbl_upright).transpose() * config.pt1_jcl_uca_upright) + (-1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright)) ;
    Mbar_rbr_lca_jcr_lca_chassis << (A(config.P_rbr_lca).transpose() * triad(config.ax1_jcr_lca_chassis)) ;
    Mbar_ground_jcr_lca_chassis << (A(P_ground).transpose() * triad(config.ax1_jcr_lca_chassis)) ;
    ubar_rbr_lca_jcr_lca_chassis << ((A(config.P_rbr_lca).transpose() * config.pt1_jcr_lca_chassis) + (-1 * A(config.P_rbr_lca).transpose() * config.R_rbr_lca)) ;
    ubar_ground_jcr_lca_chassis << ((A(P_ground).transpose() * config.pt1_jcr_lca_chassis) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbr_lca_jcr_lca_upright << (A(config.P_rbr_lca).transpose() * triad(config.ax1_jcr_lca_upright)) ;
    Mbar_rbr_upright_jcr_lca_upright << (A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_lca_upright)) ;
    ubar_rbr_lca_jcr_lca_upright << ((A(config.P_rbr_lca).transpose() * config.pt1_jcr_lca_upright) + (-1 * A(config.P_rbr_lca).transpose() * config.R_rbr_lca)) ;
    ubar_rbr_upright_jcr_lca_upright << ((A(config.P_rbr_upright).transpose() * config.pt1_jcr_lca_upright) + (-1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright)) ;
    Mbar_rbl_lca_jcl_lca_chassis << (A(config.P_rbl_lca).transpose() * triad(config.ax1_jcl_lca_chassis)) ;
    Mbar_ground_jcl_lca_chassis << (A(P_ground).transpose() * triad(config.ax1_jcl_lca_chassis)) ;
    ubar_rbl_lca_jcl_lca_chassis << ((A(config.P_rbl_lca).transpose() * config.pt1_jcl_lca_chassis) + (-1 * A(config.P_rbl_lca).transpose() * config.R_rbl_lca)) ;
    ubar_ground_jcl_lca_chassis << ((A(P_ground).transpose() * config.pt1_jcl_lca_chassis) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbl_lca_jcl_lca_upright << (A(config.P_rbl_lca).transpose() * triad(config.ax1_jcl_lca_upright)) ;
    Mbar_rbl_upright_jcl_lca_upright << (A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_lca_upright)) ;
    ubar_rbl_lca_jcl_lca_upright << ((A(config.P_rbl_lca).transpose() * config.pt1_jcl_lca_upright) + (-1 * A(config.P_rbl_lca).transpose() * config.R_rbl_lca)) ;
    ubar_rbl_upright_jcl_lca_upright << ((A(config.P_rbl_upright).transpose() * config.pt1_jcl_lca_upright) + (-1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright)) ;
    Mbar_rbr_upright_jcr_hub_bearing << (A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_hub_bearing)) ;
    Mbar_rbr_hub_jcr_hub_bearing << (A(config.P_rbr_hub).transpose() * triad(config.ax1_jcr_hub_bearing)) ;
    ubar_rbr_upright_jcr_hub_bearing << ((A(config.P_rbr_upright).transpose() * config.pt1_jcr_hub_bearing) + (-1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright)) ;
    ubar_rbr_hub_jcr_hub_bearing << ((A(config.P_rbr_hub).transpose() * config.pt1_jcr_hub_bearing) + (-1 * A(config.P_rbr_hub).transpose() * config.R_rbr_hub)) ;
    Mbar_rbr_upright_jcr_hub_bearing << (A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_hub_bearing)) ;
    Mbar_rbr_hub_jcr_hub_bearing << (A(config.P_rbr_hub).transpose() * triad(config.ax1_jcr_hub_bearing)) ;
    Mbar_rbl_upright_jcl_hub_bearing << (A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_hub_bearing)) ;
    Mbar_rbl_hub_jcl_hub_bearing << (A(config.P_rbl_hub).transpose() * triad(config.ax1_jcl_hub_bearing)) ;
    ubar_rbl_upright_jcl_hub_bearing << ((A(config.P_rbl_upright).transpose() * config.pt1_jcl_hub_bearing) + (-1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright)) ;
    ubar_rbl_hub_jcl_hub_bearing << ((A(config.P_rbl_hub).transpose() * config.pt1_jcl_hub_bearing) + (-1 * A(config.P_rbl_hub).transpose() * config.R_rbl_hub)) ;
    Mbar_rbl_upright_jcl_hub_bearing << (A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_hub_bearing)) ;
    Mbar_rbl_hub_jcl_hub_bearing << (A(config.P_rbl_hub).transpose() * triad(config.ax1_jcl_hub_bearing)) ;
    Mbar_rbr_upper_strut_jcr_strut_chassis << (A(config.P_rbr_upper_strut).transpose() * triad(config.ax1_jcr_strut_chassis)) ;
    Mbar_ground_jcr_strut_chassis << (A(P_ground).transpose() * triad(config.ax2_jcr_strut_chassis, triad(config.ax1_jcr_strut_chassis).block(0,1, 3,1))) ;
    ubar_rbr_upper_strut_jcr_strut_chassis << ((A(config.P_rbr_upper_strut).transpose() * config.pt1_jcr_strut_chassis) + (-1 * A(config.P_rbr_upper_strut).transpose() * config.R_rbr_upper_strut)) ;
    ubar_ground_jcr_strut_chassis << ((A(P_ground).transpose() * config.pt1_jcr_strut_chassis) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbr_upper_strut_jcr_strut << (A(config.P_rbr_upper_strut).transpose() * triad(config.ax1_jcr_strut)) ;
    Mbar_rbr_lower_strut_jcr_strut << (A(config.P_rbr_lower_strut).transpose() * triad(config.ax1_jcr_strut)) ;
    ubar_rbr_upper_strut_jcr_strut << ((A(config.P_rbr_upper_strut).transpose() * config.pt1_jcr_strut) + (-1 * A(config.P_rbr_upper_strut).transpose() * config.R_rbr_upper_strut)) ;
    ubar_rbr_lower_strut_jcr_strut << ((A(config.P_rbr_lower_strut).transpose() * config.pt1_jcr_strut) + (-1 * A(config.P_rbr_lower_strut).transpose() * config.R_rbr_lower_strut)) ;
    ubar_rbr_upper_strut_far_strut << ((A(config.P_rbr_upper_strut).transpose() * config.pt1_far_strut) + (-1 * A(config.P_rbr_upper_strut).transpose() * config.R_rbr_upper_strut)) ;
    ubar_rbr_lower_strut_far_strut << ((A(config.P_rbr_lower_strut).transpose() * config.pt2_far_strut) + (-1 * A(config.P_rbr_lower_strut).transpose() * config.R_rbr_lower_strut)) ;
    Mbar_rbl_upper_strut_jcl_strut_chassis << (A(config.P_rbl_upper_strut).transpose() * triad(config.ax1_jcl_strut_chassis)) ;
    Mbar_ground_jcl_strut_chassis << (A(P_ground).transpose() * triad(config.ax2_jcl_strut_chassis, triad(config.ax1_jcl_strut_chassis).block(0,1, 3,1))) ;
    ubar_rbl_upper_strut_jcl_strut_chassis << ((A(config.P_rbl_upper_strut).transpose() * config.pt1_jcl_strut_chassis) + (-1 * A(config.P_rbl_upper_strut).transpose() * config.R_rbl_upper_strut)) ;
    ubar_ground_jcl_strut_chassis << ((A(P_ground).transpose() * config.pt1_jcl_strut_chassis) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbl_upper_strut_jcl_strut << (A(config.P_rbl_upper_strut).transpose() * triad(config.ax1_jcl_strut)) ;
    Mbar_rbl_lower_strut_jcl_strut << (A(config.P_rbl_lower_strut).transpose() * triad(config.ax1_jcl_strut)) ;
    ubar_rbl_upper_strut_jcl_strut << ((A(config.P_rbl_upper_strut).transpose() * config.pt1_jcl_strut) + (-1 * A(config.P_rbl_upper_strut).transpose() * config.R_rbl_upper_strut)) ;
    ubar_rbl_lower_strut_jcl_strut << ((A(config.P_rbl_lower_strut).transpose() * config.pt1_jcl_strut) + (-1 * A(config.P_rbl_lower_strut).transpose() * config.R_rbl_lower_strut)) ;
    ubar_rbl_upper_strut_fal_strut << ((A(config.P_rbl_upper_strut).transpose() * config.pt1_fal_strut) + (-1 * A(config.P_rbl_upper_strut).transpose() * config.R_rbl_upper_strut)) ;
    ubar_rbl_lower_strut_fal_strut << ((A(config.P_rbl_lower_strut).transpose() * config.pt2_fal_strut) + (-1 * A(config.P_rbl_lower_strut).transpose() * config.R_rbl_lower_strut)) ;
    Mbar_rbr_lower_strut_jcr_strut_lca << (A(config.P_rbr_lower_strut).transpose() * triad(config.ax1_jcr_strut_lca)) ;
    Mbar_rbr_lca_jcr_strut_lca << (A(config.P_rbr_lca).transpose() * triad(config.ax2_jcr_strut_lca, triad(config.ax1_jcr_strut_lca).block(0,1, 3,1))) ;
    ubar_rbr_lower_strut_jcr_strut_lca << ((A(config.P_rbr_lower_strut).transpose() * config.pt1_jcr_strut_lca) + (-1 * A(config.P_rbr_lower_strut).transpose() * config.R_rbr_lower_strut)) ;
    ubar_rbr_lca_jcr_strut_lca << ((A(config.P_rbr_lca).transpose() * config.pt1_jcr_strut_lca) + (-1 * A(config.P_rbr_lca).transpose() * config.R_rbr_lca)) ;
    Mbar_rbl_lower_strut_jcl_strut_lca << (A(config.P_rbl_lower_strut).transpose() * triad(config.ax1_jcl_strut_lca)) ;
    Mbar_rbl_lca_jcl_strut_lca << (A(config.P_rbl_lca).transpose() * triad(config.ax2_jcl_strut_lca, triad(config.ax1_jcl_strut_lca).block(0,1, 3,1))) ;
    ubar_rbl_lower_strut_jcl_strut_lca << ((A(config.P_rbl_lower_strut).transpose() * config.pt1_jcl_strut_lca) + (-1 * A(config.P_rbl_lower_strut).transpose() * config.R_rbl_lower_strut)) ;
    ubar_rbl_lca_jcl_strut_lca << ((A(config.P_rbl_lca).transpose() * config.pt1_jcl_strut_lca) + (-1 * A(config.P_rbl_lca).transpose() * config.R_rbl_lca)) ;
    Mbar_rbr_tie_rod_jcr_tie_steering << (A(config.P_rbr_tie_rod).transpose() * triad(config.ax1_jcr_tie_steering)) ;
    Mbar_ground_jcr_tie_steering << (A(P_ground).transpose() * triad(config.ax2_jcr_tie_steering, triad(config.ax1_jcr_tie_steering).block(0,1, 3,1))) ;
    ubar_rbr_tie_rod_jcr_tie_steering << ((A(config.P_rbr_tie_rod).transpose() * config.pt1_jcr_tie_steering) + (-1 * A(config.P_rbr_tie_rod).transpose() * config.R_rbr_tie_rod)) ;
    ubar_ground_jcr_tie_steering << ((A(P_ground).transpose() * config.pt1_jcr_tie_steering) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbr_tie_rod_jcr_tie_upright << (A(config.P_rbr_tie_rod).transpose() * triad(config.ax1_jcr_tie_upright)) ;
    Mbar_rbr_upright_jcr_tie_upright << (A(config.P_rbr_upright).transpose() * triad(config.ax1_jcr_tie_upright)) ;
    ubar_rbr_tie_rod_jcr_tie_upright << ((A(config.P_rbr_tie_rod).transpose() * config.pt1_jcr_tie_upright) + (-1 * A(config.P_rbr_tie_rod).transpose() * config.R_rbr_tie_rod)) ;
    ubar_rbr_upright_jcr_tie_upright << ((A(config.P_rbr_upright).transpose() * config.pt1_jcr_tie_upright) + (-1 * A(config.P_rbr_upright).transpose() * config.R_rbr_upright)) ;
    Mbar_rbl_tie_rod_jcl_tie_steering << (A(config.P_rbl_tie_rod).transpose() * triad(config.ax1_jcl_tie_steering)) ;
    Mbar_ground_jcl_tie_steering << (A(P_ground).transpose() * triad(config.ax2_jcl_tie_steering, triad(config.ax1_jcl_tie_steering).block(0,1, 3,1))) ;
    ubar_rbl_tie_rod_jcl_tie_steering << ((A(config.P_rbl_tie_rod).transpose() * config.pt1_jcl_tie_steering) + (-1 * A(config.P_rbl_tie_rod).transpose() * config.R_rbl_tie_rod)) ;
    ubar_ground_jcl_tie_steering << ((A(P_ground).transpose() * config.pt1_jcl_tie_steering) + (-1 * A(P_ground).transpose() * R_ground)) ;
    Mbar_rbl_tie_rod_jcl_tie_upright << (A(config.P_rbl_tie_rod).transpose() * triad(config.ax1_jcl_tie_upright)) ;
    Mbar_rbl_upright_jcl_tie_upright << (A(config.P_rbl_upright).transpose() * triad(config.ax1_jcl_tie_upright)) ;
    ubar_rbl_tie_rod_jcl_tie_upright << ((A(config.P_rbl_tie_rod).transpose() * config.pt1_jcl_tie_upright) + (-1 * A(config.P_rbl_tie_rod).transpose() * config.R_rbl_tie_rod)) ;
    ubar_rbl_upright_jcl_tie_upright << ((A(config.P_rbl_upright).transpose() * config.pt1_jcl_tie_upright) + (-1 * A(config.P_rbl_upright).transpose() * config.R_rbl_upright)) ;
    ubar_rbr_hub_mcr_wheel_travel << ((A(config.P_rbr_hub).transpose() * config.pt1_mcr_wheel_travel) + (-1 * A(config.P_rbr_hub).transpose() * config.R_rbr_hub)) ;
    ubar_ground_mcr_wheel_travel << ((A(P_ground).transpose() * config.pt2_mcr_wheel_travel) + (-1 * A(P_ground).transpose() * R_ground)) ;
    ubar_rbr_hub_far_tire << ((A(config.P_rbr_hub).transpose() * config.pt1_far_tire) + (-1 * A(config.P_rbr_hub).transpose() * config.R_rbr_hub)) ;
    ubar_ground_far_tire << ((A(P_ground).transpose() * config.pt1_far_tire) + (-1 * A(P_ground).transpose() * R_ground)) ;
    ubar_rbl_hub_mcl_wheel_travel << ((A(config.P_rbl_hub).transpose() * config.pt1_mcl_wheel_travel) + (-1 * A(config.P_rbl_hub).transpose() * config.R_rbl_hub)) ;
    ubar_ground_mcl_wheel_travel << ((A(P_ground).transpose() * config.pt2_mcl_wheel_travel) + (-1 * A(P_ground).transpose() * R_ground)) ;
    ubar_rbl_hub_fal_tire << ((A(config.P_rbl_hub).transpose() * config.pt1_fal_tire) + (-1 * A(config.P_rbl_hub).transpose() * config.R_rbl_hub)) ;
    ubar_ground_fal_tire << ((A(P_ground).transpose() * config.pt1_fal_tire) + (-1 * A(P_ground).transpose() * R_ground)) ;
};

void Topology::eval_pos_eq()
{
    auto&& x0 = coord.R_rbr_uca ;
    auto&& x1 = coord.R_ground ;
    auto&& x2 = (-1 * x1) ;
    auto&& x3 = coord.P_rbr_uca ;
    auto&& x4 = A(x3) ;
    auto&& x5 = coord.P_ground ;
    auto&& x6 = A(x5) ;
    auto&& x7 = x4.transpose() ;
    auto&& x8 = Mbar_ground_jcr_uca_chassis.col(2) ;
    auto&& x9 = coord.R_rbr_upright ;
    auto&& x10 = (-1 * x9) ;
    auto&& x11 = coord.P_rbr_upright ;
    auto&& x12 = A(x11) ;
    auto&& x13 = coord.R_rbl_uca ;
    auto&& x14 = coord.P_rbl_uca ;
    auto&& x15 = A(x14) ;
    auto&& x16 = x15.transpose() ;
    auto&& x17 = Mbar_ground_jcl_uca_chassis.col(2) ;
    auto&& x18 = coord.R_rbl_upright ;
    auto&& x19 = (-1 * x18) ;
    auto&& x20 = coord.P_rbl_upright ;
    auto&& x21 = A(x20) ;
    auto&& x22 = coord.R_rbr_lca ;
    auto&& x23 = coord.P_rbr_lca ;
    auto&& x24 = A(x23) ;
    auto&& x25 = x24.transpose() ;
    auto&& x26 = Mbar_ground_jcr_lca_chassis.col(2) ;
    auto&& x27 = coord.R_rbl_lca ;
    auto&& x28 = coord.P_rbl_lca ;
    auto&& x29 = A(x28) ;
    auto&& x30 = x29.transpose() ;
    auto&& x31 = Mbar_ground_jcl_lca_chassis.col(2) ;
    auto&& x32 = coord.R_rbr_hub ;
    auto&& x33 = coord.P_rbr_hub ;
    auto&& x34 = A(x33) ;
    auto&& x35 = x12.transpose() ;
    auto&& x36 = Mbar_rbr_hub_jcr_hub_bearing.col(2) ;
    auto&& x37 = Mbar_rbr_hub_jcr_hub_bearing.col(0) ;
    auto&& x38 = coord.R_rbl_hub ;
    auto&& x39 = coord.P_rbl_hub ;
    auto&& x40 = A(x39) ;
    auto&& x41 = x21.transpose() ;
    auto&& x42 = Mbar_rbl_hub_jcl_hub_bearing.col(2) ;
    auto&& x43 = Mbar_rbl_hub_jcl_hub_bearing.col(0) ;
    auto&& x44 = coord.R_rbr_upper_strut ;
    auto&& x45 = coord.P_rbr_upper_strut ;
    auto&& x46 = A(x45) ;
    auto&& x47 = x46.transpose() ;
    auto&& x48 = Mbar_rbr_upper_strut_jcr_strut.col(0).transpose() ;
    auto&& x49 = coord.P_rbr_lower_strut ;
    auto&& x50 = A(x49) ;
    auto&& x51 = Mbar_rbr_lower_strut_jcr_strut.col(2) ;
    auto&& x52 = Mbar_rbr_upper_strut_jcr_strut.col(1).transpose() ;
    auto&& x53 = coord.R_rbr_lower_strut ;
    auto&& x54 = (x44 + (-1 * x53) + (x46 * ubar_rbr_upper_strut_jcr_strut) + (-1 * x50 * ubar_rbr_lower_strut_jcr_strut)) ;
    auto&& x55 = coord.R_rbl_upper_strut ;
    auto&& x56 = coord.P_rbl_upper_strut ;
    auto&& x57 = A(x56) ;
    auto&& x58 = x57.transpose() ;
    auto&& x59 = Mbar_rbl_upper_strut_jcl_strut.col(0).transpose() ;
    auto&& x60 = coord.P_rbl_lower_strut ;
    auto&& x61 = A(x60) ;
    auto&& x62 = Mbar_rbl_lower_strut_jcl_strut.col(2) ;
    auto&& x63 = Mbar_rbl_upper_strut_jcl_strut.col(1).transpose() ;
    auto&& x64 = coord.R_rbl_lower_strut ;
    auto&& x65 = (x55 + (-1 * x64) + (x57 * ubar_rbl_upper_strut_jcl_strut) + (-1 * x61 * ubar_rbl_lower_strut_jcl_strut)) ;
    auto&& x66 = coord.R_rbr_tie_rod ;
    auto&& x67 = coord.P_rbr_tie_rod ;
    auto&& x68 = A(x67) ;
    auto&& x69 = coord.R_rbl_tie_rod ;
    auto&& x70 = coord.P_rbl_tie_rod ;
    auto&& x71 = A(x70) ;
    auto&& x72 = Eigen::MatrixXd::Identity(1, 1) ;
    auto&& x73 = (x72) ;
    auto&& x74 = (-1 * x72) ;

    pos_eq << 
        (x0 + x2 + (x4 * ubar_rbr_uca_jcr_uca_chassis) + (-1 * x6 * ubar_ground_jcr_uca_chassis)),
        (Mbar_rbr_uca_jcr_uca_chassis.col(0).transpose() * x7 * x6 * x8),
        (Mbar_rbr_uca_jcr_uca_chassis.col(1).transpose() * x7 * x6 * x8),
        (x0 + x10 + (x4 * ubar_rbr_uca_jcr_uca_upright) + (-1 * x12 * ubar_rbr_upright_jcr_uca_upright)),
        (x13 + x2 + (x15 * ubar_rbl_uca_jcl_uca_chassis) + (-1 * x6 * ubar_ground_jcl_uca_chassis)),
        (Mbar_rbl_uca_jcl_uca_chassis.col(0).transpose() * x16 * x6 * x17),
        (Mbar_rbl_uca_jcl_uca_chassis.col(1).transpose() * x16 * x6 * x17),
        (x13 + x19 + (x15 * ubar_rbl_uca_jcl_uca_upright) + (-1 * x21 * ubar_rbl_upright_jcl_uca_upright)),
        (x22 + x2 + (x24 * ubar_rbr_lca_jcr_lca_chassis) + (-1 * x6 * ubar_ground_jcr_lca_chassis)),
        (Mbar_rbr_lca_jcr_lca_chassis.col(0).transpose() * x25 * x6 * x26),
        (Mbar_rbr_lca_jcr_lca_chassis.col(1).transpose() * x25 * x6 * x26),
        (x22 + x10 + (x24 * ubar_rbr_lca_jcr_lca_upright) + (-1 * x12 * ubar_rbr_upright_jcr_lca_upright)),
        (x27 + x2 + (x29 * ubar_rbl_lca_jcl_lca_chassis) + (-1 * x6 * ubar_ground_jcl_lca_chassis)),
        (Mbar_rbl_lca_jcl_lca_chassis.col(0).transpose() * x30 * x6 * x31),
        (Mbar_rbl_lca_jcl_lca_chassis.col(1).transpose() * x30 * x6 * x31),
        (x27 + x19 + (x29 * ubar_rbl_lca_jcl_lca_upright) + (-1 * x21 * ubar_rbl_upright_jcl_lca_upright)),
        (x9 + (-1 * x32) + (x12 * ubar_rbr_upright_jcr_hub_bearing) + (-1 * x34 * ubar_rbr_hub_jcr_hub_bearing)),
        (Mbar_rbr_upright_jcr_hub_bearing.col(0).transpose() * x35 * x34 * x36),
        (Mbar_rbr_upright_jcr_hub_bearing.col(1).transpose() * x35 * x34 * x36),
        ((std::cos(config.UF_mcr_wheel_lock(t)) * (Mbar_rbr_upright_jcr_hub_bearing.col(1).transpose() * x35 * x34 * x37)) + ((-1 * std::sin(config.UF_mcr_wheel_lock(t))) * Mbar_rbr_upright_jcr_hub_bearing.col(0).transpose() * x35 * x34 * x37)),
        (x18 + (-1 * x38) + (x21 * ubar_rbl_upright_jcl_hub_bearing) + (-1 * x40 * ubar_rbl_hub_jcl_hub_bearing)),
        (Mbar_rbl_upright_jcl_hub_bearing.col(0).transpose() * x41 * x40 * x42),
        (Mbar_rbl_upright_jcl_hub_bearing.col(1).transpose() * x41 * x40 * x42),
        ((std::cos(config.UF_mcl_wheel_lock(t)) * (Mbar_rbl_upright_jcl_hub_bearing.col(1).transpose() * x41 * x40 * x43)) + ((-1 * std::sin(config.UF_mcl_wheel_lock(t))) * Mbar_rbl_upright_jcl_hub_bearing.col(0).transpose() * x41 * x40 * x43)),
        (x44 + x2 + (x46 * ubar_rbr_upper_strut_jcr_strut_chassis) + (-1 * x6 * ubar_ground_jcr_strut_chassis)),
        (Mbar_rbr_upper_strut_jcr_strut_chassis.col(0).transpose() * x47 * x6 * Mbar_ground_jcr_strut_chassis.col(0)),
        (x48 * x47 * x50 * x51),
        (x52 * x47 * x50 * x51),
        (x48 * x47 * x54),
        (x52 * x47 * x54),
        (x55 + x2 + (x57 * ubar_rbl_upper_strut_jcl_strut_chassis) + (-1 * x6 * ubar_ground_jcl_strut_chassis)),
        (Mbar_rbl_upper_strut_jcl_strut_chassis.col(0).transpose() * x58 * x6 * Mbar_ground_jcl_strut_chassis.col(0)),
        (x59 * x58 * x61 * x62),
        (x63 * x58 * x61 * x62),
        (x59 * x58 * x65),
        (x63 * x58 * x65),
        (x53 + (-1 * x22) + (x50 * ubar_rbr_lower_strut_jcr_strut_lca) + (-1 * x24 * ubar_rbr_lca_jcr_strut_lca)),
        (Mbar_rbr_lower_strut_jcr_strut_lca.col(0).transpose() * x50.transpose() * x24 * Mbar_rbr_lca_jcr_strut_lca.col(0)),
        (x64 + (-1 * x27) + (x61 * ubar_rbl_lower_strut_jcl_strut_lca) + (-1 * x29 * ubar_rbl_lca_jcl_strut_lca)),
        (Mbar_rbl_lower_strut_jcl_strut_lca.col(0).transpose() * x61.transpose() * x29 * Mbar_rbl_lca_jcl_strut_lca.col(0)),
        (x66 + x2 + (x68 * ubar_rbr_tie_rod_jcr_tie_steering) + (-1 * x6 * ubar_ground_jcr_tie_steering)),
        (Mbar_rbr_tie_rod_jcr_tie_steering.col(0).transpose() * x68.transpose() * x6 * Mbar_ground_jcr_tie_steering.col(0)),
        (x66 + x10 + (x68 * ubar_rbr_tie_rod_jcr_tie_upright) + (-1 * x12 * ubar_rbr_upright_jcr_tie_upright)),
        (x69 + x2 + (x71 * ubar_rbl_tie_rod_jcl_tie_steering) + (-1 * x6 * ubar_ground_jcl_tie_steering)),
        (Mbar_rbl_tie_rod_jcl_tie_steering.col(0).transpose() * x71.transpose() * x6 * Mbar_ground_jcl_tie_steering.col(0)),
        (x69 + x19 + (x71 * ubar_rbl_tie_rod_jcl_tie_upright) + (-1 * x21 * ubar_rbl_upright_jcl_tie_upright)),
        (((-1 * config.UF_mcr_wheel_travel(t)) * x73) + (x32 + (x34 * ubar_rbr_hub_mcr_wheel_travel)).segment(2, 1) + (-1 * (x1 + (x6 * ubar_ground_mcr_wheel_travel)).segment(2, 1))),
        (((-1 * config.UF_mcl_wheel_travel(t)) * x73) + (x38 + (x40 * ubar_rbl_hub_mcl_wheel_travel)).segment(2, 1) + (-1 * (x1 + (x6 * ubar_ground_mcl_wheel_travel)).segment(2, 1))),
        x1,
        (x5 + (-1 * Pg_ground)),
        (x74 + (x3.transpose() * x3)),
        (x74 + (x14.transpose() * x14)),
        (x74 + (x23.transpose() * x23)),
        (x74 + (x28.transpose() * x28)),
        (x74 + (x11.transpose() * x11)),
        (x74 + (x20.transpose() * x20)),
        (x74 + (x45.transpose() * x45)),
        (x74 + (x56.transpose() * x56)),
        (x74 + (x49.transpose() * x49)),
        (x74 + (x60.transpose() * x60)),
        (x74 + (x67.transpose() * x67)),
        (x74 + (x70.transpose() * x70)),
        (x74 + (x33.transpose() * x33)),
        (x74 + (x39.transpose() * x39));
};

void Topology::eval_vel_eq()
{
    auto&& v0 = Eigen::MatrixXd::Zero(3, 1) ;
    auto&& v1 = Eigen::MatrixXd::Zero(1, 1) ;
    auto&& v2 = (Eigen::MatrixXd::Identity(1, 1)) ;

    vel_eq << 
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
        (v1 + ((-1 * derivative(config.UF_mcr_wheel_lock, t, 1)) * v2)),
        v0,
        v1,
        v1,
        (v1 + ((-1 * derivative(config.UF_mcl_wheel_lock, t, 1)) * v2)),
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
        (v1 + ((-1 * derivative(config.UF_mcr_wheel_travel, t, 1)) * v2)),
        (v1 + ((-1 * derivative(config.UF_mcl_wheel_travel, t, 1)) * v2)),
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
    auto&& a0 = coord.Pd_rbr_uca ;
    auto&& a1 = coord.Pd_ground ;
    auto&& a2 = Mbar_ground_jcr_uca_chassis.col(2) ;
    auto&& a3 = a2.transpose() ;
    auto&& a4 = coord.P_ground ;
    auto&& a5 = A(a4).transpose() ;
    auto&& a6 = Mbar_rbr_uca_jcr_uca_chassis.col(0) ;
    auto&& a7 = coord.P_rbr_uca ;
    auto&& a8 = A(a7).transpose() ;
    auto&& a9 = B(a1, a2) ;
    auto&& a10 = a0.transpose() ;
    auto&& a11 = B(a4, a2) ;
    auto&& a12 = Mbar_rbr_uca_jcr_uca_chassis.col(1) ;
    auto&& a13 = coord.Pd_rbr_upright ;
    auto&& a14 = coord.Pd_rbl_uca ;
    auto&& a15 = Mbar_rbl_uca_jcl_uca_chassis.col(0) ;
    auto&& a16 = coord.P_rbl_uca ;
    auto&& a17 = A(a16).transpose() ;
    auto&& a18 = Mbar_ground_jcl_uca_chassis.col(2) ;
    auto&& a19 = B(a1, a18) ;
    auto&& a20 = a18.transpose() ;
    auto&& a21 = a14.transpose() ;
    auto&& a22 = B(a4, a18) ;
    auto&& a23 = Mbar_rbl_uca_jcl_uca_chassis.col(1) ;
    auto&& a24 = coord.Pd_rbl_upright ;
    auto&& a25 = coord.Pd_rbr_lca ;
    auto&& a26 = Mbar_rbr_lca_jcr_lca_chassis.col(0) ;
    auto&& a27 = coord.P_rbr_lca ;
    auto&& a28 = A(a27).transpose() ;
    auto&& a29 = Mbar_ground_jcr_lca_chassis.col(2) ;
    auto&& a30 = B(a1, a29) ;
    auto&& a31 = a29.transpose() ;
    auto&& a32 = a25.transpose() ;
    auto&& a33 = B(a4, a29) ;
    auto&& a34 = Mbar_rbr_lca_jcr_lca_chassis.col(1) ;
    auto&& a35 = coord.Pd_rbl_lca ;
    auto&& a36 = Mbar_rbl_lca_jcl_lca_chassis.col(0) ;
    auto&& a37 = coord.P_rbl_lca ;
    auto&& a38 = A(a37).transpose() ;
    auto&& a39 = Mbar_ground_jcl_lca_chassis.col(2) ;
    auto&& a40 = B(a1, a39) ;
    auto&& a41 = a39.transpose() ;
    auto&& a42 = a35.transpose() ;
    auto&& a43 = B(a4, a39) ;
    auto&& a44 = Mbar_rbl_lca_jcl_lca_chassis.col(1) ;
    auto&& a45 = coord.Pd_rbr_hub ;
    auto&& a46 = Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    auto&& a47 = coord.P_rbr_upright ;
    auto&& a48 = A(a47).transpose() ;
    auto&& a49 = Mbar_rbr_hub_jcr_hub_bearing.col(2) ;
    auto&& a50 = B(a45, a49) ;
    auto&& a51 = a49.transpose() ;
    auto&& a52 = coord.P_rbr_hub ;
    auto&& a53 = A(a52).transpose() ;
    auto&& a54 = a13.transpose() ;
    auto&& a55 = B(a52, a49) ;
    auto&& a56 = Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    auto&& a57 = (Eigen::MatrixXd::Identity(1, 1)) ;
    auto&& a58 = Mbar_rbr_hub_jcr_hub_bearing.col(0) ;
    auto&& a59 = Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    auto&& a60 = Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    auto&& a61 = coord.Pd_rbl_hub ;
    auto&& a62 = Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    auto&& a63 = coord.P_rbl_upright ;
    auto&& a64 = A(a63).transpose() ;
    auto&& a65 = Mbar_rbl_hub_jcl_hub_bearing.col(2) ;
    auto&& a66 = B(a61, a65) ;
    auto&& a67 = a65.transpose() ;
    auto&& a68 = coord.P_rbl_hub ;
    auto&& a69 = A(a68).transpose() ;
    auto&& a70 = a24.transpose() ;
    auto&& a71 = B(a68, a65) ;
    auto&& a72 = Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    auto&& a73 = Mbar_rbl_hub_jcl_hub_bearing.col(0) ;
    auto&& a74 = Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    auto&& a75 = Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    auto&& a76 = coord.Pd_rbr_upper_strut ;
    auto&& a77 = Mbar_ground_jcr_strut_chassis.col(0) ;
    auto&& a78 = Mbar_rbr_upper_strut_jcr_strut_chassis.col(0) ;
    auto&& a79 = coord.P_rbr_upper_strut ;
    auto&& a80 = A(a79).transpose() ;
    auto&& a81 = a76.transpose() ;
    auto&& a82 = Mbar_rbr_upper_strut_jcr_strut.col(0) ;
    auto&& a83 = a82.transpose() ;
    auto&& a84 = coord.Pd_rbr_lower_strut ;
    auto&& a85 = Mbar_rbr_lower_strut_jcr_strut.col(2) ;
    auto&& a86 = B(a84, a85) ;
    auto&& a87 = a85.transpose() ;
    auto&& a88 = coord.P_rbr_lower_strut ;
    auto&& a89 = A(a88).transpose() ;
    auto&& a90 = B(a76, a82) ;
    auto&& a91 = B(a79, a82).transpose() ;
    auto&& a92 = B(a88, a85) ;
    auto&& a93 = Mbar_rbr_upper_strut_jcr_strut.col(1) ;
    auto&& a94 = a93.transpose() ;
    auto&& a95 = B(a76, a93) ;
    auto&& a96 = B(a79, a93).transpose() ;
    auto&& a97 = ubar_rbr_upper_strut_jcr_strut ;
    auto&& a98 = ubar_rbr_lower_strut_jcr_strut ;
    auto&& a99 = ((B(a76, a97) * a76) + (-1 * B(a84, a98) * a84)) ;
    auto&& a100 = (coord.Rd_rbr_upper_strut + (-1 * coord.Rd_rbr_lower_strut) + (B(a79, a97) * a76) + (-1 * B(a88, a98) * a84)) ;
    auto&& a101 = (coord.R_rbr_upper_strut.transpose() + (-1 * coord.R_rbr_lower_strut.transpose()) + (a97.transpose() * a80) + (-1 * a98.transpose() * a89)) ;
    auto&& a102 = coord.Pd_rbl_upper_strut ;
    auto&& a103 = Mbar_ground_jcl_strut_chassis.col(0) ;
    auto&& a104 = Mbar_rbl_upper_strut_jcl_strut_chassis.col(0) ;
    auto&& a105 = coord.P_rbl_upper_strut ;
    auto&& a106 = A(a105).transpose() ;
    auto&& a107 = a102.transpose() ;
    auto&& a108 = Mbar_rbl_upper_strut_jcl_strut.col(0) ;
    auto&& a109 = a108.transpose() ;
    auto&& a110 = coord.Pd_rbl_lower_strut ;
    auto&& a111 = Mbar_rbl_lower_strut_jcl_strut.col(2) ;
    auto&& a112 = B(a110, a111) ;
    auto&& a113 = a111.transpose() ;
    auto&& a114 = coord.P_rbl_lower_strut ;
    auto&& a115 = A(a114).transpose() ;
    auto&& a116 = B(a102, a108) ;
    auto&& a117 = B(a105, a108).transpose() ;
    auto&& a118 = B(a114, a111) ;
    auto&& a119 = Mbar_rbl_upper_strut_jcl_strut.col(1) ;
    auto&& a120 = a119.transpose() ;
    auto&& a121 = B(a102, a119) ;
    auto&& a122 = B(a105, a119).transpose() ;
    auto&& a123 = ubar_rbl_upper_strut_jcl_strut ;
    auto&& a124 = ubar_rbl_lower_strut_jcl_strut ;
    auto&& a125 = ((B(a102, a123) * a102) + (-1 * B(a110, a124) * a110)) ;
    auto&& a126 = (coord.Rd_rbl_upper_strut + (-1 * coord.Rd_rbl_lower_strut) + (B(a105, a123) * a102) + (-1 * B(a114, a124) * a110)) ;
    auto&& a127 = (coord.R_rbl_upper_strut.transpose() + (-1 * coord.R_rbl_lower_strut.transpose()) + (a123.transpose() * a106) + (-1 * a124.transpose() * a115)) ;
    auto&& a128 = Mbar_rbr_lower_strut_jcr_strut_lca.col(0) ;
    auto&& a129 = Mbar_rbr_lca_jcr_strut_lca.col(0) ;
    auto&& a130 = a84.transpose() ;
    auto&& a131 = Mbar_rbl_lower_strut_jcl_strut_lca.col(0) ;
    auto&& a132 = Mbar_rbl_lca_jcl_strut_lca.col(0) ;
    auto&& a133 = a110.transpose() ;
    auto&& a134 = coord.Pd_rbr_tie_rod ;
    auto&& a135 = Mbar_ground_jcr_tie_steering.col(0) ;
    auto&& a136 = Mbar_rbr_tie_rod_jcr_tie_steering.col(0) ;
    auto&& a137 = coord.P_rbr_tie_rod ;
    auto&& a138 = a134.transpose() ;
    auto&& a139 = coord.Pd_rbl_tie_rod ;
    auto&& a140 = Mbar_rbl_tie_rod_jcl_tie_steering.col(0) ;
    auto&& a141 = coord.P_rbl_tie_rod ;
    auto&& a142 = Mbar_ground_jcl_tie_steering.col(0) ;
    auto&& a143 = a139.transpose() ;

    acc_eq << 
        ((B(a0, ubar_rbr_uca_jcr_uca_chassis) * a0) + (-1 * B(a1, ubar_ground_jcr_uca_chassis) * a1)),
        ((a3 * a5 * B(a0, a6) * a0) + (a6.transpose() * a8 * a9 * a1) + (2 * (a10 * B(a7, a6).transpose() * a11 * a1))),
        ((a3 * a5 * B(a0, a12) * a0) + (a12.transpose() * a8 * a9 * a1) + (2 * (a10 * B(a7, a12).transpose() * a11 * a1))),
        ((B(a0, ubar_rbr_uca_jcr_uca_upright) * a0) + (-1 * B(a13, ubar_rbr_upright_jcr_uca_upright) * a13)),
        ((B(a14, ubar_rbl_uca_jcl_uca_chassis) * a14) + (-1 * B(a1, ubar_ground_jcl_uca_chassis) * a1)),
        ((a15.transpose() * a17 * a19 * a1) + (a20 * a5 * B(a14, a15) * a14) + (2 * (a21 * B(a16, a15).transpose() * a22 * a1))),
        ((a23.transpose() * a17 * a19 * a1) + (a20 * a5 * B(a14, a23) * a14) + (2 * (a21 * B(a16, a23).transpose() * a22 * a1))),
        ((B(a14, ubar_rbl_uca_jcl_uca_upright) * a14) + (-1 * B(a24, ubar_rbl_upright_jcl_uca_upright) * a24)),
        ((B(a25, ubar_rbr_lca_jcr_lca_chassis) * a25) + (-1 * B(a1, ubar_ground_jcr_lca_chassis) * a1)),
        ((a26.transpose() * a28 * a30 * a1) + (a31 * a5 * B(a25, a26) * a25) + (2 * (a32 * B(a27, a26).transpose() * a33 * a1))),
        ((a34.transpose() * a28 * a30 * a1) + (a31 * a5 * B(a25, a34) * a25) + (2 * (a32 * B(a27, a34).transpose() * a33 * a1))),
        ((B(a25, ubar_rbr_lca_jcr_lca_upright) * a25) + (-1 * B(a13, ubar_rbr_upright_jcr_lca_upright) * a13)),
        ((B(a35, ubar_rbl_lca_jcl_lca_chassis) * a35) + (-1 * B(a1, ubar_ground_jcl_lca_chassis) * a1)),
        ((a36.transpose() * a38 * a40 * a1) + (a41 * a5 * B(a35, a36) * a35) + (2 * (a42 * B(a37, a36).transpose() * a43 * a1))),
        ((a44.transpose() * a38 * a40 * a1) + (a41 * a5 * B(a35, a44) * a35) + (2 * (a42 * B(a37, a44).transpose() * a43 * a1))),
        ((B(a35, ubar_rbl_lca_jcl_lca_upright) * a35) + (-1 * B(a24, ubar_rbl_upright_jcl_lca_upright) * a24)),
        ((B(a13, ubar_rbr_upright_jcr_hub_bearing) * a13) + (-1 * B(a45, ubar_rbr_hub_jcr_hub_bearing) * a45)),
        ((a46.transpose() * a48 * a50 * a45) + (a51 * a53 * B(a13, a46) * a13) + (2 * (a54 * B(a47, a46).transpose() * a55 * a45))),
        ((a56.transpose() * a48 * a50 * a45) + (a51 * a53 * B(a13, a56) * a13) + (2 * (a54 * B(a47, a56).transpose() * a55 * a45))),
        (((-1 * derivative(config.UF_mcr_wheel_lock, t, 2)) * a57) + (a58.transpose() * a53 * ((std::cos(config.UF_mcr_wheel_lock(t)) * (B(a13, a59))) + ((-1 * std::sin(config.UF_mcr_wheel_lock(t))) * B(a13, a60))) * a13) + (((std::cos(config.UF_mcr_wheel_lock(t)) * (a59.transpose() * a48)) + ((-1 * std::sin(config.UF_mcr_wheel_lock(t))) * a60.transpose() * a48)) * B(a45, a58) * a45) + (2 * (((std::cos(config.UF_mcr_wheel_lock(t)) * (a54 * B(a47, a59).transpose())) + ((-1 * std::sin(config.UF_mcr_wheel_lock(t))) * a54 * B(a47, a60).transpose())) * B(a52, a58) * a45))),
        ((B(a24, ubar_rbl_upright_jcl_hub_bearing) * a24) + (-1 * B(a61, ubar_rbl_hub_jcl_hub_bearing) * a61)),
        ((a62.transpose() * a64 * a66 * a61) + (a67 * a69 * B(a24, a62) * a24) + (2 * (a70 * B(a63, a62).transpose() * a71 * a61))),
        ((a72.transpose() * a64 * a66 * a61) + (a67 * a69 * B(a24, a72) * a24) + (2 * (a70 * B(a63, a72).transpose() * a71 * a61))),
        (((-1 * derivative(config.UF_mcl_wheel_lock, t, 2)) * a57) + (a73.transpose() * a69 * ((std::cos(config.UF_mcl_wheel_lock(t)) * (B(a24, a74))) + ((-1 * std::sin(config.UF_mcl_wheel_lock(t))) * B(a24, a75))) * a24) + (((std::cos(config.UF_mcl_wheel_lock(t)) * (a74.transpose() * a64)) + ((-1 * std::sin(config.UF_mcl_wheel_lock(t))) * a75.transpose() * a64)) * B(a61, a73) * a61) + (2 * (((std::cos(config.UF_mcl_wheel_lock(t)) * (a70 * B(a63, a74).transpose())) + ((-1 * std::sin(config.UF_mcl_wheel_lock(t))) * a70 * B(a63, a75).transpose())) * B(a68, a73) * a61))),
        ((B(a76, ubar_rbr_upper_strut_jcr_strut_chassis) * a76) + (-1 * B(a1, ubar_ground_jcr_strut_chassis) * a1)),
        ((a77.transpose() * a5 * B(a76, a78) * a76) + (a78.transpose() * a80 * B(a1, a77) * a1) + (2 * (a81 * B(a79, a78).transpose() * B(a4, a77) * a1))),
        ((a83 * a80 * a86 * a84) + (a87 * a89 * a90 * a76) + (2 * (a81 * a91 * a92 * a84))),
        ((a94 * a80 * a86 * a84) + (a87 * a89 * a95 * a76) + (2 * (a81 * a96 * a92 * a84))),
        ((a83 * a80 * a99) + (2 * (a81 * a91 * a100)) + (a101 * a90 * a76)),
        ((a94 * a80 * a99) + (2 * (a81 * a96 * a100)) + (a101 * a95 * a76)),
        ((B(a102, ubar_rbl_upper_strut_jcl_strut_chassis) * a102) + (-1 * B(a1, ubar_ground_jcl_strut_chassis) * a1)),
        ((a103.transpose() * a5 * B(a102, a104) * a102) + (a104.transpose() * a106 * B(a1, a103) * a1) + (2 * (a107 * B(a105, a104).transpose() * B(a4, a103) * a1))),
        ((a109 * a106 * a112 * a110) + (a113 * a115 * a116 * a102) + (2 * (a107 * a117 * a118 * a110))),
        ((a120 * a106 * a112 * a110) + (a113 * a115 * a121 * a102) + (2 * (a107 * a122 * a118 * a110))),
        ((a109 * a106 * a125) + (2 * (a107 * a117 * a126)) + (a127 * a116 * a102)),
        ((a120 * a106 * a125) + (2 * (a107 * a122 * a126)) + (a127 * a121 * a102)),
        ((B(a84, ubar_rbr_lower_strut_jcr_strut_lca) * a84) + (-1 * B(a25, ubar_rbr_lca_jcr_strut_lca) * a25)),
        ((a128.transpose() * a89 * B(a25, a129) * a25) + (a129.transpose() * a28 * B(a84, a128) * a84) + (2 * (a130 * B(a88, a128).transpose() * B(a27, a129) * a25))),
        ((B(a110, ubar_rbl_lower_strut_jcl_strut_lca) * a110) + (-1 * B(a35, ubar_rbl_lca_jcl_strut_lca) * a35)),
        ((a131.transpose() * a115 * B(a35, a132) * a35) + (a132.transpose() * a38 * B(a110, a131) * a110) + (2 * (a133 * B(a114, a131).transpose() * B(a37, a132) * a35))),
        ((B(a134, ubar_rbr_tie_rod_jcr_tie_steering) * a134) + (-1 * B(a1, ubar_ground_jcr_tie_steering) * a1)),
        ((a135.transpose() * a5 * B(a134, a136) * a134) + (a136.transpose() * A(a137).transpose() * B(a1, a135) * a1) + (2 * (a138 * B(a137, a136).transpose() * B(a4, a135) * a1))),
        ((B(a134, ubar_rbr_tie_rod_jcr_tie_upright) * a134) + (-1 * B(a13, ubar_rbr_upright_jcr_tie_upright) * a13)),
        ((B(a139, ubar_rbl_tie_rod_jcl_tie_steering) * a139) + (-1 * B(a1, ubar_ground_jcl_tie_steering) * a1)),
        ((a140.transpose() * A(a141).transpose() * B(a1, a142) * a1) + (a142.transpose() * a5 * B(a139, a140) * a139) + (2 * (a143 * B(a141, a140).transpose() * B(a4, a142) * a1))),
        ((B(a139, ubar_rbl_tie_rod_jcl_tie_upright) * a139) + (-1 * B(a24, ubar_rbl_upright_jcl_tie_upright) * a24)),
        (((-1 * derivative(config.UF_mcr_wheel_travel, t, 2)) * a57) + ((B(a45, ubar_rbr_hub_mcr_wheel_travel) * a45) + (-1 * B(a1, ubar_ground_mcr_wheel_travel) * a1)).segment(2, 1)),
        (((-1 * derivative(config.UF_mcl_wheel_travel, t, 2)) * a57) + ((B(a61, ubar_rbl_hub_mcl_wheel_travel) * a61) + (-1 * B(a1, ubar_ground_mcl_wheel_travel) * a1)).segment(2, 1)),
        Eigen::MatrixXd::Zero(3, 1),
        Eigen::MatrixXd::Zero(4, 1),
        (2 * (a10 * a0)),
        (2 * (a21 * a14)),
        (2 * (a32 * a25)),
        (2 * (a42 * a35)),
        (2 * (a54 * a13)),
        (2 * (a70 * a24)),
        (2 * (a81 * a76)),
        (2 * (a107 * a102)),
        (2 * (a130 * a84)),
        (2 * (a133 * a110)),
        (2 * (a138 * a134)),
        (2 * (a143 * a139)),
        (2 * (a45.transpose() * a45)),
        (2 * (a61.transpose() * a61));
};

void Topology::eval_frc_eq()
{
    auto&& f0 = Eigen::MatrixXd::Zero(3, 1) ;
    auto&& f1 = Eigen::MatrixXd::Zero(4, 1) ;
    auto&& f2 = G(coord.Pd_rbr_uca) ;
    auto&& f3 = G(coord.Pd_rbl_uca) ;
    auto&& f4 = G(coord.Pd_rbr_lca) ;
    auto&& f5 = G(coord.Pd_rbl_lca) ;
    auto&& f6 = G(coord.Pd_rbr_upright) ;
    auto&& f7 = G(coord.Pd_rbl_upright) ;
    auto&& f8 = coord.R_rbr_upper_strut ;
    auto&& f9 = coord.R_rbr_lower_strut ;
    auto&& f10 = ubar_rbr_upper_strut_far_strut ;
    auto&& f11 = coord.P_rbr_upper_strut ;
    auto&& f12 = A(f11) ;
    auto&& f13 = ubar_rbr_lower_strut_far_strut ;
    auto&& f14 = coord.P_rbr_lower_strut ;
    auto&& f15 = A(f14) ;
    auto&& f16 = (f8.transpose() + (-1 * f9.transpose()) + (f10.transpose() * f12.transpose()) + (-1 * f13.transpose() * f15.transpose())) ;
    auto&& f17 = (f12 * f10) ;
    auto&& f18 = (f15 * f13) ;
    auto&& f19 = (f8 + (-1 * f9) + f17 + (-1 * f18)) ;
    auto&& f20 = pow((f16 * f19), 1/2) ;
    auto&& f21 = 1.0/f20 ;
    auto&& f22 = config.UF_far_strut_Fs((config.far_strut_FL + (-1 * f20))) ;
    auto&& f23 = coord.Pd_rbr_upper_strut ;
    auto&& f24 = coord.Pd_rbr_lower_strut ;
    auto&& f25 = config.UF_far_strut_Fd(((-1 * 1.0/f20) * f16 * (coord.Rd_rbr_upper_strut + (-1 * coord.Rd_rbr_lower_strut) + (B(f11, f10) * f23) + (-1 * B(f14, f13) * f24)))) ;
    auto&& f26 = ((f21 * (f22 + f25)) * (f19)) ;
    auto&& f27 = G(f23) ;
    auto&& f28 = (2 * f22) ;
    auto&& f29 = (2 * f25) ;
    auto&& f30 = coord.R_rbl_upper_strut ;
    auto&& f31 = coord.R_rbl_lower_strut ;
    auto&& f32 = ubar_rbl_upper_strut_fal_strut ;
    auto&& f33 = coord.P_rbl_upper_strut ;
    auto&& f34 = A(f33) ;
    auto&& f35 = ubar_rbl_lower_strut_fal_strut ;
    auto&& f36 = coord.P_rbl_lower_strut ;
    auto&& f37 = A(f36) ;
    auto&& f38 = (f30.transpose() + (-1 * f31.transpose()) + (f32.transpose() * f34.transpose()) + (-1 * f35.transpose() * f37.transpose())) ;
    auto&& f39 = (f34 * f32) ;
    auto&& f40 = (f37 * f35) ;
    auto&& f41 = (f30 + (-1 * f31) + f39 + (-1 * f40)) ;
    auto&& f42 = pow((f38 * f41), 1/2) ;
    auto&& f43 = 1.0/f42 ;
    auto&& f44 = config.UF_fal_strut_Fs((config.fal_strut_FL + (-1 * f42))) ;
    auto&& f45 = coord.Pd_rbl_upper_strut ;
    auto&& f46 = coord.Pd_rbl_lower_strut ;
    auto&& f47 = config.UF_fal_strut_Fd(((-1 * 1.0/f42) * f38 * (coord.Rd_rbl_upper_strut + (-1 * coord.Rd_rbl_lower_strut) + (B(f33, f32) * f45) + (-1 * B(f36, f35) * f46)))) ;
    auto&& f48 = ((f43 * (f44 + f47)) * (f41)) ;
    auto&& f49 = G(f45) ;
    auto&& f50 = (2 * f44) ;
    auto&& f51 = (2 * f47) ;
    auto&& f52 = G(f24) ;
    auto&& f53 = G(f46) ;
    auto&& f54 = G(coord.Pd_rbr_tie_rod) ;
    auto&& f55 = G(coord.Pd_rbl_tie_rod) ;
    auto&& f56 = t ;
    auto&& f57 = config.UF_far_tire_F(f56) ;
    auto&& f58 = G(coord.Pd_rbr_hub) ;
    auto&& f59 = coord.P_rbr_hub ;
    auto&& f60 = config.UF_fal_tire_F(f56) ;
    auto&& f61 = G(coord.Pd_rbl_hub) ;
    auto&& f62 = coord.P_rbl_hub ;

    frc_eq << 
        f0,
        f1,
        F_rbr_uca_gravity,
        (8 * (f2.transpose() * config.Jbar_rbr_uca * f2 * coord.P_rbr_uca)),
        F_rbl_uca_gravity,
        (8 * (f3.transpose() * config.Jbar_rbl_uca * f3 * coord.P_rbl_uca)),
        F_rbr_lca_gravity,
        (8 * (f4.transpose() * config.Jbar_rbr_lca * f4 * coord.P_rbr_lca)),
        F_rbl_lca_gravity,
        (8 * (f5.transpose() * config.Jbar_rbl_lca * f5 * coord.P_rbl_lca)),
        F_rbr_upright_gravity,
        (8 * (f6.transpose() * config.Jbar_rbr_upright * f6 * coord.P_rbr_upright)),
        F_rbl_upright_gravity,
        (8 * (f7.transpose() * config.Jbar_rbl_upright * f7 * coord.P_rbl_upright)),
        (F_rbr_upper_strut_gravity + f26),
        ((8 * (f27.transpose() * config.Jbar_rbr_upper_strut * f27 * f11)) + ((f21 * ((-1 * f28) + (-1 * f29))) * (E(f11).transpose() * skew(f17).transpose() * f19))),
        (F_rbl_upper_strut_gravity + f48),
        ((8 * (f49.transpose() * config.Jbar_rbl_upper_strut * f49 * f33)) + ((f43 * ((-1 * f50) + (-1 * f51))) * (E(f33).transpose() * skew(f39).transpose() * f41))),
        (F_rbr_lower_strut_gravity + f0 + (-1 * f26)),
        (f1 + (8 * (f52.transpose() * config.Jbar_rbr_lower_strut * f52 * f14)) + ((f21 * (f28 + f29)) * (E(f14).transpose() * skew(f18).transpose() * f19))),
        (F_rbl_lower_strut_gravity + f0 + (-1 * f48)),
        (f1 + (8 * (f53.transpose() * config.Jbar_rbl_lower_strut * f53 * f36)) + ((f43 * (f50 + f51)) * (E(f36).transpose() * skew(f40).transpose() * f41))),
        F_rbr_tie_rod_gravity,
        (8 * (f54.transpose() * config.Jbar_rbr_tie_rod * f54 * coord.P_rbr_tie_rod)),
        F_rbl_tie_rod_gravity,
        (8 * (f55.transpose() * config.Jbar_rbl_tie_rod * f55 * coord.P_rbl_tie_rod)),
        (F_rbr_hub_gravity + f57),
        ((8 * (f58.transpose() * config.Jbar_rbr_hub * f58 * f59)) + (2 * (E(f59).transpose() * (config.UF_far_tire_T(f56) + (skew((A(f59) * ubar_rbr_hub_far_tire)) * f57))))),
        (F_rbl_hub_gravity + f60),
        ((8 * (f61.transpose() * config.Jbar_rbl_hub * f61 * f62)) + (2 * (E(f62).transpose() * (config.UF_fal_tire_T(f56) + (skew((A(f62) * ubar_rbl_hub_fal_tire)) * f60)))));
};

void Topology::eval_jac_eq()
{
    auto&& j0 = Eigen::MatrixXd::Identity(3, 3) ;
    auto&& j1 = coord.P_rbr_uca ;
    auto&& j2 = Eigen::MatrixXd::Zero(1, 3) ;
    auto&& j3 = Mbar_ground_jcr_uca_chassis.col(2) ;
    auto&& j4 = j3.transpose() ;
    auto&& j5 = coord.P_ground ;
    auto&& j6 = A(j5).transpose() ;
    auto&& j7 = Mbar_rbr_uca_jcr_uca_chassis.col(0) ;
    auto&& j8 = Mbar_rbr_uca_jcr_uca_chassis.col(1) ;
    auto&& j9 = (-1 * j0) ;
    auto&& j10 = A(j1).transpose() ;
    auto&& j11 = B(j5, j3) ;
    auto&& j12 = coord.P_rbr_upright ;
    auto&& j13 = coord.P_rbl_uca ;
    auto&& j14 = Mbar_ground_jcl_uca_chassis.col(2) ;
    auto&& j15 = j14.transpose() ;
    auto&& j16 = Mbar_rbl_uca_jcl_uca_chassis.col(0) ;
    auto&& j17 = Mbar_rbl_uca_jcl_uca_chassis.col(1) ;
    auto&& j18 = A(j13).transpose() ;
    auto&& j19 = B(j5, j14) ;
    auto&& j20 = coord.P_rbl_upright ;
    auto&& j21 = coord.P_rbr_lca ;
    auto&& j22 = Mbar_ground_jcr_lca_chassis.col(2) ;
    auto&& j23 = j22.transpose() ;
    auto&& j24 = Mbar_rbr_lca_jcr_lca_chassis.col(0) ;
    auto&& j25 = Mbar_rbr_lca_jcr_lca_chassis.col(1) ;
    auto&& j26 = A(j21).transpose() ;
    auto&& j27 = B(j5, j22) ;
    auto&& j28 = coord.P_rbl_lca ;
    auto&& j29 = Mbar_ground_jcl_lca_chassis.col(2) ;
    auto&& j30 = j29.transpose() ;
    auto&& j31 = Mbar_rbl_lca_jcl_lca_chassis.col(0) ;
    auto&& j32 = Mbar_rbl_lca_jcl_lca_chassis.col(1) ;
    auto&& j33 = A(j28).transpose() ;
    auto&& j34 = B(j5, j29) ;
    auto&& j35 = Mbar_rbr_hub_jcr_hub_bearing.col(2) ;
    auto&& j36 = j35.transpose() ;
    auto&& j37 = coord.P_rbr_hub ;
    auto&& j38 = A(j37).transpose() ;
    auto&& j39 = Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    auto&& j40 = Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    auto&& j41 = A(j12).transpose() ;
    auto&& j42 = B(j37, j35) ;
    auto&& j43 = Mbar_rbr_hub_jcr_hub_bearing.col(0) ;
    auto&& j44 = Mbar_rbr_upright_jcr_hub_bearing.col(1) ;
    auto&& j45 = Mbar_rbr_upright_jcr_hub_bearing.col(0) ;
    auto&& j46 = Mbar_rbl_hub_jcl_hub_bearing.col(2) ;
    auto&& j47 = j46.transpose() ;
    auto&& j48 = coord.P_rbl_hub ;
    auto&& j49 = A(j48).transpose() ;
    auto&& j50 = Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    auto&& j51 = Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    auto&& j52 = A(j20).transpose() ;
    auto&& j53 = B(j48, j46) ;
    auto&& j54 = Mbar_rbl_hub_jcl_hub_bearing.col(0) ;
    auto&& j55 = Mbar_rbl_upright_jcl_hub_bearing.col(1) ;
    auto&& j56 = Mbar_rbl_upright_jcl_hub_bearing.col(0) ;
    auto&& j57 = coord.P_rbr_upper_strut ;
    auto&& j58 = Mbar_ground_jcr_strut_chassis.col(0) ;
    auto&& j59 = Mbar_rbr_upper_strut_jcr_strut_chassis.col(0) ;
    auto&& j60 = A(j57).transpose() ;
    auto&& j61 = Mbar_rbr_lower_strut_jcr_strut.col(2) ;
    auto&& j62 = j61.transpose() ;
    auto&& j63 = coord.P_rbr_lower_strut ;
    auto&& j64 = A(j63).transpose() ;
    auto&& j65 = Mbar_rbr_upper_strut_jcr_strut.col(0) ;
    auto&& j66 = B(j57, j65) ;
    auto&& j67 = Mbar_rbr_upper_strut_jcr_strut.col(1) ;
    auto&& j68 = B(j57, j67) ;
    auto&& j69 = j65.transpose() ;
    auto&& j70 = (j69 * j60) ;
    auto&& j71 = ubar_rbr_upper_strut_jcr_strut ;
    auto&& j72 = B(j57, j71) ;
    auto&& j73 = ubar_rbr_lower_strut_jcr_strut ;
    auto&& j74 = (coord.R_rbr_upper_strut.transpose() + (-1 * coord.R_rbr_lower_strut.transpose()) + (j71.transpose() * j60) + (-1 * j73.transpose() * j64)) ;
    auto&& j75 = j67.transpose() ;
    auto&& j76 = (j75 * j60) ;
    auto&& j77 = B(j63, j61) ;
    auto&& j78 = B(j63, j73) ;
    auto&& j79 = coord.P_rbl_upper_strut ;
    auto&& j80 = Mbar_ground_jcl_strut_chassis.col(0) ;
    auto&& j81 = Mbar_rbl_upper_strut_jcl_strut_chassis.col(0) ;
    auto&& j82 = A(j79).transpose() ;
    auto&& j83 = Mbar_rbl_lower_strut_jcl_strut.col(2) ;
    auto&& j84 = j83.transpose() ;
    auto&& j85 = coord.P_rbl_lower_strut ;
    auto&& j86 = A(j85).transpose() ;
    auto&& j87 = Mbar_rbl_upper_strut_jcl_strut.col(0) ;
    auto&& j88 = B(j79, j87) ;
    auto&& j89 = Mbar_rbl_upper_strut_jcl_strut.col(1) ;
    auto&& j90 = B(j79, j89) ;
    auto&& j91 = j87.transpose() ;
    auto&& j92 = (j91 * j82) ;
    auto&& j93 = ubar_rbl_upper_strut_jcl_strut ;
    auto&& j94 = B(j79, j93) ;
    auto&& j95 = ubar_rbl_lower_strut_jcl_strut ;
    auto&& j96 = (coord.R_rbl_upper_strut.transpose() + (-1 * coord.R_rbl_lower_strut.transpose()) + (j93.transpose() * j82) + (-1 * j95.transpose() * j86)) ;
    auto&& j97 = j89.transpose() ;
    auto&& j98 = (j97 * j82) ;
    auto&& j99 = B(j85, j83) ;
    auto&& j100 = B(j85, j95) ;
    auto&& j101 = Mbar_rbr_lca_jcr_strut_lca.col(0) ;
    auto&& j102 = Mbar_rbr_lower_strut_jcr_strut_lca.col(0) ;
    auto&& j103 = Mbar_rbl_lca_jcl_strut_lca.col(0) ;
    auto&& j104 = Mbar_rbl_lower_strut_jcl_strut_lca.col(0) ;
    auto&& j105 = coord.P_rbr_tie_rod ;
    auto&& j106 = Mbar_ground_jcr_tie_steering.col(0) ;
    auto&& j107 = Mbar_rbr_tie_rod_jcr_tie_steering.col(0) ;
    auto&& j108 = coord.P_rbl_tie_rod ;
    auto&& j109 = Mbar_ground_jcl_tie_steering.col(0) ;
    auto&& j110 = Mbar_rbl_tie_rod_jcl_tie_steering.col(0) ;
    auto&& j111 = j0.block(2,0, 1,3) ;
    auto&& j112 = (-1 * j111) ;

    jac_eq = 
        {j9,
        (-1 * B(j5, ubar_ground_jcr_uca_chassis)),
        j0,
        B(j1, ubar_rbr_uca_jcr_uca_chassis),
        j2,
        (j7.transpose() * j10 * j11),
        j2,
        (j4 * j6 * B(j1, j7)),
        j2,
        (j8.transpose() * j10 * j11),
        j2,
        (j4 * j6 * B(j1, j8)),
        j0,
        B(j1, ubar_rbr_uca_jcr_uca_upright),
        j9,
        (-1 * B(j12, ubar_rbr_upright_jcr_uca_upright)),
        j9,
        (-1 * B(j5, ubar_ground_jcl_uca_chassis)),
        j0,
        B(j13, ubar_rbl_uca_jcl_uca_chassis),
        j2,
        (j16.transpose() * j18 * j19),
        j2,
        (j15 * j6 * B(j13, j16)),
        j2,
        (j17.transpose() * j18 * j19),
        j2,
        (j15 * j6 * B(j13, j17)),
        j0,
        B(j13, ubar_rbl_uca_jcl_uca_upright),
        j9,
        (-1 * B(j20, ubar_rbl_upright_jcl_uca_upright)),
        j9,
        (-1 * B(j5, ubar_ground_jcr_lca_chassis)),
        j0,
        B(j21, ubar_rbr_lca_jcr_lca_chassis),
        j2,
        (j24.transpose() * j26 * j27),
        j2,
        (j23 * j6 * B(j21, j24)),
        j2,
        (j25.transpose() * j26 * j27),
        j2,
        (j23 * j6 * B(j21, j25)),
        j0,
        B(j21, ubar_rbr_lca_jcr_lca_upright),
        j9,
        (-1 * B(j12, ubar_rbr_upright_jcr_lca_upright)),
        j9,
        (-1 * B(j5, ubar_ground_jcl_lca_chassis)),
        j0,
        B(j28, ubar_rbl_lca_jcl_lca_chassis),
        j2,
        (j31.transpose() * j33 * j34),
        j2,
        (j30 * j6 * B(j28, j31)),
        j2,
        (j32.transpose() * j33 * j34),
        j2,
        (j30 * j6 * B(j28, j32)),
        j0,
        B(j28, ubar_rbl_lca_jcl_lca_upright),
        j9,
        (-1 * B(j20, ubar_rbl_upright_jcl_lca_upright)),
        j0,
        B(j12, ubar_rbr_upright_jcr_hub_bearing),
        j9,
        (-1 * B(j37, ubar_rbr_hub_jcr_hub_bearing)),
        j2,
        (j36 * j38 * B(j12, j39)),
        j2,
        (j39.transpose() * j41 * j42),
        j2,
        (j36 * j38 * B(j12, j40)),
        j2,
        (j40.transpose() * j41 * j42),
        j2,
        (j43.transpose() * j38 * ((std::cos(config.UF_mcr_wheel_lock(t)) * (B(j12, j44))) + ((-1 * std::sin(config.UF_mcr_wheel_lock(t))) * B(j12, j45)))),
        j2,
        (((std::cos(config.UF_mcr_wheel_lock(t)) * (j44.transpose() * j41)) + ((-1 * std::sin(config.UF_mcr_wheel_lock(t))) * j45.transpose() * j41)) * B(j37, j43)),
        j0,
        B(j20, ubar_rbl_upright_jcl_hub_bearing),
        j9,
        (-1 * B(j48, ubar_rbl_hub_jcl_hub_bearing)),
        j2,
        (j47 * j49 * B(j20, j50)),
        j2,
        (j50.transpose() * j52 * j53),
        j2,
        (j47 * j49 * B(j20, j51)),
        j2,
        (j51.transpose() * j52 * j53),
        j2,
        (j54.transpose() * j49 * ((std::cos(config.UF_mcl_wheel_lock(t)) * (B(j20, j55))) + ((-1 * std::sin(config.UF_mcl_wheel_lock(t))) * B(j20, j56)))),
        j2,
        (((std::cos(config.UF_mcl_wheel_lock(t)) * (j55.transpose() * j52)) + ((-1 * std::sin(config.UF_mcl_wheel_lock(t))) * j56.transpose() * j52)) * B(j48, j54)),
        j9,
        (-1 * B(j5, ubar_ground_jcr_strut_chassis)),
        j0,
        B(j57, ubar_rbr_upper_strut_jcr_strut_chassis),
        j2,
        (j59.transpose() * j60 * B(j5, j58)),
        j2,
        (j58.transpose() * j6 * B(j57, j59)),
        j2,
        (j62 * j64 * j66),
        j2,
        (j69 * j60 * j77),
        j2,
        (j62 * j64 * j68),
        j2,
        (j75 * j60 * j77),
        j70,
        ((j69 * j60 * j72) + (j74 * j66)),
        (-1 * j70),
        (-1 * j69 * j60 * j78),
        j76,
        ((j75 * j60 * j72) + (j74 * j68)),
        (-1 * j76),
        (-1 * j75 * j60 * j78),
        j9,
        (-1 * B(j5, ubar_ground_jcl_strut_chassis)),
        j0,
        B(j79, ubar_rbl_upper_strut_jcl_strut_chassis),
        j2,
        (j81.transpose() * j82 * B(j5, j80)),
        j2,
        (j80.transpose() * j6 * B(j79, j81)),
        j2,
        (j84 * j86 * j88),
        j2,
        (j91 * j82 * j99),
        j2,
        (j84 * j86 * j90),
        j2,
        (j97 * j82 * j99),
        j92,
        ((j91 * j82 * j94) + (j96 * j88)),
        (-1 * j92),
        (-1 * j91 * j82 * j100),
        j98,
        ((j97 * j82 * j94) + (j96 * j90)),
        (-1 * j98),
        (-1 * j97 * j82 * j100),
        j9,
        (-1 * B(j21, ubar_rbr_lca_jcr_strut_lca)),
        j0,
        B(j63, ubar_rbr_lower_strut_jcr_strut_lca),
        j2,
        (j102.transpose() * j64 * B(j21, j101)),
        j2,
        (j101.transpose() * j26 * B(j63, j102)),
        j9,
        (-1 * B(j28, ubar_rbl_lca_jcl_strut_lca)),
        j0,
        B(j85, ubar_rbl_lower_strut_jcl_strut_lca),
        j2,
        (j104.transpose() * j86 * B(j28, j103)),
        j2,
        (j103.transpose() * j33 * B(j85, j104)),
        j9,
        (-1 * B(j5, ubar_ground_jcr_tie_steering)),
        j0,
        B(j105, ubar_rbr_tie_rod_jcr_tie_steering),
        j2,
        (j107.transpose() * A(j105).transpose() * B(j5, j106)),
        j2,
        (j106.transpose() * j6 * B(j105, j107)),
        j9,
        (-1 * B(j12, ubar_rbr_upright_jcr_tie_upright)),
        j0,
        B(j105, ubar_rbr_tie_rod_jcr_tie_upright),
        j9,
        (-1 * B(j5, ubar_ground_jcl_tie_steering)),
        j0,
        B(j108, ubar_rbl_tie_rod_jcl_tie_steering),
        j2,
        (j110.transpose() * A(j108).transpose() * B(j5, j109)),
        j2,
        (j109.transpose() * j6 * B(j108, j110)),
        j9,
        (-1 * B(j20, ubar_rbl_upright_jcl_tie_upright)),
        j0,
        B(j108, ubar_rbl_tie_rod_jcl_tie_upright),
        j112,
        (-1 * B(j5, ubar_ground_mcr_wheel_travel).block(2,0, 1,4)),
        j111,
        B(j37, ubar_rbr_hub_mcr_wheel_travel).block(2,0, 1,4),
        j112,
        (-1 * B(j5, ubar_ground_mcl_wheel_travel).block(2,0, 1,4)),
        j111,
        B(j48, ubar_rbl_hub_mcl_wheel_travel).block(2,0, 1,4),
        j0,
        Eigen::MatrixXd::Zero(3, 4),
        Eigen::MatrixXd::Zero(4, 3),
        Eigen::MatrixXd::Identity(4, 4),
        j2,
        (2 * (j1.transpose())),
        j2,
        (2 * (j13.transpose())),
        j2,
        (2 * (j21.transpose())),
        j2,
        (2 * (j28.transpose())),
        j2,
        (2 * (j12.transpose())),
        j2,
        (2 * (j20.transpose())),
        j2,
        (2 * (j57.transpose())),
        j2,
        (2 * (j79.transpose())),
        j2,
        (2 * (j63.transpose())),
        j2,
        (2 * (j85.transpose())),
        j2,
        (2 * (j105.transpose())),
        j2,
        (2 * (j108.transpose())),
        j2,
        (2 * (j37.transpose())),
        j2,
        (2 * (j48.transpose()))};
};

void Topology::eval_mas_eq()
{
    auto&& m0 = (Eigen::MatrixXd::Identity(3, 3)) ;
    auto&& m1 = G(coord.P_ground) ;
    auto&& m2 = G(coord.P_rbr_uca) ;
    auto&& m3 = G(coord.P_rbl_uca) ;
    auto&& m4 = G(coord.P_rbr_lca) ;
    auto&& m5 = G(coord.P_rbl_lca) ;
    auto&& m6 = G(coord.P_rbr_upright) ;
    auto&& m7 = G(coord.P_rbl_upright) ;
    auto&& m8 = G(coord.P_rbr_upper_strut) ;
    auto&& m9 = G(coord.P_rbl_upper_strut) ;
    auto&& m10 = G(coord.P_rbr_lower_strut) ;
    auto&& m11 = G(coord.P_rbl_lower_strut) ;
    auto&& m12 = G(coord.P_rbr_tie_rod) ;
    auto&& m13 = G(coord.P_rbl_tie_rod) ;
    auto&& m14 = G(coord.P_rbr_hub) ;
    auto&& m15 = G(coord.P_rbl_hub) ;

    mas_eq = 
        {(m_ground * m0),
        (4 * (m1.transpose() * Jbar_ground * m1)),
        (config.m_rbr_uca * m0),
        (4 * (m2.transpose() * config.Jbar_rbr_uca * m2)),
        (config.m_rbl_uca * m0),
        (4 * (m3.transpose() * config.Jbar_rbl_uca * m3)),
        (config.m_rbr_lca * m0),
        (4 * (m4.transpose() * config.Jbar_rbr_lca * m4)),
        (config.m_rbl_lca * m0),
        (4 * (m5.transpose() * config.Jbar_rbl_lca * m5)),
        (config.m_rbr_upright * m0),
        (4 * (m6.transpose() * config.Jbar_rbr_upright * m6)),
        (config.m_rbl_upright * m0),
        (4 * (m7.transpose() * config.Jbar_rbl_upright * m7)),
        (config.m_rbr_upper_strut * m0),
        (4 * (m8.transpose() * config.Jbar_rbr_upper_strut * m8)),
        (config.m_rbl_upper_strut * m0),
        (4 * (m9.transpose() * config.Jbar_rbl_upper_strut * m9)),
        (config.m_rbr_lower_strut * m0),
        (4 * (m10.transpose() * config.Jbar_rbr_lower_strut * m10)),
        (config.m_rbl_lower_strut * m0),
        (4 * (m11.transpose() * config.Jbar_rbl_lower_strut * m11)),
        (config.m_rbr_tie_rod * m0),
        (4 * (m12.transpose() * config.Jbar_rbr_tie_rod * m12)),
        (config.m_rbl_tie_rod * m0),
        (4 * (m13.transpose() * config.Jbar_rbl_tie_rod * m13)),
        (config.m_rbr_hub * m0),
        (4 * (m14.transpose() * config.Jbar_rbr_hub * m14)),
        (config.m_rbl_hub * m0),
        (4 * (m15.transpose() * config.Jbar_rbl_hub * m15))};
};


void Topology::eval_reactions()
{
    //

    //rct_return;
};

void Topology::eval_reactions(Eigen::Ref<SparseBlock> jacobian)
{
    // Joint Name : jcr_uca_chassis
const auto& Jac_jcr_uca_chassis = jacobian.block(0, 7, 5, 7);
Eigen::VectorXd Q_jcr_uca_chassis = -Jac_jcr_uca_chassis.transpose() * coord.L_jcr_uca_chassis;
const auto& F_jcr_uca_chassis = Q_jcr_uca_chassis.segment(0, 3);
Eigen::VectorXd T_jcr_uca_chassis = 0.5*E(coord.P_rbr_uca) * Q_jcr_uca_chassis.segment(3, 4) - skew(A(coord.P_rbr_uca)*ubar_rbr_uca_jcr_uca_chassis)*F_jcr_uca_chassis;

std::cout << F_jcr_uca_chassis << "\n\n";
std::cout << T_jcr_uca_chassis << "\n\n\n";

// Joint Name : jcr_uca_upright
const auto& Jac_jcr_uca_upright = jacobian.block(5, 7, 3, 7);
Eigen::VectorXd Q_jcr_uca_upright = -Jac_jcr_uca_upright.transpose() * coord.L_jcr_uca_upright;
const auto& F_jcr_uca_upright = Q_jcr_uca_upright.segment(0, 3);
Eigen::VectorXd T_jcr_uca_upright = 0.5*E(coord.P_rbr_uca) * Q_jcr_uca_upright.segment(3, 4) - skew(A(coord.P_rbr_uca)*ubar_rbr_uca_jcr_uca_upright)*F_jcr_uca_upright;

// Joint Name : jcl_uca_chassis
const auto& Jac_jcl_uca_chassis = jacobian.block(8, 14, 5, 7);
Eigen::VectorXd Q_jcl_uca_chassis = -Jac_jcl_uca_chassis.transpose() * coord.L_jcl_uca_chassis;
const auto& F_jcl_uca_chassis = Q_jcl_uca_chassis.segment(0, 3);
Eigen::VectorXd T_jcl_uca_chassis = 0.5*E(coord.P_rbl_uca) * Q_jcl_uca_chassis.segment(3, 4) - skew(A(coord.P_rbl_uca)*ubar_rbl_uca_jcl_uca_chassis)*F_jcl_uca_chassis;

// Joint Name : jcl_uca_upright
const auto& Jac_jcl_uca_upright = jacobian.block(13, 14, 3, 7);
Eigen::VectorXd Q_jcl_uca_upright = -Jac_jcl_uca_upright.transpose() * coord.L_jcl_uca_upright;
const auto& F_jcl_uca_upright = Q_jcl_uca_upright.segment(0, 3);
Eigen::VectorXd T_jcl_uca_upright = 0.5*E(coord.P_rbl_uca) * Q_jcl_uca_upright.segment(3, 4) - skew(A(coord.P_rbl_uca)*ubar_rbl_uca_jcl_uca_upright)*F_jcl_uca_upright;

// Joint Name : jcr_lca_chassis
const auto& Jac_jcr_lca_chassis = jacobian.block(16, 21, 5, 7);
Eigen::VectorXd Q_jcr_lca_chassis = -Jac_jcr_lca_chassis.transpose() * coord.L_jcr_lca_chassis;
const auto& F_jcr_lca_chassis = Q_jcr_lca_chassis.segment(0, 3);
Eigen::VectorXd T_jcr_lca_chassis = 0.5*E(coord.P_rbr_lca) * Q_jcr_lca_chassis.segment(3, 4) - skew(A(coord.P_rbr_lca)*ubar_rbr_lca_jcr_lca_chassis)*F_jcr_lca_chassis;

// Joint Name : jcr_lca_upright
const auto& Jac_jcr_lca_upright = jacobian.block(21, 21, 3, 7);
Eigen::VectorXd Q_jcr_lca_upright = -Jac_jcr_lca_upright.transpose() * coord.L_jcr_lca_upright;
const auto& F_jcr_lca_upright = Q_jcr_lca_upright.segment(0, 3);
Eigen::VectorXd T_jcr_lca_upright = 0.5*E(coord.P_rbr_lca) * Q_jcr_lca_upright.segment(3, 4) - skew(A(coord.P_rbr_lca)*ubar_rbr_lca_jcr_lca_upright)*F_jcr_lca_upright;

// Joint Name : jcl_lca_chassis
const auto& Jac_jcl_lca_chassis = jacobian.block(24, 28, 5, 7);
Eigen::VectorXd Q_jcl_lca_chassis = -Jac_jcl_lca_chassis.transpose() * coord.L_jcl_lca_chassis;
const auto& F_jcl_lca_chassis = Q_jcl_lca_chassis.segment(0, 3);
Eigen::VectorXd T_jcl_lca_chassis = 0.5*E(coord.P_rbl_lca) * Q_jcl_lca_chassis.segment(3, 4) - skew(A(coord.P_rbl_lca)*ubar_rbl_lca_jcl_lca_chassis)*F_jcl_lca_chassis;

// Joint Name : jcl_lca_upright
const auto& Jac_jcl_lca_upright = jacobian.block(29, 28, 3, 7);
Eigen::VectorXd Q_jcl_lca_upright = -Jac_jcl_lca_upright.transpose() * coord.L_jcl_lca_upright;
const auto& F_jcl_lca_upright = Q_jcl_lca_upright.segment(0, 3);
Eigen::VectorXd T_jcl_lca_upright = 0.5*E(coord.P_rbl_lca) * Q_jcl_lca_upright.segment(3, 4) - skew(A(coord.P_rbl_lca)*ubar_rbl_lca_jcl_lca_upright)*F_jcl_lca_upright;

// Joint Name : jcr_hub_bearing
const auto& Jac_jcr_hub_bearing = jacobian.block(32, 35, 5, 7);
Eigen::VectorXd Q_jcr_hub_bearing = -Jac_jcr_hub_bearing.transpose() * coord.L_jcr_hub_bearing;
const auto& F_jcr_hub_bearing = Q_jcr_hub_bearing.segment(0, 3);
Eigen::VectorXd T_jcr_hub_bearing = 0.5*E(coord.P_rbr_upright) * Q_jcr_hub_bearing.segment(3, 4) - skew(A(coord.P_rbr_upright)*ubar_rbr_upright_jcr_hub_bearing)*F_jcr_hub_bearing;

// Joint Name : mcr_wheel_lock
const auto& Jac_mcr_wheel_lock = jacobian.block(37, 35, 1, 7);
Eigen::VectorXd Q_mcr_wheel_lock = -Jac_mcr_wheel_lock.transpose() * coord.L_mcr_wheel_lock;
const auto& F_mcr_wheel_lock = Q_mcr_wheel_lock.segment(0, 3);
Eigen::VectorXd T_mcr_wheel_lock = 0.5*E(coord.P_rbr_upright) * Q_mcr_wheel_lock.segment(3, 4);

// Joint Name : jcl_hub_bearing
const auto& Jac_jcl_hub_bearing = jacobian.block(38, 42, 5, 7);
Eigen::VectorXd Q_jcl_hub_bearing = -Jac_jcl_hub_bearing.transpose() * coord.L_jcl_hub_bearing;
const auto& F_jcl_hub_bearing = Q_jcl_hub_bearing.segment(0, 3);
Eigen::VectorXd T_jcl_hub_bearing = 0.5*E(coord.P_rbl_upright) * Q_jcl_hub_bearing.segment(3, 4) - skew(A(coord.P_rbl_upright)*ubar_rbl_upright_jcl_hub_bearing)*F_jcl_hub_bearing;

// Joint Name : mcl_wheel_lock
const auto& Jac_mcl_wheel_lock = jacobian.block(43, 42, 1, 7);
Eigen::VectorXd Q_mcl_wheel_lock = -Jac_mcl_wheel_lock.transpose() * coord.L_mcl_wheel_lock;
const auto& F_mcl_wheel_lock = Q_mcl_wheel_lock.segment(0, 3);
Eigen::VectorXd T_mcl_wheel_lock = 0.5*E(coord.P_rbl_upright) * Q_mcl_wheel_lock.segment(3, 4);

// Joint Name : jcr_strut_chassis
const auto& Jac_jcr_strut_chassis = jacobian.block(44, 49, 4, 7);
Eigen::VectorXd Q_jcr_strut_chassis = -Jac_jcr_strut_chassis.transpose() * coord.L_jcr_strut_chassis;
const auto& F_jcr_strut_chassis = Q_jcr_strut_chassis.segment(0, 3);
Eigen::VectorXd T_jcr_strut_chassis = 0.5*E(coord.P_rbr_upper_strut) * Q_jcr_strut_chassis.segment(3, 4) - skew(A(coord.P_rbr_upper_strut)*ubar_rbr_upper_strut_jcr_strut_chassis)*F_jcr_strut_chassis;

// Joint Name : jcr_strut
const auto& Jac_jcr_strut = jacobian.block(48, 49, 4, 7);
Eigen::VectorXd Q_jcr_strut = -Jac_jcr_strut.transpose() * coord.L_jcr_strut;
const auto& F_jcr_strut = Q_jcr_strut.segment(0, 3);
Eigen::VectorXd T_jcr_strut = 0.5*E(coord.P_rbr_upper_strut) * Q_jcr_strut.segment(3, 4) - skew(A(coord.P_rbr_upper_strut)*ubar_rbr_upper_strut_jcr_strut)*F_jcr_strut;

// Joint Name : jcl_strut_chassis
const auto& Jac_jcl_strut_chassis = jacobian.block(52, 56, 4, 7);
Eigen::VectorXd Q_jcl_strut_chassis = -Jac_jcl_strut_chassis.transpose() * coord.L_jcl_strut_chassis;
const auto& F_jcl_strut_chassis = Q_jcl_strut_chassis.segment(0, 3);
Eigen::VectorXd T_jcl_strut_chassis = 0.5*E(coord.P_rbl_upper_strut) * Q_jcl_strut_chassis.segment(3, 4) - skew(A(coord.P_rbl_upper_strut)*ubar_rbl_upper_strut_jcl_strut_chassis)*F_jcl_strut_chassis;

// Joint Name : jcl_strut
const auto& Jac_jcl_strut = jacobian.block(56, 56, 4, 7);
Eigen::VectorXd Q_jcl_strut = -Jac_jcl_strut.transpose() * coord.L_jcl_strut;
const auto& F_jcl_strut = Q_jcl_strut.segment(0, 3);
Eigen::VectorXd T_jcl_strut = 0.5*E(coord.P_rbl_upper_strut) * Q_jcl_strut.segment(3, 4) - skew(A(coord.P_rbl_upper_strut)*ubar_rbl_upper_strut_jcl_strut)*F_jcl_strut;

// Joint Name : jcr_strut_lca
const auto& Jac_jcr_strut_lca = jacobian.block(60, 63, 4, 7);
Eigen::VectorXd Q_jcr_strut_lca = -Jac_jcr_strut_lca.transpose() * coord.L_jcr_strut_lca;
const auto& F_jcr_strut_lca = Q_jcr_strut_lca.segment(0, 3);
Eigen::VectorXd T_jcr_strut_lca = 0.5*E(coord.P_rbr_lower_strut) * Q_jcr_strut_lca.segment(3, 4) - skew(A(coord.P_rbr_lower_strut)*ubar_rbr_lower_strut_jcr_strut_lca)*F_jcr_strut_lca;

// Joint Name : jcl_strut_lca
const auto& Jac_jcl_strut_lca = jacobian.block(64, 70, 4, 7);
Eigen::VectorXd Q_jcl_strut_lca = -Jac_jcl_strut_lca.transpose() * coord.L_jcl_strut_lca;
const auto& F_jcl_strut_lca = Q_jcl_strut_lca.segment(0, 3);
Eigen::VectorXd T_jcl_strut_lca = 0.5*E(coord.P_rbl_lower_strut) * Q_jcl_strut_lca.segment(3, 4) - skew(A(coord.P_rbl_lower_strut)*ubar_rbl_lower_strut_jcl_strut_lca)*F_jcl_strut_lca;

// Joint Name : jcr_tie_steering
const auto& Jac_jcr_tie_steering = jacobian.block(68, 77, 4, 7);
Eigen::VectorXd Q_jcr_tie_steering = -Jac_jcr_tie_steering.transpose() * coord.L_jcr_tie_steering;
const auto& F_jcr_tie_steering = Q_jcr_tie_steering.segment(0, 3);
Eigen::VectorXd T_jcr_tie_steering = 0.5*E(coord.P_rbr_tie_rod) * Q_jcr_tie_steering.segment(3, 4) - skew(A(coord.P_rbr_tie_rod)*ubar_rbr_tie_rod_jcr_tie_steering)*F_jcr_tie_steering;

// Joint Name : jcr_tie_upright
const auto& Jac_jcr_tie_upright = jacobian.block(72, 77, 3, 7);
Eigen::VectorXd Q_jcr_tie_upright = -Jac_jcr_tie_upright.transpose() * coord.L_jcr_tie_upright;
const auto& F_jcr_tie_upright = Q_jcr_tie_upright.segment(0, 3);
Eigen::VectorXd T_jcr_tie_upright = 0.5*E(coord.P_rbr_tie_rod) * Q_jcr_tie_upright.segment(3, 4) - skew(A(coord.P_rbr_tie_rod)*ubar_rbr_tie_rod_jcr_tie_upright)*F_jcr_tie_upright;

// Joint Name : jcl_tie_steering
const auto& Jac_jcl_tie_steering = jacobian.block(75, 84, 4, 7);
Eigen::VectorXd Q_jcl_tie_steering = -Jac_jcl_tie_steering.transpose() * coord.L_jcl_tie_steering;
const auto& F_jcl_tie_steering = Q_jcl_tie_steering.segment(0, 3);
Eigen::VectorXd T_jcl_tie_steering = 0.5*E(coord.P_rbl_tie_rod) * Q_jcl_tie_steering.segment(3, 4) - skew(A(coord.P_rbl_tie_rod)*ubar_rbl_tie_rod_jcl_tie_steering)*F_jcl_tie_steering;

// Joint Name : jcl_tie_upright
const auto& Jac_jcl_tie_upright = jacobian.block(79, 84, 3, 7);
Eigen::VectorXd Q_jcl_tie_upright = -Jac_jcl_tie_upright.transpose() * coord.L_jcl_tie_upright;
const auto& F_jcl_tie_upright = Q_jcl_tie_upright.segment(0, 3);
Eigen::VectorXd T_jcl_tie_upright = 0.5*E(coord.P_rbl_tie_rod) * Q_jcl_tie_upright.segment(3, 4) - skew(A(coord.P_rbl_tie_rod)*ubar_rbl_tie_rod_jcl_tie_upright)*F_jcl_tie_upright;

// Joint Name : mcr_wheel_travel
const auto& Jac_mcr_wheel_travel = jacobian.block(82, 91, 1, 7);
Eigen::VectorXd Q_mcr_wheel_travel = -Jac_mcr_wheel_travel.transpose() * coord.L_mcr_wheel_travel;
const auto& F_mcr_wheel_travel = Q_mcr_wheel_travel.segment(0, 3);
Eigen::VectorXd T_mcr_wheel_travel = 0.5*E(coord.P_rbr_hub) * Q_mcr_wheel_travel.segment(3, 4) - skew(A(coord.P_rbr_hub)*ubar_rbr_hub_mcr_wheel_travel)*F_mcr_wheel_travel;

// Joint Name : mcl_wheel_travel
const auto& Jac_mcl_wheel_travel = jacobian.block(83, 98, 1, 7);
Eigen::VectorXd Q_mcl_wheel_travel = -Jac_mcl_wheel_travel.transpose() * coord.L_mcl_wheel_travel;
const auto& F_mcl_wheel_travel = Q_mcl_wheel_travel.segment(0, 3);
Eigen::VectorXd T_mcl_wheel_travel = 0.5*E(coord.P_rbl_hub) * Q_mcl_wheel_travel.segment(3, 4) - skew(A(coord.P_rbl_hub)*ubar_rbl_hub_mcl_wheel_travel)*F_mcl_wheel_travel;

    //rct_return;
};