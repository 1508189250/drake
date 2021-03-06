# -*- python -*-
# This file contains rules for Bazel; see drake/doc/bazel.rst.

load("//tools:cpplint.bzl", "cpplint")
load("//tools:drake.bzl", "drake_cc_googletest", "drake_cc_library")

package(default_visibility = ["//visibility:public"])

drake_cc_library(
    name = "state_feedback_controller_base",
    hdrs = ["state_feedback_controller_base.h"],
    deps = [
        "//drake/systems/framework",
    ],
)

drake_cc_library(
    name = "model_based_controller_base",
    hdrs = ["model_based_controller_base.h"],
    deps = [
        ":state_feedback_controller_base",
        "//drake/multibody:rigid_body_tree",
        "//drake/multibody/parsers",
    ],
)

drake_cc_library(
    name = "gravity_compensator",
    srcs = ["gravity_compensator.cc"],
    hdrs = ["gravity_compensator.h"],
    deps = [
        "//drake/multibody:rigid_body_tree",
        "//drake/multibody/parsers",
        "//drake/systems/framework",
    ],
)

drake_cc_library(
    name = "linear_quadratic_regulator",
    srcs = ["linear_quadratic_regulator.cc"],
    hdrs = ["linear_quadratic_regulator.h"],
    deps = [
        "//drake/common:is_approx_equal_abstol",
        "//drake/math:continuous_algebraic_ricatti_equation",
        "//drake/systems/framework",
        "//drake/systems/primitives:linear_system",
    ],
)

drake_cc_library(
    name = "pid_controller",
    srcs = ["pid_controller.cc"],
    hdrs = ["pid_controller.h"],
    deps = [
        ":state_feedback_controller_base",
        "//drake/systems/framework",
        "//drake/systems/primitives:adder",
        "//drake/systems/primitives:demultiplexer",
        "//drake/systems/primitives:gain",
        "//drake/systems/primitives:integrator",
        "//drake/systems/primitives:matrix_gain",
        "//drake/systems/primitives:pass_through",
        "//drake/systems/primitives:saturation",
    ],
)

drake_cc_library(
    name = "pid_controlled_system",
    srcs = ["pid_controlled_system.cc"],
    hdrs = ["pid_controlled_system.h"],
    deps = [
        ":pid_controller",
        "//drake/systems/primitives:constant_vector_source",
    ],
)

drake_cc_library(
    name = "pid_with_gravity_compensator",
    srcs = ["pid_with_gravity_compensator.cc"],
    hdrs = ["pid_with_gravity_compensator.h"],
    deps = [
        ":gravity_compensator",
        ":model_based_controller_base",
        ":pid_controller",
    ],
)

# === test/ ===

drake_cc_googletest(
    name = "gravity_compensator_test",
    data = [
        "//drake/examples/SimpleFourBar:models",
        "//drake/examples/kuka_iiwa_arm:models",
    ],
    deps = [
        ":gravity_compensator",
        "//drake/common:eigen_matrix_compare",
    ],
)

drake_cc_googletest(
    name = "linear_quadratic_regulator_test",
    deps = [
        ":linear_quadratic_regulator",
        "//drake/common:eigen_matrix_compare",
    ],
)

drake_cc_googletest(
    name = "pid_controlled_system_test",
    deps = [
        ":pid_controlled_system",
        "//drake/common:eigen_matrix_compare",
    ],
)

drake_cc_googletest(
    name = "pid_controller_test",
    deps = [
        ":pid_controller",
        "//drake/common:eigen_matrix_compare",
    ],
)

cpplint()
