# graphics.library/GetDrMd



   NAME


```c
       GetDrMd -- Get the draw mode value for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) (V39).
```
   SYNOPSIS
```c
       mode = GetDrMd  ( rp )
```
	d0                a0

	ULONG GetDrMd(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *)

   FUNCTION
	Return the current value of the draw mode for the rastport. This function
	should be used instead of peeking the structure directly, because future
	graphics devices may store it differently.

   INPUTS

```c
       rp  =  a pointer to a valid [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
```
   BUGS

   NOTES

   SEE ALSO
	[SetDrMd()](../Includes_and_Autodocs_3._guide/node0322.html) [graphics/gfx.h](../Includes_and_Autodocs_3._guide/node05DC.html)

