# 30 / Layers / Types of Layers


The layers library supports three types of layers: simple refresh, smart
refresh and super bitmap.  The type of the layer, specified by the Flags
field in the [Layer](../Libraries_Manual_guide/node03E4.html)s structure, determines what facilities the layer
provides.


```c
    Use Only One Layer Type Flag
    ----------------------------
    The three layer-type Flags are mutually exclusive.  That is, only one
    layer-type flag (LAYERSIMPLE, LAYERSMART and LAYERSUPER) should be
    specified.
```
 [Simple Refresh Layer](../Libraries_Manual_guide/node03E7.html)    [Super Bitmap Layer](../Libraries_Manual_guide/node03E9.html) 
 [Smart Refresh Layer](../Libraries_Manual_guide/node03E8.html)     [Backdrop Layer](../Libraries_Manual_guide/node03EA.html) 

