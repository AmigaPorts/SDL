---
title: amiga.lib/NewList
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-newlist-2
functions: []
libraries: []
---

# amiga.lib/NewList

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	NewList -- prepare a list structure for use

   SYNOPSIS
	NewList(list)

	VOID NewList(struct [List](autodocs-3.5/include-exec-lists-h.md) *);
	VOID NewList(struct [MinList](autodocs-3.5/include-exec-lists-h.md) *);

   FUNCTION
	Perform the magic needed to prepare a [List](autodocs-3.5/include-exec-lists-h.md) header structure for
	use; the list will be empty and ready to use.  (If the list is the
	full featured type, you may need to initialize lh_Type afterwards)

	Assembly programmers may want to use the NEWLIST macro instead.

   INPUTS
	list - pointer to a [List](autodocs-3.5/include-exec-lists-h.md) or [MinList](autodocs-3.5/include-exec-lists-h.md).

   SEE ALSO
	[<exec/lists.h>](autodocs-3.5/include-exec-lists-h.md)

