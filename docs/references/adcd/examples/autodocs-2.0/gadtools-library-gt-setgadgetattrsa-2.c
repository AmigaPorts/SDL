/* Source: ADCD 2.1
 * Section: gadtools-library-gt-setgadgetattrsa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-gt-setgadgetattrsa.md
 */

    BUTTON_KIND:
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    CHECKBOX_KIND:
    GTCB_Checked (BOOL) - Initial state of checkbox, defaults to FALSE.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    CYCLE_KIND:
    GTCY_Active (UWORD) - The ordinal number (counting from zero) of
        the active choice of a cycle gadget (defaults to zero).
    GTCY_Labels (STRPTR *) - (GadTools V37 and higher only)
        Pointer to NULL-terminated array of strings
        that are the choices offered by the cycle gadget.
    GA_Disabled (BOOL) - (GadTools V37 and higher only)
        Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    INTEGER_KIND:
    GTIN_Number (ULONG) - The initial contents of the integer gadget
        (default zero).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    LISTVIEW_KIND:
    GTLV_Top (WORD) - Top item visible in the listview.  This value
        will be made reasonable if out-of-range (defaults to zero).
    GTLV_Labels (struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *) - [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) of labels whose ln_Name fields
        are to be displayed in the listview.  Use a value of ~0 to
        "detach" your [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) from the display.  You must detach your list
        before modifying the [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) structure, since GadTools reserves
        the right to traverse it on another task's schedule.  When you
        are done, attach the list by using the tag pair
        {GTLV_Labels, list}.
    GTLV_Selected (UWORD) - Ordinal number of currently selected
        item (defaults to zero if GTLV_ShowSelected is set).

    MX_KIND:
    GTMX_Active (UWORD) - The ordinal number (counting from zero) of
        the active choice of an mx gadget (Defaults to zero).

    NUMBER_KIND:
    GTNM_Number - A signed long integer to be displayed as a read-only
         number (default 0).

    PALETTE_KIND:
    GTPA_Color (UBYTE) - Initially selected color of the palette
        (defaults to 1).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    SCROLLER_KIND:
    GTSC_Top (WORD) - Top visible in scroller (defaults to zero).
    GTSC_Total (WORD) - Total in scroller area (defaults to zero).
    GTSC_Visible (WORD) - Number visible in scroller (defaults to 2).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    SLIDER_KIND:
    GTSL_Min (WORD) - Minimum level for slider (default 0).
    GTSL_Max (WORD) - Maximum level for slider (default 15).
    GTSL_Level (WORD) - Current level of slider (default 0).
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    STRING_KIND:
    GTST_String (STRPTR) - The initial contents of the string gadget,
         or NULL (default) if string is to start empty.
    GA_Disabled (BOOL) - Set to TRUE to disable gadget, FALSE otherwise
        (defaults to FALSE).

    TEXT_KIND:
    GTTX_Text - Pointer to a NULL terminated string to be displayed,
        as a read-only text-display gadget, or NULL. defaults to NULL.
