# exec.library/FindPort



   NAME
	FindPort -- find a given system message port

   SYNOPSIS
	port = FindPort(name)
	D0		A1

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *FindPort(STRPTR);

   FUNCTION
	This function will search the system message port list for a port
	with the given name.  The first port matching this name will be
	returned.  No arbitration of the port list is done.  This function
	MUST be protected with A [Forbid()/Permit()](../Includes_and_Autodocs_3._guide/node0224.html) pair!

   EXAMPLE
	#include [<exec/types.h>](../Includes_and_Autodocs_3._guide/node0654.html)
	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *FindPort();

	ULONG SafePutToPort(message, portname)
	struct [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) *message;
	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57)          portname;
	{
	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *port;

	    Forbid();
		port = FindPort(portname);
		if (port)
		    PutMsg(port,message);
	    Permit();
	    return((ULONG)port); /* If zero, the port has gone away */
	}

   INPUT
	name - name of the port to find

   RETURN
	port - a pointer to the message port, or zero if
		not found.

