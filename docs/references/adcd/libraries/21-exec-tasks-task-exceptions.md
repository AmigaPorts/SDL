---
title: 21 Exec Tasks / Task Exceptions
manual: libraries
chapter: libraries
section: 21-exec-tasks-task-exceptions
functions: [SetExcept]
libraries: [exec.library]
---

# 21 Exec Tasks / Task Exceptions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec can provide a task with its own task-local "interrupt" called an
exception.  When some exceptional event occurs, an Exec exception occurs
which stops a particular task from executing its normal code and forces it
to execute a special, task-specific exception handling routine.

If you are familiar with the 680x0, you may be used to using the term
"exceptions" in a different way.  The 680x0 has its own form of exception
that has nothing to do with an Exec exception.  These are discussed in
more detail in the "[Task Traps](libraries/21-exec-tasks-task-traps.md)" section of this chapter.  Do not confuse
Exec exceptions with 680x0 exceptions.

To set up an exception routine for a task requires setting values in the
task's control structure (the [Task](libraries/21-exec-tasks-task-structure.md) structure).  The [tc_ExceptCode](libraries/21-exec-tasks-task-structure.md) field
should point to the task's exception handling routine.  If this field is
zero, Exec will ignore all exceptions.  The [tc_ExceptData](libraries/21-exec-tasks-task-structure.md) field should
point to any data the exception routine needs.

Exec exceptions work using signals.  When a specific signal or signals
occur, Exec will stop a task and execute its exception routine.  Use the
Exec function [SetExcept()](autodocs-2.0/exec-library-setexcept.md) to tell Exec which of the task's signals should
trigger the exception.

When an exception occurs, Exec stops executing the tasks normal code and
jumps immediately into the exception routine, no matter what the task was
doing.  The exception routine operates in the same context the task's
normal code; it operates in the CPU's user mode and uses the task's stack.

Before entering the exception routine, Exec pushes the normal task code's
context onto the stack.  This includes the PC, SR, D0-D7, and A0-A6
registers.  Exec then puts certain parameters in the processor registers
for the exception routine to use.  D0 contains a signal mask indicating
which signal bit or bits caused the exception. Exec disables these signals
when the task enters its exception routine.  If more than one signal bit
is set (i.e. if two signals occurred simultaneously), it is up to the
exception routine to decide in what order to process the two different
signals.  A1 points to the related exception data (from [tc_ExceptData](libraries/21-exec-tasks-task-structure.md)),
and A6 contains the Exec library base. You can think of an exception as a
subtask outside of your normal task. Because task exception code executes
in user mode, however, the task stack must be large enough to supply the
extra space consumed during an exception.

While processing a given exception, Exec prevents that exception from
occurring recursively.  At exit from your exception-processing code, you
should make sure D0 contains the signal mask the exception routine
received in D0 because Exec looks here to see which signals it should
reactivate.  When the task executes the RTS instruction at the end of the
exception routine, the system restores the previous contents of all of the
task registers and resumes the task at the point where it was interrupted
by the exception signal.


```c
    Exceptions Are Tricky.
    ----------------------
    Exceptions are difficult to use safely.  An exception can interrupt
    a task that is executing a critical section of code within a system
    function, or one that has locked a system resource such as the disk
    or blitter (note that even simple text output uses the blitter.)
    This possibility makes it dangerous to use most system functions
    within an exception unless you are sure that your interrupted task
    was performing only local, non-critical operations.
```

---

## See Also

- [SetExcept — exec.library](../autodocs/exec.library.md#setexcept)
