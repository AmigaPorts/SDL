# layers.library/UpfrontLayer



NAME

    UpfrontLayer -- Put layer in front of all other layers.
SYNOPSIS

```c
    result = UpfrontLayer( dummy, l )
    d0                     a0     a1

    LONG UpfrontLayer( LONG, struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

```c
    Move this layer to the most upfront position swapping bits
    in and out of the display with other layers.
    If this is a refresh layer then collect damage list and
    set the LAYERREFRESH bit in layer->Flags if redraw required.
    By clearing the BACKDROP bit in the layers Flags you may
    bring a Backdrop layer up to the front of all other layers.

    Note: this operation may generate refresh events in other layers
       associated with this layer's [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure.
```
INPUTS

    dummy - unused
    l - pointer to a nonbackdrop layer
RESULTS

```c
    result - TRUE   if operation successful
             FALSE  if operation unsuccessful (probably out of memory)
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
