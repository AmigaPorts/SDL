# graphics.library/ClearScreen



NAME

```c
    ClearScreen -- Clear from current position to end of [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55).
```
SYNOPSIS

```c
    ClearScreen(rp)
                A1

    void ClearScreen(struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *);
```
FUNCTION

```c
    Clear a rectangular swath from the current position to the
    right edge of the rastPort with [ClearEOL](../Includes_and_Autodocs_2._guide/node0429.html), then clear the rest
    of the screen from just beneath the swath to the bottom of
    the rastPort.
    Clearing consists of setting the color of the swath to zero,
    or, if the DrawMode is 2, to the BgPen.
```
INPUTS

```c
    rp - pointer to [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) structure
```
NOTES

    o   This function may use the blitter.
SEE ALSO

```c
    [ClearEOL()](../Includes_and_Autodocs_2._guide/node0429.html)  [Text()](../Includes_and_Autodocs_2._guide/node0482.html)  [SetRast()](../Includes_and_Autodocs_2._guide/node047B.html)
    [graphics/text.h](../Includes_and_Autodocs_2._guide/node00A8.html)  [graphics/rastport.h](../Includes_and_Autodocs_2._guide/node00AF.html)
```
