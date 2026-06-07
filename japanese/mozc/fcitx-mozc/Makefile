COMMENT =						Fcitx5 input method module for Mozc

VERSION =						3.33.6133
DISTNAME =						fcitx-mozc-${VERSION}
PKGNAME =						fcitx-mozc-${VERSION}

GH_ACCOUNT =					fcitx
GH_PROJECT =					mozc
GH_COMMIT =						045e5d9b38f6629b258f8f931533e5fe17f68a1d

CATEGORIES=						japanese

MAINTAINER =					c2qd (https://codeberg.org/c2qd/openbsd_ports/issues)

EXTRACT_ONLY =					fcitx-mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz bazelbuild-bazel-central-registry-${BCR_COMMIT_HASH}.tar.gz

BUILD_DEPENDS +=				devel/bazel/9 devel/gettext,-tools shells/bash
LIB_DEPENDS +=					inputmethods/fcitx
RUN_DEPENDS +=					japanese/mozc/mozc

WANTLIB +=						${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Utils
WANTLIB +=						c m pthread
COMPILER_LANGS =				c++
COMPILER =						base-clang

# BSD-3-Clause + LGPL-2.1 or later(Part of the code in src/unix/fcitx5)
# Warning: I don't know anything about licenses~
#          Please determine whether to set PERMIT_PACKAGE to Y/n.
PERMIT_PACKAGE =				No

pre-build:
	mkdir -p ${WRKOBJDIR}/_bazel_tmp

do-build:
	cd ${WRKSRC}/src && ${LOCALBASE}/bin/bazel9 \
		--output_user_root=${WRKOBJDIR}/_bazel_tmp build \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--distdir=${FULLDISTDIR} \
		--config oss_linux \
		--config release_build \
		--platforms=//:openbsd-ex \
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
