---
title: exec.library/AddMemHandler
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-addmemhandler
functions: [RemMemHandler]
libraries: [exec.library]
---

# exec.library/AddMemHandler

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddMemHandler - Add a low memory handler to exec                 (V39)

   SYNOPSIS
	AddMemHandler(memHandler)
	              A1

	VOID AddMemHandler(struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) *);

   FUNCTION
	This function adds a low memory handler to the system.  The handler
	is described in the [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) structure.  Due to multitasking
	issues, the handler must be ready to run the moment this function
	call is made.  (The handler may be called before the call returns)

   NOTE
	Adding a handler from within a handler will cause undefined
	actions.  It is safe to add a handler to the list while within
	a handler but the newly added handler may or may not be called
	for the specific failure currently running.

   EXAMPLE
	struct [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) *myInt;  /* Assume it is allocated */

	myInt->is_Node.ln_Pri=50;  /* Relatively early; before RAMLIB */

	/* Please fill in the name field! */
	myInt->is_Node.ln_Name="Example Handler";

	myInt->is_Data=(APTR)mydata_pointer;
	myInt->is_Code=myhandler_code;

	AddMemHandler(myInt);
	... /* and so on */

	_myhandler_code:
			; This is the handler code
			; We are passed a pointer to struct [MemHandlerData](autodocs-3.5/include-exec-memory-h.md)
			; in a0, the value of is_Data in a1 and
			; [ExecBase](autodocs-3.5/include-exec-execbase-h.md) in a6.
			; We must not break forbid!!!
	;
	; Start off assuming we did nothing
	;
		moveq.l	#MEM_DID_NOTHING,d0
		move.l	memh_RequestFlags(a0),d1
		btst.l	#MEMB_CHIP,d1	; Did the failure happen in CHIP
		beq.s	handler_nop	; If not, we have nothing to do
		bsr	DoMyMagic	; Do the magic...
		; DoMyMagic frees whatever we can and returns d0 set...
	handler_nop:
		rts			; Return with d0 set...

   INPUTS
	memHandler - A pointer to a completely filled in [Interrupt](autodocs-3.5/include-exec-interrupts-h.md) structure
	             The priority field determine the position of the handler
	             with respect to other handlers in the system.  The higher
	             the priority, the earlier the handler is called.
	             Positive priorities will have the handler called before
	             any of the library expunge vectors are called.  Negative
	             priority handlers will be called after the library
	             expunge routines are called.
	             (Note:  RAMLIB is a handler at priority 0)

   SEE ALSO
	[RemMemHandler()](autodocs-3.5/exec-library-remmemhandler.md), exec/interrupts.i

---

## See Also

- [RemMemHandler — exec.library](../autodocs/exec.library.md#remmemhandler)
