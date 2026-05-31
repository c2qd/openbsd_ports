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

# Bazel depends
ABSEIL_VERSION =				20250814.0
BAZEL_SKYLIB_VERSION =			1.8.1
BAZEL_FEATURES_VERSION =		1.30.0
GOOGLETEST_VERSION =			1.17.0
JSONCPP_VERSION =				1.9.6
PLATFORMS_VERSION =				1.0.0
PROTOBUF_VERSION =				32.0
PYBIND11_VERSION =				2.12.0
RE2_VERSION =					2024-07-02
RULES_ANDROID_VERSION =			0.1.1
RULES_CC_VERSION =				0.2.2
RULES_JAVA_VERSION =			8.14.0
RULES_JVM_VERSION =				6.7
RULES_KOTLIN_VERSION =			1.9.6
RULES_LICENSE_VERSION =			1.0.0
RULES_PKG_VERSION =				1.1.0
RULES_PROTO_VERSION =			7.1.0
RULES_PYTHON_VERSION =			1.5.4
RULES_SHELL_VERSION =			0.3.0
STARDOC_VERSION =				0.7.2
ZLIB_VERSION =					1.3.1

DISTFILES.abseil =				abseil-cpp-${ABSEIL_VERSION}.tar.gz
SITES.abseil =					https://github.com/abseil/abseil-cpp/releases/download/${ABSEIL_VERSION}/
DISTFILES.bazel_skylib =		bazel-skylib-${BAZEL_SKYLIB_VERSION}.tar.gz
SITES.bazel_skylib =			https://github.com/bazelbuild/bazel-skylib/releases/download/${BAZEL_SKYLIB_VERSION}/
DISTFILES.bazel_features =		bazel_features-v${BAZEL_FEATURES_VERSION}.tar.gz
SITES.bazel_features =			https://github.com/bazel-contrib/bazel_features/releases/download/v${BAZEL_FEATURES_VERSION}/
DISTFILES.googletest =			googletest-${GOOGLETEST_VERSION}.tar.gz
SITES.googletest =				https://github.com/google/googletest/releases/download/v${GOOGLETEST_VERSION}/
DISTFILES.jsoncpp =				${JSONCPP_VERSION}.tar.gz
SITES.jsoncpp =					https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/
DISTFILES.platforms =			platforms-${PLATFORMS_VERSION}.tar.gz
SITES.platforms =				https://github.com/bazelbuild/platforms/releases/download/${PLATFORMS_VERSION}/
DISTFILES.protobuf =			protobuf-${PROTOBUF_VERSION}.zip
SITES.protobuf =				https://github.com/protocolbuffers/protobuf/releases/download/v${PROTOBUF_VERSION}/
DISTFILES.pybind11_bazel =		pybind11_bazel-${PYBIND11_VERSION}.zip
SITES.pybind11_bazel =			https://github.com/pybind/pybind11_bazel/releases/download/v${PYBIND11_VERSION}/
DISTFILES.re2 =					re2-${RE2_VERSION}.zip
SITES.re2 =						https://github.com/google/re2/releases/download/${RE2_VERSION}/
DISTFILES.rules_android =		v${RULES_ANDROID_VERSION}.tar.gz
SITES.rules_android =			https://github.com/bazelbuild/rules_android/archive/refs/tags/
DISTFILES.rules_cc =			rules_cc-${RULES_CC_VERSION}.tar.gz
SITES.rules_cc =				https://github.com/bazelbuild/rules_cc/releases/download/${RULES_CC_VERSION}/
DISTFILES.rules_java =			rules_java-${RULES_JAVA_VERSION}.tar.gz
SITES.rules_java =				https://github.com/bazelbuild/rules_java/releases/download/${RULES_JAVA_VERSION}/
DISTFILES.rules_jvm =			rules_jvm_external-${RULES_JVM_VERSION}.tar.gz
SITES.rules_jvm =				https://github.com/bazel-contrib/rules_jvm_external/releases/download/${RULES_JVM_VERSION}/
DISTFILES.rules_kotlin =		rules_kotlin-v${RULES_KOTLIN_VERSION}.tar.gz
SITES.rules_kotlin =			https://github.com/bazelbuild/rules_kotlin/releases/download/v${RULES_KOTLIN_VERSION}/
DISTFILES.rules_license =		rules_license-${RULES_LICENSE_VERSION}.tar.gz
SITES.rules_license =			https://github.com/bazelbuild/rules_license/releases/download/${RULES_LICENSE_VERSION}/
DISTFILES.rules_pkg =			rules_pkg-${RULES_PKG_VERSION}.tar.gz
SITES.rules_pkg =				https://github.com/bazelbuild/rules_pkg/releases/download/${RULES_PKG_VERSION}/
DISTFILES.rules_proto =			rules_proto-${RULES_PROTO_VERSION}.tar.gz
SITES.rules_proto =				https://github.com/bazelbuild/rules_proto/releases/download/${RULES_PROTO_VERSION}/
DISTFILES.rules_python =		rules_python-${RULES_PYTHON_VERSION}.tar.gz
SITES.rules_python =			https://github.com/bazel-contrib/rules_python/releases/download/${RULES_PYTHON_VERSION}/
DISTFILES.rules_shell =			rules_shell-v${RULES_SHELL_VERSION}.tar.gz
SITES.rules_shell =				https://github.com/bazelbuild/rules_shell/releases/download/v${RULES_SHELL_VERSION}/
DISTFILES.stardoc =			    stardoc-${STARDOC_VERSION}.tar.gz
SITES.stardoc =					https://github.com/bazelbuild/stardoc/releases/download/${STARDOC_VERSION}/
DISTFILES.zlib =	            zlib-${ZLIB_VERSION}.tar.gz
SITES.zlib =					https://github.com/madler/zlib/releases/download/v${ZLIB_VERSION}/

# Mozc assets
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

post-extract:
	cp ${FILESDIR}/cc_toolchain_config.bzl ${WRKSRC}/src/

pre-build:
	mkdir -p ${BAZEL_DISTDIR_ALT} && \
		cp ${FULLDISTDIR}/material_icon_tool_svg.svg ${BAZEL_DISTDIR_ALT}/24px.svg && \
		mkdir -p ${WRKDIR}/bazel_tmp

do-build:
	cd ${WRKSRC}/src && LC_ALL=C.UTF-8 ${LOCALBASE}/bin/bazel \
		--output_base=${WRKDIR}/bazel_tmp build \
		--registry=file://${WRKDIST}/bazel-central-registry \
		--distdir=${FULLDISTDIR} \
		--distdir=${BAZEL_DISDIR_ALT} \
		--config oss_linux \
		--config stable_channel \
		--config release_build \
		--platforms=//:openbsd-ex \
		--copt=-I/usr/X11R6/include \
		--linkopt=-L/usr/local/lib \
		--host_linkopt=-L/usr/local/lib \
		server:mozc_server gui/tool:mozc_tool

post-build:
	cd ${WRKSRC}/src && ${LOCALBASE}/bin/bazel shutdown

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/mozc
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/server/mozc_server" \
		"${PREFIX}/lib/mozc/mozc_server"
	${INSTALL_PROGRAM} "${WRKSRC}/src/bazel-bin/gui/tool/mozc_tool" \
		"${PREFIX}/lib/mozc/mozc_tool"

.include <bsd.port.mk>

