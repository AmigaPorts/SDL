# amiga.lib/CreatePort



   NAME
	CreatePort - [Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) and initialize a new message port

   SYNOPSIS
	port = CreatePort(name,pri)

	struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *CreatePort(STRPTR,LONG);

   FUNCTION
	Allocates and initializes a new message port. The message list
	of the new port will be prepared for use (via NewList).  A signal
	bit will be allocated, and the port will be set to signal your
	task when a message arrives (PA_SIGNAL).

	You *must* use [DeletePort()](../Includes_and_Autodocs_3._guide/node0035.html) to delete ports created with
	CreatePort()!

   INPUTS
	name - public name of the port, or NULL if the port is not named.
	       The name string is not copied. Most ports do not need names,
	       see notes below on this.
	pri  - Priority used for insertion into the public port list,
	       normally 0.

   RESULT
	port - a new [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) structure ready for use, or NULL if the port
	       could not be created due to not enough memory or no available
	       signal bit.

   NOTE
	In most cases, ports should not be named. Named ports are used for
	rendez-vous between tasks. Everytime a named port needs to be located,
	the list of all named ports must be traversed. The more named
	ports there are, the longer this list traversal takes. Thus, unless
	you really need to, do not name your ports, which will keep them off
	of the named port list and improve system performance.

   BUGS
	With versions of amiga.lib prior to V37.14, this function would
	not fail even though it couldn't allocate a signal bit. The port
	would be returned with no signal allocated.

   SEE ALSO
	[DeletePort()](../Includes_and_Autodocs_3._guide/node0035.html), [exec.library/FindPort()](../Includes_and_Autodocs_3._guide/node0208.html), [<exec/ports.h>](../Includes_and_Autodocs_3._guide/node062E.html),
	[exec.library/CreateMsgPort()](../Includes_and_Autodocs_3._guide/node01FC.html)

