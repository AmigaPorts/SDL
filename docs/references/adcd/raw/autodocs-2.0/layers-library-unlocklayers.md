# layers.library/UnlockLayers



NAME

    UnlockLayers -- Unlock all layers from graphics output.
                    Restart graphics output to layers that have been
                    waiting
SYNOPSIS

```c
    UnlockLayers( li )
                  a0

    void UnlockLayers( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
```
FUNCTION

```c
    Make all layers in this layer list unlocked.
    Then call [UnlockLayerInfo](../Includes_and_Autodocs_2._guide/node03A7.html)
```
INPUTS

```c
    li - pointer to the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure
```
BUGS

SEE ALSO

```c
    [LockLayers](../Includes_and_Autodocs_2._guide/node039D.html), [UnlockLayer](../Includes_and_Autodocs_2._guide/node03A6.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
