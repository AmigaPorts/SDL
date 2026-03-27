---
title: 21 / Task Creation / Task Stack
manual: libraries
chapter: libraries
section: 21-task-creation-task-stack
functions: []
libraries: []
---

# 21 / Task Creation / Task Stack

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Every task requires a stack.  All task stacks are user mode stacks (in the
language of the 68000) and are addressed through the A7 CPU register.  All
normal code execution occurs on this task stack.  Special modes of
execution (processor traps and system interrupts for example) execute on a
single [supervisor mode](libraries/21-processor-and-cache-control-supervisor-mode.md) stack and do not directly affect task stacks.

Task stacks are normally used to store local variables, subroutine return
addresses, and saved register values.  Additionally, when a task loses the
processor, all of its current registers are preserved on this stack (with
the exception of the stack pointer itself, which must be saved in the task
structure).

The amount of stack used by a task can vary widely.  The theoretical
minimum stack size is 72 bytes, which is the number required to save 17
CPU registers and a single return address.  Of course, a stack of this
size would not give you adequate space to perform any subroutine calls
(because the return address occupies stack space).  On the other hand, a
stack size of 1K would suffice to call most system functions but would not
allow much in the way of local variable storage.  Processes that call DOS
library functions need an additional 1500 bytes of stack.

Because stack-bounds checking is not provided as a service of Exec, it is
important to provide enough space for your task stack.  Stack overflows
are always difficult to debug and may result not only in the erratic
failure of your task but also in the mysterious malfunction of other Amiga
subsystems.  Some compilers provide a stack-checking option.


```c
    You Can't Always Check The Stack.
    ---------------------------------
    Such stack-checking options generally cannot be used if part of your
    code will be running on the system stack (interrupts, 680x0
    exceptions, handlers, servers), or on a different task's stack
    (libraries, devices, created tasks).
```
When choosing your stack size, do not cut it too close. Remember that any
recursive routines in your code may use varying amounts of stack, and that
future versions of system routines may use additional stack variables.  By
dynamically allocating buffers and arrays, most application programs can
be designed to function comfortably within the default process stack size
of 4000 bytes.

