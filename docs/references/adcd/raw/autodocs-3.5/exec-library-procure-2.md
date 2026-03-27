# exec.library/Procure



   NAME
	Procure -- bid for a semaphore                                   (V39)

   SYNOPSIS
	Procure(semaphore, bidMessage)
		A0	    A1

	VOID Procure(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *, struct [SemaphoreMessage](../Includes_and_Autodocs_3._guide/node0647.html#line50) *);

   FUNCTION
	This function is used to obtain a semaphore in an async manner.
	Like [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html), it will obtain a [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) for you
	but unlike [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html), you will not block until you get
	the semaphore.  Procure() will just post a request for the semaphore
	and will return.  When the semaphore is available (which could
	be at any time) the bidMessage will [ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html) and you will own
	the semaphore.  This lets you wait on multiple semaphores at once
	and to continue processing while waiting for the semaphore.

	NOTE:  Pre-V39, Procure() and [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html) did not work correctly.
	They also did not operate on [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) semaphores.
	Old (and broken) MessageSemaphore use as of V39 will no longer work.

   INPUT
	semaphore - The [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) that you wish to Procure()
	bidMessage- The [SemaphoreMessage](../Includes_and_Autodocs_3._guide/node0647.html#line50) that you wish replied when
		you obtain access to the semaphore.  The message's
		ssm_Semaphore field will point at the semaphore that
		was obtained.  If the ssm_Semaphore field is NULL,
		the Procure() was aborted via [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html).
		The mn_ReplyPort field of the message must point to
		a valid message port.
		To obtain a shared semaphore, the ln_Name field
		must be set to 1.  For an exclusive lock, the ln_Name
		field must be 0.  No other values are valid.

   BUGS
	Before V39, Procure() and [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html) used a different semaphore
	system that was very broken.  This new system is only available
	as of V39 even though the LVOs are the same.

   SEE ALSO
	[ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [InitSemaphore()](../Includes_and_Autodocs_3._guide/node0217.html), [ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html),
	[AttemptSemaphore()](../Includes_and_Autodocs_3._guide/node01EC.html), [ObtainSemaphoreList()](../Includes_and_Autodocs_3._guide/node021E.html), [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html), [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html)

