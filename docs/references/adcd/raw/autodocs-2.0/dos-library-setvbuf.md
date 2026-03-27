# dos.library/SetVBuf



NAME

```c
    SetVBuf -- set buffering modes and size (V36)
```
SYNOPSIS

```c
    error = SetVBuf(fh, buff, type, size)
    D0              D1   D2    D3    D4

    LONG SetVBuf(BPTR, STRPTR, LONG, LONG)
```
FUNCTION

```c
    Changes the buffering modes and buffer size for a filehandle.
    With buff == NULL, the current buffer will be deallocated and a
    new one of (approximately) size will be allocated.  If buffer is
    non-NULL, it will be used for buffering and must be at least
    max(size,208) bytes long.  If buff is NULL and size is -1,
    then only the buffering mode will be changed.
```
INPUTS

```c
    fh   - Filehandle
    buff - buffer pointer for buffered I/O
    type - buffering mode (see [<dos/stdio.h>](../Includes_and_Autodocs_2._guide/node006B.html))
    size - size of buffer for buffered I/O (sizes less than 208 bytes
           will be ignored).
```
RESULT

    error - 0 if successful.  NOTE: opposite of most dos functions!
BUGS

    Not implemented yet, always returns 0.
SEE ALSO

```c
    FputC(), [FGetC()](../Includes_and_Autodocs_2._guide/node02A2.html), [UnGetC()](../Includes_and_Autodocs_2._guide/node0305.html), [Flush()](../Includes_and_Autodocs_2._guide/node02AA.html), [FRead()](../Includes_and_Autodocs_2._guide/node02AE.html), [FWrite()](../Includes_and_Autodocs_2._guide/node02B3.html), [FGets()](../Includes_and_Autodocs_2._guide/node02A3.html),
    [FPuts()](../Includes_and_Autodocs_2._guide/node02AD.html).
```
