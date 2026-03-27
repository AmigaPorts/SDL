---
title: iffparse.library/IDtoStr
manual: autodocs-3.5
chapter: autodocs-3.5
section: iffparse-library-idtostr-2
functions: []
libraries: []
---

# iffparse.library/IDtoStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	IDtoStr -- convert a longword identifier to a null-terminated string.
	           (V36)

   SYNOPSIS
	str = IDtoStr(id, buf);
	D0            D0  A0

	[STRPTR](autodocs-3.5/include-exec-types-h.md) IDtoStr(LONG, STRPTR);

   FUNCTION
	Writes the ASCII equivalent of the given longword ID into buf as a
	null-terminated string.

   INPUTS
	id - longword ID.
	buf - character buffer to accept string (at least 5 chars).

   RESULT
	str - the value of 'buf'.

