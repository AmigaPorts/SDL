---
title: CHDF    (0x43484446)    / Character definition /
manual: amiga-mail
chapter: amiga-mail
section: chdf-0x43484446-character-definition
functions: []
libraries: []
---

# CHDF    (0x43484446)    / Character definition /

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chunk defines the shape of ProVector's outline fonts.


```c
    struct CHDFstruct {
        short   Ch;         /* The character we're defining (ASCII) */
        short   NumPoints;  /* The number of points in the definition */
        IEEE    XWidth,     /* Position for next char on baseline - X */
                YWidth;     /* Position for next char on baseline - Y */
     /* IEEE    Points[2*NumPoints]*/       /* The actual points */
    };


    #define INDICATOR   0xFFFFFFFF  /* If X == INDICATOR, Y is an action */
    #define IND_SPLINE  0x00000001  /* Next 4 pts are spline control pts */
    #define IND_MOVETO  0x00000002     /* Start new subpoly */
    #define IND_STROKE  0x00000004  /* Stroke previous path */
    #define IND_FILL    0x00000008  /* Fill previous path */
```
Ch is the value (normally ASCII) of the character outline this chunk
defines.  Like Ch1 and Ch2 in the KERN chunk, Ch is stored as a 16-bit
value.  (XWidth,YWidth) is the offset to the baseline for the
following character.  OFNT outlines are defined using the same method
used to define DR2D's polygons (see the description of OPLY/CPLY for
details).

Because the OFNT FORM does not have an ATTR chunk, it needed an
alternative to make fills and strokes possible.  There are two extra
bits used in font indicator points not found in polygon indicator
points, the IND_STROKE and IND_FILL bits (see defines above).  These
two defines describe how to render the current path when rendering
fonts.

The current path remains invisible until the path is either filled
and/or stroked.  When the IND_FILL bit is set, the currently defined
path is filled in with the current fill pattern (as specified in the
current ATTR chunk).  A set IND_STROKE bit indicates that the
currently defined path itself should be rendered.  The current ATTR's
chunk dictates the width of the line, as well as several other
attributes of the line.  These two bits apply only to the OFNT FORM
and should not be used in describing DR2D polygons.

