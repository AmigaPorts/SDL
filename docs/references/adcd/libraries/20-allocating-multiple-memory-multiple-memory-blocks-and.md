---
title: 20 / Allocating Multiple Memory / Multiple Memory Blocks and Tasks
manual: libraries
chapter: libraries
section: 20-allocating-multiple-memory-multiple-memory-blocks-and
functions: [AllocMem, RemTask]
libraries: [exec.library]
---

# 20 / Allocating Multiple Memory / Multiple Memory Blocks and Tasks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If you want to take advantage of Exec's automatic cleanup, use the [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md)
and [AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) facility to do your dynamic memory allocation.

In the [Task](libraries/21-exec-tasks-task-structure.md) control block structure, there is a list header named
[tc_MemEntry](libraries/21-exec-tasks-task-structure.md). This is the list header that you initialize to include
[MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md)s that your task has created by call(s) to [AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md).  Here is a
short program segment that handles task memory list header initialization
only.  It assumes that you have already run AllocEntry() as shown in the
simple AllocEntry() example above.


```c
    struct Task *tc;
    struct MemList *ml;

    /* First initialize the task pointer and AllocEntry() the memlist ml */

    if(!tc->tc_MemEntry)
        NewList(tc->tc_MemEntry);  /* Initialize the task's memory    */
                                   /* list header. Do this once only! */
    AddTail(tc->tc_MemEntry, ml);
```
Assuming that you have only used the [AllocEntry()](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) method (or [AllocMem()](libraries/20-exec-memory-allocation-memory-functions.md)
and built your own custom [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md)), the system now knows where to find the
blocks of memory that your task has dynamically allocated.  The [RemTask()](libraries/21-exec-tasks-function-reference.md)
function automatically frees all memory found on [tc_MemEntry](libraries/21-exec-tasks-task-structure.md).


```c
    [CreateTask()](libraries/21-task-creation-task-creation-with-amiga-lib.md) Sets Up A [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md).
    -------------------------------
    The amiga.lib CreateTask() function, and other system task and
    process creation functions use a MemList in [tc_MemEntry](libraries/21-exec-tasks-task-structure.md) so that
    the Task structure and stack will be automatically deallocated when
    the Task is removed.
```

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
