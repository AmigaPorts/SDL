# resource.library/RL_GetObjectArray



   NAME
	RL_GetObjectArray - get a pointer to a group of objects (V44)

   SYNOPSIS
	group = RL_GetObjectArray(resource,object,id)
	 D0                        A0       A1    D0

	[Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) **RL_GetObjectArray(RESOURCEFILE, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, RESOURCEID);

   FUNCTION
	If you allocated an [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) using [RL_NewObjectA](../Includes_and_Autodocs_3._guide/node0544.html) a lot of additional
	Objects and group of Objects may be allocated automatically. This
	functions returns a pointer to a group of objects with a given group
	ID.

	Never release the group with RL_DisposeGroupA. The group is released
	automatically if the object is released

   INPUTS
	resource -- a pointer to a resource
	object -- a pointer to an [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18)
	id -- a numeric id of a object group

   RESULTS
	group -- a pointer to an array of pointers to [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18)

   SEE ALSO
	[resource.library/RL_NewObjectA](../Includes_and_Autodocs_3._guide/node0544.html)
	[resource.library/RL_NewGroupA](../Includes_and_Autodocs_3._guide/node0543.html)

