# exec.library/ObtainSemaphoreShared



    NAME
	ObtainSemaphoreShared -- gain shared access to a semaphore (V36)

    SYNOPSIS
	ObtainSemaphoreShared(signalSemaphore)
	                      a0

	void ObtainSemaphoreShared(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *);

    FUNCTION
	A lock on a signal semaphore may either be exclusive, or shared.
	Exclusive locks are granted by the [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html) and
	[AttemptSemaphore()](../Includes_and_Autodocs_3._guide/node01EC.html) functions.  Shared locks are granted by
	ObtainSemaphoreShared().  Calls may be nested.

	Any number of tasks may simultaneously hold a shared lock on a
	semaphore.  Only one task may hold an exclusive lock.  A typical
	application is a list that is often read, but only occasionally
	written to.

	Any exlusive locker will be held off until all shared lockers
	release the semaphore.  Likewise, if an exlusive lock is held,
	all potential shared lockers will block until the exclusive lock
	is released.  All shared lockers are restarted at the same time.

    EXAMPLE
		ObtainSemaphoreShared(ss);
		/* read data */
		ReleaseSemaohore(ss);

		ObtainSemaphore(ss);
		/* modify data */
		ReleaseSemaohore(ss);

    NOTES
	While this function was added for V36, the feature magically works
	with all older semaphore structures.

	A task owning a shared lock must not attempt to get an exclusive
	lock on the same semaphore.

	Starting in V39, if the caller already has an exclusive lock on the
	semaphore it will return with another nesting of the lock.  Pre-V39
	this would cause a deadlock.  For pre-V39 use, you can use the
	following workaround:

		/* Try to get the shared semaphore */
		if (!AttemptSemaphoreShared(ss))
		{
			/* Check if we can get the exclusive version */
			if (!AttemptSemaphore(ss))
			{
				/* Oh well, wait for the shared lock */
				ObtainSemaphoreShared(ss));
			}
		}
		:
		:
		ReleaseSemaphore(ss);

    INPUT
	signalSemaphore -- an initialized signal semaphore structure

    NOTE
	This call is guaranteed to preserve all registers, starting with
	V37 exec.

    RESULT

    SEE ALSO
	[ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html), [InitSemaphore()](../Includes_and_Autodocs_3._guide/node0217.html), [ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html),
	[AttemptSemaphore()](../Includes_and_Autodocs_3._guide/node01EC.html), [ObtainSemaphoreList()](../Includes_and_Autodocs_3._guide/node021E.html), [Procure()](../Includes_and_Autodocs_3._guide/node0225.html), [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html)

