# graphics.library/CopySBitMap



NAME

```c
    CopySBitMap --   Syncronize [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) window with contents of
                                            Super [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47)
```
SYNOPSIS

```c
    CopySBitMap( layer )
                 a0

    void CopySBitMap(struct [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) *);
```
FUNCTION

```c
    This is the inverse of [SyncSBitMap](../Includes_and_Autodocs_2._guide/node0481.html).
    Copy all bits from SuperBitMap to [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) bounds.
    This is used for those functions that do not
    want to deal with the [ClipRect](../Includes_and_Autodocs_2._guide/node00A1.html#line63) structures but do want
    to be able to work with a SuperBitMap [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33).
```
INPUTS

```c
    layer - pointer to a SuperBitMap [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33)
        The [Layer](../Includes_and_Autodocs_2._guide/node00A1.html#line33) must already be locked by the caller.
```
BUGS

SEE ALSO

```c
    [LockLayerRom()](../Includes_and_Autodocs_2._guide/node045A.html) [SyncSBitMap()](../Includes_and_Autodocs_2._guide/node0481.html)
```
