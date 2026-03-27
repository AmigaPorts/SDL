# dos.library/AttemptLockDosList



NAME

```c
    AttemptLockDosList -- Attempt to lock the Dos Lists for use (V36)
```
SYNOPSIS

```c
    dlist = AttemptLockDosList(flags)
    D0                          D1

    struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *AttemptLockDosList(ULONG)
```
FUNCTION

```c
    Locks the dos device list in preparation to walk the list.  If the
    list is 'busy' then this routine will return NULL.  See [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html)
    for more information.
```
INPUTS

    flags - Flags stating which types of nodes you want to lock.
RESULT

    dlist - Pointer to the beginning of the list or NULL.  Not a valid
            node!
SEE ALSO

```c
    [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html), [UnLockDosList()](../Includes_and_Autodocs_2._guide/node0308.html), [Forbid()](../Includes_and_Autodocs_2._guide/node0353.html), [NextDosEntry()](../Includes_and_Autodocs_2._guide/node02D5.html)
```
