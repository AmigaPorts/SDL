# dos.library/FPutC



NAME

```c
    FPutC -- Write a character to the specified output (buffered) (V36)
```
SYNOPSIS

```c
    char = FPutC(fh, char)
    D0           D1   D2

    LONG FPutC(BPTR, UBYTE)
```
FUNCTION

```c
    Writes a single character to the output stream.  This call is
    buffered.  Use [Flush()](../Includes_and_Autodocs_2._guide/node02AA.html) between buffered and unbuffered I/O on a
    filehandle.  Interactive filehandles are flushed automatically
    on a newline, return, '0', or line feed.
```
INPUTS

    fh   - filehandle to use for buffered I/O
    char - character to write
RESULT

    char - either the character written, or EOF for an error.
SEE ALSO

```c
    [FGetC()](../Includes_and_Autodocs_2._guide/node02A2.html), [UnGetC()](../Includes_and_Autodocs_2._guide/node0305.html), [Flush()](../Includes_and_Autodocs_2._guide/node02AA.html)
```
