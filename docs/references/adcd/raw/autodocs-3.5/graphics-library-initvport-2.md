# graphics.library/InitVPort



   NAME   
	InitVPort - Initialize [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure.

   SYNOPSIS
	InitVPort( vp )
		   a0

	void InitViewPort( struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) * );

   FUNCTION
	Initialize [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure to default values.

   INPUTS
	vp - pointer to a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure

   RESULT
	[ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure set to all 0's. (1.0,1.1)

```c
       New field added SpritePriorities, initialized to 0x24 (1.2)
```
   BUGS

   SEE ALSO
	[MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

