COMMENT =						Fcitx5 input method module for Mozc

GH_ACCOUNT =					fcitx
GH_PROJECT =					mozc
GH_COMMIT =						35898ee6c4f7424ae73000bbd754510d7ab772d0

VERSION =						3.34.6239.${GH_COMMIT}
DISTNAME =						fcitx-mozc-${VERSION}
PKGNAME =						fcitx-mozc-${VERSION}

CATEGORIES=						japanese

MAINTAINER =					c2qd

EXTRACT_ONLY =					fcitx-mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz \
								bazelbuild-bazel-central-registry-${BCR_COMMIT_HASH}.tar.gz

BUILD_DEPENDS +=				devel/gettext,-tools shells/bash
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

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS} && \
		cd ${WRKDIST}/bazel-central-registry && \
		mkdir modules/abseil-cpp/20260107.1/patches && \
		cp ${FILESDIR}/enolink.patch \
		modules/abseil-cpp/20260107.1/patches/

do-build:
	cd ${WRKSRC}/src && ${LOCALBASE}/bin/bazel9 ${BAZEL_STARTUP_FLAGS} build \
		${BAZEL_BUILD_FLAGS} unix/fcitx5:fcitx5-mozc.so

do-install:
	${INSTALL_PROGRAM_DIR} "${PREFIX}/lib/fcitx5"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/unix/fcitx5/fcitx5-mozc.so" \
		"${PREFIX}/lib/fcitx5/fcitx5-mozc.so"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5/addon"
	${INSTALL_DATA_DIR} "${PREFIX}/share/fcitx5/inputmethod"
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/128x128/apps"
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/32x32/apps"
	${INSTALL_DATA_DIR} "${PREFIX}/share/icons/hicolor/48x48/apps"
	cd ${WRKSRC}/src && ${LOCALBASE}/bin/bash ../scripts/install_fcitx5_data

.include <bsd.port.mk>
