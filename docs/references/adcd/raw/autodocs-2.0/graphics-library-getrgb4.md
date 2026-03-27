# graphics.library/GetRGB4



NAME

```c
    GetRGB4 -- Inquire value of entry in [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113).
```
SYNOPSIS

```c
    value = GetRGB4( colormap, entry )
      d0              a0       d0

    ULONG GetRGB4(struct [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) *, LONG);
```
FUNCTION

```c
    Read and format a value from the [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113).
```
INPUTS

```c
    colormap - pointer to [ColorMap](../Includes_and_Autodocs_2._guide/node00B8.html#line113) structure
    entry - index into colormap
```
RESULT

    returns -1 if no valid entry
    return UWORD RGB value 4 bits per gun right justified
NOTE

```c
    Intuition's [DisplayBeep()](../Includes_and_Autodocs_2._guide/node020C.html) changes color 0. Reading Color 0 during a
    [DisplayBeep()](../Includes_and_Autodocs_2._guide/node020C.html) will lead to incorrect results.
```
BUGS

SEE ALSO

```c
    [SetRGB4()](../Includes_and_Autodocs_2._guide/node047C.html) [LoadRGB4()](../Includes_and_Autodocs_2._guide/node0458.html) [GetColorMap()](../Includes_and_Autodocs_2._guide/node0445.html) [FreeColorMap()](../Includes_and_Autodocs_2._guide/node043E.html) [graphics/view.h](../Includes_and_Autodocs_2._guide/node00B8.html)
```
