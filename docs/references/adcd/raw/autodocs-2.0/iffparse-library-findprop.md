# iffparse.library/FindProp



NAME

    FindProp -- Search for a stored property chunk.
SYNOPSIS

```c
    sp = FindProp (iff, type, id)
    d0             a0    d0   d1

    struct [StoredProperty](../Includes_and_Autodocs_2._guide/node010B.html#line94)     *sp;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
    LONG                    type, id;
```
FUNCTION

```c
    Searches for the stored property which is valid in the given context.
    Property chunks are automatically stored by [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) when
    pre-declared by [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html) or [PropChunks()](../Includes_and_Autodocs_2._guide/node01D4.html).  The [StoredProperty](../Includes_and_Autodocs_2._guide/node010B.html#line94)
    struct, if found, contains a pointer to a data buffer containing the
    contents of the stored property.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    type    - type code for chunk to search for (ex. "ILBM").
    id      - identifier code for chunk to search for (ex. "CMAP").
```
RESULT

    sp      - pointer to stored property, if found, or NULL if none
              found.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PropChunk()](../Includes_and_Autodocs_2._guide/node01D3.html), [PropChunks()](../Includes_and_Autodocs_2._guide/node01D4.html)
```
