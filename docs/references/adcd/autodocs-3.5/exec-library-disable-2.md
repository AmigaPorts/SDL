---
title: exec.library/Disable
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-disable-2
functions: [Disable, Enable, Forbid, Permit, Wait]
libraries: [exec.library]
---

# exec.library/Disable

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	Disable -- disable interrupt processing.

    SYNOPSIS
	Disable();

	void Disable(void);

    FUNCTION
	Prevents interrupts from being handled by the system, until a
	matching [Enable()](autodocs-3.5/exec-library-enable-2.md) is executed.  Disable() implies [Forbid()](autodocs-3.5/exec-library-forbid-2.md).

	DO NOT USE THIS CALL WITHOUT GOOD JUSTIFICATION.  THIS CALL IS
	VERY DANGEROUS!

    RESULTS
	All interrupt processing is deferred until the task executing makes
	a call to [Enable()](autodocs-3.5/exec-library-enable-2.md) or is placed in a wait state.  Normal task
	rescheduling does not occur while interrupts are disabled.  In order
	to restore normal interrupt processing, the programmer must execute
	exactly one call to [Enable()](autodocs-3.5/exec-library-enable-2.md) for every call to Disable().

	IMPORTANT REMINDER:

	It is important to remember that there is a danger in using
	disabled sections.  Disabling interrupts for more than ~250
	microseconds will prevent vital system functions (especially serial
	I/0) from operating in a normal fashion.

	Think twice before using Disable(), then think once more.
	After all that, think again.  With enough thought, the need
	for a Disable() can often be eliminated.  For the user of many
	device drivers, a write to disable *only* the particular interrupt
	of interest can replace a Disable().  For example:
			MOVE.W	#INTF_PORTS,_intena
	Do not use a macro for Disable(), insist on the real thing.

	This call may be made from interrupts, it will have the effect
	of locking out all higher-level interrupts (lower-level interrupts
	are automatically disabled by the CPU).

```c
        Note: In the event of a task entering a [Wait()](autodocs-3.5/exec-library-wait-2.md) after disabling
              interrupts, the system "breaks" the disabled state and runs
              normally until the task which called Disable() is rescheduled.

    NOTE
```
	This call is guaranteed to preserve all registers.

    SEE ALSO
	[Forbid()](autodocs-3.5/exec-library-forbid-2.md), [Permit()](autodocs-3.5/exec-library-permit-2.md), [Enable()](autodocs-3.5/exec-library-enable-2.md)

---

## See Also

- [Disable — exec.library](../autodocs/exec.library.md#disable)
- [Enable — exec.library](../autodocs/exec.library.md#enable)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
