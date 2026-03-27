---
title: commodities.library/CxMsgType
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-cxmsgtype-2
functions: []
libraries: []
---

# commodities.library/CxMsgType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxMsgType -- obtain the type of a commodity message. (V36)

   SYNOPSIS
	type = CxMsgType(cxm);
	D0		 A0

	ULONG CxMsgType(struct CxMsg *);

   FUNCTION
	This function returns the type of a commodity message. Possible values
	of 'type' are defined in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md). Most commodity
	messages are of type CXM_IEVENT.

   INPUTS
	cxm - the commodity message to inquire about (must NOT be NULL)

   RESULTS
   	type - the type of the commodity message, possible values are defined
	       in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md)

