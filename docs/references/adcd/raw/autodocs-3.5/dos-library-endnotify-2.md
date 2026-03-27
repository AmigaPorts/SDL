# dos.library/EndNotify



   NAME
	EndNotify -- Ends a notification request (V36)

   SYNOPSIS
	EndNotify(notifystructure)
			D1

	VOID EndNotify(struct [NotifyRequest](../Includes_and_Autodocs_3._guide/node0634.html#line50) *)

   FUNCTION
	Removes a notification request.  Safe to call even if [StartNotify()](../Includes_and_Autodocs_3._guide/node01C2.html)
	failed.  For NRF_SEND_MESSAGE, it searches your port for any messages
	about the object in question and removes and replies them before
	returning.

   INPUTS
	notifystructure - a structure passed to [StartNotify()](../Includes_and_Autodocs_3._guide/node01C2.html)

   SEE ALSO
	[StartNotify()](../Includes_and_Autodocs_3._guide/node01C2.html), [<dos/notify.h>](../Includes_and_Autodocs_3._guide/node0634.html)

