# iffparse.library/InitIFFasDOS



NAME

```c
    InitIFFasDOS -- Initialize an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) as a DOS stream.
```
SYNOPSIS

```c
    InitIFFasDOS (iff)
                  a0

    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
```
FUNCTION

```c
    The function initializes the given [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) to operate on DOS
    streams.  The iff_Stream field will need to be initialized as a BPTR
    returned from the DOS function [Open()](../Includes_and_Autodocs_2._guide/node02D6.html).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

