COMMENT =			Simple software midi player

VERSION =			0.5.0
DISTNAME =			wildmidi-${VERSION}
DISTFILES =			${DISTNAME}${EXTRACT_SUFX}
SITES =				https://github.com/Mindwerks/wildmidi/releases/download/wildmidi-${VERSION}/

SHARED_LIBS +=		WildMidi                  0.0 # 0.0

CATEGORIES =		audio

# LGPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB +=			m

COMPILER =			base-clang ports-gcc
COMPILER_LANGS =	c

MODULES +=			devel/cmake

CONFIGURE_ARGS =	-DWANT_PLAYER=OFF

.include <bsd.port.mk>
