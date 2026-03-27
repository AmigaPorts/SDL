---
title: dos.library/UnGetC
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-ungetc-2
functions: [FGetC, FPutC]
libraries: [dos.library]
---

# dos.library/UnGetC

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	UnGetC -- Makes a char available for reading again. (buffered) (V36)

   SYNOPSIS
	value = UnGetC(fh, character)
	D0	       D1      D2

	[LONG](autodocs-3.5/include-exec-types-h.md) UnGetC(BPTR, LONG)

   FUNCTION
	Pushes the character specified back into the input buffer.  Every
	time you use a buffered read routine, you can always push back 1
	character.  You may be able to push back more, though it is not
	recommended, since there is no guarantee on how many can be
	pushed back at a given moment.

	Passing -1 for the character will cause the last character read to
	be pushed back.  If the last character read was an EOF, the next
	character read will be an EOF.

	Note: UnGetC can be used to make sure that a filehandle is set up
	as a read filehandle.  This is only of importance if you are writing
	a shell, and must manipulate the filehandle's buffer.

   INPUTS
	fh	  - filehandle to use for buffered I/O
	character - character to push back or -1

   RESULT
	value     - character pushed back, or FALSE if the character cannot
		    be pushed back.

   BUGS
	In V36, UnGetC(fh,-1) after an EOF would not cause the next character
	read to be an EOF.  This was fixed for V37.

   SEE ALSO
	[FGetC()](autodocs-3.5/dos-library-fgetc-2.md), [FPutC()](autodocs-3.5/dos-library-fputc-2.md), [Flush()](autodocs-3.5/dos-library-flush-2.md)

---

## See Also

- [FGetC — dos.library](../autodocs/dos.library.md#fgetc)
- [FPutC — dos.library](../autodocs/dos.library.md#fputc)
