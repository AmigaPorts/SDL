# layers.library/InitLayers



NAME

```c
    InitLayers -- Initialize [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
SYNOPSIS

```c
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
    InitLayers( li )
                a0

    void InitLayers( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
    OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```
FUNCTION

```c
    Initialize [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure in preparation to use
    other layer operations on this list of layers.
    Make the Layers unlocked (open), available to layer operations.
```
INPUTS

    li - pointer to LayerInfo structure
BUGS

SEE ALSO

```c
    [NewLayerInfo](../Includes_and_Autodocs_2._guide/node03A1.html), [DisposeLayerInfo](../Includes_and_Autodocs_2._guide/node0395.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
