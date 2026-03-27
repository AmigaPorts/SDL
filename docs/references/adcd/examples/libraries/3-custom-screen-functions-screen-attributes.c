/* Source: ADCD 2.1
 * Section: 3-custom-screen-functions-screen-attributes
 * Library: libraries
 * ADCD reference: libraries/3-custom-screen-functions-screen-attributes.md
 */

    Initialize color table to entire preferences palette (32 colors
    beginning with V36), rather than the subset from V34 and earlier,
    namely pens 0-3, 17-19, with remaining palette as returned by
    [GetColorMap()](../Libraries_Manual_guide/node0331.html).  Data is a boolean value (use TRUE to set the flag).
    Defaults to FALSE.
