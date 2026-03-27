---
title: amiga.lib/CheckRexxMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-checkrexxmsg-2
functions: []
libraries: []
---

# amiga.lib/CheckRexxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CheckRexxMsg - Check if a [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) is from ARexx

   SYNOPSIS
	result = CheckRexxMsg(message)
	D0                    A0

	[BOOL](autodocs-3.5/include-exec-types-h.md) CheckRexxMsg(struct [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) *);

   FUNCTION
	This function checks to make sure that the message is from ARexx
	directly.  It is required when using the Rexx Variable Interface
	routines (RVI) that the message be from ARexx.

	While this function is new in the V37 amiga.lib, it is safe to
	call it in all versions of the operating system.  It is also
	PURE code, thus usable in resident/pure executables.

   NOTE
	This is a stub in amiga.lib.  It is only available via amiga.lib.
	The stub has two labels.  One, _CheckRexxMsg, takes the arguments
	from the stack.  The other, CheckRexxMsg, takes the arguments in
	registers.

   EXAMPLE
	if (CheckRexxMsg(rxmsg))
	{
		/* [Message](autodocs-3.5/include-exec-ports-h.md) is one from ARexx */
	}

   INPUTS
	message		A pointer to the [RexxMsg](autodocs-3.5/include-rexx-storage-h.md) in question

   RESULTS
	result		A boolean - TRUE if message is from ARexx.

   SEE ALSO
	[GetRexxVar()](autodocs-3.5/amiga-lib-getrexxvar-2.md), [SetRexxVar()](autodocs-3.5/amiga-lib-setrexxvar-2.md)

