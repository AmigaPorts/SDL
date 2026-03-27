---
title: IM_ERASEFRAME
manual: amiga-mail
chapter: amiga-mail
section: im-eraseframe
functions: []
libraries: []
---

# IM_ERASEFRAME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IM_ERASEFRAME method instructs an image confined to a given rectangle
to erase itself.  Normally this method is used to erase an image drawn
using the IM_DRAWFRAME method.  This method expects the following
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

        /* these parameters only valid for IM_ERASEFRAME */
        struct
        {
            WORD Width;
            WORD Height;
        } imp_Dimensions;
    };
```
The mytextlabelclass example blindly passes this method on to its
superclass.  The superclass treats IM_ERASEFRAME just like IM_ERASE.

