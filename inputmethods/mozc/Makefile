COMMENT-main =					Japanese Input Method Editor
COMMENT-tool =					GUI configuration tool for Mozc
COMMENT-fcitx =					Fcitx5 addon for Mozc

HOMEPAGE =						https://github.com/google/mozc
HOMEPAGE-fcitx =				https://github.com/fcitx/mozc

VERSION =						3.34.6239.20260814
REVISION-main =					2
DISTNAME =						mozc-${VERSION}

FULLPKGNAME-tool =				mozc-tool-${VERSION}
FULLPKGNAME-fcitx =				fcitx-mozc-${VERSION}
FULLPKGPATH-tool =				${PKGPATH},-tool
FULLPKGPATH-fcitx =				${PKGPATH},-fcitx

DIST_SUBDIR =					mozc

ONLY_FOR_ARCHS =				amd64 arm64

CATEGORIES=						inputmethods japanese

MAINTAINER =					c2qd

# non-ut flavor:
# BSD-3-Clause + NAIST-2003(IPADic) +
# Public Domain(Okinawa dictionary, Zip code data) +
# BSD-2-Clause(Japanese usage dictionary)
# ut flavor:
# BSD-3-Clause + NAIST-2003(IPADic) +
# Public Domain(Okinawa dictionary, Zip code data, place-names) +
# BSD-2-Clause(Japanese usage dictionary) +
# Apache-2.0(personal-names, Neologd, SudachiDict)
PERMIT_PACKAGE =				Yes

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

UT_COMMIT =						15c1c64502b43e31d328012860376c03c3eaf633
UT_PERSONAL_NAMES_COMMIT =		5e0d754f3162c3e1d83568307da2c9d3ea54731f
UT_PLACE_NAMES_COMMIT =			ebb123f12adde4ead5323a8113c5d4cfc91de08c
UT_NEOLOGD_COMMIT =				e33ac4ce808fa4253c6c97bf5178e229a4bfb50f
UT_SUDACHIDICT_COMMIT =			c686771bada1d59e9b105c81b29e6ac1a239cb54
JAWIKI_VERSION =				20260901

SUPDISTFILES.merge_script =		${UT_COMMIT}{merge_dictionaries}.py
SUPDISTFILES.personal_names =	${UT_PERSONAL_NAMES_COMMIT}{mozcdic-ut-personal-names}.txt.bz2
SUPDISTFILES.place_names =		${UT_PLACE_NAMES_COMMIT}{mozcdic-ut-place-names}.txt.bz2
SUPDISTFILES.neologd =			${UT_NEOLOGD_COMMIT}{mozcdic-ut-neologd}.txt.bz2
SUPDISTFILES.sudachidict =		${UT_SUDACHIDICT_COMMIT}{mozcdic-ut-sudachidict}.txt.bz2
SUPDISTFILES.jawiki_index =		jawiki-${JAWIKI_VERSION}-pages-articles-multistream-index.txt.bz2

.if ${FLAVOR:Mut}
PATCH_LIST =					patch_ut-* patch-*
BUILD_DEPENDS +=				archivers/bzip2

DISTFILES.merge_script =		${SUPDISTFILES.merge_script}
DISTFILES.personal_names =		${SUPDISTFILES.personal_names}
DISTFILES.place_names =			${SUPDISTFILES.place_names}
DISTFILES.neologd =				${SUPDISTFILES.neologd}
DISTFILES.sudachidict =			${SUPDISTFILES.sudachidict}
DISTFILES.jawiki_index =		${SUPDISTFILES.jawiki_index}
.endif

SITES.merge_script =			https://raw.githubusercontent.com/utuhiro78/merge-ut-dictionaries/${UT_COMMIT}/src/merge/
SITES.personal_names =			https://github.com/utuhiro78/mozcdic-ut-personal-names/raw/${UT_PERSONAL_NAMES_COMMIT}/
SITES.place_names =				https://github.com/utuhiro78/mozcdic-ut-place-names/raw/${UT_PLACE_NAMES_COMMIT}/
SITES.neologd =					https://github.com/utuhiro78/mozcdic-ut-neologd/raw/${UT_NEOLOGD_COMMIT}/
SITES.sudachidict =				https://github.com/utuhiro78/mozcdic-ut-sudachidict/raw/${UT_SUDACHIDICT_COMMIT}/
SITES.jawiki_index =			https://dumps.wikimedia.org/jawiki/${JAWIKI_VERSION}/

EXTRACT_ONLY =					mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								fcitx-mozc-${FCITX_MOZC_COMMIT}.tar.gz \
								hiroyuki-komatsu-japanpost_zipcode-${ZIPCODE_COMMIT}.tar.gz

BUILD_DEPENDS +=				devel/protobuf devel/gettext,-tools

WANTLIB +=						${COMPILER_LIBCXX} absl_base absl_borrowed_fixup_buffer
WANTLIB +=						absl_city absl_civil_time absl_cord absl_cord_internal
WANTLIB +=						absl_cordz_functions absl_cordz_handle absl_cordz_info
WANTLIB +=						absl_crc32c absl_crc_cord_state absl_crc_cpu_detect
WANTLIB +=						absl_crc_internal absl_debugging_internal
WANTLIB +=						absl_decode_rust_punycode absl_demangle_internal
WANTLIB +=						absl_demangle_rust absl_die_if_null absl_examine_stack
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
WANTLIB +=						absl_vlog_config_internal m protobuf utf8_validity
WANTLIB-main +=					${WANTLIB} c
WANTLIB-tool +=					${WANTLIB} GL Qt6Core Qt6Gui Qt6Widgets c
WANTLIB-fcitx +=				${WANTLIB} Fcitx5Config Fcitx5Core Fcitx5Utils

LIB_DEPENDS +=					devel/abseil-cpp devel/protobuf
LIB_DEPENDS-tool +=				${LIB_DEPENDS} x11/qt6/qtbase
LIB_DEPENDS-fcitx +=			${LIB_DEPENDS} inputmethods/fcitx

RUN_DEPENDS-main +=				devel/xdg-utils
RUN_DEPENDS-tool +=				${BASE_PKGPATH},-main
RUN_DEPENDS-fcitx +=			${BASE_PKGPATH},-main inputmethods/fcitx

MODULES +=						devel/cmake lang/python

MODPY_RUNDEP =					No

COMPILER =						base-clang ports-gcc

CFLAGS +=						-I${X11BASE}/include
CXXFLAGS +=						-I${LOCALBASE}/include
LDFLAGS +=						-L${LOCALBASE}/lib

MAKE_ENV +=						LC_CTYPE=C.UTF-8

SUBST_TARGETS +=				${WRKSRC}/mozc/src/base/system_util.cc \
								${WRKSRC}/mozc/src/base/process.cc

pre-patch:
	@if [ $$(ulimit -Sd) != "unlimited" ] && [ $$(ulimit -Sd) -lt $$((3*1024*1024)) ]; then \
		echo "datasize limit is too low. Build needs approximately 3GiB."; \
		exit 1; \
	fi
.if ${FLAVOR:Mut}
	cp ${FULLDISTDIR}/${UT_COMMIT}.py \
		${WRKSRC}/mozc/merge_dictionaries.py
.endif

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}
.if ${FLAVOR:Mut}
	${SUBST_CMD} -DJAWIKI_INDEX_FILE=${SUPDISTFILES.jawiki_index} \
		${WRKSRC}/mozc/merge_dictionaries.py
	cd ${FULLDISTDIR} && \
		cp {${UT_PERSONAL_NAMES_COMMIT},${WRKSRC}/mozc/mozcdic-ut-personal-names}.txt.bz2 && \
		cp {${UT_PLACE_NAMES_COMMIT},${WRKSRC}/mozc/mozcdic-ut-place-names}.txt.bz2 && \
		cp {${UT_NEOLOGD_COMMIT},${WRKSRC}/mozc/mozcdic-ut-neologd}.txt.bz2 && \
		cp {${UT_SUDACHIDICT_COMMIT},${WRKSRC}/mozc/mozcdic-ut-sudachidict}.txt.bz2 && \
		cp ${SUPDISTFILES.jawiki_index} ${WRKSRC}/mozc
	cd ${WRKSRC}/mozc && bzip2 -d mozcdic-ut-*.txt.bz2 && \
		cat mozcdic-ut-*.txt > mozcdic-ut.txt && \
		${MODPY_BIN} merge_dictionaries.py mozcdic-ut.txt && \
		cat mozcdic-ut.txt >> ${WRKSRC}/mozc/src/data/dictionary_oss/dictionary00.txt
.endif

post-install:
	${INSTALL_DATA_DIR} "${PREFIX}/share/doc/mozc"
	${INSTALL_DATA} "${WRKSRC}/mozc/src/data/installer/credits_en.html" \
		"${PREFIX}/share/doc/mozc/credits_en.html"
	${INSTALL_DATA} "${FILESDIR}/LEGAL_SUDACHIDICT" \
		"${PREFIX}/share/doc/mozc/LEGAL_SUDACHIDICT"
	${INSTALL_DATA} "${FILESDIR}/LICENSE_SUDACHIDICT" \
		"${PREFIX}/share/doc/mozc/LICENSE_SUDACHIDICT"
	${INSTALL_DATA} "${FILESDIR}/LICENSE_NEOLOGD" \
		"${PREFIX}/share/doc/mozc/LICENSE_NEOLOGD"
	${INSTALL_DATA} "${FILESDIR}/LICENSE-2.0.txt" \
		"${PREFIX}/share/doc/mozc/LICENSE-2.0.txt"

.include <bsd.port.mk>
