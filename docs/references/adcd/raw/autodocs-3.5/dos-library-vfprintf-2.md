# dos.library/VFPrintf



   NAME
	VFPrintf -- format and print a string to a file (buffered) (V36)

   SYNOPSIS
	count = VFPrintf(fh, fmt, argv)
	D0               D1  D2    D3

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) VFPrintf(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *)

	count = FPrintf(fh, fmt, ...)

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) FPrintf(BPTR, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57), ...)

   FUNCTION
	Writes the formatted string and values to the given file.  This
	routine is assumed to handle all internal buffering so that the
	formatting string and resultant formatted values can be arbitrarily
	long.  Any secondary error code is returned in [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).  This routine
	is buffered.

   INPUTS
	fh    - Filehandle to write to
	fmt   - [RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html) style formatting string
	argv  - Pointer to array of formatting values

   RESULT
	count - Number of bytes written or -1 (EOF) for an error

   BUGS
	The prototype for FPrintf() currently forces you to cast the first
	varargs parameter to [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) due to a deficiency in the program
	that generates fds, prototypes, and amiga.lib stubs.

   SEE ALSO
	[VPrintf()](../Includes_and_Autodocs_3._guide/node01CE.html), [VFWritef()](../Includes_and_Autodocs_3._guide/node01CD.html), [RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html), [FPutC()](../Includes_and_Autodocs_3._guide/node016C.html)

