# dos.library/RemAssignList



NAME

```c
    RemAssignList -- Remove an entry from a multi-dir assign (V36)
```
SYNOPSIS

```c
    success = RemAssignList(name,lock)
    D0                       D1   D2

    BOOL RemAssignList(STRPTR,BPTR)
```
FUNCTION

```c
    Removes an entry from a multi-directory assign.  The entry removed is
    the first one for which [SameLock](../Includes_and_Autodocs_2._guide/node02EC.html) with 'lock' returns that they are on
    the same object.  The lock for the entry in the list is unlocked (not
    the entry passed in).
```
INPUTS

```c
    name - Name of device to remove lock from (without trailing ':')
    lock - Lock associated with the object to remove from the list
```
RESULT

    success - Success/failure indicator.
SEE ALSO

```c
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [AssignLock()](../Includes_and_Autodocs_2._guide/node0282.html), [AssignPath()](../Includes_and_Autodocs_2._guide/node0283.html), [AssignLate()](../Includes_and_Autodocs_2._guide/node0281.html), [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html),
    [AssignAdd()](../Includes_and_Autodocs_2._guide/node0280.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html)
```
