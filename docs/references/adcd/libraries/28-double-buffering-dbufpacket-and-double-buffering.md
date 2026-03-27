---
title: 28 / / Double-Buffering / DBufPacket and Double-Buffering
manual: libraries
chapter: libraries
section: 28-double-buffering-dbufpacket-and-double-buffering
functions: []
libraries: []
---

# 28 / / Double-Buffering / DBufPacket and Double-Buffering

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For double-buffering, a place must be provided for the system to store the
extra information it needs.  The system maintains these data, and does not
expect the application to change them.  The [DBufPacket](autodocs-2.0/includes-graphics-gels-h.md) structure consists
of the following members:

[BufY, BufX](autodocs-2.0/includes-graphics-gels-h.md)  Lets the system keep track of where the object was located

```c
            in the last frame (as compared to the [Bob](libraries/28-using-bobs-the-bob-structure.md) structure
            members called [OldY and OldX](autodocs-2.0/includes-graphics-gels-h.md) that tell where the object
            was two frames ago).  BufY and BufX provide for correct
            restoration of the background within the currently active
            drawing buffer.
```
[BufPath](autodocs-2.0/includes-graphics-gels-h.md)     Assures that the system restores the backgrounds in the

```c
            correct sequence; it relates to the [VSprite](libraries/28-using-virtual-sprites-specification-of-vsprite-structure.md) members
            [DrawPath](libraries/28-using-virtual-sprites-reserved-vsprite-members.md) and [ClearPath](libraries/28-using-virtual-sprites-reserved-vsprite-members.md).
```
[BufBuffer](autodocs-2.0/includes-graphics-gels-h.md)   This field must be set to point to a buffer the same size

```c
            as the Bob's [SaveBuffer](libraries/28-using-bobs-the-bob-structure.md).  This buffer is used to store the
            background for later restoration when the system moves the
            object.  This buffer must be allocated from Chip memory.
```
To create a double-buffered Bob, execute a code sequence similar to the
following:


```c
    struct Bob        myBob = {0};
    struct DBufPacket myDBufPacket = {0};

    /* Allocate a DBufPacket for myBob same size as previous example */
    if (NULL != (myDBufPacket.BufBuffer = AllocRaster(48, 20 * 5)))
        {
        /* tell Bob about its double buff status */
        myBob.DBuffer = myDBufPacket;
        }
```
The example routines [makeBob()](libraries/lib-examples-animtools-c.md) and [freeBob()](libraries/lib-examples-animtools-c.md) in the [animtools.c](libraries/lib-examples-animtools-c.md) listing at
the end of this chapter show how to correctly allocate and free a
double-buffered Bob.

