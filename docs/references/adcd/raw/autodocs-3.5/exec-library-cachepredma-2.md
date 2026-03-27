# exec.library/CachePreDMA



   NAME
	CachePreDMA - Take actions prior to hardware DMA  (V37)

   SYNOPSIS
	paddress = CachePreDMA(vaddress,&length,flags)
	d0                     a0       a1      d0

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) CachePreDMA(APTR,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *,ULONG);

   FUNCTION
	Take all appropriate steps before Direct Memory Access (DMA).  This
	function is primarily intended for writers of DMA device drivers.  The
	action will depend on the CPU type installed, caching modes, and the
	state of any Memory Management [Unit](../Includes_and_Autodocs_3._guide/node05FB.html#line30) (MMU) activity.

	This function supports advanced cache architectures that have
	"copyback" modes.  With copyback, write data may be cached, but not
	actually flushed out to memory.  If the CPU has unflushed data at the
	time of DMA, data may be lost.

	As implemented
		68000 - Do nothing
		68010 - Do nothing
		68020 - Do nothing
		68030 - Do nothing
		68040 - [Write](../Includes_and_Autodocs_3._guide/node01D1.html) any matching dirty cache lines back to memory.
			As a side effect of the 68040's design, matching data
			cache lines are also invalidated -- future CPUs may
			be different.
		????? - External cache boards, Virtual Memory Systems, or
			future hardware may patch this vector to best emulate
			the intended behavior.
			With a Bus-Snooping CPU, this function my end up
			doing nothing.

   INPUTS
	address	- Base address to start the action.
	length	- Pointer to a longword with a length.
	flags	- Values:
			DMA_Continue - Indicates this call is to complete
			a prior request that was broken up.

			DMA_ReadFromRAM - Indicates that this DMA is a
			read from RAM to the DMA device (ie - a write
			to the hard drive)  This flag is not required
			but if used must match in both the PreDMA and
			PostDMA calls.  This flag *should* be used to
			help the system provide the best performance.
			This flag is safe in all versions of CachePreDMA()

   RESULTS
	paddress- Physical address that corresponds to the input virtual
		  address.
	&length	- This length value will be updated to reflect the contiguous
		  length of physical memory present at paddress.  This may
		  be smaller than the requested length.  To get the mapping
		  for the next chunk of memory, call the function again with
		  a new address, length, and the DMA_Continue flag.

   NOTE
	Due to processor granularity, areas outside of the address range
	may be affected by the cache flushing actions.  Care has been taken
	to ensure that no harm is done outside the range, and that activities
	on overlapping cache lines won't harm data.

   SEE ALSO
	exec/execbase.i, [CachePostDMA()](../Includes_and_Autodocs_3._guide/node01F2.html), [CacheClearU()](../Includes_and_Autodocs_3._guide/node01F0.html), [CacheClearE()](../Includes_and_Autodocs_3._guide/node01EF.html)

