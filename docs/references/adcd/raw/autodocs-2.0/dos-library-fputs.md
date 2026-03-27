# dos.library/FPuts



NAME

```c
    FPuts -- Writes a string the the specified output (buffered) (V36)
```
SYNOPSIS

```c
    error = FPuts(fh, str)
    D0            D1  D2

    LONG FPuts(BPTR, STRPTR)
```
FUNCTION

    This routine writes an unformatted string to the filehandle.  No
    newline is appended to the string and the length actually written is
    returned.  This routine is buffered.
INPUTS

    fh    - filehandle to use for buffered I/O
    str   - Null-terminated string to be written to default output
RESULT

    error - 0 normally, otherwise -1.  Note that this is opposite of
            most other Dos functions, which return success.
SEE ALSO

```c
    [FGets()](../Includes_and_Autodocs_2._guide/node02A3.html), [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html), [FWrite()](../Includes_and_Autodocs_2._guide/node02B3.html), [PutStr()](../Includes_and_Autodocs_2._guide/node02DF.html)
```
