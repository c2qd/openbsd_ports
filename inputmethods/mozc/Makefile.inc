DISTFILES.abseil_py =			v2.1.0.tar.gz
SITES.abseil_py =				https://github.com/abseil/abseil-py/archive/refs/tags/
DISTFILES.apple_support =		apple_support.2.4.0.tar.gz
SITES.apple_support =			https://github.com/bazelbuild/apple_support/releases/download/2.4.0/
DISTFILES.bazel_skylib =		bazel-skylib-1.9.0.tar.gz
SITES.bazel_skylib =			https://github.com/bazelbuild/bazel-skylib/releases/download/1.9.0/
DISTFILES.bazel_features =		bazel_features-v1.42.1.tar.gz
SITES.bazel_features =			https://github.com/bazel-contrib/bazel_features/releases/download/v1.42.1/
DISTFILES.platforms =			platforms-1.0.0.tar.gz
SITES.platforms =				https://github.com/bazelbuild/platforms/releases/download/1.0.0/
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
DISTFILES.rules_kotlin =		rules_kotlin-v1.9.6.tar.gz
SITES.rules_kotlin =			https://github.com/bazelbuild/rules_kotlin/releases/download/v1.9.6/
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

WRKSRC =						${WRKDIST}/src

DIST_SUBDIR =					mozc

FILESDIR =						${.CURDIR}/../files

SUBST_TARGETS +=				${WRKSRC}/config.bzl \
								${WRKSRC}/MODULE.bazel \
								${WRKSRC}/base/system_util.cc \
								${WRKSRC}/base/process.cc \
								${WRKSRC}/bazel/rules_cc_bsd_cc_toolchain_config.bzl.patch \
								${WRKSRC}/third_party/protobuf/bazel/cc_proto_library.bzl

MODULES +=						devel/bazel lang/python

MODPY_RUNDEP =					No

MODBAZEL_VERSION =				9

MODBAZEL_BCR_COMMIT_ID =		2459648091f2c5b8e21a46613cf39bffb6fba298

MODBAZEL_CONFIGS =				oss_linux release_build

MODBAZEL_FLAGS +=				--override_module=abseil-cpp=third_party/abseil-cpp \
								--override_module=googletest=third_party/gtest \
								--override_module=protobuf=third_party/protobuf \
								--override_module=zlib=third_party/zlib

TEST_FLAGS +=					--override_module=abseil-cpp=third_party/abseil-cpp \
								--override_module=googletest=third_party/gtest \
								--override_module=protobuf=third_party/protobuf \
								--override_module=zlib=third_party/zlib

.if ${MACHINE_ARCH} == "amd64"
MODBAZEL_FLAGS +=				--platforms=//:openbsd-x86_64
TEST_FLAGS +=					--platforms=//:openbsd-x86_64
.elif ${MACHINE_ARCH} == "arm64"
MODBAZEL_FLAGS +=				--platforms=//:openbsd-arm64
TEST_FLAGS +=					--platforms=//:openbsd-arm64
.endif

CXXFLAGS +=						-I${LOCALBASE}/include -pthread

LDFLAGS +=						-L${LOCALBASE}/lib -pthread
