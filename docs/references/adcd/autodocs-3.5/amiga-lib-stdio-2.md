---
title: amiga.lib/stdio
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-stdio-2
functions: [Open, Output]
libraries: [dos.library]
---

# amiga.lib/stdio

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAMES
	fclose	- close a file
	fgetc	- get a character from a file
	fprintf	- format data to file (see [printf()](autodocs-3.5/amiga-lib-printf-2.md))
	fputc	- put character to file
	fputs	- write string to file
	getchar	- get a character from stdin
	[printf](autodocs-3.5/amiga-lib-printf-2.md)	- put format data to stdout (see exec.library/RawDoFmt)
	putchar	- put character to stdout
	puts	- put string to stdout, followed by newline

   FUNCTION
	These functions work much like the standard C functions of the same
	names. The file I/O functions all use non-buffered AmigaDOS
	files, and must not be mixed with the file I/O of any C
	compiler. The names of these functions match those found in many
	standard C libraries, when a name conflict occurs, the function is
	generally taken from the FIRST library that was specified on the
	linker's command line.  Thus to use these functions, specify
	the amiga.lib library first.

	To get a suitable AmigaDOS [FileHandle](autodocs-3.5/include-dos-dosextens-h.md), the [dos.library/Open()](autodocs-3.5/dos-library-open-2.md) or
	[dos.library/Output()](autodocs-3.5/dos-library-output-2.md) functions must be used.

	All of the functions that write to stdout expect an appropriate
	[FileHandle](autodocs-3.5/include-dos-dosextens-h.md) to have been set up ahead of time. Depending on
	your C compiler and options, this may have been done by the
	startup code.  Or it can be done manually

	From C:
		extern ULONG stdout;
		/* [Remove](autodocs-3.5/exec-library-remove-2.md) the extern if startup code did not define stdout */
		stdout=Output();

	From assembly:
		XDEF	_stdout
		DC.L	_stdout	;<- Place result of [dos.library/Output()](autodocs-3.5/dos-library-output-2.md) here.

---

## See Also

- [Open — dos.library](../autodocs/dos.library.md#open)
- [Output — dos.library](../autodocs/dos.library.md#output)
