# standard library imports
import os

# getting directory of current file and specifying the directory
# where data will be saved
os.makedirs(os.path.join("model", "symenv", "data"), exist_ok=True)
#os.chdir("model")
data_dir = os.path.abspath("model/symenv/data")


# uraeus imports
from uraeus.smbd.systems import standalone_topology, configuration

# ============================================================= #
#                       Symbolic Topology
# ============================================================= #

# Creating the symbolic topology as an instance of the
# standalone_topology class
project_name = "double_wishbone_direct_acting"
sym_model = standalone_topology(project_name)

# Adding Bodies
# =============
sym_model.add_body("uca", mirror=True)
sym_model.add_body("lca", mirror=True)
sym_model.add_body("upright", mirror=True)
sym_model.add_body("upper_strut", mirror=True)
sym_model.add_body("lower_strut" ,mirror=True)
sym_model.add_body("tie_rod", mirror=True)
sym_model.add_body("hub", mirror=True)
sym_model.add_body("rack")

# Adding Joints
# =============
sym_model.add_joint.spherical("uca_upright", "rbr_uca", "rbr_upright", mirror=True)
sym_model.add_joint.spherical("lca_upright", "rbr_lca", "rbr_upright", mirror=True)
sym_model.add_joint.spherical("tie_upright", "rbr_tie_rod", "rbr_upright", mirror=True)

sym_model.add_joint.revolute("uca_chassis", "rbr_uca", "ground", mirror=True)
sym_model.add_joint.revolute("lca_chassis", "rbr_lca", "ground", mirror=True)
sym_model.add_joint.revolute("hub_bearing", "rbr_upright", "rbr_hub", mirror=True)

sym_model.add_joint.universal("strut_chassis", "rbr_upper_strut", "ground", mirror=True)
sym_model.add_joint.universal("strut_lca", "rbr_lower_strut", "rbr_lca", mirror=True)
sym_model.add_joint.universal("tie_steering", "rbr_tie_rod", "rbs_rack", mirror=True)

sym_model.add_joint.cylinderical("strut", "rbr_upper_strut", "rbr_lower_strut", mirror=True)
sym_model.add_joint.translational("rack_joint", "rbs_rack", "ground")

# Adding Actuators
# ================
sym_model.add_actuator.translational_actuator("rack_travel", "jcs_rack_joint")
sym_model.add_actuator.rotational_actuator("wheel_lock", "jcr_hub_bearing", mirror=True)
sym_model.add_actuator.absolute_locator("wheel_travel", "rbr_hub", "ground", "z", mirror=True)

# Adding Forces
# =============
sym_model.add_force.TSDA("strut", "rbr_upper_strut", "rbr_lower_strut", mirror=True)
sym_model.add_force.generic_load("tire", "rbr_hub", mirror=True)

sym_model.topology.draw_constraints_topology()

# Assembling and Saving model
sym_model.save(data_dir)
sym_model.assemble()


# ============================================================= #
#                     Symbolic Configuration
# ============================================================= #

# Symbolic configuration name.
config_name = "%s_cfg"%project_name

# Symbolic configuration instance.
sym_config = configuration(config_name, sym_model)

# Adding the desired set of UserInputs
# ====================================

# Upper Control Arm Points
# ========================
sym_config.add_point.UserInput("ucaf", mirror=True)
sym_config.add_point.UserInput("ucar", mirror=True)
sym_config.add_point.UserInput("ucao", mirror=True)

# Lower Control Arm Points
# ========================
sym_config.add_point.UserInput("lcaf", mirror=True)
sym_config.add_point.UserInput("lcar", mirror=True)
sym_config.add_point.UserInput("lcao", mirror=True)

# Tie-Rod Points
# ==============
sym_config.add_point.UserInput("tro", mirror=True)
sym_config.add_point.UserInput("tri", mirror=True)

# Spring-Damper Points
# ====================
sym_config.add_point.UserInput("strut_chassis", mirror=True)
sym_config.add_point.UserInput("strut_lca", mirror=True)
sym_config.add_point.UserInput("strut_mid", mirror=True)

# Wheel Center Points
# ===================
sym_config.add_point.UserInput("wc", mirror=True)
sym_config.add_point.UserInput("wc1", mirror=True)
sym_config.add_point.UserInput("wc2", mirror=True)

# Guiding Global Axes
# ===================
sym_config.add_vector.UserInput("x")
sym_config.add_vector.UserInput("y")
sym_config.add_vector.UserInput("z")

# Scalar Variables
# ================
sym_config.add_scalar.UserInput("strut_freelength")


# Defining Relations between original topology inputs
# and our desired UserInputs.
# ===================================================

# Defining Relations
# ==================
sym_config.add_point.Centered("strut_mid", ("hpr_strut_chassis", "hpr_strut_lca"), mirror=True)

# UCA_Upright Spherical joint
# ===========================
sym_config.add_relation.Equal_to("pt1_jcr_uca_upright", ("hpr_ucao",), mirror=True)
sym_config.add_relation.Equal_to("ax1_jcr_uca_upright", ("vcs_z",), mirror=True)

# LCA_Upright Spherical joint
# ===========================
sym_config.add_relation.Equal_to("pt1_jcr_lca_upright", ("hpr_lcao",), mirror=True)
sym_config.add_relation.Equal_to("ax1_jcr_lca_upright", ("vcs_z",), mirror=True)

# TieRod_Upright Spherical joint
# ==============================
sym_config.add_relation.Equal_to("pt1_jcr_tie_upright", ("hpr_tro",), mirror=True)
sym_config.add_relation.Equal_to("ax1_jcr_tie_upright", ("vcs_z",), mirror=True)

# Upper Control Arm Revolute Joint:
# =================================
sym_config.add_relation.Centered("pt1_jcr_uca_chassis", ("hpr_ucaf","hpr_ucar"), mirror=True)
sym_config.add_relation.Oriented("ax1_jcr_uca_chassis", ("hpr_ucaf","hpr_ucar"), mirror=True)

# Lower Control Arm Revolute Joint:
# =================================
sym_config.add_relation.Centered("pt1_jcr_lca_chassis", ("hpr_lcaf","hpr_lcar"), mirror=True)
sym_config.add_relation.Oriented("ax1_jcr_lca_chassis", ("hpr_lcaf","hpr_lcar"), mirror=True)

# Wheel Hub Revolute Joint:
# =========================
sym_config.add_relation.Equal_to("pt1_jcr_hub_bearing", ("hpr_wc",), mirror=True)
sym_config.add_relation.Equal_to("ax1_jcr_hub_bearing", ("vcs_y",), mirror=True)

# Strut-Chassis Universal Joint:
# ==============================
sym_config.add_relation.Equal_to("pt1_jcr_strut_chassis", ("hpr_strut_chassis",), mirror=True)
sym_config.add_relation.Oriented("ax1_jcr_strut_chassis", ("hpr_strut_chassis","hpr_strut_lca"), mirror=True)
sym_config.add_relation.Oriented("ax2_jcr_strut_chassis", ("hpr_strut_lca","hpr_strut_chassis"), mirror=True)

# Strut-LCA Universal Joint:
# ==========================
sym_config.add_relation.Equal_to("pt1_jcr_strut_lca", ("hpr_strut_lca",), mirror=True)
sym_config.add_relation.Oriented("ax1_jcr_strut_lca", ("hpr_strut_chassis","hpr_strut_lca"), mirror=True)
sym_config.add_relation.Oriented("ax2_jcr_strut_lca", ("hpr_strut_lca","hpr_strut_chassis"), mirror=True)

# Tie-Steer Universal Joint:
# ==========================
sym_config.add_relation.Equal_to("pt1_jcr_tie_steering", ("hpr_tri",), mirror=True)
sym_config.add_relation.Oriented("ax1_jcr_tie_steering", ("hpr_tri","hpr_tro"), mirror=True)
sym_config.add_relation.Oriented("ax2_jcr_tie_steering", ("hpr_tro","hpr_tri"), mirror=True)

# Strut Cylinderical Joint:
# =========================
sym_config.add_relation.Equal_to("pt1_jcr_strut", ("hpr_strut_mid",), mirror=True)
sym_config.add_relation.Oriented("ax1_jcr_strut", ("hpr_strut_lca","hpr_strut_chassis"), mirror=True)

# Rack Translational Joint:
# =========================
sym_config.add_relation.Centered("pt1_jcs_rack_joint", ("hpr_tri", "hpl_tri"))
sym_config.add_relation.Oriented("ax1_jcs_rack_joint", ("hpr_tri", "hpl_tri"))

# Wheel_Travel Actuation point:
# =============================
sym_config.add_relation.Equal_to("pt1_mcr_wheel_travel", ("hpr_wc",), mirror=True)


# Strut Force Element:
# ====================
sym_config.add_relation.Equal_to("pt1_far_strut", ("hpr_strut_chassis",), mirror=True)
sym_config.add_relation.Equal_to("pt2_far_strut", ("hpr_strut_lca",), mirror=True)
sym_config.add_relation.Equal_to("far_strut_FL", ("s_strut_freelength",), mirror=True)


# Tire Force Element:
# ===================
sym_config.add_relation.Equal_to("pt1_far_tire", ("hpr_wc",), mirror=True)

# ===================
# Creating Geometries
# ===================
sym_config.add_scalar.UserInput("links_ro")
sym_config.add_scalar.UserInput("strut_outer")
sym_config.add_scalar.UserInput("strut_inner")
sym_config.add_scalar.UserInput("thickness")
sym_config.add_scalar.UserInput("hub_radius")
sym_config.add_scalar.UserInput("tire_radius")
sym_config.add_scalar.UserInput("rack_radius")

# Upper Control Arm
# =================
sym_config.add_geometry.Cylinder_Geometry("uca_c1", ("hpr_ucaf", "hpr_ucao","s_links_ro"), mirror=True)
sym_config.add_geometry.Cylinder_Geometry("uca_c2", ("hpr_ucar", "hpr_ucao","s_links_ro"), mirror=True)
sym_config.add_geometry.Composite_Geometry("uca", ("gmr_uca_c1", "gmr_uca_c2"), mirror=True)
sym_config.assign_geometry_to_body("rbr_uca", "gmr_uca", mirror=True)

# Lower Control Arm
# =================
sym_config.add_geometry.Cylinder_Geometry("lca_c1", ("hpr_lcaf", "hpr_lcao","s_links_ro"), mirror=True)
sym_config.add_geometry.Cylinder_Geometry("lca_c2", ("hpr_lcar", "hpr_lcao","s_links_ro"), mirror=True)
sym_config.add_geometry.Composite_Geometry("lca", ("gmr_lca_c1", "gmr_lca_c2"), mirror=True)
sym_config.assign_geometry_to_body("rbr_lca", "gmr_lca", mirror=True)

# Wheel Upright
# =============
sym_config.add_geometry.Triangular_Prism("upright", ("hpr_ucao","hpr_wc","hpr_lcao","s_thickness"), mirror=True)
sym_config.assign_geometry_to_body("rbr_upright", "gmr_upright", mirror=True)

# Coil-Over Upper Part
# ====================
sym_config.add_geometry.Cylinder_Geometry("upper_strut", ("hpr_strut_chassis","hpr_strut_mid","s_strut_outer"), mirror=True)
sym_config.assign_geometry_to_body("rbr_upper_strut", "gmr_upper_strut", mirror=True)

# Coil-Over Lower Part
# ====================
sym_config.add_geometry.Cylinder_Geometry("lower_strut", ("hpr_strut_mid","hpr_strut_lca","s_strut_inner"), mirror=True)
sym_config.assign_geometry_to_body("rbr_lower_strut", "gmr_lower_strut", mirror=True)

# TieRod
# ======
sym_config.add_geometry.Cylinder_Geometry("tie_rod", ("hpr_tri","hpr_tro","s_links_ro"), mirror=True)
sym_config.assign_geometry_to_body("rbr_tie_rod", "gmr_tie_rod", mirror=True)

# Wheel Hub
# =========
sym_config.add_geometry.Cylinder_Geometry("hub_cyl", ("hpr_wc2","hpr_wc","s_hub_radius"), mirror=True)
sym_config.add_geometry.Cylinder_Geometry("tire", ("hpr_wc1","hpr_wc","s_tire_radius"), mirror=True)
sym_config.add_geometry.Composite_Geometry("hub", ("gmr_hub_cyl", "gmr_tire"), mirror=True)
sym_config.assign_geometry_to_body("rbr_hub", "gmr_hub", mirror=True)

# Steering Rack
# =============
sym_config.add_geometry.Cylinder_Geometry("rack", ("hpr_tri","hpl_tri","s_rack_radius"))
sym_config.assign_geometry_to_body("rbs_rack", "gms_rack", mirror=True)

sym_config.export_JSON_file(data_dir)

# ============================================================= #
#                     Code Generation
# ============================================================= #

from uraeus.nmbd.cpp.codegen import standalone_project
project = standalone_project("model")
project.create_dirs()

project.write_topology_code(sym_model)

