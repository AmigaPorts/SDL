# graphics.library/InitRastPort



NAME

    InitRastPort -- Initialize raster port structure
SYNOPSIS


```c
    InitRastPort( rp )
                  a1

    void InitRastPort(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION
   Initialize a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure to standard values.

INPUTS

```c
    rp = pointer to a [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure.
```
RESULT

```c
    all entries in [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) get zeroed out, with the following exceptions:

        Mask, FgPen, AOLPen, and LinePtrn are set to -1.
        The DrawMode is set to JAM2
        The font is set to the standard system font
```
NOTES

```c
    The struct Rastport describes a control structure
    for a write-able raster. The [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    describes how a complete single playfield display
    will be written into. A [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure is
    referenced whenever any drawing or filling
    operations are to be performed on a section of
    memory.

    The section of memory which is being used in this
    way may or may not be presently a part of the
    current actual onscreen display memory. The name
    of the actual memory section which is linked to
    the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) is referred to here as a "raster" or
    as a bitmap.

    NOTE: Calling the routine InitRastPort only
    establishes various defaults. It does NOT
    establish where, in memory, the rasters are
    located. To do graphics with this [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) the user
    must set up the [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) pointer in the [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
BUGS

SEE ALSO

```c
    [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
