# dos.library/DupLockFromFH



NAME

```c
    DupLockFromFH -- Gets a lock on an open file (V36)
```
SYNOPSIS

```c
    lock = DupLockFromFH(fh)
    D0                   D1

    BPTR DupLockFromFH(BPTR)
```
FUNCTION

    Obtain a lock on the object associated with fh.  Only works if the
    file was opened using a non-exclusive mode.  Other restrictions may be
    placed on success by the filesystem.
INPUTS

    fh   - Opened file for which to obtain the lock
RESULT

    lock - Obtained lock or NULL for failure
SEE ALSO

```c
    [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html), [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html)
```
