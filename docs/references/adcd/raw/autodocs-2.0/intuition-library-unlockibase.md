# intuition.library/UnlockIBase



NAME

```c
    UnlockIBase -- Surrender an Intuition lock gotten by [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html).
```
SYNOPSIS

```c
    UnlockIBase( Lock )
                 A0

    VOID UnlockIBase( ULONG );
```
FUNCTION


```c
    Surrenders lock gotten by [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html).

    Calling this function when you do not own the specified lock will
    immediately crash the system.
```
INPUTS

```c
    The value returned by [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html) should be passed to this function,
    to specify which internal lock is to be freed.

    Note that the parameter is passed in A0, not D0, for historical
    reasons.
```
RESULT

    None
BUGS

SEE ALSO

```c
    [LockIBase()](../Includes_and_Autodocs_2._guide/node0224.html)
```
