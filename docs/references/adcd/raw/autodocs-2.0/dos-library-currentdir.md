# dos.library/CurrentDir



NAME

    CurrentDir -- Make a directory lock the current directory
SYNOPSIS

```c
    oldLock = CurrentDir( lock )
    D0                    D1

    BPTR CurrentDir(BPTR)
```
FUNCTION

```c
    CurrentDir() causes a directory associated with a lock to be made
    the current directory.  The old current directory lock is returned.

    A value of zero is a valid result here, this 0 lock represents the
    root of file system that you booted from.

    Any call that has to [Open()](../Includes_and_Autodocs_2._guide/node02D6.html) or [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html) files (etc) requires that
    the current directory be a valid lock or 0.
```
INPUTS

    lock - BCPL pointer to a lock
RESULTS

    oldLock - BCPL pointer to a lock
SEE ALSO

```c
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html), [Open()](../Includes_and_Autodocs_2._guide/node02D6.html), [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html)
```
