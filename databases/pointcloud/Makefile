# $FreeBSD$

PORTNAME=	pointcloud
PORTVERSION=	0.1
CATEGORIES=	databases

MAINTAINER=	gustafson.erik@gmail.com
COMMENT=	Pointcloud extenstion for PostgresSQL

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	pramsey
GH_PROJECT=	pointcloud
GH_TAGNAME=	4c4bb5d

WRKSRC=		${WRKDIR}/pramsey-${PORTNAME}-${GH_TAGNAME}

USE_AUTOTOOLS=	autoconf
USES=		gmake

USE_PGSQL=	9.1+
#RUN_DEPENDS=    postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
RUN_DEPENDS=	${LOCALBASE}/share/postgis:${PORTSDIR}/databases/postgis20
WANT_PGSQL=	server
#WANT_PGSQL_VER=	91+

.include <bsd.port.mk>
