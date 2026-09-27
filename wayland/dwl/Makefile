COMMENT =			dwm for Wayland

VERSION =			0.9
DISTNAME =			dwl-${VERSION}

HOMEPAGE =			https://codeberg.org/dwl/dwl

CATEGORIES =		wayland

# GPLv3 + MIT/X + MIT + CC0
PERMIT_PACKAGE =	Yes

WRKDIST =			${WRKDIR}/dwl-v${VERSION}

DISTFILES =			dwl-v${VERSION}${EXTRACT_SUFX}
SITES =				https://codeberg.org/dwl/dwl/releases/download/v${VERSION}/

BUILD_DEPENDS =		wayland/wayland-protocols

WANTLIB +=			c input m wayland-server wlroots-0.20 xcb xcb-icccm xkbcommon

LIB_DEPENDS =		wayland/libinput-openbsd \
					wayland/wayland \
					wayland/wlroots/0.20 \
					x11/xkbcommon

RUN_DEPENDS =		wayland/xwayland

COMPILER =			base-clang ports-gcc

.include <bsd.port.mk>
