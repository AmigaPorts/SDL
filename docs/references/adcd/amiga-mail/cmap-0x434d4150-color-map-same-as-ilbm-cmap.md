---
title: CMAP (0x434D4150)       / Color map (Same as ILBM CMAP) /
manual: amiga-mail
chapter: amiga-mail
section: cmap-0x434d4150-color-map-same-as-ilbm-cmap
functions: []
libraries: []
---

# CMAP (0x434D4150)       / Color map (Same as ILBM CMAP) /

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chunk is identical to the ILBM CMAP chunk as described in the IFF
ILBM documentation.


```c
    struct CMAPstruct {
        ULONG       ID;
        ULONG       Size;
        UBYTE       ColorMap[Size];
    };
```
ColorMap is an array of 24-bit RGB color values.  The 24-bit value is
spread across three bytes, the first of which contains the red
intensity, the next contains the green intensity, and the third
contains the blue intensity.  Because DR2D stores its colors with
24-bit accuracy, DR2D readers must not make the mistake that some ILBM
readers do in assuming the CMAP chunk colors correspond directly to
Amiga color registers.

