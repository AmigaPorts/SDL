/* Source: ADCD 2.1
 * Section: 15-gadtools-gadgets-creating-gadget-lists
 * Library: libraries
 * ADCD reference: libraries/15-gadtools-gadgets-creating-gadget-lists.md
 */

    struct NewGadget *newgad1, *newgad2, *newgad3;
    struct Gadget *glist = NULL;
    struct Gadget *pgad;

    ...
    /* Initialize NewGadget structures */
    ...

    /* Note that CreateContext() requires a POINTER to a NULL-initialized
     * pointer to struct Gadget:
     */
    pgad = CreateContext(&glist);

    pgad = CreateGadget(BUTTON_KIND, pgad, newgad1, TAG_END);
    pgad = CreateGadget(STRING_KIND, pgad, newgad2, TAG_END);
    pgad = CreateGadget(MX_KIND,     pgad, newgad3, TAG_END);

    if (!pgad)
        {
        FreeGadgets(glist);
        exit_error();
        }
    else
        {
        if ( mywin=OpenWindowTags(NULL,
                                  WA_Gadgets,   glist,
                                  ...
                                  /* Other tags... */
                                  ...
                                  TAG_END) )
            {
            /* Complete the rendering of the gadgets */
            GT_RefreshWindow(win, NULL);
            ...
            /* and continue on... */
            ...
            CloseWindow(mywin);
            }

        FreeGadgets(glist);
        }
