--- ./include/pdal/Utils.hpp.orig	2014-09-25 18:46:52.823206272 +0200
+++ ./include/pdal/Utils.hpp	2014-09-25 18:48:54.126976444 +0200
@@ -36,6 +36,7 @@
 
 #include <pdal/pdal_internal.hpp>
 
+#include <sys/wait.h>
 #include <string>
 #include <cassert>
 #include <stdexcept>
