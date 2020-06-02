
#include "spatial_fourbar.hpp"


void Configuration::constructFromJSON(std::string fileName)
{
    std::cout << "Constructing Configuration Inputs" << std::endl;
    ConfigInputs.constructFromJSON(fileName);

    std::cout << "Populating Configuration Arguments!" << std::endl;
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
    this-> R_ground << 0, 0, 0 ;
    this-> P_ground << 1, 0, 0, 0 ;

    this-> q.resize(28);
    this-> q << 
        this->R_ground, 
        this->P_ground, 
        this->R_rbs_l1, 
        this->P_rbs_l1, 
        this->R_rbs_l2, 
        this->P_rbs_l2, 
        this->R_rbs_l3, 
        this->P_rbs_l3;

    this-> qd.resize(28);
    this-> qd << 
        this->Rd_ground, 
        this->Pd_ground, 
        this->Rd_rbs_l1, 
        this->Pd_rbs_l1, 
        this->Rd_rbs_l2, 
        this->Pd_rbs_l2, 
        this->Rd_rbs_l3, 
        this->Pd_rbs_l3;
};



Topology::Topology(){};
Topology::Topology(std::string prefix = "")
{
    this-> prefix = prefix;

    q0.resize(n);
    
    this-> pos_eq.resize(this-> nc);
    this-> vel_eq.resize(this-> nc);
    this-> acc_eq.resize(this-> nc);

    this-> jac_eq.reserve(this-> jac_rows.size());

    this-> indicies_map[prefix + "ground"] = 0;
    this-> indicies_map[prefix + "rbs_l1"] = 1;
    this-> indicies_map[prefix + "rbs_l2"] = 2;
    this-> indicies_map[prefix + "rbs_l3"] = 3;
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

    this-> jac_rows.resize(50);
    this-> jac_rows << 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14;
    this-> jac_rows += (rows_offset * Eigen::VectorXd::Ones(this ->jac_rows.size()) );

    this-> jac_cols.resize(50);
    this-> jac_cols << 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l1*2, 
        this-> rbs_l1*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l1*2, 
        this-> rbs_l1*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l1*2, 
        this-> rbs_l1*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l1*2, 
        this-> rbs_l1*2+1, 
        this-> rbs_l1*2, 
        this-> rbs_l1*2+1, 
        this-> rbs_l2*2, 
        this-> rbs_l2*2+1, 
        this-> rbs_l2*2, 
        this-> rbs_l2*2+1, 
        this-> rbs_l3*2, 
        this-> rbs_l3*2+1, 
        this-> rbs_l2*2, 
        this-> rbs_l2*2+1, 
        this-> rbs_l3*2, 
        this-> rbs_l3*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l3*2, 
        this-> rbs_l3*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l3*2, 
        this-> rbs_l3*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l3*2, 
        this-> rbs_l3*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> ground*2, 
        this-> ground*2+1, 
        this-> rbs_l1*2, 
        this-> rbs_l1*2+1, 
        this-> rbs_l2*2, 
        this-> rbs_l2*2+1, 
        this-> rbs_l3*2, 
        this-> rbs_l3*2+1;
};


void Topology::set_initial_states()
{
    set_gen_coordinates(this-> config.q);
    set_gen_velocities(this-> config.qd);
    q0 << config.q;
};


void Topology::set_mapping(Dict_SI& indicies_map, Dict_SS& interface_map)
{
    auto& p = this-> prefix;

    this-> ground = indicies_map[p+"ground"];
    this-> rbs_l1 = indicies_map[p+"rbs_l1"];
    this-> rbs_l2 = indicies_map[p+"rbs_l2"];
    this-> rbs_l3 = indicies_map[p+"rbs_l3"];
};




void Topology::set_gen_coordinates(Eigen::Ref<Eigen::VectorXd> q)
{
    this->q = q;
};

void Topology::set_gen_velocities(Eigen::Ref<Eigen::VectorXd> qd)
{
    this->qd = qd;
 };

void Topology::set_gen_accelerations(Eigen::Ref<Eigen::VectorXd> qdd)
{
    this->qdd = qdd;
};



void Topology::eval_constants()
{
    auto& config = this-> config;

    this-> R_ground << 0, 0, 0 ;
    this-> P_ground << 1, 0, 0, 0 ;
    this-> Pg_ground << 1, 0, 0, 0 ;
    this-> m_ground = 1.0 ;
    this-> Jbar_ground << 1, 0, 0, 0, 1, 0, 0, 0, 1 ;
    this-> F_rbs_l1_gravity << 0, 0, -9810.0*config.m_rbs_l1 ;
    this-> F_rbs_l2_gravity << 0, 0, -9810.0*config.m_rbs_l2 ;
    this-> F_rbs_l3_gravity << 0, 0, -9810.0*config.m_rbs_l3 ;

    this-> Mbar_ground_jcs_a << A(this-> P_ground).transpose() * triad(config.ax1_jcs_a) ;
    this-> Mbar_rbs_l1_jcs_a << A(config.P_rbs_l1).transpose() * triad(config.ax1_jcs_a) ;
    this-> ubar_ground_jcs_a << (A(this-> P_ground).transpose() * config.pt1_jcs_a + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
    this-> ubar_rbs_l1_jcs_a << (A(config.P_rbs_l1).transpose() * config.pt1_jcs_a + -1 * A(config.P_rbs_l1).transpose() * config.R_rbs_l1) ;
    this-> Mbar_ground_jcs_a << A(this-> P_ground).transpose() * triad(config.ax1_jcs_a) ;
    this-> Mbar_rbs_l1_jcs_a << A(config.P_rbs_l1).transpose() * triad(config.ax1_jcs_a) ;
    this-> Mbar_rbs_l1_jcs_b << A(config.P_rbs_l1).transpose() * triad(config.ax1_jcs_b) ;
    this-> Mbar_rbs_l2_jcs_b << A(config.P_rbs_l2).transpose() * triad(config.ax1_jcs_b) ;
    this-> ubar_rbs_l1_jcs_b << (A(config.P_rbs_l1).transpose() * config.pt1_jcs_b + -1 * A(config.P_rbs_l1).transpose() * config.R_rbs_l1) ;
    this-> ubar_rbs_l2_jcs_b << (A(config.P_rbs_l2).transpose() * config.pt1_jcs_b + -1 * A(config.P_rbs_l2).transpose() * config.R_rbs_l2) ;
    this-> Mbar_rbs_l2_jcs_c << A(config.P_rbs_l2).transpose() * triad(config.ax1_jcs_c) ;
    this-> Mbar_rbs_l3_jcs_c << A(config.P_rbs_l3).transpose() * triad(config.ax2_jcs_c, triad(config.ax1_jcs_c).block(0,1, 3,1)) ;
    this-> ubar_rbs_l2_jcs_c << (A(config.P_rbs_l2).transpose() * config.pt1_jcs_c + -1 * A(config.P_rbs_l2).transpose() * config.R_rbs_l2) ;
    this-> ubar_rbs_l3_jcs_c << (A(config.P_rbs_l3).transpose() * config.pt1_jcs_c + -1 * A(config.P_rbs_l3).transpose() * config.R_rbs_l3) ;
    this-> Mbar_rbs_l3_jcs_d << A(config.P_rbs_l3).transpose() * triad(config.ax1_jcs_d) ;
    this-> Mbar_ground_jcs_d << A(this-> P_ground).transpose() * triad(config.ax1_jcs_d) ;
    this-> ubar_rbs_l3_jcs_d << (A(config.P_rbs_l3).transpose() * config.pt1_jcs_d + -1 * A(config.P_rbs_l3).transpose() * config.R_rbs_l3) ;
    this-> ubar_ground_jcs_d << (A(this-> P_ground).transpose() * config.pt1_jcs_d + -1 * A(this-> P_ground).transpose() * this-> R_ground) ;
};

void Topology::eval_pos_eq()
{
    auto& config = this-> config;
    auto& t = this-> t;

    auto& x0 = this-> R_ground ;
    auto& x1 = this-> R_rbs_l1 ;
    auto& x2 = this-> P_ground ;
    auto&& x3 = A(x2) ;
    auto& x4 = this-> P_rbs_l1 ;
    auto&& x5 = A(x4) ;
    auto&& x6 = x3.transpose() ;
    auto&& x7 = this-> Mbar_rbs_l1_jcs_a.col(2) ;
    auto&& x8 = this-> Mbar_rbs_l1_jcs_a.col(0) ;
    auto& x9 = this-> R_rbs_l2 ;
    auto& x10 = this-> P_rbs_l2 ;
    auto&& x11 = A(x10) ;
    auto& x12 = this-> R_rbs_l3 ;
    auto& x13 = this-> P_rbs_l3 ;
    auto&& x14 = A(x13) ;
    auto&& x15 = x14.transpose() ;
    auto&& x16 = this-> Mbar_ground_jcs_d.col(2) ;
    auto& x17 = -1 * Eigen::MatrixXd::Identity(1, 1) ;

    pos_eq << 
        (x0 + -1 * x1 + x3 * this-> ubar_ground_jcs_a + -1 * x5 * this-> ubar_rbs_l1_jcs_a),
        this-> Mbar_ground_jcs_a.col(0).transpose() * x6 * x5 * x7,
        this-> Mbar_ground_jcs_a.col(1).transpose() * x6 * x5 * x7,
        (std::cos(config.UF_mcs_act(t)) * this-> Mbar_ground_jcs_a.col(1).transpose() * x6 * x5 * x8 + -1 * std::sin(config.UF_mcs_act(t)) * this-> Mbar_ground_jcs_a.col(0).transpose() * x6 * x5 * x8),
        (x1 + -1 * x9 + x5 * this-> ubar_rbs_l1_jcs_b + -1 * x11 * this-> ubar_rbs_l2_jcs_b),
        (x9 + -1 * x12 + x11 * this-> ubar_rbs_l2_jcs_c + -1 * x14 * this-> ubar_rbs_l3_jcs_c),
        this-> Mbar_rbs_l2_jcs_c.col(0).transpose() * x11.transpose() * x14 * this-> Mbar_rbs_l3_jcs_c.col(0),
        (x12 + -1 * x0 + x14 * this-> ubar_rbs_l3_jcs_d + -1 * x3 * this-> ubar_ground_jcs_d),
        this-> Mbar_rbs_l3_jcs_d.col(0).transpose() * x15 * x3 * x16,
        this-> Mbar_rbs_l3_jcs_d.col(1).transpose() * x15 * x3 * x16,
        x0,
        (x2 + -1 * this-> Pg_ground),
        (x17 + x4.transpose() * x4),
        (x17 + x10.transpose() * x10),
        (x17 + x13.transpose() * x13);
};

void Topology::eval_vel_eq()
{
    auto& config = this-> config;
    auto& t = this-> t;

    Eigen::Vector3d v0 = Eigen::MatrixXd::Zero(3, 1) ;
    Eigen::Matrix<double, 1, 1> v1 = Eigen::MatrixXd::Zero(1, 1) ;

    this-> vel_eq << 
        v0,
        v1,
        v1,
        (v1 + -1 * derivative(config.UF_mcs_act, t, 1) * Eigen::MatrixXd::Identity(1, 1)),
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
    auto& config = this-> config;
    auto& t = this-> t;

    auto& a0 = this-> Pd_ground ;
    auto& a1 = this-> Pd_rbs_l1 ;
    auto&& a2 = this-> Mbar_ground_jcs_a.col(0) ;
    auto& a3 = this-> P_ground ;
    auto&& a4 = A(a3).transpose() ;
    auto&& a5 = this-> Mbar_rbs_l1_jcs_a.col(2) ;
    auto&& a6 = B(a1, a5) ;
    auto&& a7 = a5.transpose() ;
    auto& a8 = this-> P_rbs_l1 ;
    auto&& a9 = A(a8).transpose() ;
    auto& a10 = a0.transpose() ;
    auto&& a11 = B(a8, a5) ;
    auto&& a12 = this-> Mbar_ground_jcs_a.col(1) ;
    auto&& a13 = this-> Mbar_rbs_l1_jcs_a.col(0) ;
    auto&& a14 = this-> Mbar_ground_jcs_a.col(1) ;
    auto&& a15 = this-> Mbar_ground_jcs_a.col(0) ;
    auto& a16 = this-> Pd_rbs_l2 ;
    auto& a17 = this-> Pd_rbs_l3 ;
    auto&& a18 = this-> Mbar_rbs_l2_jcs_c.col(0) ;
    auto& a19 = this-> P_rbs_l2 ;
    auto&& a20 = this-> Mbar_rbs_l3_jcs_c.col(0) ;
    auto& a21 = this-> P_rbs_l3 ;
    auto&& a22 = A(a21).transpose() ;
    auto&& a23 = a16.transpose() ;
    auto&& a24 = this-> Mbar_ground_jcs_d.col(2) ;
    auto&& a25 = a24.transpose() ;
    auto&& a26 = this-> Mbar_rbs_l3_jcs_d.col(0) ;
    auto&& a27 = B(a0, a24) ;
    auto&& a28 = a17.transpose() ;
    auto&& a29 = B(a3, a24) ;
    auto&& a30 = this-> Mbar_rbs_l3_jcs_d.col(1) ;

    this-> acc_eq << 
        (B(a0, this-> ubar_ground_jcs_a) * a0 + -1 * B(a1, this-> ubar_rbs_l1_jcs_a) * a1),
        (a2.transpose() * a4 * a6 * a1 + a7 * a9 * B(a0, a2) * a0 + 2 * a10 * B(a3, a2).transpose() * a11 * a1),
        (a12.transpose() * a4 * a6 * a1 + a7 * a9 * B(a0, a12) * a0 + 2 * a10 * B(a3, a12).transpose() * a11 * a1),
        (-1 * derivative(config.UF_mcs_act, t, 2) * Eigen::MatrixXd::Identity(1, 1) + a13.transpose() * a9 * (std::cos(config.UF_mcs_act(t)) * B(a0, a14) + -1 * std::sin(config.UF_mcs_act(t)) * B(a0, a15)) * a0 + (std::cos(config.UF_mcs_act(t)) * a14.transpose() * a4 + -1 * std::sin(config.UF_mcs_act(t)) * a15.transpose() * a4) * B(a1, a13) * a1 + 2 * (std::cos(config.UF_mcs_act(t)) * a10 * B(a3, a14).transpose() + -1 * std::sin(config.UF_mcs_act(t)) * a10 * B(a3, a15).transpose()) * B(a8, a13) * a1),
        (B(a1, this-> ubar_rbs_l1_jcs_b) * a1 + -1 * B(a16, this-> ubar_rbs_l2_jcs_b) * a16),
        (B(a16, this-> ubar_rbs_l2_jcs_c) * a16 + -1 * B(a17, this-> ubar_rbs_l3_jcs_c) * a17),
        (a18.transpose() * A(a19).transpose() * B(a17, a20) * a17 + a20.transpose() * a22 * B(a16, a18) * a16 + 2 * a23 * B(a19, a18).transpose() * B(a21, a20) * a17),
        (B(a17, this-> ubar_rbs_l3_jcs_d) * a17 + -1 * B(a0, this-> ubar_ground_jcs_d) * a0),
        (a25 * a4 * B(a17, a26) * a17 + a26.transpose() * a22 * a27 * a0 + 2 * a28 * B(a21, a26).transpose() * a29 * a0),
        (a25 * a4 * B(a17, a30) * a17 + a30.transpose() * a22 * a27 * a0 + 2 * a28 * B(a21, a30).transpose() * a29 * a0),
        Eigen::MatrixXd::Zero(3, 1),
        Eigen::MatrixXd::Zero(4, 1),
        2 * a1.transpose() * a1,
        2 * a23 * a16,
        2 * a28 * a17;
};

void Topology::eval_jac_eq()
{
    auto& config = this-> config;
    auto& t = this-> t;

    auto& j0 = Eigen::MatrixXd::Identity(3, 3) ;
    auto& j1 = this-> P_ground ;
    auto& j2 = Eigen::MatrixXd::Zero(1, 3) ;
    auto&& j3 = this-> Mbar_rbs_l1_jcs_a.col(2) ;
    auto&& j4 = j3.transpose() ;
    auto& j5 = this-> P_rbs_l1 ;
    auto&& j6 = A(j5).transpose() ;
    auto&& j7 = this-> Mbar_ground_jcs_a.col(0) ;
    auto&& j8 = this-> Mbar_ground_jcs_a.col(1) ;
    auto& j9 = -1 * j0 ;
    auto&& j10 = A(j1).transpose() ;
    auto&& j11 = B(j5, j3) ;
    auto&& j12 = this-> Mbar_rbs_l1_jcs_a.col(0) ;
    auto&& j13 = this-> Mbar_ground_jcs_a.col(1) ;
    auto&& j14 = this-> Mbar_ground_jcs_a.col(0) ;
    auto& j15 = this-> P_rbs_l2 ;
    auto&& j16 = this-> Mbar_rbs_l3_jcs_c.col(0) ;
    auto& j17 = this-> P_rbs_l3 ;
    auto&& j18 = A(j17).transpose() ;
    auto&& j19 = this-> Mbar_rbs_l2_jcs_c.col(0) ;
    auto&& j20 = this-> Mbar_ground_jcs_d.col(2) ;
    auto&& j21 = j20.transpose() ;
    auto&& j22 = this-> Mbar_rbs_l3_jcs_d.col(0) ;
    auto&& j23 = this-> Mbar_rbs_l3_jcs_d.col(1) ;
    auto&& j24 = B(j1, j20) ;

    this-> jac_eq = 
        {j0,
        B(j1, this-> ubar_ground_jcs_a),
        j9,
        -1 * B(j5, this-> ubar_rbs_l1_jcs_a),
        j2,
        j4 * j6 * B(j1, j7),
        j2,
        j7.transpose() * j10 * j11,
        j2,
        j4 * j6 * B(j1, j8),
        j2,
        j8.transpose() * j10 * j11,
        j2,
        j12.transpose() * j6 * (std::cos(config.UF_mcs_act(t)) * B(j1, j13) + -1 * std::sin(config.UF_mcs_act(t)) * B(j1, j14)),
        j2,
        (std::cos(config.UF_mcs_act(t)) * j13.transpose() * j10 + -1 * std::sin(config.UF_mcs_act(t)) * j14.transpose() * j10) * B(j5, j12),
        j0,
        B(j5, this-> ubar_rbs_l1_jcs_b),
        j9,
        -1 * B(j15, this-> ubar_rbs_l2_jcs_b),
        j0,
        B(j15, this-> ubar_rbs_l2_jcs_c),
        j9,
        -1 * B(j17, this-> ubar_rbs_l3_jcs_c),
        j2,
        j16.transpose() * j18 * B(j15, j19),
        j2,
        j19.transpose() * A(j15).transpose() * B(j17, j16),
        j9,
        -1 * B(j1, this-> ubar_ground_jcs_d),
        j0,
        B(j17, this-> ubar_rbs_l3_jcs_d),
        j2,
        j22.transpose() * j18 * j24,
        j2,
        j21 * j10 * B(j17, j22),
        j2,
        j23.transpose() * j18 * j24,
        j2,
        j21 * j10 * B(j17, j23),
        j0,
        Eigen::MatrixXd::Zero(3, 4),
        Eigen::MatrixXd::Zero(4, 3),
        Eigen::MatrixXd::Identity(4, 4),
        j2,
        2 * j5.transpose(),
        j2,
        2 * j15.transpose(),
        j2,
        2 * j17.transpose()};
};


