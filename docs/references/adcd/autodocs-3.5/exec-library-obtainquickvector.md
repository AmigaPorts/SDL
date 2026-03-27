---
title: exec.library/ObtainQuickVector
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-obtainquickvector
functions: []
libraries: []
---

# exec.library/ObtainQuickVector

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ObtainQuickVector -- obtain and install a Quick [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) vector (V39)

   SYNOPSIS
	vector=ObtainQuickVector(interruptCode)
	d0                       a0

	ULONG ObtainQuickVector(APTR);

   FUNCTION
	This function will install the code pointer into the quick interrupt
	vector it allocates and returns to you the interrupt vector that
	your Quick [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) system needs to use.

	This function may also return 0 if no vectors are available.  Your
	hardware should be able to then fall back to using the shared
	interrupt server chain should this happen.

	The interrupt code is a direct connect to the physical interrupt.
	This means that it is the responsibility of your code to do all
	of the context saving/restoring required by interrupt code.

	Also, due to the performance of the interrupt controller, you may
	need to also watch for "false" interrupts.  These are interrupts
	that come in just after a DISABLE.  The reason this happens is
	because the interrupt may have been posted before the DISABLE
	hardware access is completed.  For example:

	myInt:		move.l	d0,-(sp)	; Save d0...
			move.w	_intenar,d0	; Get interrupt enable state
			btst.l	#INTB_INTEN,d0	; Check if pending disable
			bne.s	realInt		; If not, do real one...
	exitInt:	move.l	(sp)+,d0	; Restore d0
			rte			; Return from int...
	;
	realInt:	; Now do your int code...  d0 is already saved
			; ALL other registers need to be saved if needed
			; This includes a0/a1/d0/d1 as this is an interrupt
			; and not a function call...
			;
			bra.s	exitInt		; [Exit](autodocs-3.5/dos-library-exit-2.md) interrupt...

	If your interrupt will not play with system (OS) structures and your
	own structures are safe to play with you do not need to check for
	the disable.  It is only needed for when the system is in disable but
	that "one last interrupt" still got through.

   NOTE
	This function was not implemented fully until V39.  Due to a mis-cue
	it is not safe to call in V37 EXEC.  (Sorry)

   INPUTS
	A pointer to your interrupt code.  This code is not an EXEC interrupt
	but is dirrectly connected to the hardware interrupt.  Thus, the
	interrupt code must not modify any registers and must return via
	an RTE.

   RESULTS
	The 8-bit vector number used for Zorro-III Quick Interrupts
	If it returns 0, no quick interrupt was allocatable.  The device
	should at this point switch to using the shared interrupt server
	method.

   SEE ALSO

