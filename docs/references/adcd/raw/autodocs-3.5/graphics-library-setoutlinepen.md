# graphics.library/SetOutlinePen



   NAME


```c
       SetOutlinePen -- Set the Outline Pen value for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) (V39).
```
   SYNOPSIS
```c
       old_pen=SetOutlinePen  ( rp, pen )
```
	  d0	                 a0   d0

	ULONG SetOutlinePen(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *,ULONG)

   FUNCTION
	Set the current value of the O pen for the rastport and turn on area outline
	mode. This function should be used instead of poking the structure directly,
	because future graphics devices may store it differently, for instance,
	using more bits.

   INPUTS
```c
       rp  =  a pointer to a valid [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
```
	pen =  a longword pen number

	returns the previous outline pen
   BUGS

   NOTES

   SEE ALSO
	[GetOPen()](../Includes_and_Autodocs_3._guide/node02E8.html) [graphics/gfxmacros.h](../Includes_and_Autodocs_3._guide/node0660.html)

