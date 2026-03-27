---
title: exec.library/RemSemaphore
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-remsemaphore
functions: []
libraries: []
---

# exec.library/RemSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    RemSemaphore -- remove a signal semaphore from the system
SYNOPSIS

```c
    RemSemaphore(signalSemaphore)
                 A1

    void RemSemaphore(struct [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) *);
```
FUNCTION

    This function removes a signal semaphore structure from the
    system's signal semaphore list.  Subsequent attempts to
    rendezvous by name with this semaphore will fail.
INPUTS
   signalSemaphore -- an initialized signal semaphore structure

SEE ALSO

```c
    [AddSemaphore](autodocs-2.0/exec-library-addsemaphore.md), [FindSemaphore](autodocs-2.0/exec-library-findsemaphore.md)
```
