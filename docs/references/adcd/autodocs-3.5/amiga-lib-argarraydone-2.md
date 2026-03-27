---
title: amiga.lib/ArgArrayDone
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-argarraydone-2
functions: []
libraries: []
---

# amiga.lib/ArgArrayDone

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ArgArrayDone -- release the memory allocated by a previous call
			to [ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md). (V36)

   SYNOPSIS
	ArgArrayDone();

	VOID ArgArrayDone(VOID);

   FUNCTION
	This function frees memory and does cleanup required after a
	call to [ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md). Don't call this until you are done using
	the ToolTypes argument strings.

   SEE ALSO
	[ArgArrayInit()](autodocs-3.5/amiga-lib-argarrayinit-2.md)

