# iffparse.library/PopChunk



NAME

    PopChunk -- Pop top context node off context stack.
SYNOPSIS

```c
    error = PopChunk (iff)
     d0               a0

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
```
FUNCTION

    Pops top context chunk and frees all associated local context items.
    The function is normally called only for writing files and signals
    the end of a chunk.
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PushChunk()](../Includes_and_Autodocs_2._guide/node01D5.html)
```
