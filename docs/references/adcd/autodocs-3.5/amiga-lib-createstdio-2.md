---
title: amiga.lib/CreateStdIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-createstdio-2
functions: [CreateIORequest]
libraries: [exec.library]
---

# amiga.lib/CreateStdIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateStdIO -- create an [IOStdReq](autodocs-3.5/include-exec-io-h.md) structure

   SYNOPSIS
	ioReq = CreateStdIO(port);

	struct [IOStdReq](autodocs-3.5/include-exec-io-h.md) *CreateStdIO(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *)

   FUNCTION
	Allocates memory for and initializes a new [IOStdReq](autodocs-3.5/include-exec-io-h.md) structure.

   INPUTS
	port - an already initialized message port to be used for this IO
	       request's reply port. If this is NULL this function fails.

   RESULT
	ioReq - a new [IOStdReq](autodocs-3.5/include-exec-io-h.md) structure, or NULL if there was not enough
		memory

   SEE ALSO
	[DeleteStdIO()](autodocs-3.5/amiga-lib-deletestdio-2.md), [CreateExtIO()](autodocs-3.5/amiga-lib-createextio-2.md), [exec.library/CreateIORequest()](autodocs-3.5/exec-library-createiorequest-2.md)

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
