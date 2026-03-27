---
title: dos.library/GetProgramDir
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-getprogramdir-2
functions: [GetProgramDir, Open, SetProgramDir]
libraries: [dos.library]
---

# dos.library/GetProgramDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetProgramDir -- Returns a lock on the directory the program was loaded
			 from (V36)

   SYNOPSIS
	lock = GetProgramDir()
	D0

	[BPTR](autodocs-3.5/include-dos-dos-h.md) GetProgramDir(void)

   FUNCTION
	Returns a shared lock on the directory the program was loaded from.
	This can be used for a program to find data files, etc, that are stored
	with the program, or to find the program file itself.  NULL returns are
	valid, and may occur, for example, when running a program from the
	resident list.  You should NOT unlock the lock.

   RESULT
	lock - A lock on the directory the current program was loaded from,
	       or NULL if loaded from resident list, etc.

   BUGS
	Should return a lock for things loaded via resident.  Perhaps should
	return currentdir if NULL.

   SEE ALSO
	[SetProgramDir()](autodocs-3.5/dos-library-setprogramdir-2.md), [Open()](autodocs-3.5/dos-library-open-2.md)

---

## See Also

- [GetProgramDir — dos.library](../autodocs/dos.library.md#getprogramdir)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [SetProgramDir — dos.library](../autodocs/dos.library.md#setprogramdir)
