# graphics.library/EraseRect



NAME


```c
    EraseRect -- Fill a defined rectangular area using the current
                    BackFill hook. (V36)
```
SYNOPSIS

```c
    EraseRect( rp, xmin, ymin, xmax, ymax)
              a1  d0:16 d1:16 d2:16 d3:16

    void EraseRect(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT, SHORT, SHORT);
```
FUNCTION

```c
    Fill the rectangular region specified by the parameters with the
    BackFill hook. If non-layered, the rectangular region specified by
    the parameters is cleared. If layered the Layer->BackFill [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) is used.
```
INPUTS

```c
    rp      - pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    xmin    - x coordinate of the upper left corner of the region to fill.
    ymin    - y coordinate of the upper left corner of the region to fill.
    xmax    - x coordinate of the lower right corner of the region to fill.
    ymax    - y coordinate of the lower right corner of the region to fill.
```
BUGS

NOTES

```c
    The following relation MUST be true:
    (xmax >= xmin) and (ymax >= ymin)
```
SEE ALSO

```c
    [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html) [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
