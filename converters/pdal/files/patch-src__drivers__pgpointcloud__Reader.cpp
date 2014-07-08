--- ./src/drivers/pgpointcloud/Reader.cpp.orig	2014-07-08 13:22:33.182961510 +0200
+++ ./src/drivers/pgpointcloud/Reader.cpp	2014-07-08 13:23:47.442864818 +0200
@@ -233,6 +233,8 @@
     oss << "FROM pg_class c, pg_attribute a ";
     oss << "WHERE c.relname = '" << m_table_name << "' ";
     oss << "AND a.attname = '" << m_column_name << "' ";
+    oss << "AND a.attrelid = c.oid ";
+    oss << "AND a.attisdropped=false";
 
     char *pcid_str(0);
     pcid_str = pg_query_once(m_session, oss.str());
