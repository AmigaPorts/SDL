# layers.library/ThinLayerInfo



NAME

    ThinLayerInfo -- convert 1.1 LayerInfo to 1.0 LayerInfo.
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
SYNOPSIS

```c
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
    ThinLayerInfo( li )
                   a0

    void ThinLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
FUNCTION

```c
    return the extra memory needed that was allocated with
    [FattenLayerInfo](../Includes_and_Autodocs_2._guide/node0397.html). This is must be done prior to freeing
    the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure itself. V1.1 software should be
    using [DisposeLayerInfo](../Includes_and_Autodocs_2._guide/node0395.html).
```
INPUTS

    li - pointer to LayerInfo structure
BUGS

SEE ALSO

```c
    [DisposeLayerInfo](../Includes_and_Autodocs_2._guide/node0395.html), [FattenLayerInfo](../Includes_and_Autodocs_2._guide/node0397.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
