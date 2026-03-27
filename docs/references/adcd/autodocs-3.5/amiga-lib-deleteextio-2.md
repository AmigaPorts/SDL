---
title: amiga.lib/DeleteExtIO
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-deleteextio-2
functions: []
libraries: []
---

# amiga.lib/DeleteExtIO

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DeleteExtIO - return memory allocated for extended IO request

   SYNOPSIS
	DeleteExtIO(ioReq);

	VOID DeleteExtIO(struct [IORequest](autodocs-3.5/include-exec-io-h.md) *);

   FUNCTION
	Frees up an IO request as allocated by [CreateExtIO()](autodocs-3.5/amiga-lib-createextio-2.md).

   INPUTS
	ioReq - the [IORequest](autodocs-3.5/include-exec-io-h.md) block to be freed, or NULL.

   SEE ALSO
	[CreateExtIO()](autodocs-3.5/amiga-lib-createextio-2.md)

