---
title: rexxsyslib.library/DeleteArgstring
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-deleteargstring-2
functions: [ClearRexxMsg, CreateArgstring, FillRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/DeleteArgstring

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DeleteArgstring - Releases an Argstring created by [CreateArgstring()](autodocs-3.5/rexxsyslib-library-createargstring-2.md)

    SYNOPSIS
	DeleteArgstring(argstring)
	                A0

	VOID DeleteArgstring(UBYTE *);

    FUNCTION
	Releases an argstring.  The argstring must have been created by ARexx

    INPUTS
	argstring - A pointer to the string buffer of an argstring.

    RESULTS

    SEE ALSO
	[CreateArgstring()](autodocs-3.5/rexxsyslib-library-createargstring-2.md), [ClearRexxMsg()](autodocs-3.5/rexxsyslib-library-clearrexxmsg-2.md), [FillRexxMsg()](autodocs-3.5/rexxsyslib-library-fillrexxmsg-2.md)


    BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
