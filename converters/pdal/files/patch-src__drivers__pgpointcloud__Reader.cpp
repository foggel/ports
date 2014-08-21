--- ./src/drivers/pgpointcloud/Reader.cpp.orig	2014-02-21 22:48:18.000000000 +0100
+++ ./src/drivers/pgpointcloud/Reader.cpp	2014-08-20 19:23:26.761292482 +0200
@@ -233,6 +233,8 @@
     oss << "FROM pg_class c, pg_attribute a ";
     oss << "WHERE c.relname = '" << m_table_name << "' ";
     oss << "AND a.attname = '" << m_column_name << "' ";
+    oss << "AND a.attrelid = c.oid ";
+    oss << "AND a.attisdropped=false";
 
     char *pcid_str(0);
     pcid_str = pg_query_once(m_session, oss.str());
