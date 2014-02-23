--- ./include/pdal/Utils.hpp.orig	2014-02-23 22:21:10.450118851 +0000
+++ ./include/pdal/Utils.hpp	2014-02-23 22:21:26.586128129 +0000
@@ -35,6 +35,8 @@
 #ifndef INCLUDED_UTILS_HPP
 #define INCLUDED_UTILS_HPP
 
+#include <sys/wait.h>
+
 #include <pdal/pdal_internal.hpp>
 
 #include <string>
