# layers.library/LockLayers



NAME

    LockLayers -- lock all layers from graphics output.
SYNOPSIS

```c
    LockLayers( li )
                a0

    void LockLayers( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
```
FUNCTION

```c
    First calls [LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html)
    Make all layers in this layer list locked.
```
INPUTS

```c
    li - pointer to [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure
```
BUGS

SEE ALSO

```c
    [LockLayer](../Includes_and_Autodocs_2._guide/node039B.html), [LockLayerInfo](../Includes_and_Autodocs_2._guide/node039C.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
