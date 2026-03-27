/* Source: ADCD 2.1
 * Section: iv-3-pub-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-pub-c.md
 */

    struct Screen *pubscreen;
    struct Window *window;
    struct Menu *menu;
    void *vi;

    struct IntuiMessage *msg;
    UBYTE defaultpubname[MAXPUBSCREENNAME];
    UWORD oldstatus;
    UWORD oldmodes;
    ULONG signal, wsignal, lastsignal, allocsignal;
    ULONG oserror;
    BOOL ABORT = FALSE;
    BOOL CLOSEDOWN = FALSE;
    struct Task *task;

    /* Fails silently if not V36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36)) {
        if (GadToolsBase = OpenLibrary("gadtools.library", 36)) {
            if ((allocsignal = AllocSignal(-1)) != -1) {
                lastsignal = 1 << allocsignal;

                /* We'll use our task address to get signaled when the last
                 * visitor window leaves. */
                task =
                  (struct Task *)&((struct Process *)FindTask(NULL))->pr_Task;

                /* Get the name of the currently default
                 * public screen (normally WB) */
                GetDefaultPubScreen(defaultpubname);

                /* Note that no checking is done to make sure the
                 * public screen name is unique.  If the public name is
                 * not unique, OSERR_PUBNOTUNIQUE is returned in an
                 * application supplied variable as data for the SA_ErrorCode
                 * tag.  In this case however, if OpenScreen fails, for
                 * whatever reason, we just bail out.
                 */

                if (pubscreen = OpenScreenTags(NULL,
                                 SA_DisplayID, HIRES_KEY,
                                 SA_Depth, 2,
                                 SA_Title,  "AmigaMail Test Public Screen",
                                 SA_PubName,"AmigaMail Test Public Screen",

                                 SA_PubSig, allocsignal,
                                 SA_PubTask, task,
                                          /* Normally you'd supply 0L, if you
                                          * the task which opened the screen to
                                          * be signaled.
                                          */
                                 SA_Pens, dri_Pens, SA_ErrorCode, &oserror,
                                 TAG_END)) {
                    if (menu = CreateMenus(sdm_menu, TAG_DONE)) {
                        if (window = OpenWindowTags(NULL,
                                      WA_Top, pubscreen->BarHeight + 1,
                                      WA_Height, pubscreen->Height
                                                 - (pubscreen->BarHeight + 1),
                                      WA_CustomScreen, pubscreen,
                                      WA_IDCMP, MENUPICK,
                                      WA_Flags, ACTIVATE|BACKDROP|
                                                    BORDERLESS|NOCAREREFRESH,
                                      TAG_END)) {

                            vi = GetVisualInfo(pubscreen, TAG_END);
                            if (LayoutMenus(menu, vi, TAG_DONE)) {
                                SetMenuStrip(window, menu);

                                /* Now we have a screen, named "AmigaMail Test
                                 * Public Screen", which is still marked
                                 * private, but ready to be made public.
                                 */
                                oldstatus = PubScreenStatus(pubscreen, 0);
                                /* Now it is really public. We'll make it the
                                 * default (and shanghai attempts to open
                                 * windows on the Workbench.
                                 */
                                SetDefaultPubScreen(
                                               "AmigaMail Test Public Screen");

                                oldmodes = SetPubScreenModes(SHANGHAI|
                                                             POPPUBSCREEN);

                                wsignal = 1 << window->UserPort->mp_SigBit;

                                do {
                                    signal = Wait(wsignal|lastsignal);
                                    /* The last visitor just left our screen */
                                    if (signal & lastsignal) {
                                        if (CLOSEDOWN)
                                            if ((oldstatus =
                                                 PubScreenStatus(pubscreen,
                                                           PSNF_PRIVATE)) & 1)
                                                ABORT = TRUE;
                                    }

                                    /* If not wsignal, this while-loop will not
                                     * be executed.
                                     */
                                    while(msg = (struct IntuiMessage *)
                                          GetMsg(window->UserPort)) {
                                    if (msg->Class == MENUPICK) {
                                            if ((UWORD)(MENU_USERDATA
                                                    (ItemAddress(menu,
                                                        msg->Code))) == QUIT) {
                                            /* If we can't make our screen
                                             * private again, we got
                                             * visitor window(s). Note
                                             * window(s) you open without
                                             * specifiying SA_PubScreenName,
                                             * are NOT considered visitor
                                             * windows.  So it's easy to try
                                             * to make your public screen
                                             * private again, without having
                                             * to close down your own windows
                                             * first.
                                             */

                                            if ((oldstatus =
                                                 PubScreenStatus(pubscreen,
                                                          PSNF_PRIVATE)) & 1) {
                                                ABORT = TRUE;
                                                }
                                            else {
                                                /* Close as soon as possible */
                                                     CLOSEDOWN = TRUE;
                                                    EasyRequest(window,
                                                                &failedES,
                                                                NULL,
                       "Can't make screen private.\nPlease close all windows");
                                                }
                                            }
                                        }
                                        ReplyMsg((struct Message *)msg);
                                    }
                                } while (ABORT == FALSE);

                                /* Restore orignal default */
                                SetDefaultPubScreen(defaultpubname);
                                ClearMenuStrip(window);
                                FreeVisualInfo(vi);
                            } else
                                EasyRequest(NULL,
                                            &failedES,
                                            NULL,
                                            "Can't layout menu's");
                            CloseWindow(window);
                        } else
                            EasyRequest(NULL,
                                        &failedES,
                                        NULL,
                                        "Can't open window");
                        FreeMenus(menu);
                    } else EasyRequest(NULL,
                                       &failedES,
                                       NULL,
                                       "Can't create menu's");
                    CloseScreen(pubscreen);
                } else
                    EasyRequest(NULL,
                                &failedES,
                                NULL,
                                "Can't open public screen");
                FreeSignal(allocsignal);
            } else
            EasyRequest(NULL, &failedES, NULL, "No signal available");
            CloseLibrary(GadToolsBase);
        }
    CloseLibrary(IntuitionBase);
    }
