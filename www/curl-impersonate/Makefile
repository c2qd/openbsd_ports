COMMENT =               Special curl build that can impersonate major browsers

HOMEPAGE =				https://curl-impersonate.readthedocs.io/

VERSION =               2.1.1
DISTNAME =              curl-impersonate-${VERSION}
CATEGORIES =            net www

SHARED_LIBS +=			curl-impersonate                0.0 # 0.0

GH_ACCOUNT =            lexiforest
GH_PROJECT =            curl-impersonate
GH_TAGNAME =            v${VERSION}

MAINTAINER =			c2qd

# MIT + Zlib(zlib) + BSD-3-Clause(zstd) +
# MIT(brotli, nghttp2, ngtcp2, nghttp3) + Apache-2.0(boringssl) + curl(curl)
PERMIT_PACKAGE =		No

DIST_SUBDIR =			curl-impersonate

ZLIB_VERSION =			1.3.1
ZSTD_VERSION =			1.5.7
BROTLI_VERSION =		1.2.0
BORINGSSL_COMMIT =		156c7b75ae9b8c3b3f847acf264f17594c3859fb
NGHTTP2_VERSION =		1.63.0
NGTCP2_VERSION =		1.20.0
NGHTTP3_VERSION =		1.15.0
CURL_VERSION =			curl-8_21_0

DISTFILES.zlib =		zlib-${ZLIB_VERSION}.tar.gz
SITES.zlib =			https://github.com/madler/zlib/releases/download/v${ZLIB_VERSION}/
DISTFILES.zstd =		zstd-${ZSTD_VERSION}.tar.gz
SITES.zstd =			https://github.com/facebook/zstd/releases/download/v${ZSTD_VERSION}/
DISTFILES.brotli =		v${BROTLI_VERSION}.tar.gz
SITES.brotli =			https://github.com/google/brotli/archive/refs/tags/
DISTFILES.boringssl =	${BORINGSSL_COMMIT}.zip
SITES.boringssl =		https://github.com/google/boringssl/archive/
DISTFILES.nghttp2 =		nghttp2-${NGHTTP2_VERSION}.tar.bz2
SITES.nghttp2 =			https://github.com/nghttp2/nghttp2/releases/download/v${NGHTTP2_VERSION}/
DISTFILES.ngtcp2 =		ngtcp2-${NGTCP2_VERSION}.tar.bz2
SITES.ngtcp2 =			https://github.com/ngtcp2/ngtcp2/releases/download/v${NGTCP2_VERSION}/
DISTFILES.nghttp3 =		nghttp3-${NGHTTP3_VERSION}.tar.bz2
SITES.nghttp3 =			https://github.com/ngtcp2/nghttp3/releases/download/v${NGHTTP3_VERSION}/
DISTFILES.curl =		${CURL_VERSION}.tar.gz
SITES.curl =			https://github.com/curl/curl/archive/

EXTRACT_ONLY =			${GH_PROJECT}-${VERSION}${EXTRACT_SUFX}

RUN_DEPENDS +=			shells/bash

WANTLIB +=				${COMPILER_LIBCXX} c

MODULES =				devel/cmake

CONFIGURE_ARGS =		-DCMAKE_INSTALL_INCLUDEDIR=include/curl-impersonate

COMPILER =				base-clang ports-gcc

SUBST_VARS +=			FULLDISTDIR

SUBST_TARGETS +=		${WRKSRC}/CMakeLists.txt

post-patch:
	${SUBST_CMD} ${SUBST_TARGETS}

# cf. https://github.com/lexiforest/curl-impersonate/blob/86e5f1f822566827cc413de843acdac60057a37c/.github/workflows/build.yml#L441-L451
post-build:
	@if ! ar t "${WRKBUILD}/deps/build/curl/lib/libcurl-impersonate.a" | \
		grep -Fqx "libcurl-impersonate.full.o"; then \
		set -x; cd ${WRKBUILD}/deps/install/lib && \
		cp libz.a libzstd.a libbrotlidec.a libbrotlicommon.a libbrotlienc.a libnghttp2.a \
		libnghttp3.a libngtcp2.a libngtcp2_crypto_boringssl.a libssl.a libcrypto.a \
		"${WRKBUILD}/deps/build/curl/lib" && \
		cd "${WRKBUILD}/deps/build/curl/lib" && \
		mv libcurl-impersonate.a libcurl-impersonate.a.orig && \
		${WRKDIR}/bin/${CC} -r -o libcurl-impersonate.full.o -Wl,--whole-archive \
		libcurl-impersonate.a.orig libz.a libzstd.a libbrotlidec.a \
		libbrotlicommon.a libbrotlienc.a libnghttp2.a libnghttp3.a \
		libngtcp2.a libngtcp2_crypto_boringssl.a libssl.a libcrypto.a \
		-Wl,--no-whole-archive && \
		ar rcs libcurl-impersonate.a libcurl-impersonate.full.o; \
	fi

.include <bsd.port.mk>
