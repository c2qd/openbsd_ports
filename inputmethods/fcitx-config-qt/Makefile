COMMENT =			GUI configure tool for fcitx5

DISTNAME =			fcitx5-configtool-5.1.14
PKGNAME =			${DISTNAME:S/fcitx5/fcitx/}

SHARED_LIBS +=		Fcitx5Migrator            0.0 # 0.0

CATEGORIES =		inputmethods

MAINTAINER =		c2qd (https://codeberg.org/c2qd/openbsd_ports/issues)

HOMEPAGE =			https://github.com/fcitx/fcitx5-configtool

# GPLv2.0+
PERMIT_PACKAGE=		Yes

WANTLIB +=			${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Qt6DBusAddons
WANTLIB +=			Fcitx5Qt6WidgetsAddons Fcitx5Utils
WANTLIB +=			KF6DBusAddons KF6ItemViews KF6WindowSystem KF6WidgetsAddons
WANTLIB +=			Qt6Core Qt6DBus Qt6Gui Qt6Widgets
WANTLIB +=			X11 c m xkbfile

SITES =				https://download.fcitx-im.org/fcitx5/fcitx5-configtool/
EXTRACT_SUFX =		.tar.zst

MODULES =			devel/kf6

BUILD_DEPENDS =		devel/gettext,-tools \
					devel/kf6/kirigami \
					devel/kf6/kpackage \
					devel/iso-codes

RUN_DEPENDS =		devel/desktop-file-utils \
					devel/kf6/kirigami \
					misc/shared-mime-info

LIB_DEPENDS =		devel/kf6/kitemviews \
					devel/kf6/kdbusaddons \
					devel/kf6/kwindowsystem \
					devel/kf6/kwidgetsaddons \
					inputmethods/fcitx \
					inputmethods/fcitx-qt

CONFIGURE_ARGS =	-DUSE_QT5=OFF

.include <bsd.port.mk>
