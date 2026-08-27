COMMENT =						Fcitx5 input method module for Mozc

HOMEPAGE =						https://github.com/fcitx/mozc

GH_ACCOUNT =					fcitx
GH_PROJECT =					mozc
GH_COMMIT =						4d5f74412c30bf82325730c77c87d9ee2d4807bb

VERSION =						3.34.6239.20260826
DISTNAME =						fcitx-mozc-${VERSION}

ONLY_FOR_ARCHS =				amd64 arm64

CATEGORIES=						inputmethods japanese

MAINTAINER =					c2qd

# BSD-3-Clause + Zlib(zlib) + BSD-3-Clause(protobuf) + Apache-2.0(abseil-cpp)
# LGPL-2.1 or later(Part of the code in src/unix/fcitx5)
PERMIT_PACKAGE =				No

EXTRACT_ONLY =					fcitx-mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								${MODBAZEL_BCR_DISTFILE}

BUILD_DEPENDS +=				devel/gettext,-tools
LIB_DEPENDS +=					inputmethods/fcitx
RUN_DEPENDS +=					inputmethods/mozc/mozc

WANTLIB +=						${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Utils
WANTLIB +=						c m
COMPILER_LANGS =				c++
COMPILER =						base-clang

ALL_TARGET =					unix/fcitx5:fcitx5-mozc.so

LDFLAGS +=						-L${LOCALBASE}/lib

NO_TEST =						Yes

L10N_LANGS =					ca da de fr he ja ka ko ru tr vi zh_CN zh_TW

ICONS =							ui-alpha_full ui-alpha_half ui-direct ui-hiragana \
								ui-katakana_full ui-katakana_half ui-dictionary \
								ui-properties ui-tool

post-extract:
	cp ${FILESDIR}/abseil_cpp_absl_status_status.cc.patch \
		${FILESDIR}/rules_cc_bsd_cc_toolchain_config.bzl.patch \
		${FILESDIR}/rules_go_go_private_sdk.bzl.patch \
		${WRKSRC}/bazel

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
.for icon in ${ICONS}
	${INSTALL_DATA} "${WRKDIST}/scripts/icons/${icon}.png" \
		"${PREFIX}/share/icons/hicolor/48x48/apps/org.fcitx.Fcitx5.fcitx_mozc_${icon:S/ui-//}.png"
	ln -sf "org.fcitx.Fcitx5.fcitx_mozc_${icon:S/ui-//}.png" \
		"${PREFIX}/share/icons/hicolor/48x48/apps/fcitx_mozc_${icon:S/ui-//}.png"
.endfor

post-install:
	cd ${WRKSRC} && rm unix/fcitx5/po/*.mo

.include <bsd.port.mk>
