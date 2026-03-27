---
title: 30 / Regions / Creating and Deleting Regions
manual: libraries
chapter: libraries
section: 30-regions-creating-and-deleting-regions
functions: [DisposeRegion, NewRegion]
libraries: [graphics.library]
---

# 30 / Regions / Creating and Deleting Regions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You allocate a [Region](autodocs-2.0/includes-graphics-regions-h.md) data structure with the [NewRegion()](autodocs-2.0/graphics-library-newregion.md) call.


```c
    struct Region *NewRegion( void );
```
The [NewRegion()](autodocs-2.0/graphics-library-newregion.md) function allocates and initializes a [Region](autodocs-2.0/includes-graphics-regions-h.md) structure that
has no drawable areas defined in it.  If the application draws through a
new region, nothing will be drawn as the region is empty.  The application
must add rectangles to the region before any graphics will appear.

Use [DisposeRegion()](autodocs-2.0/graphics-library-disposeregion.md) to free the [Region](autodocs-2.0/includes-graphics-regions-h.md) structure when you are done with it.


```c
    void DisposeRegion( struct Region *region );
```
[DisposeRegion()](autodocs-2.0/graphics-library-disposeregion.md) returns all memory associated with a region to the system
and deallocates all rectangles that have been linked to it.


```c
    Don't Forget to Free Your Rectangles.
    -------------------------------------
    All of the functions that add rectangles to the region make copies
    of the rectangles.  If the program allocates a rectangle, then adds
    it to a region, it still must deallocate the rectangle.  The call to
    [DisposeRegion()](autodocs-2.0/graphics-library-disposeregion.md) will not deallocate rectangles explicitly
    allocated by the application.
```

---

## See Also

- [DisposeRegion — graphics.library](../autodocs/graphics.library.md#disposeregion)
- [NewRegion — graphics.library](../autodocs/graphics.library.md#newregion)
