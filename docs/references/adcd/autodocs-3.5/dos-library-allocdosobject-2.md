---
title: dos.library/AllocDosObject
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-allocdosobject-2
functions: [FreeDosObject]
libraries: [dos.library]
---

# dos.library/AllocDosObject

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	AllocDosObject -- Creates a dos object (V36)

   SYNOPSIS
	ptr = AllocDosObject(type, tags)
	D0                    D1    D2

	void *AllocDosObject(ULONG, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	ptr = AllocDosObjectTagList(type, tags)
	D0                 	     D1    D2

	void *AllocDosObjectTagList(ULONG, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

	ptr = AllocDosObjectTags(type, Tag1, ...)

	void *AllocDosObjectTags(ULONG, ULONG, ...)

   FUNCTION
	Create one of several dos objects, initializes it, and returns it
	to you.  Note the DOS_STDPKT returns a pointer to the sp_Pkt of the
	structure.

	This function may be called by a task for all types and tags defined
	in the V37 includes (DOS_FILEHANDLE through DOS_RDARGS and ADO_FH_Mode
	through ADO_PromptLen, respectively).  Any future types or tags
	will be documented as to whether a task may use them.

   INPUTS
	type - type of object requested
	tags - pointer to taglist with additional information

   RESULT
	packet - pointer to the object or NULL

   BUGS
	Before V39, DOS_CLI should be used with care since [FreeDosObject()](autodocs-3.5/dos-library-freedosobject-2.md)
	can't free it.

   SEE ALSO
	[FreeDosObject()](autodocs-3.5/dos-library-freedosobject-2.md), [<dos/dostags.h>](autodocs-3.5/include-dos-dostags-h.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md)

---

## See Also

- [FreeDosObject — dos.library](../autodocs/dos.library.md#freedosobject)
