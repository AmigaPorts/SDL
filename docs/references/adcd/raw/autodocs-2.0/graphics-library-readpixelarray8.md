# graphics.library/ReadPixelArray8



NAME

```c
    ReadPixelArray8 -- read the pen number value of a rectangular array
    of pixels starting at a specified x,y location and continuing
    through to another x,y location within a certain [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55). (V36)
```
SYNOPSIS

```c
    count = ReadPixelArray8(rp,xstart,ystart,xstop,ystop,array,temprp)
    D0                      A0 D0:16  D1:16  D2:16 D3:16 A2    A1
```
 LONG ReadPixelArray8(struct  [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UWORD, UWORD, UWORD, UWORD,

```c
       UBYTE *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    For each pixel in a rectangular region, combine the bits from each
    of the bit-planes used to describe a particular [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) into the pen
    number selector which that bit combination normally forms for the
    system hardware selection of pixel color.
```
INPUTS

```c
    rp    -  pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    (xstart,ystart) - starting point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    (xstop,ystop)   - stopping point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    array -  pointer to an array of ubytes from which to fetch the pixel
             data allocate at least ((((width+15)>>4)<<4)*(ystop-ystart+1))
             bytes.
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
      count - the number of pixels read.
```
NOTE

```c
    xstop must be >= xstart
    ystop must be >= ystart
```
BUGS

SEE ALSO

```c
    [ReadPixel()](../Includes_and_Autodocs_2._guide/node046A.html)  [ReadPixelLine8()](../Includes_and_Autodocs_2._guide/node046C.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
