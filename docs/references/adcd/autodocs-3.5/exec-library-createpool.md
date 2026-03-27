---
title: exec.library/CreatePool
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-createpool
functions: [AllocPooled, CreatePool, DeletePool, FreePooled]
libraries: [exec.library]
---

# exec.library/CreatePool

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CreatePool -- Generate a private memory pool header (V39)

    SYNOPSIS
	newPool=CreatePool(memFlags,puddleSize,threshSize)
	d0                 d0       d1         d2

	void *CreatePool(ULONG,ULONG,ULONG);

    FUNCTION
	[Allocate](autodocs-3.5/exec-library-allocate-2.md) and prepare a new memory pool header.	Each pool is a
	separate tracking system for memory of a specific type.  Any number
	of pools may exist in the system.

	Pools automatically expand and shrink based on demand.	Fixed sized
	"puddles" are allocated by the pool manager when more total memory
	is needed.  Many small allocations can fit in a single puddle.
	Allocations larger than the threshSize are allocation in their own
	puddles.

	At any time individual allocations may be freed.  Or, the entire
	pool may be removed in a single step.

    INPUTS
	memFlags - a memory flags specifier, as taken by [AllocMem](autodocs-3.5/exec-library-allocmem-2.md).
	puddleSize - the size of Puddles...
	threshSize - the largest allocation that goes into normal puddles
	             This *MUST* be less than or equal to puddleSize
	             (CreatePool() will fail if it is not)

    RESULT
	The address of a new pool header, or NULL for error.

    SEE ALSO
	[DeletePool()](autodocs-3.5/exec-library-deletepool.md), [AllocPooled()](autodocs-3.5/exec-library-allocpooled.md), [FreePooled()](autodocs-3.5/exec-library-freepooled.md), exec/memory.i

---

## See Also

- [AllocPooled — exec.library](../autodocs/exec.library.md#allocpooled)
- [CreatePool — exec.library](../autodocs/exec.library.md#createpool)
- [DeletePool — exec.library](../autodocs/exec.library.md#deletepool)
- [FreePooled — exec.library](../autodocs/exec.library.md#freepooled)
