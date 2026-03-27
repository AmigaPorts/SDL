---
title: amiga.lib/DeletePort
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-deleteport-2
functions: []
libraries: []
---

# amiga.lib/DeletePort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeletePort - free a message port created by [CreatePort()](autodocs-3.5/amiga-lib-createport-2.md)

   SYNOPSIS
	DeletePort(port)

	VOID DeletePort(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	Frees a message port created by [CreatePort](autodocs-3.5/amiga-lib-createport-2.md). All messages that
	may have been attached to this port must have already been
	replied before this function is called.

   INPUTS
	port - message port to delete

   SEE ALSO
	[CreatePort()](autodocs-3.5/amiga-lib-createport-2.md)

