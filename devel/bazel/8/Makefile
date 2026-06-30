VERSION =			8.7.0

BCR_COMMIT =		8d47d2680bebc7321302877652582533fc80bcd8

MODJAVA_VER =		21

EXTRA_BAZEL_ARGS += --linkopt=-lm --host_linkopt=-lm

post-patch:
	cd ${WRKDIST}/bazel-central-registry && \
	cp ${FILESDIR}/*.patch \
		modules/c-ares/1.15.0/patches && \
	patch < ${FILESDIR}/patch-modules_c-ares_1.15.0_source_json

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${PREFIX}/bin/bazel8
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bazel8/
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc \
		${PREFIX}/share/examples/bazel8/bazel.bazelrc

.include <bsd.port.mk>
