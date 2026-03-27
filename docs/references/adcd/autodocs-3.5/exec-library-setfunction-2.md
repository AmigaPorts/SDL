---
title: exec.library/SetFunction
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-setfunction-2
functions: [Forbid, Permit, SumLibrary]
libraries: [exec.library]
---

# exec.library/SetFunction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetFunction -- change a function vector in a library

   SYNOPSIS
	oldFunc = SetFunction(library, funcOffset, funcEntry)
	D0		      A1       A0.W	   D0

	[APTR](autodocs-3.5/include-exec-types-h.md) SetFunction(struct [Library](autodocs-3.5/include-exec-libraries-h.md) *,[LONG](autodocs-3.5/include-exec-types-h.md),APTR);

   FUNCTION
	SetFunction is a functional way of changing where vectors in a
	library point.	They are changed in such a way that the
	checksumming process will never falsely declare a library to be
	invalid.

   WARNING
	If you use SetFunction on a function that can be called from
	interrupts, you are obligated to provide your own arbitration.

   NOTE
	SetFunction cannot be used on non-standard libraries like pre-V36
	dos.library.  Here you must manually [Forbid()](autodocs-3.5/exec-library-forbid-2.md), preserve all 6
	original bytes, set the new vector, [SumLibrary()](autodocs-3.5/exec-library-sumlibrary-2.md), then [Permit()](autodocs-3.5/exec-library-permit-2.md).

   INPUTS
	library    - a pointer to the library to be changed
	funcOffset - the offset of the function to be replaced
	funcEntry  - pointer to new function

   RESULTS
	oldFunc    - pointer to the old function that was just replaced

---

## See Also

- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
- [SumLibrary — exec.library](../autodocs/exec.library.md#sumlibrary)
