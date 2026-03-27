# graphics.library/SyncSBitMap



NAME

```c
    SyncSBitMap --   Syncronize Super [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) with whatever is
                     in the standard [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) bounds.
```
SYNOPSIS

```c
    SyncSBitMap( layer )
                  a0

    void SyncSBitMap( struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) * );
```
FUNCTION

```c
    Copy all bits from ClipRects in [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) into Super [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47)
    [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47).  This is used for those functions that do not
    want to deal with the [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) structures but do want
    to be able to work with a SuperBitMap [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33).
```
INPUTS

```c
    layer - pointer to a [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) that has a SuperBitMap
            The [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) should already be locked by the caller.
```
RESULT

```c
    After calling this function, the programmer can manipulate
    the bits in the superbitmap associated with the layer.
    Afterwards, the programmer should call [CopySBitMap](../Includes_and_Autodocs_2._guide/node0431.html) to
    copy the bits back into the onscreen layer.
```
BUGS

SEE ALSO

```c
    [CopySBitMap()](../Includes_and_Autodocs_2._guide/node0431.html) [graphics/clip.h](../Includes_and_Autodocs_2._guide/node00A1.html)
```
