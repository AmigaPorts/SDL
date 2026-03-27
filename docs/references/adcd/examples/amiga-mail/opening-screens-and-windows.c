/* Source: ADCD 2.1
 * Section: opening-screens-and-windows
 * Library: amiga-mail
 * ADCD reference: amiga-mail/opening-screens-and-windows.md
 */

    struct TagItem tagitem[3];
    struct Screen *screen;
    struct Window *window;

    tagitem[0].ti_Tag  = SA_DisplayID;
    tagitem[0].ti_Data = HIRES_KEY;     /* Use HIRES displaymode
                                           for default monitor */
    tagitem[1].ti_Tag  = SA_Title;
    tagitem[1].ti_Data = "AmigaMail Test Screen";
    tagitem[2].ti_Tag  = TAG_DONE;    /* Marks the end of the tag array. */

    /* All others options will be set to default. Note this screen will not
       open with the 'New Look', due to the absence of the SA_Pens tag and
       data. Further examples will have this tag */

    if (screen = OpenScreenTagList(NULL,   tagitem)) {
        tagitem[0].ti_Tag = WA_CustomScreen;
        tagitem[0].ti_Data = screen;    /* Open on my own screen */
        tagitem[1].ti_Tag = WA_Title;
        tagitem[1].ti_Data = "AmigaMail Test Window";
        tagitem[2].ti_Tag = TAG_DONE; /* Marks the end of the tag array. */

        /* Use defaults for everything else. Will open as big as the screen. */

        if (window = OpenWindowTagList(NULL, tagitem)) {

            /* rest of code */

            CloseWindow(window);
        }
        CloseScreen(screen)
    }
