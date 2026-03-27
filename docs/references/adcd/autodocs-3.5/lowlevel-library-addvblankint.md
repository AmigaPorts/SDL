---
title: lowlevel.library/AddVBlankInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-addvblankint
functions: []
libraries: []
---

# lowlevel.library/AddVBlankInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddVBlankInt -- adds a routine executed every vertical blank. (V40)

   SYNOPSIS
	intHandle = AddVBlankInt(intRoutine, intData);
	D0		         a0	  a1

	[APTR](autodocs-3.5/include-exec-types-h.md) AddVBlankInt(APTR, APTR);

   FUNCTION
	Lets you attach a routine to the system which will get called
	everytime a vertical blanking interrupt occurs.

	The routine is called from within an interrupt, so normal
	restrictions apply. The routine must preserve the following
	registers: A2, A3, A4, A7, D2-D7. Other registers are
	scratch, except for D0, which MUST BE SET TO 0 upon
	exit. On entry to the routine, A1 holds 'intData' and A5
	holds 'intRoutine'.

	If your program is to exit without reboot, you MUST call
	[RemVBlankInt()](autodocs-3.5/lowlevel-library-remvblankint.md) before exiting.

	Only one interrupt routine may be added to the system.  ALWAYS check
	the return value in case some other task has previously used this
	function.

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
	[RemVBlankInt()](autodocs-3.5/lowlevel-library-remvblankint.md)

