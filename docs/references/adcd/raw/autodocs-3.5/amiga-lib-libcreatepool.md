# amiga.lib/LibCreatePool



    NAME
	LibCreatePool -- Generate a private memory pool header (V33)

    SYNOPSIS
	newPool=LibCreatePool(memFlags,puddleSize,threshSize)
	a0                    d0       d1         d2

	void *LibCreatePool(ULONG,ULONG,ULONG);

    FUNCTION
	This function is a copy of the pool functions in V39 and up of
	EXEC.  In fact, if you are running in V39, this function will
	notice and call the EXEC function.  This function works in
	V33 and up (1.2) Amiga system.

	The C code interface is _LibCreatePool() and takes its arguments
	from the stack just like the C code interface for [CreatePool()](../Includes_and_Autodocs_3._guide/node01FD.html)
	in amiga.lib.  The assembly code interface is with the symbol
	_AsmCreatePool: and takes the parameters in registers with the
	additional parameter of [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) being in a6 which can be used
	from SAS/C 6 by a prototype of:

	void * __asm AsmCreatePool(register __d0 ULONG,
	                           register __d1 ULONG,
	                           register __d2 ULONG,
	                           register __a6 struct [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) *);

	[Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) and prepare a new memory pool header.	Each pool is a
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
	memFlags - a memory flags specifier, as taken by [AllocMem](../Includes_and_Autodocs_3._guide/node01E7.html).
	puddleSize - the size of Puddles...
	threshSize - the largest allocation that goes into normal puddles
	             This *MUST* be less than or equal to puddleSize
	             (LibCreatePool() will fail if it is not)

    RESULT
	The address of a new pool header, or NULL for error.

    SEE ALSO
	[DeletePool()](../Includes_and_Autodocs_3._guide/node0202.html), [AllocPooled()](../Includes_and_Autodocs_3._guide/node01E8.html), [FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html), exec/memory.i,
	[LibDeletePool()](../Includes_and_Autodocs_3._guide/node0045.html), [LibAllocPooled()](../Includes_and_Autodocs_3._guide/node0043.html), [LibFreePooled()](../Includes_and_Autodocs_3._guide/node0046.html)

