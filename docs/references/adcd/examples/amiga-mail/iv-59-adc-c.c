/* Source: ADCD 2.1
 * Section: iv-59-adc-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-adc-c.md
 */

    /* Automatic variables  */
    ULONG sig;
    struct DiskObject *dob = NULL;
    struct AppMessage *am;
    struct IntuiMessage *tim, im;
    struct FileInfoBlock *fib = NULL;
    BOOL alive = TRUE;

    if (!(IntuitionBase = (void *) OpenLibrary("intuition.library", 37)))
        fatal("Can't open Intuition.library");

    if (!(GfxBase = (void *) OpenLibrary("graphics.library", 37)))
        fatal("Can't open graphics.library");

    if (!(IconBase = (void *) OpenLibrary("icon.library", 37)))
        fatal("Can't open icon.library");

    if (!(WorkbenchBase = (void *) OpenLibrary("workbench.library", 37)))
        fatal("Can't open workbench.library");

    fib = (struct FileInfoBlock *) calloc(sizeof(*fib), 1);  /* allocate the FileInfoBlock */

    win = MakeWindow(&key);
    aport = (void *) CreatePort(NULL, 0);
    awin = (struct AppWindow *) AddAppWindow(0, win, win, aport, NULL);    /* setup appwindow */
    if (!win || !aport || !awin)
        fatal2("ADC: General Failure.", "Could be Low Memory condition.");

    /* setup disk object    */
    dob = (struct DiskObject *) calloc(sizeof(*dob), 1);
    dob->do_Magic = NULL;
    dob->do_Version = NULL;
    dob->do_Gadget = gad;
    dob->do_Type = NULL;
    dob->do_DefaultTool = NULL;
    dob->do_ToolTypes = NULL;
    dob->do_CurrentX = dob->do_CurrentY = NO_ICON_POSITION;
    dob->do_DrawerData = NULL;
    dob->do_ToolWindow = NULL;
    dob->do_StackSize = 0;

    if (!(aicon = (struct AppIcon *) AddAppIcon(NULL, NULL, "Application", aport, NULL, dob, TAG_END)))
        fatal("ADC: Could not create AppIcon");
    amenu[amicount++] = (void *) AddAppMenuItem(NULL, "Quit", "Quit AppDemo", aport, NULL);

    while (alive)
    {
        sig = (1 << aport->mp_SigBit) |
                ((win) ? (1 << win->UserPort->mp_SigBit) : NULL);
        sig = Wait(sig);

        /* App Messages   */
        if (sig & (1 << aport->mp_SigBit)) /* an app signal */
        {
            while (am = (struct AppMessage *) GetMsg(aport))
            {
                switch(am->am_Type)
                {
                case AMTYPE_APPWINDOW:   /* something was dropped in the window  */
                    ProcessIcon(win, am);
                    break;

                case AMTYPE_APPICON:     /* icon was double-clicked */
                    if (!am->am_NumArgs) /* Double-Clicked  */
                    {
                        if (!win) /* is our (app) window open? */
                        {
                            if (!(win = MakeWindow(&key)))
                            {
                                warning("ADC: Cannot open window!");
                                break;
                            }

                            if (!(awin = (struct AppWindow *) AddAppWindow(NULL, NULL, win, aport, NULL)))
                            {
                                warning("ADC: Cannot make window an AppWindow!");
                                CloseWindow(win); win = NULL;
                            }
                        }
                        WindowToFront(win);
                        ActivateWindow(win);
                        UpdateWindow(win);
                    }
                    else /* Icons dropped on AppIcon    */
                        ProcessIcon(win, am);

                    break;

                case AMTYPE_APPMENUITEM: /* menu item was selected */
                    if (!stricmp(am->am_UserData, "quit"))
                        alive = FALSE;

                    else /* we have something real */
                    {
                        SystemTags(am->am_UserData, SYS_Input, Open("nil:", MODE_NEWFILE),
                                                    SYS_Output, Open("CON:////Application_Output/CLOSE/AUTO/WAIT", MODE_NEWFILE),
                                                    SYS_Asynch, TRUE,
                                                    NP_StackSize, 30000,    /* Let's be generous    */
                                                    NP_Priority, 0,
                                                    NP_Cli, FALSE,
                                                    TAG_END, NULL);
                    }
                    break;

                default:
                    break;
                }
                ReplyMsg(am);
            }
        }

        /* Window Messages    */
        if (win && (sig & (1 << win->UserPort->mp_SigBit))) /* an IDCMP signal */
        {
            while (win && (tim = (struct IntuiMessage*) GetMsg(win->UserPort)))
            {
                im = *tim;
                ReplyMsg(tim);
                switch (im.Class)
                {
                case CLOSEWINDOW:
                    UpdateWindow(win);
                    RemoveAppWindow(awin); awin = NULL;
                    CloseWindow(win); win = NULL;
                    break;

                case NEWSIZE:
                case REFRESHWINDOW:
                    UpdateWindow(win);
                    break;

                default:
                    break;
                }
            }
        }
    }

    ShutDown();
