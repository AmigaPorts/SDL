# utility.library/FindNamedObject



   NAME
	FindNamedObject -- find the next object of a given name. (V39)

   SYNOPSIS
	object = FindNamedObject(nameSpace, name, lastObject);
	D0                       A0         A1    A2

	struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *FindNamedObject(struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57),
					    struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *);

   FUNCTION
	Finds an object and adds to the open count of the object. The
	object is guaranteed not to be freed until [ReleaseNamedObject()](../Includes_and_Autodocs_3._guide/node05AB.html) is
	called. The name comparison is caseless, using the current
	locale string comparison routines.

	If name is NULL, then all objects will be matched.

	If lastObject is non-NULL, it must be an object from the same
	NameSpace found on a previous call to FindNamedObject(). It
	will not be freed by this call. The search will start at the
	node after lastobject, if non-NULL.

	nameSpace is the name space from the named object given
	or the root name space if NULL is given.

   INPUTS
	nameSpace - the name space to search
	name - the name of the object to search for
	lastObject - the starting point for the search or NULL

   RESULT
	object - the first match found, or NULL for no match

   SEE ALSO
	[ReleaseNamedObject()](../Includes_and_Autodocs_3._guide/node05AB.html), [<utility/name.h>](../Includes_and_Autodocs_3._guide/node0631.html)

