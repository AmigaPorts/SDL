# iffparse.library/WriteChunkRecords



NAME

    WriteChunkRecords -- Write records from a buffer to the current
                         chunk.
SYNOPSIS

```c
    error = WriteChunkRecords (iff, buf, recsize, numrec)
     d0                        a0   a1     d0      d1

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    UBYTE            *buf;
    LONG             recsize, numrec;
```
FUNCTION

```c
    Writes record elements from the buffer into the top chunk.  This
    function operates much like [ReadChunkBytes()](../Includes_and_Autodocs_2._guide/node01D6.html).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    buf     - pointer to buffer area containing data.
    recsize - size of data records to write.
    numrec  - number of data records to write.
```
RESULT

```c
    error   - (positive) number of whole records written if successful
              or a (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [WriteChunkBytes()](../Includes_and_Autodocs_2._guide/node01DE.html)
```
