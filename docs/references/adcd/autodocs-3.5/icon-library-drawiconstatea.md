---
title: icon.library/DrawIconStateA
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-drawiconstatea
functions: []
libraries: []
---

# icon.library/DrawIconStateA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	DrawIconStateA -- [Draw](autodocs-3.5/graphics-library-draw-2.md) an icon as if it were an image (V44)

   SYNOPSIS
	DrawIconStateA(rp,icon,label,leftEdge,topEdge,state,tags)
	               A0 A1   A2    D0       D1      D2    A3

	VOID DrawIconStateA(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp,struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,
	                    [STRPTR](autodocs-3.5/include-exec-types-h.md) label,[LONG](autodocs-3.5/include-exec-types-h.md) leftEdge,[LONG](autodocs-3.5/include-exec-types-h.md) topEdge,
	                    ULONG state,struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	DrawIconState(rp,icon,label,leftEdge,topEdge,state,...);

	VOID DrawIconState(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp,struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,
	                   [STRPTR](autodocs-3.5/include-exec-types-h.md) label,[LONG](autodocs-3.5/include-exec-types-h.md) leftEdge,[LONG](autodocs-3.5/include-exec-types-h.md) topEdge,
	                   ULONG state,...);

   FUNCTION
	This function will draw an icon as if it were an image; if
	a label is provided, it will be printed below it.

   INPUTS
	rp -- Pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to draw into; the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) clipping
	    rules, font, style, text colours and drawing mode will be used.
	icon -- Pointer to a struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md).
	label -- Pointer to a NUL-terminated string, or NULL if
	    no label text is to be printed.
	leftEdge, topEdge -- Coordinates at which the icon image
	    should be drawn, including its border; please note that the
	    icon label may extend in whole or in part beyond the
	    leftEdge you have specified.
	state -- Select how and which icon image should be drawn;
	    see [intuition/imageclass.h](autodocs-3.5/include-intuition-imageclass-h.md) for supported states.
	tags -- Additional drawing options

   TAGS
	ICONDRAWA_DrawInfo (struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) *) -- Drawing information data
	    associated with the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to draw into. The [DrawInfo](autodocs-3.5/include-intuition-screens-h.md)
	    contents affect the colours of the border drawn around the
	    icon image and also carry display aspect ratio information.
	    If this tag is NULL, the default rendering pens for the
	    screen selected via IconControl(...,ICONA_SetGlobalScreen,...)
	    will be used instead.

	    This tag defaults to NULL.

	ICONDRAWA_Frameless (BOOL) -- [Draw](autodocs-3.5/graphics-library-draw-2.md) the icon without the
	    surrounding border.

	    This tag defaults to FALSE.

	ICONDRAWA_Borderless (BOOL) -- [Draw](autodocs-3.5/graphics-library-draw-2.md) the icon without the
	    surrounding border and frame.

	    This tag defaults to FALSE.

	ICONDRAWA_EraseBackground (BOOL) -- When drawing a frameless
	    icon, erase the icon background before drawing the icon.

	    This tag defaults to TRUE.

   EXAMPLE
	/* [Draw](autodocs-3.5/graphics-library-draw-2.md) the icon in its normal state, without
	 * a label but including a frame.
	 */
	struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp;
	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon;

	DrawIconStateA(rp,icon,NULL,0,0,IDS_NORMAL,NULL);

	/* The same again, but without a frame. */
	DrawIconState(rp,icon,NULL,0,0,IDS_NORMAL,
	    ICONDRAWA_Frameless,TRUE,
	TAG_DONE);

	/* [Draw](autodocs-3.5/graphics-library-draw-2.md) the icon in selected state with a border; the
	 * frame colours come from the given [DrawInfo](autodocs-3.5/include-intuition-screens-h.md).
	 */
	struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) *drawInfo;

	DrawIconState(rp,icon,NULL,0,0,IDS_SELECTED,
	    ICONDRAWA_DrawInfo,drawInfo,
	TAG_DONE);

   SEE ALSO
	[workbench/icon.h](autodocs-3.5/include-workbench-icon-h.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)
	[intuition/imageclass.h](autodocs-3.5/include-intuition-imageclass-h.md)
	[intuition/screens.h](autodocs-3.5/include-intuition-screens-h.md)
	[intuition.library/DrawImageState](autodocs-3.5/intuition-library-drawimagestate-2.md)
	[icon.library/GetIconRectangleA](autodocs-3.5/icon-library-geticonrectanglea.md)
	[icon.library/IconControlA](autodocs-3.5/icon-library-iconcontrola.md)

