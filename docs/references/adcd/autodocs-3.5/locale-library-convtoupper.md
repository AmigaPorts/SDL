---
title: locale.library/ConvToUpper
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-convtoupper
functions: []
libraries: []
---

# locale.library/ConvToUpper

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ConvToUpper -- convert a character to upper case. (V38)

   SYNOPSIS
	char = ConvToUpper(locale,character);
	D0	           A0     D0

	ULONG ConvToUpper(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *,ULONG);

   FUNCTION
	This function tests if the character specified is lower case. If it is
	then the upper case version of that character is returned, and if it
	isn't then the original character is returned.

   INPUTS
	locale - the locale to use for the conversion
	character - the character to convert

   RESULT
	char - a (possibly) converted character

   NOTE
	This function requires a full 32-bit character be passed-in in order
	to support multi-byte character sets.

