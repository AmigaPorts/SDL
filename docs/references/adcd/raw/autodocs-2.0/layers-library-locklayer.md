# layers.library/LockLayer



NAME

    LockLayer -- Lock layer to make changes to ClipRects.
SYNOPSIS

```c
    LockLayer( dummy, l )
               a0     a1

    void LockLayer( LONG, struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

```c
    Make this layer unavailable for other tasks to use.
    If another task is already using this layer then wait for
    it to complete and then reserve the layer for your own use.
    (this function does the same thing as graphics.library/LockLayerRom)

    Note: if you wish to lock MORE THAN ONE layer at a time, you
        must call [LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html) before locking those layers and
        then call [UnlockLayerInfo()](../Includes_and_Autodocs_2._guide/node03A7.html) when you have finished. This
        is to prevent system "deadlocks".

    Further Note: while you hold the lock on a layer, Intuition will block
        on operations such as windowsizing, dragging, menus, and depth
        arranging windows in this layer's screen.  It is recommended that
        YOU do not make Intuition function calls while the layer is locked.
```
INPUTS

    dummy - unused
    l - pointer to a layer
BUGS

SEE ALSO

```c
    [UnlockLayer](../Includes_and_Autodocs_2._guide/node03A6.html), [LockLayerInfo](../Includes_and_Autodocs_2._guide/node039C.html), [UnlockLayerInfo](../Includes_and_Autodocs_2._guide/node03A7.html),
    [graphics.library/LockLayerRom](../Includes_and_Autodocs_2._guide/node045A.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
