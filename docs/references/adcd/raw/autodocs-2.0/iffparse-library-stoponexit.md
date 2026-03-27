# iffparse.library/StopOnExit



NAME

    StopOnExit -- Declare a stop condition for exiting a chunk.
SYNOPSIS

```c
    error = StopOnExit (iff, type, id)
     d0                 a0    d0   d1

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             type;
    LONG             id;
```
FUNCTION

```c
    Installs an exit handler for the specified chunk which will cause the
    [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) function to return control to the caller when this chunk
    is exhausted.  [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html) will return IFFERR_EOC when the declared
    chunk is about to be popped.  This is only of value when [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html)
    is called with the IFFPARSE_SCAN control code.
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
    [ParseIFF()](../Includes_and_Autodocs_2._guide/node01D1.html)
```
