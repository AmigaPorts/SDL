---
title: exec.library/DeleteIORequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-deleteiorequest-2
functions: [CreateIORequest, DeleteIORequest]
libraries: [exec.library]
---

# exec.library/DeleteIORequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteIORequest() - Free a request made by [CreateIORequest()](autodocs-3.5/exec-library-createiorequest-2.md)  (V36)

   SYNOPSIS
	DeleteIORequest( ioReq );
	                 a0

	void DeleteIORequest(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	Frees up an IO request as allocated by [CreateIORequest()](autodocs-3.5/exec-library-createiorequest-2.md).

   INPUTS
	ioReq - A pointer to the [IORequest](autodocs-3.5/include-exec-io-h.md) block to be freed, or NULL.
		This function uses the mn_Length field to determine how
		much memory to free.

   SEE ALSO
	[CreateIORequest()](autodocs-3.5/exec-library-createiorequest-2.md), [amiga.lib/DeleteExtIO()](autodocs-3.5/amiga-lib-deleteextio-2.md)

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
- [DeleteIORequest — exec.library](../autodocs/exec.library.md#deleteiorequest)
