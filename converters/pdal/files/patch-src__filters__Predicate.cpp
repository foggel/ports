--- ./src/filters/Predicate.cpp.orig	2014-08-20 19:23:45.895942992 +0200
+++ ./src/filters/Predicate.cpp	2014-08-20 19:24:01.198436076 +0200
@@ -220,7 +220,7 @@
 
     m_numPointsPassed = dstData.getNumPoints();
 
-    return dstData.getNumPoints();
+    return m_numPointsProcessed; 
 }
 
 
