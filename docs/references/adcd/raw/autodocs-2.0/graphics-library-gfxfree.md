# graphics.library/GfxFree



NAME

```c
    GfxFree -- free a graphics extended data structure (V36)
```
SYNOPSIS

```c
    GfxFree( node );
          a0

    void GfxFree(struct [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) *);
```
FUNCTION

```c
    Free a special graphics extended data structure (each of which
    begins with an [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) structure).
```
INPUTS

```c
    node = pointer to a graphics extended data structure obtained via
           [GfxNew()](../Includes_and_Autodocs_2._guide/node044E.html).
```
RESULT

```c
    the node is deallocated from memory. graphics will dissassociate
    this special graphics extended node from any associated data
    structures, if necessary, before freeing it (see [GfxAssociate()](../Includes_and_Autodocs_2._guide/node044B.html)).
```
BUGS

```c
    an [Alert()](../Includes_and_Autodocs_2._guide/node032E.html) will be called if you attempt to free any structure
    other than a graphics extended data strucure obtained via GfxFree().
```
SEE ALSO

```c
    [graphics/gfxnodes.h](../Includes_and_Autodocs_2._guide/node00BA.html) [GfxNew()](../Includes_and_Autodocs_2._guide/node044E.html) [GfxAssociate()](../Includes_and_Autodocs_2._guide/node044B.html) GfxLookUp()
```
