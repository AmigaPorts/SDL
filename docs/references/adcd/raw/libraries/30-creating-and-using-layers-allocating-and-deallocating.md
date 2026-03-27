# 30 / / Creating and Using Layers / Allocating and Deallocating Layers


Layers are created using the routines [CreateUpfrontLayer()](../Includes_and_Autodocs_2._guide/node0393.html)
and [CreateBehindLayer()](../Includes_and_Autodocs_2._guide/node0391.html).  CreateUpfrontLayer()
creates a layer that will appear in front of any existing layers.


```c
    struct Layer *CreateUpfrontLayer( struct Layer_Info *li,
                                      struct BitMap *bm,
                                      long x0, long y0, long x1, long y1,
                                      long flags, struct BitMap *bm2 );
```
[CreateBehindLayer()](../Includes_and_Autodocs_2._guide/node0391.html) creates a layer that appears behind existing layers,
but in front of [backdrop](../Libraries_Manual_guide/node03EA.html) layers.


```c
    struct Layer *CreateBehindLayer( struct Layer_Info *li,
                                     struct BitMap *bm,
                                     long x0, long y0, long x1, long y1,
                                     long flags, struct BitMap *bm2 );
```
Both of these routines return a pointer to a [Layer](../Libraries_Manual_guide/node03E4.html) data structure (as
defined in the include file <graphics/[layers.h](../Includes_and_Autodocs_2._guide/node00C4.html#line33)>), or NULL if the operation
was unsuccessful.


```c
    A New Layer Also Gets a RastPort.
    ---------------------------------
    When a layer is created, the routine automatically creates a
    [RastPort](../Libraries_Manual_guide/node034A.html) to go along with it.  If the layer's RastPort is passed
    to the drawing routines, drawing will be restricted to the layer.
    See "[The Layer's RastPort](../Libraries_Manual_guide/node03E5.html)" section above.
```
Use the [DeleteLayer()](../Includes_and_Autodocs_2._guide/node0394.html) call to remove a layer:


```c
    LONG DeleteLayer( long dummy, struct Layer *layer );
```
[DeleteLayer()](../Includes_and_Autodocs_2._guide/node0394.html) removes a layer from the layer list and frees the memory
allocated by the layer creation calls listed above.

