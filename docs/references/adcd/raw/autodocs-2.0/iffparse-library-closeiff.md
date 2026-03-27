# iffparse.library/CloseIFF



NAME

    CloseIFF -- Close an IFF context.
SYNOPSIS

```c
    CloseIFF (iff)
              a0

    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
```
FUNCTION

```c
    Completes an IFF read or write operation by closing the IFF context
    established for this [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.  The [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct itself
    is left ready for re-use and a new context can be opened with
    [OpenIFF()](../Includes_and_Autodocs_2._guide/node01CF.html).  This function can be used for cleanup if a read or write
    fails partway through.

    As part of its cleanup operation, CloseIFF() calls the client-
    supplied stream hook vector.  The [IFFStreamCmd](../Includes_and_Autodocs_2._guide/node010B.html#line55) packet will be set
    as follows:

            sc_Command:     IFFCMD_CLEANUP
            sc_Buf:         (Not applicable)
            sc_NBytes:      (Not applicable)

    This operation is NOT permitted to fail;  any error code returned
    will be ignored (best to return 0, though).  DO NOT write to this
    structure.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct previously opened with
              [OpenIFF()](../Includes_and_Autodocs_2._guide/node01CF.html).
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [OpenIFF()](../Includes_and_Autodocs_2._guide/node01CF.html), [InitIFF()](../Includes_and_Autodocs_2._guide/node01CA.html)
```
