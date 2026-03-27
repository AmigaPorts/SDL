# graphics.library/UnlockLayerRom



NAME

```c
    UnlockLayerRom -- Unlock [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure by rom(gfx lib) code.
```
SYNOPSIS

```c
    UnlockLayerRom( layer )
                     a5

    void UnlockLayerRom( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) * );
```
FUNCTION

```c
    Release the lock on this layer. If the same task has called
    [LockLayerRom](../Includes_and_Autodocs_2._guide/node045A.html) more than once than the same number of calls to
    UnlockLayerRom must happen before the layer is actually freed
    so that other tasks may use it.
    This call does destroy scratch registers.
    This call is identical to [UnlockLayer](../Includes_and_Autodocs_2._guide/node03A6.html) (layers.library).
```
INPUTS

```c
    layer - pointer to [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure
```
BUGS

SEE ALSO

```c
    [LockLayerRom()](../Includes_and_Autodocs_2._guide/node045A.html) [layers.library/UnlockLayer()](../Includes_and_Autodocs_2._guide/node03A6.html) [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
