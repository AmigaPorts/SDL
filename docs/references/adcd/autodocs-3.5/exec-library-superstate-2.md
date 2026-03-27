---
title: exec.library/SuperState
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-superstate-2
functions: [SuperState, Supervisor, UserState]
libraries: [exec.library]
---

# exec.library/SuperState

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SuperState -- enter supervisor state with user stack

   SYNOPSIS
	oldSysStack = SuperState()
	D0

	[APTR](autodocs-3.5/include-exec-types-h.md) SuperState(void);

   FUNCTION
	Enter supervisor mode while running on the user's stack. The user
	still has access to user stack variables.  Be careful though, the
	user stack must be large enough to accommodate space for all
	interrupt data -- this includes all possible nesting of interrupts.
	This function does nothing when called from supervisor state.

   RESULTS
	oldSysStack - system stack pointer; save this.	It will come in
		      handy when you return to user state.  If the system
		      is already in supervisor mode, oldSysStack is zero.

   SEE ALSO
	[UserState()](autodocs-3.5/exec-library-userstate-2.md), [Supervisor()](autodocs-3.5/exec-library-supervisor-2.md)

---

## See Also

- [SuperState — exec.library](../autodocs/exec.library.md#superstate)
- [Supervisor — exec.library](../autodocs/exec.library.md#supervisor)
- [UserState — exec.library](../autodocs/exec.library.md#userstate)
