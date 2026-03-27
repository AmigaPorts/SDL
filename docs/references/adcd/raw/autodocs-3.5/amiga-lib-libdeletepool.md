# amiga.lib/LibDeletePool



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
	from the stack just like the C code interface for [DeletePool()](../Includes_and_Autodocs_3._guide/node0202.html)
	in amiga.lib.  The assembly code interface is with the symbol
	_AsmDeletePool: and takes the parameters in registers with the
	additional parameter of [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) being in a6 which can be used
	from SAS/C 6 by a prototype of:

	void __asm AsmDeletePool(register __a0 void *,
	                         register __a6 struct [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) *);

	Frees all memory in all puddles of the specified pool header, then
	deletes the pool header.  Individual free calls are not needed.

    INPUTS
	poolHeader - as returned by [LibCreatePool()](../Includes_and_Autodocs_3._guide/node0044.html).

    SEE ALSO
	[CreatePool()](../Includes_and_Autodocs_3._guide/node01FD.html), [AllocPooled()](../Includes_and_Autodocs_3._guide/node01E8.html), [FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html),
	[LibCreatePool()](../Includes_and_Autodocs_3._guide/node0044.html), [LibAllocPooled()](../Includes_and_Autodocs_3._guide/node0043.html), [LibFreePooled()](../Includes_and_Autodocs_3._guide/node0046.html)

