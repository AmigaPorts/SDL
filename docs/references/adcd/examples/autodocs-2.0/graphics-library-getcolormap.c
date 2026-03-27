/* Source: ADCD 2.1
 * Section: graphics-library-getcolormap
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-getcolormap.md
 */

    Allocates, initializes and returns a pointer to a [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113)
    data structure, later enabling calls to [SetRGB4](../Includes_and_Autodocs_2._guide/node047C.html)
    and [LoadRGB4](../Includes_and_Autodocs_2._guide/node0458.html) to load colors for a view port. The ColorTable
    pointer in the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) structure points to a hardware
    specific colormap data structure. You should not count on
    it being anything you can understand. Use [GetRGB4()](../Includes_and_Autodocs_2._guide/node0448.html) to
    query it or [SetRGB4CM](../Includes_and_Autodocs_2._guide/node047D.html) to set it directly.
