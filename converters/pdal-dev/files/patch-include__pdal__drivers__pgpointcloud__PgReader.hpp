--- ./include/pdal/drivers/pgpointcloud/PgReader.hpp.orig	2014-09-29 15:02:25.823050878 +0200
+++ ./include/pdal/drivers/pgpointcloud/PgReader.hpp	2014-09-29 15:02:29.863659671 +0200
@@ -109,6 +109,7 @@
     virtual void addDimensions(PointContextRef ctx);
     virtual void processOptions(const Options& options);
     virtual void ready(PointContextRef ctx);
+    virtual void initialize();
     virtual point_count_t read(PointBuffer& buf, point_count_t count);
     virtual void done(PointContextRef ctx);
     virtual bool eof()
