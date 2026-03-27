# dos.library/WriteChars



NAME

```c
    WriteChars -- Writes bytes to the the default output (buffered) (V36)
```
SYNOPSIS

```c
    count = WriteChars(buf, buflen)
    D0                 D1

    LONG WriteChars(STRPTR, LONG)
```
FUNCTION

    This routine writes a number of bytes to the default output.  The
    length is returned.  This routine is buffered.
INPUTS

    buf    - buffer of characters to write
    buflen - number of characters to write
RESULT

```c
    count - Number of bytes written.  -1 (EOF) indicates an error
```
SEE ALSO

```c
    [FPuts()](../Includes_and_Autodocs_2._guide/node02AD.html), [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html), [FWrite()](../Includes_and_Autodocs_2._guide/node02B3.html), [PutStr()](../Includes_and_Autodocs_2._guide/node02DF.html)
```
