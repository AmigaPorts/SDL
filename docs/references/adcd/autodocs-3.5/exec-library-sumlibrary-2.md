---
title: exec.library/SumLibrary
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-sumlibrary-2
functions: [Alert, SetFunction]
libraries: [exec.library]
---

# exec.library/SumLibrary

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SumLibrary -- compute and check the checksum on a library

   SYNOPSIS
	SumLibrary(library)
		   A1

	void SumLibrary(struct [Library](autodocs-3.5/include-exec-libraries-h.md) *);

   FUNCTION
	SumLibrary computes a new checksum on a library.  It can also be
	used to check an old checksum.	If an old checksum does not match,
	and the library has not been marked as changed, then the system
	will call [Alert()](autodocs-3.5/exec-library-alert-2.md).

	This call could also be periodically made by some future
	system-checking task.

   INPUTS
	library - a pointer to the library to be changed

   NOTE
	An alert will occur if the checksum fails.

   SEE ALSO
	[SetFunction()](autodocs-3.5/exec-library-setfunction-2.md)

---

## See Also

- [Alert — exec.library](../autodocs/exec.library.md#alert)
- [SetFunction — exec.library](../autodocs/exec.library.md#setfunction)
