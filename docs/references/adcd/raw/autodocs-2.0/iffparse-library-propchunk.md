# iffparse.library/PropChunk



NAME

    PropChunk -- Specify a property chunk to store.
SYNOPSIS

```c
    error = PropChunk (iff, type, id)
     d0                a0    d0   d1

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             type;
    LONG             id;
```
FUNCTION

```c
    Installs an entry handler for chunks with the given type and ID so
    that the contents of those chunks will be stored as they are
    encountered.  The storage of these chunks follows the property chunk
    scoping rules for IFF files so that at any given point, a stored
    property chunk returned by [FindProp()](../Includes_and_Autodocs_2._guide/node01C3.html) will be the valid property for
    the current context.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct (does not need to be open).
    type    - type code for the chunk to declare (ex. "ILBM").
    id      - identifier for the chunk to declare (ex. "CMAP").
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PropChunks()](../Includes_and_Autodocs_2._guide/node01D4.html), [FindProp()](../Includes_and_Autodocs_2._guide/node01C3.html), [CollectionChunk()](../Includes_and_Autodocs_2._guide/node01BC.html)
```
