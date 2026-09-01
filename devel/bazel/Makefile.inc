COMMENT =		    Polyglot build tool

DISTNAME =		    bazel-${VERSION}
PKGNAME	=			bazel${VERSION:C/\..*//}-${VERSION}

CATEGORIES =	    devel

HOMEPAGE =		    https://bazel.build/

MAINTAINER =		c2qd

# Apache 2.0
PERMIT_PACKAGE =	Yes

DISTFILES =			${DISTNAME}-dist${EXTRACT_SUFX}
SITES =			    https://github.com/bazelbuild/bazel/releases/download/${VERSION}/

EXTRACT_SUFX =		.zip

EXTRACT_CASES +=	*.zip) \
					${UNZIP} -oq ${FULLDISTDIR}/$$archive -d ${WRKSRC} ${EXTRACT_FILES};;

DIST_TUPLE +=		github bazelbuild bazel-central-registry ${BCR_COMMIT} \
					bazel-central-registry

BAZEL_DIR_STARTUP_OPTIONS += --output_base=${WRKDIR}/output_base

EXTRA_BAZEL_ARGS += --tool_java_runtime_version=local_jdk_${MODJAVA_VER} \
                    --registry=file://${WRKDIST}/bazel-central-registry \

WANTLIB +=		    ${COMPILER_LIBCXX} c m
COMPILER_LANGS =	c++
COMPILER =		    base-clang

MODULES =		    java lang/python

BUILD_DEPENDS =		shells/bash

# Disable stripping. The `bazel` binary contains an embedded zip file;
# stripping the binary removes this zip file, breaking the binary.
INSTALL_STRIP =

pre-build:
	@if [ $$(ulimit -Sd) != "unlimited" ] && [ $$(ulimit -Sd) -lt $$((2*1024*1024)) ]; then \
		echo "datasize limit is too low. Build needs approximately 2GiB."; \
		exit 1; \
	fi
	@if [ $$(ulimit -Sn) != "unlimited" ] && [ $$(ulimit -Sn) -lt 2048 ]; then \
		echo "openfiles limit is too low. Build needs approximately 2048 files."; \
		exit 1; \
	fi

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
        EMBED_LABEL="${VERSION}" \
		BAZEL_DIR_STARTUP_OPTIONS=${BAZEL_DIR_STARTUP_OPTIONS} \
        EXTRA_BAZEL_ARGS="${EXTRA_BAZEL_ARGS}" \
		SOURCE_DATE_EPOCH="0" \
		${LOCALBASE}/bin/bash ./compile.sh
	chmod -R u+w ${WRKDIR}/output_base
