---
title: exec.library/Supervisor
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-supervisor-2
functions: [SuperState, Supervisor, UserState]
libraries: [exec.library]
---

# exec.library/Supervisor

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Supervisor -- trap to a short supervisor mode function

   SYNOPSIS
	result = Supervisor(userFunc)
	Rx                   A5

	ULONG Supervisor(void *);

   FUNCTION
	Allow a normal user-mode program to execute a short assembly language
	function in the supervisor mode of the processor.  Supervisor() does
	not modify or save registers; the user function has full access to the
	register set.   All rules that apply to interrupt code must be
	followed.  In addition, no system calls are permitted.  The function
	must end with an RTE instruction.

   EXAMPLE
		;Obtain the Exception Vector base.  68010 or greater only!
		MOVECtrap:	movec.l	VBR,d0	;$4e7a,$0801
				rte

   INPUTS
	userFunc - A pointer to a short assembly language function ending
		   in RTE.  The function has full access to the register set.

   RESULTS
	result   - Whatever values the userFunc left in the registers.

   SEE ALSO
	[SuperState()](autodocs-3.5/exec-library-superstate-2.md),[UserState()](autodocs-3.5/exec-library-userstate-2.md)

---

## See Also

- [SuperState — exec.library](../autodocs/exec.library.md#superstate)
- [Supervisor — exec.library](../autodocs/exec.library.md#supervisor)
- [UserState — exec.library](../autodocs/exec.library.md#userstate)
