# Keep in sync with games/easyrpg
COMMENT =			library for handling RPG Maker 2000/2003 data

GH_ACCOUNT =		EasyRPG
GH_PROJECT =		liblcf
GH_TAGNAME =		0.8.1

CATEGORIES =		games x11

MAINTAINER =		c2qd

SHARED_LIBS +=		lcf                       1.0 # 1.0

HOMEPAGE =			https://easyrpg.org/

# GPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB +=			${COMPILER_LIBCXX} expat icudata icui18n icuuc inih c m

COMPILER =			base-clang ports-gcc

BUILD_DEPENDS =		devel/gettext,-tools

LIB_DEPENDS =		textproc/icu4c textproc/libinih

RUN_DEPENDS =		misc/shared-mime-info

MODULES +=			devel/cmake

CONFIGURE_ARGS +=	-DLIBLCF_UPDATE_MIMEDB=OFF

.include <bsd.port.mk>
