# dos.library/ParentDir



NAME

    ParentDir -- Obtain the parent of a directory or file
SYNOPSIS

```c
    newlock = ParentDir( lock )
    D0                   D1

    BPTR ParentDir(BPTR)
```
FUNCTION

```c
    The argument 'lock' is associated with a given file or directory.
    ParentDir() returns 'newlock' which is associated the parent
    directory of 'lock'.

    Taking the ParentDir() of the root of the current filing system
    returns a NULL (0) lock.  Note this 0 lock represents the root of
    file system that you booted from (which is, in effect, the parent
    of all other file system roots.)
```
INPUTS

    lock - BCPL pointer to a lock
RESULTS

    newlock - BCPL pointer to a lock
SEE ALSO

```c
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html), [ParentOfFH()](../Includes_and_Autodocs_2._guide/node02DA.html), [DupLockFromFH()](../Includes_and_Autodocs_2._guide/node0298.html)
```
