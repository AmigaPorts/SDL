---
title: DR2D.doc / OFHD
manual: devices
chapter: devices
section: dr2d-doc-ofhd
functions: []
libraries: []
---

# DR2D.doc / OFHD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

OFHD	(0x4F464844)   	/* ID of OutlineFontHeaDer */

This chunk contains some basic information on the font.


```c
    struct OFHDstruct {
        char   FontName[32];   /* Font name, null padded */
        short  FontAttrs;      /* See FA_*, below */
        IEEE   FontTop,        /* Typical height above baseline */
               FontBot,        /* Typical descent below baseline */
               FontWidth;      /* Typical width, i.e. of the letter O */
    };

    #define FA_BOLD         0x0001
    #define FA_OBLIQUE      0x0002
    #define FA_SERIF        0x0004
```
The FontName field is a NULL terminated string containing the name of this
font.  FontAttrs is a bit field with flags for several font attributes.
The flags, as defined above, are bold, oblique, and serif.  The unused
higher order bits are reserved for later use.  The other fields describe
the average dimensions of the characters in this font.  FontTop is the
average height above the baseline, FontBot is the average descent below
the baseline, and FontWidth is the average character width.

