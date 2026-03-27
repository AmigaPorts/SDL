# exec.library/ReleaseSemaphore



NAME

    ReleaseSemaphore -- make signal semaphore available to others
SYNOPSIS

```c
    ReleaseSemaphore(signalSemaphore)
                     A0

    void ReleaseSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) *);
```
FUNCTION

```c
    ReleaseSemaphore() is the inverse of [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html). It makes
    the semaphore lockable to other users.  If tasks are waiting for
    the semaphore and this this task is done with the semaphore then
    the next waiting task is signalled.

    Each [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html) call must be balanced by exactly one
    ReleaseSemaphore() call.  This is because there is a nesting count
    maintained in the semaphore of the number of times that the current
    task has locked the semaphore. The semaphore is not released to
    other tasks until the number of releases matches the number of
    obtains.

    Needless to say, havoc breaks out if the task releases more times
    than it has obtained.
```
INPUT
   signalSemaphore -- an initialized signal semaphore structure

NOTE

    This call is guaranteed to preserve all registers.
SEE ALSO

```c
    [InitSemaphore()](../Includes_and_Autodocs_2._guide/node035D.html), [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html), [ObtainSemaphoreShared()](../Includes_and_Autodocs_2._guide/node0364.html)
```
