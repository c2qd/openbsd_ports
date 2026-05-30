COMMENT =			Graphical configuration tool for Mozc

VERSION =			3.33.6133
DISTNAME =			mozc-${VERSION}
PKGNAME =			mozc-tool-${VERSION}

GH_ACCOUNT =		google
GH_PROJECT =		mozc
GH_TAGNAME =		${VERSION}

BCR_COMMIT_HASH =	a480ea6e068ef24a3deb7fd56243b1a7e4aa8259
DIST_TUPLE +=		github bazelbuild bazel-central-registry ${BCR_COMMIT_HASH} \
					bazel-central-registry

CATEGORIES=			japanese

MAINTAINER =		c2qd (https://codeberg.org/c2qd/openbsd_ports/issues)

WANTLIB +=			${COMPILER_LIBCXX} Qt6Core Qt6Gui Qt6Widgets
WANTLIB +=			c m execinfo z X11
LIB_DEPENDS +=		x11/qt6/qtbase \
					x11/xkbcommon \
					x11/dbus\
					textproc/icu4c \
					converters/libiconv \
					archivers/zstd \
					math/double-conversion \
					security/libb2 \
					devel/pcre2 \
					devel/glib2 \
					devel/harfbuzz \
					devel/gettext \
					graphics/png \
					sysutils/syslog-ng

BUILD_DEPENDS +=	devel/bazel/8

MODULES +=			x11/qt6

COMPILER_LANGS =	c++
COMPILER =			base-clang

# BSD-3-Clause
PERMIT_PACKAGE = 	Yes

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

pre-build:
	cd ${WRKSRC}/src && env JAVA_HOME=${LOCALBASE}/jdk-21 bazel fetch \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--config oss_linux \
		--compilation_mode=opt \
		--platforms=//:openbsd-x86_64 \
		gui/tool:mozc_tool

do-build:
	cd ${WRKSRC}/src && env JAVA_HOME=${LOCALBASE}/jdk-21 bazel build \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--fetch=false \
		--config oss_linux \
		--compilation_mode=opt \
		--platforms=//:openbsd-x86_64 \
		--copt=-I/usr/X11R6/include \
		--linkopt=-L${LOCALBASE}/lib \
		--host_linkopt=-L${LOCALBASE}/lib \
		gui/tool:mozc_tool

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/mozc
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/lib/mozc/mozc_tool"

.include <bsd.port.mk>
