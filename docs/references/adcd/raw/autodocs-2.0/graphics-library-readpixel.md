# graphics.library/ReadPixel



NAME

```c
    ReadPixel -- read the pen number value of the pixel at a
                 specified x,y location within a certain [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    penno = ReadPixel( rp,    x,    y )
      d0               a1  d0:16 d1:16

    LONG ReadPixel( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, SHORT, SHORT );
```
FUNCTION

```c
    Combine the bits from each of the bit-planes used to describe
    a particular [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) into the pen number selector which that
    bit combination normally forms for the system hardware selection
    of pixel color.
```
INPUTS

```c
    rp -  pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    (x,y) a point in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55)
```
RESULT

```c
    penno - the pen number of the pixel at (x,y) is returned.
            -1 is returned if the pixel cannot be read for some reason.
```
BUGS

SEE ALSO

```c
    [WritePixel()](../Includes_and_Autodocs_2._guide/node048D.html)    [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
