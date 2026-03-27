# exec.library/Forbid



NAME

    Forbid -- forbid task rescheduling.
SYNOPSIS

```c
    Forbid()

    void Forbid(void);
```
FUNCTION

```c
    Prevents other tasks from being scheduled to run by the dispatcher,
    until a matching [Permit()](../Includes_and_Autodocs_2._guide/node0369.html) is executed, or this task is scheduled to
    [Wait()](../Includes_and_Autodocs_2._guide/node038A.html).  Interrupts are NOT disabled.

    DO NOT USE THIS CALL WITHOUT GOOD JUSTIFICATION.  THIS CALL IS
    DANGEROUS!
```
RESULTS

```c
    The current task will not be rescheduled as long as it is ready to
    run.  In the event that the current task enters a wait state, other
    tasks may be scheduled.  Upon return from the wait state, the original
    task will continue to run without disturbing the Forbid().

    Calls to Forbid() nest. In order to restore normal task rescheduling,
    the programmer must execute exactly one call to [Permit()](../Includes_and_Autodocs_2._guide/node0369.html) for every
    call to Forbid().
```
WARNING

```c
    In the event of a task entering a [Wait()](../Includes_and_Autodocs_2._guide/node038A.html) after a Forbid(), the system
    "breaks" the forbidden state and runs normally until the task which
    called Forbid() is rescheduled.  If caution is not taken, this can
    cause subtle bugs, since any device or DOS call will (in effect)
    cause your task to wait.

    Forbid() is not useful or safe from within interrupt code
    (All interrupts are always higher priority than tasks, and
    interrupts are allowed to break a Forbid()).
```
NOTE

    This call is guaranteed to preserve all registers.
SEE ALSO

```c
    Permit, Disable, [ObtainSemaphore](../Includes_and_Autodocs_2._guide/node0362.html), [ObtainSemaphoreShared](../Includes_and_Autodocs_2._guide/node0364.html)
```
