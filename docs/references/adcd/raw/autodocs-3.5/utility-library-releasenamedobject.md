# utility.library/ReleaseNamedObject



   NAME
	ReleaseNamedObject -- free a named object. (V39)

   SYNOPSIS
	ReleaseNamedObject(object);
			   A0

	VOID ReleaseNamedObject(struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *);

   FUNCTION
	Decrements the open count of the object. If the object has been
	removed, and the count goes to 0, the remover will be notified
	that the object is now free.

   INPUTS
	object - the object to release.  (No action if NULL)

   SEE ALSO
	[FindNamedObject()](../Includes_and_Autodocs_3._guide/node059F.html), [RemNamedObject()](../Includes_and_Autodocs_3._guide/node05AC.html)

