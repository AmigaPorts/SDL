# commodities.library/EnqueueCxObj



   NAME
	EnqueueCxObj -- insert a commodity object within a list of objects
		        based on object priority. (V36)

   SYNOPSIS
	EnqueueCxObj(headObj,co);
		     A0      A1

	VOID EnqueueCxObj(CxObj *,[CxObj](../Includes_and_Autodocs_3._guide/node0632.html#line74) *);

   FUNCTION
	This function puts object 'co' into the list of object 'headObj'.
	The insertion point is determined by the object's priority. The
	objects are kept in the list from the highest priority to the
	lowest. New nodes are inserted in front of the first node with a
	lower priority. Hence a FIFO queue for nodes of equal priority.

	The priority of the commodity object can be set using [SetCxObjPri()](../Includes_and_Autodocs_3._guide/node00F6.html).

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
	[SetCxObjPri()](../Includes_and_Autodocs_3._guide/node00F6.html), [CxObjError()](../Includes_and_Autodocs_3._guide/node00E9.html), [ClearCxObjError()](../Includes_and_Autodocs_3._guide/node00E3.html)

