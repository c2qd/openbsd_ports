COMMENT =               Special curl build that can impersonate major browsers

HOMEPAGE =				https://curl-impersonate.readthedocs.io/

VERSION =               2.2.3
DISTNAME =              curl-impersonate-${VERSION}
CATEGORIES =            net www

# Cannot build BoringSSL
NOT_FOR_ARCHS +=		${BE_ARCHS}

SHARED_LIBS +=			curl-impersonate                0.0 # 0.0

GH_ACCOUNT =            lexiforest
GH_PROJECT =            curl-impersonate
GH_TAGNAME =            v${VERSION}

# MIT + Zlib(zlib) + BSD-3-Clause(zstd) +
# MIT(brotli, nghttp2, ngtcp2, nghttp3) + Apache-2.0(boringssl) + curl(curl)
PERMIT_PACKAGE =		Yes

DIST_SUBDIR =			curl-impersonate

DISTFILES.zlib =		zlib-1.3.1.tar.gz
SITES.zlib =			https://github.com/madler/zlib/releases/download/v1.3.1/
DISTFILES.zstd =		zstd-1.5.7.tar.gz
SITES.zstd =			https://github.com/facebook/zstd/releases/download/v1.5.7/
DISTFILES.brotli =		v1.2.0.tar.gz
SITES.brotli =			https://github.com/google/brotli/archive/refs/tags/
DISTFILES.boringssl =	156c7b75ae9b8c3b3f847acf264f17594c3859fb.zip
SITES.boringssl =		https://github.com/google/boringssl/archive/
DISTFILES.nghttp2 =		nghttp2-1.63.0.tar.bz2
SITES.nghttp2 =			https://github.com/nghttp2/nghttp2/releases/download/v1.63.0/
DISTFILES.ngtcp2 =		ngtcp2-1.20.0.tar.bz2
SITES.ngtcp2 =			https://github.com/ngtcp2/ngtcp2/releases/download/v1.20.0/
DISTFILES.nghttp3 =		nghttp3-1.15.0.tar.bz2
SITES.nghttp3 =			https://github.com/ngtcp2/nghttp3/releases/download/v1.15.0/
DISTFILES.cares =		c-ares-1.34.8.tar.gz
SITES.cares =			https://github.com/c-ares/c-ares/releases/download/v1.34.8/
DISTFILES.curl =		curl-8_22_0.tar.gz
SITES.curl =			https://github.com/curl/curl/archive/

EXTRACT_ONLY =			${GH_DISTFILE}

# Required by the wrapper scripts
RUN_DEPENDS +=			shells/bash

WANTLIB +=				${COMPILER_LIBCXX} c m

MODULES +=				devel/cmake

COMPILER =				base-clang ports-gcc

CONFIGURE_ARGS =		-DCMAKE_INSTALL_INCLUDEDIR=include/curl-impersonate \
						-DSUBJOBS=${MAKE_JOBS} \
						-DPATCH_EXE=${PATCH}

SUBST_VARS +=			FULLDISTDIR

SUBST_TARGETS +=		${WRKSRC}/CMakeLists.txt

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}

post-build:
	cd ${WRKBUILD} && ${LOCALBASE}/bin/cmake -P CollectLicenses.cmake

post-install:
	${INSTALL_DATA_DIR} "${PREFIX}/share/doc/curl-impersonate"
	find ${WRKBUILD}/licenses -type f -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/share/doc/curl-impersonate" \;

.include <bsd.port.mk>
