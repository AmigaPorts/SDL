---
title: amiga.lib/printf
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-printf-2
functions: [Output]
libraries: [dos.library]
---

# amiga.lib/printf

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	printf - print a formatted output line to the standard output.

   SYNOPSIS
	printf(formatstring [,value [,values] ] );

   FUNCTION
	[Format](autodocs-3.5/dos-library-format-2.md) the output in accordance with specifications in the format
	string.

   INPUTS
	formatString - a C-language-like NULL-terminated format string,
		       with the following supported % options:

	  %[flags][width][.limit][length]type

	    $     - must follow the arg_pos value, if specified
	  flags   - only one allowed. '-' specifies left justification.
	  width   - field width. If the first character is a '0', the
	            field is padded with leading 0s.
	    .     - must precede the field width value, if specified
	  limit   - maximum number of characters to output from a string.
	            (only valid for %s or %b).
	  length  - size of input data defaults to word (16-bit) for types c,
		    d, u and x, 'l' changes this to long (32-bit).
	  type    - supported types are:
	                  b - BSTR, data is 32-bit [BPTR](autodocs-3.5/include-dos-dos-h.md) to byte count followed
	                      by a byte string. A NULL [BPTR](autodocs-3.5/include-dos-dos-h.md) is treated as an
			      empty string. (V36)
	                  d - signed decimal
			  u - unsigned decimal
	                  x - hexadecimal with hex digits in uppercase
			  X - hexadecimal with hex digits in lowercase
	                  s - string, a 32-bit pointer to a NULL-terminated
	                      byte string. A NULL pointer is treated
	                      as an empty string.
	                  c - character

	value(s) - numeric variables or addresses of null-terminated strings
	           to be added to the format information.

   NOTE
	The global "_stdout" must be defined, and contain a pointer to
	a legal AmigaDOS file handle. Using the standard Amiga startup
	module sets this up. In other cases you will need to define
	stdout, and assign it to some reasonable value (like what the
	[dos.library/Output()](autodocs-3.5/dos-library-output-2.md) call returns). This code would set it up:

		ULONG stdout;
		stdout=Output();

   BUGS
	This function will crash if the resulting stream after
	parameter substitution is longer than 140 bytes.

---

## See Also

- [Output — dos.library](../autodocs/dos.library.md#output)
