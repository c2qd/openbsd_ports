VERSION =			9.2.0
REVISION =			1

BCR_COMMIT =		6ac2a231d2f238815e082a3a1170ad880b685c99

MODJAVA_VER =		21

post-extract:
	cp ${FILESDIR}/rules_cc_bsd_cc_toolchain_config.bzl.patch \
		${WRKSRC}/third_party

post-patch:
	${SUBST_CMD} -DCC=${CC} -DLD=${LD} -DWRKDIR=${WRKDIR} \
		${WRKSRC}/third_party/rules_cc_bsd_cc_toolchain_config.bzl.patch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${PREFIX}/bin/bazel9
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bazel9/
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc \
		${PREFIX}/share/examples/bazel9/bazel.bazelrc

.include <bsd.port.mk>
