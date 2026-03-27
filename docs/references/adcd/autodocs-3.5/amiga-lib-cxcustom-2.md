---
title: amiga.lib/CxCustom
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-cxcustom-2
functions: [CreateCxObj, CxMsgID]
libraries: [commodities.library]
---

# amiga.lib/CxCustom

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxCustom -- create a custom commodity object. (V36)

   SYNOPSIS
	customObj = CxCustom(action,id);

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CxCustom(LONG(*)(),LONG);

   FUNCTION
	This function creates a custom commodity object. The action
	of this object on receiving a commodity message is to call a
	function of the application programmer's choice.

	The function provided ('action') will be passed a pointer to
	the actual commodities message (in commodities private data
	space), and will actually execute as part of the input handler
	system task. Among other things, the value of 'id' can be
	recovered from the message by using the function [CxMsgID()](autodocs-3.5/commodities-library-cxmsgid-2.md).

	The purpose of this function is two-fold. First, it allows
	programmers to create Commodities Exchange objects with
	functionality that was not imagined or chosen for inclusion
	by the designers. Secondly, this is the only way to act
	synchronously with Commodities.

	This function is a C-language macro for [CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), defined
	in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

   INPUTS
	action - a function to call whenever a message reaches the object
	id - a message id to assign to the object

   RESULTS
	customObj - a pointer to the new custom object, or NULL if it could
		    not be created.

  SEE ALSO
	[commodities.library/CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), [commodities.library/CxMsgID()](autodocs-3.5/commodities-library-cxmsgid-2.md)

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
- [CxMsgID — commodities.library](../autodocs/commodities.library.md#cxmsgid)
