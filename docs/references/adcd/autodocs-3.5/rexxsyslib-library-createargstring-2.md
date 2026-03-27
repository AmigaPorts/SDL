---
title: rexxsyslib.library/CreateArgstring
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-createargstring-2
functions: [ClearRexxMsg, DeleteArgstring, FillRexxMsg, LengthArgstring]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/CreateArgstring

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CreateArgstring - Create an argument string structure

    SYNOPSIS
	argstr = CreateArgstring(string, length)
	D0,A0                    A0      D0

	[UBYTE](autodocs-3.5/include-exec-types-h.md) *CreateArgstring(UBYTE *, ULONG);

    FUNCTION
	Allocates a [RexxArg](autodocs-3.5/include-rexx-storage-h.md) structure and copies the supplied string into it.
	The returned pointer points at the string part of the structure
	and can be treated like an ordinary string pointer.  (However, care
	must be taken that you do not change the string)

    INPUTS
	string - A pointer at your input string
	length - The number of bytes of your input string you wish copied.
	         (NOTE:  You are limited to 65,535 byte strings)

    RESULTS
	argstr - A pointer to the argument string.  The results are returned
	         in both A0 and D0.  You should always check the result
	         as an allocation failure would cause an error.

    SEE ALSO
	[DeleteArgstring()](autodocs-3.5/rexxsyslib-library-deleteargstring-2.md), [LengthArgstring()](autodocs-3.5/rexxsyslib-library-lengthargstring-2.md), [ClearRexxMsg()](autodocs-3.5/rexxsyslib-library-clearrexxmsg-2.md), [FillRexxMsg()](autodocs-3.5/rexxsyslib-library-fillrexxmsg-2.md)


    BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [DeleteArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleteargstring)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
- [LengthArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#lengthargstring)
