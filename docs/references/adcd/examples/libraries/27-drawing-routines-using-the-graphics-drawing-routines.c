/* Source: ADCD 2.1
 * Section: 27-drawing-routines-using-the-graphics-drawing-routines
 * Library: libraries
 * ADCD reference: libraries/27-drawing-routines-using-the-graphics-drawing-routines.md
 */

    struct Window *window;
    struct RastPort *rastPort;

    window = OpenWindow(&newWindow);  /*  You could use OpenWindowTags() */
    if (window)
        rastPort = window->RPort;
