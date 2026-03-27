# exec.library/ObtainSemaphore



   NAME
	ObtainSemaphore -- gain exclusive access to a semaphore

   SYNOPSIS
	ObtainSemaphore(signalSemaphore)
			A0

	void ObtainSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *);

   FUNCTION
	[Signal](../Includes_and_Autodocs_3._guide/node023D.html) semaphores are used to gain exclusive access to an object.
	ObtainSemaphore is the call used to gain this access.  If another
	user currently has the semaphore locked the call will block until
	the object is available.

	If the current task already has locked the semaphore and attempts to
	lock it again the call will still succeed.  A "nesting count" is
	incremented each time the current owning task of the semaphore calls
	ObtainSemaphore().  This counter is decremented each time
	[ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html) is called.  When the counter returns to zero the
	semaphore is actually released, and the next waiting task is called.

	A queue of waiting tasks is maintained on the stacks of the waiting
	tasks.	Each will be called in turn as soon as the current task
	releases the semaphore.

	[Signal](../Includes_and_Autodocs_3._guide/node023D.html) Semaphores are different than [Procure()/Vacate()](../Includes_and_Autodocs_3._guide/node0245.html) semaphores.
	The former requires less CPU time, especially if the semaphore is
	not currently locked.  They require very little set up and user
	thought.  The latter flavor of semaphore make no assumptions about
	how they are used -- they are completely general.  Unfortunately
	they are not as efficient as signal semaphores, and require the
	locker to have done some setup before doing the call.

   INPUT

       signalSemaphore -- an initialized signal semaphore structure
   NOTE
	This function preserves all registers (see BUGS).

   BUGS
	Until V37, this function could destroy A0.

   SEE ALSO
	[ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [InitSemaphore()](../Includes_and_Autodocs_3._guide/node0217.html), [ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html),
	[AttemptSemaphore()](../Includes_and_Autodocs_3._guide/node01EC.html), [ObtainSemaphoreList()](../Includes_and_Autodocs_3._guide/node021E.html), [Procure()](../Includes_and_Autodocs_3._guide/node0225.html), [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html)

