---
title: intuition.library/OnGadget
manual: autodocs-3.5
chapter: autodocs-3.5
section: intuition-library-ongadget-2
functions: [AddGList, EraseRect, OffGadget, OnGadget, RefreshGList]
libraries: [graphics.library, intuition.library]
---

# intuition.library/OnGadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

    NAME
	OnGadget -- [Enable](autodocs-3.5/exec-library-enable-2.md) the specified gadget.

    SYNOPSIS
	OnGadget( [Gadget](autodocs-3.5/include-intuition-intuition-h.md), [Window](autodocs-3.5/include-intuition-intuition-h.md), [Requester](autodocs-3.5/include-intuition-intuition-h.md) )
		  A0      A1      A2

	VOID OnGadget( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
		struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) * );

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
	gadgets using [AddGList()](autodocs-3.5/intuition-library-addglist-2.md), and selectively call [RefreshGList()](autodocs-3.5/intuition-library-refreshglist-2.md).

    INPUTS
	[Gadget](autodocs-3.5/include-intuition-intuition-h.md) = pointer to the gadget that you want disabled
	[Window](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a window structure containing the gadget or
	    containing the requester which contains the gadget
	[Requester](autodocs-3.5/include-intuition-intuition-h.md) = pointer to a requester (may by NULL if this isn't
```c
           a requester gadget (i.e. GTYP_REQGADGET is not set)).

    RESULT
```
	None

    BUGS
	Traditional gadgets are rendered very simply.  This can result
	in incomplete clearing away of the ghosting pattern when
	OnGadget() is used.  For example, a button whose imagery consists
	of an [IntuiText](autodocs-3.5/include-intuition-intuition-h.md) inside a rectangular [Border](autodocs-3.5/include-intuition-intuition-h.md) doesn't have the
	button interior cleared by OnGadget().  This is because OnGadget()
	clears the GFLG_DISABLED flag then redraws the gadget.  Redrawing
	this gadget consists of redrawing the border and text.  Nothing
	redraws the field.

	The solution to this type of problem is to either use a gadget
	whose imagery is a struct [Image](autodocs-3.5/include-intuition-intuition-h.md) that covers the whole select area,
	or to manually remove the gadget, erase the gadget's select area
	(say using [EraseRect()](autodocs-3.5/graphics-library-eraserect-2.md)), then clear the GFLG_DISABLED flag,
	add the gadget back to the window, and refresh it.

    SEE ALSO
	[OffGadget()](autodocs-3.5/intuition-library-offgadget-2.md)

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
- [OffGadget — intuition.library](../autodocs/intuition.library.md#offgadget)
- [OnGadget — intuition.library](../autodocs/intuition.library.md#ongadget)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
