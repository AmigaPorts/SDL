---
title: 13 / Preferences in Release 2 / PGFX
manual: libraries
chapter: libraries
section: 13-preferences-in-release-2-pgfx
functions: []
libraries: []
---

# 13 / Preferences in Release 2 / PGFX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    struct PrinterGfxPrefs
    {
        LONG  pg_Reserved[4];
        UWORD pg_Aspect;          /* Horizontal or vertical */
        UWORD pg_Shade;           /* B&W, Greyscale, Color */
        UWORD pg_Image;           /* Positive or negative image */
        WORD  pg_Threshold;       /* Black threshold */
        UBYTE pg_ColorCorrect;    /* RGB color correction */
        UBYTE pg_Dimensions;      /* Dimension type */
        UBYTE pg_Dithering;       /* Type of dithering */
        UWORD pg_GraphicFlags;    /* Rastport dump flags */
        UBYTE pg_PrintDensity;    /* Print density 1 - 7 */
        UWORD pg_PrintMaxWidth;   /* Maximum width */
        UWORD pg_PrintMaxHeight;  /* Maximum height */
        UBYTE pg_PrintXOffset;    /* X Offset */
        UBYTE pg_PrintYOffset;    /* Y Offset */
    };
```
The possible values of each field are defined in <prefs/[printergfx.h](libraries/includes-prefs-printergfx-h.md)>.
Note that your application is responsible for checking if the supplied
values are valid.

