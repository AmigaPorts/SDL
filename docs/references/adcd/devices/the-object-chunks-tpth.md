---
title: The Object Chunks / TPTH
manual: devices
chapter: devices
section: the-object-chunks-tpth
functions: []
libraries: []
---

# The Object Chunks / TPTH

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

TPTH (0x54505448) 		/* A text string along a path */

This chunk defines a path (polygon) and supplies a string to render along
the edge of the path.


```c
    struct TPTHstruct {
        ULONG   ID;
        ULONG   Size;
        UBYTE   Justification;      /* see defines, below */
        UBYTE   WhichFont;          /* Which font to use */
        IEEE    CharW, CharH;       /* W/H of an individual char    */
        USHORT  NumChars;           /* Number of chars in the string */
        USHORT  NumPoints;          /* Number of points in the path */
        char    TextChars[NumChars];/* PAD TO EVEN #! */
        IEEE    Path[2*NumPoints];  /* The path on which the text lies */
    };
```
WhichFont contains the ID of the font used to render the text.
Justification controls how the text is justified on the line.
Justification can be one of the following values:


    #define J_LEFT          0x00    /* Left justified */
    #define J_RIGHT         0x01    /* Right justified */
    #define J_CENTER        0x02    /* Center text */
    #define J_SPREAD        0x03    /* Spread text across path */
CharW and CharH are the average width and height of the font characters
and are akin to X and Y font sizes, respectively.  A negative FontH
implies that the font is upsidedown.  Note that CharW must not be
negative.  NumChars is the number of characters in the TextChars[] string,
the string containing the text to be rendered. NumPoints is the number of
points in the Path[] array.  Path[] is the path along which the text is
rendered.  The path itself is not rendered.  The points of Path[] are in
the same format as the points of a DR2D polygon.

