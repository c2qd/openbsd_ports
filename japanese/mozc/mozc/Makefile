COMMENT =						Japanese Input Method Editor

GH_ACCOUNT =					google
GH_PROJECT =					mozc
GH_COMMIT =						76887c679e1e4f156102e4bc62ea9cf9174678a3

VERSION =						3.34.6239.${GH_COMMIT}
REVISION =						0
DISTNAME =						mozc-${VERSION}
PKGNAME =						mozc-${VERSION}

CATEGORIES=						japanese

MAINTAINER =					c2qd

UT_COMMIT =						15c1c64502b43e31d328012860376c03c3eaf633
UT_JAWIKI_COMMIT =				b50cabaecaf32c03d102db55fc5d0b98e334ec9e
UT_PERSONAL_NAMES_COMMIT =		5896ebef5f39d5772f4575fa05eb24436ce5a5f1
UT_PLACE_NAMES_COMMIT =			6f9d9bda14f0bd2c10c1563d2aed9150ea95095c
UT_NEOLOGD_COMMIT =				e33ac4ce808fa4253c6c97bf5178e229a4bfb50f
UT_SUDACHIDICT_COMMIT =			7def3da408b1854801bd5b559273f9fb8001ef5b
JAWIKI_DATE =					20260601

DISTFILES.merge_script =		merge_dictionaries.py
SITES.merge_script =			https://raw.githubusercontent.com/utuhiro78/merge-ut-dictionaries/${UT_COMMIT}/src/merge/
DISTFILES.jawiki =				mozcdic-ut-jawiki.txt.bz2
SITES.jawiki =					https://github.com/utuhiro78/mozcdic-ut-jawiki/raw/${UT_JAWIKI_COMMIT}/
DISTFILES.personal_names =		mozcdic-ut-personal-names.txt.bz2
SITES.personal_names =			https://github.com/utuhiro78/mozcdic-ut-personal-names/raw/${UT_PERSONAL_NAMES_COMMIT}/
DISTFILES.place_names =			mozcdic-ut-place-names.txt.bz2
SITES.place_names =				https://github.com/utuhiro78/mozcdic-ut-place-names/raw/${UT_PLACE_NAMES_COMMIT}/
DISTFILES.sudachidict =			mozcdic-ut-sudachidict.txt.bz2
SITES.sudachidict =				https://github.com/utuhiro78/mozcdic-ut-sudachidict/raw/${UT_SUDACHIDICT_COMMIT}/
DISTFILES.neologd =				mozcdic-ut-neologd.txt.bz2
SITES.neologd =					https://github.com/utuhiro78/mozcdic-ut-neologd/raw/${UT_NEOLOGD_COMMIT}/
DISTFILES.jawiki_index =		jawiki-${JAWIKI_DATE}-pages-articles-multistream-index.txt.bz2
SITES.jawiki_index =			https://dumps.wikimedia.org/jawiki/${JAWIKI_DATE}/

JA_USAGE_DICT_VERSION =			2025-01-25
ZIP_CODE_COMMIT =				621d059fbcbfae17bfca15b439692bae934268c3

DISTFILES.dictionary_png =		outline_chrome_reader_mode_black_48dp.png
SITES.dictionary_png =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/png/action/chrome_reader_mode/materialiconsoutlined/48dp/1x/
DISTFILES.dictionary_svg =		24px.svg
SITES.dictionary_svg =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/src/action/chrome_reader_mode/materialiconsoutlined/
DISTFILES.property_png =		round_settings_black_48dp.png
SITES.property_png =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/png/action/settings/materialiconsround/48dp/1x/
DISTFILES.property_svg =		material_icon_tool_svg{24px}.svg
SITES.property_svg =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/src/action/settings/materialiconsround/
DISTFILES.ja_usage_dict =		${JA_USAGE_DICT_VERSION}.zip
SITES.ja_usage_dict =			https://github.com/hiroyuki-komatsu/japanese-usage-dictionary/archive/refs/tags/
DISTFILES.zip_code_jigyosyo =	jigyosyo.zip
SITES.zip_code_jigyosyo =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT}/
DISTFILES.zip_code_ken_all =	ken_all.zip
SITES.zip_code_ken_all =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT}/

EXTRACT_ONLY =					mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								bazelbuild-bazel-central-registry-${BCR_COMMIT}.tar.gz

BUILD_DEPENDS +=				archivers/bzip2 www/p5-HTML-Parser

MODULES +=						x11/qt6 lang/python

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

BAZEL_DISTDIR_ALT =				${WRKDIR}/distdir_alt

post-extract:
	cp ${FULLDISTDIR}/${DISTFILES.merge_script} ${WRKSRC}/ && \
		cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS} && \
		cd ${FULLDISTDIR} && \
		cp ${DISTFILES.jawiki} ${DISTFILES.personal_names} \
		${DISTFILES.place_names} ${DISTFILES.sudachidict} \
		${DISTFILES.neologd} ${DISTFILES.jawiki_index} ${WRKSRC} && \
		cd ${WRKSRC} && bzip2 -d mozcdic-*.txt.bz2 && \
		cat mozcdic-ut-*.txt > mozcdic-ut.txt && \
		${MODPY_BIN} merge_dictionaries.py mozcdic-ut.txt && \
		cat mozcdic-ut.txt >> src/data/dictionary_oss/dictionary00.txt && \
		mkdir -p ${BAZEL_DISTDIR_ALT} && \
		cp ${FULLDISTDIR}/material_icon_tool_svg.svg ${BAZEL_DISTDIR_ALT}/24px.svg && \
		cd ${WRKDIST}/bazel-central-registry && \
		mkdir modules/abseil-cpp/20260107.1/patches && \
		cp ${FILESDIR}/enolink.patch \
		modules/abseil-cpp/20260107.1/patches

do-build:
	cd ${WRKSRC}/src && ${LOCALBASE}/bin/bazel9 \
		${BAZEL_STARTUP_FLAGS} build ${BAZEL_BUILD_FLAGS} \
		--distdir=${BAZEL_DISTDIR_ALT} \
		--copt=-I/usr/X11R6/include \
		--linkopt=-L/usr/local/lib \
		--host_linkopt=-L/usr/local/lib \
		--action_env=LC_ALL=C.UTF-8 \
		server:mozc_server gui/tool:mozc_tool

do-install:
	${INSTALL_PROGRAM_DIR} "${PREFIX}/libexec/mozc"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/server/mozc_server" \
		"${PREFIX}/libexec/mozc/mozc_server"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/libexec/mozc/mozc_tool"

.include <bsd.port.mk>

