# graphics.library/GfxAssociate



   NAME
	GfxAssociate -- associate a graphics extended node with a given pointer
	                (V36)

   SYNOPSIS

```c
       GfxAssociate(pointer, node);
                    A0       A1
```
	void GfxAssociate(VOID *, struct [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) *);

   FUNCTION
	Associate a special graphics extended data structure (each of which
	begins with an [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) structure)  with another structure via
	the other structure's pointer. Later, when you call GfxLookUp()
	with the other structure's pointer you may retrieve a pointer
	to this special graphics extended data structure, if it is
	available.

   INPUTS
	pointer = a pointer to a data structure.
	node = an [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) structure to associate with the pointer

   RESULT
	an association is created between the pointer and the node such
	that given the pointer the node can be retrieved via GfxLookUp().

   BUGS

   SEE ALSO
	[graphics/gfxnodes.h](../Includes_and_Autodocs_3._guide/node060A.html) [GfxNew()](../Includes_and_Autodocs_3._guide/node02F1.html) [GfxFree()](../Includes_and_Autodocs_3._guide/node02EF.html) GfxLookUp()

