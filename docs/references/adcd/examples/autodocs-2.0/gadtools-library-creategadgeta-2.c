/* Source: ADCD 2.1
 * Section: gadtools-library-creategadgeta
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-creategadgeta.md
 */

    All kinds:
    GT_Underscore (GadTools V37 and higher only).
        Indicates the symbol that precedes the character in the gadget
        label to be underscored.  This would be to indicate keyboard
        equivalents for gadgets (note that GadTools does not process
        the keys - it just displays the underscore).
        Example: To underscore the "M" in "Mode"...
            ng.ng_GadgetText = "_Mode:";
            gad = CreateGadget(..._KIND, &ng, prev,
                    GT_Underscore, '_',
                    ...
                    );

    BUTTON_KIND (action buttons):
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    CHECKBOX_KIND (on/off items):
    GTCB_Checked (BOOL) - Initial state of checkbox, defaults to FALSE.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    CYCLE_KIND (multiple state selections):
    GTCY_Labels (STRPTR *) - Pointer to NULL-terminated array of strings
        that are the choices offered by the cycle gadget (required).
    GTCY_Active (UWORD) - The ordinal number (counting from zero) of
        the initially active choice of a cycle gadget (defaults to zero).
    GA_Disabled (BOOL) - (GadTools V37 and higher only)
        Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    INTEGER_KIND (numeric entry):
    GTIN_Number (ULONG) - The initial contents of the integer gadget
        (default zero).
    GTIN_MaxChars (UWORD) - The maximum number of digits that the
        integer gadget is to hold (defaults to 10).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).
    STRINGA_ExitHelp (BOOL) - (New for V37) Set to TRUE to have the
        help-key cause an exit from the integer gadget.  You will
        then receive a GADGETUP with code = 0x5F (rawkey for help).
    GA_TabCycle (BOOL) - (New for V37) Set to TRUE so that pressing
        <TAB> or <Shift-TAB> will activate the next or previous
        such gadget. (defaults to TRUE, unlike regular Intuition string
        gadgets, which default to FALSE).
    GTST_EditHook (struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *) - (new for V37) [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) to use as a custom
        integer gadget edit hook (StringExtend->EditHook) for this gadget.
        GadTools will allocate the StringExtend->WorkBuffer for you.
        Defaults to NULL.
    STRINGA_Justification - (new for V37) Controls the justification of
        the contents of an integer gadget.  Choose one of STRINGLEFT,
        STRINGRIGHT, or STRINGCENTER.  (Defaults to STRINGLEFT).
    STRINGA_ReplaceMode (BOOL) - (new for V37) If TRUE, this integer gadget
        is in replace-mode.  Defaults to FALSE (insert-mode).

    LISTVIEW_KIND (scrolling list):
    GTLV_Top (WORD) - Top item visible in the listview.  This value
        will be made reasonable if out-of-range (defaults to zero).
    GTLV_Labels (struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *) - [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) of labels whose ln_Name fields
        are to be displayed in the listview.
    GTLV_ReadOnly (BOOL) - If TRUE, then listview is read-only.
    GTLV_ScrollWidth (UWORD) - Width of scroll bar for listview.
        Must be greater than zero (defaults to 16).
    GTLV_ShowSelected (struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *) - NULL to have the currently
        selected item displayed beneath the listview, or pointer to
        an already-created GadTools STRING_KIND gadget to have an
        editable display of the currently selected item.
    GTLV_Selected (UWORD) - Ordinal number of currently selected
        item, or ~0 to have no current selection (defaults to ~0).
    LAYOUTA_Spacing - Extra space to place between lines of listview
        (defaults to zero).

    MX_KIND (mutually exclusive, radio buttons):
    GTMX_Labels (STRPTR *) - Pointer to a NULL-terminated array of
        strings which are to be the labels beside each choice in a
        set of mutually exclusive gadgets.
    GTMX_Active (UWORD) - The ordinal number (counting from zero) of
        the initially active choice of an mx gadget (Defaults to zero).
    GTMX_Spacing (UWORD) - The amount of space between each choice
        of a set of mutually exclusive gadgets.  This amount is added
        to the font height to produce the vertical shift between
        choices. (defaults to one).
    LAYOUTA_Spacing - FOR COMPATIBILITY ONLY.  Use GTMX_Spacing instead.
        The number of extra pixels to insert between
        each choice of a mutually exclusive gadget.  This is added
        to the present gadget image height (9) to produce the
        true spacing between choices.  (defaults to
        FontHeight-8, which is zero for 8-point font users).

    NUMBER_KIND (read-only numeric):
    GTNM_Number - A signed long integer to be displayed as a read-only
         number (default 0).
    GTNM_Border (BOOL) - If TRUE, this flag asks for a recessed
        border to be placed around the gadget.

    PALETTE_KIND (color selection):
    GTPA_Depth (UWORD) - Number of bitplanes in the palette
        (defaults to 1).
    GTPA_Color (UBYTE) - Initially selected color of the palette
        (defaults to 1).
    GTPA_ColorOffset (UBYTE) - First color to use in palette
        (defaults to zero).
    GTPA_IndicatorWidth (UWORD) - The desired width of the current-color
        indicator, if you want one to the left of the palette.
    GTPA_IndicatorHeight (UWORD) - The desired height of the current-color
        indicator, if you want one above the palette.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    SCROLLER_KIND (for scrolling through areas or lists):
    GTSC_Top (WORD) - Top visible in area scroller represents
        (defaults to zero).
    GTSC_Total (WORD) - Total in area scroller represents
        (defaults to zero).
    GTSC_Visible (WORD) - Number visible in scroller (defaults to 2).
    GTSC_Arrows (UWORD) - Asks for arrows to be attached to the scroller.
        The value supplied will be taken as the width of each arrow button
        for a horizontal scroller, or the height of each button for a
        vertical scroller (the other dimension will match the whole
        scroller).
    PGA_Freedom - Whether scroller is horizontal or vertical.
        Choose LORIENT_VERT or LORIENT_HORIZ (defaults to horiz).
    GA_Immediate (BOOL) - Hear every IDCMP_GADGETDOWN event from scroller
        (defaults to FALSE).
    GA_RelVerify (BOOL) - Hear every IDCMP_GADGETUP event from scroller
        (defaults to FALSE).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    SLIDER_KIND (to indicate level or intensity):
    GTSL_Min (WORD) - Minimum level for slider (default 0).
    GTSL_Max (WORD) - Maximum level for slider (default 15).
    GTSL_Level (WORD) - Current level of slider (default 0).
    GTSL_MaxLevelLen (UWORD) - Max. length in characters of level string
        when rendered beside slider.
    GTSL_LevelFormat (STRPTR) - C-Style formatting string for slider
        level.  Be sure to use the 'l' (long) modifier.  This string
        is processed using [exec/RawDoFmt()](../Includes_and_Autodocs_2._guide/node036C.html), so refer to that function
        for details.
    GTSL_LevelPlace - One of PLACETEXT_LEFT, PLACETEXT_RIGHT,
        PLACETEXT_ABOVE, or PLACETEXT_BELOW, indicating where the level
        indicator is to go relative to slider (default to PLACETEXT_LEFT).
    GTSL_DispFunc ( LONG (*function)(struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *, WORD) ) - Function
        to calculate level to be displayed.  A number-of-colors slider
        might want to set the slider up to think depth, and have a
        (1 << n) function here.  Defaults to none.  Your function must
        take a pointer to gadget as the first parameter, the level
        (a WORD) as the second, and return the result as a LONG.
    GA_Immediate (BOOL) - If you want to hear each slider IDCMP_GADGETDOWN
        event.
    GA_RelVerify (BOOL) - If you want to hear each slider IDCMP_GADGETUP
        event.
    PGA_Freedom - Set to LORIENT_VERT or LORIENT_HORIZ to have a
        vertical or horizontal slider.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    STRING_KIND (text-entry):
    GTST_String (STRPTR) - The initial contents of the string gadget,
         or NULL (default) if string is to start empty.
    GTST_MaxChars (UWORD) - The maximum number of characters that the
        string gadget is to hold.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).
    STRINGA_ExitHelp (BOOL) - (New for V37) Set to TRUE to have the
        help-key cause an exit from the string gadget.  You will
        then receive a GADGETUP with code = 0x5F (rawkey for help).
    GA_TabCycle (BOOL) - (New for V37) Set to TRUE so that pressing
        <TAB> or <Shift-TAB> will activate the next or previous
        such gadget. (defaults to TRUE, unlike regular Intuition string
        gadgets, which default to FALSE).
    GTST_EditHook (struct [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) *) - (new for V37) [Hook](../Includes_and_Autodocs_2._guide/node012D.html#line23) to use as a custom
        string gadget edit hook (StringExtend->EditHook) for this gadget.
        GadTools will allocate the StringExtend->WorkBuffer for you.
        Defaults to NULL.
    STRINGA_Justification - (new for V37) Controls the justification of
        the contents of a string gadget.  Choose one of STRINGLEFT,
        STRINGRIGHT, or STRINGCENTER.  (Defaults to STRINGLEFT).
    STRINGA_ReplaceMode (BOOL) - (new for V37) If TRUE, this string gadget
        is in replace-mode.  Defaults to FALSE (insert-mode).

    TEXT_KIND (read-only text):
    GTTX_Text - Pointer to a NULL terminated string to be displayed,
        as a read-only text-display gadget, or NULL. defaults to NULL.
    GTTX_CopyText (BOOL) -  This flag instructs the text-display gadget
        to copy the supplied text string, instead of using only
        pointer to the string.  This only works for the initial value
        of GTTX_Text set at CreateGadget() time.  If you subsequently
        change GTTX_Text, the new text will be referenced by pointer,
        not copied.  Do not use this tag with a NULL GTTX_Text.
    GTTX_Border (BOOL) - If TRUE, this flag asks for a recessed
        border to be placed around the gadget.
