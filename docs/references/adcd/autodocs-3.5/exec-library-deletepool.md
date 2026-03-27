---
title: exec.library/DeletePool
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-deletepool
functions: [AllocPooled, CreatePool, FreePooled]
libraries: [exec.library]
---

# exec.library/DeletePool

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DeletePool --  Drain an entire memory pool (V39)

    SYNOPSIS
	DeletePool(poolHeader)
	           a0

	void DeletePool(void *);

    FUNCTION
	Frees all memory in all pudles of the specified pool header, then
	deletes the pool header.  Individual free calls are not needed.

    INPUTS
	poolHeader - as returned by [CreatePool()](autodocs-3.5/exec-library-createpool.md).

    SEE ALSO
	[CreatePool()](autodocs-3.5/exec-library-createpool.md), [AllocPooled()](autodocs-3.5/exec-library-allocpooled.md), [FreePooled()](autodocs-3.5/exec-library-freepooled.md)

---

## See Also

- [AllocPooled — exec.library](../autodocs/exec.library.md#allocpooled)
- [CreatePool — exec.library](../autodocs/exec.library.md#createpool)
- [FreePooled — exec.library](../autodocs/exec.library.md#freepooled)
