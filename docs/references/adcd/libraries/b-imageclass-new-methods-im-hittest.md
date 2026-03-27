---
title: B / imageclass / New Methods: IM_HITTEST
manual: libraries
chapter: libraries
section: b-imageclass-new-methods-im-hittest
functions: [PointInImage]
libraries: [intuition.library]
---

# B / imageclass / New Methods: IM_HITTEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method returns TRUE if a point is within the old [Image](libraries/8-creating-images-image-structure.md) structure box
defined by the Image structure's [LeftEdge](libraries/8-creating-images-image-structure.md), [TopEdge](libraries/8-creating-images-image-structure.md), [Width](libraries/8-creating-images-image-structure.md), and [Height](libraries/8-creating-images-image-structure.md)
fields.  Subclasses of [imageclass](libraries/b-boopsi-class-reference-imageclass.md) can redefine this method if they need to
change the criteria for deciding if a point is within an image.
Application programs should not call this method directly, instead use the
Intuition function [PointInImage()](autodocs-2.0/intuition-library-pointinimage.md).  The IM_HITTEST method uses a custom
message structure:


```c
    struct impHitTest
    {
        ULONG MethodID; /* IM_HITTEST */
        struct
        {
            WORD X;     /* Coordinates of point to test for hit */
            WORD Y;
        } imp_Point;
    };
```
If an image object doesn't need to make any changes to how its superclass
handles IM_HITTEST, it can blindly pass this method on to its superclass.

---

## See Also

- [PointInImage — intuition.library](../autodocs/intuition.library.md#pointinimage)
