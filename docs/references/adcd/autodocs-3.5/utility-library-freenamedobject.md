---
title: utility.library/FreeNamedObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-freenamedobject
functions: [AllocNamedObject]
libraries: [utility.library]
---

# utility.library/FreeNamedObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FreeNamedObject -- frees a name object. (V39)

   SYNOPSIS
	FreeNamedObject(object);
			A0

	VOID FreeNamedObject(struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *);

   FUNCTION
	Free one of a number of structures used by utility.library.
	The item must not be a member of any NameSpace, and no one
	may have it open other than yourself. If the object also
	contained a NameSpace, that namespace must be empty.
	Any additional space allocated via the datasize parameter
	for AllocNamedObject() is also released.

   INPUTS
	object - the object to be freed

   SEE ALSO
	[AllocNamedObjectA()](autodocs-3.5/utility-library-allocnamedobjecta.md)

---

## See Also

- [AllocNamedObject — utility.library](../autodocs/utility.library.md#allocnamedobject)
