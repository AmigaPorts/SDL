/* Source: ADCD 2.1
 * Section: iv-3-clonewb-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-clonewb-c.md
 */

    struct Screen *wbscreen;
    struct Screen *clonescreen;
    struct Window *window;
    struct ViewPort *vp;
    struct IntuiMessage *msg;
    ULONG modeID;

    struct DisplayInfo displayinfo;
    struct MonitorInfo monitorinfo;
    struct DimensionInfo dimensioninfo;
    struct NameInfo nameinfo;
    struct DrawInfo *drawinfo;

    ULONG result;

    /* Fails silently when not V36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36)) {
        if (GfxBase = OpenLibrary("graphics.library", 36)) {

            if (wbscreen = LockPubScreen("Workbench")) {
                /* Using intuition.library/GetScreenDrawInfo(), we get the pen
                 * array we'll use for the screen clone the easy way. */
                drawinfo = GetScreenDrawInfo(wbscreen);

                vp = &(wbscreen->ViewPort);
                /* Use graphics.library/GetVPModeID() to get the ModeID of the
                 * Workbench screen. */
                if ((modeID = GetVPModeID(vp)) != INVALID_ID) {
                    /* OK, we got a valid ModeID for the Workbench
                     * screen (surprise) */

                    /* With just the ModeID, the lock on the Workbench
                     * screen & drawinfo->dri_Pens we're able to clone the
                     * Workbench exactly, displaymode and all. When you want
                     * to know everything there is to know about this
                     * displaymode, use graphics.library/GetDisplayInfoData().
                     */
                    /* 'result' is the actual # of bytes copies
                     * into the buffer.
                     * See graphics/displayinfo.h for definitions
                     * of the various structures.
                     */
                    result = GetDisplayInfoData(NULL,
                                                (UBYTE *)&monitorinfo,
                                                sizeof(struct MonitorInfo),
                                                DTAG_MNTR, modeID);
                    result = GetDisplayInfoData(NULL,
                                                (UBYTE *)&displayinfo,
                                                sizeof(struct DisplayInfo),
                                                DTAG_DISP, modeID);
                    result = GetDisplayInfoData(NULL,
                                                (UBYTE *)&dimensioninfo,
                                                sizeof(struct DimensionInfo),
                                                DTAG_DIMS,
                                                modeID);
                    result = GetDisplayInfoData(NULL,
                                                (UBYTE *)&nameinfo,
                                                sizeof(struct NameInfo),
                                                DTAG_NAME,
                                                modeID);

                    /* If you don't want to clone the workbench exactly,
                     * you could use one of the other overscan modes
                     * and/or min/max.
                     * dimensions in dimensioninfo or open a regular screen.
                     */
                    if (clonescreen = OpenScreenTags(NULL,
                        /* Could use STDSCREENWIDTH/HEIGHT for non-scrollable
                         * screens. Those make */
                        SA_Width, wbscreen->Width,

                        /* OpenScreen() use the textoverscan values */
                        SA_Height, wbscreen->Height,

                        SA_DisplayID, modeID,

                        SA_Depth, wbscreen->BitMap.Depth,

                        /*Workbench always sizes up to OSCAN_TEXT, so do we */
                        SA_Overscan, OSCAN_TEXT,

                        SA_Pens, drawinfo->dri_Pens,

                        SA_Title, nameinfo.Name,

                        /* Doesn't hurt for screens which don't scroll */
                        SA_AutoScroll, TRUE,

                        TAG_END)) {

                        if (window = OpenWindowTags(NULL,
                            WA_Top, clonescreen->BarHeight + 1,
                            WA_Height, clonescreen->Height
                                                - (clonescreen->BarHeight + 1),
                            WA_CustomScreen, clonescreen,
                            WA_MinWidth, 320,
                            WA_MinHeight, 100,
                            WA_MaxWidth, clonescreen->Width,
                            WA_MaxHeight, clonescreen->Height,

                            /* I'm only interested in CLOSEWINDOW messages */
                            WA_IDCMP, CLOSEWINDOW,
                            WA_Flags, WINDOWSIZING|WINDOWDRAG|
                                           WINDOWDEPTH|WINDOWCLOSE|ACTIVATE,
                            WA_Title, "Close to exit.",
                            TAG_END)) {

                            /* Wait for the closewindow message */
                            WaitPort(window->UserPort);
                            /* And remove message from the port */
                            while(msg = (struct IntuiMessage *)
                                  GetMsg(window->UserPort))
                                ReplyMsg((struct Message *)msg);
                            CloseWindow(window);
                        } else
                            EasyRequest(NULL, &failedES, NULL,
                                        "Can't open window");
                        CloseScreen(clonescreen);
                    } else
                        EasyRequest(NULL, &failedES, NULL,
                                    "Can't open screen");
                } else
                    EasyRequest(NULL, &failedES, NULL, "Invalide ModeID");
                FreeScreenDrawInfo(wbscreen, drawinfo);
                UnlockPubScreen(NULL, wbscreen);
            } else
                EasyRequest(NULL, &failedES, NULL,
                            "Can't lock Workbench screen");
            CloseLibrary(GfxBase);
        }
        CloseLibrary(IntuitionBase);
    }
