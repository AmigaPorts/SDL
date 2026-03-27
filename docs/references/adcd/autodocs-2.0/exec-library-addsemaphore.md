---
title: exec.library/AddSemaphore
manual: autodocs-2.0
chapter: autodocs-2.0
section: exec-library-addsemaphore
functions: [Forbid, InitSemaphore, ObtainSemaphoreList, Permit]
libraries: [exec.library]
---

# exec.library/AddSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AddSemaphore -- initialize then add a signal semaphore to the system
SYNOPSIS

```c
    AddSemaphore(signalSemaphore)
                 A1

    void AddSemaphore(struct [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) *);
```
FUNCTION

```c
    This function attaches a signal semaphore structure to the system's
    public signal semaphore list.  The name and priority fields of the
    semaphore structure must be initialized prior to calling this
    function.  If you do not want to let others rendezvous with this
    semaphore, use [InitSemaphore()](autodocs-2.0/exec-library-initsemaphore.md) instead.

    If a semaphore has been added to the naming list, you must be
    careful to remove the semaphore from the list (via RemSemaphore)
    before deallocating its memory.

    Semaphores that are linked together in an allocation list (which
    [ObtainSemaphoreList()](autodocs-2.0/exec-library-obtainsemaphorelist.md) would use) may not be added to the system
    naming list, because the facilities use the link field of the
    signal semaphore in incompatible ways
```
INPUTS
   signalSemaphore -- an signal semaphore structure

BUGS

```c
    Does not work in Exec <V36.  Instead use this code:

        #include [<exec/execbase.h>](autodocs-2.0/includes-exec-execbase-h.md)
        #include [<exec/nodes.h>](autodocs-2.0/includes-exec-nodes-h.md)
        extern struct [ExecBase](autodocs-2.0/includes-exec-execbase-h.md) *SysBase;
            ...
        void LocalAddSemaphore(s)
        struct [SignalSemaphore](autodocs-2.0/includes-exec-semaphores-h.md) *s;
        {
            s->ss_Link.ln_Type=NT_SIGNALSEM;
            InitSemaphore(s);
            Forbid();
            Enqueue(&SysBase->SemaphoreList,s);
            Permit();
        }
```
SEE ALSO

```c
    [RemSemaphore](autodocs-2.0/exec-library-remsemaphore.md), [FindSemaphore](autodocs-2.0/exec-library-findsemaphore.md), [InitSemaphore](autodocs-2.0/exec-library-initsemaphore.md)
```

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
