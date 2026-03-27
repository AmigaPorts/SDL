---
title: exec.library/Enable
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-enable-2
functions: [Disable, Enable, Forbid, Permit]
libraries: [exec.library]
---

# exec.library/Enable

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Enable -- permit system interrupts to resume.

   SYNOPSIS
	Enable();

	void Enable(void);

   FUNCTION
	Allow system interrupts to again occur normally, after a matching
	[Disable()](autodocs-3.5/exec-library-disable-2.md) has been executed.

   RESULTS
	[Interrupt](autodocs-3.5/include-exec-interrupts-h.md) processing is restored to normal operation. The
	programmer must execute exactly one call to Enable() for every call
	to [Disable()](autodocs-3.5/exec-library-disable-2.md).

    NOTE
	This call is guaranteed to preserve all registers.

   SEE ALSO
	[Forbid()](autodocs-3.5/exec-library-forbid-2.md), [Permit()](autodocs-3.5/exec-library-permit-2.md), [Disable()](autodocs-3.5/exec-library-disable-2.md)

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
