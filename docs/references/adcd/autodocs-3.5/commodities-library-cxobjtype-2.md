---
title: commodities.library/CxObjType
manual: autodocs-3.5
chapter: autodocs-3.5
section: commodities-library-cxobjtype-2
functions: [CreateCxObj]
libraries: [commodities.library]
---

# commodities.library/CxObjType

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CxObjType -- obtain the type of a commodity object. (V36)

   SYNOPSIS
	type = CxObjType(co);
	D0		 A0

	ULONG CxObjType(CxObj *);

   FUNCTION
	This function should not really be necessary. It returns
	the type of a commodity object, which you should already
	know, since you created it in the first place.

   INPUTS
	co - the commodity object to inquire about (may be NULL)

   RESULTS
	type - the type of the commodity object, possible values are
	       defined in [<libraries/commodities.h>](autodocs-3.5/include-libraries-commodities-h.md). Returns CX_INVALID
	       if 'co' is NULL.

   SEE ALSO
	[CreateCxObj()](autodocs-3.5/commodities-library-createcxobj-2.md)

---

## See Also

- [CreateCxObj — commodities.library](../autodocs/commodities.library.md#createcxobj)
