---
title: exec.library/FindPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-findport-2
functions: [FindPort, Forbid, Permit]
libraries: [exec.library]
---

# exec.library/FindPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindPort -- find a given system message port

   SYNOPSIS
	port = FindPort(name)
	D0		A1

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *FindPort(STRPTR);

   FUNCTION
	This function will search the system message port list for a port
	with the given name.  The first port matching this name will be
	returned.  No arbitration of the port list is done.  This function
	MUST be protected with A [Forbid()/Permit()](autodocs-3.5/exec-library-permit-2.md) pair!

   EXAMPLE
	#include [<exec/types.h>](autodocs-3.5/include-exec-types-h.md)
	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *FindPort();

	ULONG SafePutToPort(message, portname)
	struct [Message](autodocs-3.5/include-exec-ports-h.md) *message;
	[STRPTR](autodocs-3.5/include-exec-types-h.md)          portname;
	{
	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *port;

	    Forbid();
		port = FindPort(portname);
		if (port)
		    PutMsg(port,message);
	    Permit();
	    return((ULONG)port); /* If zero, the port has gone away */
	}

   INPUT
	name - name of the port to find

   RETURN
	port - a pointer to the message port, or zero if
		not found.

---

## See Also

- [FindPort — exec.library](../autodocs/exec.library.md#findport)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
