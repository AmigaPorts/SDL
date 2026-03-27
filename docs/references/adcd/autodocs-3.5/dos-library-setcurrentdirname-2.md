---
title: dos.library/SetCurrentDirName
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-setcurrentdirname-2
functions: []
libraries: []
---

# dos.library/SetCurrentDirName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	SetCurrentDirName -- Sets the directory name for the process (V36)

   SYNOPSIS
	success = SetCurrentDirName(name)
	D0                        D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) SetCurrentDirName(STRPTR)

   FUNCTION
	Sets the name for the current dir in the cli structure.  If the name
	is too long to fit, a failure is returned, and the old value is left
	intact.  It is advised that you inform the user of this condition.
	This routine is safe to call even if there is no CLI structure.

   INPUTS
	name    - Name of directory to be set.

   RESULT
	success - Success/failure indicator

   BUGS
	This clips to a fixed (1.3 compatible) size.

   SEE ALSO
	[GetCurrentDirName()](autodocs-3.5/dos-library-getcurrentdirname-2.md)

