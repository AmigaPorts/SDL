# 30 / / Working With Existing Layers / Intertask Operations


If multiple tasks are manipulating layers on the same display they will be
sharing a [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure and their use of it and its related data
structures need to be coordinated.  To ensure that a structure remains
cohesive, it should be operated on by only one task at a time.  The
Layer_Info encompasses all the layers existing on a single display.

[LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html) must be called whenever the visible portions of layers may
be affected, or when the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure is changed.


```c
    void LockLayerInfo( struct Layer_Info *li );
```
The lock should be obtained whenever a layer is created, deleted sized or
moved, as the list of layers that is being managed by the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) data
structure must be updated.

It is not necessary to lock the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) data structure while rendering,
or when calling routines like [ScrollLayer()](../Libraries_Manual_guide/node03EF.html#line17), because layer sizes and
on-display positions are not being affected.

Use [UnlockLayerInfo()](../Includes_and_Autodocs_2._guide/node03A7.html) when you have finished the layer operation:


```c
    void UnlockLayerInfo( struct Layer_Info *li );
```
If you don't unlock the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) then any other task calling
[LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html) on the same Layer_Info structure will be blocked creating
a potential deadlock situation.

In addition to locking the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure, the layer itself should
be locked if it is shared between tasks so that only one task at a time
renders graphics to it.  [LockLayer()](../Includes_and_Autodocs_2._guide/node039B.html) is used to get exclusive graphics
output to a layer.


```c
    void LockLayer( long dummy, struct Layer *layer );
```
If a graphics function is in process, the lock will return when the
function is completed.  Other tasks are blocked only if they attempt to
draw graphics into this layer, or try to obtain a lock on this layer. The
[MoveLayer()](../Libraries_Manual_guide/node03EF.html#line17), [SizeLayer()](../Libraries_Manual_guide/node03EF.html#line17) and [ScrollLayer()](../Libraries_Manual_guide/node03EF.html#line17) functions automatically lock
and unlock the layer they operate on.

[UnlockLayer()](../Includes_and_Autodocs_2._guide/node03A6.html) should be used after the graphics operation to make the
layer available to other tasks again.


```c
    void UnlockLayer( struct Layer *layer );
```
If more than one layer must be locked, then the [LockLayer()](../Includes_and_Autodocs_2._guide/node039B.html) calls should
be surrounded by [LockLayerInfo()](../Includes_and_Autodocs_2._guide/node039C.html) and [UnlockLayerInfo()](../Includes_and_Autodocs_2._guide/node03A7.html) calls, to prevent
deadlock situations.

The layers library provides two additional functions, [LockLayers()](../Includes_and_Autodocs_2._guide/node039D.html) and
[UnlockLayers()](../Includes_and_Autodocs_2._guide/node03A8.html), for locking multiple layers.


```c
    void LockLayers( struct Layer_Info *li );
    void UnlockLayers( struct Layer_Info *li );
```
[LockLayers()](../Includes_and_Autodocs_2._guide/node039D.html) is used to lock all layers in a single command.
[UnlockLayers()](../Includes_and_Autodocs_2._guide/node03A8.html) releases the layers lock.  The system calls these routines
during the [BehindLayer()](../Libraries_Manual_guide/node03EF.html#line23), [UpfrontLayer()](../Libraries_Manual_guide/node03EF.html#line23) and [MoveLayerInFrontOf()](../Libraries_Manual_guide/node03EF.html#line23)
operations ([described below](../Libraries_Manual_guide/node03EF.html)).

