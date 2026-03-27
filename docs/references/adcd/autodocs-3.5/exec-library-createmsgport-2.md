---
title: exec.library/CreateMsgPort
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-createmsgport-2
functions: [AddPort, CreateMsgPort, DeleteMsgPort, RemPort]
libraries: [exec.library]
---

# exec.library/CreateMsgPort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateMsgPort - [Allocate](autodocs-3.5/exec-library-allocate-2.md) and initialize a new message port  (V36)

   SYNOPSIS
	CreateMsgPort()

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) * CreateMsgPort(void);

   FUNCTION
	Allocates and initializes a new message port.  The message list
	of the new port will be prepared for use (via NewList).  A signal
	bit will be allocated, and the port will be set to signal your
	task when a message arrives (PA_SIGNAL).

	You *must* use [DeleteMsgPort()](autodocs-3.5/exec-library-deletemsgport-2.md) to delete ports created with
	CreateMsgPort()!

   RESULT
	[MsgPort](autodocs-3.5/include-exec-ports-h.md) - A new [MsgPort](autodocs-3.5/include-exec-ports-h.md) structure ready for use, or NULL if out of
		memory or signals.  If you wish to add this port to the public
		port list, fill in the ln_Name and ln_Pri fields, then call
		[AddPort()](autodocs-3.5/exec-library-addport-2.md).  Don't forget RemPort()!

   SEE ALSO
	[DeleteMsgPort()](autodocs-3.5/exec-library-deletemsgport-2.md), [exec/AddPort()](autodocs-3.5/exec-library-addport-2.md), [exec/ports.h](autodocs-3.5/include-exec-ports-h.md), [amiga.lib/CreatePort()](autodocs-3.5/amiga-lib-createport-2.md)

---

## See Also

- [AddPort — exec.library](../autodocs/exec.library.md#addport)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteMsgPort — exec.library](../autodocs/exec.library.md#deletemsgport)
- [RemPort — exec.library](../autodocs/exec.library.md#remport)
