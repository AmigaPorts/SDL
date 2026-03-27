# iffparse.library/CurrentChunk



NAME

    CurrentChunk -- Get context node for current chunk.
SYNOPSIS

```c
    top = CurrentChunk (iff)
    d0                  a0

    struct [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68)        *top;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)  *iff;
```
FUNCTION

```c
    Returns top context node for the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.  The top
    context node corresponds to the chunk most recently pushed on the
    stack, which is the chunk where the stream is currently positioned.
    The [ContextNode](../Includes_and_Autodocs_2._guide/node010B.html#line68) structure contains information on the type of chunk
    currently being parsed (or written), its size and the current
    position within the chunk.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
```
RESULT

    top     - pointer to top context node or NULL if none.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PushChunk()](../Includes_and_Autodocs_2._guide/node01D5.html), [PopChunk()](../Includes_and_Autodocs_2._guide/node01D2.html), [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html), [ParentChunk()](../Includes_and_Autodocs_2._guide/node01D0.html)
```
