---
title: exec.library/AddSemaphore
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addsemaphore-2
functions: [FindSemaphore, Forbid, InitSemaphore, ObtainSemaphoreList, Permit, RemSemaphore]
libraries: [exec.library]
---

# exec.library/AddSemaphore

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddSemaphore -- initialize then add a signal semaphore to the system

   SYNOPSIS
	AddSemaphore(signalSemaphore)
		     A1

	void AddSemaphore(struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *);

   FUNCTION
	This function attaches a signal semaphore structure to the system's
	public signal semaphore list.  The name and priority fields of the
	semaphore structure must be initialized prior to calling this
	function.  If you do not want to let others rendezvous with this
	semaphore, use [InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md) instead.

	If a semaphore has been added to the naming list, you must be
	careful to remove the semaphore from the list (via RemSemaphore)
	before deallocating its memory.

	Semaphores that are linked together in an allocation list (which
	[ObtainSemaphoreList()](autodocs-3.5/exec-library-obtainsemaphorelist-2.md) would use) may not be added to the system
	naming list, because the facilities use the link field of the
	signal semaphore in incompatible ways

   INPUTS

       signalSemaphore -- an signal semaphore structure
   BUGS
	Does not work in Exec <V36.  Instead use this code:

	    #include [<exec/execbase.h>](autodocs-3.5/include-exec-execbase-h.md)
	    #include [<exec/nodes.h>](autodocs-3.5/include-exec-nodes-h.md)
	    extern struct [ExecBase](autodocs-3.5/include-exec-execbase-h.md) *SysBase;
		...
	    void LocalAddSemaphore(s)
	    struct [SignalSemaphore](autodocs-3.5/include-exec-semaphores-h.md) *s;
	    {
		s->ss_Link.ln_Type=NT_SIGNALSEM;
		InitSemaphore(s);
		Forbid();
		Enqueue(&SysBase->SemaphoreList,s);
		Permit();
	    }

   SEE ALSO
	[RemSemaphore()](autodocs-3.5/exec-library-remsemaphore-2.md), [FindSemaphore()](autodocs-3.5/exec-library-findsemaphore-2.md), [InitSemaphore()](autodocs-3.5/exec-library-initsemaphore-2.md)

---

## See Also

- [FindSemaphore — exec.library](../autodocs/exec.library.md#findsemaphore)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [InitSemaphore — exec.library](../autodocs/exec.library.md#initsemaphore)
- [ObtainSemaphoreList — exec.library](../autodocs/exec.library.md#obtainsemaphorelist)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [RemSemaphore — exec.library](../autodocs/exec.library.md#remsemaphore)
