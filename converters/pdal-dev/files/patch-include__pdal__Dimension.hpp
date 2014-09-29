--- ./include/pdal/Dimension.hpp.orig	2014-09-29 15:02:12.833364479 +0200
+++ ./include/pdal/Dimension.hpp	2014-09-29 15:02:15.087588131 +0200
@@ -135,6 +135,7 @@
 {
 enum Enum
 {
+    Metadataid,
     Unknown,
     X,
     Y,
@@ -189,6 +190,8 @@
 {
     switch (id)
     {
+    case Id::Metadataid:
+	return "Lantmateriets metadataid";
     case Id::X:
         return "X coordinate";
     case Id::Y:
@@ -296,7 +299,9 @@
 inline Id::Enum id(std::string s)
 {
     boost::to_upper(s);
-    if (s == "X")
+    if ( s == "METADATAID")
+	return Id::Metadataid;
+    else if (s == "X")
         return Id::X;
     else if (s == "Y")
         return Id::Y;
@@ -387,6 +392,8 @@
 {
     switch (id)
     {
+    case Id::Metadataid:
+	return "Metadataid";
     case Id::X:
         return "X";
     case Id::Y:
@@ -484,6 +491,8 @@
 
     switch (id)
     {
+    case Id::Metadataid:
+	return Unsigned32;
     case Id::X:
         return Double;
     case Id::Y:
