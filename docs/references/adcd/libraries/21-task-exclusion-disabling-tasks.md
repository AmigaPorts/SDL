---
title: 21 / Task Exclusion / Disabling Tasks
manual: libraries
chapter: libraries
section: 21-task-exclusion-disabling-tasks
functions: [Disable, Enable, Forbid, Wait]
libraries: [exec.library]
---

# 21 / Task Exclusion / Disabling Tasks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Disabling is similar to forbidding, but it also prevents interrupts from
occurring during a critical section.  Disabling is required when a task
accesses structures that are shared by interrupt code.  It eliminates the
possibility of an interrupt accessing shared structures by preventing
interrupts from occurring.  Use of disabling is strongly discouraged.

To disable interrupts you can call the [Disable()](autodocs-2.0/exec-library-disable.md) function.  To enable
interrupts again, use the [Enable()](autodocs-2.0/exec-library-enable.md) function.  Although assembler DISABLE
and ENABLE macros are provided, assembler programmers should use the
system functions rather than the macros for upwards compatibility, ease of
debugging, and smaller code size.

Like forbidden sections, disabled sections can be nested.  To restore
normal interrupt processing, an [Enable()](autodocs-2.0/exec-library-enable.md) call must be made for every
[Disable()](autodocs-2.0/exec-library-disable.md).  Also like forbidden sections, any direct or indirect call to
the [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md) function will enable interrupts until the task regains the
processor.


```c
    WARNING:
    --------
    It is important to realize that there is a danger in using disabled
    sections.  Because the software on the Amiga depends heavily on its
    interrupts occurring in nearly real time, you cannot disable for more
    than a very brief instant. Disabling interrupts for more than 250
    microseconds can interfere with the normal operation of vital system
    functions, especially serial I/O.

    WARNING:
    --------
    Masking interrupts by changing the 68000 processor interrupt
    priority levels with the MOVE SR instruction can also be dangerous
    and is very strongly discouraged.  The disable- and enable-related
    functions control interrupts through the 4703 custom chip and not
    through the 68000 priority level.  In addition, the processor
    priority level can be altered only from [supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md) (which means
    this process is much less efficient).
```
It is never necessary to both [Disable()](autodocs-2.0/exec-library-disable.md) and [Forbid()](libraries/21-task-exclusion-forbidding-task-switching.md).  Because disabling
prevents interrupts, it also prevents preemptive task scheduling.  When
disable is used within an interrupt, it will have the effect of locking
out all higher level interrupts (lower level interrupts are automatically
disabled by the CPU).  Many Exec lists can only be accessed while
disabled.  Suppose you want to print the names of all system tasks.  You
would need to access both the [TaskReady](autodocs-2.0/includes-exec-execbase-h.md) and [TaskWait](autodocs-2.0/includes-exec-execbase-h.md) lists from within a
single disabled section.  In addition, you must avoid calling system
functions that would break a disable by an indirect call to [Wait()](libraries/22-the-signal-system-waiting-for-a-signal.md)
([printf()](autodocs-2.0/amiga-lib-printf.md) for example).  In this example, the names are gathered into a
list while task switching is disabled. Then task switching is enabled and
the names are printed.


```c
     [tasklist.c](libraries/lib-examples-tasklist-c.md) 
```

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
