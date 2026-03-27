---
title: rexxsyslib.library/DeleteRexxMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: rexxsyslib-library-deleterexxmsg-2
functions: [ClearRexxMsg, CreateRexxMsg]
libraries: [rexxsyslib.library]
---

# rexxsyslib.library/DeleteRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	DeleteRexxMsg - Releases a [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) structure created by [CreateRexxMsg()](autodocs-3.5/rexxsyslib-library-createrexxmsg-2.md)

    SYNOPSIS
	DeleteRexxMsg(packet)
	              A0

	VOID DeleteRexxMsg(struct [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) *);

    FUNCTION
	The function releases an ARexx message packet that was allocated
	with [CreateRexxMsg()](autodocs-3.5/rexxsyslib-library-createrexxmsg-2.md).  Any argument fields in the [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) structure
	should be cleared before calling this function as it does
	not release them for you.

    INPUTS
	packet - A pointer to a [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) structure allocated by [CreateRexxMsg()](autodocs-3.5/rexxsyslib-library-createrexxmsg-2.md)

    EXAMPLE
	if (rmsg=CreateRexxMsg(myport,"myapp","MYAPP_PORT"))
	{
		/* Do my think with rmsg */
		ClearRexxMsg(rmsg,16);	/* We may not want to clear all 16 */
		DeleteRexxMsg(rmsg);
	}

    SEE ALSO
	[CreateRexxMsg()](autodocs-3.5/rexxsyslib-library-createrexxmsg-2.md), [ClearRexxMsg()](autodocs-3.5/rexxsyslib-library-clearrexxmsg-2.md)


    BUGS

---

## See Also

- [ClearRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#clearrexxmsg)
- [CreateRexxMsg — rexxsyslib.library](../autodocs/rexxsyslib.library.md#createrexxmsg)
