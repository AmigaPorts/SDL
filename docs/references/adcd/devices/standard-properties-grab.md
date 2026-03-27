---
title: Standard Properties / GRAB
manual: devices
chapter: devices
section: standard-properties-grab
functions: []
libraries: []
---

# Standard Properties / GRAB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The optional property "GRAB" locates a "handle" or "hotspot" of the image
relative to its upper left corner, e.g., when used as a mouse cursor or a
"paint brush".  A GRAB chunk contains a Point2D.


```c
    typedef struct {
        WORD x, y;         /* relative coordinates (pixels) */
        } Point2D;
```
