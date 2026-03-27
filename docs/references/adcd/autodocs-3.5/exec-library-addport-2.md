---
title: exec.library/AddPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addport-2
functions: [AddPort, FindPort, RemPort]
libraries: [exec.library]
---

# exec.library/AddPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddPort -- add a public message port to the system

   SYNOPSIS
	AddPort(port)
		A1

	void AddPort(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	This function attaches a message port structure to the system's
	public message port list, where it can be found by the [FindPort()](autodocs-3.5/exec-library-findport-2.md)
	function.  The name and priority fields of the port structure must
	be initialized prior to calling this function.	If the user does
	not require the priority field, it should be initialized to zero.

	Only ports that will be searched for with [FindPort()](autodocs-3.5/exec-library-findport-2.md) need to
	be added to the system list.  In addition, adding ports is often
	useful during debugging.  If the port will be searched for,
	the priority field should be at least 1 (to avoid the large number
	of inactive ports at priority zero).  If the port will be searched
	for often, set the priority in the 50-100 range (so it will be
	before other less used ports).

	Once a port has been added to the naming list, you must be careful
	to remove the port from the list (via RemPort) before deallocating
	its memory.

   NOTE
	A point of confusion is that clearing a [MsgPort](autodocs-3.5/include-exec-ports-h.md) structure to all
	zeros is not enough to prepare it for use.  As mentioned in the
	Exec chapter of the ROM Kernel Manual, the [List](autodocs-3.5/include-exec-lists-h.md) for the [MsgPort](autodocs-3.5/include-exec-ports-h.md)
	must be initialized.  This is automatically handled by AddPort(),
	and [amiga.lib/CreatePort](autodocs-3.5/amiga-lib-createport-2.md).  This initialization can be done manually
	with [amiga.lib/NewList](autodocs-3.5/amiga-lib-newlist-2.md) or the assembly NEWLIST macro.

	Do not AddPort an active port.

   INPUTS
	port - pointer to a message port

   SEE ALSO
	[RemPort()](autodocs-3.5/exec-library-remport-2.md), [FindPort()](autodocs-3.5/exec-library-findport-2.md), [amiga.lib/CreatePort()](autodocs-3.5/amiga-lib-createport-2.md), [amiga.lib/NewList()](autodocs-3.5/amiga-lib-newlist-2.md)

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [FindPort — exec.library](../autodocs/exec.library.md#findport)
- [RemPort — exec.library](../autodocs/exec.library.md#remport)
