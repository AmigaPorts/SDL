---
title: 28 / Using Virtual Sprites / VSprite Image Size
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-vsprite-image-size
functions: []
libraries: []
---

# 28 / Using Virtual Sprites / VSprite Image Size

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A true VSprite is always one word (16 pixels) wide and may be any number
of lines high.  It can be made to appear thinner by making some pixels
transparent.  Like Simple Sprites, VSprite pixels are always the size of a
pixel in low-resolution mode (320x200); regardless of the resolution the
display is set to.  To specify how many lines make up the VSprite image,
the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure member, [Height](autodocs-2.0/includes-graphics-gels-h.md), is used. VSprites always have a
[Depth](autodocs-2.0/includes-graphics-gels-h.md) of two, allowing for three colors.  The values may be set like this:


```c
    myVSprite.Width  = 1;      /* ALWAYS 1 for true VSprites. */
    myVSprite.Height = 5;      /* The example height. */
    myVSprite.Depth  = 2;      /* ALWAYS 2 for true VSprites. */
```
