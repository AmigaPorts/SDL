# 30 / / Creating and Using New Layers / Creating the Layers


The application must first allocate and initialize a [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) data
structure which the system uses to keep track of layers that are created,
use statements like:


```c
    struct Layer_Info *theLayerInfo;

    if (NULL != (theLayerInfo = NewLayerInfo()))
        {
        /* use Layer_Info */

        DisposeLayerInfo(theLayerInfo);
        }
```
Layers may be created in the common bit map by calling
[CreateUpfrontLayer()](../Libraries_Manual_guide/node03EF.html#line13) or [CreateBehindLayer()](../Libraries_Manual_guide/node03EF.html#line13), with a sequence such as the
following:


```c
    struct Layer      *layer;
    struct Layer_Info *theLayerInfo;
    struct BitMap     *theBitMap;

    /* requests construction of a smart refresh layer. */
    if (NULL == (layer = CreateUpfrontLayer(theLayerInfo, theBitMap,
              20, 20, 100, 80, LAYERSMART, NULL)))
        error("CreateUpfrontLayer() failed.");
    else
        {
        ; /* layer successfully created here. */
        }
```
