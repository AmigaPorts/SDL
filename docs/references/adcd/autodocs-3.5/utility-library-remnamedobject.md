---
title: utility.library/RemNamedObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-remnamedobject
functions: [AddNamedObject, AttemptRemNamedObject, ReleaseNamedObject, ReplyMsg]
libraries: [exec.library, utility.library]
---

# utility.library/RemNamedObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemNamedObject -- remove a named object. (V39)

   SYNOPSIS
	RemNamedObject(object, message);
	               A0      A1

	VOID RemNamedObject(struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *, struct [Message](autodocs-3.5/include-exec-ports-h.md) *);

   FUNCTION
	This function will post a request to release the object
	from whatever NameSpace it is in.  It will reply the message
	when the object is fully removed.  The message.mn_Node.ln_Name
	field will contain the object pointer or NULL if the object
	was removed by another process.

	This function will effectively do a [ReleaseNamedObject()](autodocs-3.5/utility-library-releasenamedobject.md)
	thus you must have "found" the object first.

   INPUTS
	object - the object to remove: Must be a valid [NamedObject](autodocs-3.5/include-utility-name-h.md).
	message - message to [ReplyMsg()](autodocs-3.5/exec-library-replymsg-2.md) (must be supplied)

   RESULT
	The message is replied with the ln_Name field either being
	the object or NULL. If it contains the object, the object
	is completely removed.

   SEE ALSO
	[AttemptRemNamedObject()](autodocs-3.5/utility-library-attemptremnamedobject.md), [AddNamedObject()](autodocs-3.5/utility-library-addnamedobject.md), [ReleaseNamedObject()](autodocs-3.5/utility-library-releasenamedobject.md)

---

## See Also

- [AddNamedObject — utility.library](../autodocs/utility.library.md#addnamedobject)
- [AttemptRemNamedObject — utility.library](../autodocs/utility.library.md#attemptremnamedobject)
- [ReleaseNamedObject — utility.library](../autodocs/utility.library.md#releasenamedobject)
- [ReplyMsg — exec.library](../autodocs/exec.library.md#replymsg)
