# intuition.library/DisposeObject



    NAME
	DisposeObject -- Deletes a 'boopsi' object. (V36)

    SYNOPSIS
	DisposeObject( [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) )
	               A0

	VOID DisposeObject( [APTR](../Includes_and_Autodocs_3._guide/node0654.html#line37) );

    FUNCTION
	Deletes a boopsi object and all of it auxiliary data.
	These objects are all created by [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).  Objects
	of certain classes "own" other objects, which will also
	be deleted when the object is passed to DisposeObject().
	[Read](../Includes_and_Autodocs_3._guide/node01A0.html) the per-class documentation carefully to be aware
	of these instances.

    INPUTS
	[Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) = abstract pointer to a boopsi object returned by [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).
		The pointer may be NULL, in which case this function has
		no effect.

    NOTES
	This function invokes the OM_DISPOSE method.

    RESULT
	None.

    BUGS

    SEE ALSO
	[NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html), SetAttrs(), [GetAttr()](../Includes_and_Autodocs_3._guide/node03B5.html), [MakeClass()](../Includes_and_Autodocs_3._guide/node03C3.html),
	Document "Basic Object-Oriented Programming System for Intuition"
	and the "boopsi Class Reference" document.

