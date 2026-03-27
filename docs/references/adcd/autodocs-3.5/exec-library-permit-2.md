---
title: exec.library/Permit
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-permit-2
functions: [Disable, Enable, Forbid, Permit]
libraries: [exec.library]
---

# exec.library/Permit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Permit -- permit task rescheduling.

    SYNOPSIS
	Permit()

	void Permit(void);

    FUNCTION
	Allow other tasks to be scheduled to run by the dispatcher, after a
	matching [Forbid()](autodocs-3.5/exec-library-forbid-2.md) has been executed.

    RESULTS
	Other tasks will be rescheduled as they are ready to run. In order
	to restore normal task rescheduling, the programmer must execute
	exactly one call to Permit() for every call to [Forbid()](autodocs-3.5/exec-library-forbid-2.md).

    NOTE
	This call is guaranteed to preserve all registers.

    SEE ALSO
	[Forbid()](autodocs-3.5/exec-library-forbid-2.md), [Disable()](autodocs-3.5/exec-library-disable-2.md), [Enable()](autodocs-3.5/exec-library-enable-2.md)

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
