# rexxsyslib.library/CreateArgstring



    NAME
	CreateArgstring - Create an argument string structure

    SYNOPSIS
	argstr = CreateArgstring(string, length)
	D0,A0                    A0      D0

	[UBYTE](../Includes_and_Autodocs_3._guide/node0654.html#line50) *CreateArgstring(UBYTE *, ULONG);

    FUNCTION
	Allocates a [RexxArg](../Includes_and_Autodocs_3._guide/node0633.html#line85) structure and copies the supplied string into it.
	The returned pointer points at the string part of the structure
	and can be treated like an ordinary string pointer.  (However, care
	must be taken that you do not change the string)

    INPUTS
	string - A pointer at your input string
	length - The number of bytes of your input string you wish copied.
	         (NOTE:  You are limited to 65,535 byte strings)

    RESULTS
	argstr - A pointer to the argument string.  The results are returned
	         in both A0 and D0.  You should always check the result
	         as an allocation failure would cause an error.

    SEE ALSO
	[DeleteArgstring()](../Includes_and_Autodocs_3._guide/node054B.html), [LengthArgstring()](../Includes_and_Autodocs_3._guide/node054F.html), [ClearRexxMsg()](../Includes_and_Autodocs_3._guide/node0548.html), [FillRexxMsg()](../Includes_and_Autodocs_3._guide/node054D.html)


    BUGS
