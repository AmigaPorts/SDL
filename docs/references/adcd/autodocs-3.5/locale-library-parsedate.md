---
title: locale.library/ParseDate
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-parsedate
functions: [FormatDate, ParseDate]
libraries: [locale.library]
---

# locale.library/ParseDate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	ParseDate -- interpret a string according to the date formatting
		     template and convert it into a [DateStamp](autodocs-3.5/include-dos-dos-h.md). (V38)

   SYNOPSIS
	state = ParseDate(locale,date,fmtTemplate,getCharFunc);
	D0	          A0     A1   A2          A3

	[BOOL](autodocs-3.5/include-exec-types-h.md) ParseDate(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *,struct [DateStamp](autodocs-3.5/include-dos-dos-h.md) *,[STRPTR](autodocs-3.5/include-exec-types-h.md),struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *);

   FUNCTION
	This function converts a stream of characters into an AmigaDOS
	[DateStamp](autodocs-3.5/include-dos-dos-h.md) structure. The characters are obtained from the
	getCharFunc callback hook and the formatting template is used
	to direct the parse.

   INPUTS
	locale - the locale to use for the formatting
	date - place to put the converted date, this may be NULL in which
	       case this routine can be used to simply validate a date
	fmtTemplate - the date template describing the expected format of the
		      data. See [FormatDate()](autodocs-3.5/locale-library-formatdate.md) documentation for a description of
		      date templates. The following formatting controls from
		      [FormatDate()](autodocs-3.5/locale-library-formatdate.md) can be used in ParseDate():
	                %a %A %b %B %d %e %h %H %I %m %M %p %S %y %Y
	getCharFunc - a callback hook invoked whenever a character is required.
		      The hook should return the next character to process,
		      with a NULL character to indicate the end of the string.
		      The hook is called with:

		 	A0 - address of [Hook](autodocs-3.5/include-utility-hooks-h.md) structure
	                A1 - locale pointer
			A2 - NULL

	              The hook returns the character to process in D0. Note
		      that a complete 32-bit result is expected in D0, not
		      just 8 bits.

   RESULT
	state - TRUE if the parsing went OK, or FALSE if the input did not
		match the template

   SEE ALSO
	[FormatDate()](autodocs-3.5/locale-library-formatdate.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md)

---

## See Also

- [FormatDate — locale.library](../autodocs/locale.library.md#formatdate)
- [ParseDate — locale.library](../autodocs/locale.library.md#parsedate)
