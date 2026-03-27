---
title: 28 Graphics Sprites, Bobs and Animation / Using Bobs
manual: libraries
chapter: libraries
section: 28-graphics-sprites-bobs-and-animation-using-bobs
functions: []
libraries: []
---

# 28 Graphics Sprites, Bobs and Animation / Using Bobs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following section describes how to define a Bob (blitter object). Like
VSprites, a Bob is a software construct designed to make animation easier.
The main advantage of a Bob over a VSprite is that it allows more colors
and a width greater than 16 pixels to be defined.

To create a Bob, you need both a [Bob](libraries/28-using-bobs-the-bob-structure.md) structure and a [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure.
The components common to all GELs -- height, collision-handling
information, position in the drawing area and pointers to the image
definition -- are part of the VSprite structure.  The added features --
such as drawing sequence, data about saving and restoring the background,
and other features not applicable to VSprites -- are further specified in
the Bob structure.

 [The VSprite Structure and Bobs](libraries/28-using-bobs-the-vsprite-structure-and-bobs.md)        [Bob Priorities](libraries/28-using-bobs-bob-priorities.md) 
 [VSprite Flags and Bobs](libraries/28-using-bobs-vsprite-flags-and-bobs.md)                [Adding a Bob](libraries/28-using-bobs-adding-a-bob.md) 
 [The Bob Structure](libraries/28-using-bobs-the-bob-structure.md)                     [Removing a Bob](libraries/28-using-bobs-removing-a-bob.md) 
 [Using Bob Flags](libraries/28-using-bobs-using-bob-flags.md)                       [Sorting and Displaying Bobs](libraries/28-using-bobs-sorting-and-displaying-bobs.md) 
 [Specifying the Size of a Bob](libraries/28-using-bobs-specifying-the-size-of-a-bob.md)          [Changing Bobs](libraries/28-using-bobs-changing-bobs.md) 
 [Specifying the Shape of a Bob](libraries/28-using-bobs-specifying-the-shape-of-a-bob.md)         [Complete Bob Example](libraries/lib-examples-bob-c.md) 
 [Specifying the Colors of a Bob](libraries/28-using-bobs-specifying-the-colors-of-a-bob.md)        [Double-Buffering](libraries/28-using-bobs-double-buffering.md) 
 [Other Items Influencing Bob Colors](libraries/28-using-bobs-other-items-influencing-bob-colors.md) 

