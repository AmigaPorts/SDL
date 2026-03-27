---
title: exec.library/UserState
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-userstate-2
functions: [SuperState, Supervisor]
libraries: [exec.library]
---

# exec.library/UserState

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UserState -- return to user state with user stack

   SYNOPSIS
	UserState(sysStack)
		  D0

	void UserState(APTR);

   FUNCTION
	Return to user state with user stack, from supervisor state with
	user stack.  This function is normally used in conjunction with the
	[SuperState](autodocs-3.5/exec-library-superstate-2.md) function above.

	This function must not be called from the user state.

   INPUT
	sysStack - supervisor stack pointer

   BUGS
	This function is broken in V33/34 Kickstart.  Fixed in V1.31 setpatch.

   SEE ALSO
	[SuperState()](autodocs-3.5/exec-library-superstate-2.md), [Supervisor()](autodocs-3.5/exec-library-supervisor-2.md)

---

## See Also

- [SuperState — exec.library](../autodocs/exec.library.md#superstate)
- [Supervisor — exec.library](../autodocs/exec.library.md#supervisor)
