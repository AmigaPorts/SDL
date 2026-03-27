---
title: utility.library/FindNamedObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-findnamedobject
functions: [FindNamedObject, ReleaseNamedObject]
libraries: [utility.library]
---

# utility.library/FindNamedObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FindNamedObject -- find the next object of a given name. (V39)

   SYNOPSIS
	object = FindNamedObject(nameSpace, name, lastObject);
	D0                       A0         A1    A2

	struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *FindNamedObject(struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *, [STRPTR](autodocs-3.5/include-exec-types-h.md),
					    struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *);

   FUNCTION
	Finds an object and adds to the open count of the object. The
	object is guaranteed not to be freed until [ReleaseNamedObject()](autodocs-3.5/utility-library-releasenamedobject.md) is
	called. The name comparison is caseless, using the current
	locale string comparison routines.

	If name is NULL, then all objects will be matched.

	If lastObject is non-NULL, it must be an object from the same
	NameSpace found on a previous call to FindNamedObject(). It
	will not be freed by this call. The search will start at the
	node after lastobject, if non-NULL.

	nameSpace is the name space from the named object given
	or the root name space if NULL is given.

   INPUTS
	nameSpace - the name space to search
	name - the name of the object to search for
	lastObject - the starting point for the search or NULL

   RESULT
	object - the first match found, or NULL for no match

   SEE ALSO
	[ReleaseNamedObject()](autodocs-3.5/utility-library-releasenamedobject.md), [<utility/name.h>](autodocs-3.5/include-utility-name-h.md)

---

## See Also

- [FindNamedObject — utility.library](../autodocs/utility.library.md#findnamedobject)
- [ReleaseNamedObject — utility.library](../autodocs/utility.library.md#releasenamedobject)
