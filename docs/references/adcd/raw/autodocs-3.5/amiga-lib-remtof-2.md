# amiga.lib/RemTOF



   NAME
	RemTOF - remove a task from the VBlank interrupt server chain.

   SYNOPSIS
	RemTOF(i);

	VOID RemTOF(struct [Isrvstr](../Includes_and_Autodocs_3._guide/node0622.html#line17) *);

   FUNCTION
	Removes a task from the vertical-blanking interval interrupt server
	chain.

   INPUTS
	i - pointer to an [Isrvstr](../Includes_and_Autodocs_3._guide/node0622.html#line17) structure

   SEE ALSO
	[AddTOF()](../Includes_and_Autodocs_3._guide/node001C.html), [<graphics/graphint.h>](../Includes_and_Autodocs_3._guide/node0622.html)

