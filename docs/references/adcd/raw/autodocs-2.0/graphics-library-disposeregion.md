# graphics.library/DisposeRegion



NAME

    DisposeRegion -- Return all space for this region to free
                     memory pool.
SYNOPSIS

```c
    DisposeRegion(region)
                  a0

    void DisposeRegion( struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) * );
```
FUNCTION

```c
    Free all RegionRectangles for this [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) then
    free the [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) itself.
```
INPUTS

```c
    region - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
```
BUGS

SEE ALSO

```c
    [NewRegion()](../Includes_and_Autodocs_2._guide/node0460.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
