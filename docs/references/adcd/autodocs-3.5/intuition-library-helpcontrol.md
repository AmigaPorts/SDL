---
title: intuition.library/HelpControl
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-helpcontrol
functions: [GetUniqueID]
libraries: [utility.library]
---

# intuition.library/HelpControl

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME 
	HelpControl -- Enable/disable Gadget-Help feature. (V39)

    SYNOPSIS 
	HelpControl( window, flags )
	             A0      D0

	VOID HelpControl( struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG );

    FUNCTION 
	This function can be used to turn Gadget-Help on or off for
	your window.  Gadget-Help will also be enabled/disabled
	accordingly for all other windows which share the same
	help-group.  This allows Gadget-Help to be well-behaved
	for multiple-window applications.

    INPUTS 
	window - Pointer to the window you wish to affect.  (Other windows
	    will also be affected, as explained above.
	flags - Currently, HC_GADGETHELP or zero are the allowed values.

    RESULT 
	One or more windows will have Gadget-Help turned on or off.

    NOTES
	You must use [utility.library/GetUniqueID()](autodocs-3.5/utility-library-getuniqueid.md) to get a help-group
	identifier.  Never ever supply your own!

    SEE ALSO 
	WA_HelpGroup

---

## See Also

- [GetUniqueID — utility.library](../autodocs/utility.library.md#getuniqueid)
