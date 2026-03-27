---
title: 22 / The Signal System / Generating a Signal
manual: libraries
chapter: libraries
section: 22-the-signal-system-generating-a-signal
functions: [Signal, Wait]
libraries: [exec.library]
---

# 22 / The Signal System / Generating a Signal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Signals may be generated from both tasks and system interrupts with the
[Signal()](autodocs-2.0/exec-library-signal.md) function.


```c
    VOID Signal( struct Task *task, ULONG signalSet );
```
For example [Signal](autodocs-2.0/exec-library-signal.md)(tc,mask) would signal the task with the specified mask
signals.  More than one signal can be specified in the mask.  The
following example code illustrates [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) and Signal().


```c
     [signals.c](libraries/lib-examples-signals-c.md) 
```

---

## See Also

- [Signal — exec.library](../autodocs/exec.library.md#signal)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
