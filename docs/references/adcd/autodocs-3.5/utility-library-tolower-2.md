---
title: utility.library/ToLower
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-tolower-2
functions: [ConvToLower, ToUpper]
libraries: [locale.library, utility.library]
---

# utility.library/ToLower

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ToLower -- convert a character to lower case. (V37)

   SYNOPSIS
	char = ToLower(char);
	D0	       D0

	[UBYTE](autodocs-3.5/include-exec-types-h.md) ToLower(UBYTE);

   FUNCTION
	Converts a character to lower case, handling international character
	sets.

   INPUTS
	char - character to be converted.

   RESULTS
	char - lower case version of the input character.

   NOTES
	Whenever locale.library is installed in a system, this function is
	replaced by language-specific code. This means that depending on
	which language the user has currently selected, a given character may
	return different results when passed to this function. This fact must
	be taken into consideration when using this function.

   SEE ALSO
	[ToUpper()](autodocs-3.5/utility-library-toupper-2.md), [locale.library/ConvToLower()](autodocs-3.5/locale-library-convtolower.md)

---

## See Also

- [ConvToLower — locale.library](../autodocs/locale.library.md#convtolower)
- [ToUpper — utility.library](../autodocs/utility.library.md#toupper)
