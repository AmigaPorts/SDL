---
title: dos.library/StrToLong
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-strtolong-2
functions: []
libraries: []
---

# dos.library/StrToLong

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StrToLong -- string to long value (decimal) (V36)

   SYNOPSIS
	characters = StrToLong(string,value)
	D0                       D1    D2

	[LONG](autodocs-3.5/include-exec-types-h.md) StrToLong(STRPTR, [LONG](autodocs-3.5/include-exec-types-h.md) *)

   FUNCTION
	Converts decimal string into [LONG](autodocs-3.5/include-exec-types-h.md) value.  Returns number of characters
	converted.  Skips over leading spaces & tabs (included in count).  If
	no decimal digits are found (after skipping leading spaces & tabs),
	StrToLong returns -1 for characters converted, and puts 0 into value.

   INPUTS
	string - [Input](autodocs-3.5/dos-library-input-2.md) string.
	value  - Pointer to long value.  Set to 0 if no digits are converted.

   RESULT
	result - Number of characters converted or -1.

   BUGS
	Before V39, if there were no convertible characters it returned the
	number of leading white-space characters (space and tab in this case).

