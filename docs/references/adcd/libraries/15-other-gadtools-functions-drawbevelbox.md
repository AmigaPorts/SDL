---
title: 15 / / Other GadTools Functions / DrawBevelBox()
manual: libraries
chapter: libraries
section: 15-other-gadtools-functions-drawbevelbox
functions: [DrawBevelBoxA]
libraries: [gadtools.library]
---

# 15 / / Other GadTools Functions / DrawBevelBox()

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A key visual signature shared by most GadTools gadgets is the raised or
recessed bevelled box imagery.  Since the program may wish to create its
own boxes to match, GadTools provides the [DrawBevelBox()](autodocs-2.0/gadtools-library-drawbevelboxa.md) and
[DrawBevelBoxA()](autodocs-2.0/gadtools-library-drawbevelboxa.md) functions.


```c
    void DrawBevelBoxA( struct RastPort *rport, long left, long top,
                        long width, long height, struct TagItem *taglist );
    void DrawBevelBox ( struct RastPort *rport, long left, long top,
                        long width, long height, Tag tag1, ... );
```
The rport argument is a pointer to the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) into which the box is to
be rendered.  The left, top, width and height arguments specify the
dimensions of the desired box.

The tag arguments, tag1 or taglist, may be set as follows:

GT_VisualInfo (APTR)

```c
    The [VisualInfo](libraries/15-getvisualinfo-and-freevisualinfo.md) handle as returned by a prior call to [GetVisualInfo()](libraries/15-getvisualinfo-and-freevisualinfo.md).
    This value is required.
```
GTBB_Recessed (BOOL)

    A bevelled box may either appear to be raised to signify an area of
    the window that is selectable or recessed to signify an area of the
    window in which clicking will have no effect.  Set this boolean tag
    to TRUE to get a recessed box.  Omit this tag entirely to get a
    raised box.
[DrawBevelBox()](autodocs-2.0/gadtools-library-drawbevelboxa.md) is a rendering operation, not a gadget. This means that the
program must refresh any bevelled boxes rendered through this function if
the window gets damaged.

---

## See Also

- [DrawBevelBoxA — gadtools.library](../autodocs/gadtools.library.md#drawbevelboxa)
