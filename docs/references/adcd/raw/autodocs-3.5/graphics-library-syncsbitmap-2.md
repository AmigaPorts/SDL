# graphics.library/SyncSBitMap



   NAME
```c
       SyncSBitMap --	Syncronize Super [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) with whatever is
```
			in the standard [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) bounds.

   SYNOPSIS

```c
       SyncSBitMap( layer )
                      a0
```
	void SyncSBitMap( struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) * );

   FUNCTION
```c
       Copy all bits from ClipRects in [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) into Super [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45)
```
	[BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45).  This is used for those functions that do not
	want to deal with the [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) structures but do want
	to be able to work with a SuperBitMap [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26).

   INPUTS
	layer - pointer to a [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) that has a SuperBitMap
		The [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) should already be locked by the caller.

   RESULT
	After calling this function, the programmer can manipulate
	the bits in the superbitmap associated with the layer.
	Afterwards, the programmer should call [CopySBitMap](../Includes_and_Autodocs_3._guide/node02C8.html) to
	copy the bits back into the onscreen layer.

   BUGS

   SEE ALSO
	[CopySBitMap()](../Includes_and_Autodocs_3._guide/node02C8.html) [graphics/clip.h](../Includes_and_Autodocs_3._guide/node05EA.html)

