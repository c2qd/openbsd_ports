DISTFILES.abseil =				abseil-cpp-20260107.1.tar.gz
SITES.abseil =					https://github.com/abseil/abseil-cpp/releases/download/20260107.1/
DISTFILES.abseil_py =			v2.1.0.tar.gz
SITES.abseil_py =				https://github.com/abseil/abseil-py/archive/refs/tags/
DISTFILES.apple_support =		apple_support.2.4.0.tar.gz
SITES.apple_support =			https://github.com/bazelbuild/apple_support/releases/download/2.4.0/
DISTFILES.bats_core =			v1.10.0.tar.gz
SITES.bats_core =				https://github.com/bats-core/bats-core/archive/
DISTFILES.bazel_lib_v2 =		bazel-lib-v2.22.5.tar.gz
SITES.bazel_lib_v2 =			https://github.com/bazel-contrib/bazel-lib/releases/download/v2.22.5/
DISTFILES.bazel_lib_v3 =		bazel-lib-v3.0.0.tar.gz
SITES.bazel_lib_v3 =			https://github.com/bazel-contrib/bazel-lib/releases/download/v3.0.0/
DISTFILES.bazel_skylib =		bazel-skylib-1.9.0.tar.gz
SITES.bazel_skylib =			https://github.com/bazelbuild/bazel-skylib/releases/download/1.9.0/
DISTFILES.bazel_features =		bazel_features-v1.42.1.tar.gz
SITES.bazel_features =			https://github.com/bazel-contrib/bazel_features/releases/download/v1.42.1/
DISTFILES.platforms =			platforms-1.0.0.tar.gz
SITES.platforms =				https://github.com/bazelbuild/platforms/releases/download/1.0.0/
DISTFILES.protobuf =			protobuf-34.1.bazel.tar.gz
SITES.protobuf =				https://github.com/protocolbuffers/protobuf/releases/download/v34.1/
DISTFILES.rules_android =		rules_android-v0.7.1.tar.gz
SITES.rules_android =			https://github.com/bazelbuild/rules_android/releases/download/v0.7.1/
DISTFILES.rules_android_ndk =	rules_android_ndk-v0.1.5.tar.gz
SITES.rules_android_ndk =		https://github.com/bazelbuild/rules_android_ndk/releases/download/v0.1.5/
DISTFILES.rules_apple =			rules_apple.4.5.2.tar.gz
SITES.rules_apple =				https://github.com/bazelbuild/rules_apple/releases/download/4.5.2/
DISTFILES.rules_cc =			rules_cc-0.2.17.tar.gz
SITES.rules_cc =				https://github.com/bazelbuild/rules_cc/releases/download/0.2.17/
DISTFILES.rules_go =			rules_go-v0.60.0.zip
SITES.rules_go =				https://github.com/bazel-contrib/rules_go/releases/download/v0.60.0/
DISTFILES.rules_java =			rules_java-9.3.0.tar.gz
SITES.rules_java =				https://github.com/bazelbuild/rules_java/releases/download/9.3.0/
DISTFILES.rules_kotlin =		rules_kotlin-v2.2.2.tar.gz
SITES.rules_kotlin =			https://github.com/bazelbuild/rules_kotlin/releases/download/v2.2.2/
DISTFILES.rules_license =		rules_license-1.0.0.tar.gz
SITES.rules_license =			https://github.com/bazelbuild/rules_license/releases/download/1.0.0/
DISTFILES.rules_pkg =			rules_pkg-1.2.0.tar.gz
SITES.rules_pkg =				https://github.com/bazelbuild/rules_pkg/releases/download/1.2.0/
DISTFILES.rules_python =		rules_python-1.9.0.tar.gz
SITES.rules_python =			https://github.com/bazel-contrib/rules_python/releases/download/1.9.0/
DISTFILES.rules_shell =			rules_shell-v0.6.1.tar.gz
SITES.rules_shell =				https://github.com/bazelbuild/rules_shell/releases/download/v0.6.1/
DISTFILES.rules_swift =			rules_swift.3.5.0.tar.gz
SITES.rules_swift =				https://github.com/bazelbuild/rules_swift/releases/download/3.5.0/
DISTFILES.tar_bzl =				tar.bzl-v0.5.1.tar.gz
SITES.tar_bzl =					https://github.com/bazel-contrib/tar.bzl/releases/download/v0.5.1/
DISTFILES.zlib =	            zlib-1.3.1.tar.gz
SITES.zlib =					https://github.com/madler/zlib/releases/download/v1.3.1/

WRKSRC =						${WRKDIST}/src

DIST_SUBDIR =					mozc

FILESDIR =						${.CURDIR}/../files

SUBST_TARGETS +=				${WRKSRC}/config.bzl \
								${WRKSRC}/MODULE.bazel \
								${WRKSRC}/base/system_util.cc \
								${WRKSRC}/base/process.cc \
								${WRKSRC}/bazel/rules_cc_bsd_cc_toolchain_config.bzl.patch

MODULES +=						devel/bazel lang/python

MODBAZEL_VERSION =				9

MODBAZEL_BCR_COMMIT_ID =		2459648091f2c5b8e21a46613cf39bffb6fba298

MODBAZEL_CONFIGS =				oss_linux release_build

.if ${MACHINE_ARCH} == "amd64"
MODBAZEL_FLAGS +=				--platforms=//:openbsd-x86_64
.elif ${MACHINE_ARCH} == "arm64"
MODBAZEL_FLAGS +=				--platforms=//:openbsd-arm64
.endif

MODPY_RUNDEP =					No
