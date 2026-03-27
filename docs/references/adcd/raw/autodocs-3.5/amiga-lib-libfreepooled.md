# amiga.lib/LibFreePooled



    NAME
	LibFreePooled -- Free pooled memory  (V33)

    SYNOPSIS
	LibFreePooled(poolHeader,memory,memSize)
		      a0         a1     d0

	void LibFreePooled(void *,void *,ULONG);

    FUNCTION
	This function is a copy of the pool functions in V39 and up of
	EXEC.  In fact, if you are running in V39, this function will
	notice and call the EXEC function.  This function works in
	V33 and up (1.2) Amiga system.

	The C code interface is _LibFreePooled() and takes its arguments
	from the stack just like the C code interface for [FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html)
	in amiga.lib.  The assembly code interface is with the symbol
	_AsmFreePooled: and takes the parameters in registers with the
	additional parameter of [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) being in a6 which can be used
	from SAS/C 6 by a prototype of:

	void __asm AsmFreePooled(register __a0 void *,
	                         register __a1 void *,
	                         register __d0 ULONG,
	                         register __a6 struct [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) *);

	Deallocates memory allocated by [LibAllocPooled()](../Includes_and_Autodocs_3._guide/node0043.html).  The size of the
	allocation *MUST* match the size given to [LibAllocPooled()](../Includes_and_Autodocs_3._guide/node0043.html).
	The reason the pool functions do not track individual allocation
	sizes is because many of the uses of pools have small allocation
	sizes and the tracking of the size would be a large overhead.

	Only memory allocated by [LibAllocPooled()](../Includes_and_Autodocs_3._guide/node0043.html) may be freed with this
	function!

	Doing a [LibDeletePool()](../Includes_and_Autodocs_3._guide/node0045.html) on the pool will free all of the puddles
	and thus all of the allocations done with [LibAllocPooled()](../Includes_and_Autodocs_3._guide/node0043.html) in that
	pool.  (No need to LibFreePooled() each allocation)

    INPUTS
	memory - pointer to memory allocated by [AllocPooled](../Includes_and_Autodocs_3._guide/node01E8.html).
	poolHeader - a specific private pool header.

    NOTES
	The pool function do not protect an individual pool from
	multiple accesses.  The reason is that in most cases the pools
	will be used by a single task.  If your pool is going to
	be used by more than one task you must Semaphore protect
	the pool from having more than one task trying to allocate
	within the same pool at the same time.  Warning:  [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html)
	protection *will not work* in the future.  *Do NOT* assume
	that we will be able to make it work in the future.  LibFreePooled()
	may well break a [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html) and as such can only be protected
	by a semaphore.

	To track sizes yourself, the following code can be used:
	*Assumes a6=ExecBase*

	;
	; Function to do AllocVecPooled(Pool,memSize)
	;
	AllocVecPooled:	addq.l	#4,d0		; Get space for tracking
			move.l	d0,-(sp)	; Save the size
			jsr	[LibAllocPooled](../Includes_and_Autodocs_3._guide/node0043.html)	; Call pool...
			move.l	(sp)+,d1	; Get size back...
			tst.l	d0		; Check for error
			beq.s	avp_fail	; If NULL, failed!
			move.l	d0,a0		; Get pointer...
			move.l	d1,(a0)+	; Store size
			move.l	a0,d0		; Get result
	avp_fail:	rts			; return

	;
	; Function to do LibFreeVecPooled(pool,memory)
	;
	FreeVecPooled:	move.l	-(a1),d0	; Get size / ajust pointer
			jmp	LibFreePooled

    SEE ALSO
	[AllocPooled()](../Includes_and_Autodocs_3._guide/node01E8.html), [CreatePool()](../Includes_and_Autodocs_3._guide/node01FD.html), [DeletePool()](../Includes_and_Autodocs_3._guide/node0202.html),
	[LibAllocPooled()](../Includes_and_Autodocs_3._guide/node0043.html), [LibCreatePool()](../Includes_and_Autodocs_3._guide/node0044.html), [LibDeletePool()](../Includes_and_Autodocs_3._guide/node0045.html)

