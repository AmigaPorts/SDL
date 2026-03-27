# commodities.library/RemoveCxObj



   NAME
	RemoveCxObj -- remove a commodity object from a list. (V36)

   SYNOPSIS
	RemoveCxObj(co);
		    A0

	VOID RemoveCxObj(CxObj *);

   FUNCTION
	This function removes 'co' from any list it may be a part of.
	Will not crash if 'co' is NULL, or if it has not been inserted
	in a list.

   INPUTS
	co - the object to remove (may be NULL)

   SEE ALSO
	[AttachCxObj()](../Includes_and_Autodocs_3._guide/node00E2.html), [EnqueueCxObj()](../Includes_and_Autodocs_3._guide/node00EF.html), [InsertCxObj()](../Includes_and_Autodocs_3._guide/node00F0.html)

