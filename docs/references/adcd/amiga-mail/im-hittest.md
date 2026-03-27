---
title: IM_HITTEST
manual: amiga-mail
chapter: amiga-mail
section: im-hittest
functions: [PointInImage]
libraries: [intuition.library]
---

# IM_HITTEST

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IM_HITTEST returns true if a point is within the image.  The Intuition
function PointInImage() uses this method.  IM_HITTEST requires the
following parameters:


```c
    struct impHitTest
    {
        ULONG MethodID;
        struct
        {
            WORD X;
            WORD Y;
        } imp_Point;
    };
```
The mytextlabelclass example blindly passes this method on to its
superclass.  The superclass, imageclass, will return TRUE if the point is
within the old Image structure box.

---

## See Also

- [PointInImage — intuition.library](../autodocs/intuition.library.md#pointinimage)
