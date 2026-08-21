COMMENT =			Free interpreter for RPG Maker 2000/2003 and EasyRPG games

VERSION =			0.8.1.1
DISTNAME =			easyrpg-player-${VERSION}
DISTFILES =			${DISTNAME}${EXTRACT_SUFX}
SITES =				https://easyrpg.org/downloads/player/${VERSION}/

CATEGORIES =		games x11

HOMEPAGE =			https://easyrpg.org/

# GPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB +=			${COMPILER_LIBCXX} SDL3 c expat fmt freetype harfbuzz
WANTLIB +=			icudata icui18n icuuc inih lcf m mpg123 ogg opus
WANTLIB +=			opusfile pixman-1 png sndfile speexdsp
WANTLIB +=			vorbis vorbisfile xmp z

COMPILER =			base-clang ports-gcc

MODULES +=			devel/cmake

BUILD_DEPENDS +=	textproc/asciidoctor textproc/nlohmann-json

LIB_DEPENDS +=		audio/libsndfile audio/libxmp audio/mpg123 \
					audio/opusfile audio/speexdsp devel/fmt \
					devel/harfbuzz devel/sdl3 games/liblcf \
					graphics/png textproc/libinih

RUN_DEPENDS +=		devel/desktop-file-utils x11/gtk+4,-guic

CONFIGURE_ARGS =	-DPLAYER_TARGET_PLATFORM=SDL3

CONFIGURE_ENV =		CXXFLAGS="${CXXFLAGS} -I ${X11BASE}/include" \
					LDFLAGS="-L ${X11BASE}/lib"
MAKE_ENV =			${CONFIGURE_ENV}

# make test seems bogus, disabling it.
NO_TEST =	Yes

.include <bsd.port.mk>
