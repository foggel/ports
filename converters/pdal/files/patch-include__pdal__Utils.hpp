--- ./include/pdal/Utils.hpp.orig	2014-02-21 22:48:18.000000000 +0100
+++ ./include/pdal/Utils.hpp	2014-08-20 19:23:26.761292482 +0200
@@ -35,6 +35,8 @@
 #ifndef INCLUDED_UTILS_HPP
 #define INCLUDED_UTILS_HPP
 
+#include <sys/wait.h>
+
 #include <pdal/pdal_internal.hpp>
 
 #include <string>
