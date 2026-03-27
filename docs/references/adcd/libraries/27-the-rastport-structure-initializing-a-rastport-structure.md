---
title: 27 / / The RastPort Structure / Initializing a RastPort Structure
manual: libraries
chapter: libraries
section: 27-the-rastport-structure-initializing-a-rastport-structure
functions: []
libraries: []
---

# 27 / / The RastPort Structure / Initializing a RastPort Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once you have a [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md) set up, you can declare and initialize the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)
and then link the BitMap into it.  Here is a sample initialization
sequence:


```c
    struct BitMap bitMap = {0};
    struct RastPort rastPort = {0};

    /* Initialize the RastPort and link the BitMap to it. */
    InitRastPort(&rastPort);
    rastPort.BitMap = &bitMap;


    Initialize, Then Link.
    ----------------------
    You cannot link the bitmap in until after the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) has been
    initialized.
```
