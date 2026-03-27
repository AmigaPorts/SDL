---
title: utility.library/ToUpper
manual: autodocs-3.5
chapter: autodocs-3.5
section: utility-library-toupper-2
functions: [ConvToLower, ToUpper]
libraries: [locale.library, utility.library]
---

# utility.library/ToUpper

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ToUpper -- convert a character to upper case. (V37)

   SYNOPSIS
	char = ToUpper(char);
	D0	       D0

	[UBYTE](autodocs-3.5/include-exec-types-h.md) ToUpper(UBYTE);

   FUNCTION
	Converts a character to upper case, handling international character
	sets.

   INPUTS
	char - character to be converted.

   RESULTS
	char - upper case version of input character.

   NOTES
	Whenever locale.library is installed in a system, this function is
	replaced by language-specific code. This means that depending on
	which language the user has currently selected, a given character may
	return different results when passed to this function. This fact must
	be taken into consideration when using this function.

   SEE ALSO
	ToUpper(), [locale.library/ConvToLower()](autodocs-3.5/locale-library-convtolower.md)

---

## See Also

- [ConvToLower — locale.library](../autodocs/locale.library.md#convtolower)
- [ToUpper — utility.library](../autodocs/utility.library.md#toupper)
