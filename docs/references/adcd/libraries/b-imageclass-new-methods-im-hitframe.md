---
title: B / imageclass / New Methods: IM_HITFRAME
manual: libraries
chapter: libraries
section: b-imageclass-new-methods-im-hitframe
functions: []
libraries: []
---

# B / imageclass / New Methods: IM_HITFRAME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method is a special version of [IM_HITTEST](libraries/b-imageclass-new-methods-im-hittest.md) for images that support
[IM_DRAWFRAME](libraries/b-imageclass-new-methods-im-drawframe.md).  It asks an image if a point would be inside it if the image
was confined (scaled, clipped, etc.) to a rectangular bounds.  The return
value for this method is not explicitly defined.

This method uses a custom message structure:


```c
    struct impHitTest
    {
        ULONG MethodID;    /* IM_HITFRAME */
        struct
        {
            WORD X;        /* Coordinates of point to test for hit */
            WORD Y;
        } imp_Point;

        struct
        {
            WORD Width;  /* scale, clip, restrict, etc. to these bounds */
            WORD Height;
        } imp_Dimensions;
    };
```
The [imageclass](libraries/b-boopsi-class-reference-imageclass.md) dispatcher treats IM_HITFRAME just like [IM_HITTEST](libraries/b-imageclass-new-methods-im-hittest.md),
ignoring the restricting dimensions.

