/* Source: ADCD 2.1
 * Section: 15-functions-for-gadtools-menus-creating-menus
 * Library: libraries
 * ADCD reference: libraries/15-functions-for-gadtools-menus-creating-menus.md
 */

    (New for V37, ignored under V36).  This tag allows [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) to
    return some secondary error codes.  Supply a pointer to a
    NULL-initialized ULONG, which will receive an appropriate error code
    as follows:

    GTMENU_INVALID
        Invalid menu specification.  For instance, a sub-item directly
        following a menu-title or an incomplete menu.  [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html)
        failed in this case, returning NULL.

    GTMENU_NOMEM
        Failed for lack of memory.  [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) returned NULL.

    GTMENU_TRIMMED
        The number of menus, items or sub-items exceeded the maximum
        number allowed so the menu was trimmed.  In this case,
        [CreateMenus()](../Includes_and_Autodocs_2._guide/node03E9.html) does not fail but returns a pointer to the trimmed
        [Menu](../Libraries_Manual_guide/node0199.html) structure.

    NULL
        If no error was detected.
