# commodities.library/AttachCxObj



   NAME
	AttachCxObj -- attach a commodity object to the end of an existing
		       list of objects. (V36)

   SYNOPSIS
	AttachCxObj(headObj,co);
		    A0      A1

	VOID AttachCxObj(CxObj *,[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *);

   FUNCTION
	Adds 'co' to the list of objects pointed to by 'headObj'. The
	new object is added at the end of the list.

   INPUTS
	headObj - pointer to a list of objects. If this value is NULL, then
		  the entire tree of objects pointed to by 'co' is deleted
		  and becomes invalid.
	co - the object to add to the list (may be NULL)

   RESULTS
	If 'co' is NULL, this function will record that fact in the
	internal accumulated error of 'headObj'. This error record
	can be retrieved using [CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html) and cleared using
	[ClearCxObjError()](../Includes_and_Autodocs_3._guide/node00E3.html).

   BUGS
	Until V38, passing a NULL 'headObj' parameter would cause low-memory
	access and unpredictable results.

   SEE ALSO
	[CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html), [ClearCxObjError()](../Includes_and_Autodocs_3._guide/node00E3.html)

