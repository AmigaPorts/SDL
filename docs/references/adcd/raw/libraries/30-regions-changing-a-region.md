# 30 / Regions / Changing a Region


Regions may be modified by performing logical operations with rectangles,
or with other regions.


```c
    Reuse Your Rectangles.
    ----------------------
    In all of the rectangle and region routines the clipping rectangle
    is copied into the region.  This means that a single clipping
    rectangle ([Rectangle](../Libraries_Manual_guide/node03DA.html#line49) structure) may be used many times by simply
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
 [Rectangles and Regions](../Libraries_Manual_guide/node03FC.html)    [Regions and Regions](../Libraries_Manual_guide/node03FD.html) 

