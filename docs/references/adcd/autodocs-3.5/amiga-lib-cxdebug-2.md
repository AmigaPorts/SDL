---
title: amiga.lib/CxDebug
manual: autodocs-3.5
chapter: autodocs-3.5
section: amiga-lib-cxdebug-2
functions: [CreateCxObj]
libraries: [commodities.library]
---

# amiga.lib/CxDebug

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxDebug -- create a commodity debug object. (V36)

   SYNOPSIS
	debugObj = CxDebug(id);

	[CxObj](autodocs-3.5/include-libraries-commodities-h.md) *CxDebug(LONG);

   FUNCTION
	This function creates a Commodities debug object. The action of this
	object on receiving a Commodities message is to print out information
	about the Commodities message through the serial port (using the
	kprintf() routine). The value of 'id' will also be displayed.

	Note that this is a synchronous occurrence (the printing is done by
	the input device task). If screen or file output is desired, using a
	sender object instead of a debug object is necessary, since such
	output is best done by your application process.

	This function is a C-language macro for [CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), defined
	in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md).

   INPUTS
	id - the id to assign to the debug object, this value is output
	     whenever the debug object sends data to the serial port.

   RESULTS
	debugObj - a pointer to the debug object, or NULL if it could
		   not be created.

   SEE ALSO
	[commodities.library/CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md), [CxSender()](autodocs-3.5/amiga-lib-cxsender-2.md), debug.lib/kprintf()

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
