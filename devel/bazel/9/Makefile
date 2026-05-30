VERSION =			9.1.0

BCR_COMMIT_HASH =	8d47d2680bebc7321302877652582533fc80bcd8

MODJAVA_VER =		21

EXTRA_BAZEL_ARGS += --linkopt=-lm --linkopt=-lc++ --linkopt=-lc++abi
EXTRA_BAZEL_ARGS += --linkopt=-pthread --host_linkopt=-lm --host_linkopt=-lc++
EXTRA_BAZEL_ARGS += --host_linkopt=-lc++abi --host_linkopt=-pthread

.include <bsd.port.mk>
