---
title: The Object Chunks / VBM
manual: devices
chapter: devices
section: the-object-chunks-vbm
functions: []
libraries: []
---

# The Object Chunks / VBM

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

VBM  (0x56424D20)   	/* Virtual BitMap */

The VBM chunk contains the position, dimensions, and file name of an ILBM
image.


```c
    struct VBMstruct {
        IEEE        XPos, YPos,     /* Virtual coords */
                    XSize, YSize,   /* Virtual size */
                    Rotation;       /* in degrees */
        USHORT      PathLen;        /* Length of dir path */
        char        Path[PathLen];  /* Null-terminated path of file */
    };
```
The coordinate (XPos, YPos) is the position of the upper left hand corner
of the bitmap and the XSize and YSize fields supply the x and y dimensions
to which the image should be scaled.  Rotation tells how many degrees to
rotate the ILBM around its upper left hand corner. ProVector does not
currently support rotation of bitmaps and will ignore this value.  Path
contains the name of the ILBM file and may also contain a partial or full
path to the file.  DR2D readers should not assume the path is correct.
The full path to an ILBM on one system may not match the path to the same
ILBM on another system.  If a DR2D reader cannot locate an ILBM file based
on the full path name or the file name itself (looking in the current
directory), it should ask the user where to find the image.

