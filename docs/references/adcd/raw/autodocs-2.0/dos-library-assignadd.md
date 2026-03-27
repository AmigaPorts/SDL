# dos.library/AssignAdd



NAME

```c
    AssignAdd -- Adds a lock to an assign for multi-directory assigns (V36)
```
SYNOPSIS

```c
    success = AssignAdd(name,lock)
    D0                   D1   D2

    BOOL AssignAdd(STRPTR,BPTR)
```
FUNCTION

```c
    Adds a lock to an assign, making or adding to a multi-directory
    assign.  Note that this only will succeed on an assign created with
    [AssignLock()](../Includes_and_Autodocs_2._guide/node0282.html), or an assign created with [AssignLate()](../Includes_and_Autodocs_2._guide/node0281.html) which has been
    resolved (converted into a AssignLock()-assign).

    NOTE: you should not use the lock in any way after making this call
    successfully.  It becomes the part of the assign, and will be unlocked
    by the system when the assign is removed.  If you need to keep the
    lock, pass a lock from [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html) to [AssignLock()](../Includes_and_Autodocs_2._guide/node0282.html).
```
INPUTS

```c
    name - Name of device to assign lock to (without trailing ':')
    lock - Lock associated with the assigned name
```
RESULT

    success - Success/failure indicator.  On failure, the lock is not
              unlocked.
SEE ALSO

```c
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [AssignLock()](../Includes_and_Autodocs_2._guide/node0282.html), [AssignPath()](../Includes_and_Autodocs_2._guide/node0283.html), [AssignLate()](../Includes_and_Autodocs_2._guide/node0281.html), [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html),
    [RemAssignList()](../Includes_and_Autodocs_2._guide/node02E5.html)
```
