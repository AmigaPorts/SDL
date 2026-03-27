---
title: 21 Exec Tasks / Task Creation
manual: libraries
chapter: libraries
section: 21-exec-tasks-task-creation
functions: [AllocMem, RemTask]
libraries: [exec.library]
---

# 21 Exec Tasks / Task Creation

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To create a new task you must allocate a task structure, initialize its
various fields, and then link AutoDocs/it into Exec with a call to [AddTask()](autodocs-2.0/exec-library-addtask.md). The
task structure may be allocated by calling the [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md) function with
the [MEMF_CLEAR](libraries/20-memory-functions-memory-attributes.md) and [MEMF_PUBLIC](libraries/20-memory-functions-memory-attributes.md) allocation attributes.  These attributes
indicate that the data structure is to be pre-initialized to zero and that
the structure is shared.

The [Task](libraries/21-exec-tasks-task-structure.md) fields that require initialization depend on how you intend to
use the task.  For the simplest of tasks, only a few fields must be
initialized:

```c
    tc_Node
        The task list node structure.  This includes the task's
        priority, its type, and its name (refer to the chapter
```
	"[Exec Lists and Queues](libraries/23-list-structure-node-initialization.md)").


    tc_SPLower
        The lower memory bound of the task's stack.

    tc_SPUpper
        The upper memory bound of the task's stack.

    tc_SPReg
        The initial stack pointer.  Because task stacks grow downward in
        memory, this field is usually set to the same value as
        tc_SPUpper.
Zeroing all other unused fields will cause Exec to supply the appropriate
system default values.  Allocating the structure with the [MEMF_CLEAR](libraries/20-memory-functions-memory-attributes.md)
attribute is an easy way to be sure that this happens.

Once the structure has been initialized, it must be linked to Exec. This
is done with a call to [AddTask()](autodocs-2.0/exec-library-addtask.md) in which the following parameters are
specified:


```c
    AddTask(struct Task *task, APTR initialPC, APTR finalPC )
```
The task argument is a pointer to your initialized [Task](libraries/21-exec-tasks-task-structure.md) structure.  Set
initialPC to the entry point of your task code.   This is the address of
the first instruction the new task will execute.

Set finalPC to the address of the finalization code for your task.  This
is a code section that will receive control if the initialPC routine ever
performs a return (RTS). This exists to prevent your task from being
launched into random memory upon an accidental return.  The finalPC
routine should usually perform various program-related clean-up duties and
should then remove the task.  If a zero is supplied for this parameter,
Exec will use its default finalization code (which simply calls the
[RemTask()](libraries/21-exec-tasks-function-reference.md) function).

Under Release 2, [AddTask()](autodocs-2.0/exec-library-addtask.md) returns the address of the newly added task or
NULL for failure.  Under 1.3 and older versions of the OS, no values are
returned.

 [Task Creation With Amiga.lib](libraries/21-task-creation-task-creation-with-amiga-lib.md)    [Task Stack](libraries/21-task-creation-task-stack.md)    [Task Priority](libraries/21-task-creation-task-priority.md) 

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
