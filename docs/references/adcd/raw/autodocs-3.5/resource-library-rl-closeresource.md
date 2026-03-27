# resource.library/RL_CloseResource



   NAME
	RL_CloseResource - close and free a resource object (V44)

   SYNOPSIS
	RL_CloseResource(resource)
	                   A0

	VOID RL_CloseResource(RESOURCEFILE);

   FUNCTION
	This routine closes a resource object that was previously opened with
	[RL_OpenResource](../Includes_and_Autodocs_3._guide/node0545.html). It frees all objects and object groups.

   INPUTS
	resource -- a pointer to a resource. A value of NULL is acceptable
	            which means a no-op.

   RESULTS


   SEE ALSO
	[resource.library/RL_OpenResource](../Includes_and_Autodocs_3._guide/node0545.html)

