# rexxsyslib.library/LockRexxBase



NAME

    LockRexxBase - Obtain a semaphore lock on the RexxBase structure
SYNOPSIS

```c
    LockRexxBase(resource)
                 D0

    VOID LockRexxBase(ULONG);
```
FUNCTION

    Secures the specified resource in the ARexx library base.
INPUTS

    resource - A manifest constant defining which resource to lock.
               ZERO locks all resources.
NOTES

    Currently, only ZERO resource type is available.  You *MUST* make
    sure that you do not call this function with an undefined value
    as it may become defined at some future date and cause unwanted
    behavior.
SEE ALSO

```c
    [UnlockRexxBase()](../Includes_and_Autodocs_2._guide/node0321.html)
```
BUGS

