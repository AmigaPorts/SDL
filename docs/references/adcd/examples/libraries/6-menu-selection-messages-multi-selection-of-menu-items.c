/* Source: ADCD 2.1
 * Section: 6-menu-selection-messages-multi-selection-of-menu-items
 * Library: libraries
 * ADCD reference: libraries/6-menu-selection-messages-multi-selection-of-menu-items.md
 */

    struct IntuiMessage *msg;
    struct Menu *menuStrip;
    UWORD menuNumber;
    struct MenuItem *item;

    menuNumber = msg->Code;

    while (menuNumber != MENUNULL)
        {
        item = ItemAddress(menuStrip, menuNumber);

        /* process this item */

        menuNumber = item->NextSelect;
        }
