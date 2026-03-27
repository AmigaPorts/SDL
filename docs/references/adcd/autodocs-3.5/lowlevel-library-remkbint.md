---
title: lowlevel.library/RemKBInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-remkbint
functions: []
libraries: []
---

# lowlevel.library/RemKBInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  NAME
	RemKBInt -- remove a previously installed keyboard interrupt. (V40)

  SYNOPSIS
	RemKBInt(intHandle);
	         A1

	VOID RemKBInt(APTR);

  FUNCTION
	[Remove](autodocs-3.5/exec-library-remove-2.md) a keyboard interrupt routine previously added with [AddKBInt()](autodocs-3.5/lowlevel-library-addkbint.md).

  INPUTS
	intHandle - handle obtained from [AddKBInt()](autodocs-3.5/lowlevel-library-addkbint.md). This may be NULL,
		    in which case this function does nothing.

  SEE ALSO
	[AddKBInt()](autodocs-3.5/lowlevel-library-addkbint.md)

