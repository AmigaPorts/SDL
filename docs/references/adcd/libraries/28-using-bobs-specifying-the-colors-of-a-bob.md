---
title: 28 / Using Bobs / Specifying the Colors of a Bob
manual: libraries
chapter: libraries
section: 28-using-bobs-specifying-the-colors-of-a-bob
functions: []
libraries: []
---

# 28 / Using Bobs / Specifying the Colors of a Bob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Typically a five-bitplane, low-resolution mode display allows playfield
pixels (and therefore, Bob pixels) to be selected from any of 32 active
colors out of a system palette of 4,096 different color choices. Bob
colors are limited to the colors used in the background playfield.

The system ignores the sprColors member of the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure when the
VSprite structure is the root of a Bob. Instead, the Bob's colors are
determined by the combination of the [Depth](autodocs-2.0/includes-graphics-gels-h.md) of the Bob image and its
[PlanePick](libraries/28-other-items-influencing-bob-colors-planepick.md), [PlaneOnOff](libraries/28-other-items-influencing-bob-colors-planeonoff.md) and [ImageShadow](libraries/28-other-items-influencing-bob-colors-imageshadow.md) members.

Use the [Depth](autodocs-2.0/includes-graphics-gels-h.md) member in the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure to indicate how many planes
of image data is provided to define the Bob. This also defines how many
colors the Bob will have. The combination of bits in corresponding Y,X
positions in each bitplane determines the color of the pixel at that
position.

For example, if a [Depth](autodocs-2.0/includes-graphics-gels-h.md) of one plane is specified, then the bits of that
image allow only two colors to be selected:  one color for each bit that
is a 0, a second color for each bit that is a 1.  Likewise, if there are 5
planes of image data, all 32 colors can be used in the Bob.  The Bob Depth
must not exceed the background depth.  Specify Depth using a statement
such as the following:


```c
    myVSprite.Depth = 5;   /* Allow a 32 color, 5-bitplane image. */
```
