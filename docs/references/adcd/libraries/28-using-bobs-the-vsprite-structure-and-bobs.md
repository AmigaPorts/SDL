---
title: 28 / Using Bobs / The VSprite Structure and Bobs
manual: libraries
chapter: libraries
section: 28-using-bobs-the-vsprite-structure-and-bobs
functions: []
libraries: []
---

# 28 / Using Bobs / The VSprite Structure and Bobs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The root [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure is set up as described earlier for true
VSprites, with the following exceptions:


```c
             [Y, X](autodocs-2.0/includes-graphics-gels-h.md)  Bob position is always in pixels that are the same
                   resolution as the display.

            [Flags](libraries/28-using-bobs-vsprite-flags-and-bobs.md)  For Bobs, the [VSPRITE](libraries/28-using-virtual-sprites-using-vsprite-flags.md) flag must be cleared.  [SAVEBACK](libraries/28-using-bobs-vsprite-flags-and-bobs.md)
                   or [OVERLAY](libraries/28-using-bobs-vsprite-flags-and-bobs.md) can also be used.

    [Height, Width](libraries/28-using-bobs-specifying-the-size-of-a-bob.md)  Bob pixels are the size of the background pixels. The
                   Width of Bobs may be greater than one word.

            [Depth](libraries/28-using-bobs-specifying-the-colors-of-a-bob.md)  The Depth of a Bob may be up to as deep as the
                   playfield, provided that enough image data is provided.

        [ImageData](libraries/28-using-bobs-specifying-the-shape-of-a-bob.md)  This is still a pointer to the image, but the data
                   there is organized differently.

        [SprColors](autodocs-2.0/includes-graphics-gels-h.md)  This pointer should be set to NULL for Bobs.

            [VSBob](autodocs-2.0/includes-graphics-gels-h.md)  This is a pointer to the [Bob](libraries/28-using-bobs-the-bob-structure.md) structure set up as
                   described below.
```
