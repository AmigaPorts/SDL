# resource.library/RL_DisposeObject



   NAME
	RL_DisposeObject - dispose an object (V44)

   SYNOPSIS
	RL_DisposeObject(resource, object)
	                  A0        A1

	VOID RL_DisposeObject(RESOURCEFILE, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *);

   FUNCTION
	Dispose an object that was allocated with [RL_NewObjectA](../Includes_and_Autodocs_3._guide/node0544.html).

   INPUTS
	resource -- a pointer to a resource
	object -- a pointer to an [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18). A value of NULL is acceptable which
	          means a no-op.

   RESULTS


   SEE ALSO
	[resource.library/RL_NewObjectA](../Includes_and_Autodocs_3._guide/node0544.html)

