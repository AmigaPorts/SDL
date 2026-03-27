---
title: gadtools.library/GT_GetGadgetAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-gt-getgadgetattrsa
functions: [GT_GetGadgetAttrsA]
libraries: [gadtools.library]
---

# gadtools.library/GT_GetGadgetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	GT_GetGadgetAttrsA -- request the attributes of a GadTools gadget. (V39)
	GT_GetGadgetAttrs -- varargs stub for GT_GetGadgetAttrsA(). (V39)

   SYNOPSIS
	numProcessed = GT_GetGadgetAttrsA(gad, win, req, taglist)
	                                  A0   A1   A2   A3

	[LONG](autodocs-3.5/include-exec-types-h.md) GT_GetGadgetAttrsA(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
	                        struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	numProcessed = GT_GetGadgetAttrs(gad, win, req, firsttag, ...)

	[LONG](autodocs-3.5/include-exec-types-h.md) GT_GetGadgetAttrs(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,

```c
                              struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);
```
   FUNCTION
	Retrieve the attributes of the specified gadget, according to the
	attributes chosen in the tag list.  For each entry in the tag list,
	ti_Tag identifies the attribute, and ti_Data is a pointer to
	the long variable where you wish the result to be stored.

   INPUTS
	gad - pointer to the gadget in question. May be NULL, in which case
	      this function returns 0
	win - pointer to the window containing the gadget.
	req - reserved for future use, should always be NULL
	taglist - pointer to [TagItem](autodocs-3.5/include-utility-tagitem-h.md) list.

   TAGS
	BUTTON_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)

	CHECKBOX_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTCB_Checked (BOOL) - TRUE if this gadget is currently checked,
	    FALSE otherwise. (V39)

	CYCLE_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTCY_Active (UWORD) - The ordinal number (counting from zero) of
	    the active choice of a cycle gadget. (V39)
	GTCY_Labels (STRPTR *) - The NULL-terminated array of strings
	    that are the choices offered by the cycle gadget. (V39)

	INTEGER_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTIN_Number (ULONG) - The contents of the integer gadget. (V39)

	LISTVIEW_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTLV_Top (WORD) - Ordinal number of the top item visible
	    in the listview. (V39)
	GTLV_Labels (struct [List](autodocs-3.5/include-exec-lists-h.md) *) - The list of nodes whose ln_Name fields
	    are displayed in the listview. (V39)
	GTLV_Selected (UWORD) - Ordinal number of currently selected
	    item. Returns ~0 if no item is selected. (V39)

	MX_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTMX_Active (UWORD) - The ordinal number (counting from zero) of
	    the active choice of an mx gadget. (V39)

	NUMBER_KIND:
	GTNM_Number - The signed long integer that is displayed in
	    the read-only number. (V39)

	PALETTE_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTPA_Color (UBYTE) - The selected color of the palette. (V39)
	GTPA_ColorOffset (UBYTE) - First color used in palette. (V39)
	GTPA_ColorTable (UBYTE *) - Pointer to a table of pen numbers
	    indicating  which colors should be used and edited by the palette
	    gadget. May be NULL, which causes a 1-to-1 mapping of pen numbers.
	    (V39)

	SCROLLER_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTSC_Top (WORD) - Top visible in scroller. (V39)
	GTSC_Total (WORD) - Total in scroller area. (V39)
	GTSC_Visible (WORD) - Number visible in scroller. (V39)

	SLIDER_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTSL_Min (WORD) - Minimum level for slider. (V39)
	GTSL_Max (WORD) - Maximum level for slider. (V39)
	GTSL_Level (WORD) - Current level of slider. (V39)

	STRING_KIND:
	GA_Disabled (BOOL) - TRUE if this gadget is disabled,
	    FALSE otherwise. (V39)
	GTST_String (STRPTR) - Returns a pointer to the string gadget's
	    buffer. (V39)

	TEXT_KIND:
	GTTX_Text - Pointer to the string to be displayed in the
	    read-only text-display gadget. (V39)

   RESULT
	numProcessed - the number of attributes successfully filled in.

   EXAMPLE
		long top = 0;
		long selected = 0;
		long result;
		result = GT_GetGadgetAttrs( listview_gad, win, NULL,
			GTLV_Top, &top,
			GTLV_Selected, &selected,
			TAG_DONE );
		if ( result != 2 )
		{
			printf( "Something's wrong!" );
		}

   WARNING
	The pointers you provide within the tag list to store the return
	values MUST POINT TO LONGWORDS. That is, even if the type of a
	return value is defined as (UWORD *), you must pass a pointer to
	a longword of memory.

   SEE ALSO
	GT_SetGadgetAttrs()

---

## See Also

- [GT_GetGadgetAttrsA — gadtools.library](../autodocs/gadtools.library.md#gt_getgadgetattrsa)
