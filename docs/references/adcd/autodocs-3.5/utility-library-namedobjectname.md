---
title: utility.library/NamedObjectName
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-namedobjectname
functions: [FindNamedObject, RemNamedObject]
libraries: [utility.library]
---

# utility.library/NamedObjectName

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NamedObjectName -- return the name of the object. (V39)

   SYNOPSIS
	name = NamedObjectName(object);
	D0                     A0

	[STRPTR](autodocs-3.5/include-exec-types-h.md) NamedObjectName(struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *);

   FUNCTION
	Returns the name of the object passed in...
	Note that the name string is passed back as just a pointer to
	a read-only name. If the object goes away, so does the name.

   INPUTS
	object - the object, may be NULL in which case this function
		 returns NULL.

   RESULT
	name - pointer to the name string, or NULL if 'object' is NULL.

   SEE ALSO
	[FindNamedObject()](autodocs-3.5/utility-library-findnamedobject.md), [RemNamedObject()](autodocs-3.5/utility-library-remnamedobject.md)

---

## See Also

- [FindNamedObject — utility.library](../autodocs/utility.library.md#findnamedobject)
- [RemNamedObject — utility.library](../autodocs/utility.library.md#remnamedobject)
