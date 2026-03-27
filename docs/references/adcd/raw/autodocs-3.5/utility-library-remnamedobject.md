# utility.library/RemNamedObject



   NAME
	RemNamedObject -- remove a named object. (V39)

   SYNOPSIS
	RemNamedObject(object, message);
	               A0      A1

	VOID RemNamedObject(struct [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24) *, struct [Message](../Includes_and_Autodocs_3._guide/node062E.html#line46) *);

   FUNCTION
	This function will post a request to release the object
	from whatever NameSpace it is in.  It will reply the message
	when the object is fully removed.  The message.mn_Node.ln_Name
	field will contain the object pointer or NULL if the object
	was removed by another process.

	This function will effectively do a [ReleaseNamedObject()](../Includes_and_Autodocs_3._guide/node05AB.html)
	thus you must have "found" the object first.

   INPUTS
	object - the object to remove: Must be a valid [NamedObject](../Includes_and_Autodocs_3._guide/node0631.html#line24).
	message - message to [ReplyMsg()](../Includes_and_Autodocs_3._guide/node0235.html) (must be supplied)

   RESULT
	The message is replied with the ln_Name field either being
	the object or NULL. If it contains the object, the object
	is completely removed.

   SEE ALSO
	[AttemptRemNamedObject()](../Includes_and_Autodocs_3._guide/node0598.html), [AddNamedObject()](../Includes_and_Autodocs_3._guide/node0593.html), [ReleaseNamedObject()](../Includes_and_Autodocs_3._guide/node05AB.html)

