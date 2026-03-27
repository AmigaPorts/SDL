# graphics.library/GfxFree



   NAME

```c
       GfxFree -- free a graphics extended data structure (V36)
```
   SYNOPSIS

```c
       GfxFree( node );
       	      a0
```
	void GfxFree(struct [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) *);

   FUNCTION
	Free a special graphics extended data structure (each of which
	begins with an [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) structure).

   INPUTS
	node = pointer to a graphics extended data structure obtained via
	       [GfxNew()](../Includes_and_Autodocs_3._guide/node02F1.html).

   RESULT
	the node is deallocated from memory. graphics will disassociate
	this special graphics extended node from any associated data
	structures, if necessary, before freeing it (see [GfxAssociate()](../Includes_and_Autodocs_3._guide/node02EE.html)).

   BUGS
	an [Alert()](../Includes_and_Autodocs_3._guide/node01E3.html) will be called if you attempt to free any structure
	other than a graphics extended data structure obtained via GfxFree().

   SEE ALSO
	[graphics/gfxnodes.h](../Includes_and_Autodocs_3._guide/node060A.html) [GfxNew()](../Includes_and_Autodocs_3._guide/node02F1.html) [GfxAssociate()](../Includes_and_Autodocs_3._guide/node02EE.html) GfxLookUp()

