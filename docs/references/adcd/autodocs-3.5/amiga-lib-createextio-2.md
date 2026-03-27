---
title: amiga.lib/CreateExtIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-createextio-2
functions: [CreateMsgPort]
libraries: [exec.library]
---

# amiga.lib/CreateExtIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateExtIO -- create an [IORequest](autodocs-3.5/include-exec-io-h.md) structure

   SYNOPSIS
	ioReq = CreateExtIO(port,ioSize);

	struct [IORequest](autodocs-3.5/include-exec-io-h.md) *CreateExtIO(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, ULONG);

   FUNCTION
	Allocates memory for and initializes a new IO request block
	of a user-specified number of bytes. The number of bytes
	MUST be the size of a legal [IORequest](autodocs-3.5/include-exec-io-h.md) (or extended IORequest)
	or very nasty things will happen.

   INPUTS
	port - an already initialized message port to be used for this IO
	       request's reply port. If this is NULL this function fails.
	ioSize - the size of the IO request to be created.

   RESULT
	ioReq - a new IO [Request](autodocs-3.5/intuition-library-request-2.md) block, or NULL if there was not enough memory

   EXAMPLE
	if (ioReq = CreateExtIO(CreatePort(NULL,0),sizeof(struct IOExtTD)))

   SEE ALSO
	[DeleteExtIO()](autodocs-3.5/amiga-lib-deleteextio-2.md), [CreatePort()](autodocs-3.5/amiga-lib-createport-2.md), [exec.library/CreateMsgPort()](autodocs-3.5/exec-library-createmsgport-2.md)

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
