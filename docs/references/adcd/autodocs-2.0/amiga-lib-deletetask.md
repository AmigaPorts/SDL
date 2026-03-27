---
title: amiga.lib/DeleteTask
manual: autodocs-2.0
chapter: autodocs-2.0
section: amiga-lib-deletetask
functions: [RemTask]
libraries: [exec.library]
---

# amiga.lib/DeleteTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    DeleteTask -- delete a task created with [CreateTask()](autodocs-2.0/amiga-lib-createtask.md)
```
SYNOPSIS

```c
    DeleteTask(task)

    VOID DeleteTask(struct [Task](autodocs-2.0/includes-exec-tasks-h.md) *);
```
FUNCTION

```c
    This function simply calls [exec.library/RemTask()](autodocs-2.0/exec-library-remtask.md), deleting a task
    from the Exec task lists and automatically freeing any stack and
    structure memory allocated for it by [CreateTask()](autodocs-2.0/amiga-lib-createtask.md).

    Before deleting a task, you must first make sure that the task is
    not currently executing any system code which might try to signal
    the task after it is gone.

    This can be accomplished by stopping all sources that might reference
    the doomed task, then causing the subtask to execute a Wait(0L).
    Another option is to have the task call [DeleteTask()/RemTask()](autodocs-2.0/exec-library-remtask.md) on
    itself.
```
INPUTS

    task - task to remove from the system
NOTE

```c
    This function simply calls [exec.library/RemTask()](autodocs-2.0/exec-library-remtask.md), so you can call
    [RemTask()](autodocs-2.0/exec-library-remtask.md) directly instead of calling this function.
```
SEE ALSO

```c
    [CreateTask()](autodocs-2.0/amiga-lib-createtask.md), [exec.library/RemTask()](autodocs-2.0/exec-library-remtask.md)
```

---

## See Also

- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
