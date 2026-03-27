# rexxsyslib.library/UnlockRexxBase



NAME

    UnlockRexxBase - Release a semaphore lock on the RexxBase structure
SYNOPSIS

```c
    UnlockRexxBase(resource)
                   D0

    VOID UnlockRexxBase(ULONG);
```
FUNCTION

    Releases the specified resource in the ARexx library base.
INPUTS

```c
    resource - A manifest constant defining which resource to unlock.
               This value *MUST* match the value used in the matching
               [LockRexxBase()](../Includes_and_Autodocs_2._guide/node0320.html) call.
```
NOTES

```c
    Currently, only ZERO resource type is available.  You *MUST* make
    sure that you do not call this function with an undefined value
    as it may become defined at some future date and cause unwanted
    behavior.  You *MUST* make sure that you only call this function
    after a matching call to [LockRexxBase()](../Includes_and_Autodocs_2._guide/node0320.html) was made.
```
SEE ALSO

```c
    [LockRexxBase()](../Includes_and_Autodocs_2._guide/node0320.html)
```
BUGS

