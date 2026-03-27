# amiga.lib/DoSuperMethodA



   NAME
	DoSuperMethodA -- Perform method on object coerced to superclass.

   SYNOPSIS
	result = DoSuperMethodA( cl, obj, msg )

	ULONG DoSuperMethodA( struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, [Msg](../Includes_and_Autodocs_3._guide/node0636.html#line28) );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object, as though it were the superclass
	of the specified class.

   INPUTS
	cl - pointer to boopsi class whose superclass is to
	    receive the message
	obj - pointer to boopsi object
	msg - pointer to method-specific message to send

   RESULT
	result - class and message-specific result.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.
	Some early example code may refer to this function as DSM().

   SEE ALSO
	[CoerceMethodA()](../Includes_and_Autodocs_3._guide/node0028.html), [DoMethodA()](../Includes_and_Autodocs_3._guide/node0039.html), [DoSuperMethod()](../Includes_and_Autodocs_3._guide/node003A.html), [<intuition/classusr.h>](../Includes_and_Autodocs_3._guide/node0636.html)
	ROM Kernel Manual boopsi section

