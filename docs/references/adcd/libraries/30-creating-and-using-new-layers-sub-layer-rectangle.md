---
title: 30 / / Creating and Using New Layers / Sub-Layer Rectangle Operations
manual: libraries
chapter: libraries
section: 30-creating-and-using-new-layers-sub-layer-rectangle
functions: [CreateUpfrontLayer, SwapBitsRastPortClipRect]
libraries: [layers.library]
---

# 30 / / Creating and Using New Layers / Sub-Layer Rectangle Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [SwapBitsRastPortClipRect()](autodocs-2.0/layers-library-swapbitsrastportcliprect.md) routine is for applications that do not
want to worry about clipping rectangles.


```c
    void SwapBitsRastPortClipRect( struct RastPort *rp,
                                   struct ClipRect *cr );
```
For instance, you may use The [SwapBitsRastPortClipRect()](autodocs-2.0/layers-library-swapbitsrastportcliprect.md) to produce a menu
without using Intuition.  There are two ways to produce such a menu:

 1. Create an up-front layer with [CreateUpfrontLayer()](libraries/30-layers-creating-and-using-new-layers.md), then render the

```c
    menu in it.  This could use lots of memory and require a lot of (very
    temporary) "slice-and-dice" operations to create all of the clipping
    rectangles for the existing windows and so on.
```
 2. Use [SwapBitsRastPortClipRect()](autodocs-2.0/layers-library-swapbitsrastportcliprect.md), directly on the display drawing area:


      * Render the menu in a back-up area off the display, then lock all
        of the on-display layers so that no task may use graphics
        routines to draw over the menu area on the display.

      * Next, swap the on-display bits with the off-display bits, making
        the menu appear.

      * When finished with the menu, swap again and unlock the layers.
The second method is faster and leaves the clipping rectangles and most of
the rest of the window data structures untouched.


    Warning:
    --------
    All of the layers must be locked while the menu is visible if you
    use the second method above.  Any task that is using any of the
    layers for graphics output will be halted while the menu operations
    are taking place.  If, on the other hand, the menu is rendered as a
    layer, no task need be halted while the menu is up because the lower
    layers need not be locked.

---

## See Also

- [CreateUpfrontLayer — layers.library](../autodocs/layers.library.md#createupfrontlayer)
- [SwapBitsRastPortClipRect — layers.library](../autodocs/layers.library.md#swapbitsrastportcliprect)
