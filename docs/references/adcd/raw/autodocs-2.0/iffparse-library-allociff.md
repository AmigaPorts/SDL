# iffparse.library/AllocIFF



NAME

```c
    AllocIFF -- Create a new [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) structure.
```
SYNOPSIS

```c
    iff = AllocIFF ()
    d0

    struct [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) *iff;
```
FUNCTION

```c
    Allocates a new [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) structure and initializes the basic values.
    This function is the only supported way to create an [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34)
    structure since there are private fields that need to be initialized.
```
INPUTS

RESULT

```c
    iff     - pointer to [IFFHandle](../Includes_and_Autodocs_2._guide/node010B.html#line34) structure or NULL if the allocation
              failed.
```
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FreeIFF()](../Includes_and_Autodocs_2._guide/node01C5.html)
```
