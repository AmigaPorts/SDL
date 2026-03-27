---
title: dos.library/SetArgStr
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setargstr-2
functions: [GetArgStr, RunCommand]
libraries: [dos.library]
---

# dos.library/SetArgStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetArgStr -- Sets the arguments for the current process (V36)

   SYNOPSIS
	oldptr = SetArgStr(ptr)
	D0		   D1

	[STRPTR](autodocs-3.5/include-exec-types-h.md) SetArgStr(STRPTR)

   FUNCTION
	Sets the arguments for the current program.  The ptr MUST be reset
	to it's original value before process exit.

   INPUTS
	ptr - pointer to new argument string.

   RESULT
	oldptr - the previous argument string

   SEE ALSO
	[GetArgStr()](autodocs-3.5/dos-library-getargstr-2.md), [RunCommand()](autodocs-3.5/dos-library-runcommand-2.md)

---

## See Also

- [GetArgStr — dos.library](../autodocs/dos.library.md#getargstr)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
