# graphics.library/AndRectRegion



NAME

    AndRectRegion -- Perform 2d AND operation of rectangle
                     with region, leaving result in region.
SYNOPSIS

```c
    AndRectRegion(region,rectangle)
                    a0      a1

    void AndRectRegion( struct [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) *, struct [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) * );
```
FUNCTION

    Clip away any portion of the region that exists outside
    of the rectangle. Leave the result in region.
INPUTS

```c
    region - pointer to [Region](../Includes_and_Autodocs_2._guide/node00B7.html#line28) structure
    rectangle - pointer to [Rectangle](../Includes_and_Autodocs_2._guide/node00A6.html#line28) structure
```
NOTES

```c
    Unlike the other rect-region primitives, AndRectRegion() cannot
    fail.
```
BUGS

SEE ALSO

```c
    [AndRegionRegion()](../Includes_and_Autodocs_2._guide/node0414.html) [OrRectRegion()](../Includes_and_Autodocs_2._guide/node0464.html) [graphics/regions.h](../Includes_and_Autodocs_2._guide/node00B7.html)
```
