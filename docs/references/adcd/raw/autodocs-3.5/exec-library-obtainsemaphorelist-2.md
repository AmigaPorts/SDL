# exec.library/ObtainSemaphoreList



   NAME
	ObtainSemaphoreList -- get a list of semaphores.

   SYNOPSIS
	ObtainSemaphoreList(list)
			    A0

	void ObtainSemaphoreList(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *);

   FUNCTION
	[Signal](../Includes_and_Autodocs_3._guide/node023D.html) semaphores may be linked together into a list. This function
	takes a list of these semaphores and attempts to lock all of them at
	once. This call is preferable to applying [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html) to each
	element in the list because it attempts to lock all the elements
	simultaneously, and won't deadlock if someone is attempting to lock
	in some other order.

	This function assumes that only one task at a time will attempt to
	lock the entire list of semaphores.  In other words, there needs to
	be a higher level lock (perhaps another signal semaphore...) that is
	used before someone attempts to lock the semaphore list via
	ObtainSemaphoreList().

	Note that deadlocks may result if this call is used AND someone
	attempts to use [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html) to lock more than one semaphore on
	the list.  If you wish to lock more than semaphore (but not all of
	them) then you should obtain the higher level lock (see above)

   INPUT

       list -- a list of signal semaphores
   SEE ALSO
	[ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [InitSemaphore()](../Includes_and_Autodocs_3._guide/node0217.html), [ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html),
	[AttemptSemaphore()](../Includes_and_Autodocs_3._guide/node01EC.html), [ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [Procure()](../Includes_and_Autodocs_3._guide/node0225.html), [Vacate()](../Includes_and_Autodocs_3._guide/node0245.html)

