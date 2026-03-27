---
title: exec.library/Wait
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-wait
functions: [Disable, Forbid, Wait]
libraries: [exec.library]
---

# exec.library/Wait

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Wait -- wait for one or more signals
SYNOPSIS

```c
    signals = Wait(signalSet)
    D0             D0

    ULONG Wait(ULONG);
```
FUNCTION

```c
    This function will cause the current task to suspend waiting for
    one or more signals.  When one or more of the specified signals
    occurs, the task will return to the ready state, and those signals
    will be cleared.

    If a signal occurred prior to calling Wait(), the wait condition will
    be immediately satisfied, and the task will continue to run without
    delay.
```
CAUTION

```c
    This function cannot be called while in supervisor mode or
    interrupts!  This function will break the action of a [Forbid()](autodocs-2.0/exec-library-forbid.md) or
    [Disable()](autodocs-2.0/exec-library-disable.md) call.
```
INPUT

    signalSet - The set of signals for which to wait.
                Each bit represents a particular signal.
RESULTS

    signals - the set of signals that were active

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
