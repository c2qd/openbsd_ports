COMMENT =				Python binding for curl-impersonate

VERSION =				0.15.0
REVISION =				0
DISTNAME =				curl_cffi-${VERSION}
PKGNAME =				py-${DISTNAME}
CATEGORIES =			www

ONLY_FOR_ARCHS =		amd64

GH_ACCOUNT =			lexiforest
GH_PROJECT =			curl_cffi
GH_TAGNAME =			v${VERSION}

MAINTAINER =			c2qd

LIB_DEPENDS =			www/curl-impersonate
RUN_DEPENDS =   		devel/py-cffi>=2.0.0 devel/py-certifi>=2024.2.2

WANTLIB +=				curl-impersonate

MODULES =				lang/python
MODPY_PYBUILD =			setuptools

# MIT + Zlib(zlib) + BSD-3-Clause(zstd) +
# MIT(brotli, nghttp2, ngtcp2, nghttp3) + Apache-2.0(boringssl) + curl(curl)
PERMIT_PACKAGE =		No

COMPILER_LANGS =		c
COMPILER =				base-clang

# for 0.16
# ToDo: rm libdir from patch-libs_json (when upd to 0.16)
# MAKE_ENV +=				IMPERSONATE_BUILD_DIR=${LOCALBASE}/lib \
# 						IMPERSONATE_LINK_TYPE=dynamic

CFLAGS +=				-I${LOCALBASE}/include/curl-impersonate

SUBST_VARS =			LOCALBASE
SUBST_TARGETS =			${WRKSRC}/libs.json

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}

.include <bsd.port.mk>
