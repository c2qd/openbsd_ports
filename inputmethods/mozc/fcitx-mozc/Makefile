COMMENT =						Fcitx5 input method module for Mozc

HOMEPAGE =						https://github.com/fcitx/mozc

GH_ACCOUNT =					fcitx
GH_PROJECT =					mozc
GH_COMMIT =						4d5f74412c30bf82325730c77c87d9ee2d4807bb

VERSION =						3.34.6239.20260826
REVISION =						0
DISTNAME =						fcitx-mozc-${VERSION}

ONLY_FOR_ARCHS =				amd64 arm64

CATEGORIES=						inputmethods japanese

MAINTAINER =					c2qd

# BSD-3-Clause + LGPL-2.1 or later(Part of the code in src/unix/fcitx5)
PERMIT_PACKAGE =				Yes

EXTRACT_ONLY =					fcitx-mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								${MODBAZEL_BCR_DISTFILE}

BUILD_DEPENDS +=				devel/gettext,-tools devel/protobuf

LIB_DEPENDS +=					devel/abseil-cpp devel/protobuf inputmethods/fcitx

RUN_DEPENDS +=					inputmethods/mozc/mozc

WANTLIB +=						${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Utils
WANTLIB +=						absl_base absl_borrowed_fixup_buffer absl_city absl_civil_time
WANTLIB +=						absl_cord absl_cord_internal absl_cordz_functions absl_cordz_handle
WANTLIB +=						absl_cordz_info absl_crc32c absl_crc_cord_state absl_crc_cpu_detect
WANTLIB +=						absl_crc_internal absl_debugging_internal absl_decode_rust_punycode
WANTLIB +=						absl_demangle_internal absl_demangle_rust absl_examine_stack
WANTLIB +=						absl_exponential_biased absl_flags_commandlineflag
WANTLIB +=						absl_flags_commandlineflag_internal absl_flags_config
WANTLIB +=						absl_flags_internal absl_flags_marshalling absl_flags_parse
WANTLIB +=						absl_flags_private_handle_accessor absl_flags_program_name
WANTLIB +=						absl_flags_reflection absl_flags_usage absl_flags_usage_internal
WANTLIB +=						absl_graphcycles_internal absl_hash absl_hashtablez_sampler
WANTLIB +=						absl_int128 absl_kernel_timeout_internal absl_leak_check
WANTLIB +=						absl_log_entry absl_log_flags absl_log_globals absl_log_initialize
WANTLIB +=						absl_log_internal_check_op absl_log_internal_conditions
WANTLIB +=						absl_log_internal_fnmatch absl_log_internal_format
WANTLIB +=						absl_log_internal_globals absl_log_internal_log_sink_set
WANTLIB +=						absl_log_internal_message absl_log_internal_nullguard
WANTLIB +=						absl_log_internal_proto absl_log_internal_structured_proto
WANTLIB +=						absl_log_severity absl_log_sink absl_malloc_internal
WANTLIB +=						absl_random_distributions absl_random_internal_entropy_pool
WANTLIB +=						absl_random_internal_platform absl_random_internal_randen
WANTLIB +=						absl_random_internal_randen_hwaes absl_random_internal_randen_hwaes_impl
WANTLIB +=						absl_random_internal_randen_slow absl_random_internal_seed_material
WANTLIB +=						absl_random_seed_gen_exception absl_random_seed_sequences
WANTLIB +=						absl_raw_hash_set absl_raw_logging_internal absl_spinlock_wait
WANTLIB +=						absl_stacktrace absl_status absl_statusor absl_str_format_internal
WANTLIB +=						absl_strerror absl_strings absl_strings_internal absl_symbolize
WANTLIB +=						absl_synchronization absl_throw_delegate absl_time
WANTLIB +=						absl_time_zone absl_tracing_internal absl_utf8_for_code_point
WANTLIB +=						absl_vlog_config_internal m protobuf

COMPILER =						base-clang

ALL_TARGET =					unix/fcitx5:fcitx5-mozc.so

NO_TEST =						Yes								

L10N_LANGS =					ca da de fr he ja ka ko ru tr vi zh_CN zh_TW

post-extract:
	cp ${FILESDIR}/rules_cc_bsd_cc_toolchain_config.bzl.patch \
		${FILESDIR}/rules_cc_unix_cc_toolchain_config.bzl.patch \
		${FILESDIR}/rules_go_go_private_sdk.bzl.patch \
		${WRKSRC}/bazel
	cp -Rp ${FILESDIR}/third_party ${WRKSRC}

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}
	${SUBST_CMD} -DCC=${CC} -DLD=${LD} -DWRKDIR=${WRKDIR} \
		${WRKSRC}/bazel/rules_cc_bsd_cc_toolchain_config.bzl.patch

pre-install:
	cd ${WRKSRC} && msgfmt --xml -d unix/fcitx5/po/ \
		--template unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml.in \
		-o unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml
.for lang in ${L10N_LANGS}
	msgfmt ${WRKSRC}/unix/fcitx5/po/${lang}.po \
		-o ${WRKSRC}/unix/fcitx5/po/${lang}.mo
.endfor

do-install:
	${INSTALL_PROGRAM_DIR} "${PREFIX}/lib/fcitx5"
	${INSTALL_PROGRAM} "${WRKSRC}/bazel-bin/unix/fcitx5/fcitx5-mozc.so" \
		"${PREFIX}/lib/fcitx5/fcitx5-mozc.so"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5/addon"
	${INSTALL_DATA} "${WRKSRC}/unix/fcitx5/mozc-addon.conf" \
		"${PREFIX}/share/fcitx5/addon/mozc.conf"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5/inputmethod"
	${INSTALL_DATA} "${WRKSRC}/unix/fcitx5/mozc.conf" \
		"${PREFIX}/share/fcitx5/inputmethod/mozc.conf"
	${INSTALL_DATA_DIR} "${PREFIX}/share/metainfo"
	${INSTALL_DATA} "${WRKSRC}/unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml" \
		"${PREFIX}/share/metainfo/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml"
.for lang in ${L10N_LANGS}
	${INSTALL_DATA_DIR} "${PREFIX}/share/locale/${lang}/LC_MESSAGES"
	${INSTALL_DATA} "${WRKSRC}/unix/fcitx5/po/${lang}.mo" \
		"${PREFIX}/share/locale/${lang}/LC_MESSAGES/fcitx5-mozc.mo"
.endfor
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/128x128/apps"
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/32x32/apps"
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/48x48/apps"
	${INSTALL_DATA} "${WRKSRC}/data/images/product_icon_32bpp-128.png" \
		"${PREFIX}/share/icons/hicolor/128x128/apps/org.fcitx.Fcitx5.fcitx_mozc.png"
	${INSTALL_DATA} "${WRKSRC}/data/images/unix/ime_product_icon_opensource-32.png" \
		"${PREFIX}/share/icons/hicolor/32x32/apps/org.fcitx.Fcitx5.fcitx_mozc.png"
	ln -sf org.fcitx.Fcitx5.fcitx_mozc.png \
		"${PREFIX}/share/icons/hicolor/128x128/apps/fcitx_mozc.png"
	ln -sf org.fcitx.Fcitx5.fcitx_mozc.png \
		"${PREFIX}/share/icons/hicolor/32x32/apps/fcitx_mozc.png"
.for icon in \
	ui-alpha_full ui-alpha_half ui-direct ui-hiragana ui-katakana_full \
	ui-katakana_half ui-dictionary ui-properties ui-tool
	${INSTALL_DATA} "${WRKDIST}/scripts/icons/${icon}.png" \
		"${PREFIX}/share/icons/hicolor/48x48/apps/org.fcitx.Fcitx5.fcitx_mozc_${icon:S/ui-//}.png"
	ln -sf "org.fcitx.Fcitx5.fcitx_mozc_${icon:S/ui-//}.png" \
		"${PREFIX}/share/icons/hicolor/48x48/apps/fcitx_mozc_${icon:S/ui-//}.png"
.endfor

post-install:
	cd ${WRKSRC} && rm unix/fcitx5/po/*.mo

.include <bsd.port.mk>
