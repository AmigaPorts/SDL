# amiga.lib/SetSuperAttrs



   NAME
	SetSuperAttrs -- Invoke OM_SET method on superclass with varargs.

   SYNOPSIS
	result = SetSuperAttrs( cl, obj, tag, ... )

	ULONG SetSuperAttrs( struct [IClass](../Includes_and_Autodocs_3._guide/node05E6.html#line35) *, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, ULONG, ... );

   FUNCTION
	Boopsi support function which invokes the OM_SET method on the
	superclass of the supplied class for the supplied object.  Allows
	the ops_AttrList to be supplied on the stack (i.e. in a varargs
	way).  The equivalent non-varargs function would simply be

	    DoSuperMethod( cl, obj, OM_SET, taglist, NULL );

   INPUTS
	cl - pointer to boopsi class whose superclass is to
	    receive the OM_SET message
	obj - pointer to boopsi object
	tag - list of tag-attribute pairs, ending in TAG_DONE

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

