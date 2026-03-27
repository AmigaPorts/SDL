---
title: The Global Drawing Attribute Chunks / AROW
manual: devices
chapter: devices
section: the-global-drawing-attribute-chunks-arow
functions: []
libraries: []
---

# The Global Drawing Attribute Chunks / AROW

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

AROW (0x41524F57)   	/* An arrow-head pattern */

The AROW chunk describes an arrowhead pattern.  DR2D open polygons (OPLY)
can have arrowheads attached to their endpoints.  See the description of
the OPLY chunk later in this article for more information on the OPLY
chunk.


```c
    #define ARROW_FIRST  0x01 /* Draw an arrow on the OPLY's first point */
    #define ARROW_LAST   0x02 /* Draw an arrow on the OPLY's last point */

    struct AROWstruct {
        ULONG       ID;
        ULONG       Size;
        UBYTE       Flags;          /* Flags, from ARROW_*, above */
        UBYTE       Pad0;           /* Should always 0 */
        USHORT      ArrowID;        /* Name of the arrow head */
        USHORT      NumPoints;
        IEEE        ArrowPoints[NumPoints*2];
    };
```
The Flags field specifies which end(s) of an OPLY to place an arrowhead
based on the #defines above.  ArrowID is the number by which an OPLY will
reference this arrowhead pattern.

The coordinates in the array ArrowPoints[] define the arrowhead's shape.
These points form a closed polygon.  See the section on the OPLY/CPLY
object chunks for a descriptionof how DR2D defines shapes. The arrowhead
is drawn in the same coordinate system relative to the endpoint of the
OPLY the arrowhead is attached to.  The arrowhead's origin (0,0) coincides
with the OPLY's endpoint.  DR2D assumes that the arrowhead represented in
the AROW chunk is pointing to the right so the proper rotation can be
applied to the arrowhead.  The arrow is filled according to the current
fill pattern set in the ATTR object attribute chunk.

