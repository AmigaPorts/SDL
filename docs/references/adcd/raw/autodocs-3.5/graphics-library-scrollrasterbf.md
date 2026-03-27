# graphics.library/ScrollRasterBF



   NAME
   ScrollRasterBF -- Push bits in rectangle in raster around by
                   dx,dy towards 0,0 inside rectangle. Newly empty areas
   		will be filled via [EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html). (V39)

   SYNOPSIS
   ScrollRasterBF(rp, dx, dy, xmin, ymin, xmax, ymax)

                A1  D0  D1  D2    D3    D4    D5
   void ScrollRasterBF

```c
        (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD, WORD, WORD, WORD, WORD);
```
   FUNCTION
   [Move](../Includes_and_Autodocs_3._guide/node0301.html) the bits in the raster by (dx,dy) towards (0,0)
   The space vacated is filled by calling EraseRect().
   Limit the scroll operation to the rectangle defined
   by (xmin,ymin)(xmax,ymax). Bits outside will not be
   affected. If xmax,ymax is outside the rastport then use
   the lower right corner of the rastport.
   If you are dealing with a SimpleRefresh layered [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) you
   should check rp->Layer->Flags & LAYERREFRESH to see if
   there is any damage in the damage list.  If there is you should
   call the appropriate BeginRefresh(Intuition) or BeginUpdate(graphics)
   routine sequence.

   INPUTS
   rp - pointer to a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure
   dx,dy are integers that may be positive, zero, or negative
   xmin,ymin - upper left of bounding rectangle
   xmax,ymax - lower right of bounding rectangle

   NOTES

   This call is exactly the same as [ScrollRaster](../Includes_and_Autodocs_3._guide/node031A.html), except that it calls
   [EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html) instead of [RectFill()](../Includes_and_Autodocs_3._guide/node0313.html) when clearing the newly exposed
   area. This allows use of a custom layer backfill hook.

   BUGS

   SEE ALSO
   [ScrollRaster()](../Includes_and_Autodocs_3._guide/node031A.html) [EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html) [intuition.library/ScrollWindowRaster()](../Includes_and_Autodocs_3._guide/node03EC.html) 
   graphics/rastport.h

