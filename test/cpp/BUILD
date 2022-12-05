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

cc_test(
    name = "test_day_02",
    srcs = ["test_day_02.cc"],
    data = ["//data:day_02"],
    deps = [
        ":common",
        "//src/cpp:day_02",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_day_03",
    srcs = ["test_day_03.cc"],
    data = ["//data:day_03"],
    deps = [
        ":common",
        "//src/cpp:day_03",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_day_04",
    srcs = ["test_day_04.cc"],
    data = ["//data:day_04"],
    deps = [
        ":common",
        "//src/cpp:day_04",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_day_05",
    srcs = ["test_day_05.cc"],
    data = ["//data:day_05"],
    deps = [
        ":common",
        "//src/cpp:day_05",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
