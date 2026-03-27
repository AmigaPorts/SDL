---
title: 21 / Task Traps / Trap Handlers
manual: libraries
chapter: libraries
section: 21-task-traps-trap-handlers
functions: []
libraries: []
---

# 21 / Task Traps / Trap Handlers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For compatibility with the 68000, Exec performs trap handling in
[supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md).  This means that all task switching is disabled during
trap handling. At entry to the task's trap handler, the system stack
contains a processor-dependent trap frame as defined in the 68000/10/20/30
manuals.  A longword exception number is added to this frame.  That is,
when a handler gains control, the top of stack contains the exception
number and the trap frame immediately follows.

To return from trap processing, remove the exception number from the stack
(note that this is the supervisor stack, not the user stack) and then
perform a return from exception (RTE).

Because trap processing takes place in [supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md), with task
dispatching disabled, it is strongly urged that you keep trap processing
as short as possible or switch back to user mode from within your trap
handler.  If a trap handler already exists when you add your own trap
handler, it is smart to propagate any traps that you do not handle down to
the previous handler.  This can be done by saving the previous address
from [tc_TrapCode](libraries/21-exec-tasks-task-structure.md) and having your handler pass control to that address if
the trap which occurred is not one you wish to handle.

The following example installs a simple trap handler which intercepts
processor divide-by-zero traps, and passes on all other traps to the
previous default trap code.  The example has two code modules which are
linked together.  The trap handler code is in assembler.  The C module
installs the handler, demonstrates its effectiveness, then restores the
previous [tc_TrapCode](libraries/21-exec-tasks-task-structure.md).


```c
     [trap_c.c example](libraries/lib-examples-trap-c-c.md) 
```
