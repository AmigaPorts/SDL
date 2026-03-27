---
title: DR2D.doc / The DR2D Chunks
manual: devices
chapter: devices
section: dr2d-doc-the-dr2d-chunks
functions: []
libraries: []
---

# DR2D.doc / The DR2D Chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

FORM (0x464F524D)  	/* All drawings are a FORM */


```c
    struct FORMstruct {
        ULONG       ID;             /* DR2D */
        ULONG       Size;
    };
```
DR2D (0x44523244)  /* ID of 2D drawing */

The DR2D chunks are broken up into three groups: the global drawing
attribute chunks, the object attribute chunks, and the object chunks. The
global drawing attribute chunks describe elements of a 2D drawing that are
common to many objects in the drawing.  Document preferences, palette
information, and custom fill patterns are typical document-wide settings
defined in global drawing attribute chunks. The object attribute chunks
are used to set certain properties of the object chunk(s) that follows the
object attribute chunk.  The current fill pattern, dash pattern, and line
color are all set using an object attribute chunk.  Object chunks describe
the actual DR2D drawing. Polygons, text, and bitmaps are found in these
chunks.

 [Global Drawing Attribute Chunk](devices/the-dr2d-chunks-the-global-drawing-attribute-chunks.md) 
 [Object Attribute Chunks](devices/the-dr2d-chunks-the-object-attribute-chunks.md) 
 [The Object Chunks](devices/the-dr2d-chunks-the-object-chunks.md) 

