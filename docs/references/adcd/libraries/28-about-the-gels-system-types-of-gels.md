---
title: 28 / About the GELs System / Types of GELs
manual: libraries
chapter: libraries
section: 28-about-the-gels-system-types-of-gels
functions: []
libraries: []
---

# 28 / About the GELs System / Types of GELs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The GEL types are (in order of increasing complexity):


```c
    [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)s   for Virtual Sprites.  These are represented by the VSprite
               data structure and implemented with sprite hardware.

    [Bob](libraries/28-using-bobs-the-bob-structure.md)s       Blitter Objects.  These are represented by the VSprite and
               Bob data structures and implemented with blitter hardware.

    [AnimComps](libraries/28-animation-with-gels-animation-data-structures.md)  Animation Components.  These are represented by the
               VSprite, Bob and AnimComp data structures and implemented
               with blitter hardware.

    [AnimObs](libraries/28-animation-with-gels-animation-data-structures.md)    Animation Objects.  These are used to group AnimComps. They
               are not strictly GELs, but are described here.
```
 [Simple Sprites](libraries/28-types-of-gels-simple-sprites.md)    [Bobs and AnimComps](libraries/28-types-of-gels-bobs-and-animcomps.md)    [VSprites vs. Bobs](libraries/28-types-of-gels-vsprites-vs-bobs.md) 
 [VSprites](libraries/28-types-of-gels-vsprites.md)          [AnimObs](libraries/28-types-of-gels-animobs.md) 

