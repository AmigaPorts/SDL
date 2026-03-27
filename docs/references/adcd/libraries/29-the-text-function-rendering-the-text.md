---
title: 29 / The Text Function / Rendering the Text
manual: libraries
chapter: libraries
section: 29-the-text-function-rendering-the-text
functions: [ClearEOL, ClearScreen, Move, OpenDiskFont, OpenFont, Text]
libraries: [diskfont.library, graphics.library]
---

# 29 / The Text Function / Rendering the Text

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the [Text()](libraries/29-graphics-library-and-text-the-text-function.md) routine renders text, it renders at the current rastport
position along the text's baseline.  The baseline is an imaginary line on
top of which the text is rendered.  Each font has a baseline that is a
constant number of pixels from the top of the font's bitmap.  For most
fonts, parts of some characters are rendered both above and below the
baseline (for example, y, g, and j usually have parts above and below the
baseline).  The part below the baseline is called the descender.


```c
     [Figure 29-1: Descenders and Baseline of Amiga Fonts](libraries/lib-pics-29-1-pic.md) 
```
Because [Text()](libraries/29-graphics-library-and-text-the-text-function.md) only increments the rastport's current X position as it
renders text horizontally, programs that need to print several lines of
text have to take care of moving the current pointer to the beginning of
the next line, usually with the graphics.library's [Move()](libraries/27-using-the-graphics-drawing-routines-drawing-lines.md) function:


```c
    void Move( struct RastPort *rp, LONG x, long y );
```
When moving the current position to the beginning of the next line, an
application must make sure it leaves enough space above and below the
baseline to prevent characters on different lines from overlapping each
other.  There are a few fields in the [TextFont](autodocs-2.0/includes-graphics-text-h.md) structure returned by
[OpenFont()](libraries/29-the-text-function-choosing-the-font.md) and [OpenDiskFont()](libraries/29-the-text-function-choosing-the-font.md) that are useful for spacing and rendering
text:


struct TextFont {
```c
    struct Message tf_Message; /* reply message for font removal */
                               /* font name in LN       | used in this */
    UWORD   tf_YSize;          /* font height           | order to best */
    UBYTE   tf_Style;          /* font style            | match a font */
    UBYTE   tf_Flags;          /* preferences and flags / request. */
    UWORD   tf_XSize;      /* nominal font width */
    UWORD   tf_Baseline;   /* distance from the top of char to baseline */
    UWORD   tf_BoldSmear;  /* smear to affect a bold enhancement */

    UWORD   tf_Accessors;  /* access count */

    UBYTE   tf_LoChar;     /* the first character described here */
    UBYTE   tf_HiChar;     /* the last character described here */
    APTR    tf_CharData;   /* the bit character data */

    UWORD   tf_Modulo;     /* the row modulo for the strike font data */
    APTR    tf_CharLoc;    /* ptr to location data for the strike font */
                           /*   2 words: bit offset then size */
    APTR    tf_CharSpace;  /* ptr to words of proportional spacing data */
    APTR    tf_CharKern;   /* ptr to words of kerning data */
```
};


The fields of interest to applications are as follows.

tf_YSize

    The "height", in pixels, of this font.  None of the characters in
    this font will be taller than this value.
tf_XSize

```c
    This is the character width for monospaced (non-proportional) fonts.
    The width includes the extra space needed to the left and right of
    the character to keep the characters from running together.
```
tf_Baseline

    The distance in pixels from the top line of the font to the baseline.
tf_LoChar

```c
    This is the first character glyph (the graphical symbol associated
    with this font) defined in this font.  All characters that have ASCII
    values below this value do not have an associated glyph.
```
tf_HiChar

    This is the last character glyph defined in this font.  All
    characters that have ASCII values above this value do not have an
    associated glyph.  An application can use these values to avoid
    rendering characters which have no associated glyphs.  Any characters
    without an associated glyph will have the default glyph associated to
    them.  Normally, the default glyph is a rectangle.
To erase text, the graphics.library provides two functions that were
specifically designed to clear parts of a rastport based on the dimensions
of the current font:


```c
    void ClearEOL( struct RastPort *rp );
    void ClearScreen( struct RastPort *rp );
```
Using the current font, [ClearEOL()](autodocs-2.0/graphics-library-cleareol.md) will clear the rest of the current text
line from the rastport's current position to the edge of the rastport.
ClearEOL() was introduced in the Release 2 graphics.library.
[ClearScreen()](autodocs-2.0/graphics-library-clearscreen.md) will clear the rest of the line as ClearEOL() does, but it
will also clear the rastport below the current line of text.

---

## See Also

- [ClearEOL — graphics.library](../autodocs/graphics.library.md#cleareol)
- [ClearScreen — graphics.library](../autodocs/graphics.library.md#clearscreen)
- [Move — graphics.library](../autodocs/graphics.library.md#move)
- [OpenDiskFont — diskfont.library](../autodocs/diskfont.library.md#opendiskfont)
- [OpenFont — graphics.library](../autodocs/graphics.library.md#openfont)
- [Text — graphics.library](../autodocs/graphics.library.md#text)
