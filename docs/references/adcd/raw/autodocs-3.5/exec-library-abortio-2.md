# exec.library/AbortIO



   NAME
	AbortIO - attempt to abort an in-progress I/O request

   SYNOPSIS
	AbortIO(iORequest)
	        A1

	VOID AbortIO(struct [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) *);

   FUNCTION
	Ask a device to abort a previously started [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17).  This is done
	by calling the device's ABORTIO vector, with your given [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17).


	AbortIO is a command the device that may or may not grant.  If
	successful, the device will stop processing the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17), and
	reply to it earlier than it would otherwise have done.

   NOTE
	AbortIO() does NOT [Remove()](../Includes_and_Autodocs_3._guide/node022F.html) the [IORequest](../Includes_and_Autodocs_3._guide/node0621.html#line17) from your ReplyPort, OR
	wait for it to complete.  After an AbortIO() you must wait normally
	for the reply message before actually reusing the request.

	If a request has already completed when AbortIO() is called, no
	action is taken.

   EXAMPLE
	    AbortIO(timer_request);
	    WaitIO(timer_request);
	    /* [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) is free to be reused */

   INPUTS
	iORequest - pointer to an I/O request block (must have been used
		at least once.  May be active or finished).

   SEE ALSO
	[WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html), [DoIO()](../Includes_and_Autodocs_3._guide/node0204.html), [SendIO()](../Includes_and_Autodocs_3._guide/node0236.html), [CheckIO()](../Includes_and_Autodocs_3._guide/node01F5.html)

