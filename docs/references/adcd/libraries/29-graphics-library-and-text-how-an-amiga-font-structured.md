---
title: 29 Graphics Library and Text / How an Amiga Font Structured in Memory?
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-how-an-amiga-font-structured
functions: [ExtendFont]
libraries: [graphics.library]
---

# 29 Graphics Library and Text / How an Amiga Font Structured in Memory?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

So far, this chapter has concentrated on using library functions to render
text, letting the system worry about the layout of the underlying font
data.  As far as the OS representation of a loaded font is concerned,
outline fonts and normal bitmap fonts are structured identically.  Color
fonts have some extras information associated with them and are discussed
a little later.  Every loaded font, including color fonts, has a [TextFont](autodocs-2.0/includes-graphics-text-h.md)
structure associated with them:


```c
    struct TextFont {
        struct Message tf_Message;  /* reply message for font removal */
        UWORD   tf_YSize;
        UBYTE   tf_Style;
        UBYTE   tf_Flags;
        UWORD   tf_XSize;
        UWORD   tf_Baseline;
        UWORD   tf_BoldSmear; /* smear to affect a bold enhancement */

        UWORD   tf_Accessors;
        UBYTE   tf_LoChar;
        UBYTE   tf_HiChar;
        APTR    tf_CharData;  /* the bit character data */

        UWORD   tf_Modulo;  /* the row modulo for the strike font data  */
        APTR    tf_CharLoc; /* ptr to location data for the strike font */
                            /*   2 words: bit offset then size          */
        APTR    tf_CharSpace;
                           /* ptr to words of proportional spacing data */
        APTR    tf_CharKern; /* ptr to words of kerning data            */
    };
```
The first field in this structure is a [Message](libraries/24-exec-messages-and-ports-messages.md) structure.  The node in
this Message structure is what the OS uses to link together the fonts in
the system list.  From this node, an application can extract a font's
name.  The other fields in the [TextFont](autodocs-2.0/includes-graphics-text-h.md) structure are as follows:

tf_YSize

    The maximum height of this font in pixels.
tf_Style

```c
    The style bits for this particular font, which are defined in
    <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>.  These include the same style bits that were
    mentioned in the discussion of the [TextAttr](libraries/29-the-text-function-choosing-the-font.md) structure in the
    "[Choosing the Font](libraries/29-the-text-function-choosing-the-font.md)" section of this chapter.  In addition to those
    bits, there is also the FSF_COLORFONT bit, which identifies this as a
    special kind of TextFont structure called a [ColorTextFont](libraries/29-graphics-library-and-text-but-what-about-color-fonts.md) structure.
    This is discussed later in this chapter.
```
tf_Flags

```c
    The flags for this font, which were mentioned along with the style
    bits in the section, "[Choosing the Font](libraries/29-the-text-function-choosing-the-font.md)".
```
tf_XSize

```c
    If this font is monospaced (non-proportional), tf_XSize is the width
    of each character.  The width includes the extra space needed to the
    left and right of the character to keep the characters from running
    together.
```
tf_Baseline

    The distance in pixels from the top line of the font to the baseline.
tf_BoldSmear

    When algorithmically bolding, the Amiga currently "smears" a glyph by
    rendering it, moving over tf_BoldSmear number of pixels, and
    rerendering the glyph.
tf_Accessors

```c
    The number of currently open instances of this font (like the open
    count for libraries).
```
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
tf_CharData

```c
    This is the address of the bitmap from which the OS extracts the
    font's glyphs.  The individual glyphs are bit-packed together.  The
    individual bitmaps of the glyphs are placed in ASCII order side by
    side, left to right.  The last glyph is the default glyph.  The
    following is what the bitmap of the suits-8 font example looks like
    ([suits8](libraries/lib-examples-suits8-asm.md) is the complete, disk-based bitmap font example used later
    in this chapter):

      .@@@...@@@......@........@.......@@@....@@@@@@@@@@@@............
      @@@@@.@@@@@...@@@@@.....@@@.....@@@@@...@@........@@............
      .@@@@@@@@@..@@@@@@@@@..@@@@@..@@..@..@@.@@........@@............
      ..@@@@@@@..@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@........@@............
      ...@@@@@....@@@.@.@@@..@@@@@..@@..@..@@.@@........@@............
      ....@@@.........@.......@@@.......@.....@@........@@............
      .....@........@@@@@......@......@@@@@...@@@@@@@@@@@@............
      ................................................................

    This font is rather sparse, as it only has five glyphs.  Most fonts
    at least have glyphs for each letter of the alphabet.  In this
    example, each glyph represents a symbol for a suit in a standard deck
    of cards (from left to right: hearts, spades, diamonds, and clubs).
    Notice that there is no space between the individual glyphs.  The
    spacing information is kept in separate tables to reduce the amount
    of memory occupied by the font.
```
tf_Modulo

    This is number of bytes the pointer must move to go from one line of
    a glyph to the next.  This is the pixel width of the entire font
    bitmap divided by eight.  Notice that the bitmap above does not stop
    after it gets to the end of the last glyph.  It is padded with zero
    bits to the nearest WORD boundary.
tf_CharLoc

```c
    This is a pointer to the CharLoc, the character location table. This
    table tells the OS how far into the bitmap to look for a character
    and how many pixels to fetch from each row.  The CharLoc table for
    the suits-8 font looks like this:

        $0000000B,$000B000B,$00160007,$001D000B,$0028000C

    Each of the five long words in this character location table
    corresponds to a glyph in Suits-8.  Each long word is broken up into
    two word values.  The first word is the offset in pixels from the
    left edge of the bitmap to the first column containing the
    corresponding glyph.  The second word is the width in pixels of the
    corresponding glyph image in the bitmap (note, this is not the width
    of the actual glyph as the actual glyph will have some space on
    either side of it).  For example, the diamond character (the third
    character) starts at offset $16 (22) and it is 7 pixels wide.
```
tf_CharSpace

```c
    This is a pointer to an array of WORDs containing the width of each
    glyph in the font.  Each entry tells the OS how much to increment the
    current horizontal position (usually [RastPort.cp_X](libraries/27-the-rastport-structure-rastport-pen-position-and-size.md)).  For reverse
    path fonts, these values can be negative.
```
tf_CharKern

    This is a pointer to an array of "kerning" values.  As it is used
    here, the term "kerning" is unorthodox.  On the Amiga, kerning refers
    to the number pixels to leave blank before rendering a glyph.  The
    normal typographical definition of the word refers to the number of
    pixels to back up before rendering the current glyph and is usually
    associated with a specific pair of glyphs rather than one particular
    glyph.
For each glyph the system renders, it has to do several things:


```c
    1) Get the value from the kerning table that corresponds to this
       glyph and begin the rendering that number of pixels to the right.

    2) Find this glyph's bitmap using the CharLoc table and blit the
       glyph to the rastport.

    3) If this is a proportional font, look in the spacing table and
       figure how many pixels to advance the rastport's horizontal
       position.  For a monospaced font, the horizontal position
       advance comes from the TextFont's tf_XSize field.
```
Under Release 2, when the system opens a new font, it creates an extension
to the TextFont structure called the [TextFontExtension](autodocs-2.0/includes-graphics-text-h.md).  This extension is
important because it contains a pointer to the font's tag list, which is
where the system keeps the font's [TA_DeviceDPI](libraries/29-graphics-library-and-text-font-scaling-and-aspect-ratio.md) values.  The TextFont's
tf_Message.mn_ReplyPort field contains a pointer to the TextFontExtension
structure (the <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)> include file #defines
tf_Message.mn_ReplyPort as tf_Extension).  The only field of interest in
the TextFontExtension structure is:


```c
    struct TagItem *tfe_Tags;           /* Text Tags for the font */
```
which points to the font's tag list.  Before accessing the tag list, an
application should make sure that this font has a corresponding
[TextFontExtension](autodocs-2.0/includes-graphics-text-h.md).  The [ExtendFont()](autodocs-2.0/graphics-library-extendfont.md) function will return a value of TRUE
if this font already has an extension or ExtendFont() was able to create
an extension for this font.

---

## See Also

- [ExtendFont — graphics.library](../autodocs/graphics.library.md#extendfont)
