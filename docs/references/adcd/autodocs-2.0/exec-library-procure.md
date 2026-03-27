---
title: exec.library/Procure
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-procure
functions: [Procure, Vacate]
libraries: [exec.library]
---

# exec.library/Procure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Procure -- bid for a message lock (semaphore)
```
SYNOPSIS

```c
    result = Procure(semaphore, bidMessage)
    D0               A0         A1

    BYTE Procure(struct [Semaphore](autodocs-2.0/includes-exec-semaphores-h.md) *, struct [Message](autodocs-2.0/includes-exec-ports-h.md) *);
```
FUNCTION

```c
    This function is used to obtain a message based semaphore lock.  If
    the lock is immediate, Procure() returns a true result, and the
    bidMessage is not used.   If the semaphore is already locked,
    Procure() returns false, and the task must wait for the bidMessage
    to arrive at its reply port.

    Straight "Semaphores" use the message system.  They are therefore
    queueable, and users may wait on several of them at the same time.
    This makes them more powerful than "Signal Semaphores"
```
INPUT

```c
    semaphore - a semaphore message port.  This port is used to queue
    all pending lockers.  This port should be initialized with the
    PA_IGNORE option, as the MP_SigTask field is used for a pointer to
    the current locker message (not a task). New semaphore ports must
    also have the SM_BIDS word initialized to -1.  If the semaphore is
    public, it should be named, its priority set, and the added with
    [AddPort](autodocs-2.0/exec-library-addport.md). [Message](autodocs-2.0/includes-exec-ports-h.md) port priority is often used for anti-deadlock
    locking conventions.
```
RESULT

    result - true when the semaphore is free.  In such cases no waiting
    needs to be done.  If false, then the task should wait at its
    bidMessage reply port.
BUGS

```c
    Procure() and [Vacate()](autodocs-2.0/exec-library-vacate.md) do not have proven reliability.
```
SEE ALSO

```c
    [Vacate()](autodocs-2.0/exec-library-vacate.md)
```

---

## See Also

- [Procure — exec.library](../autodocs/exec.library.md#procure)
- [Vacate — exec.library](../autodocs/exec.library.md#vacate)
