# dos.library/VPrintf



NAME

```c
    VPrintf -- format and print string (buffered) (V36)
```
SYNOPSIS

```c
    count = VPrintf(fmt, argv)
      D0            D1   D2

    LONG VPrintf(STRPTR, LONG *)

    count = Printf(fmt, ...)

    LONG Printf(STRPTR, ...)
```
FUNCTION

```c
    Writes the formatted string and values to [Output()](../Includes_and_Autodocs_2._guide/node02D8.html).  This routine is
    assumed to handle all internal buffering so that the formatting string
    and resultant formatted values can be arbitrarily long.  Any secondary
    error code is returned in [IoErr()](../Includes_and_Autodocs_2._guide/node02C2.html).  This routine is buffered.

    Note: [RawDoFmt](../Includes_and_Autodocs_2._guide/node036C.html) assumes 16 bit ints, so you will usually need 'l's in
    your formats (ex: %ld versus %d).
```
INPUTS

```c
    fmt   - exec.library [RawDoFmt()](../Includes_and_Autodocs_2._guide/node036C.html) style formatting string
    argv  - Pointer to array of formatting values
```
RESULT

```c
    count - Number of bytes written or -1 (EOF) for an error
```
BUGS

```c
    The prototype for Printf() currently forces you to cast the first
    varargs parameter to LONG due to a deficiency in the program
    that generates fds, prototypes, and amiga.lib stubs.
```
SEE ALSO

```c
    [VFPrintf()](../Includes_and_Autodocs_2._guide/node030B.html), [VFWritef()](../Includes_and_Autodocs_2._guide/node030C.html), [RawDoFmt()](../Includes_and_Autodocs_2._guide/node036C.html), [FPutC()](../Includes_and_Autodocs_2._guide/node02AC.html)
```
