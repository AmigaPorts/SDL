# intuition.library/ScrollWindowRaster



   NAME

```c
        ScrollWindowRaster -- Intuition-friendly [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html) (V39)
```
   SYNOPSIS

```c
        ScrollWindowRaster(win, dx, dy, xmin, ymin, xmax, ymax)
                           A1   D0  D1  D2    D3    D4    D5

        void ScrollWindowRaster(struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, WORD, WORD,
            WORD, WORD, WORD, WORD);
```
   FUNCTION

```c
        Calls [graphics.library/ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html), which moves
        the bits in the raster by (dx,dy) towards (0,0)
        The space vacated is filled by calling [EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html).
        NOTE: that vacated space is _not_ considered damage!
        The scroll operation is limited to the rectangle defined
        by (xmin,ymin)-(xmax,ymax). Bits outside will not be
        affected. If (xmax,ymax) is outside the rastport then use
        the lower right corner of the rastport.

        If a window is partly obscured, then it is possible for
        ScrollWindowRaster() to scroll some of the obscured
        area into view.  If the window is simple-refresh, then
        the formerly obscured area is damage, and the application
        needs to repair it.  If Intuition detects damage as a result
        of ScrollWindowRaster(), it will send an IDCMP_REFRESHWINDOW
        event to the application's window.  This handling of damage
        is the principal reason ScrollWindowRaster() is preferred
        to [ScrollRaster()](../Includes_and_Autodocs_3._guide/node031A.html) and [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html).
```
   INPUTS

```c
        win - pointer to a [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) structure
        dx,dy are integers that may be postive, zero, or negative
        xmin,ymin - upper left of bounding rectangle
        xmax,ymax - lower right of bounding rectangle
```
   NOTES

```c
        This call uses [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html), which calls [EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html)
        when clearing the newly exposed area. This allows use of
        a custom layer backfill hook.

        IMPORTANT:  boopsi gadgets should use [ScrollRaster()](../Includes_and_Autodocs_3._guide/node031A.html) or
        [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html) directly!  Never call ScrollWindowRaster()
        from inside a boopsi gadget's method handler.  Note that
        Intuition will detect and handle damage caused by such use
        of [ScrollRaster()](../Includes_and_Autodocs_3._guide/node031A.html) or [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html), for gadgets with
        the GMORE_SCROLLRASTER property.

        VERY IMPORTANT:  if you have any gadgets in your simple-refresh
        window with the GMORE_SCROLLRASTER property, you must use
        ScrollWindowRaster() instead of [ScrollRaster()](../Includes_and_Autodocs_3._guide/node031A.html) or [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html).
        Handling of gadget scroll damage is incompatible with continued
        use of these graphics functions in an Intuition window.
        NB:  If you're using a gadget class whose source code you do
        not control, that class might be using GMORE_SCROLLRASTER or
        might start to in a future version.  For that reason, you
        should use ScrollWindowRaster() if you are using any such gadgets.
```
   BUGS

```c
        In intuition.library V39 and V40 ScrollWindowRaster() must
        be considered unsafe in connection with gadget event handling
        and windows which do not have the WA_NoCareRefresh attribute set.
        A race condition may occur which will cause write accesses
        to unallocated memory and keep the IDCMP_REFRESHWINDOW message
        from getting delivered.

        The recommended workaround for this problem is to use
        ScrollWindowRaster() only in SMART_REFRESH windows which have
        the WA_NoCareRefresh attribute set. Of course, which such
        windows there will be no difference in functionality between
        ScrollWindowRaster() and [ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html).
```
   SEE ALSO

```c
        [graphics.library/ScrollRaster()](../Includes_and_Autodocs_3._guide/node031A.html), [graphics.library/ScrollRasterBF()](../Includes_and_Autodocs_3._guide/node031B.html)
        [graphics.library/EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html), WA_BackFill
```
