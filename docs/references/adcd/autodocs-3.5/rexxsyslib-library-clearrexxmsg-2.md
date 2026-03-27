---
title: rexxsyslib.library/ClearRexxMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-clearrexxmsg-2
functions: [CreateArgstring, DeleteArgstring, DeleteRexxMsg, FillRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/ClearRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	ClearRexxMsg - Releases and clears the argument array in a [RexxMsg](autodocs-3.5/include-rexx-storage-h.md)

    SYNOPSIS
	ClearRexxMsg(msgptr, count)
	             A0      D0

	VOID ClearRexxMsg(struct [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) *,ULONG);

    FUNCTION
	This function will [DeleteArgstring()](autodocs-3.5/rexxsyslib-library-deleteargstring-2.md) one or more argstrings from
	the [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) and clear the slot.  The count is used to select the
	number of slots to clear.

    INPUTS
	msgptr - A pointer to a [RexxMsg](autodocs-3.5/include-rexx-storage-h.md)
	count - The number of slots to be cleared.  The number can be from
	        1 to 16.  (There are 16 slots)

    RESULTS
	All of the slots in the given count will be cleared and the argstring
	will have been released.

    SEE ALSO
	[FillRexxMsg()](autodocs-3.5/rexxsyslib-library-fillrexxmsg-2.md), [DeleteRexxMsg()](autodocs-3.5/rexxsyslib-library-deleterexxmsg-2.md), [DeleteArgstring()](autodocs-3.5/rexxsyslib-library-deleteargstring-2.md), [CreateArgstring()](autodocs-3.5/rexxsyslib-library-createargstring-2.md)


    BUGS

---

## See Also

- [CreateArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createargstring)
- [DeleteArgstring — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleteargstring)
- [DeleteRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleterexxmsg)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
