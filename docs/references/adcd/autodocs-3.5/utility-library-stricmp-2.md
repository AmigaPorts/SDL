---
title: utility.library/Stricmp
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-stricmp-2
functions: [StrnCmp, Strnicmp]
libraries: [locale.library, utility.library]
---

# utility.library/Stricmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Stricmp	-- case-insensitive string comparison. (V37)

   SYNOPSIS
	result = Stricmp(string1,string2);
	D0		 A0      A1

	[LONG](autodocs-3.5/include-exec-types-h.md) Stricmp(STRPTR,STRPTR);

   FUNCTION
	This function compares two strings, ignoring case using a generic
	case conversion routine. If the strings have different lengths,
	the shorter is treated as if it were extended with zeros.

   INPUTS
	string1, string2 - strings to be compared

   RESULTS
	result - relationship between string1 and string2
			<0 means string1 < string2
			=0 means string1 = string2
			>0 means string1 > string2

   NOTES
	Whenever locale.library is installed in a system, this function is
	replaced by language-specific code. This means that depending on
	which language the user has currently selected, identical pairs of
	strings may return different values when passed to this function.
	This fact must be taken into consideration when using this function.

   SEE ALSO
	[Strnicmp()](autodocs-3.5/utility-library-strnicmp-2.md), [locale.library/StrnCmp()](autodocs-3.5/locale-library-strncmp.md)

---

## See Also

- [StrnCmp — locale.library](../autodocs/locale.library.md#strncmp)
- [Strnicmp — utility.library](../autodocs/utility.library.md#strnicmp)
