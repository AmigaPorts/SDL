# exec.library/AttemptSemaphore



NAME

    AttemptSemaphore -- try to obtain without blocking
SYNOPSIS

```c
    success = AttemptSemaphore(signalSemaphore)
    D0                         A0

    LONG AttemptSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) *);
```
FUNCTION

```c
    This call is similar to [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html), except that it will not
    block if the semaphore could not be locked.
```
INPUT
   signalSemaphore -- an initialized signal semaphore structure

RESULT

    success -- TRUE if the semaphore was locked, false if some
        other task already possessed the semaphore.
NOTE

    This call does NOT preserve registers.
SEE ALSO

```c
    [ObtainSemaphore()](../Includes_and_Autodocs_2._guide/node0362.html) [ObtainSemaphoreShared()](../Includes_and_Autodocs_2._guide/node0364.html), [ReleaseSemaphore()](../Includes_and_Autodocs_2._guide/node036D.html),
    [exec/semaphores.h](../Includes_and_Autodocs_2._guide/node0082.html)
```
