---
title: exec.library/Forbid
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-forbid
functions: [Forbid, Permit, Wait]
libraries: [exec.library]
---

# exec.library/Forbid

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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
    until a matching [Permit()](autodocs-2.0/exec-library-permit.md) is executed, or this task is scheduled to
    [Wait()](autodocs-2.0/exec-library-wait.md).  Interrupts are NOT disabled.

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
    the programmer must execute exactly one call to [Permit()](autodocs-2.0/exec-library-permit.md) for every
    call to Forbid().
```
WARNING

```c
    In the event of a task entering a [Wait()](autodocs-2.0/exec-library-wait.md) after a Forbid(), the system
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
    Permit, Disable, [ObtainSemaphore](autodocs-2.0/exec-library-obtainsemaphore.md), [ObtainSemaphoreShared](autodocs-2.0/exec-library-obtainsemaphoreshared.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
