---
title: locale.library/FormatString
manual: autodocs-3.5
chapter: autodocs-3.5
section: locale-library-formatstring
functions: [FormatString, RawDoFmt]
libraries: [exec.library, locale.library]
---

# locale.library/FormatString

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	FormatString -- format data into a character stream. (V38)

   SYNOPSIS
	next = FormatString(locale,fmtTemplate,dataStream,putCharFunc);
	D0                  A0     A1          A2         A3

	[APTR](autodocs-3.5/include-exec-types-h.md) FormatString(struct [Locale](autodocs-3.5/include-libraries-locale-h.md) *,[STRPTR](autodocs-3.5/include-exec-types-h.md),[APTR](autodocs-3.5/include-exec-types-h.md),struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *);

   FUNCTION
	This function performs C-language-like formatting of a data stream,
	outputting the result a character at a time. Where % formatting
	commands are found in the formatting template, they are replaced with
	the corresponding elements in 'dataStream'. %% must be used in the
	string if a % is desired in the output.

	An extension to the standard C-language [printf()](autodocs-3.5/amiga-lib-printf-2.md) conventions used
	by FormatString() is argument position specification. Specifying the
	argument position lets the order of the % commands change while the
	arguments provided remain the same. Using the C [printf()](autodocs-3.5/amiga-lib-printf-2.md) call as an
	example:
	    printf("%d eyes, %d feet and %d ears",eyes,feet,ears);
	    printf("%3$d ears, %1$d eyes and %2$d feet",eyes,feet,ears);
	These two statements would produce the following output:
	    "2 eyes, 3 feet and 4 ears" for the first
	    "4 ears, 2 eyes and 3 feet" for the second

	The argument positioning feature lets you change the format string
	being processed while keeping the data stream the same. This is
	an invaluable tool when translating strings to different languages.

   INPUTS
	locale - the locale to use for the formatting
	fmtTemplate - a C-language-like NULL-terminated format string,
		      with the following supported % options:

	  %[arg_pos$][flags][width][.limit][length]type

	  arg_pos - ordinal position of the argument for this command within
		    the array of arguments pointed to by 'dataStream'
	    $     - must follow the arg_pos value, if specified
	  flags   - only one allowed. '-' specifies left justification.
	  width   - field width. If the first character is a '0', the
	            field is padded with leading 0s.
	    .     - must precede the field limit value, if specified
	  limit   - maximum number of characters to output from a string.
	            (only valid for %s or %b).
	  length  - size of input data defaults to word (16-bit) for types c,
		    d, u and x, 'l' changes this to long (32-bit).
	  type    - supported types are:
	                  b - BSTR, data is 32-bit [BPTR](autodocs-3.5/include-dos-dos-h.md) to byte count followed
	                      by a byte string. A NULL [BPTR](autodocs-3.5/include-dos-dos-h.md) is treated as an
			      empty string.
	                  d - signed decimal
			  D - signed decimal using the locale's formatting
			      conventions
			  u - unsigned decimal
			  U - unsigned decimal using the locale's formatting
			      conventions
	                  x - hexadecimal with hex digits in uppercase
			  X - hexadecimal with hex digits in lowercase
	                  s - string, a 32-bit pointer to a NULL-terminated
	                      byte string. A NULL pointer is treated
	                      as an empty string.
	                  c - character

	              If the formatting template parameter is NULL, the
		      function returns without outputting anything. Note the
		      meaning of %x and %X are swapped with respect to
		      standard C conventions. This is for compatibility with
		      [exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md).

	dataStream - a stream of data that is interpreted according to
		     the format string. Often this is a pointer into
		     the task's stack.
	putCharFunc - a callback hook invoked for every character generated,
		      including for the terminating NULL character. The hook
		      is called with:

		 	A0 - address of [Hook](autodocs-3.5/include-utility-hooks-h.md) structure
			A1 - character for hook to process (not a pointer!)
	                A2 - locale pointer

		     the function is called with a NULL char at the end of
		     the format string.

   RESULT
	next - A pointer to beyond the last data element used in 'dataStream'
	       (the next argument that would have been processed).
	       This allows multiple formatting passes to be made using the
	       same data.

   WARNING
	This function formats word values in the data stream. If your compiler
	defaults to longs, you must add an "l" to your specifications. This
	can get strange for characters, which might look like "%lc".

   SEE ALSO
	[exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md)

---

## See Also

- [FormatString — locale.library](../autodocs/locale.library.md#formatstring)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
