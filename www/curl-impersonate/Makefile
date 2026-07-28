COMMENT =               Special curl build that can impersonate major browsers

VERSION =               2.0.0rc5
DISTNAME =              curl-impersonate-${VERSION}
CATEGORIES =            net www

SHARED_LIBS =			curl-impersonate                0.0 # 0.0

GH_ACCOUNT =            lexiforest
GH_PROJECT =            curl-impersonate
GH_TAGNAME =            v${VERSION}

DIST_SUBDIR =			curl-impersonate

ZLIB_VERSION =			1.3.1
ZSTD_VERSION =			1.5.7
BROTLI_VERSION =		1.2.0
BORINGSSL_COMMIT =		156c7b75ae9b8c3b3f847acf264f17594c3859fb
NGHTTP2_VERSION =		1.63.0
NGTCP2_VERSION =		1.20.0
NGHTTP3_VERSION =		1.15.0
CURL_VERSION =			curl-8_21_0
DISTFILES.zlib =		zlib-${ZLIB_VERSION}.tar.gz
SITES.zlib =			https://github.com/madler/zlib/releases/download/v${ZLIB_VERSION}/
DISTFILES.zstd =		zstd-${ZSTD_VERSION}.tar.gz
SITES.zstd =			https://github.com/facebook/zstd/releases/download/v${ZSTD_VERSION}/
DISTFILES.brotli =		v${BROTLI_VERSION}.tar.gz
SITES.brotli =			https://github.com/google/brotli/archive/refs/tags/
DISTFILES.boringssl =	${BORINGSSL_COMMIT}.zip
SITES.boringssl =		https://github.com/google/boringssl/archive/
DISTFILES.nghttp2 =		nghttp2-${NGHTTP2_VERSION}.tar.bz2
SITES.nghttp2 =			https://github.com/nghttp2/nghttp2/releases/download/v${NGHTTP2_VERSION}/
DISTFILES.ngtcp2 =		ngtcp2-${NGTCP2_VERSION}.tar.bz2
SITES.ngtcp2 =			https://github.com/ngtcp2/ngtcp2/releases/download/v${NGTCP2_VERSION}/
DISTFILES.nghttp3 =		nghttp3-${NGHTTP3_VERSION}.tar.bz2
SITES.nghttp3 =			https://github.com/ngtcp2/nghttp3/releases/download/v${NGHTTP3_VERSION}/
DISTFILES.curl =		${CURL_VERSION}.tar.gz
SITES.curl =			https://github.com/curl/curl/archive/

EXTRACT_ONLY =			${GH_PROJECT}-${VERSION}.tar.gz

MAINTAINER =			c2qd

BUILD_DEPENDS =			devel/ninja

RUN_DEPENDS +=			shells/bash

WANTLIB +=				${COMPILER_LIBCXX} c

MODULES =				devel/cmake

CONFIGURE_ARGS =		-DCMAKE_INSTALL_INCLUDEDIR=include/curl-impersonate \
						-DFULLDISTDIR=${FULLDISTDIR}
# MIT
PERMIT_PACKAGE =		Yes

COMPILER =				base-clang

.include <bsd.port.mk>
