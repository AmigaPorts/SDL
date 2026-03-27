# dos.library/StartNotify



   NAME
	StartNotify -- Starts notification on a file or directory (V36)

   SYNOPSIS
	success = StartNotify(notifystructure)
	D0                          D1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) StartNotify(struct [NotifyRequest](../Includes_and_Autodocs_3._guide/node0634.html#line50) *)

   FUNCTION
	Posts a notification request.  Do not modify the notify structure while
	it is active.  You will be notified when the file or directory changes.
	For files, you will be notified after the file is closed.  Not all
	filesystems will support this: applications should NOT require it.  In
	particular, most network filesystems won't support it.

   INPUTS
	notifystructure - A filled-in [NotifyRequest](../Includes_and_Autodocs_3._guide/node0634.html#line50) structure

   RESULT
	success - Success/failure of request

   BUGS
	The V36 floppy/HD filesystem doesn't actually send notifications.  The
	V36 ram handler (ram:) does.  This has been fixed for V37.

   SEE ALSO
	[EndNotify()](../Includes_and_Autodocs_3._guide/node0158.html), [<dos/notify.h>](../Includes_and_Autodocs_3._guide/node0634.html)

