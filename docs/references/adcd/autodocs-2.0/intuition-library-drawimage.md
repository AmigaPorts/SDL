---
title: intuition.library/DrawImage
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-drawimage
functions: [DrawImageState, EraseImage]
libraries: [intuition.library]
---

# intuition.library/DrawImage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DrawImage -- Draw the specified [Image](autodocs-2.0/includes-intuition-intuition-h.md) structure into a [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
SYNOPSIS

```c
    DrawImage( [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), [Image](autodocs-2.0/includes-intuition-intuition-h.md), LeftOffset, TopOffset )
               A0        A1     D0          D1

    VOID DrawImage( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [Image](autodocs-2.0/includes-intuition-intuition-h.md)    *, WORD, WORD );
```
FUNCTION

```c
    First, sets up the draw mode and pens in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) according to the
    arguments of the [Image](autodocs-2.0/includes-intuition-intuition-h.md) structure.  Then, moves the image data of
    the image argument into the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), offset by the left and top
    offsets.

    This routine does window layer clipping if you pass your window's
    (layered) [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) -- if you draw an image outside of your window,
    your imagery will be clipped at the window's edge.  If you pass
    a (non-layered) screen [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), you MUST be sure your image is
    wholly contained within the rastport bounds.

    If the NextImage field of the image argument is non-NULL,
    the next image is rendered as well, and so on until some
    NextImage field is found to be NULL.
```
INPUTS

```c
    [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) = pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to receive image rendering
    [Image](autodocs-2.0/includes-intuition-intuition-h.md) = pointer to an image structure
    LeftOffset = the offset which will be added to the image's x coordinate
    TopOffset = the offset which will be added to the image's y coordinate
```
RESULT

    None
NOTES

```c
    Intuition always has and will continue to assume there are
    at least as many planes of data pointed to by ImageData as there
    are '1' bits in the PlanePick field.  Please ensure that
    this is so.  (See the intuition.h include file for full details
    on using PlanePick).
```
BUGS

SEE ALSO

```c
    [DrawImageState()](autodocs-2.0/intuition-library-drawimagestate.md), [EraseImage()](autodocs-2.0/intuition-library-eraseimage.md)
```

---

## See Also

- [DrawImageState — intuition.library](../autodocs/intuition.library.md#drawimagestate)
- [EraseImage — intuition.library](../autodocs/intuition.library.md#eraseimage)
