load("@bazel_tools//tools/build_defs/cc:action_names.bzl","ACTION_NAMES")
load(
    "@bazel_tools//tools/cpp:cc_toolchain_config_lib.bzl",
    "feature",
    "flag_group",
    "flag_set",
    "tool_path",
)

all_link_actions = [
    ACTION_NAMES.cpp_link_executable,
    ACTION_NAMES.cpp_link_dynamic_library,
    ACTION_NAMES.cpp_link_nodeps_dynamic_library,
]

def _impl(ctx):
    tool_paths = [
        tool_path(
            name = "gcc",
            path = "clang"
        ),
        tool_path(
            name = "cpp",
            path = "cpp"
        ),
        tool_path(
            name = "ld",
            path = "ld"
        ),
        tool_path(
            name = "ar",
            path = "ar"
        ),
        tool_path(
            name = "nm",
            path = "nm"
        ),
        tool_path(
            name = "objdump",
            path = "objdump"
        ),
        tool_path(
            name = "strip",
            path = "strip"
        ),
    ]

    features = [
        feature(
            name = "default_linker_flags",
            enabled = True,
            flag_sets = [
                flag_set(
                    actions = all_link_actions,
                    flag_groups = ([
                        flag_group(
                            flags = [
                                "-L${LOCALBASE}/lib",
                                "-lc++",
                                "-lc++abi",
                                "-lm"
                            ],
                        ),
                    ]),
                ),
            ],
        ),
    ]

    return cc_common.create_cc_toolchain_config_info(
        ctx = ctx,
        features = features,
        cxx_builtin_include_directories = [
            "/usr/lib/clang/22/include",
            "${LOCALBASE}/include",
            "/usr/include",
            "${X11BASE}/include",
        ],
        toolchain_identifier = "openbsd_toolchain",
        host_system_name = "openbsd",
        target_system_name = "openbsd",
        target_cpu = "unknown",
        target_libc = "unknown",
        compiler = "clang",
        abi_version = "unknown",
        abi_libc_version = "unknown",
        tool_paths = tool_paths,
    )

cc_toolchain_config = rule(
    implementation = _impl,
    attrs = {},
    provides = [CcToolchainConfigInfo],
)

