# graphics.library/AndRegionRegion



NAME

    AndRegionRegion -- Perform 2d AND operation of one region
                      with second region, leaving result in second region.
SYNOPSIS

```c
    status = AndRegionRegion(region1,region2)
      d0                       a0      a1

    BOOL AndRegionRegion(struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *, struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) * );
```
FUNCTION

    Remove any portion of region2 that is not in region1.
INPUTS

```c
    region1 - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
    region2 - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure to use and for result
```
RESULTS

    status - return TRUE if successful operation
             return FALSE if ran out of memory
BUGS

SEE ALSO

```c
    [OrRegionRegion()](../Includes_and_Autodocs_2._guide/node0465.html) [AndRectRegion()](../Includes_and_Autodocs_2._guide/node0413.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
