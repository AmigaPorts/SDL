---
title: lowlevel.library/GetLanguageSelection
manual: autodocs-3.5
chapter: autodocs-3.5
section: lowlevel-library-getlanguageselection
functions: []
libraries: []
---

# lowlevel.library/GetLanguageSelection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetLanguageSelection -- returns the current language selection. (V40)

   SYNOPSIS
	language = GetLanguageSelection();
	D0

	ULONG GetLanguageSelection (VOID);

   FUNCTION
	Determine what the user has specified as a language.

   RESULT
	language - user specified language, or zero if none has yet been
		   specified. See [<libraries/lowlevel.h>](autodocs-3.5/include-libraries-lowlevel-h.md) for a definition
		   of the currently supported language.

   SEE ALSO
	[<libraries/lowlevel.h>](autodocs-3.5/include-libraries-lowlevel-h.md), locale.doc

