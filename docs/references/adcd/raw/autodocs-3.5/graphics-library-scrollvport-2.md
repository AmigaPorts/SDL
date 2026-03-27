# graphics.library/ScrollVPort



   NAME
	ScrollVPort -- Reinterpret RasInfo information in [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) to reflect
			the current Offset values.

   SYNOPSIS
	ScrollVPort( vp )
		     a0

	void ScrollVPort(struct [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) *vp);

   FUNCTION
	After the programmer has adjusted the Offset values in
	the RasInfo structures of [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46), change the
	the copper lists to reflect the the Scroll positions.
	Changing the [BitMap](../Includes_and_Autodocs_3._guide/node05DC.html#line45) ptr in RasInfo and not changing the
	the Offsets will effect a double buffering affect.

   INPUTS
```c
       vp - pointer to a [ViewPort](../Includes_and_Autodocs_3._guide/node05ED.html#line46) structure
```
	     that is currently be displayed.
   RESULTS
	modifies hardware and intermediate copperlists to reflect
	new RasInfo

   BUGS
```c
       pokes not fast enough to avoid some visible hashing of display (V37)
```
	This function was re-written in V39 and is ~10 times faster than
	before.

   SEE ALSO
	[MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html) [MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html) [LoadView()](../Includes_and_Autodocs_3._guide/node02FD.html)  [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

