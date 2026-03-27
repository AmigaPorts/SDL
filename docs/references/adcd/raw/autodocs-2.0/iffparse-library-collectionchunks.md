# iffparse.library/CollectionChunks



NAME

    CollectionChunks -- Declare many collection chunks at once.
SYNOPSIS

```c
    error = CollectionChunks (iff, list, n)
     d0                       a0    a1  d0

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             *list;
    LONG             n;
```
FUNCTION

```c
    Declares multiple collection chunks from a list.  The list argument
    is a pointer to an array of long words arranged in pairs.  The format
    for the list is as follows:

            TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

    The argument n is the number of pairs.  CollectionChunks() just calls
    [CollectionChunk()](../Includes_and_Autodocs_2._guide/node01BC.html) n times.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    list    - pointer to array of longword chunk types and identifiers.
    n       - number of chunks to declare.
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CollectionChunk()](../Includes_and_Autodocs_2._guide/node01BC.html)
```
