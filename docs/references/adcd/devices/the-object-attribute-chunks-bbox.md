---
title: The Object Attribute Chunks / BBOX
manual: devices
chapter: devices
section: the-object-attribute-chunks-bbox
functions: []
libraries: []
---

# The Object Attribute Chunks / BBOX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

BBOX (0x42424F48)   	/* Bounding box of next object in FORM */

The BBOX chunk supplies the dimensions and position of a bounding box
surrounding the DR2D object that follows this chunk in the FORM.  A BBOX
chunk can apply to a FILL or AROW as well as a DR2D object.  The BBOX
chunk appears just before its DR2D object, FILL, or AROW chunk.

   struct BBOXstruct {
```c
       ULONG       ID;
       ULONG       Size;
       IEEE                XMin, YMin,     /* Bounding box of obj. */
                           XMax, YMax;     /* including line width */
```
   };

In a Cartesian coordinate system, the point (XMin, YMin) is the
coordinate of the lower left hand corner of the bounding box and
(XMax, YMax) is the upper right.  These coordinates take into
consideration the width of the lines making up the bounding box.

