# utility.library/AddNamedObject



   NAME
	AddNamedObject -- add a named object to the given namespace. (V39)

   SYNOPSIS
	success = AddNamedObject(nameSpace, object);
	D0			 A0         A1

	[BOOL](../Includes_and_Autodocs_3._guide/node0654.html#line73) AddNamedObject(struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *, struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *);

   FUNCTION
	Adds a new item to a NameSpace.  If the NameSpace doesn't support
	duplicate names, a search for a duplicate will be made, and
	0 (failure) will be returned.  Otherwise, the entry will be
	Enqueue()ed to the NameSpace.

   INPUTS
	nameSpace - the name space to add to (NULL for root namespace)
	object - the object to add  (If NULL, will return failure)

   RESULT
	success - whether the operation succeeded.  Check this always!

   SEE ALSO
	[AttemptRemNamedObject()](../Includes_and_Autodocs_3._guide/node0598.html), [RemNamedObject()](../Includes_and_Autodocs_3._guide/node05AC.html)

