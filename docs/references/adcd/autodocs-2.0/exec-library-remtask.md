---
title: exec.library/RemTask
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remtask
functions: [Forbid, Permit, RemTask]
libraries: [exec.library]
---

# exec.library/RemTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemTask -- remove a task from the system
SYNOPSIS

```c
    RemTask(task)
            A1

    void RemTask(struct [Task](autodocs-2.0/includes-exec-tasks-h.md) *);
```
FUNCTION

```c
    This function removes a task from the system.  Deallocation of
    resources should have been performed prior to calling this
    function.  Removing some other task is very dangerous.  Generally
    is is best to arrange for tasks to call RemTask(0L) on themselves.

    RemTask will automagically free any memory lists attached to the
    task's TC_MEMENTRY list.
```
INPUTS

    task - pointer to the task node representing the task to be
           removed.  A zero value indicates self removal, and will
           cause the next ready task to begin execution.
BUGS

```c
    Before V36 if RemTask() was called on a task other than the current
    task, and that task was created with [amiga.lib/CreateTask](autodocs-2.0/amiga-lib-createtask.md), there was
    a slight chance of a crash.  The problem can be hidden by bracketing
    RemTask() with [Forbid()/Permit()](autodocs-2.0/exec-library-permit.md).
```
SEE ALSO

```c
    [AddTask](autodocs-2.0/exec-library-addtask.md), [exec/AllocEntry](autodocs-2.0/exec-library-allocentry.md), [amiga.lib/DeleteTask](autodocs-2.0/amiga-lib-deletetask.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [RemTask — exec.library](../autodocs/exec.library.md#remtask)
