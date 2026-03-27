# graphics.library/SetOPen



NAME

    SetOPen -- Change the Area OutLine pen and turn on Outline
                    mode for areafills.
SYNOPSIS

```c
    SetOPen(rp, pen)

    void SetOPen( struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *, UBYTE );
```
FUNCTION

```c
    This is implemented as a c-macro.
    Pen is the pen number that will be used to draw a border
    around an areafill during [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html).
```
INPUTS

```c
    rp = pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
    pen = number  between 0-255
```
BUGS

SEE ALSO

```c
    [AreaEnd()](../Includes_and_Autodocs_2._guide/node0419.html) [graphics/gfxmacros.h](../Includes_and_Autodocs_2._guide/node00B6.html) [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
