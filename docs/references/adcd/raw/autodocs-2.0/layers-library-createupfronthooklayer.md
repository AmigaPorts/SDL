# layers.library/CreateUpfrontHookLayer



NAME                                                              (V36)

    CreateUpfrontHookLayer -- Create a new layer on top of existing layers,
                              using supplied callback BackFill hook.
SYNOPSIS

```c
    result = CreateUpfrontHookLayer(li,bm,x0,y0,x1,y1,flags,hook,[,bm2])
    d0                              a0 a1 d0 d1 d2 d3   d4  a3   [ a2 ]

    struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *CreateUpfrontHookLayer(struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *,
                  struct [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) *, LONG, LONG, LONG,
                  LONG, LONG, struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *, ... );
```
FUNCTION

```c
    Create a new [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) of position and size (x0,y0)->(x1,y1)
    and place it on top of all other layers.
    Make this layer of type found in flags
    Install Layer->BackFill callback hook.
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
    hook -  Layer->BackFill callback [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) which will be called
            with object == (struct [RastPort](../Includes_and_Autodocs_2._guide/node00AF.html#line55) *) result->RastPort
            and message == [ (Layer *) layer, (struct Rectangle) bounds,
                           (WORD) offsetx, (WORD) offsety ]
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

```c
    [utility/hooks.h](../Includes_and_Autodocs_2._guide/node012D.html)
```
