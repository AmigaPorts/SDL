---
title: RGBN-RGB8.doc / Sample BODY Code
manual: devices
chapter: devices
section: rgbn-rgb8-doc-sample-body-code
functions: []
libraries: []
---

# RGBN-RGB8.doc / Sample BODY Code

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    if(!count) {
            if (Rgb8) {
                    fread (&w, 4, 1, RGBFile);
                    lock = w & 0x00000080;
                    rgb = w >> 8;
                    count = w & 0x0000007f;
            } else {
                    w = (UWORD) getw (RGBFile);
                    lock = w & 8;
                    rgb = w >> 4;
                    count = w & 7;
            }
            if (!count)
                    if (!(count = (UBYTE) getc (RGBFile)))
                            count = (UWORD) getw (RGBFile);
    }
```
The pixels are scanned from left to right across horizontal lines,
processing from top to bottom.  The (12 or 24 bit) RGB values are stored
with the red bits as the MSB's, the green bits next, and the blue bits as
the LSB's.

Special note:  As of this writing (Sep 88), Silver does NOT support
anything but black for color zero.

