---
title: exec.library/CachePostDMA
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-cachepostdma-2
functions: [CacheClearE, CacheClearU, CachePostDMA, CachePreDMA]
libraries: [exec.library]
---

# exec.library/CachePostDMA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CachePostDMA - Take actions after to hardware DMA  (V37)

   SYNOPSIS
	CachePostDMA(vaddress,&length,flags)
	             a0       a1      d0

	CachePostDMA(APTR,[LONG](autodocs-3.5/include-exec-types-h.md) *,ULONG);

   FUNCTION
	Take all appropriate steps after Direct Memory Access (DMA).  This
	function is primarily intended for writers of DMA device drivers.  The
	action will depend on the CPU type installed, caching modes, and the
	state of any Memory Management [Unit](autodocs-3.5/include-exec-devices-h.md) (MMU) activity.

	As implemented
		68000 - Do nothing
		68010 - Do nothing
		68020 - Do nothing
		68030 - [Flush](autodocs-3.5/dos-library-flush-2.md) the data cache
		68040 - [Flush](autodocs-3.5/dos-library-flush-2.md) matching areas of the data cache
		????? - External cache boards, Virtual Memory Systems, or
			future hardware may patch this vector to best emulate
			the intended behavior.
			With a Bus-Snooping CPU, this function my end up
			doing nothing.

   INPUTS
	address	- Same as initially passed to [CachePreDMA](autodocs-3.5/exec-library-cachepredma-2.md)
	length	- Same as initially passed to [CachePreDMA](autodocs-3.5/exec-library-cachepredma-2.md)
	flags	- Values:
			DMA_NoModify - If the area was not modified (and
			thus there is no reason to flush the cache) set
			this bit.

			DMA_ReadFromRAM - Indicates that this DMA is a
			read from RAM to the DMA device (ie - a write
			to the hard drive)  This flag is not required
			but if used must match in both the PreDMA and
			PostDMA calls.  This flag *should* be used to
			help the system provide the best performance.
			This flag is safe in all versions of CachePostDMA()

   SEE ALSO
	exec/execbase.i, [CachePreDMA()](autodocs-3.5/exec-library-cachepredma-2.md), [CacheClearU()](autodocs-3.5/exec-library-cacheclearu-2.md), [CacheClearE()](autodocs-3.5/exec-library-cachecleare-2.md)

---

## See Also

- [CacheClearE — exec.library](../autodocs/exec.library.md#cachecleare)
- [CacheClearU — exec.library](../autodocs/exec.library.md#cacheclearu)
- [CachePostDMA — exec.library](../autodocs/exec.library.md#cachepostdma)
- [CachePreDMA — exec.library](../autodocs/exec.library.md#cachepredma)
