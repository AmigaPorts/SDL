# iffparse.library/PropChunks



NAME

    PropChunks -- Declare many property chunks at once.
SYNOPSIS

```c
    error = PropChunks (iff, list, n)
     d0                 a0    a1  d0

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             *list;
    LONG             n;
```
FUNCTION

```c
    Declares multiple property chunks from a list.  The list argument is
    a pointer to an array of long words arranged in pairs, and has the
    following format:

            TYPE1, ID1, TYPE2, ID2, ..., TYPEn, IDn

    The argument n is the number of pairs.  PropChunks() just calls
    [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html) n times.
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
    [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html)
```
