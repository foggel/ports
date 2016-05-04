--- src/providers/oracle/qgsoracleprovider.cpp.orig	2016-05-04 06:07:23 UTC
+++ src/providers/oracle/qgsoracleprovider.cpp
@@ -2030,6 +2030,12 @@ QgsRectangle QgsOracleProvider::extent()
 
   if ( mLayerExtent.isEmpty() )
   {
+	mLayerExtent.setXMinimum = 200000;
+	mLayerExtent.setXMaximum = 1000000;
+	mLayerExtent.setYMinimum = 6100000;
+	mLayerExtent.setYMaximum = 7700000;
+
+	return mLayerExtent;
     QString sql;
     QSqlQuery qry( *mConnection );
 
