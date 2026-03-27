---
title: amiga.lib/DeleteStdIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-deletestdio-2
functions: [CreateIORequest]
libraries: [exec.library]
---

# amiga.lib/DeleteStdIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteStdIO - return memory allocated for [IOStdReq](autodocs-3.5/include-exec-io-h.md)

   SYNOPSIS
	DeleteStdIO(ioReq);

	VOID DeleteStdIO(struct [IOStdReq](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	Frees up an [IOStdReq](autodocs-3.5/include-exec-io-h.md) as allocated by [CreateStdIO()](autodocs-3.5/amiga-lib-createstdio-2.md).

   INPUTS
	ioReq - the [IORequest](autodocs-3.5/include-exec-io-h.md) block to be freed, or NULL.

   SEE ALSO
	[CreateStdIO()](autodocs-3.5/amiga-lib-createstdio-2.md), [DeleteExtIO()](autodocs-3.5/amiga-lib-deleteextio-2.md), [exec.library/CreateIORequest()](autodocs-3.5/exec-library-createiorequest-2.md)

---

## See Also

- [CreateIORequest — exec.library](../autodocs/exec.library.md#createiorequest)
