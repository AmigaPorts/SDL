---
title: 28 / / Detecting Gel Collisions / Preparing for Collision Detection
manual: libraries
chapter: libraries
section: 28-detecting-gel-collisions-preparing-for-collision
functions: []
libraries: []
---

# 28 / / Detecting Gel Collisions / Preparing for Collision Detection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Before you can use the system to detect collisions between GELS, you must
allocate and initialize a table of collision-detection routines and place
the address of the table in the [GelsInfo.CollHandler](libraries/28-detecting-collisions-building-a-table-of-collision.md) field.  This table is
an array of pointers to the actual routines that you have provided for
your collision types.  You must also prepare some members of the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md)
structure: [CollMask](libraries/28-detecting-gel-collisions-vsprite-collision-mask.md), [BorderLine](libraries/28-detecting-gel-collisions-vsprite-borderline.md), [HitMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md), and [MeMask](libraries/28-detecting-gel-collisions-using-hitmask-and-memask.md).

