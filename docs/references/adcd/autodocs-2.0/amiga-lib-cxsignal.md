---
title: amiga.lib/CxSignal
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-cxsignal
functions: [AllocSignal, CreateCxObj, FindTask, Signal]
libraries: [commodities.library, exec.library]
---

# amiga.lib/CxSignal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    CxSignal -- create a commodity signaller object. (V36)
```
SYNOPSIS

```c
    signalerObj = CxSignal(task,signal);

    CxObj *CxSignal(struct [Task](autodocs-2.0/includes-exec-tasks-h.md) *,LONG);
```
FUNCTION

```c
    This function creates a Commodities signal object. The action
    of this object on receiving a Commodities message is to
    send the 'signal' to the 'task'. The caller is responsible
    for allocating the signal and determining the proper task ID.

    Note that 'signal' is the signal value as returned by [AllocSignal()](autodocs-2.0/exec-library-allocsignal.md),
    not the mask made from that value.

    This function is a C-language macro for [CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), defined
    in [<libraries/commodities.h>](autodocs-2.0/includes-libraries-commodities-h.md).
```
INPUTS

    task - the task for the signaller to signal
    signal - the signal bit number for the signaller to send
RESULTS

    signallerObj - a pointer to the signaller object, or NULL if it could
                   not be created.
SEE ALSO

```c
    [commodities.library/CreateCxObj()](autodocs-2.0/commodities-library-createcxobj.md), [exec.library/FindTask()](autodocs-2.0/exec-library-findtask.md)
    [exec.library/Signal()](autodocs-2.0/exec-library-signal.md), [exec.library/AllocSignal()](autodocs-2.0/exec-library-allocsignal.md),
```

---

## See Also

- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [FindTask — exec.library](../autodocs/exec.library.md#findtask)
- [Signal — exec.library](../autodocs/exec.library.md#signal)
