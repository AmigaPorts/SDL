# layers.library/LockLayerInfo



NAME

    LockLayerInfo -- Lock the LayerInfo structure.
SYNOPSIS

```c
    LockLayerInfo( li )
                   a0

    void LockLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
```
FUNCTION

```c
    Before doing an operation that requires the LayerInfo
    structure, make sure that no other task is also using the
    LayerInfo structure.  LockLayerInfo() returns when the
    LayerInfo belongs to this task.  There should be
    an [UnlockLayerInfo](../Includes_and_Autodocs_2._guide/node03A7.html) for every LockLayerInfo.

    Note: All layer routines presently LockLayerInfo() when they
    start up and [UnlockLayerInfo()](../Includes_and_Autodocs_2._guide/node03A7.html) as they exit.  Programmers
    will need to use these Lock/Unlock routines if they wish
    to do something with the LayerStructure that is not
    supported by the layer library.
```
INPUTS

```c
    li - pointer to [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure
```
BUGS

SEE ALSO

```c
    [UnlockLayerInfo](../Includes_and_Autodocs_2._guide/node03A7.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
