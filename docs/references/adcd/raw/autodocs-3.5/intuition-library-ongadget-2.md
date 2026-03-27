# intuition.library/OnGadget



    NAME
	OnGadget -- [Enable](../Includes_and_Autodocs_3._guide/node0205.html) the specified gadget.

    SYNOPSIS
	OnGadget( [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213), [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908), [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) )
		  A0      A1      A2

	VOID OnGadget( struct [Gadget](../Includes_and_Autodocs_3._guide/node05E0.html#line213) *, struct [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) *,
		struct [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) * );

    FUNCTION
	This command enables the specified gadget.  When a gadget is
	enabled, these things happen:

```c
        - its imagery is displayed normally (not ghosted)
        - the GFLG_DISABLED flag is cleared
        - the gadget can thereafter be selected by the user
```
	The window parameter must point to the window which contains the
	gadget, or which contains the requester that contains the gadget
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
	Traditional gadgets are rendered very simply.  This can result
	in incomplete clearing away of the ghosting pattern when
	OnGadget() is used.  For example, a button whose imagery consists
	of an [IntuiText](../Includes_and_Autodocs_3._guide/node05E0.html#line655) inside a rectangular [Border](../Includes_and_Autodocs_3._guide/node05E0.html#line683) doesn't have the
	button interior cleared by OnGadget().  This is because OnGadget()
	clears the GFLG_DISABLED flag then redraws the gadget.  Redrawing
	this gadget consists of redrawing the border and text.  Nothing
	redraws the field.

	The solution to this type of problem is to either use a gadget
	whose imagery is a struct [Image](../Includes_and_Autodocs_3._guide/node05E0.html#line704) that covers the whole select area,
	or to manually remove the gadget, erase the gadget's select area
	(say using [EraseRect()](../Includes_and_Autodocs_3._guide/node02D0.html)), then clear the GFLG_DISABLED flag,
	add the gadget back to the window, and refresh it.

    SEE ALSO
	[OffGadget()](../Includes_and_Autodocs_3._guide/node03CF.html)

