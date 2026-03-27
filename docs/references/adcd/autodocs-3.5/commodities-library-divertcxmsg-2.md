---
title: commodities.library/DivertCxMsg
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-divertcxmsg-2
functions: [RouteCxMsg]
libraries: [commodities.library]
---

# commodities.library/DivertCxMsg

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DivertCxMsg -- send a commodity message down an object list. (V36)

   SYNOPSIS
	DivertCxMsg(cxm,headObj,returnObj);
		    A0  A1      A2

	VOID DivertCxMsg(struct CxMsg *,[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *,[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *);

   FUNCTION
	This function sends the commodity message 'cxm' down the list of
	objects attached to 'headObj'. The pointer 'returnObj' is first
	pushed onto the routing stack of 'cxm' so that when the end of the
	list of 'headObj' is reached the SUCCESSOR of 'returnObj' is the
	next destination.

	For example, when a filter finds a match with a message, the
	message is diverted down the filter's list like this:

	  DivertCxMsg(cxm,filter,filter);

   INPUTS
	cxm - the commodity message to divert (must NOT be NULL)
	headObj - the list of objects to divert the message to
	returnObj - the object to use as a place holder

   SEE ALSO
	[RouteCxMsg()](autodocs-3.5/commodities-library-routecxmsg-2.md)

---

## See Also

- [RouteCxMsg — commodities.library](../autodocs/commodities.library.md#routecxmsg)
