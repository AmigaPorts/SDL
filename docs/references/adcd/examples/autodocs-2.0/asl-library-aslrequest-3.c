/* Source: ADCD 2.1
 * Section: asl-library-aslrequest
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/asl-library-aslrequest.md
 */

    ( REMEMBER - ALL DATA STRUCTURES ARE READ-ONLY EXCEPT BY USING
      TAGITEMS !!! )

    ASL_Hail (STRPTR) - Hailing text to prompt user, typically
        displayed in window title bar.
    ASL_Window (struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *) - Parent window for the request
        function, which is used to select the screen on which the
        requesting window will be displayed and also is used for
        a shared IDCMP port.

    ASL_LeftEdge (WORD) - Preferred display position for left edge where
        request window should open.
    ASL_TopEdge (WORD) - Preferred top edge of request window.
    ASL_Width (WORD)   - Preferred width of request window.
    ASL_Height (WORD)  - Preferred height of request window.

    ASL_HookFunc (APTR) - Pointer to callback function, specific to
        each AslRequest type.

    ASL_File (STRPTR) - [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) initial filename string.
    ASL_Dir (STRPTR) - [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65) initial directory path string.

    ASL_FontName (STRPTR) - [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) initial fontname string.
    ASL_FontHeight (UWORD) - [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) initial height (ta_YSize).
    ASL_FontStyles (UBYTE) - [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) initial styles (ta_Style).
    ASL_FontFlags (UBYTE) - [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) initial flags (ta_Flags).
    ASL_FrontPen (BYTE) - [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) front pen color (fo_FrontPen).
    ASL_BackPen (BYTE) - [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) back pen color (fo_BackPen).
    ASL_MinHeight (UWORD) - Minimum height for [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) display
        of font sizes.  (Application must check return value).
    ASL_MaxHeight (UWORD) - Maximum height for [FontRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line147) display
        of font sizes. (Application must check ta_YSize returned).

    ASL_OKText (STRPTR) - Replacement for default "OK" gadget text.
        ( Limited to approx. six characters ).
    ASL_CancelText (STRPTR) - Replacement for default "CANCEL"
        gadget text. ( Limited to approx. six characters ).

    ASL_FuncFlags (ULONG) - Function flags, depends on requester
        type.  Example: FILF_SAVE for [FileRequester](../Includes_and_Autodocs_2._guide/node00EA.html#line65).
    ASL_ExtFlags1 (ULONG) - Extended flags (to pass FILF1_ bitdefs)
               Example: FIL1F_NOFILES for file requester
