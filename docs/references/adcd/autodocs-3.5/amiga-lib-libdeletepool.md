---
title: amiga.lib/LibDeletePool
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-libdeletepool
functions: [AllocPooled, CreatePool, DeletePool, FreePooled]
libraries: [exec.library]
---

# amiga.lib/LibDeletePool

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LibDeletePool --  Drain an entire memory pool (V33)

    SYNOPSIS
	LibDeletePool(poolHeader)
	              a0

	void LibDeletePool(void *);

    FUNCTION
	This function is a copy of the pool functions in V39 and up of
	EXEC.  In fact, if you are running in V39, this function will
	notice and call the EXEC function.  This function works in
	V33 and up (1.2) Amiga system.

	The C code interface is _LibDeletePool() and takes its arguments
	from the stack just like the C code interface for [DeletePool()](autodocs-3.5/exec-library-deletepool.md)
	in amiga.lib.  The assembly code interface is with the symbol
	_AsmDeletePool: and takes the parameters in registers with the
	additional parameter of [ExecBase](autodocs-3.5/include-exec-execbase-h.md) being in a6 which can be used
	from SAS/C 6 by a prototype of:

	void __asm AsmDeletePool(register __a0 void *,
	                         register __a6 struct [ExecBase](autodocs-3.5/include-exec-execbase-h.md) *);

	Frees all memory in all puddles of the specified pool header, then
	deletes the pool header.  Individual free calls are not needed.

    INPUTS
	poolHeader - as returned by [LibCreatePool()](autodocs-3.5/amiga-lib-libcreatepool.md).

    SEE ALSO
	[CreatePool()](autodocs-3.5/exec-library-createpool.md), [AllocPooled()](autodocs-3.5/exec-library-allocpooled.md), [FreePooled()](autodocs-3.5/exec-library-freepooled.md),
	[LibCreatePool()](autodocs-3.5/amiga-lib-libcreatepool.md), [LibAllocPooled()](autodocs-3.5/amiga-lib-liballocpooled.md), [LibFreePooled()](autodocs-3.5/amiga-lib-libfreepooled.md)

---

## See Also

- [AllocPooled — exec.library](../autodocs/exec.library.md#allocpooled)
- [CreatePool — exec.library](../autodocs/exec.library.md#createpool)
- [DeletePool — exec.library](../autodocs/exec.library.md#deletepool)
- [FreePooled — exec.library](../autodocs/exec.library.md#freepooled)
