# graphics.library/InitBitMap



NAME

    InitBitMap -- Initialize bit map structure with input values.
SYNOPSIS

```c
    InitBitMap( bm, depth, width, height )
                a0   d0     d1      d2

    void InitBitMap( struct [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) *, BYTE, UWORD, UWORD );
```
FUNCTION

```c
    Initialize various elements in the [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) structure to
    correctly reflect depth, width, and height.
    Must be used before use of [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) in other graphics calls.
    The Planes[8] are not initialized and need to be set up
    by the caller.  The Planes table was put at the end of the
    structure so that it may be truncated to conserve space,
    as well as extended. All routines that use [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) should
    only depend on existence of depth number of bitplanes.
    The Flagsh and pad fields are reserved for future use and
    should not be used by application programs.
```
INPUTS

```c
    bm - pointer to a [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47) structure (gfx.h)
    depth - number of bitplanes that this bitmap will have
    width - number of bits (columns) wide for this [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47)
    height- number of bits (rows) tall for this [BitMap](../Includes_and_Autodocs_2._guide/node00A6.html#line47)
```
BUGS

SEE ALSO

```c
    [graphics/gfx.h](../Includes_and_Autodocs_2._guide/node00A6.html)
```
