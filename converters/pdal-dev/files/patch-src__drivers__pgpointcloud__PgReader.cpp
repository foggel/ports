--- ./src/drivers/pgpointcloud/PgReader.cpp.orig	2014-09-29 15:01:48.546870246 +0200
+++ ./src/drivers/pgpointcloud/PgReader.cpp	2014-09-29 15:01:52.455443822 +0200
@@ -247,7 +247,9 @@
         return pdal::SpatialReference();
 }
 
-
+void PgReader::initialize() {
+	m_session = pg_connect(m_connection);
+}
 void PgReader::ready(PointContextRef ctx)
 {
     m_atEnd = false;
@@ -277,6 +279,8 @@
     m_session = NULL;
     if (m_cur_result)
         PQclear(m_cur_result);
+
+    log()->get(LogLevel::Debug) << "pgreader DONE: " << std::endl;
 }
 
 
