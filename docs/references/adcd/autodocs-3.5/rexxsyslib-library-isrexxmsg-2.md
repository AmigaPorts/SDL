---
title: rexxsyslib.library/IsRexxMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-isrexxmsg-2
functions: [CreateRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/IsRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	IsRexxMsg - Function to determine if a message came from ARexx

    SYNOPSIS
	result = IsRexxMsg(msgptr)
	D0                 A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) IsRexxMsg(struct [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) *);

    FUNCTION
	This function can be used to determine if a message came from an
	ARexx program.

    INPUTS
	msgptr - A pointer to the suspected [RexxMsg](autodocs-3.5/include-rexx-storage-h.md).

    RESULTS
	result - A boolean:  TRUE if it is an ARexx message, FALSE if not.

    SEE ALSO
	[CreateRexxMsg()](autodocs-3.5/rexxsyslib-library-createrexxmsg-2.md)


    BUGS

---

## See Also

- [CreateRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createrexxmsg)
