---
title: lowlevel.library/AddKBInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-addkbint
functions: []
libraries: []
---

# lowlevel.library/AddKBInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddKBInt -- adds a routine to the keyboard interrupt. (V40)

   SYNOPSIS
	intHandle = AddKBInt(intRoutine, intData);
	D0                   A0          A1

	[APTR](autodocs-3.5/include-exec-types-h.md) AddKBInt(APTR, APTR);

   FUNCTION
	This routine extends the functionality of the keyboard interrupt to
	include intRoutine. Since this is an extention of the normal
	keyboard interrupt all of the keyboard handshaking is handled. The
	keyboard error codes are filtered out and not passed to intRoutine.

	The routine is called whenever the user enters a key on the
	keyboard.

	The routine is called from within an interrupt, so normal
	restrictions apply. The routine must preserve the following
	registers: A2, A3, A4, A7, D2-D7. Other registers are
	scratch, except for D0, which MUST BE SET TO 0 upon
	exit. On entry to the routine, A1 holds 'intData' and A5
	holds 'intRoutine', and D0 contains the rawkey code read
	from the keyboard.

	The routine is not called when a reset is received from the
	keyboard.

	This is a low level function that does not fit the normal Amiga
	multitasking model. The interrupt installed will have no knowledge
	of which window/screen currently has input focus.

	If your program is to exit without reboot, you MUST call [RemKBInt()](autodocs-3.5/lowlevel-library-remkbint.md)
	before exiting.

	Only one interrupt routine may be added to the system.  ALWAYS
	check the return value in case some other task has previously
	used this function.

   INPUTS
	intRoutine - the routine to invoke every vblank. This routine should
		     be as short as possible to minimize its effect on overall
		     system performance.
	intData - data passed to the routine in register A1. If more than one
		  long word of data is required this should be a pointer to
		  a structure that contains the required data.

   RESULT
	intHandle - a handle used to manipulate the interrupt, or NULL
		    if it was not possible to attach the routine.

   SEE ALSO
	[RemKBInt()](autodocs-3.5/lowlevel-library-remkbint.md)

