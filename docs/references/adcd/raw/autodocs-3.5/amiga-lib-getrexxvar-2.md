# amiga.lib/GetRexxVar



   NAME
	GetRexxVar - Gets the value of a variable from a running ARexx program

   SYNOPSIS
	error = GetRexxVar(message,varname,bufpointer)
	D0,A1              A0      A1      (C-only)

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) GetRexxVar(struct [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) *,char *,char **);

   FUNCTION
	This function will attempt to extract the value of the symbol
	varname from the ARexx script that sent the message.  When called
	from C, a pointer to the extracted value will be placed in the
	pointer pointed to by bufpointer.  (*bufpointer will be the pointer
	to the value)

	When called from assembly, the pointer will be returned in A1.

	The value string returned *MUST* *NOT* be modified.

	While this function is new in the V37 amiga.lib, it is safe to
	call it in all versions of the operating system.  It is also
	PURE code, thus usable in resident/pure executables.

   NOTE
	This is a stub in amiga.lib.  It is only available via amiga.lib.
	The stub has two labels.  One, _GetRexxVar, takes the arguments
	from the stack.  The other, GetRexxVar, takes the arguments in
	registers.

	This routine does a [CheckRexxMsg()](../Includes_and_Autodocs_3._guide/node0026.html) on the message.

   EXAMPLE

	char	*value;

	/* [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) is one from ARexx */
	if (!GetRexxVar(rxmsg,"TheVar",&value))
	{
		/* The value was gotten and now is pointed to by value */
		printf("Value of TheVar is %sn",value);
	}

   INPUTS
	message		A message gotten from an ARexx script
	varname		The name of the variable to extract
	bufpointer	(For C only) A pointer to a string pointer.

   RESULTS
	error		0 for success, otherwise an error code.
			(Other codes may exists, these are documented)
			3  == Insufficient Storage
			9  == String too long
			10 == invalid message

	A1		(Assembly only)  Pointer to the string.

   SEE ALSO
	[SetRexxVar()](../Includes_and_Autodocs_3._guide/node004B.html), [CheckRexxMsg()](../Includes_and_Autodocs_3._guide/node0026.html)

