---
title: 28 / / Types Of GELs / Bobs and AnimComps
manual: libraries
chapter: libraries
section: 28-types-of-gels-bobs-and-animcomps
functions: []
libraries: []
---

# 28 / / Types Of GELs / Bobs and AnimComps

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Like VSprites, Bobs and AnimComps are graphics objects that make animation
easier.  They are rendered using the blitter.  The blitter is a special
Amiga hardware component used to move data quickly and efficiently,
optionally performing logical operations as it does.  It can be used to
move any kind of data but is especially well suited to moving rectangular
blocks of display data.

It is important to keep in mind that Bobs and AnimComps are based on the
blitter hardware while VSprites use the sprite hardware. However all three
GEL types use the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure as their root data structure.  The
system uses pointers to link the VSprite, [Bob](libraries/28-using-bobs-the-bob-structure.md) and [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) structures,
"extending" the VSprite structure to include all GEL types.

Since Bobs and AnimComps are rendered with the blitter they actually
change the underlying playfield [BitMap](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md).  The BitMap area where the GEL is
rendered can be saved.  By moving the GEL to new locations in small
increments while also saving and restoring the Bitmap as you proceed, you
can create an animation effect.  Bobs and AnimComps use the same
coordinates as the playfield and can be any size.

