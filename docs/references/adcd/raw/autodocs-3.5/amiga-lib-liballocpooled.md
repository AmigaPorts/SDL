# amiga.lib/LibAllocPooled



    NAME
	LibAllocPooled -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) memory with the pool manager (V33)

    SYNOPSIS
	memory=LibAllocPooled(poolHeader,memSize)
	d0                    a0         d0

	void *LibAllocPooled(void *,ULONG);

    FUNCTION
	This function is a copy of the pool functions in V39 and up of
	EXEC.  In fact, if you are running in V39, this function will
	notice and call the EXEC function.  This function works in
	V33 and up (1.2) Amiga system.

	The C code interface is _LibAllocPooled() and takes its arguments
	from the stack just like the C code interface for [AllocPooled()](../Includes_and_Autodocs_3._guide/node01E8.html)
	in amiga.lib.  The assembly code interface is with the symbol
	_AsmAllocPooled: and takes the parameters in registers with the
	additional parameter of [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) being in a6 which can be used
	from SAS/C 6 by a prototype of:

	void * __asm AsmAllocPooled(register __a0 void *,
	                            register __d0 ULONG,
	                            register __a6 struct [ExecBase](../Includes_and_Autodocs_3._guide/node0609.html#line33) *);

	[Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) memSize bytes of memory, and return a pointer. NULL is
	returned if the allocation fails.

	Doing a [LibDeletePool()](../Includes_and_Autodocs_3._guide/node0045.html) on the pool will free all of the puddles
	and thus all of the allocations done with LibAllocPooled() in that
	pool.  (No need to [LibFreePooled()](../Includes_and_Autodocs_3._guide/node0046.html) each allocation)

    INPUTS
	memSize - the number of bytes to allocate
	poolHeader - a specific private pool header.

    RESULT
	A pointer to the memory, or NULL.
	The memory block returned is long word aligned.

    NOTES
	The pool function do not protect an individual pool from
	multiple accesses.  The reason is that in most cases the pools
	will be used by a single task.  If your pool is going to
	be used by more than one task you must Semaphore protect
	the pool from having more than one task trying to allocate
	within the same pool at the same time.  Warning:  [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html)
	protection *will not work* in the future.  *Do NOT* assume
	that we will be able to make it work in the future.  LibAllocPooled()
	may well break a [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html) and as such can only be protected
	by a semaphore.

	To track sizes yourself, the following code can be used:
	*Assumes a6=ExecBase*

	;
	; Function to do AllocVecPooled(Pool,memSize)
	;
	AllocVecPooled:	addq.l	#4,d0		; Get space for tracking
			move.l	d0,-(sp)	; Save the size
			jsr	LibAllocPooled	; Call pool...
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
			jmp	[LibFreePooled](../Includes_and_Autodocs_3._guide/node0046.html)

    SEE ALSO
	[FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html), [CreatePool()](../Includes_and_Autodocs_3._guide/node01FD.html), [DeletePool()](../Includes_and_Autodocs_3._guide/node0202.html),
	[LibFreePooled()](../Includes_and_Autodocs_3._guide/node0046.html), [LibCreatePool()](../Includes_and_Autodocs_3._guide/node0044.html), [LibDeletePool()](../Includes_and_Autodocs_3._guide/node0045.html)

