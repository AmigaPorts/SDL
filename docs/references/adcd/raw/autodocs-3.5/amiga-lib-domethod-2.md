# amiga.lib/DoMethod



   NAME
	DoMethod -- Perform method on object.

   SYNOPSIS
	result = DoMethod( obj, MethodID, ... )

	ULONG DoMethod( [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, ULONG, ... );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object.  The message is invoked on the
	object's true class.  Equivalent to [DoMethodA()](../Includes_and_Autodocs_3._guide/node0039.html), but allows
	you to build the message on the stack.

   INPUTS
	obj - pointer to boopsi object
	MethodID - which method to send (see [<intuition/classusr.h>](../Includes_and_Autodocs_3._guide/node0636.html))
	... - method-specific message built on the stack

   RESULT
	result - specific to the message and the object's class.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.

   SEE ALSO
	[DoMethodA()](../Includes_and_Autodocs_3._guide/node0039.html), [CoerceMethodA()](../Includes_and_Autodocs_3._guide/node0028.html), [DoSuperMethodA()](../Includes_and_Autodocs_3._guide/node003B.html), [<intuition/classusr.h>](../Includes_and_Autodocs_3._guide/node0636.html)
	ROM Kernel Manual boopsi section

