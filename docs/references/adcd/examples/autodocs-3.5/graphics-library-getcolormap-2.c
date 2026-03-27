/* Source: ADCD 2.1
 * Section: graphics-library-getcolormap-2
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/graphics-library-getcolormap-2.md
 */

       Allocates, initializes and returns a pointer to a [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142)
       data structure, later enabling calls to [SetRGB4/SetRGB32](../Includes_and_Autodocs_3._guide/node0328.html)
       and [LoadRGB4/LoadRGB32](../Includes_and_Autodocs_3._guide/node02FB.html) to load colors for a view port. The
       ColorTable pointer in the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) structure points to a
       hardware specific colormap data structure. You should not
       count on it being anything you can understand. Use
       [GetRGB4()/GetRGB32()](../Includes_and_Autodocs_3._guide/node02E9.html) to query it or [SetRGB4CM/SetRGB32CM](../Includes_and_Autodocs_3._guide/node0329.html)
       to set it directly.
