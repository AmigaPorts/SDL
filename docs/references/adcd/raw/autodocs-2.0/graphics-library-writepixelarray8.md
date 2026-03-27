# graphics.library/WritePixelArray8



NAME

```c
    WritePixelArray8 -- write the pen number value of a rectangular array
    of pixels starting at a specified x,y location and continuing
    through to another x,y location within a certain [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55). (V36)
```
SYNOPSIS

```c
    count = WritePixelArray8(rp,xstart,ystart,xstop,ystop,array,temprp)
    D0                       A0 D0:16  D1:16  D2:16 D3:16  A2   A1

    LONG WritePixelArray8(struct  [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UWORD, UWORD,
         UWORD, UWORD, UBYTE *, struct  [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

    For each pixel in a rectangular region, decode the pen number selector
    from a linear array of pen numbers into the bit-planes used to describe
    a particular rastport.
INPUTS

```c
    rp     -  pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    (xstart,ystart) -  starting point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    (xstop,ystop)   -  stopping point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    array  - pointer to an array of UBYTEs from which to fetch the
             pixel data. Allocate at least
             ((((width+15)>>4)<<4)*(ystop-ystart+1)) bytes.
    temprp - temporary rastport (copy of rp with [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) set == NULL,
             temporary memory allocated for
             temprp->BitMap with Rows set == 1,
             temprp->BytesPerRow == (((width+15)>>4)<<1),
             and temporary memory allocated for
             temprp->BitMap->Planes[])
```
RESULT

```c
    For each pixel in the array:
        Pen - (0..255) number at that position is returned
```
NOTE

```c
    xstop must be >= xstart
    ystop must be >= ystart
```
BUGS

SEE ALSO

```c
    [WritePixel()](../Includes_and_Autodocs_2._guide/node048D.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
