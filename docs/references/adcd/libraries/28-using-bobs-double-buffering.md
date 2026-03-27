---
title: 28 / Using Bobs / Double-Buffering
manual: libraries
chapter: libraries
section: 28-using-bobs-double-buffering
functions: []
libraries: []
---

# 28 / Using Bobs / Double-Buffering

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Double-buffering is the technique of supplying two different memory areas
in which the drawing routines may create images.  The system displays one
memory space while drawing into the other area.  This eliminates the
"flickering" that is visible when a single display is being rendered into
at the same time that it is being displayed.


    Double-buffering For One Means Double-buffering For All.
    --------------------------------------------------------
    If any of the Bobs is double-buffered, then all of them must be
    double-buffered.
To find whether a Bob is to be double-buffered, the system examines the
pointer named [DBuffer](libraries/28-using-bobs-the-bob-structure.md) in the [Bob](libraries/28-using-bobs-the-bob-structure.md) structure.  If this pointer has a value
of NULL, the system does not use double-buffering for this Bob.  For
example:


```c
    myBob.DBuffer = NULL; /* do this if this Bob is NOT double-buffered */
```
 [DBufPacket and Double-Buffering](libraries/28-double-buffering-dbufpacket-and-double-buffering.md) 

