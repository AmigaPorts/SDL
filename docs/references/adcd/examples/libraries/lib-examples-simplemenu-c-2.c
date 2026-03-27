/* Source: ADCD 2.1
 * Section: lib-examples-simplemenu-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-simplemenu-c.md
 */

    {
    /* we only have one signal bit, so we do not have to check which
    ** bit broke the Wait().
    */
    Wait(1L << win->UserPort->mp_SigBit);

    while ( (FALSE == done) &&
            (msg = (struct IntuiMessage *)GetMsg(win->UserPort)))
        {
        class = msg->Class;
        if(class == IDCMP_MENUPICK)   menuNumber = msg->Code;

        switch (class)
            {
            case IDCMP_CLOSEWINDOW:
                done = TRUE;
                break;
            case IDCMP_MENUPICK:
                while ((menuNumber != MENUNULL) && (!done))
                    {
                    item = ItemAddress(menuStrip, menuNumber);

                    /* process this item
                    ** if there were no sub-items attached to that item,
                    ** SubNumber will equal NOSUB.
                    */
                    menuNum = MENUNUM(menuNumber);
                    itemNum = ITEMNUM(menuNumber);
                    subNum  = SUBNUM(menuNumber);

                    /* Note that we are printing all values, even things
                    ** like NOMENU, NOITEM and NOSUB.  An application should
                    ** check for these cases.
                    */
                    printf("IDCMP_MENUPICK: menu %d, item %d, sub %d\n",
                        menuNum, itemNum, subNum);

                    /* This one is the quit menu selection...
                    ** stop if we get it, and don't process any more.
                    */
                    if ((menuNum == 0) && (itemNum == 4))
                        done = TRUE;

                    menuNumber = item->NextSelect;
                    }
                break;
            }
        ReplyMsg((struct Message *)msg);
        }
    }
