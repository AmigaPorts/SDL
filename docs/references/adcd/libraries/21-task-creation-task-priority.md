---
title: 21 / Task Creation / Task Priority
manual: libraries
chapter: libraries
section: 21-task-creation-task-priority
functions: [SetTaskPri]
libraries: [exec.library]
---

# 21 / Task Creation / Task Priority

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A task's priority indicates its importance relative to other tasks.
Higher-priority tasks receive the processor before lower-priority tasks
do.  Task priority is stored as a signed number ranging from -128 to +127.
Higher priorities are represented by more positive values; zero is
considered the neutral priority.  Normally, system tasks execute somewhere
in the range of +20 to -20, and most application tasks execute at
priority 0.

It is not wise to needlessly raise a task's priority.  Sometimes it may be
necessary to carefully select a priority so that the task can properly
interact with various system tasks.  The [SetTaskPri()](libraries/21-exec-tasks-function-reference.md) Exec function is
provided for this purpose.

---

## See Also

- [SetTaskPri — exec.library](../autodocs/exec.library.md#settaskpri)
