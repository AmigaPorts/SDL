# dos.library/DupLock



NAME

    DupLock -- Duplicate a lock
SYNOPSIS

```c
    lock = DupLock( lock )
    D0              D1

    BPTR DupLock(BPTR)
```
FUNCTION

```c
    DupLock() is passed a shared filing system lock.  This is the ONLY
    way to obtain a duplicate of a lock... simply copying is not
    allowed.

    Another lock to the same object is then returned.  It is not
    possible to create a copy of a exclusive lock.

    A zero return indicates failure.
```
INPUTS

    lock - BCPL pointer to a lock
RESULTS

    newLock - BCPL pointer to a lock
SEE ALSO

```c
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html), [DupLockFromFH()](../Includes_and_Autodocs_2._guide/node0298.html), [ParentOfFH()](../Includes_and_Autodocs_2._guide/node02DA.html)
```
