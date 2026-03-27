# exec.library/ObtainSemaphore



NAME

    ObtainSemaphore -- gain exclusive access to a semaphore
SYNOPSIS

```c
    ObtainSemaphore(signalSemaphore)
                    A0

    void ObtainSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_2._guide/node0082.html#line40) *);
```
FUNCTION

```c
    [Signal](../Includes_and_Autodocs_2._guide/node0381.html) semaphores are used to gain exclusive access to an object.
    ObtainSemaphore is the call used to gain this access.  If another
    user currently has the semaphore locked the call will block until
    the object is available.

    If the current task already has locked the semaphore and attempts to
    lock it again the call will still succeed.  A "nesting count" is
    incremented each time the current owning task of the semaphore calls
    ObtainSemaphore().  This counter is decremented each time
    [ReleaseSemaphore()](../Includes_and_Autodocs_2._guide/node036D.html) is called.  When the counter returns to zero the
    semaphore is actually released, and the next waiting task is called.

    A queue of waiting tasks is maintained on the stacks of the waiting
    tasks.  Each will be called in turn as soon as the current task
    releases the semaphore.

    [Signal](../Includes_and_Autodocs_2._guide/node0381.html) Semaphores are different than [Procure()/Vacate()](../Includes_and_Autodocs_2._guide/node0389.html) semaphores.
    The former requires less CPU time, especially if the semaphore is
    not currently locked.  They require very little set up and user
    thought.  The latter flavor of semaphore make no assumptions about
    how they are used -- they are completely general.  Unfortunately
    they are not as efficient as signal semaphores, and require the
    locker to have done some setup before doing the call.
```
INPUT
   signalSemaphore -- an initialized signal semaphore structure

NOTE

```c
    This function preserves all registers (see BUGS).
```
BUGS

    Until V37, this function could destroy A0.
SEE ALSO

```c
    [ObtainSemaphoreShared()](../Includes_and_Autodocs_2._guide/node0364.html), [InitSemaphore()](../Includes_and_Autodocs_2._guide/node035D.html), [ReleaseSemaphore()](../Includes_and_Autodocs_2._guide/node036D.html),
    [AttemptSemaphore()](../Includes_and_Autodocs_2._guide/node0336.html), [ObtainSemaphoreList()](../Includes_and_Autodocs_2._guide/node0363.html)
```
