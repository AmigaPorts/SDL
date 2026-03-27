# dos.library/PutStr



NAME

```c
    PutStr -- Writes a string the the default output (buffered) (V36)
```
SYNOPSIS

```c
    error = PutStr(str)
    D0             D1

    LONG PutStr(STRPTR)
```
FUNCTION

    This routine writes an unformatted string to the default output.  No
    newline is appended to the string and any error is returned.  This
    routine is buffered.
INPUTS

    str   - Null-terminated string to be written to default output
RESULT

    error - 0 for success, -1 for any error.  NOTE: this is opposite
            most Dos function returns!
SEE ALSO

```c
    [FPuts()](../Includes_and_Autodocs_2._guide/node02AD.html), [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html), [FWrite()](../Includes_and_Autodocs_2._guide/node02B3.html), [WriteChars()](../Includes_and_Autodocs_2._guide/node0311.html)
```
