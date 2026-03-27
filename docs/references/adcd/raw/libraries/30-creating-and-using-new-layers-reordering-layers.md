# 30 / / Creating and Using New Layers / Reordering Layers


The layers library provides three function calls for reordering layers:


```c
    LONG BehindLayer ( long dummy, struct Layer *layer );
    LONG UpfrontLayer( long dummy, struct Layer *layer );
    LONG MoveLayerInFrontOf( struct Layer *layer_to_move,
                             struct Layer *other_layer );
```
[BehindLayer()](../Includes_and_Autodocs_2._guide/node038F.html) moves a layer behind all other layers.  This function
considers any [backdrop](../Libraries_Manual_guide/node03EA.html) layers, moving a current layer behind all others
except backdrop layers.  [UpfrontLayer()](../Includes_and_Autodocs_2._guide/node03A9.html) moves a layer in front of all
other layers.  [MoveLayerInFrontOf()](../Includes_and_Autodocs_2._guide/node039F.html) is used to place a layer at a specific
depth, just in front of a given layer.

As areas of [simple refresh](../Libraries_Manual_guide/node03E7.html) layers become exposed, due to layer movement or
sizing for example, the newly exposed areas have not been drawn into, and
need refreshing.  The system keeps track of these areas by using a
[DamageList](../Libraries_Manual_guide/node03E4.html#line21).  To update only those areas that need it, the [BeginUpdate()](../Includes_and_Autodocs_2._guide/node038E.html)
[EndUpdate()](../Includes_and_Autodocs_2._guide/node0396.html) functions are called.


```c
    LONG BeginUpdate( struct Layer *l );
    void EndUpdate  ( struct Layer *layer, unsigned long flag );
```
[BeginUpdate()](../Includes_and_Autodocs_2._guide/node038E.html) saves the pointer to the current clipping rectangles and
installs a pointer to a set of [ClipRect](../Libraries_Manual_guide/node03E4.html#line11)s generated from the [DamageList](../Libraries_Manual_guide/node03E4.html#line21) in
the layer structure.  To repair the layer, use the graphics rendering
routines as if to redraw the entire layer, and the routines will
automatically use the new clipping rectangle list.  So, only the damaged
areas are actually rendered into, saving time.


```c
    Never Modify the DamageList.
    ----------------------------
    The system generates and maintains the [DamageList](../Libraries_Manual_guide/node03E4.html#line21) region.  All
    application clipping should be done through the [InstallClipRegion()](../Libraries_Manual_guide/node03F8.html#line16)
    function.
```
To complete the update process call [EndUpdate()](../Includes_and_Autodocs_2._guide/node0396.html) which will restore the
original [ClipRect](../Libraries_Manual_guide/node03E4.html#line11) list.

