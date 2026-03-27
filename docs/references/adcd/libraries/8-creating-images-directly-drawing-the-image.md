---
title: 8 / Creating Images / Directly Drawing the Image
manual: libraries
chapter: libraries
section: 8-creating-images-directly-drawing-the-image
functions: [DrawImage]
libraries: [intuition.library]
---

# 8 / Creating Images / Directly Drawing the Image

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As noted above, you use the [DrawImage()](autodocs-2.0/intuition-library-drawimage.md) call to directly draw an image
into a screen or window [RastPort](libraries/27-drawing-routines-the-rastport-structure.md).


```c
    void DrawImage( struct RastPort *rp, struct Image *image,
                    long leftOffset, long topOffset );
```
The rp argument is a pointer to the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) into which the image should
be drawn.  This RastPort may come from a Window or Screen structure.

The image argument is a pointer to the list of [Image](libraries/8-creating-images-image-structure.md) structures that are
to be rendered.  The list may contain a single Image structure.

The leftOffset and topOffset arguments are the external component, or the
base position, for this list of images.  The [LeftEdge](libraries/8-creating-images-image-structure.md) and [TopEdge](libraries/8-creating-images-image-structure.md) values
of each [Image](libraries/8-creating-images-image-structure.md) structure are added to these values to determine the final
position of each image.

Images may also be indirectly drawn by attaching them to gadgets, menus or
requesters when they are initialized.

---

## See Also

- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
