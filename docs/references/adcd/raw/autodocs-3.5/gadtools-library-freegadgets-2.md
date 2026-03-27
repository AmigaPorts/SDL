# gadtools.library/FreeGadgets



   NAME
	FreeGadgets -- free a linked list of gadgets. (V36)

   SYNOPSIS
	FreeGadgets(glist)
	            A0

	VOID FreeGadgets(struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *glist);
	                 A0

   FUNCTION
	Frees any GadTools gadgets found on the linked list of gadgets
	beginning with the specified one.  Frees all the memory that was
	allocated by [CreateGadgetA()](../Includes_and_Autodocs_3._guide/node0275.html).  This function will return safely
	with no action if it receives a NULL parameter.

   INPUTS
	glist - pointer to first gadget in list to be freed.

   SEE ALSO
	[CreateGadgetA()](../Includes_and_Autodocs_3._guide/node0275.html)

