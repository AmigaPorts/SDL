---
title: locale.library/StrConvert
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-strconvert
functions: [StrConvert, StrnCmp]
libraries: [locale.library]
---

# locale.library/StrConvert

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	StrConvert -- transform a string according to collation information.
		      (V38)

   SYNOPSIS
	length = StrConvert(locale,string,buffer,bufferSize,type);
	D0                  A0     A1     A2     D0         D1

	ULONG StrConvert(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *,[STRPTR](autodocs-3.5/include-exec-types-h.md),[APTR](autodocs-3.5/include-exec-types-h.md),ULONG,ULONG);

   FUNCTION
	This function transforms the passed string and places the resulting
	into the supplied buffer. No more than bufferSize bytes are copied
	into the buffer.

	The transformation is such that if the C strcmp() function is applied
	to two transformed strings, it returns a value corresponding to
	the result returned by the [StrnCmp()](autodocs-3.5/locale-library-strncmp.md) function applied to the two
	original strings.

   INPUTS
	locale - the locale to use for the transformation
	string - NULL-terminated string to transform
	buffer - buffer where to put the transformed string
	bufferSize - maximum number of bytes to deposit in the buffer
	             StrConvert() may require more storage than
		     the unconverted string does
	type - describes how the transformation is to be performed. See
	       the documentation on [StrnCmp()](autodocs-3.5/locale-library-strncmp.md) for more information on the
	       comparison types available

   RESULT
	length - length of the transformed string which is the number of bytes
		 deposited in the buffer minus 1 (since strings are NULL-
		 terminated)

   SEE ALSO
	[StrnCmp()](autodocs-3.5/locale-library-strncmp.md), [<libraries/locale.h>](autodocs-3.5/include-libraries-locale-h.md)

---

## See Also

- [StrConvert — locale.library](../autodocs/locale.library.md#strconvert)
- [StrnCmp — locale.library](../autodocs/locale.library.md#strncmp)
