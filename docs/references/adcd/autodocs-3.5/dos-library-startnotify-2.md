---
title: dos.library/StartNotify
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-startnotify-2
functions: [EndNotify]
libraries: [dos.library]
---

# dos.library/StartNotify

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StartNotify -- Starts notification on a file or directory (V36)

   SYNOPSIS
	success = StartNotify(notifystructure)
	D0                          D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) StartNotify(struct [NotifyRequest](autodocs-3.5/include-dos-notify-h.md) *)

   FUNCTION
	Posts a notification request.  Do not modify the notify structure while
	it is active.  You will be notified when the file or directory changes.
	For files, you will be notified after the file is closed.  Not all
	filesystems will support this: applications should NOT require it.  In
	particular, most network filesystems won't support it.

   INPUTS
	notifystructure - A filled-in [NotifyRequest](autodocs-3.5/include-dos-notify-h.md) structure

   RESULT
	success - Success/failure of request

   BUGS
	The V36 floppy/HD filesystem doesn't actually send notifications.  The
	V36 ram handler (ram:) does.  This has been fixed for V37.

   SEE ALSO
	[EndNotify()](autodocs-3.5/dos-library-endnotify-2.md), [<dos/notify.h>](autodocs-3.5/include-dos-notify-h.md)

---

## See Also

- [EndNotify — dos.library](../autodocs/dos.library.md#endnotify)
