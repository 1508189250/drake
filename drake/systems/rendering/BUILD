# -*- python -*-
# This file contains rules for Bazel; see drake/doc/bazel.rst.

load("//tools:cpplint.bzl", "cpplint")
load("//tools:drake.bzl", "drake_cc_googletest", "drake_cc_library")

package(default_visibility = ["//visibility:public"])

drake_cc_library(
    name = "pose_aggregator",
    srcs = ["pose_aggregator.cc"],
    hdrs = ["pose_aggregator.h"],
    deps = [
        ":pose_bundle",
        "//drake/common",
        "//drake/common:autodiff",
        "//drake/multibody:rigid_body_tree",
        "//drake/systems/framework:leaf_system",
    ],
)

drake_cc_library(
    name = "pose_bundle",
    srcs = ["pose_bundle.cc"],
    hdrs = ["pose_bundle.h"],
    deps = [
        "//drake/common",
        "//drake/common:autodiff",
    ],
)

drake_cc_library(
    name = "drake_visualizer_client",
    srcs = ["drake_visualizer_client.cc"],
    hdrs = ["drake_visualizer_client.h"],
    deps = [
        "//drake/lcmtypes:viewer",
        "//drake/math:geometric_transform",
        "//drake/multibody/shapes",
        "@eigen//:eigen",
    ],
)

drake_cc_googletest(
    name = "pose_aggregator_test",
    deps = [
        ":pose_aggregator",
        "//drake/common:eigen_matrix_compare",
    ],
)

drake_cc_googletest(
    name = "drake_visualizer_client_test",
    data = [
        "//drake/multibody/shapes:test_models",
    ],
    deps = [
        ":drake_visualizer_client",
        "//drake/common:drake_path",
        "//drake/lcmtypes:viewer",
    ],
)

cpplint()
