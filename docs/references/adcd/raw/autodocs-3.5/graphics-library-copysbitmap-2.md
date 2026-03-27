# graphics.library/CopySBitMap



   NAME
```c
       CopySBitMap --	Syncronize [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) window with contents of
```
						Super [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45)

   SYNOPSIS

```c
       CopySBitMap( layer )
                     a0
```
	void CopySBitMap(struct [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) *);

   FUNCTION
	This is the inverse of [SyncSBitMap](../Includes_and_Autodocs_3._guide/node0331.html).
```c
       Copy all bits from SuperBitMap to [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) bounds.
```
	This is used for those functions that do not
	want to deal with the [ClipRect](../Includes_and_Autodocs_3._guide/node05EA.html#line56) structures but do want
	to be able to work with a SuperBitMap [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26).

   INPUTS
	layer - pointer to a SuperBitMap [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26)
	    The [Layer](../Includes_and_Autodocs_3._guide/node05EA.html#line26) must already be locked by the caller.

   BUGS

   SEE ALSO
	[LockLayerRom()](../Includes_and_Autodocs_3._guide/node02FE.html) [SyncSBitMap()](../Includes_and_Autodocs_3._guide/node0331.html)

