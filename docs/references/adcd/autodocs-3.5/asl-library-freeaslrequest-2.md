---
title: asl.library/FreeAslRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: asl-library-freeaslrequest-2
functions: [AllocAslRequest, AslRequest, FreeAslRequest]
libraries: [asl.library]
---

# asl.library/FreeAslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeAslRequest -- frees resources allocated by [AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md). (V36)

   SYNOPSIS
	FreeAslRequest(requester);
		       A0

	VOID FreeAslRequest(APTR);

   FUNCTION
	FreeAslRequest() frees any system resources allocated by
	[AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md). Once a requester has been freed, it can no
	longer be used with other calls to [AslRequest()](autodocs-3.5/asl-library-aslrequest-2.md).

   INPUTS
	requester - requester obtained from [AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md), or NULL in
		    which case this function does nothing.

   SEE ALSO
	[AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md)

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
- [FreeAslRequest — asl.library](../autodocs/asl.library.md#freeaslrequest)
