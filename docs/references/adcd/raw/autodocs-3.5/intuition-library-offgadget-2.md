# intuition.library/OffGadget



    NAME
	OffGadget -- [Disable](../Includes_and_Autodocs_3._guide/node0203.html) the specified gadget.

    SYNOPSIS
	OffGadget( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) )
		   A0      A1      A2

	VOID OffGadget( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) * );

    FUNCTION
	This command disables the specified gadget.  When a gadget is
	disabled, these things happen:
	     - its imagery is displayed ghosted
	     - the GFLG_DISABLED flag is set
	     - the gadget cannot be selected by User

	The window parameter must point to the window which contains the
	gadget, or which contains the requester that contains the gadget.
	The requester parameter must only be valid if the gadget has the
	GTYP_REQGADGET flag set, a requirement for all requester gadgets.

       NOTE:  it's never safe to tinker with the gadget list yourself.  Don't
       supply some gadget that Intuition hasn't already processed in
       the usual way.

    	NOTE: for compatibility reasons, this function will refresh all
	gadgets in a requester, and all gadgets from gadget to the
	end of the gadget list if gadget is in a window.

	If you want to improve on this behavior, you may perform the
	equivalent operation yourself: remove a gadget or gadgets,
	change the state of their GFLG_DISABLED flag, replace the
	gadgets using [AddGList()](../Includes_and_Autodocs_3._guide/node0393.html), and selectively call [RefreshGList()](../Includes_and_Autodocs_3._guide/node03DD.html).

    INPUTS
	[Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) = pointer to the gadget that you want disabled
	[Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) = pointer to a window structure containing the gadget or
	    containing the requester which contains the gadget
	[Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) = pointer to a requester (may by NULL if this isn't
```c
           a requester gadget (i.e. GTYP_REQGADGET is not set)).

    RESULT
```
	None

    BUGS

    SEE ALSO
	[OnGadget()](../Includes_and_Autodocs_3._guide/node03D1.html), [AddGadget()](../Includes_and_Autodocs_3._guide/node0392.html), [RefreshGadgets()](../Includes_and_Autodocs_3._guide/node03DC.html)

