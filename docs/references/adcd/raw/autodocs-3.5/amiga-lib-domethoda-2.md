# amiga.lib/DoMethodA



   NAME
	DoMethodA -- Perform method on object.

   SYNOPSIS
	result = DoMethodA( obj, msg )

	ULONG DoMethodA( [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, [Msg](../Includes_and_Autodocs_3._guide/node0636.html#line28) );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object.  The message is invoked on the
	object's true class.

   INPUTS
	obj - pointer to boopsi object
	msg - pointer to method-specific message to send

   RESULT
	result - specific to the message and the object's class.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.
	Some early example code may refer to this function as DM().

   SEE ALSO
	[DoMethod()](../Includes_and_Autodocs_3._guide/node0038.html), [CoerceMethodA()](../Includes_and_Autodocs_3._guide/node0028.html), [DoSuperMethodA()](../Includes_and_Autodocs_3._guide/node003B.html), [<intuition/classusr.h>](../Includes_and_Autodocs_3._guide/node0636.html)
	ROM Kernel Manual boopsi section

