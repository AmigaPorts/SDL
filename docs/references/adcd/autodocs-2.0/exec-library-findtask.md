---
title: exec.library/FindTask
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-findtask
functions: [FindTask, Forbid, Permit]
libraries: [exec.library]
---

# exec.library/FindTask

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    FindTask -- find a task with the given name or find oneself
SYNOPSIS

```c
    task = FindTask(name)
    D0              A1

    struct [Task](autodocs-2.0/includes-exec-tasks-h.md) *FindTask(STRPTR);
```
FUNCTION

```c
    This function will check all task queues for a task with the given
    name, and return a pointer to its task control block.  If a NULL
    name pointer is given a pointer to the current task will be
    returned.

    Finding oneself with a NULL for the name is very quick.  Finding a
    task by name is very system expensive, and will disable interrupts
    for a long time.  Since a task may remove itself at any time,
    a [Forbid()/Permit()](autodocs-2.0/exec-library-permit.md) pair may be needed to ensure the pointer
    returned by FindTask() is still valid when used.
```
INPUT

    name - pointer to a name string
RESULT

```c
    task - pointer to the task (or Process)
```

---

## See Also

- [FindTask — exec.library](../autodocs/exec.library.md#findtask)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
