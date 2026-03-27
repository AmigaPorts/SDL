# rexxsyslib.library/FillRexxMsg



NAME

    FillRexxMsg - Fill the argument strings as needed
SYNOPSIS

```c
    result = FillRexxMsg(msgptr, count, mask)
    D0                   A0      D0     D1 [0:15]

    BOOL FillRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) *,ULONG,ULONG);
```
FUNCTION

```c
    This function will convert and install up to 16 argument strings into
    a [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) structure.  The message packet's argument fields must be
    set to either a pointer to a NULL terminated string or an integer value
    The mask, bits 0 to 15, correspond to the type of value is stored
    in the argument slot.  If the bit is cleared, the argument is a
    string pointer; if the bit is set, the argument is an integer.
```
INPUTS

```c
    msgptr - Pointer to a [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) (allocated via CreateRexxMsg)
    count - The number of argument slots to fill in.  This number should
            be from 1 to 16.

    mask - A bit mask corresponding to the 16 fields that is used to
           determine the type of the field.
```
RESULTS

    result - A boolean.  If it is TRUE, the call worked.  If it is false,
             some allocation did not work.  All argstrings that were
             created will be released.
SEE ALSO

```c
    [ClearRexxMsg()](../Includes_and_Autodocs_2._guide/node0318.html), [CreateArgstring()](../Includes_and_Autodocs_2._guide/node0319.html), [DeleteArgstring()](../Includes_and_Autodocs_2._guide/node031B.html), [CreateRexxMsg()](../Includes_and_Autodocs_2._guide/node031A.html)
```
BUGS

