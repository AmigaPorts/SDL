# graphics.library/WritePixelLine8



NAME

```c
    WritePixelLine8 -- write the pen number value of a horizontal line
    of pixels starting at a specified x,y location and continuing
    right for count pixels. (V36)
```
SYNOPSIS

```c
    count = WritePixelLine8(rp,xstart,ystart,width,array,temprp)
    D0                      A0 D0:16  D1:16  D2    A2    A1

    LONG WritePixelLine8(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UWORD, UWORD,
         UWORD, UBYTE *, struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

    For each pixel in a horizontal region, decode the pen number selector
    from a linear array of pen numbers into the bit-planes used to describe
    a particular rastport.
INPUTS

```c
    rp     - pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    (x,y)  - a point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
    width  - count of horizontal pixels to write
    array  - pointer to an array of UBYTEs from which to fetch the pixel
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
```
NOTE

    width must be non negative
BUGS

SEE ALSO

```c
    [WritePixel()](../Includes_and_Autodocs_2._guide/node048D.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
