---
title: utility.library/AddNamedObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-addnamedobject
functions: [AttemptRemNamedObject, Enqueue, RemNamedObject]
libraries: [exec.library, utility.library]
---

# utility.library/AddNamedObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AddNamedObject -- add a named object to the given namespace. (V39)

   SYNOPSIS
	success = AddNamedObject(nameSpace, object);
	D0			 A0         A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) AddNamedObject(struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *, struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *);

   FUNCTION
	Adds a new item to a NameSpace.  If the NameSpace doesn't support
	duplicate names, a search for a duplicate will be made, and
	0 (failure) will be returned.  Otherwise, the entry will be
	Enqueue()ed to the NameSpace.

   INPUTS
	nameSpace - the name space to add to (NULL for root namespace)
	object - the object to add  (If NULL, will return failure)

   RESULT
	success - whether the operation succeeded.  Check this always!

   SEE ALSO
	[AttemptRemNamedObject()](autodocs-3.5/utility-library-attemptremnamedobject.md), [RemNamedObject()](autodocs-3.5/utility-library-remnamedobject.md)

---

## See Also

- [AttemptRemNamedObject — utility.library](../autodocs/utility.library.md#attemptremnamedobject)
- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [RemNamedObject — utility.library](../autodocs/utility.library.md#remnamedobject)
