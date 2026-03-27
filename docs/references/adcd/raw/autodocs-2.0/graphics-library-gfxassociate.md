# graphics.library/GfxAssociate



NAME

```c
    GfxAssociate -- associate a graphics extended node with a given pointer
                    (V36)
```
SYNOPSIS
   GfxAssociate(pointer, node);

```c
                A0       A1

    void GfxAssociate(VOID *, struct [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) *);
```
FUNCTION

```c
    Associate a special graphics extended data structure (each of which
    begins with an [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) structure)  with another structure via
    the other structure's pointer. Later, when you call GfxLookUp()
    with the other structure's pointer you may retrieve a pointer
    to this special graphics extended data structure, if it is
    available.
```
INPUTS

```c
    pointer = a pointer to a data structure.
    node = an [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) structure to associate with the pointer
```
RESULT

```c
    an association is created between the pointer and the node such
    that given the pointer the node can be retrieved via GfxLookUp().
```
BUGS

SEE ALSO

```c
    [graphics/gfxnodes.h](../Includes_and_Autodocs_2._guide/node00BA.html) [GfxNew()](../Includes_and_Autodocs_2._guide/node044E.html) [GfxFree()](../Includes_and_Autodocs_2._guide/node044C.html) GfxLookUp()
```
