# dos.library/FGetC



NAME

```c
    FGetC -- Read a character from the specified input (buffered) (V36)
```
SYNOPSIS

```c
    char = FGetC(fh)
    D0           D1

    LONG FGetC(BPTR)
```
FUNCTION

```c
    Reads the next character from the input stream.  A -1 is
    returned when EOF or an error is encountered.  This call is buffered.
    Use [Flush()](../Includes_and_Autodocs_2._guide/node02AA.html) between buffered and unbuffered I/O on a filehandle.
```
INPUTS

    fh - filehandle to use for buffered I/O
RESULT

```c
    char - character read (0-255) or -1
```
BUGS

```c
    In V36, after an EOF was read, EOF would always be returned from
    FGetC() from then on.  Starting in V37, it tries to read from the
    handler again each time (unless UnGetC(fh,-1) was called).
```
SEE ALSO

```c
    [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html), [UnGetC()](../Includes_and_Autodocs_2._guide/node0305.html), [Flush()](../Includes_and_Autodocs_2._guide/node02AA.html)
```
