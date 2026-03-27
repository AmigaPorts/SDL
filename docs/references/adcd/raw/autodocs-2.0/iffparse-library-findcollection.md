# iffparse.library/FindCollection



NAME

    FindCollection -- Get a pointer to the current list of collection
                      items.
SYNOPSIS

```c
    ci = FindCollection (iff, type, id)
    d0                   a0    d0   d1

    struct [CollectionItem](../Includes_and_Autodocs_2._guide/node010B.html#line104)    *ci;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
    LONG                    type, id;
```
FUNCTION

```c
    Returns a pointer to a list of [CollectionItem](../Includes_and_Autodocs_2._guide/node010B.html#line104) structures for each of
    the collection chunks of the given type encountered so far in the
    course of parsing this IFF file.  The items appearing first in the
    list will be the ones encountered most recently.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    type    - type code to search for.
    id      - identifier code to search for.
```
RESULT

    ci      - pointer to last collection chunk encountered with
              links to previous ones.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CollectionChunk()](../Includes_and_Autodocs_2._guide/node01BC.html), [CollectionChunks()](../Includes_and_Autodocs_2._guide/node01BD.html)
```
