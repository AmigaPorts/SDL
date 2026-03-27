---
title: gadtools.library/DrawBevelBoxA
manual: autodocs-2.0
chapter: autodocs-2.0
section: gadtools-library-drawbevelboxa
functions: [DrawBevelBoxA, GetVisualInfoA]
libraries: [gadtools.library]
---

# gadtools.library/DrawBevelBoxA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DrawBevelBoxA -- Draws a bevelled box. (V36)
    DrawBevelBox -- Varargs stub for DrawBevelBox(). (V36)
```
SYNOPSIS

```c
    DrawBevelBoxA(rport, left, top, width, height, taglist)
                  A0     D0    D1   D2     D3      A1

    VOID DrawBevelBoxA(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD, WORD, WORD,
        struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *taglist);

    DrawBevelBox(rport, left, top, width, height, firsttag, ...)

    VOID DrawBevelBox(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, WORD, WORD, WORD, WORD,
        Tag, ...);
```
FUNCTION

```c
    DrawBevelBoxA() renders a bevelled box of specified dimensions
    into the supplied [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).
```
INPUTS

```c
    rport - The [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) into which the box is to be drawn.
    left - The left edge of the box.
    top - The top edge of the box.
    width - The width of the box.
    height - The height of the box.
    taglist - Pointer to a [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) list.
```
TAGS

```c
    GTBB_Recessed (BOOL):  Set to anything for a recessed-looking box.
        If absent, the box defaults, it would be raised.
    GT_VisualInfo (APTR):  You MUST supply the value you obtained
        from an earlier call to [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md).
```
RESULT

    None.
EXAMPLE

NOTES

```c
    DrawBevelBox() is a rendering operation, not a gadget.  That
    means you must refresh it at the appropriate time, like any
    other rendering operation.
```
BUGS

SEE ALSO

```c
    [GetVisualInfoA()](autodocs-2.0/gadtools-library-getvisualinfoa.md)
```

---

## See Also

- [DrawBevelBoxA — gadtools.library](../autodocs/gadtools.library.md#drawbevelboxa)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
