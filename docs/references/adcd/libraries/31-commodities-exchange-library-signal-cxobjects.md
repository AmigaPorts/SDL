---
title: 31 Commodities Exchange Library / Signal CxObjects
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-signal-cxobjects
functions: [AllocSignal]
libraries: [exec.library]
---

# 31 Commodities Exchange Library / Signal CxObjects

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A commodity can use a [sender CxObject](libraries/31-commodities-exchange-library-sender-cxobjects.md) to find out if a [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) has
"visited" a [CxObject](libraries/31-commodities-exchange-filter-objects-and-input.md), but this method unnecessarily uses system resources.
A commodity that is only interested in knowing if such a visitation took
place does not need to see a corresponding input event or a CxMessage ID.
Instead, Commodities Exchange has a CxObject that uses an Exec signal.


```c
    signalCxObj = CxObj  *CxSignal(struct Task *, LONG cx_signal);
```
[CxSignal()](autodocs-2.0/amiga-lib-cxsignal.md) sets up a signal [CxObject](libraries/31-commodities-exchange-library-cxobjects.md).  When a signal CxObject receives a
[CxMessage](libraries/31-commodities-exchange-library-cxmessages.md), it signals a task.  The commodity is responsible for
determining the proper task ID and allocating the signal.  Normally, a
commodity wants to be signalled so it uses [FindTask](libraries/21-exec-tasks-function-reference.md)(NULL) to find it's own
task address.  Note that cx_signal from the above prototype is the signal
number as returned by [AllocSignal()](libraries/22-the-signal-system-signal-allocation.md), not the signal mask made from that
number.  For more information on signals, see the "[Exec Signals](libraries/22-exec-signals.md)" chapter.

The example [Divert.c](libraries/lib-examples-divert-c.md) (shown a little later in this chapter) uses a signal
[CxObject](libraries/31-commodities-exchange-library-cxobjects.md).

---

## See Also

- [AllocSignal — exec.library](../autodocs/exec.library.md#allocsignal)
