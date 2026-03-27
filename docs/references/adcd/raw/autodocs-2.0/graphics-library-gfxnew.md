# graphics.library/GfxNew



NAME

```c
    GfxNew -- allocate a graphics extended data structure (V36)
```
SYNOPSIS

```c
    result = GfxNew( node_type );
    d0               d0

    struct [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) *GfxNew( ULONG);
```
FUNCTION

```c
    Allocate a special graphics extended data structure (each of which
    begins with an [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) structure).  The type of structure to
    be allocated is specified by the node_type identifier.
```
INPUTS

```c
    node_type = which type of graphics extended data structure to allocate.
                (see gfxnodes.h for identifier definitions.)
```
RESULT

```c
    result = a pointer to the allocated graphics node or NULL if the
             allocation failed.
```
BUGS

SEE ALSO

```c
    [graphics/gfxnodes.h](../Includes_and_Autodocs_2._guide/node00BA.html) [GfxFree()](../Includes_and_Autodocs_2._guide/node044C.html) [GfxAssociate()](../Includes_and_Autodocs_2._guide/node044B.html) GfxLookUp()
```
