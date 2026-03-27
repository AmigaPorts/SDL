# dos.library/ParentOfFH



NAME

```c
    ParentOfFH -- returns a lock on the parent directory of a file (V36)
```
SYNOPSIS

```c
    lock = ParentOfFH(fh)
    D0               D1

    BPTR ParentOfFH(BPTR)
```
FUNCTION

    Returns a shared lock on the parent directory of the filehandle.
INPUTS

    fh   - Filehandle you want the parent of.
RESULT

    lock - Lock on parent directory of the filehandle or NULL for failure.
SEE ALSO

```c
    Parent(), [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html) [DupLockFromFH()](../Includes_and_Autodocs_2._guide/node0298.html)
```
