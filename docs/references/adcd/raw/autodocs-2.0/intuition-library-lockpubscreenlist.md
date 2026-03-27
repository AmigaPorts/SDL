# intuition.library/LockPubScreenList



NAME

```c
    LockPubScreenList -- Prevent changes to the system list. (V36)
```
SYNOPSIS

```c
    [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) = LockPubScreenList()
    D0

    struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *LockPubScreenList( VOID );
```
FUNCTION

```c
    Arbitrates access to public screen list while you quickly
    make a copy of it for display to the user.

    Note that this is intended only for the Public [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) Manager
    program.
```
NOTES

```c
    The nodes on the list are [PubScreenNode](../Includes_and_Autodocs_2._guide/node00DD.html#line381) structures.
    Act quickly while holding this lock.  The restrictions
    on [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html) apply here as well.
```
INPUTS

    None.
RESULT

    A pointer to the public screen list.
BUGS

SEE ALSO

```c
    [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html), Intuition V36 update documentation
```
