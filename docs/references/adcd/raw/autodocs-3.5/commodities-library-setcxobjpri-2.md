# commodities.library/SetCxObjPri



   NAME
	SetCxObjPri -- set the priority of a commodity object. (V36)

   SYNOPSIS
	oldPri = SetCxObjPri(co,pri)
	D0                   A0 D0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) SetCxObjPri(CxObj *,LONG);

   FUNCTION
	This function sets the priority of a commodity object for the
	purposes of [EnqueueCxObj()](../Includes_and_Autodocs_3._guide/node00EF.html).

	It is strongly recommended that the ToolTypes environment be
	utilized to provide end-user control over the priority of
 	brokers, but application specific ordering of other objects
	within their lists is not dictated.

   INPUTS
	co - the commodity object to affect (may be NULL)
	pri - the object's new priority in the range -128 to +127. A value
	      of 0 is normal.

   RESULTS
	oldPri - the previous priority of the object or 0 if 'co' was NULL.
		 This value is only returned in V38 and beyond.

   BUGS
	This function will not reposition an object within its list when
	its priority changes. To attain the same effect, first remove the
	object from its list using [RemoveCxObj()](../Includes_and_Autodocs_3._guide/node00F4.html), set its priority using
	SetCxObjPri(), and reinsert it in the list using [EnqueueCxObj()](../Includes_and_Autodocs_3._guide/node00EF.html).

   SEE ALSO
	[EnqueueCxObj()](../Includes_and_Autodocs_3._guide/node00EF.html)

