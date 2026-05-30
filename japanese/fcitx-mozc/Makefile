COMMENT =			Fcitx5 input method module for Mozc

VERSION =			3.33.6133
DISTNAME =			fcitx-mozc-${VERSION}
PKGNAME =			fcitx-mozc-${VERSION}

GH_ACCOUNT =		fcitx
GH_PROJECT =		mozc
GH_COMMIT =  		a8652b9253b77b7e9039801d8814dbb5f3f4b274

BCR_COMMIT_HASH =	a480ea6e068ef24a3deb7fd56243b1a7e4aa8259
DIST_TUPLE +=		github bazelbuild bazel-central-registry ${BCR_COMMIT_HASH} \
					bazel-central-registry

CATEGORIES=			japanese

MAINTAINER =		c2qd (https://codeberg.org/c2qd/openbsd_ports/issues)

BUILD_DEPENDS +=	devel/bazel/8 inputmethods/fcitx devel/gettext,-tools \
					shells/bash
LIB_DEPENDS +=		inputmethods/fcitx

WANTLIB +=			${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Utils
WANTLIB +=			m pthread
COMPILER_LANGS =	c++
COMPILER =			base-clang

# BSD-3-Clause
PERMIT_PACKAGE = 	Yes

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

pre-build:
	cd ${WRKSRC}/src && bazel fetch \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--config oss_linux \
		--platforms=//:openbsd-x86_64 \
		unix/fcitx5:fcitx5-mozc.so

do-build:
	cd ${WRKSRC}/src && bazel build \
		--fetch=false \
		--config oss_linux \
		--platforms=//:openbsd-x86_64 \
		unix/fcitx5:fcitx5-mozc.so

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
