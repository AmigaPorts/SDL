---
title: utility.library/AllocNamedObjectA
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-allocnamedobjecta
functions: [FreeNamedObject, ReleaseNamedObject]
libraries: [utility.library]
---

# utility.library/AllocNamedObjectA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocNamedObjectA -- allocate a named object. (V39)

   SYNOPSIS
	object = AllocNamedObjectA(name, tagList);
	D0                         A0    A1

	struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *AllocNamedObjectA(STRPTR, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	object = AllocNamedObject(name, Tag1, ...);

	struct [NamedObject](autodocs-3.5/include-utility-name-h.md) *AllocNamedObject(STRPTR, ULONG, ...);

   FUNCTION
	Allocates a [NamedObject](autodocs-3.5/include-utility-name-h.md) and initializes it as needed to the
	name given. This object can then be used as an object in the
	namespaces. Tags can be given to make an object contain a
	namespace such that nested namespaces can be built.
	When the object is allocated, it automatically has one use.
	If you later wish to release this object such that others may
	remove it from the namespace you must do a [ReleaseNamedObject()](autodocs-3.5/utility-library-releasenamedobject.md).

   INPUTS
	name - name for the object (must not be NULL)
	tagList - tags with additional information for the allocation or NULL

   TAGS
	ANO_NameSpace - [BOOL](autodocs-3.5/include-exec-types-h.md) tag, default FALSE.  If this tag is
	                TRUE, the named object will also have a
	                name space attached to it.
	ANO_UserSpace - ULONG tag, default 0.  If this tag is non-NULL
	                it defines the size (in bytes) of the user
	                space to be allocated with the named object
	                and that will be pointed to by the no_Object
	                pointer.  This memory is long-word aligned.
	                If no space is defined, no_Object will be NULL.
	ANO_Priority  - [BYTE](autodocs-3.5/include-exec-types-h.md) tag, default 0.  This tag lets you pick
	                a priority for the named object for when it is
	                placed into a name space.
	ANO_Flags     - ULONG tag, default 0.  This tag lets you set
	                the flags of the NameSpace (if you allocated
	                one)  There currently are only TWO flags.
	                Do *NOT* set *any* other bits as they are for
	                future use!!!  (You can't read them anyway)
	                The flags are:
	                NSF_NODUPS	- Name space must be unique.
	                NSF_CASE	- Name space is case sensitive

   RESULT
	object - the object allocated, or NULL for failure. The object
	         is defined as a pointer to a pointer.  You can do what you
	         wish with the pointer. (It may be NULL or contain a pointer
	         to memory that you had asked for in the tags.)

   SEE ALSO
	[FreeNamedObject()](autodocs-3.5/utility-library-freenamedobject.md), [<utility/name.h>](autodocs-3.5/include-utility-name-h.md)

---

## See Also

- [FreeNamedObject — utility.library](../autodocs/utility.library.md#freenamedobject)
- [ReleaseNamedObject — utility.library](../autodocs/utility.library.md#releasenamedobject)
