COMMENT =						Japanese Input Method Editor

HOMEPAGE =						https://github.com/google/mozc

GH_ACCOUNT =					google
GH_PROJECT =					mozc
GH_COMMIT =						851c3fe33060d2a6090363e4d7ec44fafde2c03d

VERSION =						3.34.6239.20260814
DISTNAME =						mozc-${VERSION}
PKGNAME =						mozc-${VERSION}

FLAVORS =						ut
FLAVOR ?=

CATEGORIES=						inputmethods japanese

MAINTAINER =					c2qd

.if ${FLAVOR:Mut}
# BSD-3-Clause + NAIST-2003(IPADic) + Zlib(zlib) +
# Public Domain(Okinawa dictionary, Zip code data, place-names) +
# BSD-2-Clause(Japanese usage dictionary) + BSD-3-Clause(protobuf) +
# CC-BY-SA-4.0(jawiki, edict2) + Apache-2.0(abseil-cpp, personal-names, Neologd, SudachiDict)
PERMIT_PACKAGE =				No # Hmm...?
MODPY_ADJ_FILES +=              ${WRKSRC}/merge_dictionaries.py
PATCH_LIST =					patch_ut-* patch-*
.else
# Question: Is it okay to change PERMIT_PACKAGE depending on the flavor?
# BSD-3-Clause + NAIST-2003(IPADic) + Zlib(zlib) +
# Public Domain(Okinawa dictionary, Zip code data) +
# BSD-2-Clause(Japanese usage dictionary) + BSD-3-Clause(protobuf) +
# Apache-2.0(abseil-cpp)
PERMIT_PACKAGE =				Yes # Maybe.
.endif

UT_COMMIT =						15c1c64502b43e31d328012860376c03c3eaf633
UT_JAWIKI_COMMIT =				88dddd9d7bc5657861aff3820fd2abc7d5186851
UT_PERSONAL_NAMES_COMMIT =		fb36082545e77e673741a1068620489dffb8ea2c
UT_PLACE_NAMES_COMMIT =			ebb123f12adde4ead5323a8113c5d4cfc91de08c
UT_NEOLOGD_COMMIT =				e33ac4ce808fa4253c6c97bf5178e229a4bfb50f
UT_SUDACHIDICT_COMMIT =			c686771bada1d59e9b105c81b29e6ac1a239cb54
UT_EDICT2_COMMIT =				8fe8f7918baf513c3d7e243807dfcda2d5c30139
JAWIKI_DATE =					20260801

SUPDISTFILES.merge_script =		merge_dictionaries-${UT_COMMIT}{merge_dictionaries}.py
SITES.merge_script =			https://raw.githubusercontent.com/utuhiro78/merge-ut-dictionaries/${UT_COMMIT}/src/merge/
SUPDISTFILES.jawiki =				mozcdic-ut-jawiki-${UT_JAWIKI_COMMIT}{mozcdic-ut-jawiki}.txt.bz2
SITES.jawiki =					https://github.com/utuhiro78/mozcdic-ut-jawiki/raw/${UT_JAWIKI_COMMIT}/
UT_JAWIKI =						mozcdic-ut-jawiki-${UT_JAWIKI_COMMIT}.txt.bz2
SUPDISTFILES.personal_names =		mozcdic-ut-personal-names-${UT_PERSONAL_NAMES_COMMIT}{mozcdic-ut-personal-names}.txt.bz2
SITES.personal_names =			https://github.com/utuhiro78/mozcdic-ut-personal-names/raw/${UT_PERSONAL_NAMES_COMMIT}/
UT_PERSONAL_NAMES =				mozcdic-ut-personal-names-${UT_PERSONAL_NAMES_COMMIT}.txt.bz2
SUPDISTFILES.place_names =			mozcdic-ut-place-names-${UT_PLACE_NAMES_COMMIT}{mozcdic-ut-place-names}.txt.bz2
SITES.place_names =				https://github.com/utuhiro78/mozcdic-ut-place-names/raw/${UT_PLACE_NAMES_COMMIT}/
UT_PLACE_NAMES =				mozcdic-ut-place-names-${UT_PLACE_NAMES_COMMIT}.txt.bz2
SUPDISTFILES.neologd =				mozcdic-ut-neologd-${UT_NEOLOGD_COMMIT}{mozcdic-ut-neologd}.txt.bz2
SITES.neologd =					https://github.com/utuhiro78/mozcdic-ut-neologd/raw/${UT_NEOLOGD_COMMIT}/
UT_NEOLOGD =					mozcdic-ut-neologd-${UT_NEOLOGD_COMMIT}.txt.bz2
SUPDISTFILES.sudachidict =			mozcdic-ut-sudachidict-${UT_SUDACHIDICT_COMMIT}{mozcdic-ut-sudachidict}.txt.bz2
SITES.sudachidict =				https://github.com/utuhiro78/mozcdic-ut-sudachidict/raw/${UT_SUDACHIDICT_COMMIT}/
UT_SUDACHIDICT =				mozcdic-ut-sudachidict-${UT_SUDACHIDICT_COMMIT}.txt.bz2
SUPDISTFILES.edict2 =				mozcdic-ut-edict2-${UT_EDICT2_COMMIT}{mozcdic-ut-edict2}.txt.bz2
SITES.edict2 =					https://github.com/utuhiro78/mozcdic-ut-edict2/raw/${UT_EDICT2_COMMIT}/
UT_EDICT2 =						mozcdic-ut-edict2-${UT_EDICT2_COMMIT}.txt.bz2
SUPDISTFILES.jawiki_index =		jawiki-${JAWIKI_DATE}-pages-articles-multistream-index.txt.bz2
SITES.jawiki_index =			https://dumps.wikimedia.org/jawiki/${JAWIKI_DATE}/

JA_USAGE_DICT_VERSION =			2025-01-25
ZIP_CODE_COMMIT =				621d059fbcbfae17bfca15b439692bae934268c3

DISTFILES.ja_usage_dict =		${JA_USAGE_DICT_VERSION}.zip
SITES.ja_usage_dict =			https://github.com/hiroyuki-komatsu/japanese-usage-dictionary/archive/refs/tags/
DISTFILES.zip_code_jigyosyo =	jigyosyo.zip
SITES.zip_code_jigyosyo =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT}/
DISTFILES.zip_code_ken_all =	ken_all.zip
SITES.zip_code_ken_all =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT}/

EXTRACT_ONLY =					mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								bazelbuild-bazel-central-registry-${BCR_COMMIT}.tar.gz

BUILD_DEPENDS +=				archivers/bzip2

WANTLIB +=						${COMPILER_LIBCXX} Qt6Core Qt6Gui Qt6Widgets
WANTLIB +=						c m execinfo z X11
LIB_DEPENDS +=					x11/qt6/qtbase

COMPILER_LANGS =				c++
COMPILER =						base-clang

BAZEL_BUILD_FLAGS +=			--copt=-I${X11BASE}/include \
								--linkopt=-L${LOCALBASE}/lib \
								--host_linkopt=-L${LOCALBASE}/lib \
								--action_env=LC_CTYPE=C.UTF-8

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/
.if ${FLAVOR:Mut}
	cp ${FULLDISTDIR}/merge_dictionaries-${UT_COMMIT}.py \
		${WRKSRC}/merge_dictionaries.py
.endif

pre-patch:
	@if [ $$(ulimit -Sd) -lt $$((3*1024*1024)) ]; then \
		echo "datasize limit is too low. Build needs approximately 3GiB."; \
		exit 1; \
	fi
	cp ${FILESDIR}/versions_json.patch \
		${WRKDIST}/bazel-central-registry/modules/rules_go/${RULES_GO_VERSION}/patches

generate-ut:
	cd ${FULLDISTDIR} && rm -f ${WRKSRC}/mozcdic-ut-*.txt* && \
		cp ${UT_JAWIKI} ${UT_PERSONAL_NAMES} ${UT_PLACE_NAMES} \
		${UT_NEOLOGD} ${UT_SUDACHIDICT} ${UT_EDICT2} ${DISTFILES.jawiki_index} \
		${WRKSRC} && \
		cd ${WRKSRC} && bzip2 -d mozcdic-ut-*.txt.bz2 && \
		cat mozcdic-ut-*.txt > mozcdic-ut.txt && \
		${MODPY_BIN} merge_dictionaries.py mozcdic-ut.txt && \
		cat mozcdic-ut.txt >> src/data/dictionary_oss/dictionary00.txt

.if ${FLAVOR:Mut}
post-patch: generate-ut
.endif

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS} && ${SUBST_CMD} ${SUBST_VARS_bazel_conf} \
		${SUBST_TARGETS_bazel_conf} && 	cd ${WRKDIST}/bazel-central-registry && \
		mkdir modules/abseil-cpp/${ABSEIL_VERSION}/patches && \
		cp ${FILESDIR}/enolink.patch \
		modules/abseil-cpp/${ABSEIL_VERSION}/patches

do-build:
	cd ${WRKSRC}/src && ${BAZEL_ENVS} ${LOCALBASE}/bin/bazel9 \
		${BAZEL_STARTUP_FLAGS} build ${BAZEL_BUILD_FLAGS} \
		server:mozc_server gui/tool:mozc_tool

do-install:
	${INSTALL_PROGRAM_DIR} "${PREFIX}/libexec/mozc"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/server/mozc_server" \
		"${PREFIX}/libexec/mozc/mozc_server"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/libexec/mozc/mozc_tool"
	${INSTALL_DATA_DIR} "${PREFIX}/share/doc/mozc"
	${INSTALL_DATA} "${WRKSRC}/src/data/installer/credits_en.html" \
		"${PREFIX}/share/doc/mozc/credits_en.html"

.include <bsd.port.mk>
