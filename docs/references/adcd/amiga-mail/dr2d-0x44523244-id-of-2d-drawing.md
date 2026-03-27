---
title: DR2D (0x44523244)       / ID of 2D drawing /
manual: amiga-mail
chapter: amiga-mail
section: dr2d-0x44523244-id-of-2d-drawing
functions: []
libraries: []
---

# DR2D (0x44523244)       / ID of 2D drawing /

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The DR2D chunks are broken up into three groups: the global drawing
attribute chunks, the object attribute chunks, and the object chunks.
The global drawing attribute chunks describe elements of a 2D drawing
that are common to many objects in the drawing.  Document preferences,
palette information, and custom fill patterns are typical
document-wide settings defined in global drawing attribute chunks.
The object attribute chunks are used to set certain properties of the
object chunk(s) that follows the object attribute chunk.  The current
fill pattern, dash pattern, and line color are all set using an object
attribute chunk.  Object chunks describe the actual DR2D drawing.
Polygons, text, and bitmaps are found in these chunks.

