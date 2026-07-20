COMMENT =						Fcitx5 input method module for Mozc

HOMEPAGE =						https://github.com/fcitx/mozc

GH_ACCOUNT =					fcitx
GH_PROJECT =					mozc
GH_COMMIT =						3f9b1bd6d089cef2e1e8814d7de25291e730274b

VERSION =						3.34.6239.20260719.git${GH_COMMIT:C/^(.{8}).*/\1/}
REVISION =						1
DISTNAME =						fcitx-mozc-${VERSION}
PKGNAME =						fcitx-mozc-${VERSION}

CATEGORIES=						japanese

MAINTAINER =					c2qd

EXTRACT_ONLY =					fcitx-mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								bazelbuild-bazel-central-registry-${BCR_COMMIT}.tar.gz

BUILD_DEPENDS +=				devel/gettext,-tools
LIB_DEPENDS +=					inputmethods/fcitx
RUN_DEPENDS +=					japanese/mozc/mozc

WANTLIB +=						${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Utils
WANTLIB +=						c m
COMPILER_LANGS =				c++
COMPILER =						base-clang

# BSD-3-Clause + LGPL-2.1 or later(Part of the code in src/unix/fcitx5)
# Warning: I don't know anything about licenses~
#          Please determine whether to set PERMIT_PACKAGE to Y/n.
PERMIT_PACKAGE =				No

MOFILES =						ca da de fr he ja ka ko ru tr vi zh_CN zh_TW

ICONS =							ui-alpha_full ui-alpha_half ui-direct ui-hiragana \
								ui-katakana_full ui-katakana_half ui-dictionary \
								ui-properties ui-tool

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

pre-patch:
	cp ${FILESDIR}/pyinterpreter_fallback.patch \
		${WRKDIST}/bazel-central-registry/modules/rules_python/1.9.0/patches  && \
		cp ${FILESDIR}/versions_json.patch \
		${WRKDIST}/bazel-central-registry/modules/rules_go/0.60.0/patches

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS} && \
		cd ${WRKSRC} && \
		PYIF_HASH=$$(sha256 -bq bazel-central-registry/modules/rules_python/1.9.0/patches/pyinterpreter_fallback.patch); \
		${SUBST_CMD} \
		-DPYIF_HASH=$${PYIF_HASH} ${SUBST_TARGETS_EX}
		cd ${WRKDIST}/bazel-central-registry && \
		mkdir modules/abseil-cpp/20260107.1/patches && \
		cp ${FILESDIR}/enolink.patch \
		modules/abseil-cpp/20260107.1/patches/

do-build:
	cd ${WRKSRC}/src && ${BAZEL_ENVS} ${LOCALBASE}/bin/bazel9 \
		${BAZEL_STARTUP_FLAGS} build \
		${BAZEL_BUILD_FLAGS} unix/fcitx5:fcitx5-mozc.so

pre-install:
	cd ${WRKSRC}/src && ../scripts/install_fcitx5_data

do-install:
	${INSTALL_PROGRAM_DIR} "${PREFIX}/lib/fcitx5"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/unix/fcitx5/fcitx5-mozc.so" \
		"${PREFIX}/lib/fcitx5/fcitx5-mozc.so"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5/addon"
	${INSTALL_DATA} "${WRKSRC}/src/unix/fcitx5/mozc-addon.conf" \
		"${PREFIX}/share/fcitx5/addon/mozc.conf"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5/inputmethod"
	${INSTALL_DATA} "${WRKSRC}/src/unix/fcitx5/mozc.conf" \
		"${PREFIX}/share/fcitx5/inputmethod/mozc.conf"
	${INSTALL_DATA_DIR} "${PREFIX}/share/metainfo"
	${INSTALL_DATA} "${WRKSRC}/src/unix/fcitx5/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml" \
		"${PREFIX}/share/metainfo/org.fcitx.Fcitx5.Addon.Mozc.metainfo.xml"
.for lang in ${MOFILES}
	${INSTALL_DATA_DIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/src/unix/fcitx5/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/fcitx5-mozc.mo
.endfor
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/128x128/apps"
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/32x32/apps"
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/48x48/apps"
	${INSTALL_DATA} "${WRKSRC}/src/data/images/product_icon_32bpp-128.png" \
		"${PREFIX}/share/icons/hicolor/128x128/apps/org.fcitx.Fcitx5.fcitx_mozc.png"
	${INSTALL_DATA} "${WRKSRC}/src/data/images/unix/ime_product_icon_opensource-32.png" \
		"${PREFIX}/share/icons/hicolor/32x32/apps/org.fcitx.Fcitx5.fcitx_mozc.png"
.for icon in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/scripts/icons/${icon}.png \
		${PREFIX}/share/icons/hicolor/48x48/apps/org.fcitx.Fcitx5.fcitx_mozc_${icon:S/ui-//}.png
	${LN} -sf org.fcitx.Fcitx5.fcitx_mozc_${icon:S/ui-//}.png \
		${PREFIX}/share/icons/hicolor/48x48/apps/fcitx_mozc_${icon:S/ui-//}.png
.endfor

post-install:
	cd ${WRKSRC}/src && rm unix/fcitx5/po/*.mo

.include <bsd.port.mk>
