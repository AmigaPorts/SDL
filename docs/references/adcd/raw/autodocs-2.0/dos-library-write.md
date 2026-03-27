# dos.library/Write



NAME

    Write -- Write bytes of data to a file
SYNOPSIS

```c
    returnedLength =  Write( file, buffer, length )
    D0                       D1    D2      D3

    LONG Write (BPTR, void *, LONG)
```
FUNCTION

```c
    Write() writes bytes of data to the opened file 'file'. 'length'
    indicates the length of data to be transferred; 'buffer' is a
    pointer to the buffer. The value returned is the length of
    information actually written. So, when 'length' is greater than
    zero, the value of 'length' is the number of characters written.
    Errors are indicated by a value of -1.

    Note: this is an unbuffered routine (the request is passed directly
    to the filesystem.)  Buffered I/O is more efficient for small
    reads and writes; see [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html).
```
INPUTS

    file - BCPL pointer to a file handle
    buffer - pointer to the buffer
    length - integer
RESULTS

    returnedLength - integer
SEE ALSO

```c
    [Read()](../Includes_and_Autodocs_2._guide/node02E0.html), [Seek()](../Includes_and_Autodocs_2._guide/node02ED.html), [Open()](../Includes_and_Autodocs_2._guide/node02D6.html), [Close()](../Includes_and_Autodocs_2._guide/node028A.html), [FPutC](../Includes_and_Autodocs_2._guide/node02AC.html)
```
