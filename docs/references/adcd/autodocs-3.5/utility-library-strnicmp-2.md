---
title: utility.library/Strnicmp
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-strnicmp-2
functions: [Stricmp, StrnCmp]
libraries: [locale.library, utility.library]
---

# utility.library/Strnicmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	Strnicmp -- length-limited case-insensitive string compare. (V37)

   SYNOPSIS
	result = Strnicmp(string1,string2,length);
	D0		  A0      A1	  D0

	[LONG](autodocs-3.5/include-exec-types-h.md) Strnicmp(STRPTR,[STRPTR](autodocs-3.5/include-exec-types-h.md),LONG);

   FUNCTION
	This function compares two strings, ignoring case using a generic
	case conversion routine. If the strings have different lengths,
	the shorter is treated as if it were extended with zeros. This function
	never compares more than 'length' characters.

   INPUTS
	string1, string2 - strings to be compared
	length - maximum number of characters to examine

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
	[Stricmp()](autodocs-3.5/utility-library-stricmp-2.md), [locale.library/StrnCmp()](autodocs-3.5/locale-library-strncmp.md)

---

## See Also

- [Stricmp — utility.library](../autodocs/utility.library.md#stricmp)
- [StrnCmp — locale.library](../autodocs/locale.library.md#strncmp)
