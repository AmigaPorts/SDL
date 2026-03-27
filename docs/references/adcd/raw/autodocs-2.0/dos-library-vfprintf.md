# dos.library/VFPrintf



NAME

```c
    VFPrintf -- format and print a string to a file (buffered) (V36)
```
SYNOPSIS

```c
    count = VFPrintf(fh, fmt, argv)
    D0               D1  D2    D3

    LONG VFPrintf(BPTR, STRPTR, LONG *)

    count = FPrintf(fh, fmt, ...)

    LONG FPrintf(BPTR, STRPTR, ...)
```
FUNCTION

```c
    Writes the formatted string and values to the given file.  This
    routine is assumed to handle all internal buffering so that the
    formatting string and resultant formatted values can be arbitrarily
    long.  Any secondary error code is returned in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).  This routine
    is buffered.
```
INPUTS

```c
    fh    - Filehandle to write to
    fmt   - [RawDoFmt()](../Includes_and_Autodocs_2._guide/node036C.html) style formatting string
    argv  - Pointer to array of formatting values
```
RESULT

```c
    count - Number of bytes written or -1 (EOF) for an error
```
BUGS

```c
    The prototype for FPrintf() currently forces you to cast the first
    varargs parameter to LONG due to a deficiency in the program
    that generates fds, prototypes, and amiga.lib stubs.
```
SEE ALSO

```c
    [VPrintf()](../Includes_and_Autodocs_2._guide/node030D.html), [VFWritef()](../Includes_and_Autodocs_2._guide/node030C.html), [RawDoFmt()](../Includes_and_Autodocs_2._guide/node036C.html), [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html)
```
