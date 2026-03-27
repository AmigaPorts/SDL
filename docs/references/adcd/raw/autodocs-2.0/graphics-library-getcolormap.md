# graphics.library/GetColorMap



NAME


    GetColorMap -- allocate and initialize Colormap
SYNOPSIS

```c
    cm = GetColorMap( entries )
          d0                   d0

    struct [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) *GetColorMap( ULONG);
```
FUNCTION

```c
    Allocates, initializes and returns a pointer to a [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113)
    data structure, later enabling calls to [SetRGB4](../Includes_and_Autodocs_2._guide/node047C.html)
    and [LoadRGB4](../Includes_and_Autodocs_2._guide/node0458.html) to load colors for a view port. The ColorTable
    pointer in the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) structure points to a hardware
    specific colormap data structure. You should not count on
    it being anything you can understand. Use [GetRGB4()](../Includes_and_Autodocs_2._guide/node0448.html) to
    query it or [SetRGB4CM](../Includes_and_Autodocs_2._guide/node047D.html) to set it directly.
```
INPUTS

    entries - number of entries for this colormap
RESULT

    The pointer value returned by this routine, if nonzero,
    may be stored into the ViewPort.ColorMap pointer.
    If a value of 0 is returned, the system was unable
    to allocate enough memory space for the required
    data structures.
BUGS

SEE ALSO

```c
    [SetRGB4()](../Includes_and_Autodocs_2._guide/node047C.html) [FreeColorMap()](../Includes_and_Autodocs_2._guide/node043E.html)
```
