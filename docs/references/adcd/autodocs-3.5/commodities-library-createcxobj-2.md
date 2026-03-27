---
title: commodities.library/CreateCxObj
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-createcxobj-2
functions: [CxBroker, CxObjError]
libraries: [commodities.library]
---

# commodities.library/CreateCxObj

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateCxObj -- create a new commodity object. (V36)

   SYNOPSIS
	co = CreateCxObj(type,arg1,arg2);
	D0		 D0   A0   A1

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CreateCxObj(ULONG,[LONG](autodocs-3.5/include-exec-types-h.md),LONG);

   FUNCTION
	This function creates a commodity object of type 'type'. It is not
	proper to call this function directly. Each object creation routine
	except [CxBroker()](autodocs-3.5/commodities-library-cxbroker-2.md) is defined as a macro in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md)
	These are independently documented.

	All functions which operate on a commodity object are made with
	a reference to the thirty-two bit value returned by this function
	(or by [CxBroker()](autodocs-3.5/commodities-library-cxbroker-2.md)).

   INPUTS
	type - the type of object to create as defined in
	       [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md)
	arg1 - first argument, meaning depends on 'type'
	arg2 - second argument, meaning depends on 'type'

   RESULTS
	co - a pointer to the new object or NULL if it could not be created.
	     A NULL return indicates typically a lack of system memory. Minor
	     problems in creating an object, such as providing a bad filter
	     description to [cx_lib/CxFilter()](autodocs-3.5/amiga-lib-cxfilter-2.md), typically don't cause failure,
	     but are recorded in an internal error field in the new object
	     which can be accessed via [CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md).

   SEE ALSO
	[CxObjError()](autodocs-3.5/commodities-library-cxobjerror-2.md), [cx_lib/CxFilter()](autodocs-3.5/amiga-lib-cxfilter-2.md), [cx_lib/CxSender()](autodocs-3.5/amiga-lib-cxsender-2.md),
	[cx_lib/CxSignal()](autodocs-3.5/amiga-lib-cxsignal-2.md), [cx_lib/CxTranslate()](autodocs-3.5/amiga-lib-cxtranslate-2.md), [cx_lib/CxDebug()](autodocs-3.5/amiga-lib-cxdebug-2.md),
	[cx_lib/CxCustom()](autodocs-3.5/amiga-lib-cxcustom-2.md), [CxBroker()](autodocs-3.5/commodities-library-cxbroker-2.md)

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
- [CxObjError — commodities.library](../autodocs/commodities.library.md#cxobjerror)
