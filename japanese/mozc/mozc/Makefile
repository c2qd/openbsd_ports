COMMENT =						Japanese Input Method Editor

VERSION =						3.33.6133
DISTNAME =						mozc-${VERSION}
PKGNAME =						mozc-${VERSION}

GH_ACCOUNT =					google
GH_PROJECT =					mozc
GH_TAGNAME =					${VERSION}

BCR_COMMIT_HASH =				a480ea6e068ef24a3deb7fd56243b1a7e4aa8259
DIST_TUPLE +=					github bazelbuild bazel-central-registry ${BCR_COMMIT_HASH} \
								bazel-central-registry

CATEGORIES=						japanese

MAINTAINER =					c2qd (https://codeberg.org/c2qd/openbsd_ports/issues)

JA_USAGE_DICT_VERSION =			2025-01-25
ZIP_CODE_COMMIT_HASH =			33524763837473258e7ba2f14b17fc3a70519831

DISTFILES.dictionary_png =		outline_chrome_reader_mode_black_48dp.png
SITES.dictionary_png =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/png/action/chrome_reader_mode/materialiconsoutlined/48dp/1x/
DISTFILES.dictionary_svg =		24px.svg
SITES.dictionary_svg =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/src/action/chrome_reader_mode/materialiconsoutlined/
DISTFILES.property_png =		round_settings_black_48dp.png
SITES.property_png =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/png/action/settings/materialiconsround/48dp/1x/
DISTFILES.property_svg =		material_icon_tool_svg{24px}.svg
SITES.property_svg =			https://raw.githubusercontent.com/google/material-design-icons/4.0.0/src/action/settings/materialiconsround/
DISTFILES.ja_usage_dict =		${JA_USAGE_DICT_VERSION}.zip
SITES.ja_usage_dict =			https://github.com/hiroyuki-komatsu/japanese-usage-dictionary/archive/refs/tags/
DISTFILES.zip_code_jigyosyo =	jigyosyo.zip
SITES.zip_code_jigyosyo =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT_HASH}/
DISTFILES.zip_code_ken_all =	ken_all.zip
SITES.zip_code_ken_all =		https://github.com/hiroyuki-komatsu/japanpost_zipcode/raw/${ZIP_CODE_COMMIT_HASH}/

EXTRACT_ONLY =					mozc-${VERSION}.tar.gz bazelbuild-bazel-central-registry-${BCR_COMMIT_HASH}.tar.gz

BUILD_DEPENDS +=				devel/bazel/8

MODULES +=						x11/qt6

WANTLIB +=						${COMPILER_LIBCXX} Qt6Core Qt6Gui Qt6Widgets
WANTLIB +=						c m pthread execinfo z X11
LIB_DEPENDS +=					x11/qt6/qtbase \
								x11/xkbcommon \
								x11/dbus\
								textproc/icu4c \
								converters/libiconv \
								archivers/zstd \
								math/double-conversion \
								security/libb2 \
								devel/pcre2 \
								devel/glib2 \
								devel/harfbuzz \
								devel/gettext \
								graphics/png \
								sysutils/syslog-ng

COMPILER_LANGS =				c++
COMPILER =						base-clang

# BSD-3-Clause + NAIST-2003(IPADic) + Public Domain(Okinawa dictionary) +
# BSD-2-Claude(Japanese usage dictionary) + Copyright non-assertion(Zip code data)
PERMIT_PACKAGE =				Yes

PATCHDIR =						${.CURDIR}/../patches
FILESDIR =						${.CURDIR}/../files

BAZEL_DISTDIR_ALT =				${WRKDIR}/distdir_alt

SUBST_VARS +=					LOCALBASE X11BASE

SUBST_TARGETS +=				${WRKSRC}/src/config.bzl \
								${WRKSRC}/src/base/system_util.cc \
								${WRKSRC}/src/base/process.cc \
								${WRKSRC}/src/cc_toolchain_config.bzl

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}

pre-build:
	mkdir -p ${BAZEL_DISTDIR_ALT} && \
		cp ${FULLDISTDIR}/material_icon_tool_svg.svg ${BAZEL_DISTDIR_ALT}/24px.svg && \
		mkdir -p ${WRKDIR}/bazel_tmp

do-build:
	cd ${WRKSRC}/src && env LC_ALL=C.UTF-8 ${LOCALBASE}/bin/bazel8 \
		--output_base=${WRKDIR}/bazel_tmp build \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--distdir=${FULLDISTDIR} \
		--distdir=${BAZEL_DISTDIR_ALT} \
		--config oss_linux \
		--config release_build \
		--platforms=//:openbsd-ex \
		--copt=-I/usr/X11R6/include \
		--linkopt=-L/usr/local/lib \
		--host_linkopt=-L/usr/local/lib \
		server:mozc_server gui/tool:mozc_tool

post-build:
	cd ${WRKSRC}/src && ${LOCALBASE}/bin/bazel8 shutdown

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/bin/mozc
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/server/mozc_server" \
		"${PREFIX}/bin/mozc/mozc_server"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/bin/mozc/mozc_tool"

.include <bsd.port.mk>

