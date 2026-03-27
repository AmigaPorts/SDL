# E / Release 2 Changes That Can Affect Compatibility / Layers


  * Use [NewLayerInfo()](../Libraries_Manual_guide/node03F2.html) to create, not [FattenLayerInfo()](../Includes_and_Autodocs_2._guide/node0397.html), [ThinLayerInfo()](../Includes_and_Autodocs_2._guide/node03A5.html),

```c
    [InitLayers()](../Includes_and_Autodocs_2._guide/node0398.html).
```
  * Simple-refresh preserves all of the pixels it can.  Sizing a

```c
    [SIMPLE_REFRESH](../Libraries_Manual_guide/node0125.html#line110) window no longer clears the whole window.
```
  * Speed of layer operations is different.  Don't depend on layer

    operations to finish before or after other asynchronous actions.
