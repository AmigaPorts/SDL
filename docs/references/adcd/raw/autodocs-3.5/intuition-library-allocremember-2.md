# intuition.library/AllocRemember



    NAME
	AllocRemember -- [AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html) with tracking to make freeing easy.

    SYNOPSIS
	MemBlock = AllocRemember( RememberKey, Size, Flags )
	D0			  A0	       D0    D1

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) AllocRemember( struct [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) **, ULONG, ULONG );

    FUNCTION
	This routine calls the Exec [AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html) function for you, but also links
	the parameters of the allocation into a master list, so that
	you can simply call the Intuition routine [FreeRemember()](../Includes_and_Autodocs_3._guide/node03B0.html) at a later
	time to deallocate all allocated memory without being required to
	remember the details of the memory you've allocated.

	This routine will have two primary uses:
       -   Let's say that you're doing a long series of allocations in a
           procedure.  If any one of the allocations fails, your program
	    may need to abort the procedure.  Abandoning ship correctly
	    involves freeing up what memory you've already allocated.  This
	    procedure allows you to free up that memory easily, without being
	    required to keep track of how many allocations you've already done,
	    what the sizes of the allocations were, or where the memory was
	    allocated.


```c
       -   Also, in the more general case, you may do all of the allocations
           in your entire program using this routine.  Then, when your
           program is exiting, you can free it all up at once with a
           simple call to [FreeRemember()](../Includes_and_Autodocs_3._guide/node03B0.html).
```
	You create the "anchor" for the allocation master list by creating
	a variable that's a pointer to struct [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429), and initializing
	that pointer to NULL.  This is called the RememberKey.  Whenever
	you call AllocRemember(), the routine actually does two memory
	allocations, one for the memory you want and the other for a copy
	of a [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) structure.  The [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) structure is filled in
	with data describing your memory allocation, and it's linked
	into the master list pointed to by your RememberKey.  Then, to
	free up any memory that's been allocated, all you have to do is
	call [FreeRemember()](../Includes_and_Autodocs_3._guide/node03B0.html) with your RememberKey.

	Please read the [FreeRemember()](../Includes_and_Autodocs_3._guide/node03B0.html) function description, too.  As you will
	see, you can select either to free just the link nodes and keep all the
	allocated memory for yourself, or to free both the nodes and your memory
	buffers.


    INPUTS
	RememberKey = the address of a pointer to struct [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429).  Before the
	very first call to AllocRemember, initialize this pointer to NULL.

	Size = the size in bytes of the memory allocation.  Please refer to the
	    [exec.library/AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html) function for details.
	Flags = the specifications for the memory allocation.  Please refer to
	    the [exec.library/AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html) function for details.

    EXAMPLE
	struct [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) *RememberKey;
	RememberKey = NULL;
	buffer = AllocRemember(&RememberKey, BUFSIZE, MEMF_CHIP);
	if (buffer)
	{
	    /* Use the buffer */
	    ...
	}
	FreeRemember(&RememberKey, TRUE);

    RESULT
	If the memory allocation is successful, this routine returns the byte
	address of your requested memory block.  Also, the node to your block
	will be linked into the list pointed to by your RememberKey variable.
	If the allocation fails, this routine returns NULL and the list pointed
	to by RememberKey, if any, will be unchanged.

    BUGS
	This function makes two allocations for each memory buffer
	you request.  This is neither fast nor good for memory
	fragmentation.

	This function should use the exec AllocPool() function internally,
	at least for the [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) headers.

    SEE ALSO
	[FreeRemember()](../Includes_and_Autodocs_3._guide/node03B0.html), [exec.library/AllocMem()](../Includes_and_Autodocs_3._guide/node01E7.html)

