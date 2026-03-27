---
title: utility.library/AttemptRemNamedObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-attemptremnamedobject
functions: [AddNamedObject, FreeNamedObject, ReleaseNamedObject, RemNamedObject]
libraries: [utility.library]
---

# utility.library/AttemptRemNamedObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AttemptRemNamedObject -- attempt to remove a named object. (V39)

   SYNOPSIS
	result = AttemptRemNamedObject(object);
	D0                             A0

	[LONG](autodocs-3.5/include-exec-types-h.md) AttemptRemNamedObject(struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *);

   FUNCTION
	Attempts to remove an object from whatever NameSpace it's in.
	You must have found the object first (in order to get a use count)
	before trying to remove it.  If the object is in use or is
	in the process of being removed, this function will return
	a failure code.  If the object is fully removed, the object will
	then be available to be [FreeNamedObject()](autodocs-3.5/utility-library-freenamedobject.md).

   INPUTS
	object - the object to attempt to remove  The object must be valid

   RESULT
	success - FALSE if object is still in use (somewhere)
	          TRUE if object was removed

   SEE ALSO
	[RemNamedObject()](autodocs-3.5/utility-library-remnamedobject.md), [AddNamedObject()](autodocs-3.5/utility-library-addnamedobject.md), [ReleaseNamedObject()](autodocs-3.5/utility-library-releasenamedobject.md)

---

## See Also

- [AddNamedObject — utility.library](../autodocs/utility.library.md#addnamedobject)
- [FreeNamedObject — utility.library](../autodocs/utility.library.md#freenamedobject)
- [ReleaseNamedObject — utility.library](../autodocs/utility.library.md#releasenamedobject)
- [RemNamedObject — utility.library](../autodocs/utility.library.md#remnamedobject)
