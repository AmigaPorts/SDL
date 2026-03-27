# graphics.library/BltPattern



NAME

    BltPattern --  Using standard drawing rules for areafill,
                                     blit through a mask.
SYNOPSIS

```c
    BltPattern(rp, mask, xl, yl, maxx, maxy, bytecnt)
              a1,  a0   d0  d1   d2   d3     d4

    void BltPattern
       (struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, void *, SHORT, SHORT, SHORT, SHORT, SHORT);
```
FUNCTION

```c
    Blit using drawmode,areafill pattern, and mask
    at position rectangle (xl,yl) (maxx,maxy).
```
INPUTS

```c
    rp    -  points to the destination [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) for the blit.
    mask  -  points to 2 dimensional mask if needed
             if mask == NULL then use a rectangle.
    xl,yl -  coordinates of upper left of rectangular region in [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    maxx,maxy - points to lower right of rectangular region in [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    bytecnt - BytesPerRow for mask
```
RESULT

SEE ALSO

```c
    [AreaEnd](../Includes_and_Autodocs_2._guide/node0419.html)
```
