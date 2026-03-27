---
title: exec.library/RemIntServer
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-remintserver-2
functions: [AddIntServer]
libraries: [exec.library]
---

# exec.library/RemIntServer

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemIntServer -- remove an interrupt server from a server chain

   SYNOPSIS
	RemIntServer(intNum, interrupt)
		     D0      A1

	void RemIntServer(ULONG,struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) *);

   FUNCTION
	This function removes an interrupt server node from the given
	server chain.

	If this server was the last one on this chain, interrupts for this
	chain are disabled.

   INPUTS
	intNum - the Paula interrupt bit (0..14)
	interrupt - pointer to an interrupt server node

   BUGS
	Before V36 Kickstart, the feature that disables the interrupt
	would not function.  For most server chains this does not
	cause a problem.

   SEE ALSO
	[AddIntServer()](autodocs-3.5/exec-library-addintserver-2.md), [hardware/intbits.h](autodocs-3.5/include-hardware-intbits-h.md)

---

## See Also

- [AddIntServer — exec.library](../autodocs/exec.library.md#addintserver)
