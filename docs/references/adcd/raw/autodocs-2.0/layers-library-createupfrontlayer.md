# layers.library/CreateUpfrontLayer



NAME

    CreateUpfrontLayer -- Create a new layer on top of existing layers.
SYNOPSIS

```c
    result = CreateUpfrontLayer(li,bm,x0,y0,x1,y1,flags [,bm2])
    d0                          a0 a1 d0 d1 d2 d3   d4  [ a2 ]

    struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *CreateUpfrontLayer(struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *, struct [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) *,
        LONG, LONG, LONG, LONG, LONG, ... );
```
FUNCTION

```c
    Create a new [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) of position and size (x0,y0)->(x1,y1)
    and place it on top of all other layers.
    Make this layer of type found in flags
    if SuperBitMap, use bm2 as pointer to real SuperBitMap.
    and copy contents of Superbitmap into display layer.

    Note: when using SUPERBITMAP, you should also set LAYERSMART flag.
```
INPUTS

```c
    li - pointer to LayerInfo structure
    bm - pointer to common [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) used by all Layers
    x0,y0 - upper left hand corner of layer
    x1,y1 - lower right hand corner of layer
    flags - various types of layers supported as bit sets.
    bm2 - pointer to optional Super [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47)
```
RESULTS

```c
    result - pointer to [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) structure if successful
             NULL if not successful
```
BUGS

SEE ALSO
   [DeleteLayer](../Includes_and_Autodocs_2._guide/node0394.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html), [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html), [graphics/gfx.h](../Includes_and_Autodocs_2._guide/node00A6.html)

