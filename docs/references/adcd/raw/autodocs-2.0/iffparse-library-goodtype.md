# iffparse.library/GoodType



NAME

    GoodType -- Test if a type follows the IFF 85 specification.
SYNOPSIS

```c
    isok = GoodType (type)
     d0               d0

    LONG isok, type;
```
FUNCTION

```c
    Tests the given longword type identifier to see if it meets all the
    EA IFF 85 specifications for a FORM type (requirements for a FORM
    type are more stringent than those for a simple chunk ID).  If it
    complies, GoodType() returns non-zero, otherwise 0.
```
INPUTS

    type    - potential 32 bit format type identifier.
RESULT

    isok    - non-zero if this is a valid type id, 0 otherwise.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [GoodID()](../Includes_and_Autodocs_2._guide/node01C7.html)
```
