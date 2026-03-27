---
title: 28 / Using Virtual Sprites / Reserved VSprite Members
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-reserved-vsprite-members
functions: []
libraries: []
---

# 28 / Using Virtual Sprites / Reserved VSprite Members

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) structure members are reserved for system use (do not write
to them):


```c
    [NextVSprite and PrevVSprite](autodocs-2.0/includes-graphics-gels-h.md) -- These are used as links in the
                                   [GelsInfo](libraries/28-about-the-gels-system-the-gels-system.md) list.

         [DrawPath and ClearPath](autodocs-2.0/includes-graphics-gels-h.md) -- These are used for Bobs, not true
                                   VSprites.

                  [OldY and OldX](autodocs-2.0/includes-graphics-gels-h.md) -- Previous position holder, the system
                                   uses these for double buffered Bobs,
                                   but application programs can read
                                   them too.
```
The values can be set like this:


```c
    myVSprite.NextVSprite = NULL;
    myVSprite.PrevVSprite = NULL;
    myVSprite.DrawPath  = NULL;
    myVSprite.ClearPath = NULL;
    myVSprite.OldY = 0;
    myVSprite.OldX = 0;
```
