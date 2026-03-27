---
title: CPLY (0x43504C59) and OPLY (0x4F504C59)
manual: amiga-mail
chapter: amiga-mail
section: cply-0x43504c59-and-oply-0x4f504c59
functions: []
libraries: []
---

# CPLY (0x43504C59) and OPLY (0x4F504C59)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Polygons are the basic components of almost all 2D objects in the DR2D
FORM.  Lines, squares, circles, and arcs are all examples of DR2D
polygons.  There are two types of DR2D polygons, the open polygon
(OPLY) and the closed polygon (CPLY).  The difference between a closed
and open polygon is that the computer adds a line segment connecting
the endpoints of a closed polygon so that it is a continuous path.  An
open polygon's endpoints do not have to meet, like the endpoints of a
line segment.


```c
    struct POLYstruct {
        ULONG       ID;
        ULONG       Size;
        USHORT      NumPoints;
        IEEE        PolyPoints[2*NumPoints];
    };
```
The NumPoints field contains the number of points in the polygon and
the PolyPoints array contains the (X, Y) coordinates of the points of
the non-curved parts of polygons.  The even index elements are X
coordinates and the odd index elements are Y coordinates.

   [Figure 3 - Bezier curves](amiga-mail/vii-1-dr2d-3-pic.md) 

DR2D uses Bezier cubic sections, or cubic splines, to describe curves
in polygons.  A set of four coordinates (P1 through P4) defines the
shape of a cubic spline.  The first coordinate (P1) is the point where
the curve begins.  The line from the first to the second coordinate
(P1 to P2) is tangent to the curve at the first point.  The line from
P3 to P4 is tangent to the cubic section, where it ends at P4.

The coordinates describing the cubic section are stored in the
PolyPoints[] array with the coordinates of the normal points.  DR2D
inserts an indicator point before a set of cubic section points to
differentiate a normal point from the points that describe a curve.
An indicator point has an X value of 0xFFFFFFFF.  The indicator
point's Y value is a bit field.  If this bit field's low-order bit is
set, the points that follow the indicator point make up a cubic
section.

The second lowest order bit in the indicator point's bit field is the
MOVETO flag.  If this bit is set, the point (or set of cubic section
points) starts a new polygon, or subpolygon.  This subpolygon will
appear to be completely separate from other polygons but there is an
important connection between a polygon and its subpolygon.
Subpolygons make it possible to create holes in polygons.  An example
of a polygon with a hole is the letter "O".  The "O" is a filled
circular polygon with a smaller circular polygon within it.  The
reason the inner polygon isn't covered up when the outer polygon is
filled is that DR2D fills are done using the even-odd rule.

The even-odd rule determines if a point is "inside" a polygon by
drawing a ray outward from that point and counting the number of path
segments the ray crosses.  If the number is even, the point is outside
the object and shouldn't be filled.  Conversely, an odd number of
crossings means the point is inside and should be filled.  DR2D only
applies the even-odd rule to a polygon and its subpolygons, so no
other objects are considered in the calculations.

Taliesin, Inc. supplied the following algorithm to illustrate the
format of DR2D polygons.  OPLYs, CPLYs, AROWs, and ProVector's outline
fonts all use the same format:



```c
    typedef union {
        IEEE num;
        LONG bits;
    } Coord;

    #define INDICATOR       0xFFFFFFFF
    #define IND_SPLINE      0x00000001
    #define IND_MOVETO      0x00000002

    /* A common pitfall in attempts to support DR2D has
            been to fail to recognize the case when an
            INDICATOR point indicates the following
            coordinate to be the first point of BOTH a
            Bezier cubic and a sub-polygon, ie. the
            value of the flag = (IND_CURVE | IND_MOVETO) */

    Coord   Temp0, Temp1;
    int     FirstPoint, i, Increment;

    /* Initialize the path */
    NewPath();
    FirstPoint = 1;

    /* Draw the path */
    i = 0;
    while( i < NumPoints ) {
        Temp0.num = PolyPoints[2*i];    Temp1.num = PolyPoints[2*i + 1];
        if( Temp0.bits == INDICATOR ) {
            /* Increment past the indicator */
            Increment = 1;
            if( Temp1.bits & IND_MOVETO ) {
                /* Close and fill, if appropriate */
                if( ID == CPLY ) {
                    FillPath();
                }
                else {
                    StrokePath();
                }

                /* Set up the new path */
                NewPath();
                FirstPoint = 1;
            }
            if( Temp1.bits & IND_CURVE ) {
                /* The next 4 points are Bezier cubic control points */
                if( FirstPoint )
                    MoveTo( PolyPoints[2*i + 2], PolyPoints[2*i + 3] );
                else
                    LineTo( PolyPoints[2*i + 2], PolyPoints[2*i + 3] );
                CurveTo(    PolyPoints[2*i + 4], PolyPoints[2*i + 5],
                            PolyPoints[2*i + 6], PolyPoints[2*i + 7],
                            PolyPoints[2*i + 8], PolyPoints[2*i + 9] );
                FirstPoint = 0;
                /* Increment past the control points */
                Increment += 4;
            }
        }
        else {
            if( FirstPoint )
                MoveTo(     PolyPoints[2*i], PolyPoints[2*i + 1] );
            else
                LineTo(     PolyPoints[2*i], PolyPoints[2*i + 1] );
            FirstPoint = 0;

            /* Increment past the last endpoint */
            Increment = 1;
        }

        /* Add the increment */
        i += Increment;
    }

    /* Close the last path */
    if( ID == CPLY ) {
        FillPath();
    }
    else {
        StrokePath();
    }
```
