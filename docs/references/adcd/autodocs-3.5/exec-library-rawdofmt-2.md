---
title: exec.library/RawDoFmt
manual: autodocs-3.5
chapter: autodocs-3.5
section: exec-library-rawdofmt-2
functions: [RawDoFmt]
libraries: [exec.library]
---

# exec.library/RawDoFmt

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RawDoFmt -- format data into a character stream.

   SYNOPSIS
	NextData = RawDoFmt(FormatString, DataStream, PutChProc, PutChData);

       d0                  a0            a1          a2         a3
	[APTR](autodocs-3.5/include-exec-types-h.md) RawDoFmt(STRPTR,[APTR](autodocs-3.5/include-exec-types-h.md),void (*)(),APTR);

   FUNCTION
	perform "C"-language-like formatting of a data stream, outputting
	the result a character at a time.  Where % formatting commands are
	found in the [FormatString](autodocs-3.5/locale-library-formatstring.md), they will be replaced with the
	corresponding element in the DataStream.  %% must be used in the
	string if a % is desired in the output.

	Under V36, RawDoFmt() returns a pointer to the end of the DataStream
	(The next argument that would have been processed).  This allows
	multiple formatting passes to be made using the same data.

   INPUTS
	[FormatString](autodocs-3.5/locale-library-formatstring.md) - a "C"-language-like NULL terminated format string,
	with the following supported % options:

	 %[flags][width.limit][length]type

	flags  - only one allowed. '-' specifies left justification.
	width  - field width.  If the first character is a '0', the
		 field will be padded with leading 0's.
	  .    - must follow the field width, if specified
	limit  - maximum number of characters to output from a string.
		 (only valid for %s).
	length - size of input data defaults to WORD for types d, x,
		 and c, 'l' changes this to long (32-bit).
	type   - supported types are:
			b - BSTR, data is 32-bit [BPTR](autodocs-3.5/include-dos-dos-h.md) to byte count followed
			    by a byte string, or NULL terminated byte string.
			    A NULL [BPTR](autodocs-3.5/include-dos-dos-h.md) is treated as an empty string.
			    (Added in V36 exec)
			d - decimal
			u - unsigned decimal (Added in V37 exec)
			x - hexadecimal
			s - string, a 32-bit pointer to a NULL terminated
			    byte string.  In V36, a NULL pointer is treated
			    as an empty string
			c - character

	DataStream - a stream of data that is interpreted according to
		 the format string.  Often this is a pointer into
		 the task's stack.
	PutChProc  - the procedure to call with each character to be
		 output, called as:

	PutChProc(Char,  PutChData);
		  D0-0:8 A3

		the procedure is called with a NULL Char at the end of
		the format string.

	PutChData - a value that is passed through to the PutChProc
		procedure.  This is untouched by RawDoFmt, and may be
		modified by the PutChProc.

   EXAMPLE
	;
	; Simple version of the C "sprintf" function.  Assumes C-style
	; stack-based function conventions.
	;
	;   long eyecount;
	;   eyecount=2;
	;   sprintf(string,"%s have %ld eyes.","Fish",eyecount);
	;
	; would produce "Fish have 2 eyes." in the string buffer.
	;
		XDEF _sprintf
		XREF _AbsExecBase
		XREF _LVORawDoFmt
	_sprintf:	; ( ostring, format, {values} )
		movem.l a2/a3/a6,-(sp)

		move.l	4*4(sp),a3       ;Get the output string pointer
		move.l	5*4(sp),a0       ;Get the [FormatString](autodocs-3.5/locale-library-formatstring.md) pointer
		lea.l	6*4(sp),a1       ;Get the pointer to the DataStream
		lea.l	stuffChar(pc),a2
		move.l	_AbsExecBase,a6
		jsr	_LVORawDoFmt(a6)

		movem.l (sp)+,a2/a3/a6
		rts

	;------ PutChProc function used by RawDoFmt -----------
	stuffChar:
		move.b	d0,(a3)+        ;Put data to output string
		rts

   WARNING
	This Amiga ROM function formats word values in the data stream.  If
	your compiler defaults to longs, you must add an "l" to your
	% specifications.  This can get strange for characters, which might
	look like "%lc".

	The result of RawDoFmt() is *ONLY* valid in V36 and later releases
	of EXEC.  Pre-V36 versions of EXEC have "random" return values.

   SEE ALSO
	Documentation on the C language "printf" call in any C language
	reference book.

---

## See Also

- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
