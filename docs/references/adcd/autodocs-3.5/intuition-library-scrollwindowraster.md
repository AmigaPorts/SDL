---
title: intuition.library/ScrollWindowRaster
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-scrollwindowraster
functions: [EraseRect, ScrollRaster, ScrollRasterBF, ScrollWindowRaster]
libraries: [graphics.library, intuition.library]
---

# intuition.library/ScrollWindowRaster

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
        ScrollWindowRaster -- Intuition-friendly [ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md) (V39)
```
   SYNOPSIS

```c
        ScrollWindowRaster(win, dx, dy, xmin, ymin, xmax, ymax)
                           A1   D0  D1  D2    D3    D4    D5

        void ScrollWindowRaster(struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, WORD, WORD,
            WORD, WORD, WORD, WORD);
```
   FUNCTION

```c
        Calls [graphics.library/ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md), which moves
        the bits in the raster by (dx,dy) towards (0,0)
        The space vacated is filled by calling [EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md).
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
        to [ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md) and [ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md).
```
   INPUTS

```c
        win - pointer to a [Window](autodocs-3.5/include-intuition-intuition-h.md) structure
        dx,dy are integers that may be postive, zero, or negative
        xmin,ymin - upper left of bounding rectangle
        xmax,ymax - lower right of bounding rectangle
```
   NOTES

```c
        This call uses [ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md), which calls [EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md)
        when clearing the newly exposed area. This allows use of
        a custom layer backfill hook.

        IMPORTANT:  boopsi gadgets should use [ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md) or
        [ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md) directly!  Never call ScrollWindowRaster()
        from inside a boopsi gadget's method handler.  Note that
        Intuition will detect and handle damage caused by such use
        of [ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md) or [ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md), for gadgets with
        the GMORE_SCROLLRASTER property.

        VERY IMPORTANT:  if you have any gadgets in your simple-refresh
        window with the GMORE_SCROLLRASTER property, you must use
        ScrollWindowRaster() instead of [ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md) or [ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md).
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
        ScrollWindowRaster() and [ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md).
```
   SEE ALSO

```c
        [graphics.library/ScrollRaster()](autodocs-3.5/graphics-library-scrollraster-2.md), [graphics.library/ScrollRasterBF()](autodocs-3.5/graphics-library-scrollrasterbf.md)
        [graphics.library/EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md), WA_BackFill
```

---

## See Also

- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
- [ScrollRaster — graphics.library](../autodocs/graphics.library.md#scrollraster)
- [ScrollRasterBF — graphics.library](../autodocs/graphics.library.md#scrollrasterbf)
- [ScrollWindowRaster — intuition.library](../autodocs/intuition.library.md#scrollwindowraster)
