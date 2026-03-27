---
title: gadtools.library/GT_SetGadgetAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-setgadgetattrsa-2
functions: [GT_BeginRefresh, GT_EndRefresh, GT_SetGadgetAttrsA, RawDoFmt]
libraries: [exec.library, gadtools.library]
---

# gadtools.library/GT_SetGadgetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_SetGadgetAttrsA -- change the attributes of a GadTools gadget. (V36)
	GT_SetGadgetAttrs -- varargs stub for GT_SetGadgetAttrsA(). (V36)

   SYNOPSIS
	GT_SetGadgetAttrsA(gad, win, req, tagList)
	                   A0   A1   A2   A3

	VOID GT_SetGadgetAttrsA(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
	                        struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	GT_SetGadgetAttrs(gad, win, req, firsttag, ...)

	VOID GT_SetGadgetAttrs(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
	                       struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	Change the attributes of the specified gadget, according to the
	attributes chosen in the tag list. If an attribute is not provided
	in the tag list, its value remains unchanged.

   INPUTS
	gad - pointer to the gadget in question. Starting with V39, this
	      value may be NULL in which case this function does nothing
	win - pointer to the window containing the gadget. Starting with V39,
	      this value may be NULL in which case the internal attributes of
	      the gadgets are altered but no rendering occurs.
	req - reserved for future use, should always be NULL
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL.

   TAGS
	BUTTON_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise.
	    (V36)

	CHECKBOX_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise.
	    (V36)
	GTCB_Checked (BOOL) - State of checkbox. (V36)

	CYCLE_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V37)
	GTCY_Active (UWORD) - The ordinal number (counting from zero) of
	    the active choice of a cycle gadget. (V36)
	GTCY_Labels (STRPTR *) - Pointer to NULL-terminated array of strings
	    that are the choices offered by the cycle gadget. (V37)

	INTEGER_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V36)
	GTIN_Number (ULONG) - New value of the integer gadget (V36)

	LISTVIEW_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V39)
	GTLV_Top (WORD) - Top item visible in the listview.  This value
	    will be made reasonable if out-of-range. (V36)
	GTLV_MakeVisible (WORD) - Number of an item that should be forced
	    within the visible area of the listview by doing minimal scrolling.
	    This tag overrides GTLV_Top. (V39)
	GTLV_Labels (struct [List](autodocs-3.5/include-exec-lists-h.md) *) - [List](autodocs-3.5/include-exec-lists-h.md) of nodes whose ln_Name fields
	    are to be displayed in the listview.  Use a value of ~0 to
	    "detach" your [List](autodocs-3.5/include-exec-lists-h.md) from the display.  You must detach your list
	    before modifying the [List](autodocs-3.5/include-exec-lists-h.md) structure, since GadTools reserves
	    the right to traverse it on another task's schedule.  When you
	    are done, attach the list by using the tag pair
	    {GTLV_Labels, list}. (V36)
	GTLV_Selected (UWORD) - Ordinal number of currently selected
	    item. Starting with V39, you can provide ~0 to cause the currently
	    selected item to be deselected. (V36)

	MX_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V39)
	GTMX_Active (UWORD) - The ordinal number (counting from zero) of
	    the active choice of an mx gadget. (V36)

	NUMBER_KIND:
	GTNM_Number (LONG) - A signed long integer to be displayed in
	    the number gadget. (V36)
	GTNM_FrontPen (UBYTE) - The pen to use when rendering the number. (V39)
	GTNM_BackPen (UBYTE) - The pen to use when rendering the background
	    of the number. (V39)
	GTNM_Justification (UBYTE) - Determines how the number is rendered
	    within the gadget box. GTJ_LEFT will make the rendering be
	    flush with the left side of the gadget, GTJ_RIGHT will make it
	    flush with the right side, and GTJ_CENTER will center the number
	    within the gadget box. (V39)
	GTNM_Format (STRPTR) - C-Style formatting string to apply on the number
	    before display. Be sure to use the 'l' (long) modifier. This string
	    is processed using [exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), so refer to that
	    function for details. (V39)

	PALETTE_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V36)
	GTPA_Color (UBYTE) - Selected color of the palette. This
	    number is a pen number, and not the ordinal color number within
	    the palette gadget itself. (V36)
	GTPA_ColorOffset (UBYTE) - First color to use in palette (V39)
	GTPA_ColorTable (UBYTE *) - Pointer to a table of pen numbers
	    indicating  which colors should be used and edited by the palette
	    gadget. This array must contain as many entries as there are
	    colors displayed in the palette gadget. The array provided with
	    this tag must remain valid for the life of the gadget or until a
	    new table is provided. A NULL table pointer causes a 1-to-1
	    mapping of pen numbers. (V39)

	SCROLLER_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V36)
	GTSC_Top (WORD) - Top visible in scroller. (V36)
	GTSC_Total (WORD) - Total in scroller area. (V36)
	GTSC_Visible (WORD) - Number visible in scroller. (V36)

	SLIDER_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V36)
	GTSL_Min (WORD) - Minimum level for slider. (V36)
	GTSL_Max (WORD) - Maximum level for slider. (V36)
	GTSL_Level (WORD) - Current level of slider. (V36)
	GTSL_LevelFormat (STRPTR) - C-Style formatting string for slider
	    level.  Be sure to use the 'l' (long) modifier.  This string
	    is processed using [exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), so refer to that
	    function for details. (V39)
	GTSL_DispFunc ( [LONG](autodocs-3.5/include-exec-types-h.md) (*function)(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, WORD) ) - Function
	    to calculate level to be displayed.  A number-of-colors slider
	    might want to set the slider up to think depth, and have a
	    (1 << n) function here.  Your function must
	    take a pointer to gadget as the first parameter, the level
	    (a WORD) as the second, and return the result as a [LONG](autodocs-3.5/include-exec-types-h.md). (V39)
	GTSL_Justification (UBYTE) - Determines how the level display is to
	    be justified within its alotted space. Choose one of GTJ_LEFT,
	    GTJ_RIGHT, or GTJ_CENTER. (V39)

	STRING_KIND:
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (V36)
	GTST_String (STRPTR) - New contents of the string gadget,
	    or NULL to reset the gadget to the empty state. (V36)

	TEXT_KIND:
	GTTX_Text - New NULL terminated string to be displayed in the text
	    gadget. NULL means to clear the gadget. (V36)
	GTTX_FrontPen (UBYTE) - The pen to use when rendering the text. (V39)
	GTTX_BackPen (UBYTE) - The pen to use when rendering the background
	    of the text. (V39)
	GTTX_Justification (UBYTE) - Determines how the text is rendered
	    within the gadget box. GTJ_LEFT will make the rendering be
	    flush with the left side of the gadget, GTJ_RIGHT will make it
	    flush with the right side, and GTJ_CENTER will center the text
	    within the gadget box. (V39)

   NOTES
	This function may not be called inside of a [GT_BeginRefresh()](autodocs-3.5/gadtools-library-gt-beginrefresh-2.md) /
	[GT_EndRefresh()](autodocs-3.5/gadtools-library-gt-endrefresh-2.md) session.  (As always, restrict yourself to simple
	rendering functions).

   SEE ALSO
	GT_GetGadgetAttrs()

---

## See Also

- [GT_BeginRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_beginrefresh)
- [GT_EndRefresh — gadtools.library](../autodocs/gadtools.library.md#gt_endrefresh)
- [GT_SetGadgetAttrsA — gadtools.library](../autodocs/gadtools.library.md#gt_setgadgetattrsa)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
