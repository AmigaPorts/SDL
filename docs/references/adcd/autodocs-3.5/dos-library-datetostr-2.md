---
title: dos.library/DateToStr
manual: autodocs-3.5
chapter: autodocs-3.5
section: dos-library-datetostr-2
functions: [DateStamp]
libraries: [dos.library]
---

# dos.library/DateToStr

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DateToStr -- Converts a [DateStamp](autodocs-3.5/include-dos-dos-h.md) to a string (V36)

   SYNOPSIS
	success = DateToStr( datetime )
	D0                      D1

	[BOOL](autodocs-3.5/include-exec-types-h.md) DateToStr(struct [DateTime](autodocs-3.5/include-dos-datetime-h.md) *)

   FUNCTION
	DateToStr converts an AmigaDOS [DateStamp](autodocs-3.5/include-dos-dos-h.md) to a human
	readable ASCII string as requested by your settings in the
	[DateTime](autodocs-3.5/include-dos-datetime-h.md) structure.

   INPUTS
	[DateTime](autodocs-3.5/include-dos-datetime-h.md) - a pointer to an initialized [DateTime](autodocs-3.5/include-dos-datetime-h.md) structure.

	The [DateTime](autodocs-3.5/include-dos-datetime-h.md) structure should be initialized as follows:

	dat_Stamp - a copy of the datestamp you wish to convert to
		  ascii.

	dat_Format - a format	byte which specifies the format	of the
		  dat_StrDate.	This can be any	of the following
		  (note: If value used is something other than those
		  below, the default of	FORMAT_DOS is used):

		  FORMAT_DOS:	  AmigaDOS format (dd-mmm-yy).

		  FORMAT_INT:	  International	format (yy-mmm-dd).

		  FORMAT_USA:	  American format (mm-dd-yy).

		  FORMAT_CDN:	  Canadian format (dd-mm-yy).

		  FORMAT_DEF:	  default format for locale.

	dat_Flags - a	flags byte.  The only flag which affects this
		  function is:

		  DTF_SUBST:	  If set, a string such	as Today,
				  Monday, etc.,	will be	used instead
				  of the dat_Format specification if
				  possible.
		  DTF_FUTURE:	  Ignored by this function.

	dat_StrDay - pointer to a buffer to receive the day of the
		  week string.	(Monday, Tuesday, etc.). If null, this
		  string will not be generated.

	dat_StrDate -	pointer	to a buffer to receive the date
		  string, in the format	requested by dat_Format,
		  subject to possible modifications by DTF_SUBST.  If
		  null,	this string will not be	generated.

	dat_StrTime -	pointer	to a buffer to receive the time	of day
		  string. If NULL, this	will not be generated.

   RESULT
	success	- a zero return indicates that the [DateStamp](autodocs-3.5/include-dos-dos-h.md) was
		  invalid, and could not be converted.	Non-zero
		  indicates that the call succeeded.

   SEE ALSO
	[DateStamp()](autodocs-3.5/dos-library-datestamp-2.md), StrtoDate(), [<dos/datetime.h>](autodocs-3.5/include-dos-datetime-h.md)

---

## See Also

- [DateStamp — dos.library](../autodocs/dos.library.md#datestamp)
