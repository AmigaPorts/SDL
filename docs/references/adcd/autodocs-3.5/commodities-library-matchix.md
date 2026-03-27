---
title: commodities.library/MatchIX
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-matchix
functions: [MatchIX, ParseIX]
libraries: [commodities.library]
---

# commodities.library/MatchIX

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	MatchIX -- see if an input event matches an initialized input
		   expression. (V38)

   SYNOPSIS
	match = MatchIX(event,ix);
	D0		A0    A1

	[BOOL](autodocs-3.5/include-exec-types-h.md) MatchIX(struct [InputEvent](autodocs-3.5/include-devices-inputevent-h.md) *,IX *);

   FUNCTION
	This function determines whether an input event matches an
	initialized input expression. Applications generally do not
	need to call this function as filter objects will normally provide
	all the event filtering needed. Nevertheless, MatchIX()
	can come in handy as it is the same function used to match an
	event to the various filter objects when an event makes its way
	through the input network.

   INPUTS
	event - the input event to match against the input expression
	ix - the input expression for the comparison

   RESULTS
	match - TRUE if the input event matches the input expression, or
		FALSE if not

   SEE ALSO
	[<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md), [ParseIX()](autodocs-3.5/commodities-library-parseix-2.md)

---

## See Also

- [MatchIX — commodities.library](../autodocs/commodities.library.md#matchix)
- [ParseIX — commodities.library](../autodocs/commodities.library.md#parseix)
