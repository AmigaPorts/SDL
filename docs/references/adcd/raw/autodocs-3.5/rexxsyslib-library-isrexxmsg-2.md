# rexxsyslib.library/IsRexxMsg



    NAME
	IsRexxMsg - Function to determine if a message came from ARexx

    SYNOPSIS
	result = IsRexxMsg(msgptr)
	D0                 A0

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) IsRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) *);

    FUNCTION
	This function can be used to determine if a message came from an
	ARexx program.

    INPUTS
	msgptr - A pointer to the suspected [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97).

    RESULTS
	result - A boolean:  TRUE if it is an ARexx message, FALSE if not.

    SEE ALSO
	[CreateRexxMsg()](../Includes_and_Autodocs_3._guide/node054A.html)


    BUGS
