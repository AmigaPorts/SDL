---
title: utility.library/ReleaseNamedObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-releasenamedobject
functions: [FindNamedObject, RemNamedObject]
libraries: [utility.library]
---

# utility.library/ReleaseNamedObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ReleaseNamedObject -- free a named object. (V39)

   SYNOPSIS
	ReleaseNamedObject(object);
			   A0

	VOID ReleaseNamedObject(struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *);

   FUNCTION
	Decrements the open count of the object. If the object has been
	removed, and the count goes to 0, the remover will be notified
	that the object is now free.

   INPUTS
	object - the object to release.  (No action if NULL)

   SEE ALSO
	[FindNamedObject()](autodocs-3.5/utility-library-findnamedobject.md), [RemNamedObject()](autodocs-3.5/utility-library-remnamedobject.md)

---

## See Also

- [FindNamedObject — utility.library](../autodocs/utility.library.md#findnamedobject)
- [RemNamedObject — utility.library](../autodocs/utility.library.md#remnamedobject)
