---
title: amiga.lib/CreatePort
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-createport-2
functions: [CreateMsgPort, FindPort]
libraries: [exec.library]
---

# amiga.lib/CreatePort

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreatePort - [Allocate](autodocs-3.5/exec-library-allocate-2.md) and initialize a new message port

   SYNOPSIS
	port = CreatePort(name,pri)

	struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *CreatePort(STRPTR,LONG);

   FUNCTION
	Allocates and initializes a new message port. The message list
	of the new port will be prepared for use (via NewList).  A signal
	bit will be allocated, and the port will be set to signal your
	task when a message arrives (PA_SIGNAL).

	You *must* use [DeletePort()](autodocs-3.5/amiga-lib-deleteport-2.md) to delete ports created with
	CreatePort()!

   INPUTS
	name - public name of the port, or NULL if the port is not named.
	       The name string is not copied. Most ports do not need names,
	       see notes below on this.
	pri  - Priority used for insertion into the public port list,
	       normally 0.

   RESULT
	port - a new [MsgPort](autodocs-3.5/include-exec-ports-h.md) structure ready for use, or NULL if the port
	       could not be created due to not enough memory or no available
	       signal bit.

   NOTE
	In most cases, ports should not be named. Named ports are used for
	rendez-vous between tasks. Everytime a named port needs to be located,
	the list of all named ports must be traversed. The more named
	ports there are, the longer this list traversal takes. Thus, unless
	you really need to, do not name your ports, which will keep them off
	of the named port list and improve system performance.

   BUGS
	With versions of amiga.lib prior to V37.14, this function would
	not fail even though it couldn't allocate a signal bit. The port
	would be returned with no signal allocated.

   SEE ALSO
	[DeletePort()](autodocs-3.5/amiga-lib-deleteport-2.md), [exec.library/FindPort()](autodocs-3.5/exec-library-findport-2.md), [<exec/ports.h>](autodocs-3.5/include-exec-ports-h.md),
	[exec.library/CreateMsgPort()](autodocs-3.5/exec-library-createmsgport-2.md)

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [FindPort — exec.library](../autodocs/exec.library.md#findport)
