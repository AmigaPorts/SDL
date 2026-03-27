---
title: exec.library/SetTaskPri
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-settaskpri
functions: []
libraries: []
---

# exec.library/SetTaskPri

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetTaskPri -- get and set the priority of a task
SYNOPSIS

```c
    oldPriority = SetTaskPri(task, priority)
    D0-0:8                   A1    D0-0:8

    BYTE SetTaskPri(struct [Task](autodocs-2.0/includes-exec-tasks-h.md) *,LONG);
```
FUNCTION

```c
    This function changes the priority of a task regardless of its
    state.  The old priority of the task is returned.  A reschedule is
    performed, and a context switch may result.

    To change the priority of the currently running task, pass the
    result of FindTask(0); as the task pointer.
```
INPUTS

    task - task to be affected
    priority - the new priority for the task
RESULT

    oldPriority - the tasks previous priority
