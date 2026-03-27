---
title: commodities.library/RouteCxMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-routecxmsg-2
functions: [DivertCxMsg]
libraries: [commodities.library]
---

# commodities.library/RouteCxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	RouteCxMsg -- set the next destination of a commodity message. (V36)

   SYNOPSIS
	RouteCxMsg(cxm,co);
		   A0  A1

	VOID RouteCxMsg(struct CxMsg *,[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *);

   FUNCTION
	Establishes the next destination of a commodity message
	to be 'co', which must be a valid commodity object, and
	must be linked in ultimately to commodities' object list.

	Routing of an object is analogous to a 'goto' in a program.
	There is no effect on the message's routing stack.

   INPUTS
	cxm - the commodity message to route (must NOT be NULL)
	co - the commodity object to route the message to (must NOT be NULL)

   SEE ALSO
	[DivertCxMsg()](autodocs-3.5/commodities-library-divertcxmsg-2.md)

---

## See Also

- [DivertCxMsg — commodities.library](../autodocs/commodities.library.md#divertcxmsg)
