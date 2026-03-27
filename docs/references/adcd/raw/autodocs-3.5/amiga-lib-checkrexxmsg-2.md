# amiga.lib/CheckRexxMsg



   NAME
	CheckRexxMsg - Check if a [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) is from ARexx

   SYNOPSIS
	result = CheckRexxMsg(message)
	D0                    A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) CheckRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) *);

   FUNCTION
	This function checks to make sure that the message is from ARexx
	directly.  It is required when using the Rexx Variable Interface
	routines (RVI) that the message be from ARexx.

	While this function is new in the V37 amiga.lib, it is safe to
	call it in all versions of the operating system.  It is also
	PURE code, thus usable in resident/pure executables.

   NOTE
	This is a stub in amiga.lib.  It is only available via amiga.lib.
	The stub has two labels.  One, _CheckRexxMsg, takes the arguments
	from the stack.  The other, CheckRexxMsg, takes the arguments in
	registers.

   EXAMPLE
	if (CheckRexxMsg(rxmsg))
	{
		/* [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) is one from ARexx */
	}

   INPUTS
	message		A pointer to the [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) in question

   RESULTS
	result		A boolean - TRUE if message is from ARexx.

   SEE ALSO
	[GetRexxVar()](../Includes_and_Autodocs_3._guide/node003F.html), [SetRexxVar()](../Includes_and_Autodocs_3._guide/node004B.html)

