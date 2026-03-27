# intuition.library/RemoveGList



    NAME
	RemoveGList -- [Remove](../Includes_and_Autodocs_3._guide/node022F.html) a sublist of gadgets from a window.

    SYNOPSIS
	Position = RemoveGList( [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), Numgad )
	D0			A0	A1	D0

	[UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) RemoveGList( struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *, struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, WORD );

    FUNCTION
	Removes 'Numgad' gadgets from the gadget list of the specified
	window.  Will remove gadgets from a requester if the first
	gadget's GadgetType flag GTYP_REQGADGET is set.

	Otherwise identical to [RemoveGadget()](../Includes_and_Autodocs_3._guide/node03E2.html).

    NOTE
	The last gadget in the list does NOT have its link zeroed.
	New with V36: OK, last gadget's NextGadget field is set to NULL.

	New with V37: If one of the gadgets you wish to remove
	is the active gadget, this routine will wait for the user
	to release the mouse button before deactivating and removing
	the gadget.

    INPUTS
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window containing the gadget or the requester
	    containing the gadget to be removed.
	[Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) = pointer to the gadget to be removed.  The gadget itself
           describes whether this is a gadget that should be removed
           from the window or some requester.
	Numgad = number of gadgets to be removed.  If -1, remove all gadgets
	    to end of window gadget list

    RESULT
	Returns the ordinal position of the removed gadget.  If the gadget
	wasn't found in the appropriate list, or if there are no gadgets in
	the list, returns -1.

    BUGS

    SEE ALSO
	[RemoveGadget()](../Includes_and_Autodocs_3._guide/node03E2.html), [AddGadget()](../Includes_and_Autodocs_3._guide/node0392.html), [AddGList()](../Includes_and_Autodocs_3._guide/node0393.html)

