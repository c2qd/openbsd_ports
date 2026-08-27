MODBAZEL_VERSION ?=

.if ${MODBAZEL_VERSION} != "8" && ${MODBAZEL_VERSION} != "9"
ERRORS += "MODBAZEL_VERSION must be one of 8 or 9."
.endif

MODULES += java

.if ${MODBAZEL_VERSION} == "8"
BUILD_DEPENDS += devel/bazel/8
MODJAVA_VER = 21
.elif ${MODBAZEL_VERSION} == "9"
BUILD_DEPENDS += devel/bazel/9
MODJAVA_VER = 21
.endif

MODBAZEL_USE_BCR ?= Yes

.if ${MODBAZEL_USE_BCR:L} == "yes"
.if empty(MODBAZEL_BCR_COMMIT_ID)
ERRORS += "MODBAZEL_BCR_COMMIT_ID must be set to a commit ID of"
ERRORS += "https://github.com/bazelbuild/bazel-central-registry"
.endif

DIST_TUPLE += github bazelbuild bazel-central-registry \
			  ${MODBAZEL_BCR_COMMIT_ID} bazel-central-registry
MODBAZEL_BCR_DISTFILE = bazelbuild-bazel-central-registry-${MODBAZEL_BCR_COMMIT_ID}.tar.gz
MODBAZEL_BCR_DIR = ${WRKDIST}/bazel-central-registry
MODBAZEL_FLAGS += --registry=file://${MODBAZEL_BCR_DIR}
TEST_FLAGS += --registry=file://${MODBAZEL_BCR_DIR}
.endif

USE_LIBTOOL ?= No

ALL_TARGET ?= //...
TEST_TARGET ?= //...

MODBAZEL_FLAGS += ${MAKE_ENV:S/^/--action_env=/} ${MAKE_ENV:S/^/--host_action_env=/} \
				  ${CFLAGS:S/^/--copt=/} ${CFLAGS:S/^/--host_copt=/} \
				  ${CXXFLAGS:S/^/--cxxopt=/} ${CXXFLAGS:S/^/--host_cxxopt=/} \
				  ${LDFLAGS:S/^/--linkopt=/} ${LDFLAGS:S/^/--host_linkopt=/}

TEST_FLAGS += ${MAKE_ENV:S/^/--action_env=/} ${MAKE_ENV:S/^/--host_action_env=/} \
			  ${CFLAGS:S/^/--copt=/} ${CFLAGS:S/^/--host_copt=/} \
			  ${CXXFLAGS:S/^/--cxxopt=/} ${CXXFLAGS:S/^/--host_cxxopt=/} \
			  ${LDFLAGS:S/^/--linkopt=/} ${LDFLAGS:S/^/--host_linkopt=/}

# --config foo --config bar: foo bar
MODBAZEL_CONFIGS ?=

MODBAZEL_STARTUP_FLAGS += --batch --output_base=${WRKDIR}/modbazel_output_base \
						 --output_user_root=${WRKDIR}/modbazel_output_user_root

MODBAZEL_BUILD_TARGET = cd ${WRKBUILD} && exec ${SETENV} ${MAKE_ENV} \
						${LOCALBASE}/bin/bazel${MODBAZEL_VERSION} \
						${MODBAZEL_STARTUP_FLAGS} build \
						--distdir=${FULLDISTDIR} \
						${MODBAZEL_CONFIGS:S/^/--config /} \
						${_MODBAZEL_VERBOSE} --jobs=${MAKE_JOBS} \
						${MODBAZEL_FLAGS} ${ALL_TARGET}

MODBAZEL_TEST_TARGET = cd ${WRKBUILD} && exec ${SETENV} ${MAKE_ENV} \
					   ${LOCALBASE}/bin/bazel${MODBAZEL_VERSION} \
					   ${MODBAZEL_STARTUP_FLAGS} test --build_tests_only \
					   --distdir=${FULLDISTDIR} \
					   ${MODBAZEL_CONFIGS:S/^/--config=/} \
					   ${_MODBAZEL_VERBOSE} --jobs=${MAKE_JOBS} \
					   ${TEST_FLAGS} ${TEST_TARGET}

.if !target(do-build)
do-build:
	@${MODBAZEL_BUILD_TARGET}
.endif

.if !target(do-test)
do-test:
	@${MODBAZEL_TEST_TARGET}
.endif

MODBAZEL_WANTCOLOR ?= No

.if ${MODBAZEL_WANTCOLOR:L} == "yes" && defined(TERM)
MAKE_ENV += TERM=${TERM}
.endif

# Very long
MODBAZEL_VERBOSE ?= No

.if ${MODBAZEL_VERBOSE:L} == "yes"
_MODBAZEL_VERBOSE = --subcommands --verbose_failures
.endif
