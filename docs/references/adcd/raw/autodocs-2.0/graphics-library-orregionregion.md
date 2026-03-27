# graphics.library/OrRegionRegion



NAME

    OrRegionRegion -- Perform 2d OR operation of one region
                   with second region, leaving result in second region
SYNOPSIS

```c
    status = OrRegionRegion(region1,region2)
      d0                       a0      a1

    BOOL OrRegionRegion( struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *, struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) * );
```
FUNCTION

    If any portion of region1  is not in the region then add
    that portion to the region2
INPUTS

```c
    region1 - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
    region2 - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
```
RESULTS

    status - return TRUE if successful operation
             return FALSE if ran out of memory
BUGS

SEE ALSO

```c
    [OrRectRegion()](../Includes_and_Autodocs_2._guide/node0464.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
