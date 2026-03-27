# commodities.library/CxObjType



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
	       defined in [<libraries/commodities.h>](../Includes_and_Autodocs_3._guide/node0632.html). Returns CX_INVALID
	       if 'co' is NULL.

   SEE ALSO
	[CreateCxObj()](../Includes_and_Autodocs_3._guide/node00E4.html)

