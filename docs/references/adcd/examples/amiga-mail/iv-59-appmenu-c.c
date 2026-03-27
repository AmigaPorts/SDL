/* Source: ADCD 2.1
 * Section: iv-59-appmenu-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-appmenu-c.md
 */

    struct MsgPort *msgport;
    struct Window  *window;
    struct AppMenuItem *appmenuitem;
    struct IntuiMessage *imsg;
    struct AppMessage *appmsg;
    struct WBArg   *argptr;

    ULONG           id = 1, userdata = 0, i;
    BOOL            ABORT = FALSE;

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
                                   WA_Title, "AppMenu", TAG_END))
                {

                    /* Use our window to attach an menu item to the Tools menu. */
                    if (appmenuitem = AddAppMenuItem(id, userdata,
                                                     "AppMenuItem", msgport, NULL))
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
                                 * The AppMessage type will be MTYPE_APPMENU,
                                 * the ID & userdata are what we supplied when
                                 * the window was designed as an AppWindow.
                                 * Since there are no Workbench arguments for
                                 * menu operations, NumArgs will always be 0.
                                 */
                                printf(
                       "am: appmsg=%lx, Type=%ld, ID=%ld, UserData=%ld, NumArgs=%ld\n",
                                       appmsg, appmsg->am_Type, appmsg->am_ID,
                                       appmsg->am_UserData, appmsg->am_NumArgs);
                                argptr = appmsg->am_ArgList;
                                for (i = 0; i < appmsg->am_NumArgs; i++)
                                {

                                    /*
                                     * The lock will be on the directory in
                                     * which the file resides. If there is no
                                     * filename, either a volume or window was
                                     * dropped on us.
                                     */
                                    printf("\targ(%ld): Name='%s', Lock=%lx\n", i,
                                           argptr->wa_Name, argptr->wa_Lock);
                                    /* Point to next argument */
                                    argptr++;
                                }

                                ReplyMsg((struct Message *) appmsg);
                            }
                        } while (ABORT == FALSE);
                        /* remove the AppMenu and close down */
                        RemoveAppMenuItem(appmenuitem);
                    }
                    else
                        printf("Couldn't add AppMenuItem\n");
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
