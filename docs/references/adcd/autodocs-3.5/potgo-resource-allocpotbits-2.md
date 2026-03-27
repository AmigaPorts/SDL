---
title: potgo.resource/AllocPotBits
manual: autodocs-3.5
chapter: autodocs-3.5
section: potgo-resource-allocpotbits-2
functions: []
libraries: []
---

# potgo.resource/AllocPotBits

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocPotBits -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) bits in the potgo register.

   SYNOPSIS
	allocated = AllocPotBits(bits)
	D0                       D0

	[UWORD](autodocs-3.5/include-exec-types-h.md) AllocPotBits( [UWORD](autodocs-3.5/include-exec-types-h.md) );

   FUNCTION
	The AllocPotBits routine allocates bits in the hardware potgo
	register that the application wishes to manipulate via
	[WritePotgo](autodocs-3.5/potgo-resource-writepotgo-2.md).  The request may be for more than one bit.  A
	user trying to allocate bits may find that they are
	unavailable because they are already allocated, or because
	the start bit itself (bit 0) has been allocated, or if
	requesting the start bit, because input bits have been
	allocated.  A user can block itself from allocation: i.e.
	it should FreePotgoBits the bits it has and re-AllocPotBits if
	it is trying to change an allocation involving the start bit.

   INPUTS
	bits - a description of the hardware bits that the application
		wishes to manipulate, loosely based on the register
		description itself:
	    START (bit 0) - set if you wish to use start (i.e. start
		    the proportional controller counters) with the
		    input ports you allocate (below).  You must
		    allocate all the DATxx ports you want to apply
		    START to in this same call, with the OUTxx bit
		    clear.
	    DATLX (bit 8) - set if you wish to use the port associated
		    with the left (0) controller, pin 5.
	    OUTLX (bit 9) - set if you promise to use the LX port in
		    output mode only.  The port is not set to output
		    for you at this time -- this bit set indicates
		    that you don't mind if STARTs are initiated at any
		    time by others, since ports that are enabled for
		    output are unaffected by START.
	    DATLY (bit 10) - as DATLX but for the left (0) controller,
		    pin 9.
	    OUTLY (bit 11) - as OUTLX but for LY.
	    DATRX (bit 12) - the right (1) controller, pin 5.
	    OUTRX (bit 13) - OUT for RX.
	    DATRY (bit 14) - the right (1) controller, pin 9.
	    OUTRY (bit 15) - OUT for RY.

   RESULTS
	allocated - the START and DATxx bits of those requested that
		were granted.  The OUTxx bits are don't cares.

