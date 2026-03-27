# iffparse.library/ReadChunkBytes



NAME

    ReadChunkBytes -- Read bytes from the current chunk into a buffer.
SYNOPSIS

```c
    actual = ReadChunkBytes (iff, buf, size)
      d0                     a0   a1    d0

    LONG             actual;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    UBYTE            *buf;
    LONG             size;
```
FUNCTION

```c
    Reads the [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) stream into the buffer for the specified number
    of bytes.  Reads are limited to the size of the current chunk and
    attempts to read past the end of the chunk will truncate.  Function
    returns positive number of bytes read or a negative error code.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    buf     - pointer to buffer area to receive data.
    size    - number of bytes to read.
```
RESULT

```c
    actual  - (positive) number of bytes read if successful or a
              (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [ReadChunkRecords()](../Includes_and_Autodocs_2._guide/node01D7.html), [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html), [WriteChunkBytes()](../Includes_and_Autodocs_2._guide/node01DE.html)
```
