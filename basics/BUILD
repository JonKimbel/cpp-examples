cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
)

cc_binary(
    name = "primitive-types",
    srcs = ["primitive-types.cc"],
    deps = [
        "@fmt_github//:fmt",
    ],
)

cc_binary(
    name = "basic-structure",
    srcs = ["basic-structure.cc"],
)

cc_binary(
    name = "class-example",
    srcs = ["class-example.cc"],
    deps = [
        ":class-example-other-class",
    ]
)

cc_library(
    name = "class-example-other-class",
    srcs = ["class-example-other-class.cc"],
    hdrs = ["class-example-other-class.h"],
)

cc_binary(
    name = "vector-example",
    srcs = ["vector-example.cc"],
    deps = [
        "@fmt_github//:fmt",
    ]
)

cc_binary(
    name = "pointers",
    srcs = ["pointers.cc"],
    deps = [
        "@fmt_github//:fmt",
    ]
)

cc_binary(
    name = "struct-example",
    srcs = ["struct-example.cc"],
    deps = [
        "@fmt_github//:fmt",
    ]
)

cc_binary(
    name = "templates",
    srcs = ["templates.cc"],
    deps = [
        "@fmt_github//:fmt",
    ],
)

cc_binary(
    name = "macros",
    srcs = ["macros.cc"],
    deps = [
        "@fmt_github//:fmt",
    ],
)

cc_binary(
    name = "inlining",
    srcs = ["inlining.cc"],
    deps = [
        "@fmt_github//:fmt",
    ],
)

cc_binary(
    name = "function-pointers",
    srcs = ["function-pointers.cc"],
    deps = [
        "@fmt_github//:fmt",
    ],
)

cc_binary(
    name = "inheritance",
    srcs = ["inheritance.cc"],
    deps = [
        "@fmt_github//:fmt",
        ":base-class",
        ":parent-class",
        ":child-class",
    ],
)

cc_library(
    name = "base-class",
    hdrs = ["base-class.h"],
)

cc_library(
    name = "parent-class",
    hdrs = ["parent-class.h"],
    deps = [
        ":base-class",
    ],
)

cc_library(
    name = "child-class",
    hdrs = ["child-class.h"],
    deps = [
        ":parent-class",
    ],
)

cc_binary(
    name = "friend-functions",
    srcs = ["friend-functions.cc"],
    deps = [
        "@fmt_github//:fmt",
    ],
)
