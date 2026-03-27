# layers.library/UnlockLayerInfo



NAME

    UnlockLayerInfo -- Unlock the LayerInfo structure.
SYNOPSIS

```c
    UnlockLayerInfo( li )
                     a0

    void UnlockLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
```
FUNCTION

```c
    After the operation is complete that required a [LockLayerInfo](../Includes_and_Autodocs_2._guide/node039C.html),
    unlock the LayerInfo structure so that  other tasks may
    affect the layers.
```
INPUTS

```c
    li - pointer to the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure
```
 BUGS

 SEE ALSO

```c
    [LockLayerInfo](../Includes_and_Autodocs_2._guide/node039C.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
