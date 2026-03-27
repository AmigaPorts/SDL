---
title: Rasterizing a Glyph
manual: amiga-mail
chapter: amiga-mail
section: rasterizing-a-glyph
functions: []
libraries: []
---

# Rasterizing a Glyph

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Once an application has set up the scaling engine, obtaining a glyph
is a matter of asking for it.  As was mentioned earlier, the
ObtainInfoA()/ObtainInfo() function queries a scaling engine for
glyph information.  This function accepts a pointer to a GlyphEngine
structure and a tag list.  To ask for a rasterization of a glyph,
pass ObtainInfo() the OT_GlyphMap tag.  The engine expects the
OT_GlyphMap value to be an address where it can place the address of
a GlyphMap structure.  The GlyphMap structure (defined in
<diskfont/glyph.h>) is for reading only and looks like this:

struct GlyphMap {
```c
    UWORD  glm_BMModulo;    /* # of bytes in row: always multiple of 4 */
    UWORD  glm_BMRows;      /* # of rows in bitmap */
    UWORD  glm_BlackLeft;   /* # of blank pixel columns at left of */
                            /* glyph */
    UWORD  glm_BlackTop;    /* # of blank rows at top of glyph */
    UWORD  glm_BlackWidth;  /* span of non-blank columns (horizontal */
                            /* span of the glyph) */
    UWORD  glm_BlackHeight; /* span of non-blank rows (vertical span of */
                            /* the glyph) */
    FIXED  glm_XOrigin;     /* distance from upper left corner of */
                            /* bitmap to lower */
    FIXED  glm_YOrigin;     /* left of glyph (baseline), in fractional */
                            /* pixels */
    WORD   glm_X0;          /* approximation of XOrigin in whole pixels */
    WORD   glm_Y0;          /* approximation of YOrigin in whole pixels */
    WORD   glm_X1;          /* approximation of XOrigin + Width */
    WORD   glm_Y1;          /* approximation of YOrigin + Width */
    FIXED  glm_Width;       /* character advance, as fraction of em */
                            /* width */
    UBYTE *glm_BitMap;      /* actual glyph bitmap */
```
};

The glm_BitMap field points to a single bitplane bitmap of the glyph.
This bitmap is not necessarily in Chip RAM, so if an application
needs to use the blitter to render the glyph, it has to copy the
bitmap to a Chip RAM buffer.  The fields glm_BMModulo and glm_BMRows
are the dimensions of the whole bitmap.  The glyph itself does not
occupy the entire bitmap area.  The fields glm_BlackLeft,
glm_BlackTop, glm_BlackWidth, and glm_BlackHeight describe the
position and dimension of the glyph within the bitmap.  The fields
glm_XOrigin and glm_YOrigin are the X and Y offsets from the bitmap's
upper left corner to the glyph's lower left corner.  The lower left
corner lies on the glyph's baseline.  These X and Y offsets are in
fractional pixels.  The fields glm_X0 and glm_Y0 are rounded versions
of glm_XOrigin and glm_YOrigin, respectively.

The glm_Width field is a measure of the width of the glyph in
fractions of an em (pronounced like the letter 'M').  This value is a
fixed point binary fraction.  The em is a relative measurement.  A
distance of one em is equal to the point size of the typeface.  For
example, in a 36 point typeface, one em equals 36 points which is
approximately equal to a half inch.  For a 72 point typeface, one em
equals 72 points which is approximately equal to one inch.

When an application is finished with the GlyphMap structure, it must
use the ReleaseInfoA() or ReleaseInfo() function to relinquish the
GlyphMap structure.  This function uses the same format as
ObtainInfoA()/ObtainInfo(), except the data value of the OT_GlyphMap
tag is a pointer to the GlyphMap structure (rather than a pointer to
a pointer).

