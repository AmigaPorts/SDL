---
title: gadtools.library/DrawBevelBoxA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-drawbevelboxa-2
functions: [DrawBevelBoxA, GetVisualInfoA]
libraries: [gadtools.library]
---

# gadtools.library/DrawBevelBoxA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DrawBevelBoxA -- draw a bevelled box. (V36)
	DrawBevelBox -- varargs stub for DrawBevelBoxA(). (V36)

   SYNOPSIS
	DrawBevelBoxA(rport, left, top, width, height, tagList);
	              A0     D0    D1   D2     D3      A1

	VOID DrawBevelBoxA(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD, WORD, WORD,
	                   struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *taglist);

	DrawBevelBox(rport, left, top, width, height, firsttag, ...);

	VOID DrawBevelBox(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *, WORD, WORD, WORD, WORD,
	                  [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	This function renders a bevelled box of specified dimensions
	and type into the supplied [RastPort](autodocs-3.5/include-graphics-rastport-h.md).

   INPUTS
	rport - [RastPort](autodocs-3.5/include-graphics-rastport-h.md) into which the box is to be drawn.
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
			from an earlier call to [GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md) with this
			tag. (V36)

   NOTES
	DrawBevelBox() is a rendering operation, not a gadget. That
	means you must refresh it at the appropriate time, like any
	other rendering operation.

   SEE ALSO
	[GetVisualInfoA()](autodocs-3.5/gadtools-library-getvisualinfoa-2.md), [<libraries/gadtools.h>](autodocs-3.5/include-libraries-gadtools-h.md)

---

## See Also

- [DrawBevelBoxA — gadtools.library](../autodocs/gadtools.library.md#drawbevelboxa)
- [GetVisualInfoA — gadtools.library](../autodocs/gadtools.library.md#getvisualinfoa)
