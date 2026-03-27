# graphics.library/GetOPen



   NAME


```c
       GetOPen -- Get the O Pen value for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) (V39).
```
   SYNOPSIS
```c
       pen = GetOPen  ( rp )
```
	d0		 a0

	ULONG GetOPen(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *)

   FUNCTION
	Return the current value of the O pen for the rastport. This function
	should be used instead of peeking the structure directly, because future
	graphics devices may store it differently, for instance, using more bits.

   INPUTS

```c
       rp  =  a pointer to a valid [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
```
   BUGS

   NOTES

   SEE ALSO
	[SetOutlinePen()](../Includes_and_Autodocs_3._guide/node0326.html) [graphics/gfx.h](../Includes_and_Autodocs_3._guide/node05DC.html)

