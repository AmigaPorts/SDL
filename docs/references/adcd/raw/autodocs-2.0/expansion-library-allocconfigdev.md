# expansion.library/AllocConfigDev



NAME

```c
    AllocConfigDev - allocate a [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structure
```
SYNOPSIS

```c
    configDev = AllocConfigDev()
    D0
```
FUNCTION

```c
    This routine returns the address of a [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structure.
    It is provided so new fields can be added to the structure
    without breaking old, existing code.  The structure is cleared
    when it is returned to the user.
```
INPUTS

RESULTS

```c
    configDev - either a valid [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structure or NULL.
```
EXCEPTIONS

SEE ALSO

```c
    [FreeConfigDev](../Includes_and_Autodocs_2._guide/node03B5.html)
```
BUGS

