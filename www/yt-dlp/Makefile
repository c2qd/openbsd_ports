COMMENT =	CLI program to download videos from YouTube and other sites

MODPY_DISTV =	2026.8.19
VERSION = ${MODPY_DISTV}

DISTNAME =	yt-dlp-${VERSION}
DISTFILES =	yt_dlp-${VERSION}${EXTRACT_SUFX}

WRKDIST = ${WRKDIR}/yt_dlp-${VERSION}

CATEGORIES =	www

# Public Domain
PERMIT_PACKAGE =	Yes

MODULES =	lang/python
MODPY_PI =	Yes
MODPY_PYBUILD =	hatchling

# deps are optional, though required for various site extractors
# or functionality. these ones are quite common and either don't
# pull in a big chain of other ports, or (in the case of ffmpeg)
# are strongly recommended.
RUN_DEPENDS =	audio/py-mutagen \
		devel/py-certifi \
		graphics/ffmpeg \
		security/py-cryptodomex \
		www/py-curl_cffi \
		www/py-requests \
		www/py-yt-dlp-ejs>=0.8.0

TEST_DEPENDS +=	devel/flake8 \
		archivers/py-brotlicffi \
		net/py-websockets

.include <bsd.port.mk>
