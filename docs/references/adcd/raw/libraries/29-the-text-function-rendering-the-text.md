# 29 / The Text Function / Rendering the Text


When the [Text()](../Libraries_Manual_guide/node03D5.html) routine renders text, it renders at the current rastport
position along the text's baseline.  The baseline is an imaginary line on
top of which the text is rendered.  Each font has a baseline that is a
constant number of pixels from the top of the font's bitmap.  For most
fonts, parts of some characters are rendered both above and below the
baseline (for example, y, g, and j usually have parts above and below the
baseline).  The part below the baseline is called the descender.


```c
     [Figure 29-1: Descenders and Baseline of Amiga Fonts](../Libraries_Manual_guide/node05F8.html) 
```
Because [Text()](../Libraries_Manual_guide/node03D5.html) only increments the rastport's current X position as it
renders text horizontally, programs that need to print several lines of
text have to take care of moving the current pointer to the beginning of
the next line, usually with the graphics.library's [Move()](../Libraries_Manual_guide/node0359.html) function:


```c
    void Move( struct RastPort *rp, LONG x, long y );
```
When moving the current position to the beginning of the next line, an
application must make sure it leaves enough space above and below the
baseline to prevent characters on different lines from overlapping each
other.  There are a few fields in the [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line89) structure returned by
[OpenFont()](../Libraries_Manual_guide/node03D6.html#line5) and [OpenDiskFont()](../Libraries_Manual_guide/node03D6.html#line5) that are useful for spacing and rendering
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
Using the current font, [ClearEOL()](../Includes_and_Autodocs_2._guide/node0429.html) will clear the rest of the current text
line from the rastport's current position to the edge of the rastport.
ClearEOL() was introduced in the Release 2 graphics.library.
[ClearScreen()](../Includes_and_Autodocs_2._guide/node042C.html) will clear the rest of the line as ClearEOL() does, but it
will also clear the rastport below the current line of text.

