---
title: 28 / / The Bob Structure / Linking Bob and VSprite Structures
manual: libraries
chapter: libraries
section: 28-the-bob-structure-linking-bob-and-vsprite-structures
functions: []
libraries: []
---

# 28 / / The Bob Structure / Linking Bob and VSprite Structures

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) and [Bob](libraries/28-using-bobs-the-bob-structure.md) structures must point to one another, so that the
system can find the entire GEL.  The structures are linked with statements
like this:


```c
    myBob.BobVSprite = &myVSprite;
    myVSprite.VSBob  = &myBob;
```
Now the system (and the application program) can go back and forth between
the two structures to obtain the various [Bob](libraries/28-using-bobs-the-bob-structure.md) variables.

