/* Source: ADCD 2.1
 * Section: iv-59-appwindow-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-appwindow-c.md
 */

    struct MsgPort *msgport;
    struct Window  *window;
    struct AppWindow *appwindow;
    struct IntuiMessage *imsg;
    struct AppMessage *appmsg;
    struct WBArg   *argptr;

    ULONG           id = 1, userdata = 0;
    BOOL            ABORT = FALSE;
    UCOUNT          i;

    /* Open Intuition.library & Workbench.library. Fail silently if < 36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36))
    {
        if (WorkbenchBase = OpenLibrary("workbench.library", 36))
        {
            /* Create the message port to which Workbench can send messages */
            if (msgport = CreateMsgPort())
            {
                if (window =
                    OpenWindowTags(NULL, WA_Left, 0, WA_Top, 1, WA_Width, 160,
                                   WA_Height, 50, WA_IDCMP, CLOSEWINDOW,
                                   WA_Flags, WINDOWCLOSE | WINDOWDRAG,
                                   WA_Title, "AppWindow", TAG_END))
                {

                    /*
                     * Turn the window we opened into an AppWindow. Provide an
                     * ID so you can tell possible more AppWindows apart.
                     */
                    if (appwindow = AddAppWindow(id, userdata, window, msgport, NULL))
                    {
                        do
                        {
                            /* Wait for either a CLOSEWINDOW or an AppMessage */
                            Wait(1 << window->UserPort->mp_SigBit |
                                1 << msgport->mp_SigBit);
                            while (imsg = (struct IntuiMessage *)
                                GetMsg(window->UserPort))
                            {
                                if (imsg->Class = CLOSEWINDOW)
                                    ABORT = TRUE;
                                ReplyMsg((struct Message *) imsg);
                            }
                            while (appmsg = (struct AppMessage *) GetMsg(msgport))
                            {

                                /*
                                 * The AppMessage type will be MTYPE_APPWINDOW,
                                 * the ID & userdata are what we supplied when
                                 * the window was designed as an AppWindow.
                                 * NumArgs allows us to process the Workbench
                                 * arguments properly.
                                 */
                                printf(
                       "aw: appmsg=%lx, Type=%ld, ID=%ld, UserData=%ld, NumArgs=%ld\n",
                                       appmsg, appmsg->am_Type, appmsg->am_ID,
                                       appmsg->am_UserData, appmsg->am_NumArgs);

                                /*
                                 * Get a pointer to the start of the Workbench
                                 * argument list.
                                 */
                                argptr = appmsg->am_ArgList;
                                for (i = 0; i < appmsg->am_NumArgs; i++)
                                {

                                    /*
                                     * The lock will be on the directory in
                                     * which the file resides. If there is no
                                     * filename, either a volume or window was
                                     * dropped on us.
                                     */
                                    printf("\targ(%ld): Name='%s', Lock=%lx\n",
                                           i, argptr->wa_Name, argptr->wa_Lock);
                                    /* Point to next argument */
                                    argptr++;
                                }
                                ReplyMsg((struct Message *) appmsg);
                            }
                        } while (ABORT == FALSE);
                        /* remove the appwindow status and close down */
                        RemoveAppWindow(appwindow);
                    }
                    else
                        printf("Couldn't AddAppWindow\n");
                    CloseWindow(window);
                }
                else
                    printf("Couldn't open window\n");
                DeleteMsgPort(msgport);
            }
            else
                printf("Coulnd't create messageport\n");
            CloseLibrary(WorkbenchBase);
        }
        else
            printf("Couldn't open workbench.library\n");
        CloseLibrary(IntuitionBase);
    }
    else
        printf("Couldn't open intuition.library\n");
