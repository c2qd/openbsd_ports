VERSION =			8.8.0

BCR_COMMIT =		b5176b63a86cea0d1d8093daf8d353fe707d3d98

MODJAVA_VER =		21

EXTRA_BAZEL_ARGS += --linkopt=-lm --host_linkopt=-lm

post-patch:
	cp ${FILESDIR}/c-ares_BUILD.bazel.patch \
		${WRKSRC}/third_party

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${PREFIX}/bin/bazel8
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bazel8/
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc \
		${PREFIX}/share/examples/bazel8/bazel.bazelrc

.include <bsd.port.mk>
