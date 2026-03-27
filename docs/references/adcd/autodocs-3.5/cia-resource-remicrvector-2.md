---
title: cia.resource/RemICRVector
manual: autodocs-3.5
chapter: autodocs-3.5
section: cia-resource-remicrvector-2
functions: []
libraries: []
---

# cia.resource/RemICRVector

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemICRVector -- Detach an interrupt handler from a [CIA](autodocs-3.5/include-hardware-cia-h.md) bit.

   SYNOPSIS
	RemICRVector( Resource, iCRBit, interrupt )
	              A6        D0      A1

	void RemICRVector( struct [Library](autodocs-3.5/include-exec-libraries-h.md) *, WORD, struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) *);

   FUNCTION
	Disconnect interrupt processing code for a particular
	interrupt bit of the [CIA](autodocs-3.5/include-hardware-cia-h.md) ICR.

	This function will also disable the [CIA](autodocs-3.5/include-hardware-cia-h.md) interrupt for the
	given ICR bit.

   INPUTS
	iCRBit          Bit number to set (0..4).
	interrupt       Pointer to interrupt structure.

   RESULT

   NOTE
	The [CIA](autodocs-3.5/include-hardware-cia-h.md) resources are special in that there is more than one
	of them in the system. Because of this, the C language stubs
	in amiga.lib for the [CIA](autodocs-3.5/include-hardware-cia-h.md) resources require an extra parameter
	to specify which [CIA](autodocs-3.5/include-hardware-cia-h.md) resource to use. The synopsis for the
	amiga.lib stubs is as follows:

	RemICRVector( Resource, iCRBit, interrupt )
	              A6        D0      A1

	void RemICRVector( struct [Library](autodocs-3.5/include-exec-libraries-h.md) *, WORD, struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) *);

   SEE ALSO
	[cia.resource/AddICRVector()](autodocs-3.5/cia-resource-addicrvector-2.md)

