---
title: exec.library/Vacate
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-vacate
functions: [Procure, Vacate]
libraries: [exec.library]
---

# exec.library/Vacate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Vacate -- release a message lock (semaphore)
```
SYNOPSIS

```c
    Vacate(semaphore)
           A0

    void Vacate(struct [Semaphore](autodocs-2.0/includes-exec-semaphores-h.md) *);
```
FUNCTION

```c
    This function releases a previously locked semaphore (see
    the [Procure()](autodocs-2.0/exec-library-procure.md) function).
    If another task is waiting for the semaphore, its bidMessage
    will be sent to its reply port.
```
INPUT

    semaphore - the semaport message port representing the
    semaphore to be freed.
BUGS

```c
    [Procure()](autodocs-2.0/exec-library-procure.md) and Vacate() do not have proven reliability.
```
SEE ALSO

```c
    [Procure](autodocs-2.0/exec-library-procure.md)
```

---

## See Also

- [Procure — exec.library](../autodocs/exec.library.md#procure)
- [Vacate — exec.library](../autodocs/exec.library.md#vacate)
