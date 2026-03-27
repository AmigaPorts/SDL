# dos.library/Fault



NAME

```c
    Fault -- Returns the text associated with a DOS error code (V36)
```
SYNOPSIS

```c
    success = Fault(code, header, buffer, len)
    D0               D1     D2      D3    D4

    BOOL Fault(LONG, STRPTR, STRPTR, LONG)
```
FUNCTION

```c
    This routine obtains the error message text for the given error code.
    The header is prepended to the text of the error message, followed
    by a colon.  Puts a null-terminated string for the error message into
    the buffer.  By convention, error messages should be no longer than 80
    characters (+1 for termination), and preferably no more than 60.
    The value returned by [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) is set to the code passed in.  If there
    is no message for the error code, the message will be "Error code
    <number>n".
```
INPUTS

    code   - Error code
    header - header to output before error text
    buffer - Buffer to receive error message.
    len    - Length of the buffer.
RESULT

    success - Success/failure code.
SEE ALSO

```c
    [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html), [SetIoErr()](../Includes_and_Autodocs_2._guide/node02F8.html), [PrintFault()](../Includes_and_Autodocs_2._guide/node02DE.html)
```
