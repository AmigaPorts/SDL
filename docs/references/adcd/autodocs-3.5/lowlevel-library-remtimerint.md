---
title: lowlevel.library/RemTimerInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-remtimerint
functions: []
libraries: []
---

# lowlevel.library/RemTimerInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemTimerInt -- remove a previously installed timer interrupt. (V40)

   SYNOPSIS
	RemTimerInt(intHandle);
	            A1

	VOID RemTimerInt(APTR);

   FUNCTION
	Removes a timer interrupt routine previously installed with
	[AddTimerInt](autodocs-3.5/lowlevel-library-addtimerint.md).

   INPUTS
	intHandle - handle obtained from [AddTimerInt()](autodocs-3.5/lowlevel-library-addtimerint.md). This may be NULL,
		    in which case this function does nothing.

   SEE ALSO
	[AddTimerInt()](autodocs-3.5/lowlevel-library-addtimerint.md), [StopTimerInt()](autodocs-3.5/lowlevel-library-stoptimerint.md), [StartTimerInt()](autodocs-3.5/lowlevel-library-starttimerint.md)

