VERSION =			9.2.0

BCR_COMMIT =		6ac2a231d2f238815e082a3a1170ad880b685c99

MODJAVA_VER =		21

EXTRA_BAZEL_ARGS += --linkopt=-lm --linkopt=-lc++ --linkopt=-lc++abi \
					--linkopt=-pthread --host_linkopt=-lm --host_linkopt=-lc++ \
					--host_linkopt=-lc++abi --host_linkopt=-pthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${PREFIX}/bin/bazel9
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bazel9/
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc \
		${PREFIX}/share/examples/bazel9/bazel.bazelrc

.include <bsd.port.mk>
