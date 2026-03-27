---
title: 21 Exec Tasks / Task Termination
manual: libraries
chapter: libraries
section: 21-exec-tasks-task-termination
functions: [RemTask]
libraries: [exec.library]
---

# 21 Exec Tasks / Task Termination

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Task termination may occur as the result of a number of situations:

  * A program returning from its [initialPC](libraries/21-exec-tasks-task-creation.md) routine and dropping into its

```c
    [finalPC](libraries/21-exec-tasks-task-creation.md) routine or the system default finalizer.
```
  * A task trap that is too serious for a recovery action. This includes

    traps like processor bus error, odd address access errors, etc.
  * A trap that is not handled by the task.  For example, the task might

    be terminated if your code happened to encounter a processor TRAP
    instruction and you did not provide a trap handling routine.
  * An explicit call to Exec [RemTask()](libraries/21-exec-tasks-function-reference.md) or amiga.lib [DeleteTask()](libraries/21-task-creation-task-creation-with-amiga-lib.md).

Task termination involves the deallocation of system resources and the
removal of the task structure from Exec.  The most important part of task
termination is the deallocation of system resources.  A task must return
all memory that it allocated for its private use, it must terminate any
outstanding I/O commands, and it must close access to any system libraries
or devices that it has opened.

It is wise to adopt a strategy for task clean-up responsibility.  You
should decide whether resource allocation and deallocation is the duty of
the creator task or the newly created task.  Often it is easier and safer
for the creator to handle the resource allocation and deallocation on
behalf of its offspring.  In such cases, before removing the child task,
you must make sure it is in a safe state such as [Wait](libraries/22-the-signal-system-waiting-for-a-signal.md)(0L) and not still
using a resources or waiting for an event or signal that might still occur.


```c
    NOTE:
    -----
    Certain resources, such as signals and created ports, must be
    allocated and deallocated by the same task that will wait on them.
    Also note that if your subtask code is part of your loaded program,
    you must not allow your program to exit before its subtasks have
    cleaned up their allocations, and have been either deleted or placed
    in a safe state such as [Wait](libraries/22-the-signal-system-waiting-for-a-signal.md)(0L).
```

---

## See Also

- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
