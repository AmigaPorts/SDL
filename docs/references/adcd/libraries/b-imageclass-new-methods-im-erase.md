---
title: B / imageclass / New Methods: IM_ERASE
manual: libraries
chapter: libraries
section: b-imageclass-new-methods-im-erase
functions: [EraseImage, EraseRect]
libraries: [graphics.library, intuition.library]
---

# B / imageclass / New Methods: IM_ERASE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IM_ERASE method tells an image to erase itself.  Applications should
not call this method directly, instead they should call the Intuition
function [EraseImage()](autodocs-2.0/intuition-library-eraseimage.md).  The return value for this method is not explicitly
defined.

The IM_ERASE method uses a custom message structure:


```c
    struct impErase
    {
        ULONG           MethodID;   /* IM_ERASE */
        struct RastPort *imp_RPort; /* The image's RastPort */
        struct
        {
            WORD X;                 /* X and Y offset relative */
            WORD Y;                 /* to the image's IA_Left  */
        } imp_Offset;               /* and IA_Top attributes.  */
    };
```
The [imageclass](libraries/b-boopsi-class-reference-imageclass.md) dispatcher calls the graphics.library function [EraseRect()](autodocs-2.0/graphics-library-eraserect.md)
to erase the image.  The imageclass dispatcher gets the position of the
image using the offsets from the IM_ERASE message and the dimensions it
finds in the object's [Image](libraries/8-creating-images-image-structure.md) structure.  The imageclass dispatcher does not
do any bounds checking before calling EraseRect().

---

## See Also

- [EraseImage — intuition.library](../autodocs/intuition.library.md#eraseimage)
- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
