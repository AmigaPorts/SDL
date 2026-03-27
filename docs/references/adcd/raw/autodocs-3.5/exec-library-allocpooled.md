# exec.library/AllocPooled



    NAME
	AllocPooled -- [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) memory with the pool manager (V39)

    SYNOPSIS
	memory=AllocPooled(poolHeader,memSize)
	d0                 a0         d0

	void *AllocPooled(void *,ULONG);

    FUNCTION
	[Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) memSize bytes of memory, and return a pointer. NULL is
	returned if the allocation fails.

	Doing a [DeletePool()](../Includes_and_Autodocs_3._guide/node0202.html) on the pool will free all of the puddles
	and thus all of the allocations done with AllocPooled() in that
	pool.  (No need to [FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html) each allocation)

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
	that we will be able to make it work in the future.  AllocPooled()
	may well break a [Forbid()](../Includes_and_Autodocs_3._guide/node020C.html) and as such can only be protected
	by a semaphore.

	To track sizes yourself, the following code can be used:
	Assumes a6=ExecBase

	;
	; Function to do AllocVecPooled(Pool,memSize)
	;
	AllocVecPooled:	addq.l	#4,d0		; Get space for tracking
			move.l	d0,-(sp)	; Save the size
			jsr	_LVOAllocPooled(a6)	; Call pool...
			move.l	(sp)+,d1	; Get size back...
			tst.l	d0		; Check for error
			beq.s	avp_fail	; If NULL, failed!
			move.l	d0,a0		; Get pointer...
			move.l	d1,(a0)+	; Store size
			move.l	a0,d0		; Get result
	avp_fail:	rts			; return

	;
	; Function to do FreeVecPooled(pool,memory)
	;
	FreeVecPooled:	move.l	-(a1),d0	; Get size / ajust pointer
			jmp	_LVOFreePooled(a6)

    SEE ALSO
	[FreePooled()](../Includes_and_Autodocs_3._guide/node020F.html), [CreatePool()](../Includes_and_Autodocs_3._guide/node01FD.html), [DeletePool()](../Includes_and_Autodocs_3._guide/node0202.html)

