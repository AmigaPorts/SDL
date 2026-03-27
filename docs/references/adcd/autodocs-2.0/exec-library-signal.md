---
title: exec.library/Signal
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-signal
functions: []
libraries: []
---

# exec.library/Signal

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    Signal -- signal a task
SYNOPSIS

```c
    Signal(task, signals)
           A1    D0

    void Signal(struct [Task](autodocs-2.0/includes-exec-tasks-h.md) *,ULONG);
```
FUNCTION

```c
    This function signals a task with the given signals.  If the task
    is currently waiting for one or more of these signals, it will be
    made ready and a reschedule will occur. If the task is not waiting
    for any of these signals, the signals will be posted to the task
    for possible later use. A signal may be sent to a task regardless
    of whether its running, ready, or waiting.

    This function is considered "low level".  Its main purpose is to
    support multiple higher level functions like [PutMsg](autodocs-2.0/exec-library-putmsg.md).

    This function is safe to call from interrupts.
```
INPUT

    task - the task to be signalled
    signals - the signals to be sent
SEE ALSO

```c
    Wait, [SetSignal](autodocs-2.0/exec-library-setsignal.md)
```
