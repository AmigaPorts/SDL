---
title: commodities.library/CxMsgID
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-cxmsgid-2
functions: []
libraries: []
---

# commodities.library/CxMsgID

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxMsgID -- obtain the ID of a commodity message. (V36)

   SYNOPSIS
	id = CxMsgID(cxm);
	D0	     A0

	[LONG](autodocs-3.5/include-exec-types-h.md) CxMsgID(struct CxMsg *);

   FUNCTION
	This function returns the value associated with the cause or source
	of the commodity message 'cxm'. Values are provided by the application
	when a sender or custom object is created.

   INPUTS
	cxm - the commodity message to inquire about (must NOT be NULL)

   RESULTS
	id - if not specified by the application, the ID value of a
	     commodity message will be 0. It is suggested that using
	     non-zero values in your program as a rule may identify some
	     possible errors.

   SEE ALSO
	[cx_lib/CxSender()](autodocs-3.5/amiga-lib-cxsender-2.md), [cx_lib/CxCustom()](autodocs-3.5/amiga-lib-cxcustom-2.md)

