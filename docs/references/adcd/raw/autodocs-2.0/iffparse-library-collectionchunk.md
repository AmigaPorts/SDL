# iffparse.library/CollectionChunk



NAME

    CollectionChunk -- declare a chunk type for collection.
SYNOPSIS

```c
    error = CollectionChunk (iff, type, id)
     d0                      a0    d0   d1

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             type;
    LONG             id;
```
FUNCTION

```c
    Installs an entry handler for chunks with the given type and id so
    that the contents of those chunks will be stored as they are
    encountered.  This is like [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html) except that more than one
    chunk of this type can be stored in lists which can be returned by
    [FindCollection()](../Includes_and_Autodocs_2._guide/node01C1.html).  The storage of these chunks still follows the
    property chunk scoping rules for IFF files so that at any given
    point, stored collection chunks will be valid in the current context.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct (does not need to be open).
    type    - type code for the chunk to declare (ex. "ILBM").
    id      - identifier for the chunk to declare (ex. "CRNG").
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CollectionChunks()](../Includes_and_Autodocs_2._guide/node01BD.html), [FindCollection()](../Includes_and_Autodocs_2._guide/node01C1.html), [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html)
```
