---
title: intuition.library/EraseImage
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-eraseimage
functions: [EraseRect]
libraries: [graphics.library]
---

# intuition.library/EraseImage

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    EraseImage -- Erases an [Image](autodocs-2.0/includes-intuition-intuition-h.md). (V36)
```
SYNOPSIS

```c
    EraseImage( RPort, [Image](autodocs-2.0/includes-intuition-intuition-h.md), LeftOffset, TopOffset )
                A0     A1     D0          D1

    VOID EraseImage( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [Image](autodocs-2.0/includes-intuition-intuition-h.md) *, WORD, WORD );
```
FUNCTION

```c
    Erases an [Image](autodocs-2.0/includes-intuition-intuition-h.md).  For a normal [Image](autodocs-2.0/includes-intuition-intuition-h.md) structure, this will
    call the graphics function [EraseRect()](autodocs-2.0/graphics-library-eraserect.md) (clear using layer
    backfill, if any) for the [Image](autodocs-2.0/includes-intuition-intuition-h.md) box (LeftEdge/TopEdge/Width/Height).

    For custom image, the exact behavior is determined by the
    custom image class.
```
INPUTS

```c
    RPort   - [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) to erase a part of
    [Image](autodocs-2.0/includes-intuition-intuition-h.md)   - custom or standard image
    LeftOffset,RightOffset - pixel offsets of [Image](autodocs-2.0/includes-intuition-intuition-h.md) position
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [graphics.library/EraseRect()](autodocs-2.0/graphics-library-eraserect.md).
```

---

## See Also

- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
