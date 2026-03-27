/* Source: ADCD 2.1
 * Section: 29-graphics-library-and-text-does-the-text-fit
 * Library: libraries
 * ADCD reference: libraries/29-graphics-library-and-text-does-the-text-fit.md
 */

    te_Width        the same value returned by [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html).

    te_Height       the font's Y size.

    te_Extent.MinX  the pixel offset from the rastport's current X position
                    to the left side of the bounding box defined by the
                    rectangle structure.  Normally, this is zero.

    te_Extent.MinY  the distance in pixels from the baseline to the top of
                    the bounding box.

    te_Extent.MaxX  the pixel offset from the rastport's current X position
                    to the right side of the bounding box.  Normally, this
                    is te_Width - 1.

    te_Extent.MaxY  the distance from the baseline to the bottom of the
                    bounding box.
