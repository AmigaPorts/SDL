# layers.library/MoveSizeLayer



NAME                                                              (V36)

    MoveSizeLayer -- Position/Size layer
SYNOPSIS

```c
    result = MoveSizeLayer( layer, dx, dy, dw, dh )
    d0                      a0     d0  d1  d2  d3

    LONG MoveSizeLayer( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *, LONG, LONG, LONG, LONG);
```
FUNCTION

```c
    Change upperleft and lower right position of [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33).
```
INPUTS

```c
    dummy - unused
    l - pointer to a nonbackdrop layer
    dx,dy - change upper left corner by (dx,dy)
    dw,dy - change size by (dw,dh)
```
RETURNS

```c
    result - TRUE if operation successful
             FALSE if failed (due to out of memory)
             FALSE if failed (due to illegal layer->bounds)
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
