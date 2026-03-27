# rexxsyslib.library/ClearRexxMsg



NAME

```c
    ClearRexxMsg - Releases and clears the argument array in a [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99)
```
SYNOPSIS

```c
    ClearRexxMsg(msgptr, count)
                 A0      D0

    VOID ClearRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) *,ULONG);
```
FUNCTION

```c
    This function will [DeleteArgstring()](../Includes_and_Autodocs_2._guide/node031B.html) one or more argstrings from
    the [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99) and clear the slot.  The count is used to select the
    number of slots to clear.
```
INPUTS

```c
    msgptr - A pointer to a [RexxMsg](../Includes_and_Autodocs_2._guide/node0127.html#line99)
    count - The number of slots to be cleared.  The number can be from
            1 to 16.  (There are 16 slots)
```
RESULTS

    All of the slots in the given count will be cleared and the argstring
    will have been released.
SEE ALSO

```c
    [FillRexxMsg()](../Includes_and_Autodocs_2._guide/node031D.html), [DeleteRexxMsg()](../Includes_and_Autodocs_2._guide/node031C.html), [DeleteArgstring()](../Includes_and_Autodocs_2._guide/node031B.html), [CreateArgstring()](../Includes_and_Autodocs_2._guide/node0319.html)
```
BUGS

