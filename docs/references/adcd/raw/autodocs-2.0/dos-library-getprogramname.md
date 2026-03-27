# dos.library/GetProgramName



NAME

```c
    GetProgramName -- Returns the current program name (V36)
```
SYNOPSIS

```c
    success = GetProgramName(buf, len)
    D0                       D1   D2

    BOOL GetProgramName(STRPTR, LONG)
```
FUNCTION

```c
    Extracts the program name from the CLI structure and puts it
    into the buffer.  If the buffer is too small, the name is truncated
    present, a null string is returned in the buffer, and failure from
    the call (with [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) == ERROR_OBJECT_WRONG_TYPE);
```
INPUTS

    buf     - Buffer to hold extracted name
    len     - Number of bytes of space in buffer
RESULT

    success - Success/failure indicator
SEE ALSO

```c
    [SetProgramName()](../Includes_and_Autodocs_2._guide/node02FB.html)
```
