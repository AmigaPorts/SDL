/* Source: ADCD 2.1
 * Section: iv-69-hide-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-69-hide-c.md
 */

    struct Window  *window;
    struct IntuiMessage *imsg;
    struct Gadget  *gadgetcontext;
    struct Gadget  *gadget, *hidegadget;
    struct MsgPort *appport;
    struct NewGadget ng;
    struct TextExtent textextent;
    struct AppIcon *appicon = NULL;
    struct AppMessage *appmsg;
    UWORD           left, top;
    void           *visualinfo;
    ULONG           signal, windowsignal, waitmask;
    BOOL            ABORT = FALSE;
    BOOL            CONTINUE, ICONIFY;

    if (IntuitionBase = OpenLibrary("intuition.library", 37))
    {
        /* Open GfxBase to use TextExtent() so we can handle proportional fonts */
        if (GfxBase = OpenLibrary("graphics.library", 37))
        {
            /* Open gadtools for that lonely gadget */
            if (GadToolsBase = OpenLibrary("gadtools.library", 37))
            {
                if (WorkbenchBase = OpenLibrary("workbench.library", 37))
                {
                    /* Message to receive appmessage on */
                    if (appport = CreateMsgPort())
                    {
                        /* open a window with tags */
                        left = top = 50;
                        do
                        {
                            /* no NewWindow structure, tags only */
                            if (window = OpenWindowTags(NULL,
                                         /* Open at far left corner */
                                         WA_Left, left,
                                         WA_Top, top,
                                         WA_Width, 150,
                                         WA_Height, 80,
                                         WA_Title, (LONG) "hide",
                                         WA_Flags, WFLG_DRAGBAR |
                                             WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                                             WFLG_ACTIVATE | WFLG_SMART_REFRESH |
                                             WFLG_NOCAREREFRESH,
                                         WA_IDCMP,
                                             IDCMP_CLOSEWINDOW | IDCMP_GADGETUP,
                                         TAG_DONE))
                            {
                                windowsignal = 1L << window->UserPort->mp_SigBit;
                                /*
                                 * Get the visual info gadtools needs for the
                                 * screen we opened on
                                 */
                                if (visualinfo = GetVisualInfoA(window->WScreen, NULL))
                                {

                                    /*
                                     * Create a simple gadtools button and sort
                                     * of lay it out
                                     */
                                    if (gadget = CreateContext(&gadgetcontext))
                                    {

                                        /*
                                         * Use TextExtent to handle
                                         * proportional fonts
                                         */
                                        TextExtent(&(window->WScreen->RastPort),
                                                   "Hide", 4, &textextent);
                                        ng.ng_Width = textextent.te_Width + 8;
                                        ng.ng_LeftEdge = (window->Width / 2)
                                                              - (ng.ng_Width / 2);
                                        ng.ng_Height = textextent.te_Height + 4;
                                        ng.ng_TopEdge = (
                                            (window->Height - window->BorderTop
                                                - window->BorderBottom) / 2)
                                            + (ng.ng_Height / 2);
                                        ng.ng_TextAttr = window->WScreen->Font;
                                        ng.ng_GadgetText = "Hide";
                                        ng.ng_VisualInfo = visualinfo;
                                        ng.ng_GadgetID = 1;
                                        ng.ng_Flags = PLACETEXT_IN;
                                        hidegadget = gadget =
                                            CreateGadget(BUTTON_KIND, gadget,
                                                         &ng, TAG_END);
                                        AddGList(window, gadget, -1, -1, NULL);
                                        RefreshGList(gadget, window, NULL, -1);
                                        GT_RefreshWindow(window, NULL);

                                        CONTINUE = TRUE;
                                        waitmask = windowsignal|
                                                       1L << appport->mp_SigBit;
                                        do
                                        {
                                            signal = Wait(waitmask);

                                          if (signal & windowsignal)
                                            {
                                                while (imsg = (struct IntuiMessage *)
                                                    GetMsg(window->UserPort))
                                                {
                                                    if (imsg->Class ==
                                                            IDCMP_CLOSEWINDOW)
                                                    {
                                                        ABORT = TRUE;
                                                        CONTINUE = FALSE;
                                                        ICONIFY = FALSE;
                                                    }
                                                    else
                                                    if (imsg->Class == IDCMP_GADGETUP)
                                                        ICONIFY = TRUE;
                                                    ReplyMsg((struct Message *) imsg);
                                                }
                                            }
                                            if (signal & (1L << appport->mp_SigBit))
                                            {
                                                while (appmsg = (struct AppMessage *)
                                                    GetMsg(appport))
                                                {

                                                    /*
                                                     * If am->NumArgs is zero
                                                     * the user double-clicked
                                                     * on our icon, otherwise
                                                     * one or more icons were
                                                     * dropped on top of it.
                                                     */
                                                    if (appmsg->am_NumArgs == 0)
                                                    {
                                                        RemoveAppIcon(appicon);
                                                        CONTINUE = FALSE;
                                                    }
                                                    ReplyMsg(
                                                        (struct Message *) appmsg);
                                                }
                                            }
                                            if (ICONIFY)
                                            {

                                                /*
                                                 * Add appicon, close window if
                                                 * succesful
                                                 */
                                                appicon = AddAppIcon(1, NULL, "Hide",
                                                    appport, NULL, &AppIconDObj, NULL);
                                                if (appicon == NULL)
                                                {
                                                    DisplayBeep(window->WScreen);
                                                }
                                                else
                                                {
                                                    RemoveGadget(window, hidegadget);
                                                    left = window->LeftEdge;
                                                    top = window->TopEdge;
                                                    CloseWindow(window);
                                                    window = NULL;
                                                    /* there is no window
                                                     * message port anymore */
                                                    waitmask =
                                                        1L << appport->mp_SigBit;
                                                }
                                                ICONIFY = FALSE;
                                            }
                                        } while (CONTINUE == TRUE);
                                        if (window)
                                            RemoveGadget(window, hidegadget);
                                        FreeGadgets(gadgetcontext);
                                    }
                                    FreeVisualInfo(visualinfo);
                                }


                                if (window)
                                {
                                    left = window->LeftEdge;
                                    top = window->TopEdge;
                                    CloseWindow(window);
                                }
                            }
                        } while (ABORT == FALSE);
                        DeleteMsgPort(appport);
                    }
                    CloseLibrary(WorkbenchBase);
                }
                CloseLibrary(GadToolsBase);
            }
            CloseLibrary(GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
    return (0);
