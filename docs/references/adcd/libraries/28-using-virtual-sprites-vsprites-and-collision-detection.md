---
title: 28 / Using Virtual Sprites / VSprites and Collision Detection
manual: libraries
chapter: libraries
section: 28-using-virtual-sprites-vsprites-and-collision-detection
functions: []
libraries: []
---

# 28 / Using Virtual Sprites / VSprites and Collision Detection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Some members of the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) data structure are used for special purposes
such as collision detection, user extensions or for system extensions
(such as Bobs and AnimComps).  For most applications these fields are set
to zero:


```c
    myVSprite.HitMask    = 0;  /* These are all used for collision */
    myVSprite.MeMask     = 0;  /* detection                        */
    myVSprite.BorderLine = 0;
    myVSprite.CollMask   = 0;

    myVSprite.VUserExt = 0;    /* Only use this for user extensions to */
                               /* VSprite                              */

    myVSprite.VSBob = NULL;    /* Only Bobs and AnimComps need this */
```
The special uses of these fields are explained further in the sections
that follow.

