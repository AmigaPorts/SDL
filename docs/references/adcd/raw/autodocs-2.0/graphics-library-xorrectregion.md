# graphics.library/XorRectRegion



NAME

    XorRectRegion -- Perform 2d XOR operation of rectangle
                     with region, leaving result in region
SYNOPSIS

```c
    status = XorRectRegion(region,rectangle)
    d0                     a0      a1

    BOOL XorRectRegion( struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *, struct [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) * );
```
FUNCTION

    Add portions of rectangle to region if they are not in
    the region.
    Remove portions of rectangle from region if they are
    in the region.
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
    [OrRegionRegion()](../Includes_and_Autodocs_2._guide/node0465.html) [AndRegionRegion()](../Includes_and_Autodocs_2._guide/node0414.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
