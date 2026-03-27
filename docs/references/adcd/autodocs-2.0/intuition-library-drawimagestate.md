---
title: intuition.library/DrawImageState
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-drawimagestate
functions: [DrawImage, GetScreenDrawInfo]
libraries: [intuition.library]
---

# intuition.library/DrawImageState

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DrawImageState -- Draw an (extended) Intuition [Image](autodocs-2.0/includes-intuition-intuition-h.md) with
            special visual state. (V36)
```
SYNOPSIS

```c
    DrawImageState( RPort, [Image](autodocs-2.0/includes-intuition-intuition-h.md), LeftOffset, TopOffset, State, [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) )
                    A0     A1     D0          D1         D2     A2

    VOID DrawImageState( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [Image](autodocs-2.0/includes-intuition-intuition-h.md) *,
            WORD, WORD, ULONG, struct [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) * );
```
FUNCTION

```c
    This function draws an Intuition [Image](autodocs-2.0/includes-intuition-intuition-h.md) structure in a variety of
    "visual states," which are defined by constants in
    [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md).  These include:
    IDS_NORMAL              - like [DrawImage()](autodocs-2.0/intuition-library-drawimage.md)
    IDS_SELECTED            - represents the "selected state" of a [Gadget](autodocs-2.0/includes-intuition-intuition-h.md)
    IDS_DISABLED            - the "ghosted state" of a gadget
    IDS_BUSY                - for future functionality
    IDS_INDETERMINATE       - for future functionality
    IDS_INACTIVENORMAL      - for gadgets in window border
    IDS_INACTIVESELECTED    - for gadgets in window border
    IDS_INACTIVEDISABLED    - for gadgets in window border

    Only IDS_NORMAL will make sense for traditional [Image](autodocs-2.0/includes-intuition-intuition-h.md) structures,
    this function is more useful when applied to new custom images
    or "object-oriented image classes."

    Each class of custom images is responsible for documenting which
    visual states it supports, and you typically want to use images
    which support the appropriate states with your custom gadgets.

    The [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) parameter provides information invaluable to
    "rendered" images, such as pen color and resolution.  Each
    image class must document whether this parameter is required.
```
INPUTS

```c
    RPort   - [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) for rendering
    [Image](autodocs-2.0/includes-intuition-intuition-h.md)   - pointer to a (preferably custom) image
    LeftOffset,RightOffset - positional offsets in pixels
    State   - visual state selected from above
    [DrawInfo](autodocs-2.0/includes-intuition-screens-h.md) - pointer to packed of pen selections and resolution.
```
RESULT

    None.
EXAMPLE

    Provided separately in the DevCon '90 disk set.
NOTES


BUGS


SEE ALSO

```c
    [DrawImage()](autodocs-2.0/intuition-library-drawimage.md), [GetScreenDrawInfo()](autodocs-2.0/intuition-library-getscreendrawinfo.md), [intuition/imageclass.h](autodocs-2.0/includes-intuition-imageclass-h.md)
```

---

## See Also

- [DrawImage — intuition.library](../autodocs/intuition.library.md#drawimage)
- [GetScreenDrawInfo — intuition.library](../autodocs/intuition.library.md#getscreendrawinfo)
