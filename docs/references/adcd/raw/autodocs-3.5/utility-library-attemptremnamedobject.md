# utility.library/AttemptRemNamedObject



   NAME
	AttemptRemNamedObject -- attempt to remove a named object. (V39)

   SYNOPSIS
	result = AttemptRemNamedObject(object);
	D0                             A0

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) AttemptRemNamedObject(struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *);

   FUNCTION
	Attempts to remove an object from whatever NameSpace it's in.
	You must have found the object first (in order to get a use count)
	before trying to remove it.  If the object is in use or is
	in the process of being removed, this function will return
	a failure code.  If the object is fully removed, the object will
	then be available to be [FreeNamedObject()](../Includes_and_Autodocs_3._guide/node05A1.html).

   INPUTS
	object - the object to attempt to remove  The object must be valid

   RESULT
	success - FALSE if object is still in use (somewhere)
	          TRUE if object was removed

   SEE ALSO
	[RemNamedObject()](../Includes_and_Autodocs_3._guide/node05AC.html), [AddNamedObject()](../Includes_and_Autodocs_3._guide/node0593.html), [ReleaseNamedObject()](../Includes_and_Autodocs_3._guide/node05AB.html)

