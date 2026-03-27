# resource.library/RL_DisposeGroup



   NAME
	RL_DisposeGroup - dispose a group of objects (V44)

   SYNOPSIS
	RL_DisposeGroup(resource, group)
	                 A0        A1

	VOID RL_DisposeGroup(RESOURCEFILE, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) **);

   FUNCTION
	Disposes a group of objects that was allocated with [RL_NewGroupA](../Includes_and_Autodocs_3._guide/node0543.html).
	Never dispose a object from the group with [RL_DisposeObject](../Includes_and_Autodocs_3._guide/node0541.html),
	[DisposeObject](../Includes_and_Autodocs_3._guide/node03A5.html) or [DisposeDTObject](../Includes_and_Autodocs_3._guide/node0109.html).

   INPUTS
	resource -- a pointer to a resource
	group -- a pointer to an array of pointers to [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18). A value of
	         NULL is acceptable which means a no-op.

   RESULTS


   SEE ALSO
	[resource.library/RL_NewGroupA](../Includes_and_Autodocs_3._guide/node0543.html)

