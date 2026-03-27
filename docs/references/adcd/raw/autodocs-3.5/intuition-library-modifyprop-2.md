# intuition.library/ModifyProp



    NAME
	ModifyProp -- Modify the current parameters of a proportional gadget.

    SYNOPSIS
	ModifyProp( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143),
		    A0	    A1	    A2
```c
           	    Flags, HorizPot, VertPot, HorizBody, VertBody )
```
		    D0	   D1	     D2	      D3	 D4

	VOID ModifyProp( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) );

    FUNCTION
	Modifies the parameters of the specified proportional gadget.  The
	gadget's internal state is then recalculated and the imagery
	is redisplayed in the window or requester that contains the gadget.

	The requester variable can point to a requester structure.  If the
	gadget has the GTYP_REQGADGET flag set, the gadget is in a requester
	and the window pointer must point to the window of the requester.
	If this is not the gadget of a requester, the requester argument may
	be NULL.

	NOTE: this function causes all gadgets from the proportional
	gadget to the end of the gadget list to be refreshed, for
	reasons of compatibility.
	For more refined display updating, use [NewModifyProp()](../Includes_and_Autodocs_3._guide/node03CA.html).

	New for V36: ModifyProp() refreshing consists of redrawing gadgets
	completely.  [NewModifyProp()](../Includes_and_Autodocs_3._guide/node03CA.html) has changed this behavior (see
	[NewModifyProp()](../Includes_and_Autodocs_3._guide/node03CA.html)).

    INPUTS
	PropGadget = pointer to a proportional gadget
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to the window containing the gadget or the window
	    containing the requester containing the gadget.
	[Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) = pointer to a requester (may be NULL if this isn't
	    a requester gadget)
	Flags = value to be stored in the Flags field of the [PropInfo](../Includes_and_Autodocs_3._guide/node05E0.html#line537)
	HorizPot = value to be stored in the HorizPot field of the [PropInfo](../Includes_and_Autodocs_3._guide/node05E0.html#line537)
	VertPot = value to be stored in the VertPot field of the [PropInfo](../Includes_and_Autodocs_3._guide/node05E0.html#line537)
	HorizBody = value to be stored in the HorizBody field of the [PropInfo](../Includes_and_Autodocs_3._guide/node05E0.html#line537)
	VertBody = value to be stored in the VertBody field of the [PropInfo](../Includes_and_Autodocs_3._guide/node05E0.html#line537)

    RESULT
	None

    BUGS

    SEE ALSO
	[NewModifyProp()](../Includes_and_Autodocs_3._guide/node03CA.html)
	The Intuition Reference Manual and Amiga ROM Kernel Manual contain
	more information on Proportional Gadgets.

