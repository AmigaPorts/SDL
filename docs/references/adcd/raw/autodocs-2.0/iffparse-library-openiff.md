# iffparse.library/OpenIFF



NAME

```c
    OpenIFF -- Prepare an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) to read or write a new IFF stream.
```
SYNOPSIS

```c
    error = OpenIFF (iff, rwmode)
     d0              a0     d0

    LONG             error;
    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
    LONG             rwmode;
```
FUNCTION

```c
    Initializes an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct for a new read or write.  The
    direction of the I/O is given by the value of rwmode, which can be
    either IFFF_READ or IFFF_WRITE.

    As part of its initialization procedure, OpenIFF() calls the client-
    supplied stream hook vector.  The [IFFStreamCmd](../Includes_and_Autodocs_2._guide/node010B.html#line55) packet will contain
    the following:

            sc_Command:     IFFCMD_INIT
            sc_Buf:         (Not applicable)
            sc_NBytes:      (Not applicable)

    This operation is permitted to fail.  DO NOT write to this structure.
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
    rwmode  - IFFF_READ or IFFF_WRITE
```
RESULT

    error   - contains an error code or 0 if successful.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [CloseIFF()](../Includes_and_Autodocs_2._guide/node01BB.html), [InitIFF()](../Includes_and_Autodocs_2._guide/node01CA.html)
```
