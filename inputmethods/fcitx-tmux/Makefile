COMMENT =			Tmux plugin to make tmux as a fcitx 5 client

VERSION =			20251230
REVISION =			0
DISTNAME =			fcitx5-tmux-${VERSION}
PKGNAME =			${DISTNAME:S/fcitx5/fcitx/}

CATEGORIES =		inputmethods

# GPLv2.0+
PERMIT_PACKAGE =	Yes

GH_ACCOUNT =		wengxt
GH_PROJECT =		fcitx5-tmux
GH_COMMIT =			fe96f85bc01685540c607742cbc317db94c94683

WANTLIB +=			${COMPILER_LIBCXX} Fcitx5Utils c m

LIB_DEPENDS =		inputmethods/fcitx

RUN_DEPENDS =		inputmethods/fcitx \
					shells/bash \
					x11/dbus,-main

MODULES =			devel/cmake

COMPILER =			base-clang ports-gcc

.include <bsd.port.mk>
