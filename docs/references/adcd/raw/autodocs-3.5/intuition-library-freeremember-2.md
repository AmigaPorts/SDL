# intuition.library/FreeRemember



    NAME
	FreeRemember -- Free memory allocated by calls to [AllocRemember()](../Includes_and_Autodocs_3._guide/node0394.html).

    SYNOPSIS
	FreeRemember( RememberKey, ReallyForget )
		      A0           D0

	VOID FreeRemember( struct [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) **, [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) );

    FUNCTION
	This function frees up memory allocated by the [AllocRemember()](../Includes_and_Autodocs_3._guide/node0394.html) function.
	It will either free up just the [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) structures, which supply the
	link nodes that tie your allocations together, or it will deallocate
	both the link nodes AND your memory buffers too.

	If you want to deallocate just the [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) structure link nodes,
	you should set the ReallyForget argument to FALSE.  However, if you
	want FreeRemember to really deallocate all the memory, including
	both the [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) structure link nodes and the buffers you requested
	via earlier calls to [AllocRemember()](../Includes_and_Autodocs_3._guide/node0394.html), then you should set the
	ReallyForget argument to TRUE.

	NOTE WELL: Once you call this function passing it FALSE, the
	linkages between all the memory chunks are lost, and you
	cannot subsequently use FreeRemember() to free them.

    INPUTS
	RememberKey = the address of a pointer to struct [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429).  This
```c
           pointer should either be NULL or set to some value (possibly
           NULL) by a call to [AllocRemember()](../Includes_and_Autodocs_3._guide/node0394.html).
```
	ReallyForget = a [BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) FALSE or TRUE describing, respectively,
```c
           whether you want to free up only the [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) nodes or
           if you want this procedure to really forget about all of
           the memory, including both the nodes and the memory buffers
           referenced by the nodes.

    EXAMPLE
```
	struct [Remember](../Includes_and_Autodocs_3._guide/node05E0.html#line1429) *RememberKey;
	RememberKey = NULL;
	AllocRemember(&RememberKey, BUFSIZE, MEMF_CHIP);
	FreeRemember(&RememberKey, TRUE);

    RESULT
	None

    BUGS

    SEE ALSO
	[AllocRemember()](../Includes_and_Autodocs_3._guide/node0394.html), [exec.library/FreeMem()](../Includes_and_Autodocs_3._guide/node020E.html)

