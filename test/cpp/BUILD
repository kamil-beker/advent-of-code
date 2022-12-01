cc_library(
    name = "common",
    srcs = ["common.h"],
    visibility = ["//test/cpp:__subpackages__"],
)

cc_test(
    name = "test_day_01",
    srcs = ["test_day_01.cc"],
    data = ["//data:day_01"],
    deps = [
        ":common",
        "//src/cpp:day_01",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
