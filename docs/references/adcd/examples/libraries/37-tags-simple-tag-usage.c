/* Source: ADCD 2.1
 * Section: 37-tags-simple-tag-usage
 * Library: libraries
 * ADCD reference: libraries/37-tags-simple-tag-usage.md
 */

    struct TagItem tagitem[3];
    struct Screen *screen;
    struct Window *window;

    tagitem[0].ti_Tag = WA_CustomScreen;
    tagitem[0].ti_Data = screen;    /* Open on my own screen */
    tagitem[1].ti_Tag = WA_Title;
    tagitem[1].ti_Data = "RKM Test Window";
    tagitem[2].ti_Tag = TAG_DONE;   /* Marks the end of the tag array. */

    /* Use defaults for everything else. Will open as big as the screen. */
    /* Because all window parameters are specified using tags, we don't  */
    /* need a NewWindow structure                                        */

    if (window = OpenWindowTagList(NULL, tagitem))
    {
        /* rest of code */
        CloseWindow(window);
    }
