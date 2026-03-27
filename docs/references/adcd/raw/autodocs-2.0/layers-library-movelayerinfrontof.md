# layers.library/MoveLayerInFrontOf



NAME

    MoveLayerInFrontOf -- Put layer in front of another layer.
SYNOPSIS

```c
    result = MoveLayerInFrontOf( layertomove, targetlayer )
                                a0           a1

    LONG MoveLayerInFrontOf( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *, struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

```c
    Move this layer in front of target layer, swapping bits
    in and out of the display with other layers.
    If this is a refresh layer then collect damage list and
    set the LAYERREFRESH bit in layer->Flags if redraw required.

    Note: this operation may generate refresh events in other layers
        associated with this layer's [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.
```
INPUTS

    layertomove - pointer to layer which should be moved
    targetlayer - pointer to target layer in front of which to move layer
RESULTS

```c
    result = TRUE    if operation successful
             FALSE   if operation unsuccessful (probably out of memory)
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
