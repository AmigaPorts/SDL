# graphics.library/OrRectRegion



NAME

    OrRectRegion -- Perform 2d OR operation of rectangle
                   with region, leaving result in region.
SYNOPSIS

```c
    status = OrRectRegion(region,rectangle)
      d0                    a0      a1

    BOOL OrRectRegion( struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *, struct [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) * );
```
FUNCTION

    If any portion of rectangle is not in the region then add
    that portion to the region.
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
    [AndRectRegion()](../Includes_and_Autodocs_2._guide/node0413.html) [OrRegionRegion()](../Includes_and_Autodocs_2._guide/node0465.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
