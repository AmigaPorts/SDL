# graphics.library/DrawGList



   NAME
	DrawGList -- [Process](../Includes_and_Autodocs_3._guide/node05D9.html#line36) the gel list, queueing VSprites, drawing Bobs.

   SYNOPSIS
	DrawGList(rp, vp)
	          A1  A0

	void DrawGList(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *);

   FUNCTION
	Performs one pass of the current gel list.
	   - If nextLine and lastColor are defined, these are
	     initialized for each gel.
```c
          - If it's a [VSprite](../Includes_and_Autodocs_3._guide/node05D4.html#line71), build it into the copper list.
          - If it's a [Bob](../Includes_and_Autodocs_3._guide/node05D4.html#line138), draw it into the current raster.
          - Copy the save values into the "old" variables,
```
	     double-buffering if required.

   INPUTS
	rp = pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) where Bobs will be drawn
	vp = pointer to the [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) for which VSprites will be created

   RESULT

   BUGS
	MUSTDRAW isn't implemented yet.

   SEE ALSO
	[InitGels()](../Includes_and_Autodocs_3._guide/node02F4.html)  [graphics/gels.h](../Includes_and_Autodocs_3._guide/node05D4.html) [graphics/rastport.h](../Includes_and_Autodocs_3._guide/node05D7.html)  [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

