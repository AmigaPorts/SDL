# exec.library/AddResource



   NAME
	AddResource -- add a resource to the system

   SYNOPSIS
	AddResource(resource)
		    A1

	void AddResource(APTR);

   FUNCTION
	This function adds a new resource to the system and makes it
	available to other users.  The resource must be ready to be called
	at this time.

	Resources currently have no system-imposed structure, however they
	must start with a standard named node (LN_SIZE), and should with
	a standard [Library](../Includes_and_Autodocs_3._guide/node0626.html#line33) node (LIB_SIZE).

   INPUTS
	resource - pointer an initialized resource node

   SEE ALSO
	[RemResource()](../Includes_and_Autodocs_3._guide/node0231.html), [OpenResource()](../Includes_and_Autodocs_3._guide/node0223.html), [MakeLibrary()](../Includes_and_Autodocs_3._guide/node021B.html)

