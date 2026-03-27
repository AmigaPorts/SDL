# layers.library/BeginUpdate



NAME

    BeginUpdate -- Prepare to repair damaged layer.
SYNOPSIS

```c
    result = BeginUpdate( l )
    d0                    a0

    LONG BeginUpdate( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

```c
    Convert damage list to [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) list and swap in for
    programmer to redraw through. This routine simulates
    the ROM library environment. The idea is to only render in the
    "damaged" areas, saving time over redrawing all of the layer.
    The layer is locked against changes made by the layer library.
```
INPUTS

    l - pointer to a layer
RESULTS

```c
    result - TRUE if damage list converted to [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) list sucessfully.
             FALSE if list conversion aborted. (probably out of memory)
```
BUGS

```c
    If BeginUpdate returns FALSE, programmer must abort the attempt to
    refresh this layer and instead call EndUpdate( l, FALSE ) to restore
    original [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) and damage list.
```
SEE ALSO

```c
    [EndUpdate](../Includes_and_Autodocs_2._guide/node0396.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
