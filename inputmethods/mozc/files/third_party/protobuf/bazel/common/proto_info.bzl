ProtoInfo = provider(
    doc = "Compatibility ProtoInfo provider.",
    fields = {
        "direct_sources": "Direct .proto source files.",
        "transitive_sources": "Transitive .proto source files.",
        "direct_descriptor_set": "Descriptor set for direct sources.",
        "transitive_descriptor_sets": "Transitive descriptor sets.",
        "proto_source_root": "Proto source root.",
        "transitive_proto_path": "Transitive proto paths.",
        "check_deps_sources": "Sources used for dependency checking.",
        "allow_exports": "Allowed export targets.",
        "transitive_extension_declarations": "Transitive extension declarations.",
    },
)
