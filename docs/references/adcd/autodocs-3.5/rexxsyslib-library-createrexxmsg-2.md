---
title: rexxsyslib.library/CreateRexxMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-createrexxmsg-2
functions: [ClearRexxMsg, DeleteRexxMsg, FillRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/CreateRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	CreateRexxMsg - Create an ARexx message structure

    SYNOPSIS
	rexxmsg = CreateRexxMsg(port, extension, host)
	D0,A0                   A0    A1         D0

	struct [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) *CreateRexxMsg(struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *, [UBYTE](autodocs-3.5/include-exec-types-h.md) *);

    FUNCTION
	This functions allocates an ARexx message packet.  The [RexxMsg](autodocs-3.5/include-rexx-storage-h.md)
	consists of a standard EXEC message structure extended to include
	the ARexx specific information.

    INPUTS
	port - A pointer to a public or private message port.  This *MUST*
	       be a valid port as this is where the message will be replied.

	extension - A pointer to a NULL terminated string that is to be used
	            as the default extension for the REXX scripts.  If this
	            is NULL, the default is "REXX"

	host - A pointer to a NULL terminated string that is to be used
	       as the default host port.  The name must be the same as the
	       name of the public message port that is to be the default host.
	       If this field is NULL, the default is REXX.

    RESULTS
	rexxmsg - A [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) structure

    NOTES
	The extension and host strings must remain valid for as long as the
	[RexxMsg](autodocs-3.5/include-rexx-storage-h.md) exists as only the pointer to those strings are stored.

    SEE ALSO
	[DeleteRexxMsg()](autodocs-3.5/rexxsyslib-library-deleterexxmsg-2.md), [ClearRexxMsg()](autodocs-3.5/rexxsyslib-library-clearrexxmsg-2.md), [FillRexxMsg()](autodocs-3.5/rexxsyslib-library-fillrexxmsg-2.md)


    BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [DeleteRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#deleterexxmsg)
- [FillRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#fillrexxmsg)
