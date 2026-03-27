---
title: rexxsyslib.library/LengthArgstring
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-lengthargstring-2
functions: [CreateArgstring]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/LengthArgstring

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	LengthArgstring - Returns the length value stored in the argstring

    SYNOPSIS
	length = LengthArgstring(argstring)
	D0                       A0

	ULONG LengthArgstring(UBYTE *);

    FUNCTION
	This function returns the length value stored in the argstring.
	This is *NOT* the same as doing a strlen() type call on the
	argstring.  (Note that argstrings may contain NULLs)

    INPUTS
	argstring - A pointer to an argstring that was created by ARexx

    RESULTS
	length - The length of the argstring.

    EXAMPLE

    SEE ALSO
	[CreateArgstring()](autodocs-3.5/rexxsyslib-library-createargstring-2.md)


    BUGS

---

## See Also

- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
