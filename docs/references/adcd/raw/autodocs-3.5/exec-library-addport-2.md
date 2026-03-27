# exec.library/AddPort



   NAME
	AddPort -- add a public message port to the system

   SYNOPSIS
	AddPort(port)
		A1

	void AddPort(struct [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) *);

   FUNCTION
	This function attaches a message port structure to the system's
	public message port list, where it can be found by the [FindPort()](../Includes_and_Autodocs_3._guide/node0208.html)
	function.  The name and priority fields of the port structure must
	be initialized prior to calling this function.	If the user does
	not require the priority field, it should be initialized to zero.

	Only ports that will be searched for with [FindPort()](../Includes_and_Autodocs_3._guide/node0208.html) need to
	be added to the system list.  In addition, adding ports is often
	useful during debugging.  If the port will be searched for,
	the priority field should be at least 1 (to avoid the large number
	of inactive ports at priority zero).  If the port will be searched
	for often, set the priority in the 50-100 range (so it will be
	before other less used ports).

	Once a port has been added to the naming list, you must be careful
	to remove the port from the list (via RemPort) before deallocating
	its memory.

   NOTE
	A point of confusion is that clearing a [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27) structure to all
	zeros is not enough to prepare it for use.  As mentioned in the
	Exec chapter of the ROM Kernel Manual, the [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) for the [MsgPort](../Includes_and_Autodocs_3._guide/node062E.html#line27)
	must be initialized.  This is automatically handled by AddPort(),
	and [amiga.lib/CreatePort](../Includes_and_Autodocs_3._guide/node002A.html).  This initialization can be done manually
	with [amiga.lib/NewList](../Includes_and_Autodocs_3._guide/node0047.html) or the assembly NEWLIST macro.

	Do not AddPort an active port.

   INPUTS
	port - pointer to a message port

   SEE ALSO
	[RemPort()](../Includes_and_Autodocs_3._guide/node0230.html), [FindPort()](../Includes_and_Autodocs_3._guide/node0208.html), [amiga.lib/CreatePort()](../Includes_and_Autodocs_3._guide/node002A.html), [amiga.lib/NewList()](../Includes_and_Autodocs_3._guide/node0047.html)

