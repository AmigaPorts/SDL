---
title: intuition.library/PrintIText
manual: autodocs-2.0
chapter: autodocs-2.0
section: intuition-library-printitext
functions: []
libraries: []
---

# intuition.library/PrintIText

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    PrintIText -- Print text described by the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) argument.
```
SYNOPSIS

```c
    PrintIText( [RastPort](autodocs-2.0/includes-graphics-rastport-h.md), IText, LeftOffset, TopOffset )
                A0        A1     D0          D1

    VOID PrintIText( struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, struct [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) *, WORD, WORD );
```
FUNCTION

```c
    Prints the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) into the specified [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).  Sets up the
    [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) as specified by the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) values, then prints the text
    into the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) at the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) x/y coordinates offset by the
    left/top arguments.  Note, though, that the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) structure
    itself may contain further text position coordinates: those
    coordinates and the Left/TopOffsets are added to obtain the true
    position of the text to be rendered.

    This routine does window layer clipping as appropriate -- if you
    print text outside of your window, your characters will be
    clipped at the window's edge, providing you pass your window's
    (layered) [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).

    If the NextText field of the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) argument is non-NULL,
    the next [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) is rendered as well, and so on until some
    NextText field is NULL.

    [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) with the ITextFont field NULL are displayed in the
    font of the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md).  If the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) font is also NULL, the
    system default font, as set via the [Preferences](autodocs-2.0/includes-intuition-preferences-h.md) tool, will be used.
```
INPUTS

```c
    [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) = the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) destination of the text
    IText = pointer to an instance of the structure [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md)
    LeftOffset = left offset of the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) into the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
    TopOffset = top offset of the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) into the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md)
```
RESULT

    None
BUGS

SEE ALSO

