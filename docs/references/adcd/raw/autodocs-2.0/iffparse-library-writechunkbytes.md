# iffparse.library/WriteChunkBytes



NAME

    WriteChunkBytes -- Write data from a buffer into the current chunk.
SYNOPSIS

```c
    error = WriteChunkBytes (iff, buf, size)
     d0                      a0   a1    d0

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    UBYTE            *buf;
    LONG             size;
```
FUNCTION

    Writes "size" bytes from the specified buffer into the current chunk.
    If the current chunk was pushed with IFFSIZE_UNKNOWN, the size of the
    chunk gets increased by the size of the buffer written.  If the size
    was specified for this chunk, attempts to write past the end of the
    chunk will be truncated.
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    buf     - pointer to buffer area with bytes to be written.
    size    - number of bytes to write.
```
RESULT

```c
    error   - (positive) number of bytes written if successful or a
              (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [PushChunk()](../Includes_and_Autodocs_2._guide/node01D5.html), [PopChunk()](../Includes_and_Autodocs_2._guide/node01D2.html), [WriteChunkRecords()](../Includes_and_Autodocs_2._guide/node01DF.html)
```
