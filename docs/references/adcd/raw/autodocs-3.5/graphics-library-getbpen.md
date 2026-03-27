# graphics.library/GetBPen



   NAME


```c
       GetBPen -- Get the B Pen value for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) (V39).
```
   SYNOPSIS
```c
       pen = GetBPen  ( rp )
```
	d0	   	 a0

	ULONG GetBPen(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *)

   FUNCTION
	Return the current value of the B pen for the rastport. This function
	should be used instead of peeking the structure directly, because future
	graphics devices may store it differently, using more bits.

   INPUTS

```c
       rp  =  a pointer to a valid [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
```
   BUGS

   NOTES

   SEE ALSO
	[SetBPen()](../Includes_and_Autodocs_3._guide/node031F.html) [graphics/gfx.h](../Includes_and_Autodocs_3._guide/node05DC.html)

