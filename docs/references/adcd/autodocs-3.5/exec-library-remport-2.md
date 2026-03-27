---
title: exec.library/RemPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remport-2
functions: [AddPort, FindPort]
libraries: [exec.library]
---

# exec.library/RemPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemPort -- remove a message port from the system

   SYNOPSIS
	RemPort(port)
		A1

	void RemPort(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	This function removes a message port structure from the system's
	message port list.  Subsequent attempts to rendezvous by name with
	this port will fail.

   INPUTS
	port - pointer to a message port

   SEE ALSO
	[AddPort()](autodocs-3.5/exec-library-addport-2.md), [FindPort()](autodocs-3.5/exec-library-findport-2.md)

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [FindPort — exec.library](../autodocs/exec.library.md#findport)
