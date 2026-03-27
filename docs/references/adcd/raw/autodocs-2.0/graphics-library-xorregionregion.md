# graphics.library/XorRegionRegion



NAME

    XorRegionRegion -- Perform 2d XOR operation of one region
                       with second region, leaving result in second region
SYNOPSIS

```c
    status = XorRegionRegion(region1,region2)
    d0                        a0      a1

    BOOL XorRegionRegion( struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *, struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) * );
```
FUNCTION

    Join the regions together. If any part of region1 overlaps
    region2 then remove that from the new region.
INPUTS

```c
    region1      = pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
    region2      = pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
```
RESULTS

    status - return TRUE if successful operation
             return FALSE if ran out of memory
BUGS

