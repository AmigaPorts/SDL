# graphics.library/ClearRegion



NAME

    ClearRegion -- Remove all rectangles from region.
SYNOPSIS

```c
    ClearRegion(region)
                 a0

    void ClearRegion( struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) * );
```
FUNCTION

    Clip away all rectangles in the region leaving nothing.
INPUTS

```c
    region - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
```
BUGS

SEE ALSO

```c
    [NewRegion()](../Includes_and_Autodocs_2._guide/node0460.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
