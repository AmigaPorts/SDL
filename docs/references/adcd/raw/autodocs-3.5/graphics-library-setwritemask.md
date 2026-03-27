# graphics.library/SetWriteMask



   NAME


```c
       SetWriteMask -- Set the pixel write mask value for a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) (V39).
```
   SYNOPSIS
```c
       success=SetWriteMask ( rp, msk )
```
	  d0	               a0   d0

	ULONG SetWriteMask(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *,ULONG)

   FUNCTION
	Set the current value of the bit write mask for the rastport.
	bits of the pixel with zeros in their mask will not be modified by
	subsequent drawing operations.

   INPUTS
```c
       rp  =  a pointer to a valid [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) structure.
```
	msk =  a longword mask value.

	Graphics devices which do not support per-bit masking will
	return 0 (failure).
   BUGS

   NOTES

   SEE ALSO
	[graphics/gfxmacros.h](../Includes_and_Autodocs_3._guide/node0660.html)

