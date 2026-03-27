# iffparse.library/ReadChunkRecords



NAME

    ReadChunkRecords -- Read record elements from the current chunk into
                        a buffer.
SYNOPSIS

```c
    actual = ReadChunkRecords (iff, buf, recsize, numrec)
      d0                       a0   a1     d0       d1

    LONG             actual;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    UBYTE            *buf;
    LONG             recsize, numrec;
```
FUNCTION

```c
    Reads records from the current chunk into buffer.  Truncates attempts
    to read past end of chunk (only whole records are read; remaining
    bytes that are not of a whole record size are left unread and
    available for [ReadChunkBytes()](../Includes_and_Autodocs_2._guide/node01D6.html)).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    buf     - pointer to buffer area to receive data.
    recsize - size of data records to read.
    numrec  - number of data records to read.
```
RESULT

```c
    actual  - (positive) number of whole records read if successful or a
              (negative) IFFERR_#? error code if not successful.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [ReadChunkBytes()](../Includes_and_Autodocs_2._guide/node01D6.html), [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html), [WriteChunkRecords()](../Includes_and_Autodocs_2._guide/node01DF.html)
```
