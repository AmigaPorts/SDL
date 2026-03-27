---
title: graphics.library/Text
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-text
functions: [Move, TextLength]
libraries: [graphics.library]
---

# graphics.library/Text

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Text -- Write text characters (no formatting).
```
SYNOPSIS

```c
    Text(rp, string, length)
         A1  A0      D0-0:16

    void Text(struct [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) *, STRPTR, WORD);
```
FUNCTION

```c
    This graphics function writes printable text characters to the
    specified [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) at the current position.  No control meaning
    is applied to any of the characters, thus only text on the
    current line is output.

    The current position in the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) is updated to the next
    character position.
    If the characters displayed run past the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) boundary,
    the current position is truncated to the boundary, and
    thus does not equal the old position plus the text length.
```
INPUTS

```c
    rp     - a pointer to the [RastPort](autodocs-2.0/includes-graphics-rastport-h.md) which describes where the
             text is to be output
    string - the address of string to output
    length - the number of characters in the string.
             If zero, there are no characters to be output.
```
NOTES

    o   This function may use the blitter.
    o   Changing the text direction with RastPort->TxSpacing is
        not supported.
BUGS

```c
    For V34 and earlier:
    o   The maximum string length (in pixels) is limited to
        (1024 - 16 = 1008) pixels wide.
    o   A text string whose last character(s) have a
        tf_CharLoc size component that extends to the right of
        the rightmost of the initial and final CP positions
        will be (inappropriately) clipped.
```
SEE ALSO

```c
    [Move()](autodocs-2.0/graphics-library-move.md)  [TextLength()](autodocs-2.0/graphics-library-textlength.md)  [graphics/text.h](autodocs-2.0/includes-graphics-text-h.md)  [graphics/rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)
```

---

## See Also

- [Move — graphics.library](../autodocs/graphics.library.md#move)
- [TextLength — graphics.library](../autodocs/graphics.library.md#textlength)
