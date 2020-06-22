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
    deps = [
        "@fmt_github//:fmt",
    ],
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
