# layers.library/DeleteLayer



NAME

    DeleteLayer -- delete layer from layer list.
SYNOPSIS

```c
    result = DeleteLayer( dummy, l )
    d0                    a0,    a1

    LONG DeleteLayer( LONG, struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

    Remove this layer from the list of layers.  Release memory
    associated with it.  Restore other layers that may have been
    obscured by it.  Trigger refresh in those that may need it.
    If this is a superbitmap layer make sure SuperBitMap is current.
    The SuperBitMap is not removed from the system but is available
    for program use even though the rest of the layer information has
    been deallocated.
INPUTS

    dummy - unused
    l - pointer to a layer
RESULTS

```c
    result - TRUE if this layer successfully deleted from the system
             FALSE if layer not deleted. (probably out of memory )
```
BUGS

SEE ALSO

```c
    [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
