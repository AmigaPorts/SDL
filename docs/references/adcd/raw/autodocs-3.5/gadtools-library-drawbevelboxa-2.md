# gadtools.library/DrawBevelBoxA



   NAME
	DrawBevelBoxA -- draw a bevelled box. (V36)
	DrawBevelBox -- varargs stub for DrawBevelBoxA(). (V36)

   SYNOPSIS
	DrawBevelBoxA(rport, left, top, width, height, tagList);
	              A0     D0    D1   D2     D3      A1

	VOID DrawBevelBoxA(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD, WORD, WORD,
	                   struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *taglist);

	DrawBevelBox(rport, left, top, width, height, firsttag, ...);

	VOID DrawBevelBox(struct [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) *, WORD, WORD, WORD, WORD,
	                  [Tag](../Includes_and_Autodocs_3._guide/node064C.html#line29), ...);

   FUNCTION
	This function renders a bevelled box of specified dimensions
	and type into the supplied [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53).

   INPUTS
	rport - [RastPort](../Includes_and_Autodocs_3._guide/node05D7.html#line53) into which the box is to be drawn.
	left - left edge of the box.
	top - top edge of the box.
	width - width of the box.
	height - height of the box.
	tagList - pointer to an array of tags providing extra parameters

   TAGS
	GTBB_Recessed (BOOL) - Set to anything for a recessed-looking box.
			If absent, the box defaults, it would be raised. (V36)

	GTBB_FrameType (ULONG) - Determines what kind of box this function
			renders. BBFT_BUTTON generates a box like what is
			used around GadTools BUTTON_KIND gadgets. BBFT_RIDGE
			generates a box like what is used around GadTools
			STRING_KIND gadgets. Finally, BBFT_ICONDROPBOX
			generates a box suitable for a standard icon drop
			box imagery. (defaults to BBFT_BUTTON). (V39)

	GT_VisualInfo (APTR) - You MUST supply the value you obtained
			from an earlier call to [GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html) with this
			tag. (V36)

   NOTES
	DrawBevelBox() is a rendering operation, not a gadget. That
	means you must refresh it at the appropriate time, like any
	other rendering operation.

   SEE ALSO
	[GetVisualInfoA()](../Includes_and_Autodocs_3._guide/node027B.html), [<libraries/gadtools.h>](../Includes_and_Autodocs_3._guide/node062A.html)

