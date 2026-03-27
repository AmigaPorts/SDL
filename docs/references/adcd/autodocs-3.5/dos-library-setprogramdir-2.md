---
title: dos.library/SetProgramDir
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setprogramdir-2
functions: [GetProgramDir, Open]
libraries: [dos.library]
---

# dos.library/SetProgramDir

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetProgramDir -- Sets the directory returned by [GetProgramDir](autodocs-3.5/dos-library-getprogramdir-2.md) (V36)

   SYNOPSIS
	oldlock = SetProgramDir(lock)
	D0		         D1

	[BPTR](autodocs-3.5/include-dos-dos-h.md) SetProgramDir(BPTR)

   FUNCTION
	Sets a shared lock on the directory the program was loaded from.
	This can be used for a program to find data files, etc, that are
	stored with the program, or to find the program file itself.  NULL
	is a valid input.  This can be accessed via [GetProgramDir()](autodocs-3.5/dos-library-getprogramdir-2.md) or
	by using paths relative to PROGDIR:.

   INPUTS
	lock - A lock on the directory the current program was loaded from

   RESULT
	oldlock - The previous ProgramDir.

   SEE ALSO
	[GetProgramDir()](autodocs-3.5/dos-library-getprogramdir-2.md), [Open()](autodocs-3.5/dos-library-open-2.md)

---

## See Also

- [GetProgramDir — dos.library](../autodocs/dos.library.md#getprogramdir)
- [Open — dos.library](../autodocs/dos.library.md#open)
