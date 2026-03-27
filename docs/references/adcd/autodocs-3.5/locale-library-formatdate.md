---
title: locale.library/FormatDate
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-formatdate
functions: [ParseDate]
libraries: [locale.library]
---

# locale.library/FormatDate

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FormatDate -- generate a date string based on a date formatting
		      template. (V38)

   SYNOPSIS
	FormatDate(locale,fmtTemplate,date,putCharFunc);
	           A0     A1          A2   A3

	VOID FormatDate(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *,[STRPTR](autodocs-3.5/include-exec-types-h.md),struct [DateStamp](autodocs-3.5/include-dos-dos-h.md) *,
	                struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *);

   FUNCTION
	This function processes a formatting template and generates
	a stream of bytes that's sent one character at a time to the
	putCharFunc callback hook.

   INPUTS
	locale - the locale to use for the formatting
	fmtTemplate - the NULL-terminated template describing the desired
		      format for the date. This is constructed just like
		      C-language [printf()](autodocs-3.5/amiga-lib-printf-2.md) statements, except that different
		      formatting codes are used. Just like in C, formatting
		      codes start with a % followed by the formatting command.
		      The following commands are accepted by this function:

	                %a - abbreviated weekday name
	                %A - weekday name
	                %b - abbreviated month name
	                %B - month name
	                %c - same as "%a %b %d %H:%M:%S %Y"
	                %C - same as "%a %b %e %T %Z %Y"
	                %d - day number with leading 0s
	                %D - same as "%m/%d/%y"
	                %e - day number with leading spaces
	                %h - abbreviated month name
	                %H - hour using 24-hour style with leading 0s
	                %I - hour using 12-hour style with leading 0s
	                %j - julian date
	                %m - month number with leading 0s
	                %M - the number of minutes with leading 0s
	                %n - insert a linefeed
	                %p - AM or PM strings
	                %q - hour using 24-hour style
	                %Q - hour using 12-hour style
	                %r - same as "%I:%M:%S %p"
	                %R - same as "%H:%M"
	                %S - number of seconds with leadings 0s
	                %t - insert a tab character
	                %T - same as "%H:%M:%S"
	                %U - week number, taking Sunday as first day of week
	                %w - weekday number
	                %W - week number, taking Monday as first day of week
	                %x - same as "%m/%d/%y"
	                %X - same as "%H:%M:%S"
	                %y - year using two digits with leading 0s
	                %Y - year using four digits with leading 0s

	              If the template parameter is NULL, a single NULL byte
		      is sent to putCharFunc.
	date - the date to format into a string
	putCharFunc - a callback hook invoked for every character generated,
		      including for the terminating NULL character. The hook
		      is called with:

		 	A0 - address of [Hook](autodocs-3.5/include-utility-hooks-h.md) structure
			A1 - character for hook to process (not a pointer!)
	                A2 - locale pointer

   SEE ALSO
	[ParseDate()](autodocs-3.5/locale-library-parsedate.md), [<libraries/locale.h>](autodocs-3.5/include-libraries-locale-h.md), [<dos/dos.h>](autodocs-3.5/include-dos-dos-h.md)

---

## See Also

- [ParseDate — locale.library](../autodocs/locale.library.md#parsedate)
