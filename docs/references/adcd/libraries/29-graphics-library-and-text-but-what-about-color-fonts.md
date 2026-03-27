---
title: 29 Graphics Library and Text / But What About Color Fonts?
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-but-what-about-color-fonts
functions: []
libraries: []
---

# 29 Graphics Library and Text / But What About Color Fonts?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When the Amiga loads a color font, it has to account for more information
than will fit into the [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structures.  For color fonts, the Amiga
uses a superset of the TextFont structure called the ColorTextFont
structure (defined in <graphics/[text.h](autodocs-2.0/includes-graphics-text-h.md)>):


```c
    struct ColorTextFont {
        struct TextFont ctf_TF;
        UWORD ctf_Flags;      /* extended flags */
        UBYTE ctf_Depth;      /* number of bit planes */
        UBYTE ctf_FgColor;    /* color that is remapped to FgPen */
        UBYTE ctf_Low;        /* lowest color represented here */
        UBYTE ctf_High;       /* highest color represented here */
        UBYTE ctf_PlanePick;      /* PlanePick ala Images */
        UBYTE ctf_PlaneOnOff;     /* PlaneOnOff ala Images */
        struct ColorFontColors *ctf_ColorFontColors; /* colors for font */
        APTR ctf_CharData[8]; /* pointers to bit planes ala tf_CharData */
    };
```
The ctf_TF field is the [TextFont](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) structure described in the previous
section.  There are two minor differences between the data stored in a
color font's TextFont structure and an ordinary TextFont structure.  The
first is that the color font's [TextFont.tf_Style](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) field has the
FSF_COLORFONT bit set.  The other difference is that the bitmap that
[TextFont.tf_CharData](libraries/29-graphics-library-and-text-how-an-amiga-font-structured.md) points to can be a multi-plane bitmap.

The ctf_Flags field is a bitfield that supports the following flags:

CT_COLORFONT  The color map for this font contains colors specified by the

              designer.
CT_GREYFONT   The colors for this font describe evenly stepped gray shades

              from low to high.
The ctf_Depth field contains the bitplane depth of this font's bitmap.

The ctf_FgColor contains the color that will be dynamically remapped
during output by changing ctf_FgColor to [RastPort.FgPen](libraries/27-the-rastport-structure-rastport-drawing-pens.md).  This field
allows a ColorTextFont to contain color outlines, shadows, etc. while also
containing a predominant color that can be changed by the user.  If the
font does not have a predominant color, ctf_FgColor is 0xFF.  For example,
given a color font that has a blue and red outline and a white center, the
person designing the font can set ctf_FgColor equal to white.  Then when
the font is used in a paint package that supports color fonts, the white
will change to the current foreground color.

The fields ctf_Low and ctf_High contain the lowest and highest color
values in the ColorTextFont.  For example, a four bitplane color font can
have sixteen colors, but the font may use only nine of those colors, thus
ctf_Low=0 and ctf_High=8.  The most important use of these colors is for
defining the boundaries of a gray scale font.  If the font uses less than
the total number of colors around but needs white as the lowest and black
as the highest level of gray, the boundaries would have to be defined in
order for the font to be rendered correctly.  Defaults for these values
should be the lowest and the highest values for the given number of
bitplanes.

The ctf_PlanePick and ctf_PlaneOnOff contain information for saving space
in memory for some types of ColorTextFont structures.  The ctf_PlanePick
field contains information about where each plane of data will be rendered
in a given bitmap.  The ctf_PlaneOnOff field contains information about
planes that are not used to render a plane of font data.  If
ctf_PlaneOnOff contains a zero bit for a given plane, that bitplane is
cleared.  If ctf_PlaneOnOff contains a set bit for a given plane, that
bitplane is filled.  For more information on how the ctf_PlaneOnOff and
ctf_PlanePick fields work see the "[Specifying the Colors of a Bob](libraries/28-using-bobs-specifying-the-colors-of-a-bob.md)" section
of the "Graphics Sprites, Bobs and Animation" chapter of this book.

The ctf_ColorFontColors field contains a pointer to a [ColorFontColors](autodocs-2.0/includes-graphics-text-h.md)
structure:


```c
    struct ColorFontColors {
        UWORD   cfc_Reserved;   /* *must* be zero */
        UWORD   cfc_Count;      /* number of entries in cfc_ColorTable */
        UWORD  *cfc_ColorTable;
                          /* 4 bit per component color map packed xRGB */
    };
```
Which specifies the colors used by this font.  The ColorFontColors
cfc_Count field contains the number of colors defined in this structure.
Each color is defined as a single, UWORD entry in the cfc_ColorTable.  For
each entry in cfc_ColorTable, the lowest four bits make up the blue
element, the next four bits the green element, the next four bits the red
element, and the upper four bits should be masked out.

The ctf_CharData[] fields is an array of pointers to each of the bitplanes
of the color font data.

