---
title: 28 Graphics Sprites, Bobs and Animation / Using Virtual Sprites
manual: libraries
chapter: libraries
section: 28-graphics-sprites-bobs-and-animation-using-virtual-sprites
functions: []
libraries: []
---

# 28 Graphics Sprites, Bobs and Animation / Using Virtual Sprites

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section describes how to set up the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure so that it
represents a true VSprite.  True VSprites are managed by the GELs system
which converts them to Simple Sprites and displays them.  (Later sections
describe how a VSprite structure can be set up for Bobs and AnimComps.)

Before the system is told of a VSprite's existence, space for the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)
data structure must be allocated and initialized to correctly represent a
VSprite.  Since the system does no validity checking on the VSprite
structure, the result of using a bogus structure is usually a fireworks
display, followed by a system failure.

The system software provides a way to detect collisions between VSprites
and other on-screen objects.  There is also a method of extending the
[VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure to incorporate user defined variables.  These subjects
are applicable to all GELs and are explained later in the section on
"[Collisions and GEL Structure Extensions](libraries/28-collisions-and-gel-structure-extensions.md)".

 [Specification of VSprite Structure](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) 
 [Reserved VSprite Members](libraries/28-using-virtual-sprites-reserved-vsprite-members.md) 
 [Using VSprite Flags](libraries/28-using-virtual-sprites-using-vsprite-flags.md) 
 [VSprite Position](libraries/28-using-virtual-sprites-vsprite-position.md) 
 [VSprite Image Size](libraries/28-using-virtual-sprites-vsprite-image-size.md) 
 [VSprites and Collision Detection](libraries/28-using-virtual-sprites-vsprites-and-collision-detection.md) 
 [VSprite Image Data](libraries/28-using-virtual-sprites-vsprite-image-data.md) 
 [Specifying the Colors of a VSprite](libraries/28-using-virtual-sprites-specifying-the-colors-of-a-vsprite.md) 
 [Adding and Removing VSprites](libraries/28-using-virtual-sprites-adding-and-removing-vsprites.md) 
 [Changing VSprites](libraries/28-using-virtual-sprites-changing-vsprites.md) 
 [Getting the VSprite List In Order](libraries/28-using-virtual-sprites-getting-the-vsprite-list-in-order.md) 
 [Displaying the VSprites](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) 

