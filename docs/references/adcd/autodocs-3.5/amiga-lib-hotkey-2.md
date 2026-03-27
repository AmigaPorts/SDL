---
title: amiga.lib/HotKey
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-hotkey-2
functions: [CxObjError, SetFilter]
libraries: [commodities.library]
---

# amiga.lib/HotKey

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	HotKey -- create a commodity triad. (V36)

   SYNOPSIS
	filterObj = Hotkey(description,port,id);

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *HotKey(STRPTR,struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *,LONG);

   FUNCTION
	This function creates a triad of commodity objects to accomplish a
	high-level function.

	The three objects are a filter, which is created to match by the call
	CxFilter(description), a sender created by the call CxSender(port,id),
	and a translator which is created by CxTranslate(NULL), so that it
	swallows any commodity input event messages that are passed down by
	the filter.

	This is the simple way to get a message sent to your program when the
	user performs a particular input action.

	It is strongly recommended that the ToolTypes environment be used to
	allow the user to specify the input descriptions for your application's
	hotkeys.

   INPUTS
	description - the description string to use for the filter in the same
		      format as accepted by [commodities.library/SetFilter()](autodocs-3.5/commodities-library-setfilter-2.md)
	port - port for the sender to send messages to.
	id - id of the messages sent by the sender

   RESULTS
	filterObj - a pointer to a filter object, or NULL if it could
		    not be created.

   SEE ALSO
	[CxFilter()](autodocs-3.5/amiga-lib-cxfilter-2.md), [CxSender()](autodocs-3.5/amiga-lib-cxsender-2.md), [CxTranslate()](autodocs-3.5/amiga-lib-cxtranslate-2.md),
	[commodities.library/CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md), [commodities.library/SetFilter()](autodocs-3.5/commodities-library-setfilter-2.md)

---

## See Also

- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
- [SetFilter — commodities.library](../autodocs/commodities.library.md#setfilter)
