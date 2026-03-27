# exec.library/CreatePool



    NAME
	CreatePool -- Generate a private memory pool header (V39)

    SYNOPSIS
	newPool=CreatePool(memFlags,puddleSize,threshSize)
	d0                 d0       d1         d2

	void *CreatePool(ULONG,ULONG,ULONG);

    FUNCTION
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
	             (CreatePool() will fail if it is not)

    RESULT
	The address of a new pool header, or NULL for error.

    SEE ALSO
	[DeletePool()](../Includes_and_Autodocs_3._guide/node0202.html), [AllocPooled()](../Includes_and_Autodocs_3._guide/node01E8.html), [FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html), exec/memory.i

