# graphics.library/SetRGB4



NAME

    SetRGB4 -- Set one color register for this viewport.
SYNOPSIS

```c
    SetRGB4(  vp, n,   r,    g,    b)
              a0  d0  d1:4  d2:4  d3:4

    void SetRGB4( struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *, SHORT, UBYTE, UBYTE, UBYTE );
```
FUNCTION

```c
    Change the color look up table so that this viewport displays
    the color (r,g,b) for pen number n.
```
INPUTS

```c
    vp - pointer to  viewport structure
    n - the color number (range from 0 to 31)
    r - red level (0-15)
    g - green level (0-15)
    b - blue level (0-15)
```
RESULT

```c
    If there is a [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) for this viewport, then the value will
    be stored in the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113).
    The selected color register is changed to match your specs.
    If the color value is unused then nothing will happen.
```
BUGS

    NOTE: Under V36 and up, it is not safe to call this function
    from an interrupt, due to semaphore protection of graphics
    copper lists.
SEE ALSO

```c
    [LoadRGB4()](../Includes_and_Autodocs_2._guide/node0458.html) [GetRGB4()](../Includes_and_Autodocs_2._guide/node0448.html) [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
