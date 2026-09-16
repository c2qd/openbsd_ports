COMMENT =				Python binding for curl-impersonate

MODPY_DISTV =			0.16.3
REVISION =				0
DISTNAME =				curl_cffi-${MODPY_DISTV}
PKGNAME =				py-${DISTNAME}
CATEGORIES =			net www

ONLY_FOR_ARCHS =		amd64 arm64 riscv64

# MIT
PERMIT_PACKAGE =		Yes

WANTLIB +=				curl-impersonate

BUILD_DEPENDS =			devel/py-cffi>=2.0.0
LIB_DEPENDS =			net/curl-impersonate
RUN_DEPENDS =   		devel/py-cffi>=2.0.0 devel/py-certifi>=2024.2.2

MODULES =				lang/python
MODPY_PI =				Yes
MODPY_PYBUILD =			setuptools

COMPILER =				base-clang ports-gcc

MAKE_ENV +=				IMPERSONATE_BUILD_DIR=${LOCALBASE}/lib \
						IMPERSONATE_LINK_TYPE=dynamic

CFLAGS +=				-I${LOCALBASE}/include/curl-impersonate

.include <bsd.port.mk>
