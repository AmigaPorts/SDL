---
title: B / imageclass / New Methods: IM_DRAWFRAME
manual: libraries
chapter: libraries
section: b-imageclass-new-methods-im-drawframe
functions: []
libraries: []
---

# B / imageclass / New Methods: IM_DRAWFRAME

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The IM_DRAWFRAME method instructs an image object to render itself within
the confines of a given rectangle.  The return value for this method is
not explicitly defined.

This method uses a custom message structure that is basically an extension
of the [IM_DRAW](libraries/b-imageclass-new-methods-im-draw.md) message: struct [impDraw](libraries/b-imageclass-new-methods-im-draw.md)


```c
    {
        ULONG           MethodID;    /* IM_DRAWFRAME */
        struct RastPort *imp_RPort;  /* RastPort to render into */
        struct
        {
            WORD X;                  /* X and Y offset relative to the */
            WORD Y;           /* image's IA_Left and IA_Top attributes */
        } imp_Offset;
        ULONG    imp_State;  /* Visual state of image (see defines below)*/
        struct DrawInfo *imp_DrInfo;
                    /* DrawInfo describing target RastPort (can be NULL) */
        struct
        {
            WORD Width;   /* scale, clip, restrict, etc. to these bounds */
            WORD Height;
        } imp_Dimensions;
    };
```
The Width and Height fields provide the object's rectangular bounds.  How
the image object deals with the frame is implementation specific.  If the
[imageclass](libraries/b-boopsi-class-reference-imageclass.md) dispatcher sees this message, it will convert it to an [IM_DRAW](libraries/b-imageclass-new-methods-im-draw.md)
message and send it back to the image's true class.  An image subclass
which assigns proper meaning to this method (i.e., [frameiclass](libraries/b-boopsi-class-reference-frameiclass.md)) should
handle this method itself.

This method is useful to classes of images that can scale or clip
themselves to arbitrary dimensions.  Typically, an instance of a class
that truly supports this method will massage its imagery as best it can to
fit into the rectangle.

In general, applications that use this method to draw an object should use
the [IM_ERASEFRAME](libraries/b-imageclass-new-methods-im-eraseframe.md) method to erase it (see below).  This will ensure that
the image erases itself at the proper scale.

