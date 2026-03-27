---
title: The Object Attribute Chunks / ATTR
manual: devices
chapter: devices
section: the-object-attribute-chunks-attr
functions: []
libraries: []
---

# The Object Attribute Chunks / ATTR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

ATTR (0x41545452)   	/* Object attributes */

The ATTR chunk sets various attributes for the objects that follow it. The
attributes stay in effect until the next ATTR changes the attributes, or
the enclosing FORM ends, whichever comes first.


```c
    /* Various fill types */
    #define FT_NONE         0    /* No fill                 */
    #define FT_COLOR        1    /* Fill with color from palette */
    #define FT_OBJECTS      2    /* Fill with tiled objects */


    struct ATTRstruct {
        ULONG       ID;
        ULONG       Size;
        UBYTE       FillType;    /* One of FT_*, above      */
        UBYTE       JoinType;    /* One of JT_*, below      */
        UBYTE       DashPattern; /* ID of edge dash pattern */
        UBYTE       ArrowHead;   /* ID of arrowhead to use  */
        USHORT      FillValue;   /* Color or object with which to fill */
        USHORT      EdgeValue;   /* Edge color index        */
        USHORT      WhichLayer;  /* ID of layer it's in     */
        IEEE        EdgeThick;   /* Line width              */
    };
```
FillType specifies what kind of fill to use on this ATTR chunk's objects.
A value of FT_NONE means that this ATTR chunk's objects are not filled.
FT_COLOR indicates that the objects should be filled in with a color.
That color's ID (from the CMAP chunk) is stored in the FillValue field.
If FillType is equal to FT_OBJECTS, FillValue contains the ID of a fill
pattern defined in a FILL chunk.

JoinType determines which style of line join to use when connecting the
edges of line segments.  The field contains one of these four values:


    /* Join types */
    #define JT_NONE         0       /* Don't do line joins */
    #define JT_MITER        1       /* Mitered join */
    #define JT_BEVEL        2       /* Beveled join */
    #define JT_ROUND        3       /* Round join */
DashPattern and ArrowHead contain the ID of the dash pattern and arrow
head for this ATTR's objects.  A DashPattern of zero means that there is
no dash pattern so lines will be invisible.  If ArrowHead is 0, OPLYs have
no arrow head.  EdgeValue is the color of the line segments.  WhichLayer
contains the ID of the layer this ATTR's objects are in.  EdgeThick is the
width of this ATTR's line segments.

