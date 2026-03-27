---
title: utility.library/GetUniqueID
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-getuniqueid
functions: [GetUniqueID]
libraries: [utility.library]
---

# utility.library/GetUniqueID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetUniqueID -- return a relatively unique number. (V39)

   SYNOPSIS
	id = GetUniqueID();
	D0

	ULONG GetUniqueID(VOID);

   FUNCTION
	Returns a unique value each time it is called. This is useful for
	things that need unique ID such as the GadgetHelp ID, etc.
	Note that this is only unique for 4,294,967,295 calls to this
	function. Under normal use this is not a problem.
	This function is safe in interrupts.

   RESULT
	id - a 32-bit value that is unique.

---

## See Also

- [GetUniqueID — utility.library](../autodocs/utility.library.md#getuniqueid)
