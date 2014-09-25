--- ./include/pdal/portable_endian.hpp.orig	2014-09-25 18:47:00.001025520 +0200
+++ ./include/pdal/portable_endian.hpp	2014-09-25 18:48:23.175189835 +0200
@@ -48,7 +48,7 @@
 #elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
                
 #   include <sys/endian.h>
-                
+/*
 #   define be16toh betoh16
 #   define le16toh letoh16
                  
@@ -57,7 +57,7 @@
                   
 #   define be64toh betoh64
 #   define le64toh letoh64
-                   
+*/                   
 #elif defined(__WINDOWS__)
                     
 #   include <winsock2.h>
