COMMENT =				flexible input method framework

DISTNAME =				fcitx5-5.1.22
REVISION =				0
PKGNAME =				${DISTNAME:S/fcitx5/fcitx/}

SHARED_LIBS +=			Fcitx5Config                    0.1 # 0.0
SHARED_LIBS +=			Fcitx5Core                      1.2 # 0.0
SHARED_LIBS +=			Fcitx5Utils                     2.0 # 0.0

CATEGORIES =			inputmethods chinese japanese korean

HOMEPAGE =				https://fcitx-im.org/

# LGPLv2.1+
PERMIT_PACKAGE=			Yes

SITES =					https://download.fcitx-im.org/fcitx5/fcitx5/
SITES.data =			https://download.fcitx-im.org/data/
DISTFILES.data=			en_dict-20121020.tar.gz

EXTRACT_SUFX =			.tar.zst

# 5.1.22 only
PATCHFILES.syncstream =	fcitx5-70488af0ae-osyncstream{70488af0ae335ad896a94e828df6891e6d696418}.patch
SITES.syncstream =		https://github.com/fcitx/fcitx5/commit/

PATCH_DIST_STRIP =		-p1

WANTLIB +=				${COMPILER_LIBCXX} c cairo dbus-1 enchant-2
WANTLIB +=				execinfo expat gdk_pixbuf-2.0 gio-2.0 glib-2.0
WANTLIB +=				gobject-2.0 harfbuzz intl kvm m pango-1.0
WANTLIB +=				pangocairo-1.0 rsvg-2 uuid uv wayland-client wayland-cursor
WANTLIB +=				xcb xcb-ewmh xcb-icccm xcb-imdkit xcb-keysyms
WANTLIB +=				xcb-randr xcb-render xcb-shape xcb-util xcb-xfixes
WANTLIB +=				xcb-xinerama xcb-xkb xkbcommon xkbcommon-x11 xkbfile z

MODULES =				devel/cmake

BUILD_DEPENDS =         devel/kf6/extra-cmake-modules \
						devel/gettext,-tools \
                        devel/iso-codes \
						textproc/nlohmann-json \
						wayland/wayland

# bash: for fcitx5-diagnose.sh
RUN_DEPENDS =           devel/desktop-file-utils \
                        misc/shared-mime-info \
                        shells/bash \
                        x11/gtk+4,-guic

LIB_DEPENDS =           devel/harfbuzz,-main \
                        devel/libuv \
                        devel/pango \
                        graphics/gdk-pixbuf2 \
                        inputmethods/xcb-imdkit \
                        sysutils/e2fsprogs \
                        textproc/enchant2 \
						wayland/wayland \
                        x11/dbus \
						x11/gnome/librsvg \
                        x11/xkbcommon

CONFIGURE_ARGS =        -DCMAKE_INSTALL_SYSCONFDIR=${PREFIX}/share/examples

COMPILER =				base-clang ports-gcc
COMPILER_LANGS =		c++

CFLAGS +=				-I${LOCALBASE}/include -I${X11BASE}/include
CXXFLAGS +=				-I${LOCALBASE}/include -I${X11BASE}/include

post-patch:
		cp ${FULLDISTDIR}/en_dict-20121020.tar.gz \
			${WRKSRC}/src/modules/spell/

.include <bsd.port.mk>
