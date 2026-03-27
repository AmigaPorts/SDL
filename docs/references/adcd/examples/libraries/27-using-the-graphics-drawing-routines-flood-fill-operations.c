/* Source: ADCD 2.1
 * Section: 27-using-the-graphics-drawing-routines-flood-fill-operations
 * Library: libraries
 * ADCD reference: libraries/27-using-the-graphics-drawing-routines-flood-fill-operations.md
 */

    BYTE oldAPen;
    UWORD oldDrPt;
    struct RastPort *rastPort = Window->RPort;

    /* Save the old values of the foreground pen and draw pattern. */
    oldAPen = rastPort->FgPen;
    oldDrPt = rastPort->LinePtrn;

    /* Use AreaOutline pen color for foreground pen. */
    SetAPen(rastPort, rastPort->AOlPen);
    SetDrPt(rastPort, ~0);      /* Insure a solid draw pattern. */

    Move(rastPort, 0, 0);  /* Using mode 0 to create a triangular shape */
    Draw(rastPort, 0, 100);
    Draw(rastPort, 100, 100);
    Draw(rastPort, 0, 0);       /* close it */

    SetAPen(rastPort, oldAPen); /* Restore original foreground pen. */
    Flood(rastPort, 0, 10, 50); /* Start Flood() inside triangle. */

    SetDrPt(rastPort, oldDrPt); /* Restore original draw mode. */
