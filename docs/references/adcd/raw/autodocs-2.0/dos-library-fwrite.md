# dos.library/FWrite



NAME

```c
    FWrite -- Writes a number of blocks to an output (buffered) (V36)
```
SYNOPSIS

```c
    count = FWrite(fh, buf, blocklen, blocks)
    D0             D1  D2     D3        D4

    LONG FWrite(BPTR, STRPTR, ULONG, ULONG)
```
FUNCTION

    Attempts to write a number of blocks, each blocklen long, from the
    specified buffer to the output stream.  May return less than the
    number of blocks requested, if there is some error such as a full
    disk or r/w error.  This call is buffered.
INPUTS

    fh       - filehandle to use for buffered I/O
    buf      - Area to write bytes from.
    blocklen - number of bytes per block.  Must be > 0.
    blocks   - number of blocks to read.  Must be > 0.
RESULT

    count - Number of _blocks_ written.  On an error, the number of
            blocks actually written is returned.
BUGS

```c
    Doesn't clear [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) before starting.  If you want to find out
    about errors, use SetIoErr(0L) before calling.
```
SEE ALSO

```c
    [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html), [FRead()](../Includes_and_Autodocs_2._guide/node02AE.html), [FPuts()](../Includes_and_Autodocs_2._guide/node02AD.html)
```
