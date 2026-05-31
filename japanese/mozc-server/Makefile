COMMENT =			Japanese Input Method Editor

VERSION =			3.33.6133
DISTNAME =			mozc-${VERSION}
PKGNAME =			mozc-server-${VERSION}

GH_ACCOUNT =		google
GH_PROJECT =		mozc
GH_TAGNAME =		${VERSION}

BCR_COMMIT_HASH =	a480ea6e068ef24a3deb7fd56243b1a7e4aa8259
DIST_TUPLE +=		github bazelbuild bazel-central-registry ${BCR_COMMIT_HASH} \
					bazel-central-registry

CATEGORIES=			japanese

MAINTAINER =		c2qd (https://codeberg.org/c2qd/openbsd_ports/issues)

BUILD_DEPENDS +=	devel/bazel/8

WANTLIB +=			${COMPILER_LIBCXX} c m pthread
COMPILER_LANGS =	c++
COMPILER =			base-clang

# BSD-3-Clause (Google) + IPAdic/NAIST/ICOT permissive + Public Domain
PERMIT_PACKAGE = 	Yes

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

pre-build:
	cd ${WRKSRC}/src && bazel fetch \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--config oss_linux \
		--platforms=//:openbsd-ex \
		server:mozc_server

do-build:
	cd ${WRKSRC}/src && bazel build \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--fetch=false \
		--config oss_linux \
		--platforms=//:openbsd-ex \
		--linkopt=-L/usr/local/lib \
		--host_linkopt=-L/usr/local/lib \
		server:mozc_server

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/mozc
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/server/mozc_server" "${PREFIX}/lib/mozc/mozc_server"

.include <bsd.port.mk>
