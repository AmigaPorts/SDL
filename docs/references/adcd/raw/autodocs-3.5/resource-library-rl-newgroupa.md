# resource.library/RL_NewGroupA



   NAME
	RL_NewGroupA - allocate a group of objects (V44)

   SYNOPSIS
	group = RL_NewGroupA(resource,id,taglist)
	 D0                   A0      D0  A1

	[Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) **RL_NewGroupA(RESOURCEFILE, RESOURCEID, struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

   FUNCTION
	The routine allocates a group of objects with a given numeric id.

   INPUTS
	resource -- a pointer to a resource
	id -- a numeric id
	taglist -- a pointer to an array of [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31). Currently no tags are
	           defined.

   RESULTS
	group -- a pointer to an array of pointers to [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) or NULL.

   SEE ALSO
	[resource.library/RL_DisposeGroup](../Includes_and_Autodocs_3._guide/node0540.html)
	[resource.library/RL_GetObjectArray](../Includes_and_Autodocs_3._guide/node0542.html)

