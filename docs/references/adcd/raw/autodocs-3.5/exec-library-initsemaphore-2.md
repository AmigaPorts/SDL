# exec.library/InitSemaphore



   NAME
	InitSemaphore -- initialize a signal semaphore

   SYNOPSIS
	InitSemaphore(signalSemaphore)
		      A0

	void InitSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *);

   FUNCTION
	This function initializes a signal semaphore and prepares it for
	use.  It does not allocate anything, but does initialize list
	pointers and the semaphore counters.

	Semaphores are often used to protect critical data structures
	or hardware that can only be accessed by one task at a time.
	After initialization, the address of the [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) may be
	made available to any number of tasks.  Typically a task will
	try to [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html), passing this address in.  If no other
	task owns the semaphore, then the call will lock and return
	quickly.  If more tasks try to [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html), they will
	be put to sleep.  When the owner of the semaphore releases
	it, the next waiter in turn will be woken up.

	Semaphores are often preferable to the old-style [Forbid()/Permit()](../Includes_and_Autodocs_3._guide/node0224.html)
	type arbitration.  With [Forbid()/Permit()](../Includes_and_Autodocs_3._guide/node0224.html) *all* other tasks are
	prevented from running.  With semaphores, only those tasks that
	need access to whatever the semaphore protects are subject
	to waiting.

   INPUT
	signalSemaphore -- a signal semaphore structure (with all fields
			   set to zero before the call)

   SEE ALSO
	[ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html), [ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [AttemptSemaphore()](../Includes_and_Autodocs_3._guide/node01EC.html),
	[ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html), [Procure()](../Includes_and_Autodocs_3._guide/node0225.html), [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html), [exec/semaphores.h](../Includes_and_Autodocs_3._guide/node0647.html)

