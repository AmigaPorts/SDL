---
title: 28 / Using Bobs / Removing a Bob
manual: libraries
chapter: libraries
section: 28-using-bobs-removing-a-bob
functions: [DrawGList, RemBob, RemIBob]
libraries: [graphics.library]
---

# 28 / Using Bobs / Removing a Bob

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Two methods may be used to remove a Bob.  The first method uses the
[RemBob()](autodocs-2.0/graphics-library-rembob.md) macro.  RemBob() causes the system to remove the Bob during the
next call to [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) (or two calls to DrawGList() if the system is
double-buffered).  RemBob() asks the system to remove the Bob at the next
convenient time.  See the description of the [BOBSAWAY](libraries/28-using-bobs-using-bob-flags.md) and [BOBNIX](libraries/28-using-bobs-using-bob-flags.md) flags
above. It is called as follows:


```c
    struct Bob myBob = {0};

    RemBob(&myBob);
```
The second method uses the [RemIBob()](autodocs-2.0/graphics-library-remibob.md) routine.  RemIBob() tells the system
to remove this Bob immediately.  For example:


```c
    struct Bob      myBob = {0};
    struct RastPort rastport = {0};
    struct ViewPort viewport = {0};

    RemIBob(&myBob, &rastport, &viewport);
```
This causes the system to erase the Bob from the drawing area and causes
the immediate erasure of any other Bob that had been drawn subsequent to
(and on top of) this one.  The system then unlinks the Bob from the system
GEL list.  To redraw the Bobs that were drawn on top of the one just
removed, another call to [DrawGList()](libraries/28-using-virtual-sprites-displaying-the-vsprites.md) must be made.

---

## See Also

- [DrawGList — graphics.library](../autodocs/graphics.library.md#drawglist)
- [RemBob — graphics.library](../autodocs/graphics.library.md#rembob)
- [RemIBob — graphics.library](../autodocs/graphics.library.md#remibob)
