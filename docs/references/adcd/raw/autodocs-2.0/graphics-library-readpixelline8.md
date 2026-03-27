# graphics.library/ReadPixelLine8



NAME

```c
    ReadPixelLine8 -- read the pen number value of a horizontal line
    of pixels starting at a specified x,y location and continuing
    right for count pixels. (V36)
```
SYNOPSIS

```c
    count = ReadPixelLine8(rp,xstart,ystart,width,array,temprp)
    D0                     A0 D0:16  D1:16  D2    A2    A1

    LONG ReadPixelLine8(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UWORD, UWORD, UWORD,
         UBYTE *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) * );
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
    rp     - pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    (x,y)  - a point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    width  - count of horizontal pixels to read
    array -  pointer to an array of UBYTEs from which to fetch the pixel
             data allocate at least (((width+15)>>4)<<4) bytes.
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
    count   - the number of pixels read.
```
NOTE

    width must be non negative
BUGS

SEE ALSO

```c
    [ReadPixel()](../Includes_and_Autodocs_2._guide/node046A.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
