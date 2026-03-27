---
title: 28 / / Types Of GELs / VSprites vs. Bobs
manual: libraries
chapter: libraries
section: 28-types-of-gels-vsprites-vs-bobs
functions: []
libraries: []
---

# 28 / / Types Of GELs / VSprites vs. Bobs

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you are going to manage the movement and sequencing of GELS yourself,
you need to decide if sprite animation (VSprites) or blitter animation
(Bobs, AnimComps and AnimObs) best suit your needs.  If you've got simple
requirements or lots of coding time, you may even opt to use only Simple
Sprites, and control them yourself.  On the other hand if you want the
system to manage your animations,  AnimComps must be used and they are
Bobs at heart.

Some fundamental differences between VSprites and Bobs are:

  * VSprite images and coordinates currently low-resolution pixels, even

    on a high resolution display.  Bob images and coordinates have the
    same resolution as the playfield they are rendered into.
  * VSprites have a maximum width of 16 (low resolution) pixels.  Bobs

```c
    can be any width (although large Bobs tend to slow down the system).
    The height of either VSprites or Bobs can be as tall as the display.
```
  * VSprites have a maximum of three colors (Simple Sprites can have

```c
    fifteen if they're attached).  Because the system uses the Copper to
    control VSprite colors on the fly, the colors are not necessarily the
    same as those in the background playfield.  Bobs can use any or all
    of the colors in the background playfield.  Limiting factors include
    playfield resolution and display time.  Bobs with more colors take
    longer to display.
```
  * VSprites are positioned using absolute display coordinates, and don't

    move with screens.  Bobs follow screen movement.
In general, VSprites offer speed, while Bobs offer flexibility.

The following figure shows how the various GEL data structures, [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)s,
[Bobs](libraries/28-using-bobs-the-bob-structure.md) and [AnimComps](libraries/28-animation-with-gels-animation-data-structures.md) are linked together.



       VSPRITE                  BOB                 ANIMCOMP
     ____________           ____________          ____________
    |            |       _\|            |      _\|            |
    | VSprite    |      | /| VSprite    |     | /| VSprite    |
    |____________|      |  |____________|     |  |____________|
    |            |  _   |  |            |     |  |            |
    | VSpriteBob |-|_|  |  | VSpriteBob |__   |  | VSpriteBob |__
    |____________|      |  |____________|  |  |  |____________|  |
                        |                  |  |                  |
                        |                  |  |                  |
                        |   ____________   |  |   ____________   |
                        |  |            |/_|  |  |            |/_|
                        |  | Bob        |\    |  | Bob        |>___
                        |  |____________|     |  |____________|\   |
                        |  |            |     |  |            |    |
                        |__| BobVSprite |     |__| BobVSprite |__  |
                           |____________|        |____________|  | |
                           |            |  _                     | |
                           | BobComp    |-|_|                    | |
                           |____________|         ____________   | |
                                                 |            |/_| |
                                                 | AnimComp   |\   |
                                                 |____________|    |
                                                 |            |    |
                                                 | Bob        |____|
                                                 |____________|


                  Figure 28-1: GEL Structure Layout
