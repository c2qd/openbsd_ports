COMMENT-main =					Japanese Input Method Editor
COMMENT-tool =					GUI configuration tool for Mozc
COMMENT-fcitx =					Fcitx5 addon for Mozc

HOMEPAGE =						https://github.com/google/mozc
HOMEPAGE-fcitx =				https://github.com/fcitx/mozc

VERSION =						3.34.6239.20260814
DISTNAME =						mozc-${VERSION}

FULLPKGNAME-tool =				mozc-tool-${VERSION}
FULLPKGNAME-fcitx =				fcitx-mozc-${VERSION}
FULLPKGPATH-tool =				${PKGPATH},-tool
FULLPKGPATH-fcitx =				${PKGPATH},-fcitx

DIST_SUBDIR =					mozc

ONLY_FOR_ARCHS =				amd64 arm64

CATEGORIES=						inputmethods japanese

MAINTAINER =					c2qd

GH_ACCOUNT =					fcitx
GH_PROJECT =					mozc-cmake
GH_COMMIT =						35b68cf9c84588590739bca7bbe8ffe24833ef79

FCITX_MOZC_COMMIT =				3f8dea4bdf72c6af200ecdbe3d456871fb1d5e03
ZIPCODE_COMMIT =				ba167e0bd99ee9705e40a747c7358f425511f78a

DIST_TUPLE +=					github fcitx mozc ${FCITX_MOZC_COMMIT} mozc

DIST_TUPLE +=					github hiroyuki-komatsu japanpost_zipcode \
								${ZIPCODE_COMMIT} japanpost_zipcode

MULTI_PACKAGES =				-main -tool -fcitx
FLAVORS =						ut
FLAVOR ?=

.include <bsd.port.arch.mk>

.if ${BUILD_PACKAGES:M-main}
CONFIGURE_ARGS +=				-DENABLE_SERVER=On -DBUILD_SERVER=On
.endif
.if ${BUILD_PACKAGES:M-tool}
CONFIGURE_ARGS +=				-DBUILD_TOOL=On
.endif
.if ${BUILD_PACKAGES:M-fcitx}
CONFIGURE_ARGS +=				-DBUILD_FCITX=On
.endif

.if ${FLAVOR:Mut}
# BSD-3-Clause + NAIST-2003(IPADic) +
# Public Domain(Okinawa dictionary, Zip code data, place-names) +
# BSD-2-Clause(Japanese usage dictionary) + CC-BY-SA-4.0(jawiki, edict2) +
# Apache-2.0(personal-names, Neologd, SudachiDict)
PERMIT_PACKAGE =				No
PATCH_LIST =					patch_ut-* patch-*
BUILD_DEPENDS +=				archivers/bzip2
.else
# BSD-3-Clause + NAIST-2003(IPADic) + Zlib(zlib) +
# Public Domain(Okinawa dictionary, Zip code data) +
# BSD-2-Clause(Japanese usage dictionary)
PERMIT_PACKAGE =				Yes
.endif

UT_COMMIT =						15c1c64502b43e31d328012860376c03c3eaf633
UT_JAWIKI_COMMIT =				88dddd9d7bc5657861aff3820fd2abc7d5186851
UT_PERSONAL_NAMES_COMMIT =		fb36082545e77e673741a1068620489dffb8ea2c
UT_PLACE_NAMES_COMMIT =			ebb123f12adde4ead5323a8113c5d4cfc91de08c
UT_NEOLOGD_COMMIT =				e33ac4ce808fa4253c6c97bf5178e229a4bfb50f
UT_SUDACHIDICT_COMMIT =			c686771bada1d59e9b105c81b29e6ac1a239cb54
UT_EDICT2_COMMIT =				8fe8f7918baf513c3d7e243807dfcda2d5c30139
JAWIKI_VERSION =				20260801

SUPDISTFILES.merge_script =		merge_dictionaries-${UT_COMMIT}{merge_dictionaries}.py
SITES.merge_script =			https://raw.githubusercontent.com/utuhiro78/merge-ut-dictionaries/${UT_COMMIT}/src/merge/
SUPDISTFILES.jawiki =			mozcdic-ut-jawiki-${UT_JAWIKI_COMMIT}{mozcdic-ut-jawiki}.txt.bz2
SITES.jawiki =					https://github.com/utuhiro78/mozcdic-ut-jawiki/raw/${UT_JAWIKI_COMMIT}/
UT_JAWIKI =						mozcdic-ut-jawiki-${UT_JAWIKI_COMMIT}.txt.bz2
SUPDISTFILES.personal_names =	mozcdic-ut-personal-names-${UT_PERSONAL_NAMES_COMMIT}{mozcdic-ut-personal-names}.txt.bz2
SITES.personal_names =			https://github.com/utuhiro78/mozcdic-ut-personal-names/raw/${UT_PERSONAL_NAMES_COMMIT}/
UT_PERSONAL_NAMES =				mozcdic-ut-personal-names-${UT_PERSONAL_NAMES_COMMIT}.txt.bz2
SUPDISTFILES.place_names =		mozcdic-ut-place-names-${UT_PLACE_NAMES_COMMIT}{mozcdic-ut-place-names}.txt.bz2
SITES.place_names =				https://github.com/utuhiro78/mozcdic-ut-place-names/raw/${UT_PLACE_NAMES_COMMIT}/
UT_PLACE_NAMES =				mozcdic-ut-place-names-${UT_PLACE_NAMES_COMMIT}.txt.bz2
SUPDISTFILES.neologd =			mozcdic-ut-neologd-${UT_NEOLOGD_COMMIT}{mozcdic-ut-neologd}.txt.bz2
SITES.neologd =					https://github.com/utuhiro78/mozcdic-ut-neologd/raw/${UT_NEOLOGD_COMMIT}/
UT_NEOLOGD =					mozcdic-ut-neologd-${UT_NEOLOGD_COMMIT}.txt.bz2
SUPDISTFILES.sudachidict =		mozcdic-ut-sudachidict-${UT_SUDACHIDICT_COMMIT}{mozcdic-ut-sudachidict}.txt.bz2
SITES.sudachidict =				https://github.com/utuhiro78/mozcdic-ut-sudachidict/raw/${UT_SUDACHIDICT_COMMIT}/
UT_SUDACHIDICT =				mozcdic-ut-sudachidict-${UT_SUDACHIDICT_COMMIT}.txt.bz2
SUPDISTFILES.edict2 =			mozcdic-ut-edict2-${UT_EDICT2_COMMIT}{mozcdic-ut-edict2}.txt.bz2
SITES.edict2 =					https://github.com/utuhiro78/mozcdic-ut-edict2/raw/${UT_EDICT2_COMMIT}/
UT_EDICT2 =						mozcdic-ut-edict2-${UT_EDICT2_COMMIT}.txt.bz2
SUPDISTFILES.jawiki_index =		jawiki-${JAWIKI_VERSION}-pages-articles-multistream-index.txt.bz2
SITES.jawiki_index =			https://dumps.wikimedia.org/jawiki/${JAWIKI_VERSION}/

EXTRACT_ONLY =					mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								fcitx-mozc-${FCITX_MOZC_COMMIT}.tar.gz \
								hiroyuki-komatsu-japanpost_zipcode-${ZIPCODE_COMMIT}.tar.gz

BUILD_DEPENDS +=				devel/protobuf devel/gettext,-tools

WANTLIB-main +=					${COMPILER_LIBCXX} absl_base absl_borrowed_fixup_buffer
WANTLIB-main +=					absl_city absl_civil_time absl_cord absl_cord_internal
WANTLIB-main +=					absl_cordz_functions absl_cordz_handle absl_cordz_info
WANTLIB-main +=					absl_crc32c absl_crc_cord_state absl_crc_cpu_detect
WANTLIB-main +=					absl_crc_internal absl_debugging_internal
WANTLIB-main +=					absl_decode_rust_punycode absl_demangle_internal
WANTLIB-main +=					absl_demangle_rust absl_die_if_null absl_examine_stack
WANTLIB-main +=					absl_exponential_biased absl_flags_commandlineflag
WANTLIB-main +=					absl_flags_commandlineflag_internal absl_flags_config
WANTLIB-main +=					absl_flags_internal absl_flags_marshalling absl_flags_parse
WANTLIB-main +=					absl_flags_private_handle_accessor absl_flags_program_name
WANTLIB-main +=					absl_flags_reflection absl_flags_usage absl_flags_usage_internal
WANTLIB-main +=					absl_graphcycles_internal absl_hash absl_hashtablez_sampler
WANTLIB-main +=					absl_int128 absl_kernel_timeout_internal absl_leak_check
WANTLIB-main +=					absl_log_entry absl_log_flags absl_log_globals absl_log_initialize
WANTLIB-main +=					absl_log_internal_check_op absl_log_internal_conditions
WANTLIB-main +=					absl_log_internal_fnmatch absl_log_internal_format
WANTLIB-main +=					absl_log_internal_globals absl_log_internal_log_sink_set
WANTLIB-main +=					absl_log_internal_message absl_log_internal_nullguard
WANTLIB-main +=					absl_log_internal_proto absl_log_internal_structured_proto
WANTLIB-main +=					absl_log_severity absl_log_sink absl_malloc_internal
WANTLIB-main +=					absl_random_distributions absl_random_internal_entropy_pool
WANTLIB-main +=					absl_random_internal_platform absl_random_internal_randen
WANTLIB-main +=					absl_random_internal_randen_hwaes absl_random_internal_randen_hwaes_impl
WANTLIB-main +=					absl_random_internal_randen_slow absl_random_internal_seed_material
WANTLIB-main +=					absl_random_seed_gen_exception absl_random_seed_sequences
WANTLIB-main +=					absl_raw_hash_set absl_raw_logging_internal absl_spinlock_wait
WANTLIB-main +=					absl_stacktrace absl_status absl_statusor absl_str_format_internal
WANTLIB-main +=					absl_strerror absl_strings absl_strings_internal absl_symbolize
WANTLIB-main +=					absl_synchronization absl_throw_delegate absl_time
WANTLIB-main +=					absl_time_zone absl_tracing_internal absl_utf8_for_code_point
WANTLIB-main +=					absl_vlog_config_internal c m protobuf utf8_validity

WANTLIB-tool +=					${COMPILER_LIBCXX} GL Qt6Core Qt6Gui Qt6Widgets
WANTLIB-tool += 				absl_base absl_borrowed_fixup_buffer absl_city absl_civil_time
WANTLIB-tool += 				absl_cord absl_cord_internal absl_cordz_functions absl_cordz_handle
WANTLIB-tool += 				absl_cordz_info absl_crc32c absl_crc_cord_state absl_crc_cpu_detect
WANTLIB-tool += 				absl_crc_internal absl_debugging_internal absl_decode_rust_punycode
WANTLIB-tool += 				absl_demangle_internal absl_demangle_rust absl_die_if_null
WANTLIB-tool += 				absl_examine_stack absl_exponential_biased absl_flags_commandlineflag
WANTLIB-tool += 				absl_flags_commandlineflag_internal absl_flags_config
WANTLIB-tool += 				absl_flags_internal absl_flags_marshalling absl_flags_parse
WANTLIB-tool += 				absl_flags_private_handle_accessor absl_flags_program_name
WANTLIB-tool += 				absl_flags_reflection absl_flags_usage absl_flags_usage_internal
WANTLIB-tool += 				absl_graphcycles_internal absl_hash absl_hashtablez_sampler
WANTLIB-tool += 				absl_int128 absl_kernel_timeout_internal absl_leak_check
WANTLIB-tool += 				absl_log_entry absl_log_flags absl_log_globals absl_log_initialize
WANTLIB-tool += 				absl_log_internal_check_op absl_log_internal_conditions
WANTLIB-tool += 				absl_log_internal_fnmatch absl_log_internal_format
WANTLIB-tool += 				absl_log_internal_globals absl_log_internal_log_sink_set
WANTLIB-tool += 				absl_log_internal_message absl_log_internal_nullguard
WANTLIB-tool += 				absl_log_internal_proto absl_log_internal_structured_proto
WANTLIB-tool += 				absl_log_severity absl_log_sink absl_malloc_internal
WANTLIB-tool += 				absl_random_distributions absl_random_internal_entropy_pool
WANTLIB-tool += 				absl_random_internal_platform absl_random_internal_randen
WANTLIB-tool += 				absl_random_internal_randen_hwaes absl_random_internal_randen_hwaes_impl
WANTLIB-tool += 				absl_random_internal_randen_slow absl_random_internal_seed_material
WANTLIB-tool += 				absl_random_seed_gen_exception absl_random_seed_sequences
WANTLIB-tool += 				absl_raw_hash_set absl_raw_logging_internal absl_spinlock_wait
WANTLIB-tool += 				absl_stacktrace absl_status absl_statusor absl_str_format_internal
WANTLIB-tool += 				absl_strerror absl_strings absl_strings_internal absl_symbolize
WANTLIB-tool += 				absl_synchronization absl_throw_delegate absl_time
WANTLIB-tool += 				absl_time_zone absl_tracing_internal absl_utf8_for_code_point
WANTLIB-tool += 				absl_vlog_config_internal c m protobuf utf8_validity

WANTLIB-fcitx +=				${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Utils
WANTLIB-fcitx +=				absl_base absl_borrowed_fixup_buffer absl_city absl_civil_time
WANTLIB-fcitx +=				absl_cord absl_cord_internal absl_cordz_functions absl_cordz_handle
WANTLIB-fcitx +=				absl_cordz_info absl_crc32c absl_crc_cord_state absl_crc_cpu_detect
WANTLIB-fcitx +=				absl_crc_internal absl_debugging_internal absl_decode_rust_punycode
WANTLIB-fcitx +=				absl_demangle_internal absl_demangle_rust absl_die_if_null
WANTLIB-fcitx += 				absl_examine_stack absl_exponential_biased absl_flags_commandlineflag
WANTLIB-fcitx +=				absl_flags_commandlineflag_internal absl_flags_config
WANTLIB-fcitx +=				absl_flags_internal absl_flags_marshalling absl_flags_parse
WANTLIB-fcitx +=				absl_flags_private_handle_accessor absl_flags_program_name
WANTLIB-fcitx +=				absl_flags_reflection absl_flags_usage absl_flags_usage_internal
WANTLIB-fcitx +=				absl_graphcycles_internal absl_hash absl_hashtablez_sampler
WANTLIB-fcitx +=				absl_int128 absl_kernel_timeout_internal absl_leak_check
WANTLIB-fcitx +=				absl_log_entry absl_log_flags absl_log_globals absl_log_initialize
WANTLIB-fcitx +=				absl_log_internal_check_op absl_log_internal_conditions
WANTLIB-fcitx +=				absl_log_internal_fnmatch absl_log_internal_format
WANTLIB-fcitx +=				absl_log_internal_globals absl_log_internal_log_sink_set
WANTLIB-fcitx +=				absl_log_internal_message absl_log_internal_nullguard
WANTLIB-fcitx +=				absl_log_internal_proto absl_log_internal_structured_proto
WANTLIB-fcitx +=				absl_log_severity absl_log_sink absl_malloc_internal
WANTLIB-fcitx +=				absl_random_distributions absl_random_internal_entropy_pool
WANTLIB-fcitx +=				absl_random_internal_platform absl_random_internal_randen
WANTLIB-fcitx +=				absl_random_internal_randen_hwaes absl_random_internal_randen_hwaes_impl
WANTLIB-fcitx +=				absl_random_internal_randen_slow absl_random_internal_seed_material
WANTLIB-fcitx +=				absl_random_seed_gen_exception absl_random_seed_sequences
WANTLIB-fcitx +=				absl_raw_hash_set absl_raw_logging_internal absl_spinlock_wait
WANTLIB-fcitx +=				absl_stacktrace absl_status absl_statusor absl_str_format_internal
WANTLIB-fcitx +=				absl_strerror absl_strings absl_strings_internal absl_symbolize
WANTLIB-fcitx +=				absl_synchronization absl_throw_delegate absl_time
WANTLIB-fcitx +=				absl_time_zone absl_tracing_internal absl_utf8_for_code_point
WANTLIB-fcitx +=				absl_vlog_config_internal m protobuf utf8_validity

LIB_DEPENDS-main +=				devel/abseil-cpp devel/protobuf
LIB_DEPENDS-tool +=				devel/abseil-cpp devel/protobuf x11/qt6/qtbase
LIB_DEPENDS-fcitx +=			devel/abseil-cpp devel/protobuf inputmethods/fcitx

RUN_DEPENDS-main +=				devel/xdg-utils
RUN_DEPENDS-fcitx +=			inputmethods/fcitx

MODULES +=						devel/cmake lang/python

MODPY_RUNDEP =					No

COMPILER =						base-clang ports-gcc

CFLAGS +=						-I${X11BASE}/include
CXXFLAGS +=						-I${LOCALBASE}/include
LDFLAGS +=						-L${LOCALBASE}/lib

MAKE_ENV +=						LC_CTYPE=C.UTF-8

SUBST_TARGETS +=				${WRKDIST}/mozc/src/base/system_util.cc \
								${WRKDIST}/mozc/src/base/process.cc

pre-patch:
	@if [ $$(ulimit -Sd) != "unlimited" ] && [ $$(ulimit -Sd) -lt $$((3*1024*1024)) ]; then \
		echo "datasize limit is too low. Build needs approximately 3GiB."; \
		exit 1; \
	fi
.if ${FLAVOR:Mut}
	cp ${FULLDISTDIR}/merge_dictionaries-${UT_COMMIT}.py \
		${WRKDIST}/mozc/merge_dictionaries.py
.endif

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}
.if ${FLAVOR:Mut}
	${SUBST_CMD} -DJAWIKI_INDEX_FILE=${SUPDISTFILES.jawiki_index} \
		${WRKDIST}/mozc/merge_dictionaries.py
	rm -f ${WRKDIST}/mozc/mozcdic-ut*.txt*
	cd ${FULLDISTDIR} && cp ${UT_JAWIKI} ${UT_PERSONAL_NAMES} ${UT_PLACE_NAMES} \
		${UT_NEOLOGD} ${UT_SUDACHIDICT} ${UT_EDICT2} \
		${SUPDISTFILES.jawiki_index} ${WRKDIST}/mozc
	cd ${WRKDIST}/mozc && bzip2 -d mozcdic-ut-*.txt.bz2 && \
		cat mozcdic-ut-*.txt > mozcdic-ut.txt && \
		${MODPY_BIN} merge_dictionaries.py mozcdic-ut.txt && \
		cat mozcdic-ut.txt >> ${WRKSRC}/mozc/src/data/dictionary_oss/dictionary00.txt
.endif

post-install:
	${INSTALL_DATA_DIR} "${PREFIX}/share/doc/mozc"
	${INSTALL_DATA} "${WRKDIST}/mozc/src/data/installer/credits_en.html" \
		"${PREFIX}/share/doc/mozc/credits_en.html"

.include <bsd.port.mk>
