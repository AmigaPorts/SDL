---
title: IM_ERASE
manual: amiga-mail
chapter: amiga-mail
section: im-erase
functions: [EraseImage, EraseRect]
libraries: [graphics.library, intuition.library]
---

# IM_ERASE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IM_ERASE method tells an image to erase itself.  The Intuition
function EraseImage() uses this method.  IM_ERASE receives the following
parameters:


```c
    struct impErase
    {
        ULONG MethodID;
        struct RastPort *imp_RPort;
        struct
        {
            WORD X;
            WORD Y;
        } imp_Offset;
    };
```
The mytextlabelclass example doesn't know anything about this method, so
it blindly passes this message on to the superclass.  The superclass,
imageclass, will call the graphics.library function EraseRect() using the
dimensions found in the imageclass object's Image structure.

---

## See Also

- [EraseImage — intuition.library](../autodocs/intuition.library.md#eraseimage)
- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
