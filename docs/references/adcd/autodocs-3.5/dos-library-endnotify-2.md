---
title: dos.library/EndNotify
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-endnotify-2
functions: [StartNotify]
libraries: [dos.library]
---

# dos.library/EndNotify

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	EndNotify -- Ends a notification request (V36)

   SYNOPSIS
	EndNotify(notifystructure)
			D1

	VOID EndNotify(struct [NotifyRequest](autodocs-3.5/include-dos-notify-h.md) *)

   FUNCTION
	Removes a notification request.  Safe to call even if [StartNotify()](autodocs-3.5/dos-library-startnotify-2.md)
	failed.  For NRF_SEND_MESSAGE, it searches your port for any messages
	about the object in question and removes and replies them before
	returning.

   INPUTS
	notifystructure - a structure passed to [StartNotify()](autodocs-3.5/dos-library-startnotify-2.md)

   SEE ALSO
	[StartNotify()](autodocs-3.5/dos-library-startnotify-2.md), [<dos/notify.h>](autodocs-3.5/include-dos-notify-h.md)

---

## See Also

- [StartNotify — dos.library](../autodocs/dos.library.md#startnotify)
