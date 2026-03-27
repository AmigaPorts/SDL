# resource.library/RL_NewObjectA



   NAME
	RL_NewObjectA - create a new object (V44)

   SYNOPSIS
	object = RL_NewObjectA(resource,id,taglist)
	 D0                     A0      D0  A1

	[Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *RL_NewObjectA(RESOURCEFILE, RESOURCEID, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);;

   FUNCTION
	The routine creates a new object with a given numeric id.

   INPUTS
	resource -- a pointer to a resource
	id -- a numeric id
	taglist -- a pointer to an array of [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31). The tags are moved
	           forward to the call of NewObjectA, [NewDTObjectA](../Includes_and_Autodocs_3._guide/node0111.html) or
	           whatever is called to create the object

   RESULTS
	object -- a pointer to an [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) or NULL.

   SEE ALSO
	intuition.library/NewObjectA
	[datatypes.library/NewDTObjectA](../Includes_and_Autodocs_3._guide/node0111.html)
	[resource.library/RL_DisposeObject](../Includes_and_Autodocs_3._guide/node0541.html)

