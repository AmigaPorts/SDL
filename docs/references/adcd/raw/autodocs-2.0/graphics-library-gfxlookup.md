# graphics.library/GfxLookUP



NAME

```c
    GfxLookUp -- find a graphics extended node associated with a
                 given pointer (V36)
```
SYNOPSIS

```c
    result = GfxLookUp( pointer );
      d0                   a0

    struct [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) *GfxLookUp( void *);
```
FUNCTION

```c
    Finds a special graphics extended data structure (if any) associated
    with the pointer to a data structure (eg: [ViewExtra](../Includes_and_Autodocs_2._guide/node00B8.html#line69) associated with
    a [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) structure).
```
INPUTS

```c
    pointer = a pointer to a data structure which may have an
              [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) associated with it (typically a [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57) ).
```
RESULT

```c
    result = a pointer to the [ExtendedNode](../Includes_and_Autodocs_2._guide/node00BA.html#line18) that has previously been
             associated with the pointer.
```
BUGS

SEE ALSO

```c
    [graphics/gfxnodes.h](../Includes_and_Autodocs_2._guide/node00BA.html) [GfxNew()](../Includes_and_Autodocs_2._guide/node044E.html) [GfxFree()](../Includes_and_Autodocs_2._guide/node044C.html) [GfxAssociate()](../Includes_and_Autodocs_2._guide/node044B.html)
```
