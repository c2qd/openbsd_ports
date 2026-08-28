load("@rules_cc//cc:defs.bzl", "cc_library")

def cc_proto_library(name, deps = [], **kwargs):
    pkg = native.package_name()
    lib = "_{}_pb".format(pkg.replace("/", "_"))

    if not native.existing_rule(lib):
        protos = native.glob(["*.proto"])
        outs = [p[:-len(".proto")] + ext for p in protos for ext in (".pb.cc", ".pb.h")]

        native.genrule(
            name = lib + "_gen",
            srcs = protos,
            outs = outs,
            cmd = "${LOCALBASE}/bin/protoc -I. --cpp_out=$(GENDIR) " +
                  " ".join([pkg + "/" + p for p in protos]),
        )
        cc_library(
            name = lib,
            srcs = [o for o in outs if o.endswith(".cc")],
            hdrs = [o for o in outs if o.endswith(".h")],
            copts = ["-I$(GENDIR)"],
            deps = ["@com_google_protobuf//:protobuf"],
            visibility = ["//visibility:public"],
        )

    native.alias(name = name, actual = lib, visibility = ["//visibility:public"])
