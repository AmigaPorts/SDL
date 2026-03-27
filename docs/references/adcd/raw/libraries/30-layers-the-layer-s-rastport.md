# 30 / Layers / The Layer's RastPort


When a layer is created, a [RastPort](../Libraries_Manual_guide/node034A.html) is automatically to go along with it.
The pointer to the RastPort is contained in the layer data structure.
Using this RastPort, the application may draw anywhere into the layer's
bounds rectangle.  If the application tries to draw outside of this
rectangle, the graphics routines will clip the graphics.

Here is sample code showing how to access the layer's [RastPort](../Libraries_Manual_guide/node034A.html):


```c
    struct RastPort *myRPort;
        /* allocate a RastPort pointer for each layer */

    myRPort = layer->rp;

    /* The layer's RastPort may be used with any of the graphics library
    ** calls that require this structure.  For instance, to fill layer
    ** with color:
    */
    SetRast(layer->rp, color);

    /* set up for writing text into layer */
    SetDrMd(layer->rp,JAM1);
    SetAPen(layer->rp,0);
    Move(layer->rp, 5, 7);

    /* write into layer */
    Text(layer->rp, string, strlen(string));
```
