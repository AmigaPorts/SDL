# exec.library/OpenResource



   NAME
	OpenResource -- gain access to a resource

   SYNOPSIS
	resource = OpenResource(resName)
	D0			A1

	[APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) OpenResource(STRPTR);

   FUNCTION
	This function returns a pointer to a resource that was previously
	installed into the system.

	There is no CloseResource() function.

   INPUTS

       resName - the name of the resource requested.
   RESULTS
	resource - if successful, a resource pointer, else NULL

