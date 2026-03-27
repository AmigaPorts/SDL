/* Source: ADCD 2.1
 * Section: iv-59-appicon-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-appicon-c.md
 */

    struct MsgPort *msgport;
    struct Window  *window;
    struct AppIcon *appicon;
    struct IntuiMessage *imsg;
    struct AppMessage *appmsg;
    struct WBArg   *argptr;

    ULONG           id = 1, userdata = 0;
    BOOL            ABORT = FALSE;
    UCOUNT          i;


    /* Open needed libraries. Fail silently if < 36 */
    if (IntuitionBase = OpenLibrary("intuition.library", 36))
    {
        if (WorkbenchBase = OpenLibrary("workbench.library", 36))
        {
            if (msgport = CreateMsgPort())
            {
                if (window =
                    OpenWindowTags(NULL, WA_Left, 0, WA_Top, 1, WA_Width, 160,
                                   WA_Height, 50, WA_IDCMP, CLOSEWINDOW,
                                   WA_Flags, WINDOWCLOSE | WINDOWDRAG,
                                   WA_Title, "AppIcon", TAG_END))
                {

                    /* Add the icon to Workbench */
                    if (appicon = AddAppIcon(id, userdata, "AppIcon",
                        msgport, NULL, &AppIconDObj, NULL))
                    {
                        do
                        {
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
                                printf(
                       "ai: appmsg=%lx, Type=%ld, ID=%ld, UserData=%ld, NumArgs=%ld\n",
                                       appmsg, appmsg->am_Type, appmsg->am_ID,
                                       appmsg->am_UserData, appmsg->am_NumArgs);
                                argptr = appmsg->am_ArgList;

                                /*
                                 * If am->NumArgs is zero the user
                                 * double-clicked on our icon, otherwise one or
                                 * more icons were dropped on top of it.
                                 */
                                for (i = 0; i < appmsg->am_NumArgs; i++)
                                {
                                    printf("\targ(%ld): Name='%s', Lock=%lx\n",
                                    i, argptr->wa_Name, argptr->wa_Lock);
                                    argptr++;
                                }
                                ReplyMsg((struct Message *) appmsg);
                            }
                        } while (ABORT == FALSE);
                        /* Remove the AppIcon and clean up */
                        RemoveAppIcon(appicon);
                    }
                    else
                        printf("Couldn't add AppIcon\n");
                    CloseWindow(window);
                }
                else
                    printf("Couldn't open window\n");
                DeleteMsgPort(msgport);
            }
            else
                printf("Couldn't create messageport\n");
            CloseLibrary(WorkbenchBase);
        }
        else
            printf("Couldn't open workbench.library\n");
        CloseLibrary(IntuitionBase);
    }
    else
        printf("Couldn't open intuition.library\n");
