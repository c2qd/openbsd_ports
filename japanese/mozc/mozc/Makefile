COMMENT =						Japanese Input Method Editor

HOMEPAGE =						https://github.com/google/mozc

GH_ACCOUNT =					google
GH_PROJECT =					mozc
GH_COMMIT =						3f235b4eb6fcff7d14ef5f0fb8ee56de7ee4c732

VERSION =						3.34.6239.20260717.git${GH_COMMIT:C/^(.{10}).*/\1/}
DISTNAME =						mozc-${VERSION}
PKGNAME =						mozc-${VERSION}

CATEGORIES=						japanese

MAINTAINER =					c2qd

UT_COMMIT =						15c1c64502b43e31d328012860376c03c3eaf633
UT_JAWIKI_COMMIT =				4d32dfc2e3a3644d6b4ab848fb129ca2cd52a619
UT_PERSONAL_NAMES_COMMIT =		159e01bf4af61a3fa9367ae2578fd42c464a0ea7
UT_PLACE_NAMES_COMMIT =			9951ef87972c1d2c3803e2106b86083d14a242f9
UT_NEOLOGD_COMMIT =				e33ac4ce808fa4253c6c97bf5178e229a4bfb50f
UT_SUDACHIDICT_COMMIT =			7def3da408b1854801bd5b559273f9fb8001ef5b
JAWIKI_DATE =					20260701

DISTFILES.merge_script =		merge_dictionaries-${UT_COMMIT}{merge_dictionaries}.py
SITES.merge_script =			https://raw.githubusercontent.com/utuhiro78/merge-ut-dictionaries/${UT_COMMIT}/src/merge/
MERGE_SCRIPT =					${DISTFILES.merge_script:C/-[0-9a-fA-F]{40}//:C/\{[^}]*\}//}
DISTFILES.jawiki =				mozcdic-ut-jawiki-${UT_JAWIKI_COMMIT}{mozcdic-ut-jawiki}.txt.bz2
SITES.jawiki =					https://github.com/utuhiro78/mozcdic-ut-jawiki/raw/${UT_JAWIKI_COMMIT}/
DISTFILES.personal_names =		mozcdic-ut-personal-names-${UT_PERSONAL_NAMES_COMMIT}{mozcdic-ut-personal-names}.txt.bz2
SITES.personal_names =			https://github.com/utuhiro78/mozcdic-ut-personal-names/raw/${UT_PERSONAL_NAMES_COMMIT}/
DISTFILES.place_names =			mozcdic-ut-place-names-${UT_PLACE_NAMES_COMMIT}{mozcdic-ut-place-names}.txt.bz2
SITES.place_names =				https://github.com/utuhiro78/mozcdic-ut-place-names/raw/${UT_PLACE_NAMES_COMMIT}/
DISTFILES.neologd =				mozcdic-ut-neologd-${UT_NEOLOGD_COMMIT}{mozcdic-ut-neologd}.txt.bz2
SITES.neologd =					https://github.com/utuhiro78/mozcdic-ut-neologd/raw/${UT_NEOLOGD_COMMIT}/
DISTFILES.sudachidict =			mozcdic-ut-sudachidict-${UT_SUDACHIDICT_COMMIT}{mozcdic-ut-sudachidict}.txt.bz2
SITES.sudachidict =				https://github.com/utuhiro78/mozcdic-ut-sudachidict/raw/${UT_SUDACHIDICT_COMMIT}/
DISTFILES.jawiki_index =		jawiki-${JAWIKI_DATE}-pages-articles-multistream-index.txt.bz2
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

MODULES +=						lang/python

MODPY_RUNDEP =                  No
MODPY_ADJ_FILES +=              ${WRKSRC}/merge_dictionaries.py

WANTLIB +=						${COMPILER_LIBCXX} Qt6Core Qt6Gui Qt6Widgets
WANTLIB +=						c m execinfo z X11
LIB_DEPENDS +=					x11/qt6/qtbase

COMPILER_LANGS =				c++
COMPILER =						base-clang

# BSD-3-Clause + NAIST-2003(IPADic) + Public Domain(Okinawa dictionary) +
# BSD-2-Clause(Japanese usage dictionary) +
# Copyright non-assertion(Zip code data / place-names) +
# CC BY-SA(jawiki) + Apache 2.0(personal-names / Neologd / SudachiDict)
# Warning: I don't know anything about licenses~
#          Please determine whether to set PERMIT_PACKAGE to Y/n.
PERMIT_PACKAGE =				No

post-extract:
	cp ${FULLDISTDIR}/${MERGE_SCRIPT} ${WRKSRC}/ && \
		cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

pre-patch:
	cp ${FILESDIR}/pyinterpreter_fallback.patch \
		${WRKDIST}/bazel-central-registry/modules/rules_python/${RULES_PYTHON_VERSION}/patches && \
		cp ${FILESDIR}/versions_json.patch \
		${WRKDIST}/bazel-central-registry/modules/rules_go/${RULES_GO_VERSION}/patches

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS} && ${SUBST_CMD} ${SUBST_VARS_bazel_conf} \
		${SUBST_TARGETS_bazel_conf} && cd ${WRKSRC} && \
		PYIF_HASH=$$(sha256 -bq bazel-central-registry/modules/rules_python/${RULES_PYTHON_VERSION}/patches/pyinterpreter_fallback.patch); \
		${SUBST_CMD} \
		-DPYIF_HASH=$${PYIF_HASH} ${SUBST_TARGETS_rules_python} && \
		cd ${FULLDISTDIR} && \
		cp ${FULLDISTDIR}/mozcdic-ut-*.txt.bz2 ${DISTFILES.jawiki_index} ${WRKSRC} && \
		cd ${WRKSRC} && bzip2 -d mozcdic-ut-*.txt.bz2 && \
		cat mozcdic-ut-*.txt > mozcdic-ut.txt && \
		${MODPY_BIN} ${MERGE_SCRIPT} mozcdic-ut.txt && \
		cat mozcdic-ut.txt >> src/data/dictionary_oss/dictionary00.txt && \
		cd ${WRKDIST}/bazel-central-registry && \
		mkdir modules/abseil-cpp/${ABSEIL_VERSION}/patches && \
		cp ${FILESDIR}/enolink.patch \
		modules/abseil-cpp/${ABSEIL_VERSION}/patches

do-build:
	cd ${WRKSRC}/src && ${BAZEL_ENVS} ${LOCALBASE}/bin/bazel9 \
		${BAZEL_STARTUP_FLAGS} build ${BAZEL_BUILD_FLAGS} \
		--copt=-I/usr/X11R6/include \
		--linkopt=-L/usr/local/lib \
		--host_linkopt=-L/usr/local/lib \
		--action_env=LC_CTYPE=C.UTF-8 \
		server:mozc_server gui/tool:mozc_tool

do-install:
	${INSTALL_PROGRAM_DIR} "${PREFIX}/libexec/mozc"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/server/mozc_server" \
		"${PREFIX}/libexec/mozc/mozc_server"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/libexec/mozc/mozc_tool"

.include <bsd.port.mk>

