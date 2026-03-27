# utility.library/NamedObjectName



   NAME
	NamedObjectName -- return the name of the object. (V39)

   SYNOPSIS
	name = NamedObjectName(object);
	D0                     A0

	[STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) NamedObjectName(struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *);

   FUNCTION
	Returns the name of the object passed in...
	Note that the name string is passed back as just a pointer to
	a read-only name. If the object goes away, so does the name.

   INPUTS
	object - the object, may be NULL in which case this function
		 returns NULL.

   RESULT
	name - pointer to the name string, or NULL if 'object' is NULL.

   SEE ALSO
	[FindNamedObject()](../Includes_and_Autodocs_3._guide/node059F.html), [RemNamedObject()](../Includes_and_Autodocs_3._guide/node05AC.html)

