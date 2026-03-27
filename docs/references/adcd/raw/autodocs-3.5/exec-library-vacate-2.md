# exec.library/Vacate



   NAME
	Vacate -- release a bitMessage from [Procure()](../Includes_and_Autodocs_3._guide/node0225.html)                    (V39)

   SYNOPSIS
	Vacate(semaphore, bidMessage)
	       A0         A1

	void Vacate(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *,struct [SemaphoreMessage](../Includes_and_Autodocs_3._guide/node0647.html#line50) *);

   FUNCTION
	This function can be used to release a semaphore obtained via
	[Procure()](../Includes_and_Autodocs_3._guide/node0225.html).  However, the main purpose for this call is to be
	able to remove a bid for a semaphore that has not yet responded.
	This is required when a [Procure()](../Includes_and_Autodocs_3._guide/node0225.html) was issued and the program
	no longer needs to get the semaphore and wishes to cancel the
	[Procure()](../Includes_and_Autodocs_3._guide/node0225.html) request.  The canceled request will be replied with
	the ssm_Semaphore field set to NULL.  If you own the semaphore,
	the message was already replied and only the ssm_Semaphore field
	will be cleared.

	NOTE:  Pre-V39, [Procure()](../Includes_and_Autodocs_3._guide/node0225.html) and Vacate() did not work correctly.
	They also did not operate on [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) semaphores.
	Old (and broken) MessageSemaphore use as of V39 will no longer work.

   INPUT
	semaphore - The [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) that you wish to Vacate()
	bidMessage- The [SemaphoreMessage](../Includes_and_Autodocs_3._guide/node0647.html#line50) that you wish to abort.
		The message's ssm_Semaphore field will be cleared.
		The message will be replied if it is still on the waiting
		list.  If it is not on the waiting list, it is assumed
		that the semaphore is owned and it will be released.

   BUGS
	Before V39, [Procure()](../Includes_and_Autodocs_3._guide/node0225.html) and Vacate() used a different semaphore
	system that was very broken.  This new system is only available
	as of V39 even though the LVOs are the same.

   SEE ALSO
	[ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [InitSemaphore()](../Includes_and_Autodocs_3._guide/node0217.html), [ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html),
	[AttemptSemaphore()](../Includes_and_Autodocs_3._guide/node01EC.html), [ObtainSemaphoreList()](../Includes_and_Autodocs_3._guide/node021E.html), [Procure()](../Includes_and_Autodocs_3._guide/node0225.html), [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html)

