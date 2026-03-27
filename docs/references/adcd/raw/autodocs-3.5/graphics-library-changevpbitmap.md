# graphics.library/ChangeVPBitMap



   NAME
       ChangeVPBitMap -- change display memory address for multi-buffered
			  animation (V39)

   SYNOPSIS
```c
       ChangeVPBitMap(vp,bm,db)
```
	               a0 a1 a2

	void ChangeVPBitMap(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *, struct [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) *, struct [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278) *);

   FUNCTION
	Changes the area of display memory which will be displayed in a
	viewport. This can be used to implement double (or triple)
	buffering, a method of achieving smooth animation.

   INPUTS
	vp  =  a pointer to a viewport
```c
       bm  = a pointer to a [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) structure. This [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) structure must be
```
	      of the same layout as the one attached to the viewport (same
	      depth, alignment, and BytesPerRow).
	db  =  A pointer to a [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278).

   BUGS

   NOTES
	This will set the vp->RasInfo->BitMap field to the bm pointer which is
	passed.

	When using the synchronization features, you MUST carefully insure that
	all messages have been replied to before calling [FreeDBufInfo](../Includes_and_Autodocs_3._guide/node02DA.html) or
	calling ChangeVPBitMap with the same [DBufInfo](../Includes_and_Autodocs_3._guide/node05ED.html#line278).


   SEE ALSO
	[AllocDBufInfo()](../Includes_and_Autodocs_3._guide/node02A1.html) [AllocBitMap()](../Includes_and_Autodocs_3._guide/node02A0.html)

