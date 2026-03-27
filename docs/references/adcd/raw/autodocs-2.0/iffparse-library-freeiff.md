# iffparse.library/FreeIFF



NAME

```c
    FreeIFF -- Deallocate an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.
```
SYNOPSIS

```c
    FreeIFF (iff)
             a0

    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
```
FUNCTION

```c
    Deallocates all resources associated with this [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct.  The
    struct MUST have already been closed with [CloseIFF()](../Includes_and_Autodocs_2._guide/node01BB.html).
```
INPUTS

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) struct to free.
```
RESULT

EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [AllocIFF()](../Includes_and_Autodocs_2._guide/node01B8.html), [CloseIFF()](../Includes_and_Autodocs_2._guide/node01BB.html)
```
