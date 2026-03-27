---
title: lowlevel.library/AddTimerInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-addtimerint
functions: []
libraries: []
---

# lowlevel.library/AddTimerInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddTimerInt -- adds an interrupt that is executed at regular
		       intervals. (V40)

   SYNOPSIS
	intHandle = AddTimerInt(intRoutine, intData);
	D0                      A0          A1

	[APTR](autodocs-3.5/include-exec-types-h.md) AddTimerInt(APTR, APTR);

   FUNCTION
	Calling this routine causes the system to allocate a [CIA](autodocs-3.5/include-hardware-cia-h.md) timer
	and set up 'intRoutine' to service any interrupts caused by the timer.
	Although the timer is allocated it is neither running, nor enabled.
	StartIntTimer() must be called to establish the time interval and
	start the timer.

	The routine is called from within an interrupt, so normal
	restrictions apply. The routine must preserve the following
	registers: A2, A3, A4, A7, D2-D7. Other registers are
	scratch, except for D0, which MUST BE SET TO 0 upon
	exit. On entry to the routine, A1 holds 'intData' and A5
	holds 'intRoutine'.

	Only a single [CIA](autodocs-3.5/include-hardware-cia-h.md) timer will be allocated by this routine. So this
	routine may only be called once without an intervening call to
	[RemTimerInt()](autodocs-3.5/lowlevel-library-remtimerint.md).

	The [CIA](autodocs-3.5/include-hardware-cia-h.md) timer used by this routine is not guaranteed to always be
	the same. This routine utilizes the [CIA](autodocs-3.5/include-hardware-cia-h.md) resource and uses an
	unallocated [CIA](autodocs-3.5/include-hardware-cia-h.md) timer.

	If your program is to exit without reboot, you MUST match all
	calls to this function with calls to [RemTimerInt()](autodocs-3.5/lowlevel-library-remtimerint.md) before exiting.

	Even if you only use the function once in your program; checking
	the return value will make your program more tolerant for
	mulititasking on the Amiga computer platforms.

   INPUTS
	intRoutine - the routine to invoke upon timer interrupts. This routine
		     should be as short as possible to minimize its effect on
		     overall system performance.
	intData - data passed to the routine in register A1. If more than one
		  long word of data is required this should be a pointer to
		  a structure that contains the required data.

   RESULT
	intHandle - a handle used to manipulate the interrupt, or NULL
		    if it was not possible to attach the routine.

   SEE ALSO
	[RemTimerInt()](autodocs-3.5/lowlevel-library-remtimerint.md), [StopTimerInt()](autodocs-3.5/lowlevel-library-stoptimerint.md), [StartTimerInt()](autodocs-3.5/lowlevel-library-starttimerint.md)

