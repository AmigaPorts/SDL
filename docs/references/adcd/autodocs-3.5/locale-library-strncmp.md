---
title: locale.library/StrnCmp
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-strncmp
functions: [CloseLocale, OpenLocale, StrConvert]
libraries: [locale.library]
---

# locale.library/StrnCmp

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StrnCmp -- localized string comparison. (V38)

   SYNOPSIS
	result = StrnCmp(locale,string1,string2,length,type);
	D0               A0     A1      A2      D0     D1

	[LONG](autodocs-3.5/include-exec-types-h.md) StrnCmp(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *,[STRPTR](autodocs-3.5/include-exec-types-h.md),[STRPTR](autodocs-3.5/include-exec-types-h.md),[LONG](autodocs-3.5/include-exec-types-h.md),ULONG);

   FUNCTION
	Compares string1 to string2 according to the collation information
	provided by the locale and returns an integer greater than,
	equal to, or less than zero, accordingly as the string pointed to
	by string1 is greater than, equal to, or less than the string
	pointed to by string2.

	The length parameter specifies how many characters to compare, or if
	the length is specified as -1 then the strings are compared until
	a NULL is encountered.

	The type parameter dictates how the comparison is to be performed.

   INPUTS
	locale - the locale to use for this comparison
	string1	- NULL-terminated string
	string2	- NULL-terminated string
	length - the maximum number of characters to be compared, or -1 to
		 compare all characters until a NULL is encountered
	type - describes how the comparison is to be performed. The following
	       values can be passed:
		 SC_ASCII causes an ASCII-based case-insensitive comparison
		 to be performed. SC_ASCII is the fastest of the comparison
		 types, but it uses ASCII ordering and considers accented
		 characters different than their non-accented counterparts.

		 SC_COLLATE1 causes the characters to be compared using their
		 primary sorting order. This effectively produces a comparison
		 that ignores letter case and diacritical marks. That is,
		 letters such as "e" and "é" are treated as if they were both
		 "e".

		 SC_COLLATE2 causes the characters to be compared using both
		 their primary and secondary sorting order. SC_COLLATE2 is
		 slower than SC_COLLATE1. This is the type of comparison to
		 use when sorting data to be presented to the user. It operates
		 in two passes. First it performs a comparison equivalent to
		 SC_COLLATE1. If both strings compare the same, then a second
		 pass is made using the secondary sorting order, which gives
		 finer resolution to the comparison. For example, SC_COLLATE1
		 would return the following strings as identical:
		    "père"  and  "pere"
		 since SC_COLLATE1 ignores diacritical marks. SC_COLLATE2
		 would make a second pass over the string comparing
		 diacritical marks instead of actual characters.

   RESULT
	result - relationship between string1 and string2
			<0 means string1 < string2
			=0 means string1 = string2
			>0 means string1 > string2

   SEE ALSO
	[OpenLocale()](autodocs-3.5/locale-library-openlocale.md), [CloseLocale()](autodocs-3.5/locale-library-closelocale.md), [StrConvert()](autodocs-3.5/locale-library-strconvert.md)

---

## See Also

- [CloseLocale — locale.library](../autodocs/locale.library.md#closelocale)
- [OpenLocale — locale.library](../autodocs/locale.library.md#openlocale)
- [StrConvert — locale.library](../autodocs/locale.library.md#strconvert)
