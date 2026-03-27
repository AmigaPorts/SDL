# utility.library/FreeNamedObject



   NAME
	FreeNamedObject -- frees a name object. (V39)

   SYNOPSIS
	FreeNamedObject(object);
			A0

	VOID FreeNamedObject(struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *);

   FUNCTION
	Free one of a number of structures used by utility.library.
	The item must not be a member of any NameSpace, and no one
	may have it open other than yourself. If the object also
	contained a NameSpace, that namespace must be empty.
	Any additional space allocated via the datasize parameter
	for AllocNamedObject() is also released.

   INPUTS
	object - the object to be freed

   SEE ALSO
	[AllocNamedObjectA()](../Includes_and_Autodocs_3._guide/node0595.html)

