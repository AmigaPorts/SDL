# graphics.library/GfxNew



   NAME

```c
       GfxNew -- allocate a graphics extended data structure (V36)
```
   SYNOPSIS
 	result = GfxNew( node_type );
	d0		 d0

	struct [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) *GfxNew( ULONG);

   FUNCTION
	[Allocate](../Includes_and_Autodocs_3._guide/node01E5.html) a special graphics extended data structure (each of which
	begins with an [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) structure).  The type of structure to
	be allocated is specified by the node_type identifier.

   INPUTS
	node_type = which type of graphics extended data structure to allocate.
		    (see gfxnodes.h for identifier definitions.)

   RESULT
	result = a pointer to the allocated graphics node or NULL if the
		 allocation failed.

   BUGS

   SEE ALSO
	[graphics/gfxnodes.h](../Includes_and_Autodocs_3._guide/node060A.html) [GfxFree()](../Includes_and_Autodocs_3._guide/node02EF.html) [GfxAssociate()](../Includes_and_Autodocs_3._guide/node02EE.html) GfxLookUp()

