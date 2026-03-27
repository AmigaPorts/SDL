---
title: 21 / Task Exclusion / Forbidding Task Switching
manual: libraries
chapter: libraries
section: 21-task-exclusion-forbidding-task-switching
functions: [Forbid, Permit, Wait]
libraries: [exec.library]
---

# 21 / Task Exclusion / Forbidding Task Switching

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Forbidding is used when a task is accessing shared structures that might
also be accessed at the same time from another task.  It effectively
eliminates the possibility of simultaneous access by imposing
nonpreemptive task scheduling.  This has the net effect of disabling
multitasking for as long as your task remains in its running state. While
forbidden, your task will continue running until it performs a call to
[Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) or exits from the forbidden state.  Interrupts will occur normally,
but no new tasks will be dispatched, regardless of their priorities.

When a task running in the forbidden state calls the [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) function,
directly or indirectly, it implies a temporary exit from its forbidden
state. Since almost all stdio, device I/O, and file I/O functions must
Wait() for I/O completion, performing such calls will cause your task to
Wait(), temporarily breaking the forbid.  While the task is waiting, the
system will perform normally.  When the task receives one of the signals
it is waiting for, it will again reenter the forbidden state. To become
forbidden, a task calls the [Forbid()](autodocs-2.0/exec-library-forbid.md) function.  To escape, the [Permit()](autodocs-2.0/exec-library-permit.md)
function is used.  The use of these functions may be nested with the
expected affects; you will not exit the forbidden mode until you call the
outermost Permit().

As an example, the Exec task list should only be accessed when in a
[Forbid()](autodocs-2.0/exec-library-forbid.md) state.  Accessing the list without forbidding could lead to
incorrect results or it could crash the entire system.  To access the task
list also requires the program to disable interrupts which is discussed in
the [next section](libraries/21-task-exclusion-disabling-tasks.md).

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
