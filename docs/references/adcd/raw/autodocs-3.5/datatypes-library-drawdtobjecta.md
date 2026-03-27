# datatypes.library/DrawDTObjectA



    NAME
	DrawDTObjectA - [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) a DataTypes object.                (V44)

    SYNOPSIS
	retval = DrawDTObjectA (rp, o, x, y, w, h, th, tv, attrs);
	d0			a0  a1 d0 d1 d2 d3 d4  d5  a2

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) DrawDTObjectA (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *rp, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) x, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) y,
			    [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) w, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) h, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) th, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) tv,
			    struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *);

	retval = DrawDTObject (rp, o, x, y, w, h, th, tv, tag1, ...);

	[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) DrawDTObjectA (struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *rp, [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) x, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) y,
			    [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) w, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) h, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) th, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) tv, [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

    FUNCTION
	This function is used to draw a DataTypes object into a [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

	This function can be used for strip printing the object or
	embedding it within a document.

	You must successfully call [ObtainDTDrawInfoA()](../Includes_and_Autodocs_3._guide/node0113.html) before using
	this function.

	This function invokes the object's DTM_DRAW method.

	Clipping MUST be turned on within the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).  This means
	that there must be a valid layer structure attached to the
	[RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

    INPUTS
	rp - Pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to draw into.
	o - Pointer to an object returned by [NewDTObjectA()](../Includes_and_Autodocs_3._guide/node0111.html).
	x - Left-most point of area to draw into.
	y - Top-most point of area to draw into.
	w - Width of area to draw into.
	h - Height of area to draw into.
	th - Horizontal top in units.
	tv - Vertical top in units.
	attrs - Additional attributes.

    TAGS
	none defined at this time.

    RETURNS
	TRUE to indicate that it was able to render, FALSE on failure.

    SEE ALSO
	ObtainDTDrawInfo(), [ReleaseDTDrawInfo()](../Includes_and_Autodocs_3._guide/node0117.html)

