/* Source: ADCD 2.1
 * Section: gadtools-library-createmenusa
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-createmenusa.md
 */

    GTMN_FrontPen (UBYTE) - Pen number to be used for menu text.
        (defaults to zero).
    GTMN_FullMenu (BOOL) - (GadTools V37 and higher only)
        Requires that the [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) specification describes a complete
        menu strip, not a fragment.  If a fragment is found,
        CreateMenusA() will fail with a secondary error of
        GTMENU_INVALID.  (defaults to FALSE).
    GTMN_SecondaryError (ULONG *) - (GadTools V37 and higher only)
        Supply a pointer to a NULL-initialized ULONG to receive a
        descriptive error code.  Possible values:
        GTMENU_INVALID - [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) structure describes an illegal
            menu.  (CreateMenusA() will fail with a NULL result).
        GTMENU_TRIMMED - [NewMenu](../Includes_and_Autodocs_2._guide/node0106.html#line122) structure has too many menus, items,
            or subitems (CreateMenusA() will succeed, returning a
            trimmed-down menu structure).
        GTMENU_NOMEM - CreateMenusA() ran out of memory.
