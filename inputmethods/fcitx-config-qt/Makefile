COMMENT =			GUI configure tool for fcitx5

DISTNAME =			fcitx5-configtool-5.1.15
PKGNAME =			${DISTNAME:S/fcitx5/fcitx/}

SHARED_LIBS +=		Fcitx5Migrator            0.0 # 0.0

CATEGORIES =		inputmethods

HOMEPAGE =			https://github.com/fcitx/fcitx5-configtool

# GPLv2.0+
PERMIT_PACKAGE=		Yes

SITES =				https://download.fcitx-im.org/fcitx5/fcitx5-configtool/
EXTRACT_SUFX =		.tar.zst

WANTLIB +=			${COMPILER_LIBCXX} Fcitx5Config Fcitx5Core Fcitx5Qt6DBusAddons
WANTLIB +=			Fcitx5Qt6WidgetsAddons Fcitx5Utils KF6ConfigCore KF6DBusAddons
WANTLIB +=			KF6I18n KF6ItemViews KF6WidgetsAddons KF6WindowSystem
WANTLIB +=			KirigamiPlatform Qt6Concurrent Qt6Core Qt6DBus Qt6Gui Qt6Network
WANTLIB +=			Qt6OpenGL Qt6Qml Qt6Quick Qt6Widgets
WANTLIB +=			GL X11 c m xkbcommon xkbfile

MODULES =			devel/cmake devel/kf6

BUILD_DEPENDS =		devel/kf6/extra-cmake-modules \
					devel/gettext,-tools \
					devel/kf6/kpackage \
					devel/iso-codes

RUN_DEPENDS =		devel/desktop-file-utils \
					devel/kf6/kdeclarative \
					misc/shared-mime-info

LIB_DEPENDS =		devel/kf6/kcmutils \
					devel/kf6/kcoreaddons \
					devel/kf6/kdbusaddons \
					devel/kf6/kiconthemes \
					devel/kf6/kirigami \
					devel/kf6/kitemviews \
					devel/kf6/ksvg \
					devel/kf6/kwidgetsaddons \
					devel/kf6/kwindowsystem \
					inputmethods/fcitx \
					inputmethods/fcitx-qt \
					x11/kde-plasma/libplasma

CONFIGURE_ARGS =	-DUSE_QT5=OFF

.include <bsd.port.mk>
