# exec.library/RemSemaphore



   NAME
	RemSemaphore -- remove a signal semaphore from the system

   SYNOPSIS
	RemSemaphore(signalSemaphore)
		     A1

	void RemSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *);

   FUNCTION
	This function removes a signal semaphore structure from the
	system's signal semaphore list.  Subsequent attempts to
	rendezvous by name with this semaphore will fail.

   INPUTS

       signalSemaphore -- an initialized signal semaphore structure
   SEE ALSO
	[AddSemaphore()](../Includes_and_Autodocs_3._guide/node01E0.html), [FindSemaphore()](../Includes_and_Autodocs_3._guide/node020A.html)

