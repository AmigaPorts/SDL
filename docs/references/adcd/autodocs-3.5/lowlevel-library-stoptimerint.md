---
title: lowlevel.library/StopTimerInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-stoptimerint
functions: []
libraries: []
---

# lowlevel.library/StopTimerInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StopTimerInt -- stop the timer associated with the timer interrupt.
			(V40)

   SYNOPSIS
	StopTimerInt(intHandle);
	             A1

	VOID StopTimerInt(APTR);

   FUNCTION
	Stops the timer associated with the timer interrupt handle passed.
	This is used to stop a continuous timer started by
	[StartTimerInt()](autodocs-3.5/lowlevel-library-starttimerint.md).

   INPUTS
	intHandle - handle obtained from [AddTimerInt()](autodocs-3.5/lowlevel-library-addtimerint.md).

   SEE ALSO
	[AddTimerInt()](autodocs-3.5/lowlevel-library-addtimerint.md), [RemTimerInt()](autodocs-3.5/lowlevel-library-remtimerint.md), [StartTimerInt()](autodocs-3.5/lowlevel-library-starttimerint.md)

