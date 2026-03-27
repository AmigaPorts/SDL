# amiga.lib/stdio



   NAMES
	fclose	- close a file
	fgetc	- get a character from a file
	fprintf	- format data to file (see [printf()](../Includes_and_Autodocs_3._guide/node0048.html))
	fputc	- put character to file
	fputs	- write string to file
	getchar	- get a character from stdin
	[printf](../Includes_and_Autodocs_3._guide/node0048.html)	- put format data to stdout (see exec.library/RawDoFmt)
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

	To get a suitable AmigaDOS [FileHandle](../Includes_and_Autodocs_3._guide/node05D9.html#line88), the [dos.library/Open()](../Includes_and_Autodocs_3._guide/node0196.html) or
	[dos.library/Output()](../Includes_and_Autodocs_3._guide/node0198.html) functions must be used.

	All of the functions that write to stdout expect an appropriate
	[FileHandle](../Includes_and_Autodocs_3._guide/node05D9.html#line88) to have been set up ahead of time. Depending on
	your C compiler and options, this may have been done by the
	startup code.  Or it can be done manually

	From C:
		extern ULONG stdout;
		/* [Remove](../Includes_and_Autodocs_3._guide/node022F.html) the extern if startup code did not define stdout */
		stdout=Output();

	From assembly:
		XDEF	_stdout
		DC.L	_stdout	;<- Place result of [dos.library/Output()](../Includes_and_Autodocs_3._guide/node0198.html) here.

