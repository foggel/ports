# $FreeBSD$

PORTNAME=	pdal-dev
GH_TAGNAME=	c24dbb2
PORTVERSION=	0.9.9${GH_TAGNAME}

CATEGORIES=	converters

MAINTAINER=	gustafson.erik@gmail.com
COMMENT=	PDAL - Point Data Abstraction Library

LICENSE=	BSD3CLAUSE

CONFLICTS_INSTALL= converters/pdal
BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USE_GITHUB=	yes
GH_ACCOUNT=	PDAL
GH_PROJECT=	PDAL

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}

USES=		cmake
CMAKE_ARGS=	-DWITH_TESTS=OFF 
USE_PYTHON=	yes

OPTIONS_DEFINE=	GDAL GEOTIFF PROJ LIBXML2 LASZIP

GDAL_DESC=	Geospatial Data Abstraction Library

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGDAL}
LIB_DEPENDS+=	libgdal.so:${PORTSDIR}/graphics/gdal
.endif

.if ${PORT_OPTIONS:MGEOTIFF}
LIB_DEPENDS+=	libgeotiff.so:${PORTSDIR}/graphics/libgeotiff
.endif

.if ${PORT_OPTIONS:MPROJ}
LIB_DEPENDS+=	libproj.so:${PORTSDIR}/graphics/proj
.endif

.if ${PORT_OPTIONS:MLIBXML2}
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
.endif

.if ${PORT_OPTIONS:MLASZIP}
LIB_DEPENDS+=	liblaszip.so:${PORTSDIR}/archivers/laszip
.endif

.include <bsd.port.mk>
