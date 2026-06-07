COMMENT =						Japanese Input Method Editor

VERSION =						3.33.6133
DISTNAME =						mozc-${VERSION}
PKGNAME =						mozc-${VERSION}

GH_ACCOUNT =					google
GH_PROJECT =					mozc
GH_COMMIT =						b18e5de65659cfa5a4f92066bcbb6bfa4d94dfe5
#GH_TAGNAME =					${VERSION}

CATEGORIES=						japanese

MAINTAINER =					c2qd (https://codeberg.org/c2qd/openbsd_ports/issues)

JA_USAGE_DICT_VERSION =			2025-01-25
ZIP_CODE_COMMIT_HASH =			621d059fbcbfae17bfca15b439692bae934268c3

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

EXTRACT_ONLY =					mozc-${VERSION}-${GH_COMMIT:C/^(.{8}).*/\1/}.tar.gz bazelbuild-bazel-central-registry-${BCR_COMMIT_HASH}.tar.gz

BUILD_DEPENDS +=				devel/bazel/9

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
# BSD-2-Clause(Japanese usage dictionary) + Copyright non-assertion(Zip code data)
# Warning: I don't know anything about licenses~
#          Please determine whether to set PERMIT_PACKAGE to Y/n.
PERMIT_PACKAGE =				No

BAZEL_DISTDIR_ALT =				${WRKDIR}/distdir_alt

pre-build:
	mkdir -p ${BAZEL_DISTDIR_ALT} && \
		cp ${FULLDISTDIR}/material_icon_tool_svg.svg ${BAZEL_DISTDIR_ALT}/24px.svg && \
		mkdir -p ${WRKOBJDIR}/_bazel_tmp

do-build:
	cd ${WRKSRC}/src && env LC_ALL=C.UTF-8 ${LOCALBASE}/bin/bazel9 \
		--output_user_root=${WRKOBJDIR}/_bazel_tmp build \
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

do-install:
	${INSTALL_PROGRAM_DIR} "${PREFIX}/lib/mozc"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/server/mozc_server" \
		"${PREFIX}/lib/mozc/mozc_server"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/lib/mozc/mozc_tool"

.include <bsd.port.mk>

