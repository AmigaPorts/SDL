---
title: asl.library/ActivateAslRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: asl-library-activateaslrequest
functions: [AllocAslRequest, AslRequest]
libraries: [asl.library]
---

# asl.library/ActivateAslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ActivateAslRequest -- attempt to activate an asl requester. (V44)

   SYNOPSIS
	ActivateAslRequest(requester);
	                      A0

	VOID ActivateAslRequest(APTR requester);

   FUNCTION
	The different types of asl requesters are modal (as of V44). Yet at
	times it may be necessary to activate a modal requester from a different
	task context.

   INPUTS
	requester - requester obtained from [AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md), or NULL in
		    which case this function does nothing.

   SEE ALSO
	[AslRequest()](autodocs-3.5/asl-library-aslrequest-2.md)

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
