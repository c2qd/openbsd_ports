COMMENT =			Simple software midi player

VERSION =			0.5.0
REVISION =			0
DISTNAME =			wildmidi-${VERSION}
DISTFILES =			${DISTNAME}${EXTRACT_SUFX}
SITES =				https://github.com/Mindwerks/wildmidi/releases/download/wildmidi-${VERSION}/

SHARED_LIBS +=		WildMidi                  0.0 # 0.0

CATEGORIES =		audio

# LGPLv3+(lib) / GPLv3+(player)
PERMIT_PACKAGE =	Yes

WANTLIB +=			c m sndio

COMPILER =			base-clang ports-gcc
COMPILER_LANGS =	c

MODULES +=			devel/cmake

.include <bsd.port.mk>
