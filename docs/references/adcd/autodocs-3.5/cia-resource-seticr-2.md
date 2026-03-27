---
title: cia.resource/SetICR
manual: autodocs-3.5
chapter: autodocs-3.5
section: cia-resource-seticr-2
functions: []
libraries: []
---

# cia.resource/SetICR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetICR -- [Cause](autodocs-3.5/exec-library-cause-2.md), clear, and sample ICR interrupts.

   SYNOPSIS
	oldMask = SetICR( Resource, mask )
	D0                A6        D0

	WORD SetICR( struct [Library](autodocs-3.5/include-exec-libraries-h.md) *, WORD );

   FUNCTION
	This function provides a means of reseting, causing, and
	sampling 8520 [CIA](autodocs-3.5/include-hardware-cia-h.md) interrupt control registers.

   INPUTS
	mask            A bit mask indicating which interrupts to be
	                    effected. If bit 7 is clear the mask
	                    indicates interrupts to be reset.  If bit
	                    7 is set, the mask indicates interrupts to
	                    be caused. Bit positions are identical to
	                    those in 8520 ICR.

   RESULTS
	oldMask         The previous interrupt register status before
	                    making the requested changes.  To sample
	                    current status without making changes,
	                    call the function with a null parameter.

   EXAMPLES
	Get the interrupt mask:
	    mask = SetICR(0)
	Clear serial port interrupt:
	    SetICR(0x08)

   NOTE
	The [CIA](autodocs-3.5/include-hardware-cia-h.md) resources are special in that there is more than one
	of them in the system. Because of this, the C language stubs
	in amiga.lib for the [CIA](autodocs-3.5/include-hardware-cia-h.md) resources require an extra parameter
	to specify which [CIA](autodocs-3.5/include-hardware-cia-h.md) resource to use. The synopsis for the
	amiga.lib stubs is as follows:

	oldMask = SetICR( Resource, mask )
	D0                A6        D0

	WORD SetICR( struct [Library](autodocs-3.5/include-exec-libraries-h.md) *, WORD );

	***WARNING***

	Never read the contents of the [CIA](autodocs-3.5/include-hardware-cia-h.md) interrupt control registers
	directly.  Reading the contents of one of the [CIA](autodocs-3.5/include-hardware-cia-h.md) interrupt
	control registers clears the register.  This can result in
	interrupts being missed by critical operating system code, and
	other applications.

   EXCEPTIONS
	Setting an interrupt bit for an enabled interrupt will cause
	an immediate interrupt.

   SEE ALSO
	[cia.resource/AbleICR()](autodocs-3.5/cia-resource-ableicr-2.md)

