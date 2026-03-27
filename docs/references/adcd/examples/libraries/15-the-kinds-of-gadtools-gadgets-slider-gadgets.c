/* Source: ADCD 2.1
 * Section: 15-the-kinds-of-gadtools-gadgets-slider-gadgets
 * Library: libraries
 * ADCD reference: libraries/15-the-kinds-of-gadtools-gadgets-slider-gadgets.md
 */

    Optional function to convert the level for display.  A slider to
    select the number of colors for a screen may operate in screen depth
    (1 to 5, for instance), but actually display the number of colors (2,
    4, 8, 16 or 32).  This may be done by providing a GTSL_DispFunc
    function which returns 1 << level.  The function must take a pointer
    to the [Gadget](../Libraries_Manual_guide/node0149.html) as the first parameter and the level, a WORD, as the
    second and return the result as a LONG.  The default behavior for
    displaying a level is to do so without any conversion.  (Create only.)
