---
title: 28 / Using Bobs / Specifying the Size of a Bob
manual: libraries
chapter: libraries
section: 28-using-bobs-specifying-the-size-of-a-bob
functions: []
libraries: []
---

# 28 / Using Bobs / Specifying the Size of a Bob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Bobs do not have the 16-pixel width limit that applies to VSprites.  To
specify the overall size of a Bob, use the [Height and Width](autodocs-2.0/includes-graphics-gels-h.md) members of the
root [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure.  Specify the Width as the number of 16-bit words
it takes to fully contain the object.  The number of lines is still
specified with the Height member in the VSprite data structure.

As an example, suppose the Bob is 24 pixels wide and 20 lines tall.  Use
statements like the following to specify the size:


```c
    myVSprite.Height = 20;  /* 20 lines tall. */
    myVSprite.Width  = 2;   /* 24 bits fit into two words. */
```
Because Bobs are drawn into the background playfield, the pixels of the
Bob are the same size as the background pixels, and share the color
palette of the [ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).

