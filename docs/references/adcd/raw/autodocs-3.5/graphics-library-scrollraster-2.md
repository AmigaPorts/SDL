# graphics.library/ScrollRaster



   NAME
   ScrollRaster -- Push bits in rectangle in raster around by
                   dx,dy towards 0,0 inside rectangle.
   SYNOPSIS
   ScrollRaster(rp, dx, dy, xmin, ymin, xmax, ymax)

                A1  D0  D1  D2    D3    D4    D5
   void ScrollRaster

```c
        (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD, WORD, WORD, WORD, WORD);
```
   FUNCTION
   [Move](../Includes_and_Autodocs_3._guide/node0301.html) the bits in the raster by (dx,dy) towards (0,0)
   The space vacated is RectFilled with BGPen.
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

   EXAMPLE
   ScrollRaster(rp,0,1,minx,miny,maxx,maxy) /* shift raster up by one row */
   ScrollRaster(rp,-1,-1,minx,miny,maxx,maxy)
		  /* shift raster down and to the right by 1 pixel

   BUGS
   In 1.2/V1.3 if you ScrollRaster a SUPERBITMAP exactly left or 
   right, and there is no [TmpRas](../Includes_and_Autodocs_3._guide/node05D7.html#line31) attached to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53), the system
   will allocate one for you, but will never free it or record its 
   location. This bug has been fixed for V36.  The workaround for
   1.2/1.3 is to attach a valid [TmpRas](../Includes_and_Autodocs_3._guide/node05D7.html#line31) of size at least
   MAXBYTESPERROW to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) before the call.

   Beginning with V36 ScrollRaster adds the shifted areas into the 
   damage list for SIMPLE_REFRESH windows. Due to unacceptable 
   system overhead, the decision was made NOT to propagate this 
   shifted area damage for SMART_REFRESH windows.

   SEE ALSO
   [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html) graphics/rastport.h

