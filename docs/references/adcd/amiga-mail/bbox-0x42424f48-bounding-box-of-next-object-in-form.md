---
title: BBOX (0x42424F48)       / Bounding box of next object in FORM /
manual: amiga-mail
chapter: amiga-mail
section: bbox-0x42424f48-bounding-box-of-next-object-in-form
functions: []
libraries: []
---

# BBOX (0x42424F48)       / Bounding box of next object in FORM /

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The BBOX chunk supplies the dimensions and position of a bounding box
surrounding the DR2D object that follows this chunk in the FORM.  A
BBOX chunk can apply to a FILL or AROW as well as a DR2D object.  The
BBOX chunk appears just before its DR2D object, FILL, or AROW chunk.


```c
    struct BBOXstruct {
        ULONG       ID;
        ULONG       Size;
        IEEE                XMin, YMin,     /* Bounding box of obj. */
                            XMax, YMax;     /* including line width */
    };
```
In a Cartesian coordinate system, the point (XMin, YMin) is the
coordinate of the lower left hand corner of the bounding box and
(XMax, YMax) is the upper right.  These coordinates take into
consideration the width of the lines making up the bounding box.

