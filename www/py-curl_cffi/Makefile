COMMENT =				Python binding for curl-impersonate

HOMEPAGE =				https://curl-cffi.readthedocs.io/

VERSION =				0.16.3
REVISION =				0
DISTNAME =				curl_cffi-${VERSION}
PKGNAME =				py-${DISTNAME}
CATEGORIES =			www

ONLY_FOR_ARCHS =		amd64 arm64 riscv64

# MIT
PERMIT_PACKAGE =		Yes

DISTFILES =				${DISTNAME}${EXTRACT_SUFX}

SITES =					https://github.com/lexiforest/curl_cffi/releases/download/v${VERSION}/

MAINTAINER =			c2qd

WANTLIB +=				curl-impersonate

BUILD_DEPENDS =			devel/py-cffi>=2.0.0
LIB_DEPENDS =			www/curl-impersonate
RUN_DEPENDS =   		devel/py-cffi>=2.0.0 devel/py-certifi>=2024.2.2

MODULES =				lang/python
MODPY_PYBUILD =			setuptools

COMPILER =				base-clang ports-gcc

MAKE_ENV +=				IMPERSONATE_BUILD_DIR=${LOCALBASE}/lib \
						IMPERSONATE_LINK_TYPE=dynamic

CFLAGS +=				-I${LOCALBASE}/include/curl-impersonate

.include <bsd.port.mk>
