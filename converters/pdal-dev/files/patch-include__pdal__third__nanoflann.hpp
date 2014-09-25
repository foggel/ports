--- ./include/pdal/third/nanoflann.hpp.orig	2014-09-25 18:47:46.582817340 +0200
+++ ./include/pdal/third/nanoflann.hpp	2014-09-25 18:48:02.800912098 +0200
@@ -40,6 +40,7 @@
 #include <cstdio>  // for fwrite()
 #include <cmath>   // for fabs(),...
 #include <limits>
+#include <cstdlib> // for abs()
 
 // Avoid conflicting declaration of min/max macros in windows headers
 #if !defined(NOMINMAX) && (defined(_WIN32) || defined(_WIN32_)  || defined(WIN32) || defined(_WIN64))
