---
title: exec.library/CreateIORequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-createiorequest-2
functions: [CreateIORequest, CreateMsgPort, DeleteIORequest]
libraries: [exec.library]
---

# exec.library/CreateIORequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateIORequest() -- create an [IORequest](autodocs-3.5/include-exec-io-h.md) structure  (V36)

   SYNOPSIS
	ioReq = CreateIORequest( ioReplyPort, size );
	 D0                       A0           D0

	struct [IORequest](autodocs-3.5/include-exec-io-h.md) *CreateIORequest(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, ULONG);

   FUNCTION
	Allocates memory for and initializes a new IO request block
	of a user-specified number of bytes.  The number of bytes
	must be at least as large as a "struct Message".

   INPUTS
	ioReplyPort - Pointer to a port for replies (an initialized message
		port, as created by [CreateMsgPort()](autodocs-3.5/exec-library-createmsgport-2.md) ).  If NULL, this
		function fails.
	size - the size of the IO request to be created.

   RESULT
	ioReq - A pointer to the new [IORequest](autodocs-3.5/include-exec-io-h.md) block, or NULL.

   SEE ALSO
	[DeleteIORequest()](autodocs-3.5/exec-library-deleteiorequest-2.md), [CreateMsgPort()](autodocs-3.5/exec-library-createmsgport-2.md), [amiga.lib/CreateExtIO()](autodocs-3.5/amiga-lib-createextio-2.md)

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [DeleteIORequest — exec.library](../autodocs/exec.library.md#deleteiorequest)
