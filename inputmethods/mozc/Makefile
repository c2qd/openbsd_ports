COMMENT-main =					Japanese Input Method Editor
COMMENT-tool =					GUI configuration tool for Mozc
COMMENT-fcitx =					Fcitx5 addon for Mozc

HOMEPAGE =						https://github.com/google/mozc
HOMEPAGE-fcitx =				https://github.com/fcitx/mozc

VERSION =						3.34.6239.20260915.01
DISTNAME =						mozc-${VERSION}

FULLPKGNAME-tool =				mozc-tool-${VERSION}
FULLPKGNAME-fcitx =				fcitx-mozc-${VERSION}
FULLPKGPATH-tool =				${PKGPATH},-tool
FULLPKGPATH-fcitx =				${PKGPATH},-fcitx

GH_ACCOUNT =					fcitx
GH_PROJECT =					mozc
GH_COMMIT =						07f544528a885c2d267f3e9b2937a1ebbe7edac2

MULTI_PACKAGES =				-main -tool -fcitx
FLAVORS =						ut
FLAVOR ?=

.include <bsd.port.arch.mk>

ONLY_FOR_ARCHS =				amd64 arm64

CATEGORIES=						inputmethods japanese

# non-ut flavor:
# BSD-3-Clause(mozc, protobuf) + Apache-2.0(abseil-cpp) + Zlib(zlib) +
# NAIST-2003(IPADic) + Public Domain(Okinawa dictionary, Zip code data) +
# BSD-2-Clause(Japanese usage dictionary)
# ut flavor:
# BSD-3-Clause(mozc, protobuf) + Zlib(zlib) + NAIST-2003(IPADic) +
# Public Domain(Okinawa dictionary, Zip code data, place-names) +
# BSD-2-Clause(Japanese usage dictionary) +
# Apache-2.0(abseil-cpp, personal-names, Neologd, SudachiDict)
PERMIT_PACKAGE =				Yes

ZIP_CODE_COMMIT =				621d059fbcbfae17bfca15b439692bae934268c3
DISTFILES.ja_usage_dict =		2025-01-25.zip
SITES.ja_usage_dict =			https://github.com/hiroyuki-komatsu/japanese-usage-dictionary/archive/refs/tags/
DISTFILES.zip_code_jigyosyo =	jigyosyo.zip
SITES.zip_code_jigyosyo =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT}/
DISTFILES.zip_code_ken_all =	ken_all.zip
SITES.zip_code_ken_all =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT}/

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

EXTRACT_ONLY =					${GH_DISTFILE} ${MODBAZEL_BCR_DISTFILE}

BUILD_DEPENDS +=				devel/gettext,-tools

WANTLIB +=						${COMPILER_LIBCXX} m
WANTLIB-main +=					${WANTLIB} c
WANTLIB-tool +=					${WANTLIB} Qt6Core Qt6Gui Qt6Widgets c
WANTLIB-fcitx +=				${WANTLIB} Fcitx5Config Fcitx5Core Fcitx5Utils

LIB_DEPENDS-tool +=				x11/qt6/qtbase
LIB_DEPENDS-fcitx +=			inputmethods/fcitx

RUN_DEPENDS-tool +=				devel/xdg-utils ${BASE_PKGPATH},-main
RUN_DEPENDS-fcitx +=			${BASE_PKGPATH},-main

COMPILER =						base-clang

WRKSRC =						${WRKDIST}/src

DIST_SUBDIR =					mozc

SUBST_TARGETS +=				${WRKSRC}/config.bzl \
								${WRKSRC}/MODULE.bazel \
								${WRKSRC}/base/system_util.cc \
								${WRKSRC}/base/process.cc \
								${WRKSRC}/bazel/rules_cc_bsd_cc_toolchain_config.bzl.patch

MODULES +=						devel/bazel lang/python

MODBAZEL_VERSION =				9

MODBAZEL_BCR_COMMIT =			2459648091f2c5b8e21a46613cf39bffb6fba298

MODBAZEL_CONFIGS =				oss_linux release_build

MODPY_RUNDEP =					No

ALL_TARGET =					server:mozc_server gui/tool:mozc_tool unix/fcitx5:fcitx5-mozc.so

CFLAGS +=						-I${X11BASE}/include
LDFLAGS +=						-L${LOCALBASE}/lib

MAKE_ENV +=						LC_CTYPE=C.UTF-8

L10N_LANGS =					ca da de fr he ja ka ko ru sv tr vi zh_CN zh_TW

post-extract:
	cp ${FILESDIR}/abseil_cpp_absl_status_status.cc.patch \
		${FILESDIR}/rules_cc_bsd_cc_toolchain_config.bzl.patch \
		${FILESDIR}/rules_go_go_private_sdk.bzl.patch \
		${WRKSRC}/bazel

pre-patch:
	@if [ $$(ulimit -Sd) != "unlimited" ] && [ $$(ulimit -Sd) -lt $$((3*1024*1024)) ]; then \
		echo "datasize limit is too low. Build needs approximately 3GiB."; \
		exit 1; \
	fi
.if ${FLAVOR:Mut}
	cp ${FULLDISTDIR}/${UT_COMMIT}.py \
		${WRKDIST}/merge_dictionaries.py
.endif

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}
	${SUBST_CMD} -DCC=${CC} -DLD=${LD} -DWRKDIR=${WRKDIR} \
		${WRKSRC}/bazel/rules_cc_bsd_cc_toolchain_config.bzl.patch
.if ${FLAVOR:Mut}
	${SUBST_CMD} -DJAWIKI_INDEX_FILE=${SUPDISTFILES.jawiki_index} \
		${WRKDIST}/merge_dictionaries.py
	cd ${FULLDISTDIR} && \
		cp {${UT_PERSONAL_NAMES_COMMIT},${WRKDIST}/mozcdic-ut-personal-names}.txt.bz2 && \
		cp {${UT_PLACE_NAMES_COMMIT},${WRKDIST}/mozcdic-ut-place-names}.txt.bz2 && \
		cp {${UT_NEOLOGD_COMMIT},${WRKDIST}/mozcdic-ut-neologd}.txt.bz2 && \
		cp {${UT_SUDACHIDICT_COMMIT},${WRKDIST}/mozcdic-ut-sudachidict}.txt.bz2 && \
		cp ${SUPDISTFILES.jawiki_index} ${WRKDIST}
	cd ${WRKDIST} && bzip2 -d mozcdic-ut-*.txt.bz2 && \
		cat mozcdic-ut-*.txt > mozcdic-ut.txt && \
		${MODPY_BIN} merge_dictionaries.py mozcdic-ut.txt && \
		cat mozcdic-ut.txt >> ${WRKSRC}/data/dictionary_oss/dictionary00.txt
.endif

pre-install:
.if ${BUILD_PACKAGES:M-fcitx}
	cd ${WRKSRC} && msgfmt --xml -d unix/fcitx5/po/ \
		--template unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml.in \
		-o unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml
.for lang in ${L10N_LANGS}
	msgfmt ${WRKSRC}/unix/fcitx5/po/${lang}.po \
		-o ${WRKSRC}/unix/fcitx5/po/${lang}.mo
.endfor
.endif

do-install:
.if ${BUILD_PACKAGES:M-main}
	${INSTALL_PROGRAM_DIR} "${PREFIX}/libexec/mozc"
	${INSTALL_PROGRAM} "${WRKSRC}/bazel-bin/server/mozc_server" \
		"${PREFIX}/libexec/mozc/mozc_server"
	${INSTALL_DATA_DIR} "${PREFIX}/share/doc/mozc"
	${INSTALL_DATA} "${WRKSRC}/data/installer/credits_en.html" \
		"${PREFIX}/share/doc/mozc/credits_en.html"
.	if ${FLAVOR:Mut}
	${INSTALL_DATA} "${FILESDIR}/LICENSE-2.0.txt" \
		"${PREFIX}/share/doc/mozc/LICENSE-2.0.txt"
	${INSTALL_DATA} "${FILESDIR}/LICENSE_NEOLOGD" \
		"${PREFIX}/share/doc/mozc/LICENSE_NEOLOGD"
	${INSTALL_DATA} "${FILESDIR}/LICENSE_SUDACHIDICT" \
		"${PREFIX}/share/doc/mozc/LICENSE_SUDACHIDICT"
	${INSTALL_DATA} "${FILESDIR}/LEGAL_SUDACHIDICT" \
		"${PREFIX}/share/doc/mozc/LEGAL_SUDACHIDICT"
.	endif
.endif
.if ${BUILD_PACKAGES:M-tool}
	${INSTALL_PROGRAM} "${WRKSRC}/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/libexec/mozc/mozc_tool"
.endif
.if ${BUILD_PACKAGES:M-fcitx}
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
.endif

post-install:
.if ${BUILD_PACKAGES:M-fcitx}
	cd ${WRKSRC} && rm -f unix/fcitx5/po/*.mo
.endif

.include "bazel.inc"

.include <bsd.port.mk>
