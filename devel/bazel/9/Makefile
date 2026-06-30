VERSION =			9.1.1

BCR_COMMIT =		8d47d2680bebc7321302877652582533fc80bcd8

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
