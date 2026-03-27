# graphics.library/LockLayerRom



NAME

```c
    LockLayerRom -- Lock [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure by rom(gfx lib) code.
```
SYNOPSIS

```c
    LockLayerRom( layer )
                   a5

    void LockLayerRom( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) * );
```
FUNCTION

```c
    Return when the layer is locked and no other task may
    alter the [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) structure in the [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure.
    This call does not destroy any registers.
    This call nests so that callers in this chain will not lock
    themselves out.
    Do not have the [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) locked during a call to intuition.
    There is a potential deadlock problem here, if intuition
    needs to get other locks as well.
    Having the layer locked prevents other tasks from using the
    layer library functions, most notably intuition itself. So
    be brief.
    layers.library's [LockLayer](../Includes_and_Autodocs_2._guide/node039B.html) is identical to LockLayerRom.
```
INPUTS

```c
    layer - pointer to [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure
```
RESULTS

```c
    The layer is locked and the task can render assuming the
    ClipRects will not change out from underneath it until
    an [UnlockLayerRom](../Includes_and_Autodocs_2._guide/node0486.html) is called.
```
SEE ALSO

```c
    [UnlockLayerRom()](../Includes_and_Autodocs_2._guide/node0486.html) [layers.library/LockLayer()](../Includes_and_Autodocs_2._guide/node039B.html) [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
