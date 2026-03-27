# graphics.library/ClearRectRegion



NAME

    ClearRectRegion -- Perform 2d CLEAR operation of rectangle
                    with region, leaving result in region.
SYNOPSIS

```c
    status = ClearRectRegion(region,rectangle)
     d0                       a0      a1

    BOOL ClearRectRegion(struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *, struct [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) * );
```
FUNCTION

    Clip away any portion of the region that exists inside
    of the rectangle. Leave the result in region.
INPUTS

```c
    region - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
    rectangle - pointer to [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) structure
```
RESULTS

    status - return TRUE if successful operation
             return FALSE if ran out of memory
BUGS

SEE ALSO

```c
    [AndRectRegion()](../Includes_and_Autodocs_2._guide/node0413.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
