# iffparse.library/ParentChunk



NAME

    ParentChunk -- Get the nesting context node for the given chunk.
SYNOPSIS

```c
    parent = ParentChunk (cn)
      d0                  a0

    struct [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68) *parent, *cn;
```
FUNCTION

```c
    Returns a context node for the chunk containing the chunk for the
    given context node.  This function effectively moves down the context
    stack into previously pushed contexts.  For example, to get a
    [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68) pointer for the enclosing FORM chunk while reading a data
    chunk, use: ParentChunk (CurrentChunk (iff)) to find this pointer.
    The [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68) structure contains information on the type of chunk
    and its size.
```
INPUTS

    cn      - pointer to a context node.
RESULT

    parent  - pointer to the enclosing context node or NULL if none.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CurrentChunk()](../Includes_and_Autodocs_2._guide/node01BE.html)
```
