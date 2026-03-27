---
title: 21 / Task Creation / Task Creation With Amiga.lib
manual: libraries
chapter: libraries
section: 21-task-creation-task-creation-with-amiga-lib
functions: [RemTask]
libraries: [exec.library]
---

# 21 / Task Creation / Task Creation With Amiga.lib

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A simpler method of creating a task is provided by the amiga.lib Exec
support function [CreateTask()](autodocs-2.0/amiga-lib-createtask.md), which can be accessed if your code is
linked with amiga.lib.


```c
    CreateTask(char *name, LONG priority, APTR initialPC, ULONG stacksize)
```
A task created with [CreateTask()](autodocs-2.0/amiga-lib-createtask.md) may be removed with the amiga.lib
[DeleteTask()](autodocs-2.0/amiga-lib-deletetask.md) function, or it may simply return when it is finished.
CreateTask() adds a [MemList](libraries/20-exec-memory-allocation-allocating-multiple-memory-blocks.md) to the [tc_MemEntry](libraries/21-exec-tasks-task-structure.md) of the task it creates,
describing all memory it has allocated for the task, including the task
stack and the [Task](libraries/21-exec-tasks-task-structure.md) structure itself.  This memory will be deallocated by
Exec when the task is either explicitly removed ([RemTask()](libraries/21-exec-tasks-function-reference.md) or
DeleteTask()) or when it exits to Exec's default task removal code
(RemTask()).

Note that a bug in the [CreateTask()](autodocs-2.0/amiga-lib-createtask.md) code caused a failed memory allocation
to go unnoticed in V33 and early versions of Release 2 amiga.lib.

If your development language is not linkable with amiga.lib, it may
provide an equivalent built-in function, or you can create your own based
on the "createtask.c" code in the Amiga ROM Kernel Reference Manual:
Includes and Autodocs.

Depending on the priority of a new task and the priorities of other tasks
in the system, the newly added task may begin execution immediately.


    Sharing Library Pointers
    ------------------------
    Although in most cases it is possible for a parent task to pass a
    library base to a child task so the child can use that library, for
    some libraries, this is not possible.  For this reason, the only
    library base sharable between tasks is Exec's library base.
Here is an example of simple task creation.  In this example there is no
coordination or communication between the main process and the simple task
it has created.  A more complex example might use named ports and messages
to coordinate the activities and shutdown of two tasks.  Because our task
is very simple and never calls any system functions which could cause it
to be signalled or awakened, we can safely remove the task at any time.


```c
    Keep This In Mind.
    ------------------
    Because the simple task's code is a function in our program, we must
    stop the subtask before exiting.

     [simpletask.c](libraries/lib-examples-simpletask-c.md) 
```

---

## See Also

- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
