---
title: commodities.library/CxBroker
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-cxbroker-2
functions: [CxBroker, SetCxObjPri]
libraries: [commodities.library]
---

# commodities.library/CxBroker

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxBroker -- create a commodity broker. (V36)

   SYNOPSIS
	broker = CxBroker(nb,error);
	D0		  A0 D0

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CxBroker(struct [NewBroker](autodocs-3.5/include-libraries-commodities-h.md) *,[LONG](autodocs-3.5/include-exec-types-h.md) *);

   FUNCTION
	This function creates a broker from the specification found in the
	[NewBroker](autodocs-3.5/include-libraries-commodities-h.md) structure pointed to by 'nb'. The purpose and meaning of the
	fields of the [NewBroker](autodocs-3.5/include-libraries-commodities-h.md) structure are described below. Also see
	[<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md) for more info.

	struct [NewBroker](autodocs-3.5/include-libraries-commodities-h.md)
	{
	    [BYTE](autodocs-3.5/include-exec-types-h.md)            nb_Version;
	    [STRPTR](autodocs-3.5/include-exec-types-h.md)          nb_Name;
	    [STRPTR](autodocs-3.5/include-exec-types-h.md)          nb_Title;
	    [STRPTR](autodocs-3.5/include-exec-types-h.md)          nb_Descr;
	    WORD            nb_Unique;
	    WORD	    nb_Flags;
	    [BYTE](autodocs-3.5/include-exec-types-h.md)            nb_Pri;
	    struct [MsgPort](autodocs-3.5/include-exec-ports-h.md) *nb_Port;
	    WORD            nb_ReservedChannel;
	};

	nb_Version
	This is the way that future versions of commodities can identify
	which version of the [NewBroker](autodocs-3.5/include-libraries-commodities-h.md) structure you are using. This should be
	set to NB_VERSION as defined in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md)

	nb_Name
	This is the name of the broker. This name is used to find the broker
	in commodities' object list and is the name shown in the listview
	gadget of the Exchange program. The name string is copied in the
	broker object upon creation so it can be discarded right after
	CxBroker() returns. The maximum length of the name string is defined
	by a constant in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

	nb_Title, nb_Descr
	These are two strings which appear to the user in the Exchange
	program and describe the application the broker is representing.
	Note that these strings are copied into the broker object so they
	can be discarded right after CxBroker() returns. The maximum length
	of these strings that will be recognized are defined by constants in
	[<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

	nb_Unique
	This field indicates what should happen if a broker of the same name
	(nb_Name) already exists in commodities' object list. Constants
	in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md) allow the caller to specify whether
	another broker is to be created, and whether any existing broker of
	the same name should be notified that an attempt at creating a
	duplicate has been made.

	nb_Pri
	This specifies with what priority the new broker is to be inserted
	within commodities' object list. Higher priority nodes appear
	earlier in a list. It is strongly recommended that the ToolTypes
	environment of an application be used to allow the end-user to set
	the priority of the broker.

   INPUTS
	nb - an initialized [NewBroker](autodocs-3.5/include-libraries-commodities-h.md) structure
	error - a pointer to a longword where to store a failure code (may be
		NULL)

   RESULTS
	broker - a pointer to the broker object or NULL upon failure. If the
		 'error' pointer is not NULL, a further diagnostic code is
		 placed at that address. Error codes are defined in
		 [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md) and include:

			CBERR_OK
			No problems; broker created OK.

 			CBERR_SYSERR
			System problems, not your fault, sign of low memory.

			CBERR_DUP
			The nb_Unique field specified that only one broker of
			'nb_Name' should be allowed, and one already exists.

			CBERR_VERSION
			The version specified in 'nb_Version' is unknown to the
			library.

   SEE ALSO
	[SetCxObjPri()](autodocs-3.5/commodities-library-setcxobjpri-2.md), [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md)

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
- [SetCxObjPri — commodities.library](../autodocs/commodities.library.md#setcxobjpri)
