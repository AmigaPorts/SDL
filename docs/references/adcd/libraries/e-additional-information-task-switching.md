---
title: E / Additional Information / Task Switching
manual: libraries
chapter: libraries
section: e-additional-information-task-switching
functions: [Wait]
libraries: [exec.library]
---

# E / Additional Information / Task Switching

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The 1.3 Kickstart contained two task switching bugs.  After an interrupt,
a task could lose the CPU to another equal priority task, even if the
first task's time was not up.  The second bug allowed a task whose time
was up to hold on to the CPU either forever, or until a higher priority
task was scheduled.  Two busy-waiting tasks at high priority would never
share the CPU.  Because the input.device runs at priority 20, usually the
effect of these bugs was masked out for low priority tasks.  The
[ExecBase->Quantum](autodocs-2.0/includes-exec-execbase-h.md) field had little effect because of the bugs.

For 2.0, a task runs until either its [Quantum](autodocs-2.0/includes-exec-execbase-h.md) is up, or a higher priority
task preempts it.  When the Quantum time is up, the task will now lose the
CPU.  The Quantum was set to 16/60 second for 1.3, and 4/60 second for 2.0.

In general, the 2.0 change makes the system more efficient by eliminating
unnecessary task switches on interrupt-busy systems (for example, during
serial input).  However, the change has caused problems for some programs
that use two tasks of equal priority, one busy-waiting and one [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md)ing
on events such as serial input.  Previously, each incoming serial
character interrupt would cause task context switch allowing the
event-handling task to run immediately.  Under 2.0 the two tasks share the
processor fairly.

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
