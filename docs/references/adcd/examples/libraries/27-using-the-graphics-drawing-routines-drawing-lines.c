/* Source: ADCD 2.1
 * Section: 27-using-the-graphics-drawing-routines-drawing-lines
 * Library: libraries
 * ADCD reference: libraries/27-using-the-graphics-drawing-routines-drawing-lines.md
 */

    SetAPen(&rastPort, COLOR1);    /* Set A pen color. */
    Move(&rastPort, 0, 0);    /* Move to this location. */
    Draw(&rastPort, 100,50);    /* Draw to a this location. */


    Caution:
    --------
    If you attempt to draw a line outside the bounds of the [BitMap](../Libraries_Manual_guide/node032B.html#line74),
    using the basic initialized [RastPort](../Libraries_Manual_guide/node034A.html), you may crash the system.
    You must either do your own software clipping to assure that the line
    is in range, or use the layers library. Software clipping means that
    you need to determine if the line will fall outside your BitMap
    before you draw it, and render only the part which falls inside
    the BitMap.
