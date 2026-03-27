---
title: exec.library/SetSR
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-setsr-2
functions: []
libraries: []
---

# exec.library/SetSR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetSR -- get and/or set processor status register

   SYNOPSIS
	oldSR = SetSR(newSR, mask)
	D0	      D0     D1

	ULONG SetSR(ULONG, ULONG);

   FUNCTION
	This function provides a means of modifying the CPU status register
	in a "safe" way (well, how safe can a function like this be
	anyway?).  This function will only affect the status register bits
	specified in the mask parameter.  The prior content of the entire
	status register is returned.

   INPUTS
	newSR - new values for bits specified in the mask.
	    All other bits are not effected.
	mask - bits to be changed

   RESULTS
	oldSR - the entire status register before new bits

   EXAMPLES
	To get the current SR:
	    currentSR = SetSR(0,0);
	To change the processor interrupt level to 3:
	    oldSR = SetSR($0300,$0700);
	Set processor interrupts back to prior level:
	    SetSR(oldSR,$0700);

