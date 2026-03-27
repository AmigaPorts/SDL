/* Source: ADCD 2.1
 * Section: i-1-tagitems-and-tag-lists
 * Library: amiga-mail
 * ADCD reference: amiga-mail/i-1-tagitems-and-tag-lists.md
 */

    struct TagItem tagitem[3];
    struct Window *window;

    tagitem[0].ti_Tag = WA_CustomScreen;
    tagitem[0].ti_Data = screen;    /* Open on my own screen */
    tagitem[1].ti_Tag = WA_Title;
    tagitem[1].ti_Data = "AmigaMail Test Window";
    tagitem[2].ti_Tag = TAG_DONE;   /* Marks the end of the tag array. */

    /* Use defaults for everything else. Will open as big as the screen.*/

    if (window = OpenWindowTagList(NULL, /* Because all window parameters
                                          * are specified using tags, we
                                          * don't need a NewScreen
                                          * structure                   */
                                   tagitem))
    {
        /* rest of code */
        CloseWindow(window);
    }
