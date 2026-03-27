# icon.library/DrawIconStateA



   NAME
	DrawIconStateA -- [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) an icon as if it were an image (V44)

   SYNOPSIS
	DrawIconStateA(rp,icon,label,leftEdge,topEdge,state,tags)
	               A0 A1   A2    D0       D1      D2    A3

	VOID DrawIconStateA(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *rp,struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon,
	                    [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) label,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) leftEdge,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) topEdge,
	                    ULONG state,struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *tags);

	DrawIconState(rp,icon,label,leftEdge,topEdge,state,...);

	VOID DrawIconState(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *rp,struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon,
	                   [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) label,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) leftEdge,[LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) topEdge,
	                   ULONG state,...);

   FUNCTION
	This function will draw an icon as if it were an image; if
	a label is provided, it will be printed below it.

   INPUTS
	rp -- Pointer to the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to draw into; the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) clipping
	    rules, font, style, text colours and drawing mode will be used.
	icon -- Pointer to a struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64).
	label -- Pointer to a NUL-terminated string, or NULL if
	    no label text is to be printed.
	leftEdge, topEdge -- Coordinates at which the icon image
	    should be drawn, including its border; please note that the
	    icon label may extend in whole or in part beyond the
	    leftEdge you have specified.
	state -- Select how and which icon image should be drawn;
	    see [intuition/imageclass.h](../Includes_and_Autodocs_3._guide/node061B.html) for supported states.
	tags -- Additional drawing options

   TAGS
	ICONDRAWA_DrawInfo (struct [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) *) -- Drawing information data
	    associated with the [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) to draw into. The [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65)
	    contents affect the colours of the border drawn around the
	    icon image and also carry display aspect ratio information.
	    If this tag is NULL, the default rendering pens for the
	    screen selected via IconControl(...,ICONA_SetGlobalScreen,...)
	    will be used instead.

	    This tag defaults to NULL.

	ICONDRAWA_Frameless (BOOL) -- [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) the icon without the
	    surrounding border.

	    This tag defaults to FALSE.

	ICONDRAWA_Borderless (BOOL) -- [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) the icon without the
	    surrounding border and frame.

	    This tag defaults to FALSE.

	ICONDRAWA_EraseBackground (BOOL) -- When drawing a frameless
	    icon, erase the icon background before drawing the icon.

	    This tag defaults to TRUE.

   EXAMPLE
	/* [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) the icon in its normal state, without
	 * a label but including a frame.
	 */
	struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *rp;
	struct [DiskObject](../Includes_and_Autodocs_3._guide/node05D6.html#line64) *icon;

	DrawIconStateA(rp,icon,NULL,0,0,IDS_NORMAL,NULL);

	/* The same again, but without a frame. */
	DrawIconState(rp,icon,NULL,0,0,IDS_NORMAL,
	    ICONDRAWA_Frameless,TRUE,
	TAG_DONE);

	/* [Draw](../Includes_and_Autodocs_3._guide/node02CD.html) the icon in selected state with a border; the
	 * frame colours come from the given [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65).
	 */
	struct [DrawInfo](../Includes_and_Autodocs_3._guide/node0602.html#line65) *drawInfo;

	DrawIconState(rp,icon,NULL,0,0,IDS_SELECTED,
	    ICONDRAWA_DrawInfo,drawInfo,
	TAG_DONE);

   SEE ALSO
	[workbench/icon.h](../Includes_and_Autodocs_3._guide/node0618.html)
	[workbench/workbench.h](../Includes_and_Autodocs_3._guide/node05D6.html)
	[intuition/imageclass.h](../Includes_and_Autodocs_3._guide/node061B.html)
	[intuition/screens.h](../Includes_and_Autodocs_3._guide/node0602.html)
	[intuition.library/DrawImageState](../Includes_and_Autodocs_3._guide/node03AA.html)
	[icon.library/GetIconRectangleA](../Includes_and_Autodocs_3._guide/node034F.html)
	[icon.library/IconControlA](../Includes_and_Autodocs_3._guide/node0351.html)

