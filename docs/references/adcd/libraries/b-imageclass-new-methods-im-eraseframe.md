---
title: B / imageclass / New Methods: IM_ERASEFRAME
manual: libraries
chapter: libraries
section: b-imageclass-new-methods-im-eraseframe
functions: []
libraries: []
---

# B / imageclass / New Methods: IM_ERASEFRAME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method is a special version of [IM_ERASE](libraries/b-imageclass-new-methods-im-erase.md) for images that support
[IM_DRAWFRAME](libraries/b-imageclass-new-methods-im-drawframe.md).  It asks an image to erase itself as if it were confined
(scaled, clipped, etc.) to a rectangular bounds.  The return value for
this method is not explicitly defined.

This method uses a custom message structure:

struct impErase /* NOTE: This is a subset of impDraw */

```c
    {
        ULONG           MethodID;   /* IM_ERASEFRAME */
        struct RastPort *imp_RPort; /* The image's RastPort */
        struct
        {
            WORD X;      /* X and Y offset relative to the */
            WORD Y;      /* image's IA_Left and IA_Top attributes */
        } imp_Offset;

        struct
        {
            WORD Width;  /* scale, clip, restrict, etc. to these bounds */
            WORD Height;
        } imp_Dimensions;
    };
```
The [imageclass](libraries/b-boopsi-class-reference-imageclass.md) dispatcher handles an IM_ERASEFRAME message as if it was an
IM_ERASE message, ignoring the bounds.  See the imageclass description for
[IM_ERASE](libraries/b-imageclass-new-methods-im-erase.md) for more details.

