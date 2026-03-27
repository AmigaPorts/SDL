# graphics.library/GfxLookUP



   NAME
    	GfxLookUp -- find a graphics extended node associated with a 
		     given pointer (V36)

   SYNOPSIS

```c
       result = GfxLookUp( pointer );
       d0		    a0
```
	struct [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) *GfxLookUp( void *);

   FUNCTION
	Finds a special graphics extended data structure (if any) associated
	with the pointer to a data structure (eg: [ViewExtra](../Includes_and_Autodocs_3._guide/node05ED.html#line75) associated with
	a [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure).

   INPUTS
	pointer = a pointer to a data structure which may have an
		  [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) associated with it (typically a [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) ).

   RESULT
	result = a pointer to the [ExtendedNode](../Includes_and_Autodocs_3._guide/node060A.html#line16) that has previously been
		 associated with the pointer.

   BUGS

   SEE ALSO
	[graphics/gfxnodes.h](../Includes_and_Autodocs_3._guide/node060A.html) [GfxNew()](../Includes_and_Autodocs_3._guide/node02F1.html) [GfxFree()](../Includes_and_Autodocs_3._guide/node02EF.html) [GfxAssociate()](../Includes_and_Autodocs_3._guide/node02EE.html)

