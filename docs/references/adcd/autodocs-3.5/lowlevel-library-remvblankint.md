---
title: lowlevel.library/RemVBlankInt
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-remvblankint
functions: []
libraries: []
---

# lowlevel.library/RemVBlankInt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RemVBlankInt -- remove a previously installed vertical blank routine.
			(V40)

   SYNOPSIS
	RemVBlankInt(intHandle);
		     A1

	VOID RemVBlankInt(APTR);

   FUNCTION
	Removes a vertical blank interrupt routine previously added with
	[AddVBlankInt()](autodocs-3.5/lowlevel-library-addvblankint.md).

   INPUTS
	intHandle - handle obtained from [AddVBlankInt()](autodocs-3.5/lowlevel-library-addvblankint.md). This may be NULL,
		    in which case this function does nothing.

   SEE ALSO
	[AddVBlankInt()](autodocs-3.5/lowlevel-library-addvblankint.md)

