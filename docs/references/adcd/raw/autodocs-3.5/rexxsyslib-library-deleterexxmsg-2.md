# rexxsyslib.library/DeleteRexxMsg



    NAME
	DeleteRexxMsg - Releases a [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) structure created by [CreateRexxMsg()](../Includes_and_Autodocs_3._guide/node054A.html)

    SYNOPSIS
	DeleteRexxMsg(packet)
	              A0

	VOID DeleteRexxMsg(struct [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) *);

    FUNCTION
	The function releases an ARexx message packet that was allocated
	with [CreateRexxMsg()](../Includes_and_Autodocs_3._guide/node054A.html).  Any argument fields in the [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) structure
	should be cleared before calling this function as it does
	not release them for you.

    INPUTS
	packet - A pointer to a [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) structure allocated by [CreateRexxMsg()](../Includes_and_Autodocs_3._guide/node054A.html)

    EXAMPLE
	if (rmsg=CreateRexxMsg(myport,"myapp","MYAPP_PORT"))
	{
		/* Do my think with rmsg */
		ClearRexxMsg(rmsg,16);	/* We may not want to clear all 16 */
		DeleteRexxMsg(rmsg);
	}

    SEE ALSO
	[CreateRexxMsg()](../Includes_and_Autodocs_3._guide/node054A.html), [ClearRexxMsg()](../Includes_and_Autodocs_3._guide/node0548.html)


    BUGS
