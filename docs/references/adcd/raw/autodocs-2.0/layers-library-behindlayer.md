# layers.library/BehindLayer



NAME

    BehindLayer -- Put layer behind other layers.
SYNOPSIS

```c
    result = BehindLayer( dummy, l )
    d0                    a0     a1

    LONG BehindLayer( LONG, struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

```c
    Move this layer to the most behind position swapping bits
    in and out of the display with other layers.
    If other layers are REFRESH then collect their damage lists and
    set the LAYERREFRESH bit in the Flags fields of those layers that
    may be revealed.  If this layer is a backdrop layer then
    put this layer behind all other backdrop layers.
    If this layer is NOT a backdrop layer then put in front of the
    top backdrop layer and behind all other layers.

    Note: this operation may generate refresh events in other layers
       associated with this layer's [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.
```
INPUTS

    dummy - unused
    l - pointer to a layer
RESULTS

```c
    result - TRUE    if operation successful
             FALSE   if operation unsuccessful (probably out of memory)
```
BUGS

SEE ALSO
   [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)

