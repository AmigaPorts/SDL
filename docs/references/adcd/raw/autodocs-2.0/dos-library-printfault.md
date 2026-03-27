# dos.library/PrintFault



NAME

```c
    PrintFault -- Returns the text associated with a DOS error code (V36)
```
SYNOPSIS

```c
    success = PrintFault(code, header)
    D0                    D1     D2

    BOOL PrintFault(LONG, STRPTR)
```
FUNCTION

```c
    This routine obtains the error message text for the given error code.
    This is similar to the [Fault()](../Includes_and_Autodocs_2._guide/node02A1.html) function, except that the output is
    written to the default output channel with buffered output.
    The value returned by [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) is set to the code passed in.
```
INPUTS

    code   - Error code
    header - header to output before error text
RESULT

    success - Success/failure code.
SEE ALSO

```c
    [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html), [Fault()](../Includes_and_Autodocs_2._guide/node02A1.html), [SetIoErr()](../Includes_and_Autodocs_2._guide/node02F8.html), [Output()](../Includes_and_Autodocs_2._guide/node02D8.html), [FPuts()](../Includes_and_Autodocs_2._guide/node02AD.html)
```
