---
title: 8 / Creating Text / IntuiText Structure
manual: libraries
chapter: libraries
section: 8-creating-text-intuitext-structure
functions: [PrintIText]
libraries: [intuition.library]
---

# 8 / Creating Text / IntuiText Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To render text using Intuition, the application must create one or more
instances of the [IntuiText](autodocs-2.0/includes-intuition-intuition-h.md) structure:


```c
    struct IntuiText
        {
        UBYTE FrontPen, BackPen;
        UBYTE DrawMode;
        WORD LeftEdge;
        WORD TopEdge;
        struct TextAttr *ITextFont;
        UBYTE *IText;
        struct IntuiText *NextText;
        };
```
Here is a brief description of each member of the IntuiText structure:

FrontPen

    The pen number specifying the color used to draw the text.
BackPen

    The pen number specifying the color used to draw the background for
    the text, if JAM2 drawing mode is specified.
DrawMode

```c
    This field specifies one of four drawing modes:

    JAM1
        FrontPen is used to draw the text; background color is unchanged.

    JAM2
        FrontPen is used to draw the text; background color is changed
        to the color in BackPen.

    COMPLEMENT
        The characters are drawn in the complement of the colors that
        were in the background.

    INVERSVID
        Inverses the draw modes describe above.  For instance INVERVID
        used with JAM1 means the character is untouched while the
        background is filled with the color of the FrontPen.
```
LeftEdge and TopEdge

```c
    The location of the text relative to its base position when it is
    drawn.  These offsets are added to the base position to determine the
    final location of the text data.

    The base position for text rendered with [PrintIText()](libraries/8-creating-text-directly-drawing-the-intuitext.md) is taken from
    arguments passed in the function call.  For gadgets and menus, the
    base position is always the upper, left corner of the select box.
    For requesters the base position is always the upper, left corner of
    the requester.

    LeftEdge gives the offset of the left edge of the character cell and
    TopEdge gives the offset of the top edge of the character cell for
    the first character in the text string.  Negative values of LeftEdge
    and TopEdge move the position up and to the left of the base
    position.  Positive values move down and to the right.
```
ITextFont

    A pointer to a TextAttr structure defining the font to be used. Set
    this to NULL to use the default font.
IText

    A pointer to the NULL terminated text string to be displayed.
NextText

    A pointer to another instance of IntuiText.  Set this field to NULL
    for the last IntuiText in a list.

---

## See Also

- [PrintIText — intuition.library](../autodocs/intuition.library.md#printitext)
