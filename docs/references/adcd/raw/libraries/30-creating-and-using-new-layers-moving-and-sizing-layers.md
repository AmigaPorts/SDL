# 30 / / Creating and Using New Layers / Moving and Sizing Layers


The layers library includes three functions for moving and sizing layers:


```c
    LONG MoveLayer( long dummy, struct Layer *layer, long dx, long dy );
    LONG SizeLayer( long dummy, struct Layer *layer, long dx, long dy );
    LONG MoveSizeLayer( struct Layer *layer, long dx, long dy, long dw,
                        long dh);
```
[MoveLayer()](../Includes_and_Autodocs_2._guide/node039E.html) moves a layer to a new position relative to its current
position.  [SizeLayer()](../Includes_and_Autodocs_2._guide/node03A3.html) changes the size of a layer by modifying the
coordinates of the lower right corner of the layer.  [MoveSizeLayer()](../Includes_and_Autodocs_2._guide/node03A0.html)
changes both the size and position of a layer in a single call.

