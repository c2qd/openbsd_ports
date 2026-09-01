COMMENT =				File archiver with a high compression ratio

VERSION =				26.02
DISTNAME =				7-zip-${VERSION}

CATEGORIES =			archivers

HOMEPAGE =				https://7-zip.org

# LGPLv2.1+ + LGPLv2.1+ with unRAR license restriction +
# BSD-3-Clause + BSD-2-Clause + Public Domain
PERMIT_PACKAGE =		Yes

WRKSRC =				${WRKDIST}/CPP/7zip/Bundles/Alone2

EXTRACT_SUFX =			.tar.xz
DISTFILES =				7z${VERSION:C/\.//}-src${EXTRACT_SUFX}
SITES =					https://github.com/ip7z/7zip/releases/download/${VERSION}/

EXTRACT_CASES =			*.tar.xz) \
						mkdir -p ${WRKDIST}; \
						xz -T${MAKE_JOBS} -d <${FULLDISTDIR}/$$archive | \
						${TAR} -xf - -C ${WRKDIST} -- ${EXTRACT_FILES};;

FIX_CRLF_FILES =		${WRKDIST}/CPP/7zip/7zip_gcc.mak

WANTLIB +=				${COMPILER_LIBCXX} c m

COMPILER =				base-clang ports-gcc

USE_GMAKE =				Yes

MAKE_ENV +=				DISABLE_RAR_COMPRESS=1

MAKE_FILE_base-clang =	../../cmpl_clang.mak
MAKE_FILE_ports-gcc =	../../cmpl_gcc.mak
MAKE_FILE =				${MAKE_FILE_${CHOSEN_COMPILER}}

post-extract:
	chmod -R u+w ${WRKDIST}

do-install:
	${INSTALL_PROGRAM} "${WRKSRC}/b/c/7zz" \
		"${PREFIX}/bin/7zz"

.include <bsd.port.mk>
