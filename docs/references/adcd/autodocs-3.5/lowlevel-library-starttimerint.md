---
title: lowlevel.library/StartTimerInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-starttimerint
functions: []
libraries: []
---

# lowlevel.library/StartTimerInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StartTimerInt -- start the timer associated with the timer interrupt.
			 (V40)

   SYNOPSIS
	StartTimerInt(intHandle, timeInterval, continuous);
	              A1         D0            D1

	VOID StartTimerInt(APTR, ULONG, BOOL);

   FUNCTION
	This routine starts a stopped timer that is assocatied with a
	timer interrupt created by [AddTimerInt()](autodocs-3.5/lowlevel-library-addtimerint.md).

   INPUTS
	intHandle - handle obtained from [AddTimerInt()](autodocs-3.5/lowlevel-library-addtimerint.md).
	timeInterval - number of micoseconds between interrupts. The
	               maximum value allowed is 90,000. If higher values
	               are passed there will be unexpected results.
	continuous - FALSE for a one shot interrupt. TRUE for multiple
	             interrupts.

   SEE ALSO
	[AddTimerInt()](autodocs-3.5/lowlevel-library-addtimerint.md), [RemTimerInt()](autodocs-3.5/lowlevel-library-remtimerint.md), [StopTimerInt()](autodocs-3.5/lowlevel-library-stoptimerint.md)

