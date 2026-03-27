# layers.library/DisposeLayerInfo



NAME

    DisposeLayerInfo -- Return all memory for LayerInfo to memory pool
SYNOPSIS

```c
    DisposeLayerInfo( li )
                      a0

    void DisposeLayerInfo( struct [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) *);
```
FUNCTION

```c
    return LayerInfo and any other memory attached to this LayerInfo
    to memory allocator.

    Note: if you wish to delete the layers associated with this [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33)
        structure, remember to call [DeleteLayer()](../Includes_and_Autodocs_2._guide/node0394.html) for each of the layers
        before calling DisposeLayerInfo().
```
INPUTS

    li - pointer to LayerInfo structure
EXAMPLE



```c
    --delete the layers associated this [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure--

    DeleteLayer(li,simple_layer);
    DeleteLayer(li,smart_layer);

    --see documentation on [DeleteLayer](../Includes_and_Autodocs_2._guide/node0394.html) about deleting SuperBitMap layers--
    my_super_bitmap_ptr = super_layer->SuperBitMap;
    DeleteLayer(li,super_layer);

    --now dispose of the [Layer_Info](../Includes_and_Autodocs_2._guide/node00C4.html#line33) structure itself--
    DisposeLayerInfo(li);
```
BUGS

SEE ALSO

```c
    [DeleteLayer](../Includes_and_Autodocs_2._guide/node0394.html), [graphics/layers.h](../Includes_and_Autodocs_2._guide/node00C4.html)
```
