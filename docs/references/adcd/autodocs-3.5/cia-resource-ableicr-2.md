---
title: cia.resource/AbleICR
manual: autodocs-3.5
chapter: autodocs-3.5
section: cia-resource-ableicr-2
functions: []
libraries: []
---

# cia.resource/AbleICR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AbleICR -- Enable/disable ICR interrupts.

   SYNOPSIS
	oldMask = AbleICR( Resource, mask )
	D0                 A6        D0

	WORD AbleICR( struct [Library](autodocs-3.5/include-exec-libraries-h.md) *, WORD );

   FUNCTION
	This function provides a means of enabling and disabling 8520
	[CIA](autodocs-3.5/include-hardware-cia-h.md) interrupt control registers. In addition it returns the
	previous enable mask.

   INPUTS
	mask            A bit mask indicating which interrupts to be
	                    modified. If bit 7 is clear the mask
	                    indicates interrupts to be disabled. If
	                    bit 7 is set, the mask indicates
	                    interrupts to be enabled. Bit positions
	                    are identical to those in 8520 ICR.

   RESULTS
	oldMask         The previous enable mask before the requested
	                    changes. To get the current mask without
	                    making changes, call the function with a
	                    null parameter.

   EXAMPLES
	Get the current mask:
	    mask = AbleICR(0)
	[Enable](autodocs-3.5/exec-library-enable-2.md) both timer interrupts:
	    AbleICR(0x83)
	[Disable](autodocs-3.5/exec-library-disable-2.md) serial port interrupt:
	    AbleICR(0x08)

   EXCEPTIONS
	Enabling the mask for a pending interrupt will cause an
	immediate processor interrupt (that is if everything else is
	enabled). You may want to clear the pending interrupts with
	[SetICR()](autodocs-3.5/cia-resource-seticr-2.md) prior to enabling them.

   NOTE
	The [CIA](autodocs-3.5/include-hardware-cia-h.md) resources are special in that there is more than one
	of them in the system. Because of this, the C language stubs
	in amiga.lib for the [CIA](autodocs-3.5/include-hardware-cia-h.md) resources require an extra parameter
	to specify which [CIA](autodocs-3.5/include-hardware-cia-h.md) resource to use. The synopsis for the
	amiga.lib stubs is as follows:

	oldMask = AbleICR( Resource, mask )
	D0                 A6        D0

	WORD AbleICR( struct [Library](autodocs-3.5/include-exec-libraries-h.md) *, WORD );

   SEE ALSO
	[cia.resource/SetICR()](autodocs-3.5/cia-resource-seticr-2.md)

