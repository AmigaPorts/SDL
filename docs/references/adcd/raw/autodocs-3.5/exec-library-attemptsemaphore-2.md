# exec.library/AttemptSemaphore



   NAME
	AttemptSemaphore -- try to obtain without blocking

   SYNOPSIS
	success = AttemptSemaphore(signalSemaphore)
	D0			   A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AttemptSemaphore(struct [SignalSemaphore](../Includes_and_Autodocs_3._guide/node0647.html#line39) *);

   FUNCTION
	This call is similar to [ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html), except that it will not
	block if the semaphore could not be locked.

   INPUT

       signalSemaphore -- an initialized signal semaphore structure
   RESULT
	success -- TRUE if the semaphore was locked, false if some
	    other task already possessed the semaphore.

    NOTE
	This call does NOT preserve registers.

   SEE ALSO
	[ObtainSemaphore()](../Includes_and_Autodocs_3._guide/node021D.html) [ObtainSemaphoreShared()](../Includes_and_Autodocs_3._guide/node021F.html), [ReleaseSemaphore()](../Includes_and_Autodocs_3._guide/node0228.html),
	[exec/semaphores.h](../Includes_and_Autodocs_3._guide/node0647.html)

