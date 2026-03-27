# layers.library/MoveLayer



NAME

```c
    MoveLayer -- Move layer to new position in [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47).
```
SYNOPSIS

```c
    result = MoveLayer( dummy, l, dx, dy )
    d0                  a0     a1 d0  d1

    LONG MoveLayer( LONG, struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *, LONG, LONG);
```
FUNCTION

```c
    Move this layer to new position in shared [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47).
    If any refresh layers become revealed, collect damage and
    set REFRESH bit in layer Flags.
```
INPUTS

    dummy - unused
    l - pointer to a nonbackdrop layer
    dx - delta to add to current x position
    dy - delta to add to current y position
RETURNS

```c
    result - TRUE if operation successful
             FALSE if failed (out of memory)
```
BUGS

```c
    May not handle (dx,dy) which attempts to move the layer ouside the
    layer's RastPort->BitMap bounds .
```
SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
