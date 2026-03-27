# exec.library/AttemptSemaphoreShared



   NAME
	AttemptSemaphoreShared -- try to obtain without blocking       (V37)

   SYNOPSIS
	success = AttemptSemaphoreShared(signalSemaphore)
	D0			         A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AttemptSemaphoreShared(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *);

   FUNCTION
	This call is similar to [ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), except that it
	will not block if the semaphore could not be locked.

   INPUT

       signalSemaphore -- an initialized signal semaphore structure
   RESULT
	success -- TRUE if the semaphore was granted, false if some
	    other task already possessed the semaphore in exclusive mode.

   NOTE
	This call does NOT preserve registers.

	Starting in V39 this call will grant the semaphore if the
	caller is already the owner of an exclusive lock on the semaphore.
	In pre-V39 systems this would not be the case.  If you need this
	feature you can do the following workaround:

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) myAttemptSempahoreShared(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *ss)
	{
	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) result;

		/* Try for a shared semaphore */
		if (!(result=AttemptSemaphoreShared(ss)))
		{
			/* Now try for the exclusive one... */
			result=AttempSemaphore(ss);
		}
		return(result);
	}

   SEE ALSO
	[ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html) [ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html),
	[exec/semaphores.h](../Includes_and_Autodocs_3._guide/node0647.html)

