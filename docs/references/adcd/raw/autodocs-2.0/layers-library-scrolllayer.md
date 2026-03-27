# layers.library/ScrollLayer



NAME

    ScrollLayer -- Scroll around in a superbitmap, translate coordinates
                  in non-superbitmap layer.
SYNOPSIS

```c
    ScrollLayer( dummy, l, dx, dy )
                 a0     a1 d0  d1

    void ScrollLayer( LONG, struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *, LONG, LONG);
```
FUNCTION

```c
    For a SuperBitMap Layer:
    Update the SuperBitMap from the layer display, then copy bits
    between [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) and SuperBitMap to reposition layer over different
    portion of SuperBitMap.
    For nonSuperBitMap layers, all (x,y) pairs are adjusted by
    the scroll(x,y) value in the layer.  To cause (0,0) to actually
    be drawn at (3,10) use ScrollLayer(-3,-10). This can be useful
    along with [InstallClipRegion](../Includes_and_Autodocs_2._guide/node0399.html) to simulate Intuition GZZWindows
    without the overhead of an extra layer.
```
INPUTS

    dummy - unused
    l - pointer to a layer
    dx - delta to add to current x scroll value
    dy - delta to add to current y scroll value
BUGS

```c
    May not handle (dx,dy) which attempts to move the layer ouside the
    layer's SuperBitMap bounds.
```
SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
