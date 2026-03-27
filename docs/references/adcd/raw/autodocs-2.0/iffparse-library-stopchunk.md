# iffparse.library/StopChunk



NAME

```c
    StopChunk -- Declare a chunk which should cause [ParseIFF](../Includes_and_Autodocs_2._guide/node01D1.html) to return.
```
SYNOPSIS

```c
    error = StopChunk (iff, type, id)
     d0                a0    d0   d1

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             type;
    LONG             id;
```
FUNCTION

```c
    Installs an entry handler for the specified chunk which will cause
    the [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) function to return control to the caller when this
    chunk is encountered.  This is only of value when [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) is
    called with the IFFPARSE_SCAN control code.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct (need not be open).
    type    - type code for chunk to declare (ex. "ILBM").
    id      - identifier for chunk to declare (ex. "BODY").
```
RESULT

    error   - 0 if successful or an IFFERR_#? error code if not
              successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [StopChunks()](../Includes_and_Autodocs_2._guide/node01DA.html), [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html)
```
