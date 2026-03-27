---
title: exec.library/CacheClearU
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-cacheclearu-2
functions: [CacheClearE, CacheClearU, CacheControl]
libraries: [exec.library]
---

# exec.library/CacheClearU

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CacheClearU - User callable simple cache clearing (V37)

   SYNOPSIS
	CacheClearU()

	void CacheClearU(void);

   FUNCTION
	[Flush](autodocs-3.5/dos-library-flush-2.md) out the contents of any CPU instruction and data caches.
	If dirty data cache lines are present, push them to memory first.

	Caches must be cleared after *any* operation that could cause
	invalid or stale data.  The most common cases are DMA and modifying
	instructions using the processor.  See the [CacheClearE()](autodocs-3.5/exec-library-cachecleare-2.md) autodoc
	for a more complete description.

	Some examples of when the cache needs clearing:
			Self modifying code
			Building Jump tables
			Run-time code patches
			Relocating code for use at different addresses.
			Loading code from disk

   SEE ALSO
	exec/execbase.i, [CacheControl()](autodocs-3.5/exec-library-cachecontrol-2.md), [CacheClearE()](autodocs-3.5/exec-library-cachecleare-2.md)

---

## See Also

- [CacheClearE — exec.library](../autodocs/exec.library.md#cachecleare)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [CacheControl — exec.library](../autodocs/exec.library.md#cachecontrol)
