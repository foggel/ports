--- ./src/drivers/pgpointcloud/Writer.cpp.orig	2014-09-25 17:17:19.000000000 +0200
+++ ./src/drivers/pgpointcloud/Writer.cpp	2014-10-03 12:47:19.000000000 +0200
@@ -118,20 +118,40 @@
     m_pcid = options.getValueOrDefault<boost::uint32_t>("pcid", 0);
     m_pack = options.getValueOrDefault<bool>("pack_ignored_fields", true);
     m_pre_sql = getOptions().getValueOrDefault<std::string>("pre_sql", "");
+    m_lmv_dims = getOptions().getValueOrDefault<bool>("lmv_dims", "false");
 }
 
 
 void Writer::ready(PointContextRef ctx)
 {
+	bool keep = false;
     m_pointSize = 0;
     m_dims = ctx.dims();
+   
+
     for (auto di = m_dims.begin(); di != m_dims.end(); ++di)
     {
         Dimension::Type::Enum type = Dimension::defaultType(*di);
         if (type == Dimension::Type::None)
             type = Dimension::Type::Float;
-        m_types.push_back(type);
-        m_pointSize += Dimension::size(type);
+		m_types.push_back(type);
+        switch(*di)
+        {
+                case Dimension::Id::X:
+                case Dimension::Id::Y:
+                case Dimension::Id::Z:
+                case Dimension::Id::Metadataid:
+            	case Dimension::Id::Classification:
+                        keep = 1;
+						break;
+				default:
+                        keep=0;
+                        break;
+        }
+        if(!m_lmv_dims || keep) {
+                m_pointSize += Dimension::size(type);
+        }
+
     }
 }
 
@@ -165,6 +185,7 @@
     Option pcid("pcid", 0, "use this existing pointcloud schema id, if it exists");
     Option pre_sql("pre_sql", "", "before the pipeline runs, read and execute this SQL file, or run this SQL command");
     Option post_sql("post_sql", "", "after the pipeline runs, read and execute this SQL file, or run this SQL command");
+    Option lmv_dims("lmv_dims", "" "keep only dimensions used in nnh-database");
 
     options.add(table);
     options.add(schema);
@@ -176,6 +197,7 @@
     options.add(pcid);
     options.add(pre_sql);
     options.add(post_sql);
+    options.add(lmv_dims);
 
     return options;
 }
@@ -544,15 +566,34 @@
     char *pos = outbuf.get();
     size_t clicks = 0;
     size_t interrupt = m_dims.size() * 100;
+    bool keep = false;
 
     for (PointId id = 0; id < buffer.size(); ++id)
     {
         auto ti = m_types.begin();
         for (auto di = m_dims.begin(); di != m_dims.end(); ++di, ++ti)
         {
-            fillBuf(buffer, pos, *di, *ti, id);
-            pos += Dimension::size(*ti);
+				switch(*di)
+				{
+						case Dimension::Id::X:
+						case Dimension::Id::Y:
+						case Dimension::Id::Z:
+						case Dimension::Id::Metadataid:
+						case Dimension::Id::Classification:
+                            keep=1;
+							break;
+						default:
+							keep=0;
+							break;
+				}
+
+                if(!m_lmv_dims || keep) {
+                        fillBuf(buffer, pos, *di, *ti, id);
+                        pos += Dimension::size(*ti);
+                }
         }
+
+
         if (id % 100 == 0)
             m_callback->invoke(id);
     }
