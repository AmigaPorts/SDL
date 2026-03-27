# dos.library/UnLock



NAME

    UnLock -- Unlock a directory or file
SYNOPSIS

```c
    UnLock( lock )
            D1

    void UnLock(BPTR)
```
FUNCTION

```c
    The filing system lock (obtained from [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html), or
    [CreateDir()](../Includes_and_Autodocs_2._guide/node028C.html)) is removed and deallocated.
```
INPUTS

    lock - BCPL pointer to a lock
NOTE

```c
    passing zero to UnLock() is harmless
```
SEE ALSO

```c
    [Lock()](../Includes_and_Autodocs_2._guide/node02C6.html), [DupLock()](../Includes_and_Autodocs_2._guide/node0297.html), [ParentOfFH()](../Includes_and_Autodocs_2._guide/node02DA.html), [DupLockFromFH()](../Includes_and_Autodocs_2._guide/node0298.html)
```
