# dos.library/UnLockDosList



NAME

```c
    UnLockDosList -- Unlocks the Dos [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) (V36)
```
SYNOPSIS

```c
    UnLockDosList(flags)
                    D1

    void UnLockDosList(ULONG)
```
FUNCTION

```c
    Unlocks the access on the Dos [Device](../Includes_and_Autodocs_2._guide/node0087.html#line25) [List](../Includes_and_Autodocs_2._guide/node007D.html#line21).  You MUST pass the same
    flags you used to lock the list.
```
INPUTS

```c
    flags - MUST be the same flags passed to (Attempt)LockDosList()
```
SEE ALSO

```c
    [AttemptLockDosList()](../Includes_and_Autodocs_2._guide/node0284.html), [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html), [Permit()](../Includes_and_Autodocs_2._guide/node0369.html)
```
