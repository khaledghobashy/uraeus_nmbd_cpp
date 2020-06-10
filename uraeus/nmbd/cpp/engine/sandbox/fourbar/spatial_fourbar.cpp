
#include "spatial_fourbar.hpp"

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
    ConfigInputs.get("R_rbs_l1", R_rbs_l1);
    ConfigInputs.get("P_rbs_l1", P_rbs_l1);
    ConfigInputs.get("Rd_rbs_l1", Rd_rbs_l1);
    ConfigInputs.get("Pd_rbs_l1", Pd_rbs_l1);
    ConfigInputs.get("Rdd_rbs_l1", Rdd_rbs_l1);
    ConfigInputs.get("Pdd_rbs_l1", Pdd_rbs_l1);
    ConfigInputs.get("m_rbs_l1", m_rbs_l1);
    ConfigInputs.get("Jbar_rbs_l1", Jbar_rbs_l1);
    ConfigInputs.get("R_rbs_l2", R_rbs_l2);
    ConfigInputs.get("P_rbs_l2", P_rbs_l2);
    ConfigInputs.get("Rd_rbs_l2", Rd_rbs_l2);
    ConfigInputs.get("Pd_rbs_l2", Pd_rbs_l2);
    ConfigInputs.get("Rdd_rbs_l2", Rdd_rbs_l2);
    ConfigInputs.get("Pdd_rbs_l2", Pdd_rbs_l2);
    ConfigInputs.get("m_rbs_l2", m_rbs_l2);
    ConfigInputs.get("Jbar_rbs_l2", Jbar_rbs_l2);
    ConfigInputs.get("R_rbs_l3", R_rbs_l3);
    ConfigInputs.get("P_rbs_l3", P_rbs_l3);
    ConfigInputs.get("Rd_rbs_l3", Rd_rbs_l3);
    ConfigInputs.get("Pd_rbs_l3", Pd_rbs_l3);
    ConfigInputs.get("Rdd_rbs_l3", Rdd_rbs_l3);
    ConfigInputs.get("Pdd_rbs_l3", Pdd_rbs_l3);
    ConfigInputs.get("m_rbs_l3", m_rbs_l3);
    ConfigInputs.get("Jbar_rbs_l3", Jbar_rbs_l3);
    ConfigInputs.get("ax1_jcs_a", ax1_jcs_a);
    ConfigInputs.get("pt1_jcs_a", pt1_jcs_a);
    ConfigInputs.get("ax1_jcs_a", ax1_jcs_a);
    ConfigInputs.get("UF_mcs_act", UF_mcs_act);
    ConfigInputs.get("ax1_jcs_b", ax1_jcs_b);
    ConfigInputs.get("pt1_jcs_b", pt1_jcs_b);
    ConfigInputs.get("ax1_jcs_c", ax1_jcs_c);
    ConfigInputs.get("ax2_jcs_c", ax2_jcs_c);
    ConfigInputs.get("pt1_jcs_c", pt1_jcs_c);
    ConfigInputs.get("ax1_jcs_d", ax1_jcs_d);
    ConfigInputs.get("pt1_jcs_d", pt1_jcs_d);
};


void Configuration::set_inital_configuration()
{
    R_ground << 0, 0, 0 ;
    P_ground << 1, 0, 0, 0 ;

    q.resize(28);
    q << 
        R_ground, 
        P_ground, 
        R_rbs_l1, 
        P_rbs_l1, 
        R_rbs_l2, 
        P_rbs_l2, 
        R_rbs_l3, 
        P_rbs_l3;

    qd.resize(28);
    qd << 
        Rd_ground, 
        Pd_ground, 
        Rd_rbs_l1, 
        Pd_rbs_l1, 
        Rd_rbs_l2, 
        Pd_rbs_l2, 
        Rd_rbs_l3, 
        Pd_rbs_l3;
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
    rct_eq.resize(6*5);

    jac_rows.resize(50);
    jac_cols.resize(50);
    jac_eq.reserve(50);

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
    for (auto& name : bodies_names) {indicies_map[prefix + name] = i; i++;};
};


void Topology::assemble(Dict_SI& indicies_map, Dict_SS& interface_map, int rows_offset)
{
    set_mapping(indicies_map, interface_map);

    jac_rows << 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14;
    jac_rows += (rows_offset * Eigen::VectorXd::Ones(jac_rows.size()) );

    jac_cols << 
        ground*2, 
        ground*2+1, 
        rbs_l1*2, 
        rbs_l1*2+1, 
        ground*2, 
        ground*2+1, 
        rbs_l1*2, 
        rbs_l1*2+1, 
        ground*2, 
        ground*2+1, 
        rbs_l1*2, 
        rbs_l1*2+1, 
        ground*2, 
        ground*2+1, 
        rbs_l1*2, 
        rbs_l1*2+1, 
        rbs_l1*2, 
        rbs_l1*2+1, 
        rbs_l2*2, 
        rbs_l2*2+1, 
        rbs_l2*2, 
        rbs_l2*2+1, 
        rbs_l3*2, 
        rbs_l3*2+1, 
        rbs_l2*2, 
        rbs_l2*2+1, 
        rbs_l3*2, 
        rbs_l3*2+1, 
        ground*2, 
        ground*2+1, 
        rbs_l3*2, 
        rbs_l3*2+1, 
        ground*2, 
        ground*2+1, 
        rbs_l3*2, 
        rbs_l3*2+1, 
        ground*2, 
        ground*2+1, 
        rbs_l3*2, 
        rbs_l3*2+1, 
        ground*2, 
        ground*2+1, 
        ground*2, 
        ground*2+1, 
        rbs_l1*2, 
        rbs_l1*2+1, 
        rbs_l2*2, 
        rbs_l2*2+1, 
        rbs_l3*2, 
        rbs_l3*2+1;
};


void Topology::set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map)
{
    auto& p = this-> prefix;

    ground = indicies_map[p+"ground"];
    rbs_l1 = indicies_map[p+"rbs_l1"];
    rbs_l2 = indicies_map[p+"rbs_l2"];
    rbs_l3 = indicies_map[p+"rbs_l3"];

    
};


void Topology::eval_constants()
{
    R_ground << 0, 0, 0 ;
    P_ground << 1, 0, 0, 0 ;
    Pg_ground << 1, 0, 0, 0 ;
    m_ground = 1.0 ;
    Jbar_ground << 1, 0, 0, 0, 1, 0, 0, 0, 1 ;
    F_rbs_l1_gravity << 0, 0, -9810.0*config.m_rbs_l1 ;
    F_rbs_l2_gravity << 0, 0, -9810.0*config.m_rbs_l2 ;
    F_rbs_l3_gravity << 0, 0, -9810.0*config.m_rbs_l3 ;
                    
    Mbar_ground_jcs_a << (A(P_ground).transpose() * triad(config.ax1_jcs_a)) ;
    Mbar_rbs_l1_jcs_a << (A(config.P_rbs_l1).transpose() * triad(config.ax1_jcs_a)) ;
    ubar_ground_jcs_a << ((A(P_ground).transpose() * config.pt1_jcs_a) + (-1 * A(P_ground).transpose() * R_ground)) ;
    ubar_rbs_l1_jcs_a << ((A(config.P_rbs_l1).transpose() * config.pt1_jcs_a) + (-1 * A(config.P_rbs_l1).transpose() * config.R_rbs_l1)) ;
    Mbar_ground_jcs_a << (A(P_ground).transpose() * triad(config.ax1_jcs_a)) ;
    Mbar_rbs_l1_jcs_a << (A(config.P_rbs_l1).transpose() * triad(config.ax1_jcs_a)) ;
    Mbar_rbs_l1_jcs_b << (A(config.P_rbs_l1).transpose() * triad(config.ax1_jcs_b)) ;
    Mbar_rbs_l2_jcs_b << (A(config.P_rbs_l2).transpose() * triad(config.ax1_jcs_b)) ;
    ubar_rbs_l1_jcs_b << ((A(config.P_rbs_l1).transpose() * config.pt1_jcs_b) + (-1 * A(config.P_rbs_l1).transpose() * config.R_rbs_l1)) ;
    ubar_rbs_l2_jcs_b << ((A(config.P_rbs_l2).transpose() * config.pt1_jcs_b) + (-1 * A(config.P_rbs_l2).transpose() * config.R_rbs_l2)) ;
    Mbar_rbs_l2_jcs_c << (A(config.P_rbs_l2).transpose() * triad(config.ax1_jcs_c)) ;
    Mbar_rbs_l3_jcs_c << (A(config.P_rbs_l3).transpose() * triad(config.ax2_jcs_c, triad(config.ax1_jcs_c).block(0,1, 3,1))) ;
    ubar_rbs_l2_jcs_c << ((A(config.P_rbs_l2).transpose() * config.pt1_jcs_c) + (-1 * A(config.P_rbs_l2).transpose() * config.R_rbs_l2)) ;
    ubar_rbs_l3_jcs_c << ((A(config.P_rbs_l3).transpose() * config.pt1_jcs_c) + (-1 * A(config.P_rbs_l3).transpose() * config.R_rbs_l3)) ;
    Mbar_rbs_l3_jcs_d << (A(config.P_rbs_l3).transpose() * triad(config.ax1_jcs_d)) ;
    Mbar_ground_jcs_d << (A(P_ground).transpose() * triad(config.ax1_jcs_d)) ;
    ubar_rbs_l3_jcs_d << ((A(config.P_rbs_l3).transpose() * config.pt1_jcs_d) + (-1 * A(config.P_rbs_l3).transpose() * config.R_rbs_l3)) ;
    ubar_ground_jcs_d << ((A(P_ground).transpose() * config.pt1_jcs_d) + (-1 * A(P_ground).transpose() * R_ground)) ;
};

void Topology::eval_pos_eq()
{
    auto&& x0 = coord.R_ground ;
    auto&& x1 = coord.R_rbs_l1 ;
    auto&& x2 = coord.P_ground ;
    auto&& x3 = A(x2) ;
    auto&& x4 = coord.P_rbs_l1 ;
    auto&& x5 = A(x4) ;
    auto&& x6 = x3.transpose() ;
    auto&& x7 = Mbar_rbs_l1_jcs_a.col(2) ;
    auto&& x8 = Mbar_rbs_l1_jcs_a.col(0) ;
    auto&& x9 = coord.R_rbs_l2 ;
    auto&& x10 = coord.P_rbs_l2 ;
    auto&& x11 = A(x10) ;
    auto&& x12 = coord.R_rbs_l3 ;
    auto&& x13 = coord.P_rbs_l3 ;
    auto&& x14 = A(x13) ;
    auto&& x15 = x14.transpose() ;
    auto&& x16 = Mbar_ground_jcs_d.col(2) ;
    auto&& x17 = (-1 * Eigen::MatrixXd::Identity(1, 1)) ;

    pos_eq << 
        (x0 + (-1 * x1) + (x3 * ubar_ground_jcs_a) + (-1 * x5 * ubar_rbs_l1_jcs_a)),
        (Mbar_ground_jcs_a.col(0).transpose() * x6 * x5 * x7),
        (Mbar_ground_jcs_a.col(1).transpose() * x6 * x5 * x7),
        ((std::cos(config.UF_mcs_act(t)) * (Mbar_ground_jcs_a.col(1).transpose() * x6 * x5 * x8)) + ((-1 * std::sin(config.UF_mcs_act(t))) * Mbar_ground_jcs_a.col(0).transpose() * x6 * x5 * x8)),
        (x1 + (-1 * x9) + (x5 * ubar_rbs_l1_jcs_b) + (-1 * x11 * ubar_rbs_l2_jcs_b)),
        (x9 + (-1 * x12) + (x11 * ubar_rbs_l2_jcs_c) + (-1 * x14 * ubar_rbs_l3_jcs_c)),
        (Mbar_rbs_l2_jcs_c.col(0).transpose() * x11.transpose() * x14 * Mbar_rbs_l3_jcs_c.col(0)),
        (x12 + (-1 * x0) + (x14 * ubar_rbs_l3_jcs_d) + (-1 * x3 * ubar_ground_jcs_d)),
        (Mbar_rbs_l3_jcs_d.col(0).transpose() * x15 * x3 * x16),
        (Mbar_rbs_l3_jcs_d.col(1).transpose() * x15 * x3 * x16),
        x0,
        (x2 + (-1 * Pg_ground)),
        (x17 + (x4.transpose() * x4)),
        (x17 + (x10.transpose() * x10)),
        (x17 + (x13.transpose() * x13));
};

void Topology::eval_vel_eq()
{
    auto&& v0 = Eigen::MatrixXd::Zero(3, 1) ;
    auto&& v1 = Eigen::MatrixXd::Zero(1, 1) ;

    vel_eq << 
        v0,
        v1,
        v1,
        (v1 + ((-1 * derivative(config.UF_mcs_act, t, 1)) * Eigen::MatrixXd::Identity(1, 1))),
        v0,
        v0,
        v1,
        v0,
        v1,
        v1,
        v0,
        Eigen::MatrixXd::Zero(4, 1),
        v1,
        v1,
        v1;
};

void Topology::eval_acc_eq()
{
    auto&& a0 = coord.Pd_ground ;
    auto&& a1 = coord.Pd_rbs_l1 ;
    auto&& a2 = Mbar_rbs_l1_jcs_a.col(2) ;
    auto&& a3 = a2.transpose() ;
    auto&& a4 = coord.P_rbs_l1 ;
    auto&& a5 = A(a4).transpose() ;
    auto&& a6 = Mbar_ground_jcs_a.col(0) ;
    auto&& a7 = coord.P_ground ;
    auto&& a8 = A(a7).transpose() ;
    auto&& a9 = B(a1, a2) ;
    auto&& a10 = a0.transpose() ;
    auto&& a11 = B(a4, a2) ;
    auto&& a12 = Mbar_ground_jcs_a.col(1) ;
    auto&& a13 = Mbar_rbs_l1_jcs_a.col(0) ;
    auto&& a14 = Mbar_ground_jcs_a.col(1) ;
    auto&& a15 = Mbar_ground_jcs_a.col(0) ;
    auto&& a16 = coord.Pd_rbs_l2 ;
    auto&& a17 = coord.Pd_rbs_l3 ;
    auto&& a18 = Mbar_rbs_l2_jcs_c.col(0) ;
    auto&& a19 = coord.P_rbs_l2 ;
    auto&& a20 = Mbar_rbs_l3_jcs_c.col(0) ;
    auto&& a21 = coord.P_rbs_l3 ;
    auto&& a22 = A(a21).transpose() ;
    auto&& a23 = a16.transpose() ;
    auto&& a24 = Mbar_ground_jcs_d.col(2) ;
    auto&& a25 = a24.transpose() ;
    auto&& a26 = Mbar_rbs_l3_jcs_d.col(0) ;
    auto&& a27 = B(a0, a24) ;
    auto&& a28 = a17.transpose() ;
    auto&& a29 = B(a7, a24) ;
    auto&& a30 = Mbar_rbs_l3_jcs_d.col(1) ;

    acc_eq << 
        ((B(a0, ubar_ground_jcs_a) * a0) + (-1 * B(a1, ubar_rbs_l1_jcs_a) * a1)),
        ((a3 * a5 * B(a0, a6) * a0) + (a6.transpose() * a8 * a9 * a1) + (2 * (a10 * B(a7, a6).transpose() * a11 * a1))),
        ((a3 * a5 * B(a0, a12) * a0) + (a12.transpose() * a8 * a9 * a1) + (2 * (a10 * B(a7, a12).transpose() * a11 * a1))),
        (((-1 * derivative(config.UF_mcs_act, t, 2)) * Eigen::MatrixXd::Identity(1, 1)) + (a13.transpose() * a5 * ((std::cos(config.UF_mcs_act(t)) * (B(a0, a14))) + ((-1 * std::sin(config.UF_mcs_act(t))) * B(a0, a15))) * a0) + (((std::cos(config.UF_mcs_act(t)) * (a14.transpose() * a8)) + ((-1 * std::sin(config.UF_mcs_act(t))) * a15.transpose() * a8)) * B(a1, a13) * a1) + (2 * (((std::cos(config.UF_mcs_act(t)) * (a10 * B(a7, a14).transpose())) + ((-1 * std::sin(config.UF_mcs_act(t))) * a10 * B(a7, a15).transpose())) * B(a4, a13) * a1))),
        ((B(a1, ubar_rbs_l1_jcs_b) * a1) + (-1 * B(a16, ubar_rbs_l2_jcs_b) * a16)),
        ((B(a16, ubar_rbs_l2_jcs_c) * a16) + (-1 * B(a17, ubar_rbs_l3_jcs_c) * a17)),
        ((a18.transpose() * A(a19).transpose() * B(a17, a20) * a17) + (a20.transpose() * a22 * B(a16, a18) * a16) + (2 * (a23 * B(a19, a18).transpose() * B(a21, a20) * a17))),
        ((B(a17, ubar_rbs_l3_jcs_d) * a17) + (-1 * B(a0, ubar_ground_jcs_d) * a0)),
        ((a25 * a8 * B(a17, a26) * a17) + (a26.transpose() * a22 * a27 * a0) + (2 * (a28 * B(a21, a26).transpose() * a29 * a0))),
        ((a25 * a8 * B(a17, a30) * a17) + (a30.transpose() * a22 * a27 * a0) + (2 * (a28 * B(a21, a30).transpose() * a29 * a0))),
        Eigen::MatrixXd::Zero(3, 1),
        Eigen::MatrixXd::Zero(4, 1),
        (2 * (a1.transpose() * a1)),
        (2 * (a23 * a16)),
        (2 * (a28 * a17));
};

void Topology::eval_frc_eq()
{
    auto&& f0 = G(coord.Pd_rbs_l1) ;
    auto&& f1 = G(coord.Pd_rbs_l2) ;
    auto&& f2 = G(coord.Pd_rbs_l3) ;

    frc_eq << 
        Eigen::MatrixXd::Zero(3, 1),
        Eigen::MatrixXd::Zero(4, 1),
        F_rbs_l1_gravity,
        (8 * (f0.transpose() * config.Jbar_rbs_l1 * f0 * coord.P_rbs_l1)),
        F_rbs_l2_gravity,
        (8 * (f1.transpose() * config.Jbar_rbs_l2 * f1 * coord.P_rbs_l2)),
        F_rbs_l3_gravity,
        (8 * (f2.transpose() * config.Jbar_rbs_l3 * f2 * coord.P_rbs_l3));
};

void Topology::eval_jac_eq()
{
    auto&& j0 = Eigen::MatrixXd::Identity(3, 3) ;
    auto&& j1 = coord.P_ground ;
    auto&& j2 = Eigen::MatrixXd::Zero(1, 3) ;
    auto&& j3 = Mbar_rbs_l1_jcs_a.col(2) ;
    auto&& j4 = j3.transpose() ;
    auto&& j5 = coord.P_rbs_l1 ;
    auto&& j6 = A(j5).transpose() ;
    auto&& j7 = Mbar_ground_jcs_a.col(0) ;
    auto&& j8 = Mbar_ground_jcs_a.col(1) ;
    auto&& j9 = (-1 * j0) ;
    auto&& j10 = A(j1).transpose() ;
    auto&& j11 = B(j5, j3) ;
    auto&& j12 = Mbar_rbs_l1_jcs_a.col(0) ;
    auto&& j13 = Mbar_ground_jcs_a.col(1) ;
    auto&& j14 = Mbar_ground_jcs_a.col(0) ;
    auto&& j15 = coord.P_rbs_l2 ;
    auto&& j16 = Mbar_rbs_l3_jcs_c.col(0) ;
    auto&& j17 = coord.P_rbs_l3 ;
    auto&& j18 = A(j17).transpose() ;
    auto&& j19 = Mbar_rbs_l2_jcs_c.col(0) ;
    auto&& j20 = Mbar_ground_jcs_d.col(2) ;
    auto&& j21 = j20.transpose() ;
    auto&& j22 = Mbar_rbs_l3_jcs_d.col(0) ;
    auto&& j23 = Mbar_rbs_l3_jcs_d.col(1) ;
    auto&& j24 = B(j1, j20) ;

    jac_eq = 
        {j0,
        B(j1, ubar_ground_jcs_a),
        j9,
        (-1 * B(j5, ubar_rbs_l1_jcs_a)),
        j2,
        (j4 * j6 * B(j1, j7)),
        j2,
        (j7.transpose() * j10 * j11),
        j2,
        (j4 * j6 * B(j1, j8)),
        j2,
        (j8.transpose() * j10 * j11),
        j2,
        (j12.transpose() * j6 * ((std::cos(config.UF_mcs_act(t)) * (B(j1, j13))) + ((-1 * std::sin(config.UF_mcs_act(t))) * B(j1, j14)))),
        j2,
        (((std::cos(config.UF_mcs_act(t)) * (j13.transpose() * j10)) + ((-1 * std::sin(config.UF_mcs_act(t))) * j14.transpose() * j10)) * B(j5, j12)),
        j0,
        B(j5, ubar_rbs_l1_jcs_b),
        j9,
        (-1 * B(j15, ubar_rbs_l2_jcs_b)),
        j0,
        B(j15, ubar_rbs_l2_jcs_c),
        j9,
        (-1 * B(j17, ubar_rbs_l3_jcs_c)),
        j2,
        (j16.transpose() * j18 * B(j15, j19)),
        j2,
        (j19.transpose() * A(j15).transpose() * B(j17, j16)),
        j9,
        (-1 * B(j1, ubar_ground_jcs_d)),
        j0,
        B(j17, ubar_rbs_l3_jcs_d),
        j2,
        (j22.transpose() * j18 * j24),
        j2,
        (j21 * j10 * B(j17, j22)),
        j2,
        (j23.transpose() * j18 * j24),
        j2,
        (j21 * j10 * B(j17, j23)),
        j0,
        Eigen::MatrixXd::Zero(3, 4),
        Eigen::MatrixXd::Zero(4, 3),
        Eigen::MatrixXd::Identity(4, 4),
        j2,
        (2 * (j5.transpose())),
        j2,
        (2 * (j15.transpose())),
        j2,
        (2 * (j17.transpose()))};
};

void Topology::eval_mas_eq()
{
    auto&& m0 = (Eigen::MatrixXd::Identity(3, 3)) ;
    auto&& m1 = G(coord.P_ground) ;
    auto&& m2 = G(coord.P_rbs_l1) ;
    auto&& m3 = G(coord.P_rbs_l2) ;
    auto&& m4 = G(coord.P_rbs_l3) ;

    mas_eq = 
        {(m_ground * m0),
        (4 * (m1.transpose() * Jbar_ground * m1)),
        (config.m_rbs_l1 * m0),
        (4 * (m2.transpose() * config.Jbar_rbs_l1 * m2)),
        (config.m_rbs_l2 * m0),
        (4 * (m3.transpose() * config.Jbar_rbs_l2 * m3)),
        (config.m_rbs_l3 * m0),
        (4 * (m4.transpose() * config.Jbar_rbs_l3 * m4))};
};


void Topology::eval_reactions()
{
    //rct_expressions

    ////rct_return;
};

void Topology::eval_reactions(Eigen::Ref<SparseBlock> jacobian)
{
    // Joint Name : jcs_a
    const Eigen::MatrixXd& Jac_jcs_a = jacobian.block(0, 0, 5, 7);
    Eigen::VectorXd Q_jcs_a = -Jac_jcs_a.transpose() * coord.L_jcs_a;
    const Eigen::VectorXd& F_jcs_a = Q_jcs_a.segment(0, 3);
    Eigen::VectorXd T_jcs_a = 0.5*E(coord.P_ground) * Q_jcs_a.segment(3, 4) - skew(A(coord.P_ground)*ubar_ground_jcs_a)*F_jcs_a;

    // Joint Name : mcs_act
    const Eigen::MatrixXd& Jac_mcs_act = jacobian.block(5, 0, 1, 7);
    Eigen::VectorXd Q_mcs_act = -Jac_mcs_act.transpose() * coord.L_mcs_act;
    const Eigen::VectorXd& F_mcs_act = Q_mcs_act.segment(0, 3);
    Eigen::VectorXd T_mcs_act = 0.5*E(coord.P_ground) * Q_mcs_act.segment(3, 4);

    // Joint Name : jcs_b
    const Eigen::MatrixXd& Jac_jcs_b = jacobian.block(6, 7, 3, 7);
    Eigen::VectorXd Q_jcs_b = -Jac_jcs_b.transpose() * coord.L_jcs_b;
    const Eigen::VectorXd& F_jcs_b = Q_jcs_b.segment(0, 3);
    Eigen::VectorXd T_jcs_b = 0.5*E(coord.P_rbs_l1) * Q_jcs_b.segment(3, 4) - skew(A(coord.P_rbs_l1)*ubar_rbs_l1_jcs_b)*F_jcs_b;

    // Joint Name : jcs_c
    const Eigen::MatrixXd& Jac_jcs_c = jacobian.block(9, 14, 4, 7);
    Eigen::VectorXd Q_jcs_c = -Jac_jcs_c.transpose() * coord.L_jcs_c;
    const Eigen::VectorXd& F_jcs_c = Q_jcs_c.segment(0, 3);
    Eigen::VectorXd T_jcs_c = 0.5*E(coord.P_rbs_l2) * Q_jcs_c.segment(3, 4) - skew(A(coord.P_rbs_l2)*ubar_rbs_l2_jcs_c)*F_jcs_c;

    // Joint Name : jcs_d
    const Eigen::MatrixXd& Jac_jcs_d = jacobian.block(13, 21, 5, 7);
    Eigen::VectorXd Q_jcs_d = -Jac_jcs_d.transpose() * coord.L_jcs_d;
    const Eigen::VectorXd& F_jcs_d = Q_jcs_d.segment(0, 3);
    Eigen::VectorXd T_jcs_d = 0.5*E(coord.P_rbs_l3) * Q_jcs_d.segment(3, 4) - skew(A(coord.P_rbs_l3)*ubar_rbs_l3_jcs_d)*F_jcs_d;

    rct_eq << F_jcs_a,
        T_jcs_a,
        F_mcs_act,
        T_mcs_act,
        F_jcs_b,
        T_jcs_b,
        F_jcs_c,
        T_jcs_c,
        F_jcs_d,
        T_jcs_d;;
};