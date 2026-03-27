# iffparse.library/GoodID



NAME

    GoodID -- Test if an identifier follows the IFF 85 specification.
SYNOPSIS

```c
    isok = GoodID (id)
     d0            d0

    LONG isok, id;
```
FUNCTION

    Tests the given longword identifier to see if it meets all the EA IFF
    85 specifications for a chunk ID.  If so, it returns non-zero,
    otherwise 0.
INPUTS

    id      - potential 32 bit identifier.
RESULT

    isok    - non-zero if this is a valid ID, 0 otherwise.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GoodType()](../Includes_and_Autodocs_2._guide/node01C8.html)
```
