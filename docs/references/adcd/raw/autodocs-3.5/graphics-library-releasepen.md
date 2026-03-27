# graphics.library/ReleasePen



   NAME
	ReleasePen -- Release an allocated palette entry to the free pool. (V39)


   SYNOPSIS
	ReleasePen( cm, n)
	            a0 d0

	void ReleasePen( Struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, ULONG);

   FUNCTION
	Return the palette entry for use by other applications.
	If the reference count for this palette entry goes to zero,
	then it may be reset to another RGB value.

   INPUTS

```c
       cm  =  A pointer to a color map created by [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html).
```
	n   =  A palette index obtained via any of the palette allocation
	       functions. Passing a -1 will result in this call doing
	       nothing.

   BUGS

   NOTES
	This function works for both shared and exclusive palette entries.

   SEE ALSO
	[GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [ObtainPen()](../Includes_and_Autodocs_3._guide/node0307.html) [ObtainBestPenA()](../Includes_and_Autodocs_3._guide/node0306.html)

