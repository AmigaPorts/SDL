---
title: icon.library/GetIconRectangleA
manual: autodocs-3.5
chapter: autodocs-3.5
section: icon-library-geticonrectanglea
functions: []
libraries: []
---

# icon.library/GetIconRectangleA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GetIconRectangleA -- Query the size of the area an icon renders into (V44)

   SYNOPSIS
	success = GetIconRectangleA(rp,icon,label,rectangle,tags)
	D0                          A0 A1   A2    A3        A4

	[BOOL](autodocs-3.5/include-exec-types-h.md) GetIconRectangleA(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp,struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,
	                       [STRPTR](autodocs-3.5/include-exec-types-h.md) label,struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) *rectangle,
	                       struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *tags);

	success = GetIconRectangle(rp,icon,label,rectangle,...);

	[BOOL](autodocs-3.5/include-exec-types-h.md) GetIconRectangle(struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp,struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon,
	                      [STRPTR](autodocs-3.5/include-exec-types-h.md) label,struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) *rectangle,...);

   FUNCTION
	This function will calculate the size of the area icon rendering
	would affect.

   INPUTS
	rp -- Pointer to the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) to use for calculating the
	    the size of the label with respect to the font and
	    style options currently in use; this parameter may be
	    NULL if the label is NULL, too.
	icon -- Pointer to a struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md).
	label -- Pointer to a NUL-terminated string, or NULL if
	    no label text is to enter the calculation.
	rectangle -- Pointer to a struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) to fill in. The
	    contents will take the size of the icon image, the icon
	    border size and -- if you provide [RastPort](autodocs-3.5/include-graphics-rastport-h.md) and label
	    text -- the icon label into account. Due to how labels
	    are printed, the rectangle->MinX and rectangle->MinY
	    members may be negative.
	tags -- Additional drawing options to be taken into account.

   TAGS
	ICONDRAWA_DrawInfo (struct [DrawInfo](autodocs-3.5/include-intuition-screens-h.md) *) -- Drawing information data
	    associated with the [RastPort](autodocs-3.5/include-graphics-rastport-h.md) parameter passed in.

	    This tag defaults to NULL.

	ICONDRAWA_Borderless (BOOL) -- When calculating the size of
	    the rectangle, this tag allows you to leave the icon
	    border size out of the equation.

	    This tag defaults to FALSE.

   RESULTS
	success -- TRUE if the parameters were well-formed and
	    the output data fits into the [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) data
	    structure (which may not be the case if the image
	    is too large for a signed 16 bit integer to hold).

   EXAMPLE
	/* Find out how large an icon is. */
	struct [DiskObject](autodocs-3.5/include-workbench-workbench-h.md) *icon;
	struct [Rectangle](autodocs-3.5/include-graphics-gfx-h.md) rect;

	if(GetIconRectangleA(NULL,NULL,icon,NULL,&rect,NULL))
	{
	    [LONG](autodocs-3.5/include-exec-types-h.md) width,height;

	    width = rect.MaxX - rect.MinX + 1;
	    height = rect.MaxY - rect.MinY + 1;

	    Printf("icon is %ld×%ld pixels in size.n",
	        width,height);
	}

	/* Find out which area the icon rendering would
	 * cover if a label would be printed below it.
	 */
	struct [RastPort](autodocs-3.5/include-graphics-rastport-h.md) *rp;

	if(GetIconRectangle(rp,NULL,icon,"a rather long label text",&rect,TAG_DONE))
	{
	    Printf("icon plus label would cover the area %ld,%ld×%ld,%ldn",
	        rect.MinX,rect.MinY,rect.MaxX,rect.MaxY);
	}

   NOTES
	This function can be used to optimize on-screen rendering by
	precalculating the area rendering would cover. To make sure that
	the precalculated area size matches the one covered by the actual
	drawing operation, the RastPorts you use for measuring and for
	drawing should share the same font and the same text styles.

	The image size calculated by this function can be
	slightly larger than the data you will find in the icon's
	do_Gadget.GadgetRender [Image](autodocs-3.5/include-intuition-intuition-h.md) structure since the icon border
	will be taken into account. This happens regardless of whether
	icon.library was switched into frameless icon rendering mode
	or whether the icon is frameless. To obtain the size of the
	icon without taking the border into account, use the
	ICONDRAWA_Borderless tag.

   SEE ALSO
	[workbench/icon.h](autodocs-3.5/include-workbench-icon-h.md)
	[workbench/workbench.h](autodocs-3.5/include-workbench-workbench-h.md)
	icon.library/DrawIconState
	[icon.library/IconControlA](autodocs-3.5/icon-library-iconcontrola.md)

