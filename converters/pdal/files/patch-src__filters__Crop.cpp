--- ./src/filters/Crop.cpp.orig	2014-02-21 22:48:18.000000000 +0100
+++ ./src/filters/Crop.cpp	2014-08-20 19:23:26.761292482 +0200
@@ -428,7 +428,7 @@
             outputData.setNumPoints(outputData.getNumPoints() + tmpData.getNumPoints());
         }
 
-        numPointsNeeded -= tmpData.getNumPoints() ;
+        numPointsNeeded -= numPointsProcessed ;
         m_cropFilter.log()->get(logDEBUG3) << numPointsNeeded << " left to read this block" << std::endl;
 
     }
