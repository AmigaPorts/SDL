---
title: asl.library/AbortAslRequest
manual: autodocs-3.5
chapter: autodocs-3.5
section: asl-library-abortaslrequest
functions: [AllocAslRequest, AslRequest]
libraries: [asl.library]
---

# asl.library/AbortAslRequest

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AbortAslRequest -- attempt to abort an asl requester. (V44)

   SYNOPSIS
	AbortAslRequest(requester);
	                   A0

	VOID AbortAslRequest(APTR requester);

   FUNCTION
	The different types of asl requesters are modal (as of V44). Yet at
	times it may be necessary to abort a modal requester from a different
	task context. AbortAslRequest() will attempt to tell the modal asl
	requester provided to shut down and perform as if the user had clicked
	on the requester's window close gadget. This may take some time to
	complete; be prepared to handle this.

   INPUTS
	requester - requester obtained from [AllocAslRequest()](autodocs-3.5/asl-library-allocaslrequest-2.md), or NULL in
		    which case this function does nothing.

   SEE ALSO
	[AslRequest()](autodocs-3.5/asl-library-aslrequest-2.md)

---

## See Also

- [AllocAslRequest — asl.library](../autodocs/asl.library.md#allocaslrequest)
- [AslRequest — asl.library](../autodocs/asl.library.md#aslrequest)
