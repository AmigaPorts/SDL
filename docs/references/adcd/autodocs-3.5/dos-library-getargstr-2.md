---
title: dos.library/GetArgStr
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getargstr-2
functions: [GetArgStr, RunCommand, SetArgStr]
libraries: [dos.library]
---

# dos.library/GetArgStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetArgStr -- Returns the arguments for the process (V36)

   SYNOPSIS
	ptr = GetArgStr()
	D0

	[STRPTR](autodocs-3.5/include-exec-types-h.md) GetArgStr(void)

   FUNCTION
	Returns a pointer to the (null-terminated) arguments for the program
	(process).  This is the same string passed in a0 on startup from CLI.

   RESULT
	ptr - pointer to arguments

   SEE ALSO
	[SetArgStr()](autodocs-3.5/dos-library-setargstr-2.md), [RunCommand()](autodocs-3.5/dos-library-runcommand-2.md)

---

## See Also

- [GetArgStr — dos.library](../autodocs/dos.library.md#getargstr)
- [RunCommand — dos.library](../autodocs/dos.library.md#runcommand)
- [SetArgStr — dos.library](../autodocs/dos.library.md#setargstr)
