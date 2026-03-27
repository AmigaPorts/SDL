/* Source: ADCD 2.1
 * Section: 6-setting-up-menus-menu-numbers
 * Library: libraries
 * ADCD reference: libraries/6-setting-up-menus-menu-numbers.md
 */

    if (menuNumber == MENUNULL)
        /* no menu selection was made */ ;
    else
        {
        /* if there were no sub-items attached to that item,
        ** SubNumber will equal NOSUB.
        */
        menuNum = MENUNUM(menuNumber);
        itemNum = ITEMNUM(menuNumber);
        subNum  = SUBNUM(menuNumber);
        }
