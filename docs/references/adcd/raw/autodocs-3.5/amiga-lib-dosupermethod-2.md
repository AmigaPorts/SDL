# amiga.lib/DoSuperMethod



   NAME
	DoSuperMethod -- Perform method on object coerced to superclass.

   SYNOPSIS
	result = DoSuperMethod( cl, obj, MethodID, ... )

	ULONG DoSuperMethod( struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, ULONG, ... );

   FUNCTION
	Boopsi support function that invokes the supplied message
	on the specified object, as though it were the superclass
	of the specified class.  Equivalent to [DoSuperMethodA()](../Includes_and_Autodocs_3._guide/node003B.html),
	but allows you to build the message on the stack.

   INPUTS
	cl - pointer to boopsi class whose superclass is to
	    receive the message
	obj - pointer to boopsi object
	... - method-specific message built on the stack

   RESULT
	result - class and message-specific result.

   NOTES
	This function first appears in the V37 release of amiga.lib.
	While it intrinsically does not require any particular release
	of the system software to operate, it is designed to work with
	the boopsi subsystem of Intuition, which was only introduced
	in V36.

   SEE ALSO
	[CoerceMethodA()](../Includes_and_Autodocs_3._guide/node0028.html), [DoMethodA()](../Includes_and_Autodocs_3._guide/node0039.html), [DoSuperMethodA()](../Includes_and_Autodocs_3._guide/node003B.html), [<intuition/classusr.h>](../Includes_and_Autodocs_3._guide/node0636.html)
	ROM Kernel Manual boopsi section

