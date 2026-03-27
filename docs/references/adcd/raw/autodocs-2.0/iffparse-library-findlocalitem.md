# iffparse.library/FindLocalItem



NAME

    FindLocalItem -- Return a local context item from the context stack.
SYNOPSIS

```c
    lci = FindLocalItem (iff, type, id, ident)
    d0                   a0    d0   d1   d2

    struct [LocalContextItem](../Includes_and_Autodocs_2._guide/node010B.html#line82)   *lci;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
    LONG                    type, id, ident;
```
FUNCTION

```c
    Searches the context stack of the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct for a local
    context item which matches the given ident, type and id.  This
    function searches the context stack from the most current context
    backwards, so that the item found (if any) will be the one with
    greatest precedence in the context stack.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    type    - type code to search for.
    id      - ID code to search for.
    ident   - ident code for the class of context item to search for
              (ex. "exhd" -- exit handler).
```
RESULT

    lci     - pointer local context item if found, or NULL if nothing
              matched.
EXAMPLE

NOTES

BUGS

    It really should have some sort of wildcarding capability.
SEE ALSO

```c
    [StoreLocalItem()](../Includes_and_Autodocs_2._guide/node01DD.html)
```
