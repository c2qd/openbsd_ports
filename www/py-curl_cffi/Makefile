COMMENT =				Python binding for curl-impersonate

HOMEPAGE =				https://curl-cffi.readthedocs.io/

VERSION =				0.16.2
DISTNAME =				curl_cffi-${VERSION}
PKGNAME =				py-${DISTNAME}
CATEGORIES =			www

ONLY_FOR_ARCHS =		amd64 arm64

# MIT + Zlib(zlib) + BSD-3-Clause(zstd) +
# MIT(brotli, nghttp2, ngtcp2, nghttp3) + Apache-2.0(boringssl) + curl(curl)
PERMIT_PACKAGE =		No

DISTFILES =				${DISTNAME}${EXTRACT_SUFX}

SITES =					https://github.com/lexiforest/curl_cffi/releases/download/v${VERSION}/

MAINTAINER =			c2qd

WANTLIB +=				${COMPILER_LIBCXX} curl-impersonate

BUILD_DEPENDS =			devel/py-cffi>=2.0.0
LIB_DEPENDS =			www/curl-impersonate
RUN_DEPENDS =   		devel/py-cffi>=2.0.0 devel/py-certifi>=2024.2.2

WANTLIB +=				curl-impersonate

MODULES =				lang/python
MODPY_PYBUILD =			setuptools

COMPILER =				base-clang

MAKE_ENV +=				IMPERSONATE_BUILD_DIR=${LOCALBASE}/lib


CFLAGS +=				-I${LOCALBASE}/include/curl-impersonate

.include <bsd.port.mk>
