/* Source: ADCD 2.1
 * Section: iv-69-jumpy-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-69-jumpy-c.md
 */

    struct Window       *window;
    struct IntuiMessage *imsg;
    struct Gadget       *gadgetcontext;
    struct Gadget       *gadget, *nextscreengadget;
    struct NewGadget     ng;
    struct TextExtent    textextent;
    UWORD                left, top;
    void                *visualinfo;
    UBYTE               *startupname;
    UBYTE                namebuffer[MAXPUBSCREENNAME];
    UBYTE              **tooltypes;
    BOOL                 ABORT = FALSE;

    if (IntuitionBase = OpenLibrary("intuition.library", 37))
    {
        /* Open GfxBase to use TextExtent() so we can handle proportional fonts */
        if (GfxBase = OpenLibrary("graphics.library", 37))
        {
            if (GadToolsBase = OpenLibrary("gadtools.library", 37))
            {

                /*
                 * Open commodities & icon.library so we can use ArgArray
                 * functions
                 */
                if (CxBase = OpenLibrary("commodities.library", 37))
                {
                    if (IconBase = OpenLibrary("icon.library", 37))
                    {
                        left = 50;
                        top = 50;                /* Initial offset */
                        /* Note that these are functions in amiga.lib */
                        if (tooltypes = ArgArrayInit(argc, argv))
                        {
                            startupname =
                                ArgString(tooltypes, "PUBSCREEN", "Workbench");
                            strcpy(namebuffer, startupname);
                            ArgArrayDone();
                        }
                        else
                            strcpy(namebuffer, "Workbench");
                        do
                        {
                            /* open a window with tags */
                            /* no NewWindow structure, tags only */
                            if (window = OpenWindowTags(NULL,
                                        /* Open at far left corner */
                                        WA_Left,  left,
                                        WA_Top,   top,
                                        WA_Width, 150,
                                        WA_Height, 80,
                                        WA_Title, (LONG) "jumpy",
                                        WA_PubScreenName, (LONG) namebuffer,
                                        /* if no pubscreen with this name exists... */
                                        WA_PubScreenFallBack, TRUE,
                                        /* ...fall back on default pubscreen */
                                        WA_Flags, WFLG_DRAGBAR | WFLG_DEPTHGADGET |
                                            WFLG_CLOSEGADGET | WFLG_ACTIVATE |
                                            WFLG_SMART_REFRESH | WFLG_NOCAREREFRESH,
                                        WA_IDCMP, IDCMP_CLOSEWINDOW | IDCMP_GADGETUP,
                                        TAG_DONE))
                            {

                                /*
                                 * Get the visual info gadtools needs for the
                                 * screen we opened on
                                 */
                                if (visualinfo = GetVisualInfoA(window->WScreen, NULL))
                                {

                                    /*
                                     * Create a simple gadtools button and sort
                                     * of lay it out. Note this doesn't do any
                                     * checking for legal (window) dimensions.
                                     */
                                    if (gadget = CreateContext(&gadgetcontext))
                                    {

                                        /*
                                         * Use TextExtent to handle
                                         * proportional fonts
                                         */
                                        TextExtent(&(window->WScreen->RastPort),
                                                   "Jump", 4, &textextent);
                                        ng.ng_Width = textextent.te_Width + 8;
                                        ng.ng_LeftEdge = (window->Width / 2) -
                                                          (ng.ng_Width / 2);
                                        ng.ng_Height = textextent.te_Height + 4;
                                        ng.ng_TopEdge = (
                                            (window->Height - window->BorderTop -
                                                window->BorderBottom) / 2) +
                                            (ng.ng_Height / 2);
                                        ng.ng_TextAttr = window->WScreen->Font;
                                        ng.ng_GadgetText = "Jump";
                                        ng.ng_VisualInfo = visualinfo;
                                        ng.ng_GadgetID = 1;
                                        ng.ng_Flags = PLACETEXT_IN;
                                        nextscreengadget = gadget =
                                            CreateGadget(BUTTON_KIND, gadget, &ng,
                                                         TAG_END);
                                        AddGList(window, gadget, -1, -1, NULL);
                                        RefreshGList(gadget, window, NULL, -1);
                                        GT_RefreshWindow(window, NULL);

                                        WaitPort(window->UserPort);
                                        while (imsg = (struct IntuiMessage *)
                                            GetMsg(window->UserPort))
                                        {
                                            if (imsg->Class == IDCMP_CLOSEWINDOW)
                                                ABORT = TRUE;
                                            else if (imsg->Class = IDCMP_GADGETUP)
                                                NextPubScreen(window->WScreen,
                                                              namebuffer);
                                            ReplyMsg((struct Message *) imsg);
                                        }
                                        RemoveGadget(window, nextscreengadget);
                                        FreeGadgets(gadgetcontext);
                                    }
                                    FreeVisualInfo(visualinfo);
                                }
                                left = window->LeftEdge;
                                top = window->TopEdge;
                                CloseWindow(window);
                            }
                        } while (ABORT == FALSE);

                        CloseLibrary(IconBase);
                    }
                    CloseLibrary(CxBase);
                }
                CloseLibrary(GadToolsBase);
            }
            CloseLibrary(GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
    return (0);
