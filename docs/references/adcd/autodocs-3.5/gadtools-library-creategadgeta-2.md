---
title: gadtools.library/CreateGadgetA
manual: autodocs-3.5
chapter: autodocs-3.5
section: gadtools-library-creategadgeta-2
functions: [CreateGadgetA, FreeGadgets, RawDoFmt]
libraries: [exec.library, gadtools.library]
---

# gadtools.library/CreateGadgetA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME
	CreateGadgetA -- allocate and initialize a gadtools gadget. (V36)
	CreateGadget -- varargs stub for CreateGadgetA(). (V36)

   SYNOPSIS
	gad = CreateGadgetA(kind, previous, newgad, tagList)
	D0                  D0    A0        A1      A2

	struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *CreateGadgetA(ULONG, struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *,
	                             struct [NewGadget](autodocs-3.5/include-libraries-gadtools-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *);

	gad = CreateGadget(kind, previous, newgad, firsttag, ...)

	struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *CreateGadget(ULONG, struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *,
	                            struct [NewGadget](autodocs-3.5/include-libraries-gadtools-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...);

   FUNCTION
	CreateGadgetA() allocates and initializes a new gadget of the
	specified kind, and attaches it to the previous gadget.  The
	gadget is created based on the supplied kind, [NewGadget](autodocs-3.5/include-libraries-gadtools-h.md) structure,
	and tags.

   INPUTS
	kind - kind of gadget is to be created, one of the XXX_KIND values
	       defined in [<libraries/gadtools.h>](autodocs-3.5/include-libraries-gadtools-h.md)
	previous - pointer to the previous gadget that this new gadget
	           is to be attached to. This function will fail if this value
		   is NULL
	newgad - a filled in [NewGadget](autodocs-3.5/include-libraries-gadtools-h.md) structure describing the desired
	         gadget's size, position, label, etc.
	tagList - pointer to an array of tags providing optional extra
		  parameters, or NULL

   TAGS
	All kinds:
	GT_Underscore - Indicates the symbol that precedes the character in
	    the gadget label to be underscored.  This can be to indicate
	    keyboard equivalents for gadgets (note that GadTools does not
	    process the keys - it just displays the underscore).  For example,
	    to underscore the "M" in "Mode":
		ng.ng_GadgetText = "_Mode:";
		gad = CreateGadget(..._KIND, &ng, prev,
			GT_Underscore, '_',
			...
			);
	    (V37)

	BUTTON_KIND (action buttons):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V36)
	GA_Immediate (BOOL) - Hear IDCMP_GADGETDOWN events from button gadget
	    (defaults to FALSE). (V39)

	CHECKBOX_KIND (on/off items):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE).
	GTCB_Checked (BOOL) - Initial state of checkbox (defaults to FALSE)
	    (V36)
	GTCB_Scaled (BOOL) - If true, then checkbox imagery will be scaled to
	    fit the gadget's width & height.  Otherwise, a fixed size of
	    CHECKBOXWIDTH by CHECKBOXHEIGHT will be used. (defaults to FALSE)
	    (V39)

	CYCLE_KIND (multiple state selections):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V37)
	GTCY_Labels (STRPTR *) - Pointer to NULL-terminated array of strings
	    that are the choices offered by the cycle gadget. This tag is
	    required. (V36)
	GTCY_Active (UWORD) - The ordinal number (counting from zero) of
	    the initially active choice of a cycle gadget (defaults to zero).
	    (V36)

	INTEGER_KIND (numeric entry):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V36)
	GA_Immediate (BOOL) - Hear IDCMP_GADGETDOWN events from integer
	    gadget (defaults to FALSE). (V39)
	GA_TabCycle (BOOL) - Set to TRUE so that pressing <TAB> or <Shift-TAB>
	    will activate the next or previous such gadget. (defaults to TRUE,
	    unlike regular Intuition string gadgets which default to FALSE).
	    (V37)
	GTIN_Number (LONG) - The initial contents of the integer gadget
	    (defaults to 0). (V36)
	GTIN_MaxChars (UWORD) - The maximum number of digits that the
	    integer gadget is to hold (defaults to 10). (V36)
	GTIN_EditHook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - [Hook](autodocs-3.5/include-utility-hooks-h.md) to use as a custom
	    integer gadget edit hook (StringExtend->EditHook) for this gadget.
	    GadTools will allocate the StringExtend->WorkBuffer for you.
	    (defaults to NULL). (V37)
	STRINGA_ExitHelp (BOOL) - Set to TRUE to have the help-key cause an
	    exit from the integer gadget.  You will then receive an
	    IDCMP_GADGETUP event with Code = 0x5F (rawkey for help).
	    (defaults to FALSE) (V37)
	STRINGA_Justification - Controls the justification of the contents of
	    an integer gadget.  Choose one of STRINGLEFT, STRINGRIGHT, or
	    STRINGCENTER (defaults to STRINGLEFT). (V37)
	STRINGA_ReplaceMode (BOOL) - If TRUE, this integer gadget is in
	    replace-mode (defaults to FALSE (insert-mode)). (V37)

	LISTVIEW_KIND (scrolling list):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V39)
	GTLV_Top (WORD) - Top item visible in the listview.  This value
	    will be made reasonable if out-of-range (defaults to 0). (V36)
	GTLV_MakeVisible (WORD) - Number of an item that should be forced
	    within the visible area of the listview by doing minimal scrolling.
	    This tag overrides GTLV_Top. (V39)
	GTLV_Labels (struct [List](autodocs-3.5/include-exec-lists-h.md) *) - [List](autodocs-3.5/include-exec-lists-h.md) of nodes whose ln_Name fields
	    are to be displayed in the listview. (V36)
	GTLV_ReadOnly (BOOL) - If TRUE, then listview is read-only
	    (defaults to FALSE). (V36)
	GTLV_ScrollWidth (UWORD) - Width of scroll bar for listview.
	    Must be greater than zero (defaults to 16). (V36)
	GTLV_ShowSelected (struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *) - NULL to have the currently
	    selected item displayed beneath the listview under V37 or with
	    a highlight bar in V39. If not NULL, this is a pointer to
	    an already-created GadTools STRING_KIND gadget to have an
	    editable display of the currently selected item. If the tag is
	    not present, the currently selected item will not be displayed.
	    (V36)
	GTLV_Selected (UWORD) - Ordinal number of currently selected
	    item, or ~0 to have no current selection (defaults to ~0). (V36)
	LAYOUTA_Spacing (UWORD) - Extra space to place between lines of
	    listview (defaults to 0). (V36)
	GTLV_ItemHeight (UWORD) - The exact height of an item. This is
	    normally useful for listviews that use the GTLV_CallBack
	    rendering hook (defaults to ng->ng_TextAttr->ta_YSize). (V39)
	GTLV_CallBack (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - Callback hook for various listview
	    operations. As of V39, the only callback supported is for custom
	    rendering of individual items in the listview. The call back hook
	    is called with:
		A0 - struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *
		A1 - struct [LVDrawMsg](autodocs-3.5/include-libraries-gadtools-h.md) *
		A2 - struct [Node](autodocs-3.5/include-exec-nodes-h.md) *
	    The callback hook *must* check the lvdm_MethodID field of the
	    message and only do processing if it equals LV_DRAW. If any
	    other value is passed, the callback hook must return LVCB_UNKNOWN
	GTLV_MaxPen (UWORD) - The maximum pen number used by rendering
	    in a custom rendering callback hook. This is used to optimize
	    the rendering and scrolling of the listview display (default is
	    the maximum pen number used by all of TEXTPEN, BACKGROUNDPEN,
	    FILLPEN, TEXTFILLPEN, and BLOCKPEN. (V39)

	MX_KIND (mutually exclusive, radio buttons):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V39)
	GTMX_Labels (STRPTR *) - Pointer to a NULL-terminated array of
	    strings which are to be the labels beside each choice in a
	    set of mutually exclusive gadgets. This tag is required. (V36)
	GTMX_Active (UWORD) - The ordinal number (counting from zero) of
	    the initially active choice of an mx gadget (defaults to 0). (V36)
	GTMX_Spacing (UWORD) - The amount of space between each choice
	    of a set of mutually exclusive gadgets.  This amount is added
	    to the font height to produce the vertical shift between
	    choices (defaults to 1). (V36)
	GTMX_Scaled (BOOL) - If true, then mx gadget imagery will be scaled
	    to fit the gadget's width & height.  Otherwise, a fixed size of
	    MXWIDTH by MXHEIGHT will be used. When setting this tag to TRUE,
	    you should typically set the height of the gadget to be
	    (ng.ng_TextAttr->ta_YSize + 1). (defaults to FALSE.) (V39)
	GTMX_TitlePlace - One of PLACETEXT_LEFT, PLACETEXT_RIGHT,
	    PLACETEXT_ABOVE, or PLACETEXT_BELOW, indicating where the title
	    of the gadget is to be displayed. Without this tag, the
	    NewGadget.ng_GadgetText field is ignored for MX_KIND gadgets.
	    (V39)
	LAYOUTA_Spacing - FOR COMPATIBILITY ONLY.  Use GTMX_Spacing instead.
	    The number of extra pixels to insert between each choice of a
	    mutually exclusive gadget.  This is added to the present gadget
	    image height (9) to produce the true spacing between choices.
	    (defaults to FontHeight-8, which is zero for 8-point font users).
	    (V36)

	NUMBER_KIND (read-only numeric):
	GTNM_Number (LONG) - A signed long integer to be displayed as a read-only
	    number (defaults to 0). (V36)
	GTNM_Border (BOOL) - If TRUE, this flag asks for a recessed border to
	    be placed around the gadget. (V36)
	GTNM_FrontPen (UBYTE) - The pen to use when rendering the number
	    (defaults to DrawInfo->dri_Pens[TEXTPEN]). (V39)
	GTNM_BackPen (UBYTE) - The pen to use when rendering the background
	    of the number (defaults to leaving the background untouched).
	    (V39)
	GTNM_Justification (UBYTE) - Determines how the number is rendered
	    within the gadget box. GTJ_LEFT will make the rendering be
	    flush with the left side of the gadget, GTJ_RIGHT will make it
	    flush with the right side, and GTJ_CENTER will center the number
	    within the gadget box. Under V39, using this tag also required
	    using {GTNM_Clipped, TRUE}, otherwise the text would not show
	    up in the gadget. This has been fixed in V40.
	    (defaults to GTJ_LEFT). (V39)
	GTNM_Format (STRPTR) - C-Style formatting string to apply on the number
	    before display. Be sure to use the 'l' (long) modifier. This string
	    is processed using [exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), so refer to that
	    function for details. (defaults to "%ld") (V39)
	GTNM_MaxNumberLen (ULONG) - Maximum number of bytes that can be
	    generated by applying the GTNM_Format formatting string to the
	    number (excluding the NULL terminator). (defaults to 10). (V39)
	GTNM_Clipped (BOOL) - Determine whether text should be clipped to
	    the gadget dimensions (defaults to FALSE for gadgets without
	    borders, TRUE for gadgets with borders). (V39)

	PALETTE_KIND (color selection):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V36)
	GTPA_Depth (UWORD) - Number of bitplanes in the palette
	    (defaults to 1). (V36)
	GTPA_Color (UBYTE) - Initially selected color of the palette. This
	    number is a pen number, and not the ordinal color number within
	    the palette gadget itself. (defaults to 1). (V36)
	GTPA_ColorOffset (UBYTE) - First color to use in palette
	    (defaults to 0). (V36)
	GTPA_IndicatorWidth (UWORD) - The desired width of the current-color
	    indicator, if you want one to the left of the palette. (V36)
	GTPA_IndicatorHeight (UWORD) - The desired height of the current-color
	    indicator, if you want one above the palette. (V36)
	GTPA_ColorTable (UBYTE *) - Pointer to a table of pen numbers
	    indicating  which colors should be used and edited by the palette
	    gadget. This array must contain as many entries as there are
	    colors displayed in the palette gadget. The array provided with
	    this tag must remain valid for the life of the gadget or until a
	    new table is provided. (default is NULL, which causes a 1-to-1
	    mapping of pen numbers). (V39)
	GTPA_NumColors (UWORD) - Number of colors to display in the palette
	    gadget. This override GTPA_Depth and allows numbers which aren't
	    powers of 2. (defaults to 2) (V39)

	SCROLLER_KIND (for scrolling through areas or lists):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V36)
	GA_RelVerify (BOOL) - Hear every IDCMP_GADGETUP event from scroller
	    (defaults to FALSE). (V36)
	GA_Immediate (BOOL) - Hear every IDCMP_GADGETDOWN event from scroller
	    (defaults to FALSE). (V36)
	GTSC_Top (WORD) - Top visible in area scroller represents
	    (defaults to 0). (V36)
	GTSC_Total (WORD) - Total in area scroller represents
	    (defaults to 0). (V36)
	GTSC_Visible (WORD) - Number visible in scroller (defaults to 2). (V36)
	GTSC_Arrows (UWORD) - Asks for arrows to be attached to the scroller.
	    The value supplied will be taken as the width of each arrow button
	    for a horizontal scroller, or the height of each button for a
	    vertical scroller (the other dimension will match the whole
	    scroller). (V36)
	PGA_Freedom - Whether scroller is horizontal or vertical.
	    Choose LORIENT_VERT or LORIENT_HORIZ (defaults to LORIENT_HORIZ).
	    (V36)

	SLIDER_KIND (to indicate level or intensity):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V36)
	GA_RelVerify (BOOL) - If you want to hear each slider IDCMP_GADGETUP
	    event (defaults to FALSE). (V36)
	GA_Immediate (BOOL) - If you want to hear each slider IDCMP_GADGETDOWN
	    event (defaults to FALSE). (V36)
	GTSL_Min (WORD) - Minimum level for slider (defaults to 0). (V36)
	GTSL_Max (WORD) - Maximum level for slider (defaults to 15). (V36)
	GTSL_Level (WORD) - Current level of slider (defaults to 0). (V36)
	GTSL_MaxLevelLen (UWORD) - Maximum length in characters of level string
	    when rendered beside slider (defaults to 2). (V36)
	GTSL_LevelFormat (STRPTR) - C-Style formatting string for slider
	    level.  Be sure to use the 'l' (long) modifier.  This string
	    is processed using [exec.library/RawDoFmt()](autodocs-3.5/exec-library-rawdofmt-2.md), so refer to that
	    function for details. (defaults to "%ld"). (V36)
	GTSL_LevelPlace - One of PLACETEXT_LEFT, PLACETEXT_RIGHT,
	    PLACETEXT_ABOVE, or PLACETEXT_BELOW, indicating where the level
	    indicator is to go relative to slider (default to PLACETEXT_LEFT).
	    (V36)
	GTSL_DispFunc ( [LONG](autodocs-3.5/include-exec-types-h.md) (*function)(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, WORD) ) - Function
	    to calculate level to be displayed.  A number-of-colors slider
	    might want to set the slider up to think depth, and have a
	    (1 << n) function here.  Defaults to none.  Your function must
	    take a pointer to gadget as the first parameter, the level
	    (a WORD) as the second, and return the result as a [LONG](autodocs-3.5/include-exec-types-h.md). (V36)
	GTSL_MaxPixelLen (ULONG) - Indicates the maximum pixel size used up
	    by the level display for any value of the slider. This is mostly
	    useful when dealing with proportional fonts. (defaults to
	    FontWidth*MaxLevelLen). (V39)
	GTSL_Justification (UBYTE) - Determines how the level display is to
	    be justified within its alotted space. Choose one of GTJ_LEFT,
	    GTJ_RIGHT, or GTJ_CENTER (defaults to GTJ_LEFT). (V39)
	PGA_Freedom - Set to LORIENT_VERT or LORIENT_HORIZ to have a
	    vertical or horizontal slider (defaults to LORIENT_HORIZ). (V36)

	STRING_KIND (text-entry):
	GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
	    (defaults to FALSE). (V36)
	GA_Immediate (BOOL) - Hear IDCMP_GADGETDOWN events from string
	    gadget (defaults to FALSE). (V39)
	GA_TabCycle (BOOL) - Set to TRUE so that pressing <TAB> or <Shift-TAB>
	    will activate the next or previous such gadget. (defaults to TRUE,
	    unlike regular Intuition string gadgets which default to FALSE).
	    (V37)
	GTST_String (STRPTR) - The initial contents of the string gadget,
	    or NULL (default) if string is to start empty. (V36)
	GTST_MaxChars (UWORD) - The maximum number of characters that the
	    string gadget is to hold. (V36)
	GTST_EditHook (struct [Hook](autodocs-3.5/include-utility-hooks-h.md) *) - [Hook](autodocs-3.5/include-utility-hooks-h.md) to use as a custom string gadget
	    edit hook (StringExtend->EditHook) for this gadget. GadTools will
	    allocate the StringExtend->WorkBuffer for you. (defaults to NULL).
	    (V37)
	STRINGA_ExitHelp (BOOL) - Set to TRUE to have the help-key cause an
	    exit from the string gadget.  You will then receive an
	    IDCMP_GADGETUP event with Code = 0x5F (rawkey for help).
	    (V37)
	STRINGA_Justification - Controls the justification of the contents of
	    a string gadget.  Choose one of STRINGLEFT, STRINGRIGHT, or
	    STRINGCENTER (defaults to STRINGLEFT). (V37)
	STRINGA_ReplaceMode (BOOL) - If TRUE, this string gadget is in
	    replace-mode (defaults to FALSE (insert-mode)). (V37)

	TEXT_KIND (read-only text):
	GTTX_Text - Pointer to a NULL terminated string to be displayed,
	    as a read-only text-display gadget, or NULL. (defaults to NULL)
	    (V36)
	GTTX_CopyText (BOOL) -	This flag instructs the text-display gadget
	    to copy the supplied text string, instead of using only
	    pointer to the string.  This only works for the initial value
	    of GTTX_Text set at CreateGadget() time.  If you subsequently
	    change GTTX_Text, the new text will be referenced by pointer,
	    not copied.  Do not use this tag with a NULL GTTX_Text. (V37)
	GTTX_Border (BOOL) - If TRUE, this flag asks for a recessed
	    border to be placed around the gadget. (V36)
	GTTX_FrontPen (UBYTE) - The pen to use when rendering the text
	    (defaults to DrawInfo->dri_Pens[TEXTPEN]). (V39)
	GTTX_BackPen (UBYTE) - The pen to use when rendering the background
	    of the text (defaults to leaving the background untouched).
	    (V39)
	GTTX_Justification (UBYTE) - Determines how the text is rendered
	    within the gadget box. GTJ_LEFT will make the rendering be
	    flush with the left side of the gadget, GTJ_RIGHT will make it
	    flush with the right side, and GTJ_CENTER will center the text
	    within the gadget box. Under V39, using this tag also required
	    using {GTNM_Clipped, TRUE}, otherwise the text would not show
	    up in the gadget. This has been fixed in V40.
	    (defaults to GTJ_LEFT). (V39)
	GTTX_Clipped (BOOL) - Determine whether text should be clipped to
	    the gadget dimensions (defaults to FALSE for gadgets without
	    borders, TRUE for gadgets with borders). (V39)

   RESULT
	gad - pointer to the new gadget, or NULL if the allocation failed
	      or if previous was NULL.

   NOTES
	Note that the ng_VisualInfo and ng_TextAttr fields of the
	[NewGadget](autodocs-3.5/include-libraries-gadtools-h.md) structure must be set to valid VisualInfo and
	[TextAttr](autodocs-3.5/include-graphics-text-h.md) pointers, or this function will fail.

	Starting with V37, string and integer gadgets have the GFLG_TABCYCLE
	feature automatically.  If the user presses Tab or Shift-Tab while
	in a string or integer gadget, the next or previous one in
	sequence will be activated.  You will hear an IDCMP_GADGETUP message
	with a code of 0x09.  Use {GA_TabCycle, FALSE} to supress this.

   SEE ALSO
	[FreeGadgets()](autodocs-3.5/gadtools-library-freegadgets-2.md), GT_SetGadgetAttrs(), GetVisualInfo(),
	[<libraries/gadtools.h>](autodocs-3.5/include-libraries-gadtools-h.md)

---

## See Also

- [CreateGadgetA — gadtools.library](../autodocs/gadtools.library.md#creategadgeta)
- [FreeGadgets — gadtools.library](../autodocs/gadtools.library.md#freegadgets)
- [RawDoFmt — exec.library](../autodocs/exec.library.md#rawdofmt)
