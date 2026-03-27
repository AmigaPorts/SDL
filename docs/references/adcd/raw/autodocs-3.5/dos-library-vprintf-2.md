# dos.library/VPrintf



   NAME
	VPrintf -- format and print string (buffered) (V36)

   SYNOPSIS
	count = VPrintf(fmt, argv)
	  D0            D1   D2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) VPrintf(STRPTR, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *)

	count = Printf(fmt, ...)

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) Printf(STRPTR, ...)

   FUNCTION
	Writes the formatted string and values to [Output()](../Includes_and_Autodocs_3._guide/node0198.html).  This routine is
	assumed to handle all internal buffering so that the formatting string
	and resultant formatted values can be arbitrarily long.  Any secondary
	error code is returned in [IoErr()](../Includes_and_Autodocs_3._guide/node0182.html).  This routine is buffered.

	Note: [RawDoFmt](../Includes_and_Autodocs_3._guide/node0227.html) assumes 16 bit ints, so you will usually need 'l's in
	your formats (ex: %ld versus %d).

   INPUTS
	fmt   - exec.library [RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html) style formatting string
	argv  - Pointer to array of formatting values

   RESULT
	count - Number of bytes written or -1 (EOF) for an error

   BUGS
	The prototype for Printf() currently forces you to cast the first
	varargs parameter to [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) due to a deficiency in the program
	that generates fds, prototypes, and amiga.lib stubs.

   SEE ALSO
	[VFPrintf()](../Includes_and_Autodocs_3._guide/node01CC.html), [VFWritef()](../Includes_and_Autodocs_3._guide/node01CD.html), [RawDoFmt()](../Includes_and_Autodocs_3._guide/node0227.html), [FPutC()](../Includes_and_Autodocs_3._guide/node016C.html)

