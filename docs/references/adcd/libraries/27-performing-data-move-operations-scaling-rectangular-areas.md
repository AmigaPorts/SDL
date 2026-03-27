---
title: 27 / / Performing Data Move Operations / Scaling Rectangular Areas
manual: libraries
chapter: libraries
section: 27-performing-data-move-operations-scaling-rectangular-areas
functions: [BitMapScale, ScalerDiv]
libraries: [graphics.library]
---

# 27 / / Performing Data Move Operations / Scaling Rectangular Areas

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[BitMapScale()](autodocs-2.0/graphics-library-bitmapscale.md) will scale a single bitmap any integral size up to 16,383
times its original size.  This function is available only in Release 2 and
later versions of the OS.  It is called with the address of a BitScaleArgs
structure (see <graphics/[scale.h](autodocs-2.0/includes-graphics-scale-h.md)>).


```c
    void BitMapScale(struct BitScaleArgs *bsa)
```
The bsa argument specifies the [BitMap](libraries/27-display-routines-and-structures-viewport-display-memory.md)s to use, the source and destination
rectangles, as well as the scaling factor.  The source and destination may
not overlap.  The caller must ensure that the destination BitMap is large
enough to receive the scaled-up copy of the source rectangle.  The
function [ScalerDiv()](autodocs-2.0/graphics-library-scalerdiv.md) is provided to help in the calculation of the
destination BitMap's size.

---

## See Also

- [BitMapScale — graphics.library](../autodocs/graphics.library.md#bitmapscale)
- [ScalerDiv — graphics.library](../autodocs/graphics.library.md#scalerdiv)
