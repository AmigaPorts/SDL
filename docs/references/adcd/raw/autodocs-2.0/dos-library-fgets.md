# dos.library/FGets



NAME

```c
    FGets -- Reads a line from the specified input (buffered) (V36)
```
SYNOPSIS

```c
    buffer = FGets(fh, buf, len)
    D0             D1  D2   D3

    STRPTR FGets(BPTR, STRPTR, ULONG)
```
FUNCTION

    This routine reads in a single line from the specified input stopping
    at a NEWLINE character or EOF.  In either event, UP TO the number of
    len specified bytes minus 1 will be copied into the buffer.  Hence if
    a length of 50 is passed and the input line is longer than 49 bytes,
    it will return 49 characters.  It returns the buffer pointer normally,
    or NULL if EOF is the first thing read.

    If terminated by a newline, the newline WILL be the last character in
    the buffer.  This is a buffered read routine.  The string read in IS
    null-terminated.
INPUTS

    fh  - filehandle to use for buffered I/O
    buf - Area to read bytes into.
    len - Number of bytes to read, must be > 0.
RESULT

```c
    buffer - Pointer to buffer passed in, or NULL for immediate EOF or for
             an error.  If NULL is returnd for an EOF, [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html) will return
             0.
```
SEE ALSO

```c
    [FRead()](../Includes_and_Autodocs_2._guide/node02AE.html), [FPuts()](../Includes_and_Autodocs_2._guide/node02AD.html), [FGetC()](../Includes_and_Autodocs_2._guide/node02A2.html)
```
