# exec.library/CachePostDMA



   NAME
	CachePostDMA - Take actions after to hardware DMA  (V37)

   SYNOPSIS
	CachePostDMA(vaddress,&length,flags)
	             a0       a1      d0

	CachePostDMA(APTR,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *,ULONG);

   FUNCTION
	Take all appropriate steps after Direct Memory Access (DMA).  This
	function is primarily intended for writers of DMA device drivers.  The
	action will depend on the CPU type installed, caching modes, and the
	state of any Memory Management [Unit](../Includes_and_Autodocs_3._guide/node05FB.html#line30) (MMU) activity.

	As implemented
		68000 - Do nothing
		68010 - Do nothing
		68020 - Do nothing
		68030 - [Flush](../Includes_and_Autodocs_3._guide/node016A.html) the data cache
		68040 - [Flush](../Includes_and_Autodocs_3._guide/node016A.html) matching areas of the data cache
		????? - External cache boards, Virtual Memory Systems, or
			future hardware may patch this vector to best emulate
			the intended behavior.
			With a Bus-Snooping CPU, this function my end up
			doing nothing.

   INPUTS
	address	- Same as initially passed to [CachePreDMA](../Includes_and_Autodocs_3._guide/node01F3.html)
	length	- Same as initially passed to [CachePreDMA](../Includes_and_Autodocs_3._guide/node01F3.html)
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
	exec/execbase.i, [CachePreDMA()](../Includes_and_Autodocs_3._guide/node01F3.html), [CacheClearU()](../Includes_and_Autodocs_3._guide/node01F0.html), [CacheClearE()](../Includes_and_Autodocs_3._guide/node01EF.html)

