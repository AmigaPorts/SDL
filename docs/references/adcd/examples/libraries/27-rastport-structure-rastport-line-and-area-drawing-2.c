/* Source: ADCD 2.1
 * Section: 27-rastport-structure-rastport-line-and-area-drawing
 * Library: libraries
 * ADCD reference: libraries/27-rastport-structure-rastport-line-and-area-drawing.md
 */

    SetAfPt(&rastPort, NULL, 0);


    Pattern Positioning.
    --------------------
    The pattern is always positioned with respect to the upper left
    corner of the [RastPort](../Libraries_Manual_guide/node034A.html) drawing area (the 0,0 coordinate).  If you
    draw two rectangles whose edges are adjacent, the pattern will be
    continuous across the rectangle boundaries.
