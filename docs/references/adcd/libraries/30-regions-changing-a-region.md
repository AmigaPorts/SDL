---
title: 30 / Regions / Changing a Region
manual: libraries
chapter: libraries
section: 30-regions-changing-a-region
functions: []
libraries: []
---

# 30 / Regions / Changing a Region

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Regions may be modified by performing logical operations with rectangles,
or with other regions.


```c
    Reuse Your Rectangles.
    ----------------------
    In all of the rectangle and region routines the clipping rectangle
    is copied into the region.  This means that a single clipping
    rectangle ([Rectangle](libraries/29-graphics-library-and-text-does-the-text-fit.md) structure) may be used many times by simply
    changing the x and y values.  The application need not create a
    new instance of the Rectangle structure for each rectangle added
    to a region.
```
For instance:


```c
    extern struct Region *RowRegion;  /* created elsewhere */

    WORD ktr;
    struct Rectangle rect;

    for (ktr = 1; ktr < 6; ktr++)
        {
        rect.MinX = 50;
        rect.MaxX = 315;
        rect.MinY = (ktr * 10) - 5;
        rect.MaxY = (ktr * 10);

        if (!OrRectRegion(RowRegion, &rect))
            clean_exit(RETURN_WARN);
        }
```
 [Rectangles and Regions](libraries/30-changing-a-region-rectangles-and-regions.md)    [Regions and Regions](libraries/30-changing-a-region-regions-and-regions.md) 

