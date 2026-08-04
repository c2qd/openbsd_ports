ABSEIL_VERSION =				20260107.1
APPLE_SUPPORT_VERSION =			2.4.0
BATS_CORE_VERSION =				1.10.0
BAZEL_LIB_VERSION_V2 =			2.22.5
BAZEL_LIB_VERSION_V3 =			3.0.0
BAZEL_SKYLIB_VERSION =			1.9.0
BAZEL_FEATURES_VERSION =		1.42.1
BUILDOZER_VERSION =				8.5.1
GOOGLETEST_VERSION =			1.17.0
PLATFORMS_VERSION =				1.0.0
PROTOBUF_VERSION =				34.1
PYBIND11_VERSION =				2.13.6
RULES_ANDROID_VERSION =			0.7.1
RULES_ANDROID_NDK_VERSION =		0.1.5
RULES_APPLE_VERSION =			4.5.2
RULES_CC_VERSION =				0.2.17
RULES_GO_VERSION =				0.60.0
RULES_JAVA_VERSION =			9.3.0
RULES_JVM_VERSION =				6.7
RULES_JVM_EXTERNAL_VERSION =	6.9
RULES_KOTLIN_VERSION =			2.2.2
RULES_LICENSE_VERSION =			1.0.0
RULES_PKG_VERSION =				1.2.0
RULES_PROTO_VERSION =			7.1.0
RULES_PYTHON_VERSION =			1.9.0
RULES_ROBOLECTRIC_VERSION =		4.14.1.2
RULES_SHELL_VERSION =			0.6.1
RULES_SWIFT_VERSION =			3.5.0
STARDOC_VERSION =				0.7.2
TAR_BZL_VERSION =				0.5.1
ZLIB_VERSION =					1.3.1

DISTFILES.abseil =				abseil-cpp-${ABSEIL_VERSION}.tar.gz
SITES.abseil =					https://github.com/abseil/abseil-cpp/releases/download/${ABSEIL_VERSION}/
DISTFILES.apple_support =		apple_support.${APPLE_SUPPORT_VERSION}.tar.gz
SITES.apple_support =			https://github.com/bazelbuild/apple_support/releases/download/${APPLE_SUPPORT_VERSION}/
DISTFILES.bats_core =			v${BATS_CORE_VERSION}.tar.gz
SITES.bats_core =				https://github.com/bats-core/bats-core/archive/
DISTFILES.bazel_lib_v2 =		bazel-lib-v${BAZEL_LIB_VERSION_V2}.tar.gz
SITES.bazel_lib_v2 =			https://github.com/bazel-contrib/bazel-lib/releases/download/v${BAZEL_LIB_VERSION_V2}/
DISTFILES.bazel_lib_v3 =		bazel-lib-v${BAZEL_LIB_VERSION_V3}.tar.gz
SITES.bazel_lib_v3 =			https://github.com/bazel-contrib/bazel-lib/releases/download/v${BAZEL_LIB_VERSION_V3}/
DISTFILES.bazel_skylib =		bazel-skylib-${BAZEL_SKYLIB_VERSION}.tar.gz
SITES.bazel_skylib =			https://github.com/bazelbuild/bazel-skylib/releases/download/${BAZEL_SKYLIB_VERSION}/
DISTFILES.bazel_features =		bazel_features-v${BAZEL_FEATURES_VERSION}.tar.gz
SITES.bazel_features =			https://github.com/bazel-contrib/bazel_features/releases/download/v${BAZEL_FEATURES_VERSION}/
DISTFILES.buildozer =			buildozer-v${BUILDOZER_VERSION}.tar.gz
SITES.buildozer =				https://github.com/fmeum/buildozer/releases/download/v${BUILDOZER_VERSION}/
DISTFILES.googletest =			googletest-${GOOGLETEST_VERSION}.tar.gz
SITES.googletest =				https://github.com/google/googletest/releases/download/v${GOOGLETEST_VERSION}/
DISTFILES.platforms =			platforms-${PLATFORMS_VERSION}.tar.gz
SITES.platforms =				https://github.com/bazelbuild/platforms/releases/download/${PLATFORMS_VERSION}/
DISTFILES.protobuf =			protobuf-${PROTOBUF_VERSION}.bazel.tar.gz
SITES.protobuf =				https://github.com/protocolbuffers/protobuf/releases/download/v${PROTOBUF_VERSION}/
DISTFILES.pybind11_bazel =		pybind11_bazel-${PYBIND11_VERSION}.tar.gz
SITES.pybind11_bazel =			https://github.com/pybind/pybind11_bazel/releases/download/v${PYBIND11_VERSION}/
DISTFILES.rules_android =		rules_android-v${RULES_ANDROID_VERSION}.tar.gz
SITES.rules_android =			https://github.com/bazelbuild/rules_android/releases/download/v${RULES_ANDROID_VERSION}/
DISTFILES.rules_android_ndk =	rules_android_ndk-v${RULES_ANDROID_NDK_VERSION}.tar.gz
SITES.rules_android_ndk =		https://github.com/bazelbuild/rules_android_ndk/releases/download/v${RULES_ANDROID_NDK_VERSION}/
DISTFILES.rules_apple =			rules_apple.${RULES_APPLE_VERSION}.tar.gz
SITES.rules_apple =				https://github.com/bazelbuild/rules_apple/releases/download/${RULES_APPLE_VERSION}/
DISTFILES.rules_cc =			rules_cc-${RULES_CC_VERSION}.tar.gz
SITES.rules_cc =				https://github.com/bazelbuild/rules_cc/releases/download/${RULES_CC_VERSION}/
DISTFILES.rules_go =			rules_go-v${RULES_GO_VERSION}.zip
SITES.rules_go =				https://github.com/bazel-contrib/rules_go/releases/download/v${RULES_GO_VERSION}/
DISTFILES.rules_java =			rules_java-${RULES_JAVA_VERSION}.tar.gz
SITES.rules_java =				https://github.com/bazelbuild/rules_java/releases/download/${RULES_JAVA_VERSION}/
DISTFILES.rules_jvm =			rules_jvm_external-${RULES_JVM_VERSION}.tar.gz
SITES.rules_jvm =				https://github.com/bazel-contrib/rules_jvm_external/releases/download/${RULES_JVM_VERSION}/
DISTFILES.rules_jvm_external =	rules_jvm_external-${RULES_JVM_EXTERNAL_VERSION}.tar.gz
SITES.rules_jvm_external =		https://github.com/bazel-contrib/rules_jvm_external/releases/download/${RULES_JVM_EXTERNAL_VERSION}/
DISTFILES.rules_kotlin =		rules_kotlin-v${RULES_KOTLIN_VERSION}.tar.gz
SITES.rules_kotlin =			https://github.com/bazelbuild/rules_kotlin/releases/download/v${RULES_KOTLIN_VERSION}/
DISTFILES.rules_license =		rules_license-${RULES_LICENSE_VERSION}.tar.gz
SITES.rules_license =			https://github.com/bazelbuild/rules_license/releases/download/${RULES_LICENSE_VERSION}/
DISTFILES.rules_pkg =			rules_pkg-${RULES_PKG_VERSION}.tar.gz
SITES.rules_pkg =				https://github.com/bazelbuild/rules_pkg/releases/download/${RULES_PKG_VERSION}/
DISTFILES.rules_python =		rules_python-${RULES_PYTHON_VERSION}.tar.gz
SITES.rules_python =			https://github.com/bazel-contrib/rules_python/releases/download/${RULES_PYTHON_VERSION}/
DISTFILES.rules_robolectric =	robolectric-bazel-${RULES_ROBOLECTRIC_VERSION}.tar.gz
SITES.rules_robolectric =		https://github.com/robolectric/robolectric-bazel/releases/download/${RULES_ROBOLECTRIC_VERSION}/
DISTFILES.rules_shell =			rules_shell-v${RULES_SHELL_VERSION}.tar.gz
SITES.rules_shell =				https://github.com/bazelbuild/rules_shell/releases/download/v${RULES_SHELL_VERSION}/
DISTFILES.rules_swift =			rules_swift.${RULES_SWIFT_VERSION}.tar.gz
SITES.rules_swift =				https://github.com/bazelbuild/rules_swift/releases/download/${RULES_SWIFT_VERSION}/
DISTFILES.stardoc =			    stardoc-${STARDOC_VERSION}.tar.gz
SITES.stardoc =					https://github.com/bazelbuild/stardoc/releases/download/${STARDOC_VERSION}/
DISTFILES.tar_bzl =				tar.bzl-v${TAR_BZL_VERSION}.tar.gz
SITES.tar_bzl =					https://github.com/bazel-contrib/tar.bzl/releases/download/v${TAR_BZL_VERSION}/
DISTFILES.zlib =	            zlib-${ZLIB_VERSION}.tar.gz
SITES.zlib =					https://github.com/madler/zlib/releases/download/v${ZLIB_VERSION}/

BCR_COMMIT =					2459648091f2c5b8e21a46613cf39bffb6fba298
DIST_TUPLE +=					github bazelbuild bazel-central-registry ${BCR_COMMIT} \
								bazel-central-registry

DIST_SUBDIR =					mozc

SUBST_TARGETS +=				${WRKSRC}/src/config.bzl \
								${WRKSRC}/src/MODULE.bazel \
								${WRKSRC}/src/base/system_util.cc \
								${WRKSRC}/src/base/process.cc

CLANG_RESOURCE_DIR !=			/usr/bin/${CC} -print-resource-dir
CLANG_RESOURCE_DIR :=			${CLANG_RESOURCE_DIR}/include

SUBST_VARS_bazel_conf +=		-DCC=${CC} -DLD=${LD} -DWRKDIR=${WRKDIR} \
								-DCLANG_RESOURCE_DIR=${CLANG_RESOURCE_DIR}

SUBST_TARGETS_bazel_conf +=		${WRKSRC}/src/cc_toolchain_config.bzl

SUBST_TARGETS_rules_python +=	${WRKSRC}/bazel-central-registry/modules/rules_python/${RULES_PYTHON_VERSION}/source.json

FILESDIR =						${.CURDIR}/../files

BUILD_DEPENDS +=				devel/bazel/9

MODULES +=						java lang/python

MODJAVA_VER =					21

MODPY_RUNDEP =					No

HTTPS_PROXY ?=					http://127.0.0.1:1

BAZEL_ENVS +=					JAVA_HOME=${JAVA_HOME} HTTPS_PROXY=${HTTPS_PROXY}

BAZEL_STARTUP_FLAGS =			--batch --output_base=${WRKDIST}/bazel_output_base \
								--output_user_root=${WRKDIST}/bazel_output_user_root

BAZEL_BUILD_FLAGS +=			--tool_java_runtime_version=local_jdk_${MODJAVA_VER} \
								--registry=file://${WRKDIST}/bazel-central-registry \
								--distdir=${FULLDISTDIR}\
								--config oss_linux \
								--config release_build \
								--platforms=//:openbsd-ex

# === for debug; with mitmproxy ===
.if defined(ENABLE_PROXY) && ${ENABLE_PROXY} == "1"
BUILD_DEPENDS +=				security/mitmproxy

BAZEL_STARTUP_FLAGS +=			--host_jvm_args=-Djavax.net.ssl.trustStore=/tmp/cacerts \
								--host_jvm_args=-Djavax.net.ssl.trustStorePassword=changeit

BAZEL_ENVS +=					HTTPS_PROXY=http://127.0.0.1:8080
.endif

proxyconfig:
	cp ${JAVA_HOME}/lib/security/cacerts /tmp/cacerts && \
		keytool -importcert -alias mitmproxy \
		-file ~/.mitmproxy/mitmproxy-ca-cert.pem \
		-keystore /tmp/cacerts -storepass changeit
# === end ===

do-test:
	cd ${WRKSRC}/src && ${BAZEL_ENVS} ${LOCALBASE}/bin/bazel9 ${BAZEL_STARTUP_FLAGS} test ... \
		${BAZEL_BUILD_FLAGS} --build_tests_only
