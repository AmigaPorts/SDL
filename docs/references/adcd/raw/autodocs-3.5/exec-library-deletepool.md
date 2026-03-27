# exec.library/DeletePool



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
	poolHeader - as returned by [CreatePool()](../Includes_and_Autodocs_3._guide/node01FD.html).

    SEE ALSO
	[CreatePool()](../Includes_and_Autodocs_3._guide/node01FD.html), [AllocPooled()](../Includes_and_Autodocs_3._guide/node01E8.html), [FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html)

