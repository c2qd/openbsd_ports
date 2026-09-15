VERSION =			8.8.0

BCR_COMMIT =		b5176b63a86cea0d1d8093daf8d353fe707d3d98

MODJAVA_VER =		21

post-extract:
	cp ${FILESDIR}/rules_cc_bsd_cc_toolchain_config.bzl.patch \
		${FILESDIR}/c-ares_BUILD.bazel.patch \
		${WRKSRC}/third_party

post-patch:
	${SUBST_CMD} -DCC=${CC} -DLD=${LD} -DWRKDIR=${WRKDIR} \
		${WRKSRC}/third_party/rules_cc_bsd_cc_toolchain_config.bzl.patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${PREFIX}/bin/bazel8
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bazel8/
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc \
		${PREFIX}/share/examples/bazel8/bazel.bazelrc

.include <bsd.port.mk>
