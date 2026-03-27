# rexxsyslib.library/LengthArgstring



    NAME
	LengthArgstring - Returns the length value stored in the argstring

    SYNOPSIS
	length = LengthArgstring(argstring)
	D0                       A0

	ULONG LengthArgstring(UBYTE *);

    FUNCTION
	This function returns the length value stored in the argstring.
	This is *NOT* the same as doing a strlen() type call on the
	argstring.  (Note that argstrings may contain NULLs)

    INPUTS
	argstring - A pointer to an argstring that was created by ARexx

    RESULTS
	length - The length of the argstring.

    EXAMPLE

    SEE ALSO
	[CreateArgstring()](../Includes_and_Autodocs_3._guide/node0549.html)


    BUGS
