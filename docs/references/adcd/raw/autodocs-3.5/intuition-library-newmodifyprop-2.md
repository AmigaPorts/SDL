# intuition.library/NewModifyProp



    NAME
	NewModifyProp -- [ModifyProp()](../Includes_and_Autodocs_3._guide/node03C6.html), but with selective refresh.

    SYNOPSIS
	NewModifyProp( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143), Flags,
		       A0      A1      A2         D0
		HorizPot, VertPot, HorizBody, VertBody, NumGad )
		D1        D2       D3         D4        D5

	VOID NewModifyProp( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) *, [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43), WORD );

    FUNCTION
	Performs the function of [ModifyProp()](../Includes_and_Autodocs_3._guide/node03C6.html), but refreshes
	gadgets in the list as specified by the NumGad parameter.
	With NumGad = -1, this function is identical to [ModifyProp()](../Includes_and_Autodocs_3._guide/node03C6.html).

	New for V36: When NumGad = 1, this function will now perform
	an incremental update of the proportional gadget knob image,
	rather than refreshing the entire gadget.  This means much
	less flashing when programmatically scrolling a proportional
	gadget.

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
	NumGad = number of gadgets to be refreshed after propgadget internals
	    have been adjusted.  -1 means "to end of list."

    RESULT
	None

    BUGS

    SEE ALSO 
	[ModifyProp()](../Includes_and_Autodocs_3._guide/node03C6.html)
	The Intuition Reference Manual contains more information on
	Proportional Gadgets.

